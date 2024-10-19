#pragma once
#include "Aluno.h"
class ElAluno
{
private:
	Aluno* pAluno;
	ElAluno* pProx;
	ElAluno* pAnte;
	float n1, n2, nFinal;
	int nFaltas;

public:
	ElAluno();
	~ElAluno();

	void setAluno(Aluno* al) { pAluno = al; }
	Aluno* getAluno() { return pAluno; }

	void setProx(ElAluno* px) { pProx = px; }
	ElAluno* getProx() { return pProx; }

	void setAnte(ElAluno* ant) { pAnte = ant; }
	ElAluno* getAnte() { return pAnte; }

	void setN1(float nota1) { n1 = nota1; }
	float getN1() const { return n1; }

	void setN2(float nota2) { n2 = nota2; }
	float getN2() const { return n2; }

	float getNFinal() { nFinal = (n1 + n2) / 2; return nFinal; }

	void DarFalta() { nFaltas++; }
	int getFaltas() const { return nFaltas; }
};