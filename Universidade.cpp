#include "Universidade.h"
#include "Professor.h"
#include "ElProfessor.h"
#include <iostream>

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

bool Universidade::incluiDepart(Departamento* dp)
{
	ElDepartamento* el = new ElDepartamento();
	el->setDepartamento(dp);

	if (pDepartAtual == nullptr && pDepartPrim == nullptr)
	{
		pDepartAtual = el;
		pDepartPrim = el;
	}
	else
	{
		pDepartAtual->setProx(el);
		el->setAnte(pDepartAtual);
		pDepartAtual = el;
	}
	el->getDepartamento()->setUniversidade(this);
	return true;
}

bool Universidade::removeDepart(Departamento* dp)
{
	ElDepartamento* aux = pDepartPrim;

	while (aux != nullptr && aux->getDepartamento()->getNome() != dp->getNome())
	{
		aux = aux->getProx();
	}
	if (aux == nullptr) return false;
	else
	{
		if (aux == pDepartPrim)
		{
			pDepartPrim = aux->getProx();

			if (pDepartPrim != nullptr) 
			{ 
				pDepartPrim->setAnte(nullptr);
			}
		}
		if (aux == pDepartAtual)
		{
			pDepartAtual = aux->getAnte();
			pDepartAtual->setProx(nullptr);

			if (pDepartAtual != nullptr) 
			{  
				pDepartAtual->setProx(nullptr);
			}
		}
		else
		{
			aux->getAnte()->setProx(aux->getProx());
			aux->getProx()->setAnte(aux->getAnte());
		}

		delete aux;
		return true;
	}
}

void Universidade::listaDepartInicial()
{
	ElDepartamento* aux = pDepartPrim;

	std::cout << "Departamentos da Universidade " << nome << " (início -> fim):" << std::endl;
	while (aux != nullptr)
	{
		std::cout << "O Departamento " << aux->getDepartamento()->getNome() << " Faz parte da Universidade " << nome << std::endl;
		aux = aux->getProx();
	}
}

void Universidade::listaDepartFinal()
{
	ElDepartamento* aux = pDepartAtual;

	std::cout << "Departamentos da Universidade " << nome << " (fim -> início):" << std::endl;
	while (aux != nullptr)
	{
		std::cout << "O Departamento " << aux->getDepartamento()->getNome() << " Faz parte da Universidade " << nome << std::endl;
		aux = aux->getAnte();
	}
}

bool Universidade::incluiProfessor(Professor* pr)
{
	ElProfessor* el = new ElProfessor();
	el->setProfessor(pr);

	if (pProfessorAtual == nullptr && pProfessorPrim == nullptr)
	{
		pProfessorAtual = el;
		pProfessorPrim = el;
	}
	else
	{
		pProfessorAtual->setProx(el);
		el->setAnte(pProfessorAtual);
		pProfessorAtual = el;
	}
	el->getProfessor()->setUniv(this);
	return true;
}

bool Universidade::removeProfessor(Professor* pr)
{
	ElProfessor* aux = pProfessorPrim;
	while (aux != nullptr && aux->getProfessor()->getNome() != pr->getNome())
	{
		aux = aux->getProx();
	}

	if (aux == nullptr) return false;
	else
	{
		if (aux == pProfessorPrim)
		{
			pProfessorPrim = aux->getProx();

			if (pProfessorPrim != nullptr)
			{
				pProfessorPrim->setAnte(nullptr);
			}
		}
		if (aux == pProfessorAtual)
		{
			pProfessorAtual = aux->getAnte();
			pProfessorAtual->setProx(nullptr);

			if (pProfessorAtual != nullptr)
			{
				pProfessorAtual->setProx(nullptr);
			}
		}
		else
		{
			aux->getAnte()->setProx(aux->getProx());
			aux->getProx()->setAnte(aux->getAnte());
		}

		delete aux;
		return true;
	}

}

void Universidade::listaProfessorInicial()
{
	ElProfessor* aux = pProfessorPrim;

	std::cout << "Professores da Universidade " << nome << " (início -> fim):" << std::endl;
	while (aux != nullptr)
	{
		std::cout << "O Professor " << aux->getProfessor()->getNome() << "Trabalha na Universidade " << nome << std::endl;
		aux = aux->getProx();
	}
}

void Universidade::listaProfessorFinal()
{
	ElProfessor* aux = pProfessorAtual;

	std::cout << "Professores da Universidade " << nome << " (fim -> início):" << std::endl;
	while (aux != nullptr)
	{
		std::cout << "O Professor " << aux->getProfessor()->getNome() << "Trabalha na Universidade " << nome << std::endl;
		aux = aux->getAnte();
	}
}
