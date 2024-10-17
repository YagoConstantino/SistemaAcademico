#pragma once
#include "Disciplina.h"

class ElDisciplina
{
private:
	Disciplina* pDisciplina;
	ElDisciplina* pProx;
	ElDisciplina* pAnte;

public:
	void setDisciplina(Disciplina* dc) { pDisciplina = dc; }
	Disciplina* getDisciplina() { return pDisciplina; }

	void setProx(ElDisciplina* el) { pProx = el; }
	ElDisciplina* getProx() { return pProx; }

	void setAnte(ElDisciplina* el) { pAnte = el; }
	ElDisciplina* getAnte() { return pAnte; }

};