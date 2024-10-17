#pragma once
#include <string>
class Universidade;
class ElDisciplina;
class Disiciplina;
class Departamento
{
private:
	std::string nome;

	Universidade* pUniv;

	ElDisciplina* pDisciplinaPrim;
	ElDisciplina* pDisciplinaAtual;

public:
	Departamento();
	~Departamento();

	void setNome(const char* name) { nome = name; }
	const char* getNome() { return nome; }

	void setUniversidade(Universidade* pu) { pUniv = pu; };
	Universidade* getUniversidade() { return pUniv; }

	void setDisciplina(Disciplina* pd);
	void listeDisciplinas();
	void listeDisciplinas2();
};