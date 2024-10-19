#pragma once
#include "Professor.h"
#include "Aluno.h"
#include "Universidade.h"
#include "Departamento.h"
#include "Disciplina.h"

class Principal
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

	int diaH, mesH, anoH;

public:
	Principal();
	~Principal();

	void inicializaUniversidade();
	void inicializaProfessor();
	void inicializaDepartamento();
	void inicializaDisciplina();
	void inicializaAluno();
	
	void CalcIdade();
	void listaDepartamento();
	void listaDisciplina();
	void listaAluno();
	void listaDisciplinaAluno();
	void notasAlunos();

	void Executar();
};