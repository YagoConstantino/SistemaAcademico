#pragma once
#include "ElDepartamento.h"
#include <iostream>

class ListaDepartamento
{
private:
	ElDepartamento* pDepartPrim;
	ElDepartamento* pDepartAtual;

public:
	ListaDepartamento();
	~ListaDepartamento();

	bool incluiDepart(Departamento* dp);
	bool removeDepart(Departamento* dp);
	void listaDepartInicial();
	void listaDepartFinal();

	ElDepartamento* getPprim() { return pDepartPrim; }
	Departamento* buscaDepartamento(std::string& nome);
};