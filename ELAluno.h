#pragma once
#include "Aluno.h"
class ElAluno
{
private:
	Aluno* pAluno;
	ElAluno* pProx;
	ElAluno* pAnte;

public:

	void setAluno(Aluno* al) { pAluno = al; }
	Aluno* getAluno() { return pAluno; }

	void setProx(ElAluno* px) { pProx = px; }
	ElAluno* getProx() { return pProx; }

	void setAnte(ElAluno* ant) { pAnte = ant; }
	ElAluno* getAnte() { return pAnte; }

};