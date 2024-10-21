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

	void listarAlunosInicio();
	void listarAlunosFinal();

	ElAluno* getAlunoPrim() { return pAlunoPrim; }

	Aluno* buscaAluno(std::string& nome);

};