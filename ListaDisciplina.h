#pragma once
#include "ElDisciplina.h"
#include "Disciplina.h"

class ListaDisciplina
{
private:
	ElDisciplina* pDisciplinaPrim;
	ElDisciplina* pDisciplinaAtual;

public:
	ListaDisciplina();
	~ListaDisciplina();

	bool incluiDisciplina(Disciplina* pd);
	bool removeDisciplina(Disciplina* pd);

	void listeDisciplinasInicio();
	void listeDisciplinasFinal();

	ElDisciplina* getPprim() { return pDisciplinaPrim; }
	ElDisciplina* buscaDisciplina(std::string& nome);

};