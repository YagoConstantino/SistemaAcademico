#pragma once
#include "Professor.h"
class ElProfessor
{
private:
	Professor* pProfessor;
	ElProfessor* pProx;
	ElProfessor* pAnte;

public:
	void setProfessor(Professor* pr) { pProfessor = pr; }
	Professor* getProfessor() { return pProfessor; }

	void setProx(ElProfessor* el) { pProx = el; }
	ElProfessor* getProx() { return pProx; }

	void setAnte(ElProfessor* el) { pAnte = el; }
	ElProfessor* getAnte() { return pAnte; }

};