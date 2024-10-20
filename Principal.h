#pragma once
#include "Professor.h"
#include "Aluno.h"
#include "Universidade.h"
#include "Departamento.h"
#include "Disciplina.h"
#include "ListaUniversidade.h"

class Principal
{
private:
	ListaUniversidade* objListaUniversidade;
	ListaDepartamento* objListaDepartamento;
	ListaDisciplina* objListaDisciplina;
	ListaProfessor* objListaProfessor;
	ListaAluno* objListaAluno;

	int diaH, mesH, anoH;

public:
	Principal();
	~Principal();
	
	void CadUniversidade();
	void CadDepartamento();
	void CadDisciplina();
	void CadProfessor();
	void CadAluno();

	void Menu();
	void MenuCad();
	void MenuExe();

	void Executar();
};