#include "Departamento.h"
#include "ElDisciplina.h"
#include "Universidade.h"
#include <iostream>
Departamento::Departamento()
{
	nome = " ";
	pUniv = nullptr;
	pDisciplinaAtual = nullptr;
	pDisciplinaPrim = nullptr;

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
	pUniv = nullptr;
	pDisciplinaAtual = nullptr;
	pDisciplinaPrim = nullptr;
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
