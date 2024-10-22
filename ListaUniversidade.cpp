#include "ListaUniversidade.h"
#include <iostream>
ListaUniversidade::ListaUniversidade()
{
	pPrim = nullptr;
	PAtual = nullptr;
}

ListaUniversidade::~ListaUniversidade()
{
	ElUniversidade* aux = pPrim;

	while (aux != nullptr)
	{
		pPrim = pPrim->getProx();
		delete aux;
		aux = pPrim;
	}

	pPrim = nullptr;
	PAtual = nullptr;
}

bool ListaUniversidade::incluiUniversidade(Universidade* pu)
{
	if (pu == nullptr) return false;
	else
	{
		ElUniversidade* aux = new ElUniversidade();
		aux->setPuniv(pu);

		if (pPrim == nullptr && PAtual == nullptr)
		{
			pPrim = PAtual = aux;
		}
		else
		{
			PAtual->setProx(aux);
			aux->setAnte(aux);
			PAtual = aux;
		}
		return true;
	}
}

bool ListaUniversidade::removeUniversidade(Universidade* pu)
{
	if (pu == nullptr) return false;
	ElUniversidade* aux = pPrim;

	while (aux != nullptr && aux->getUniv()->getNome() != pu->getNome())
	{
		aux = aux->getProx();
	}

	if (aux == nullptr)
	{
		printf("Universidade nao encontrada\n");
		return false;
	}

	if (aux == pPrim)
	{
		pPrim = aux->getProx();
		if (pPrim != nullptr) pPrim->setAnte(nullptr);
	}
	else if (aux == PAtual)
	{
		PAtual = aux->getAnte();
		if(PAtual!=nullptr)PAtual->setProx(nullptr);
	}
	else
	{
		aux->getAnte()->setProx(aux->getProx());
		aux->getProx()->setAnte(aux->getAnte());
	}
	
	delete aux;
	return true;
}

void ListaUniversidade::listaUniversidadeInicio()
{
	ElUniversidade* aux = pPrim;
	printf("Lista de Universidades Cadastradas (inicio->final)\n\n");
	while (aux != nullptr)
	{
		std::cout << aux->getUniv()->getNome() << std::endl;
		aux = aux->getProx();
	}
}

void ListaUniversidade::listaUniversidadeFinal()
{
	ElUniversidade* aux = PAtual;
	printf("Lista de Universidades Cadastradas (final->inicio)\n\n");
	while (aux != nullptr)
	{
		std::cout << aux->getUniv()->getNome() << std::endl;

		aux = aux->getAnte();
	}
}

Universidade* ListaUniversidade::buscaUniv(std::string& nome)
{
	ElUniversidade* aux = pPrim;

	while (aux != nullptr)
	{
		if (aux->getUniv()->getNome() == nome) return aux->getUniv();
		else aux = aux->getProx();
	}
	std::cout << "Nao encontrado a Universidade" << std::endl;
	return nullptr;
}
