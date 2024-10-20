#pragma once
#include "ElUniversidade.h"

class ListaUniversidade
{
private:
	ElUniversidade* pPrim;
	ElUniversidade* PAtual;

public:
	ListaUniversidade();
	~ListaUniversidade();

	bool incluiUniversidade(Universidade* pu);
	bool removeUniversidade(Universidade* pu);

	void listaUniversidadeInicio();
	void listaUniversidadeFinal();

	ElUniversidade* getpPrim() { return pPrim; }
	ElUniversidade* buscaUniv(std::string& nome);
};