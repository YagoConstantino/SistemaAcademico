#pragma once
#include <string>
class Universidade;
class ElDisciplina;
class Disciplina;
class ElProfessor;
class Professor;


class Departamento
{
private:
	std::string nome;

	Universidade* pUniv;

	ElDisciplina* pDisciplinaPrim;
	ElDisciplina* pDisciplinaAtual;

	ElProfessor* pProfessorPrim;
	ElProfessor* pProfessorAtual;

public:
	Departamento();
	~Departamento();

	void setNome(std::string name) { nome = name; }
	std::string getNome() { return nome; }

	void setUniversidade(Universidade* pu) { pUniv = pu; };
	Universidade* getUniversidade() { return pUniv; }

	bool incluiDisciplina(Disciplina* pd);
	bool removeDisciplina(Disciplina* pd);

	void listeDisciplinasInicio();
	void listeDisciplinasFinal();

	bool incluiProfessor(Professor* pr);
	bool excluiProfessor(Professor* pr);

	void listeProfessoresInicio();
	void listeProfessoresFinal();
};