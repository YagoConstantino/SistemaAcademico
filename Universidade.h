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

	void incluiDepart(Departamento* dp);
	void listaDepartInicial();
	void listaDepartFinal();

	void incluiProfessor(Professor* pr);
	void listaProfessorInicial();
	void listaProfessorFinal();


};