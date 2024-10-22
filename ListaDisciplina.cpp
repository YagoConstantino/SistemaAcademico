#include "ListaDisciplina.h"
#include <iostream>

ListaDisciplina::ListaDisciplina()
{
	pDisciplinaAtual = pDisciplinaPrim = nullptr;
}

ListaDisciplina::~ListaDisciplina()
{
	ElDisciplina* aux, * no;

	aux = pDisciplinaPrim;
	while (aux != nullptr)
	{
		no = aux;
		aux = aux->getProx();
		delete no;
	}
	pDisciplinaAtual = pDisciplinaPrim = nullptr;
}

bool ListaDisciplina::incluiDisciplina(Disciplina* pd)
{
    if (pd== nullptr) return false;

    ElDisciplina* el = new ElDisciplina();
    el->setDisciplina(pd);

    if (pDisciplinaPrim == nullptr && pDisciplinaAtual == nullptr)
    {
        pDisciplinaPrim = pDisciplinaAtual = el;
    }
    else
    {
        pDisciplinaAtual->setProx(el);
        el->setAnte(pDisciplinaAtual);
        pDisciplinaAtual = el;
    }
    return true;
}

bool ListaDisciplina::removeDisciplina(Disciplina* pd)
{
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

void ListaDisciplina::listeDisciplinasInicio()
{
    ElDisciplina* aux = pDisciplinaPrim;

    while (aux != nullptr) {
        std::cout << "Disciplina: " << aux->getDisciplina()->getNome() << std::endl;
        aux = aux->getProx();
    }
    printf("\n");
}

void ListaDisciplina::listeDisciplinasFinal()
{
    ElDisciplina* aux = pDisciplinaAtual;

    while (aux != nullptr) {
        std::cout << "Disciplina: " << aux->getDisciplina()->getNome() << std::endl;
        aux = aux->getAnte();
    }
    printf("\n");
}

Disciplina* ListaDisciplina::buscaDisciplina(std::string& nome)
{
    ElDisciplina* aux = pDisciplinaPrim;

    while (aux != nullptr)
    {
        if (aux->getDisciplina()->getNome() == nome) return aux->getDisciplina();
        else aux = aux->getProx();
    }
    std::cout << "Não encontrado a Disciplina" << std::endl;
    return nullptr;
}
