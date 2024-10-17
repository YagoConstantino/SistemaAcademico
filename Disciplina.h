#pragma once
#include <string>
#include "ELAluno.h"

class Disciplina
{
private:
	int id;
	std::string nome;
	std::string areaConhecimento;
	int numeroAlunos;
	int contAlunos;

	Departamento* pDeptoAssociado;
	ElAluno* pAlunoPrim;
	ElAluno* pAlunoAtual;

public:
	Disciplina(int na = 45, const char* ac = " ");
	~Disciplina();

	Disciplina* pProx;
	Disciplina* pAnte;

	void setID(int i) { id = i; }
	int getID() { return id; }

	void setNome(std::string& name) { nome = name; }
	std::string& getNome() { return nome; }

	void setArea(std::string& area) { areaConhecimento = area; }
	std::string& getArea() { return areaConhecimento; }

	void setDepartamento(Departamento* pd) { pDeptoAssociado = pd; };
	Departamento* getDepartamento() { return pDeptoAssociado; }

	bool incluirAluno(Aluno* pa);
	bool excluirAluno(Aluno* pa);

	void listarAlunos();
	void listarAlunos2();




};