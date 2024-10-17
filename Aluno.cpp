#include "Aluno.h"
#include "Universidade.h"
#include "Departamento.h"
#include "ElDisciplina.h"
#include "Disciplina.h"


Aluno::Aluno(int dia, int mes, int ano):
Pessoa(dia,mes,ano)
{
	pUnivFiliado = nullptr;
	pDepartFiliado = nullptr;

	pDisciplinaPrim = nullptr;
	pDisciplinaAtual = nullptr;
}

Aluno::Aluno() :Pessoa()
{
	pUnivFiliado = nullptr;
	pDepartFiliado = nullptr;

	pDisciplinaPrim = nullptr;
	pDisciplinaAtual = nullptr;
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
