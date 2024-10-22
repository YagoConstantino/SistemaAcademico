#pragma once
#include "Universidade.h"
#include "Aluno.h"
#include "Professor.h"
#include "Departamento.h"
#include "Disciplina.h"
#include "ListaUniversidade.h"


class Menu
{
private:

	ListaAluno* objListaAluno;
	ListaDepartamento* objListaDepartamento;
	ListaDisciplina* objListaDisciplina;
	ListaProfessor* objListaProfessor;
	ListaUniversidade* objListaUniversidade;
	int diaAT, mesAT, anoAT;

public:
	Menu();
	~Menu();

	void CadUniversidade();
	void CadDepartamento();
	void CadDisciplina();
	void CadProfessor();
	void CadAluno();

	void MenuPrin();
	void MenuCad();
	void MenuExe();

	void Executar();


	
};