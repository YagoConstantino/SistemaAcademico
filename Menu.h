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

	Professor Simao;
	Professor Leyza;
	Professor Dorini;
	Professor Thais;

	Aluno A;
	Aluno B;
	Aluno C;
	Aluno D;

	Universidade UTFPR;

	Departamento DAINF;
	Departamento DAMAT;

	Disciplina FundProg;
	Disciplina TecProg;
	Disciplina Algebra;
	Disciplina Calculo;

	ListaAluno* objListaAluno;
	ListaDepartamento* objListaDepartamento;
	ListaDisciplina* objListaDisciplina;
	ListaProfessor* objListaProfessor;
	ListaUniversidade* objListaUniversidade;
	int diaAT, mesAT, anoAT;

	int cont_idDisciplina;
	int cont_idAluno;
	int cont_idDepartamento;

public:
	Menu();
	~Menu();

	void inicializaUniversidade();
	void inicializaProfessor();
	void inicializaDepartamento();
	void inicializaDisciplina();
	void inicializaAluno();
	void UnivOndeProfsTrabalham();
	void DepOndeProfsTrabalham();

	void CalcIdade();
	void listaDepartamento();
	void listaDisciplina();
	void listaAluno();
	void listaDisciplinaAluno();
	void notasAlunos();

	void CadUniversidade();
	void CadDepartamento();
	void CadDisciplina();
	void CadProfessor();
	void CadAluno();

	/*
	void GravarTudo();
	void GravarUniversidades();
	void GravarDepartamentos();
	void GravarDisciplinas();
	void GravarAlunos();
	void GravarProfessores();

	void RecuperarTudo();
	void RecuperarUniversidades();
	void RecuperarDepartamentos();
	void RecuperarDisciplinas();
	void RecuperarAlunos();
	void RecuperarProfessores();*/

	void MenuPrin();
	void MenuCad();
	void MenuExe();

	void Executar();

	

	
};