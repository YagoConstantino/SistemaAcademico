#include "ELAluno.h"

ElAluno::ElAluno()
{
	pAluno = nullptr;
	pProx = nullptr;
	pAnte = nullptr;
	n1 = n2 = nFinal = 0;
	nFaltas = 0;
}

ElAluno::~ElAluno()
{
	pAluno = nullptr;
	pProx = nullptr;
	pAnte = nullptr;
}