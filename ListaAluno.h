#pragma once
#include "ELAluno.h"
#include "Aluno.h"

class ListaAluno
{
private:

	ElAluno* pAlunoPrim;
	ElAluno* pAlunoAtual;
	int numeroAlunos;
	int contAlunos;

public:
	ListaAluno(int na = 45);
	~ListaAluno();


	bool incluirAluno(Aluno* pa);
	bool excluirAluno(Aluno* pa);

	void listarAlunosInicio(std::string& nome);
	void listarAlunosFinal(std::string& nome);

	ElAluno* getAlunoPrim() { return pAlunoPrim; }

};