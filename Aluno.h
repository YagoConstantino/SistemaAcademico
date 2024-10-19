#pragma once
#include "Pessoa.h"
class ListaDisciplina;
class Universidade;
class Departamento;
class ElDisciplina;
class Disciplina;

class Aluno :public Pessoa
{
private:
	int RA;
	Universidade* pUnivFiliado;
	Departamento* pDepartFiliado;
	ListaDisciplina* objListaDisciplina;

public:
	Aluno(int dia, int mes, int ano);
	Aluno();
	~Aluno();

	void setRa(int ra) { RA = ra; }
	int getRA() { return RA; }

	void setUniversidade(Universidade* un) { pUnivFiliado = un; }
	Universidade* getUniv() { return pUnivFiliado; }

	void setDepartamento(Departamento* dp) { pDepartFiliado = dp; }
	Departamento* getDepart() { return pDepartFiliado; }

	bool incluiDisciplina(Disciplina* pd);
	bool removeDisciplina(Disciplina* pd);

	void listeDisciplinasInicio();
	void listeDisciplinasFinal();

};