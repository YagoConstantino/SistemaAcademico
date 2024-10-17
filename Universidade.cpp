#include "Universidade.h"
#include "Professor.h"
#include "ElProfessor.h"

Universidade::Universidade(std::string& name)
{
	setNome(name);
	pDepartPrim = nullptr;
	pDepartAtual = nullptr;

	pProfessorPrim = nullptr;
	pProfessorAtual = nullptr;

}

Universidade::Universidade()
{
	nome = " ";
	pDepartPrim = nullptr;
	pDepartAtual = nullptr;

	pProfessorPrim = nullptr;
	pProfessorAtual = nullptr;
}

Universidade::~Universidade()
{
	ElDepartamento* aux = pDepartPrim;
	{
		while (aux != nullptr)
		{
			ElDepartamento* no = aux;
			aux = aux->getProx();
			delete no;
		}
	}

	ElProfessor* aux2 = pProfessorPrim;
	{
		while (aux2 != nullptr)
		{
			ElProfessor* no = aux2;
			aux = aux->getProx();
			delete no;
		}
	}

	pDepartPrim = nullptr;
	pDepartAtual = nullptr;

	pProfessorPrim = nullptr;
	pProfessorAtual = nullptr;
}