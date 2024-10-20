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
	void listaDepartInicial(std::string& nome);
	void listaDepartFinal(std::string& nome);

	ElDepartamento* getPprim() { return pDepartPrim; }
	ElDepartamento* buscaDepartamento(std::string& nome);
};