#include "ListaProfessor.h"
#include <iostream>
#include "ElProfessor.h"
#include"Professor.h"

ListaProfessor::ListaProfessor()
{
	pProfessorAtual = pProfessorPrim = nullptr;

}

ListaProfessor::~ListaProfessor()
{
    ElProfessor* aux2 = pProfessorPrim;
    ElProfessor* no2 = nullptr;

    while (aux2 != nullptr)
    {
        no2 = aux2;
        aux2 = aux2->getProx();
        delete no2;
    }
}

bool ListaProfessor::incluiProfessor(Professor* pr)
{
    if (pr == nullptr) return false;

    ElProfessor* el = new ElProfessor();
    el->setProfessor(pr);

    if (pProfessorPrim == nullptr && pProfessorAtual == nullptr)
    {
        pProfessorPrim = pProfessorAtual = el;
    }
    else
    {
        pProfessorAtual->setProx(el);
        el->setAnte(pProfessorAtual);
        pProfessorAtual = el;
    }
    return true;
}

bool ListaProfessor::excluiProfessor(Professor* pr)
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

void ListaProfessor::listeProfessoresInicio(std::string& nome)
{
    ElProfessor* aux = pProfessorPrim;
    std::cout << "Professores do Departamento " << nome << " (inicio -> fim):" << std::endl;
    while (aux != nullptr) {
        std::cout << "Professor: " << aux->getProfessor()->getNome()<<" Do "<<
        aux->getProfessor()->getDepart()->getNome()<< std::endl;
        aux = aux->getProx();
    }
    std::cout << std::endl;
}

void ListaProfessor::listeProfessoresFinal(std::string& nome)
{
    ElProfessor* aux = pProfessorPrim;
    std::cout << "Professores do Departamento " << nome << " (inicio -> fim):" << std::endl;
    while (aux != nullptr) {
        std::cout << "Professor: " << aux->getProfessor()->getNome() << " Do "  <<
        aux->getProfessor()->getDepart()->getNome() << std::endl;
        aux = aux->getAnte();
    }
    std::cout << std::endl;
}

Professor* ListaProfessor::buscaProfessor(std::string& nome)
{
    ElProfessor* aux = pProfessorPrim;

    while (aux != nullptr)
    {
        if (aux->getProfessor()->getNome() == nome) return aux->getProfessor();
        else aux = aux->getProx();
    }
    std::cout << "Não encontrado o Professor" << std::endl;
    return nullptr;
}
