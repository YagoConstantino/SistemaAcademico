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

	void MenuPrin();
	void MenuCriacao();
	void MenuExecuta();
	

	void criaUniv();
	void criaDepart();
	void criaDisciplina();
	void criaProfessor() const;
	void criaAluno();


	
};