#include "Departamento.h"
#include "ElDisciplina.h"
#include "Universidade.h"
#include <iostream>
#include "ElProfessor.h"
#include "Professor.h"
Departamento::Departamento()
{
	nome = " ";
	pUniv = nullptr;
	pDisciplinaAtual = nullptr;
	pDisciplinaPrim = nullptr;
    pProfessorPrim = nullptr;
    pProfessorAtual = nullptr;

}

Departamento::~Departamento()
{
	ElDisciplina* aux, * no;

	aux = pDisciplinaPrim;
	while (aux != nullptr)
	{
		no = aux;
		aux = aux->getProx();
		delete no;
	}

    ElProfessor* aux2 = pProfessorPrim; 
    ElProfessor* no2 = nullptr;
 
    while (aux2 != nullptr)
    {
        no2 = aux2;
        aux2 = aux2->getProx();
        delete no2;
    }

	pUniv = nullptr;
	pDisciplinaAtual = nullptr;
	pDisciplinaPrim = nullptr;
    pProfessorPrim = nullptr;
    pProfessorAtual = nullptr;
}

bool Departamento::incluiDisciplina(Disciplina* pd) {
    ElDisciplina* el = new ElDisciplina();
    el->setDisciplina(pd);

    if (pDisciplinaAtual == nullptr && pDisciplinaPrim == nullptr) {
        pDisciplinaPrim = el;
        pDisciplinaAtual = el;
    }
    else {
        pDisciplinaAtual->setProx(el);
        el->setAnte(pDisciplinaAtual);
        pDisciplinaAtual = el;
    }

    el->getDisciplina()->setDepartamento(this);
    return true;
}

bool Departamento::removeDisciplina(Disciplina* pd) {
    ElDisciplina* aux = pDisciplinaPrim;

    while (aux != nullptr && aux->getDisciplina()->getNome() != pd->getNome()) {
        aux = aux->getProx();
    }

    if (aux == nullptr) return false;

    if (aux == pDisciplinaPrim) {
        pDisciplinaPrim = aux->getProx();
        if (pDisciplinaPrim != nullptr) pDisciplinaPrim->setAnte(nullptr);
    }
    else if (aux == pDisciplinaAtual) {
        pDisciplinaAtual = aux->getAnte();
        pDisciplinaAtual->setProx(nullptr);
    }
    else {
        aux->getAnte()->setProx(aux->getProx());
        aux->getProx()->setAnte(aux->getAnte());
    }

    delete aux;
    return true;
}

void Departamento::listeDisciplinasInicio() {
    ElDisciplina* aux = pDisciplinaPrim;

    while (aux != nullptr) {
        std::cout << "Disciplina: " << aux->getDisciplina()->getNome() << std::endl;
        aux = aux->getProx();
    }
    printf("\n");
}

void Departamento::listeDisciplinasFinal() {
    ElDisciplina* aux = pDisciplinaAtual;

    while (aux != nullptr) {
        std::cout << "Disciplina: " << aux->getDisciplina()->getNome() << std::endl;
        aux = aux->getAnte();
    }
    printf("\n");
}

bool Departamento::incluiProfessor(Professor* pr) {
    if (pr == nullptr) return false;

    ElProfessor* el = new ElProfessor();
    el->setProfessor(pr);

    if (pProfessorPrim == nullptr&& pProfessorAtual==nullptr)
    {
        pProfessorPrim = pProfessorAtual = el;
    }
    else 
    {
        pProfessorAtual->setProx(el);
        el->setAnte(pProfessorAtual);
        pProfessorAtual = el;
    }

    pr->setDepartamento(this);
    return true;
}

bool Departamento::excluiProfessor(Professor* pr) 
{
    if (pr == nullptr) return false;

    ElProfessor* aux = pProfessorPrim;
    while (aux != nullptr && aux->getProfessor()->getNome() != pr->getNome()) 
    {
        aux = aux->getProx();
    }

    if (aux == nullptr) return false; // Professor não encontrado

    if (aux == pProfessorPrim) 
    {
        pProfessorPrim = aux->getProx();
        if (pProfessorPrim != nullptr) 
            pProfessorPrim->setAnte(nullptr);
    }

    else if (aux == pProfessorAtual) {
        pProfessorAtual = aux->getAnte();
        if (pProfessorAtual != nullptr) 
            pProfessorAtual->setProx(nullptr);
    }

    else 
    {
        aux->getAnte()->setProx(aux->getProx());
        if (aux->getProx() != nullptr)
            aux->getProx()->setAnte(aux->getAnte());
    }

    delete aux;
    return true;
}

void Departamento::listeProfessoresInicio() {
    ElProfessor* aux = pProfessorPrim;
    std::cout << "Professores do Departamento " << nome << " (inicio -> fim):" << std::endl;
    while (aux != nullptr) {
        std::cout << "Professor: " << aux->getProfessor()->getNome() << std::endl;
        aux = aux->getProx();
    }
    std::cout << std::endl;
}

void Departamento::listeProfessoresFinal() {
    ElProfessor* aux = pProfessorAtual;
    std::cout << "Professores do Departamento " << nome << " (fim -> inicio):" << std::endl;
    while (aux != nullptr) {
        std::cout << "Professor: " << aux->getProfessor()->getNome() << std::endl;
        aux = aux->getAnte();
    }
    std::cout << std::endl;
}
