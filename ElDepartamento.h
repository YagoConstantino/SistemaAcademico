#pragma once
#include "Departamento.h"

class ElDepartamento
{
private:
	Departamento* pDepartamento;
	ElDepartamento* pProx;
	ElDepartamento* pAnte;

public:
	ElDepartamento();
	~ElDepartamento();

	void setDepartamento(Departamento* al) { pDepartamento = al; }
	Departamento* getDepartamento() { return pDepartamento; }

	void setProx(ElDepartamento* px) { pProx = px; }
	ElDepartamento* getProx() { return pProx; }

	void setAnte(ElDepartamento* ant) { pAnte = ant; }
	ElDepartamento* getAnte() { return pAnte; }

};