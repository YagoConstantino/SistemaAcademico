#include "Professor.h"

Professor::Professor(int dia, int mes, int ano):Pessoa(dia,mes,ano)
{
	pUnivFiliado = nullptr;
	pDepartFiliado = nullptr;
}

Professor::Professor():Pessoa()
{
	pUnivFiliado = nullptr;
	pDepartFiliado = nullptr;
}

Professor::~Professor()
{
	pUnivFiliado = nullptr;
	pDepartFiliado = nullptr;
}
