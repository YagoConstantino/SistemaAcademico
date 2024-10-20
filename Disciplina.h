#pragma once
#include <string>
#include "ELAluno.h"
#include "ListaAluno.h"

class Disciplina
{
private:
	int id;
	std::string nome;
	std::string areaConhecimento;
	int numeroAlunos;
	int contAlunos;

	Departamento* pDeptoAssociado;
	ListaAluno* objListaAluno;
	

public:
	Disciplina(int na = 45, std::string ac = "");
	~Disciplina();


	void setID(int i) { id = i; }
	int getID() { return id; }

	void setNome(std::string name) { nome = name; }
	std::string& getNome() { return nome; }

	void setArea(std::string area) { areaConhecimento = area; }
	std::string& getArea() { return areaConhecimento; }

	void setDepartamento(Departamento* pd) { pDeptoAssociado = pd; };
	Departamento* getDepartamento() { return pDeptoAssociado; }

	bool incluirAluno(Aluno* pa);
	bool excluirAluno(Aluno* pa);

	void listarAlunosInicio();
	void listarAlunosFinal();

	ElAluno* getAlunoPrim();

};