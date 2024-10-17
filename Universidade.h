#pragma once
#include "Departamento.h"
#include "ElDepartamento.h"

#include <string>

class Professor;
class ElProfessor;
class Universidade
{
private:
	std::string nome;

	ElDepartamento* pDepartPrim;
	ElDepartamento* pDepartAtual;

	ElProfessor* pProfessorPrim;
	ElProfessor* pProfessorAtual;

public:

	Universidade(std::string& name);
	Universidade();
	~Universidade();

	void setNome(std::string& name) { nome = name; }
	std::string& getNome() { return nome; };

	bool incluiDepart(Departamento* dp);
	bool removeDepart(Departamento* dp);
	void listaDepartInicial();
	void listaDepartFinal();

	bool incluiProfessor(Professor* pr);
	bool removeProfessor(Professor* pr);
	void listaProfessorInicial();
	void listaProfessorFinal();


};