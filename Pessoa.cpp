#include "Pessoa.h"

Pessoa::Pessoa(int dia, int mes, int ano)
{
	inicializa(dia, mes, ano);
}

Pessoa::Pessoa()
{
	inicializa(0, 0, 0);
}

Pessoa::~Pessoa()
{

}

void Pessoa::inicializa(int diaNa, int mesNa, int anoNa)
{
	diaP = diaNa;
	mesP = mesNa;
	anoP = anoNa;
	nome = " ";
	ID = -1;
}

void Pessoa::calcIdade(int diaAt, int mesAt, int anoAt)
{
	idadeP = anoAt - anoP;
	if (mesP > mesAt)
	{
		idadeP = idadeP - 1;
	}
	else
	{
		if (mesP == mesAt)
		{
			if (diaP > diaAt)
			{
				idadeP = idadeP - 1;
			}
		}
	}
}
