#include "Aluno.h"
#include "Universidade.h"
#include "Departamento.h"
#include "ElDisciplina.h"
#include "Disciplina.h"
#include "ListaDisciplina.h"
#include <iostream>


Aluno::Aluno(int dia, int mes, int ano):
Pessoa(dia,mes,ano)
{
	pUnivFiliado = nullptr;
	pDepartFiliado = nullptr;
	objListaDisciplina = new ListaDisciplina();
	
    RA = -1;
}

Aluno::Aluno() :Pessoa()
{
	pUnivFiliado = nullptr;
	pDepartFiliado = nullptr;
	objListaDisciplina = new ListaDisciplina();
	
    RA = -1;
}

Aluno::~Aluno()
{
	pUnivFiliado = nullptr;
	pDepartFiliado = nullptr;	
	delete objListaDisciplina;
}

bool Aluno::incluiDisciplina(Disciplina* pd)
{
	return objListaDisciplina->incluiDisciplina(pd);
}

bool Aluno::removeDisciplina(Disciplina* pd)
{
	return objListaDisciplina->removeDisciplina(pd);
}

void Aluno::listeDisciplinasInicio()
{
	objListaDisciplina->listeDisciplinasInicio();
}

void Aluno::listeDisciplinasFinal()
{
	objListaDisciplina->listeDisciplinasFinal();
}
