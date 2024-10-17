#include "Departamento.h"
#include "ElDisciplina.h"
#include "Universidade.h"
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
