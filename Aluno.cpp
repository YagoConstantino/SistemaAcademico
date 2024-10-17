#include "Aluno.h"
#include "Universidade.h"
#include "Departamento.h"
#include "ElDisciplina.h"
#include "Disciplina.h"
#include <iostream>


Aluno::Aluno(int dia, int mes, int ano):
Pessoa(dia,mes,ano)
{
	pUnivFiliado = nullptr;
	pDepartFiliado = nullptr;

	pDisciplinaPrim = nullptr;
	pDisciplinaAtual = nullptr;
    RA = -1;
}

Aluno::Aluno() :Pessoa()
{
	pUnivFiliado = nullptr;
	pDepartFiliado = nullptr;

	pDisciplinaPrim = nullptr;
	pDisciplinaAtual = nullptr;
    RA = -1;
}

Aluno::~Aluno()
{
	ElDisciplina* aux = pDisciplinaPrim;
	while (aux != nullptr)
	{
		ElDisciplina* no = aux;
		aux = aux->getProx();
		delete no;
	}
	pUnivFiliado = nullptr;
	pDepartFiliado = nullptr;

	pDisciplinaPrim = nullptr;
	pDisciplinaAtual = nullptr;
}

void Aluno::incluiDisciplina(Disciplina* dc) {
    ElDisciplina* el = new ElDisciplina();
    el->setDisciplina(dc);

    if (pDisciplinaAtual == nullptr && pDisciplinaPrim == nullptr) {
        pDisciplinaPrim = el;
        pDisciplinaAtual = el;
    }
    else {
        pDisciplinaAtual->setProx(el);
        el->setAnte(pDisciplinaAtual);
        pDisciplinaAtual = el;
    }

 
}

void Aluno::listaDisciplinaInicial() {
    ElDisciplina* aux = pDisciplinaPrim;
    std::cout << "Disciplinas do Aluno " << getNome() << " (início -> fim):" << std::endl;

    while (aux != nullptr) {
        std::cout << " - " << aux->getDisciplina()->getNome() << std::endl;
        aux = aux->getProx();
    }
}

void Aluno::listaDisciplinaFinal() {
    ElDisciplina* aux = pDisciplinaAtual;
    std::cout << "Disciplinas do Aluno " << getNome() << " (fim -> início):" << std::endl;

    while (aux != nullptr) {
        std::cout << " - " << aux->getDisciplina()->getNome() << std::endl;
        aux = aux->getAnte();
    }
}