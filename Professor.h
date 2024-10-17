#pragma once
#include "Pessoa.h"
#include "Universidade.h"
#include "Departamento.h"

class Professor :public Pessoa
{
private:
	Universidade* pUnivFiliado;
	Departamento* pDepartFiliado;

public:
	Professor(int dia, int mes, int ano);
	Professor();
	~Professor();

	void setUniv(Universidade* un) { pUnivFiliado = un; }
	Universidade* getUniv() { return pUnivFiliado; }

	void setDepartamento(Departamento* dp) { pDepartFiliado = dp; }
	Departamento* getDepart() { return pDepartFiliado; }

};
