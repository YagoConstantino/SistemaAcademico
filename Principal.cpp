#include "Principal.h"
#include <Windows.h>
#include <iostream>
using namespace std;

Principal::Principal()
{
	objListaAluno = new ListaAluno();
	objListaDepartamento = new ListaDepartamento();
	objListaDisciplina = new ListaDisciplina();
	objListaProfessor = new ListaProfessor();
	objListaUniversidade = new ListaUniversidade();
	Executar();
}

Principal::~Principal()
{
	delete objListaUniversidade;
	delete objListaDepartamento;
	delete objListaProfessor;
	delete objListaDisciplina;
	delete objListaAluno;
}


void Principal::Menu()
{
	int op = -1;

	while (op != 3)
	{
		system("cls");
		cout << "Informe sua opcao :" << endl;
		cout << "1 Cadastrar" << endl;
		cout << "2 Executar " << endl;
		cout << "3 Sair" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
		{
			MenuCad();
		}
		break;

		case 2:
		{
			MenuExe();
		}
		break;

		case 3:
		{
			cout << "FIM" << endl;
		}
		break;

		default:
		{
			cout << "Opcao Invalida" << endl;
			system("pause");
		}
		break;
		}
	}
}

void Principal::MenuCad()
{
	int op = -1;
	while (op != 6)
	{
		cout << "Informe sua opcao :" << endl;
		cout << "1 Cadastrar Universidade" << endl;
		cout << "2 Cadastrar Departamento " << endl;
		cout << "3 Cadastrar Disciplina" << endl;
		cout << "4 Cadastrar Professor" << endl;
		cout << "5 Cadastrar Aluno" << endl;
		cout << "6 Sair" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
			CadUniversidade();
			break;

		case 2:
			CadDepartamento();
			break;

		case 3:
			CadDisciplina();
			break;

		case 4:
			CadProfessor();
			break;

		case 5:
			CadAluno();
			break;

		case 6:
			cout << "FIM" << endl;
			break;

		default:
			cout << "Valor invalido" << endl;
			system("pause");
		
		}


	}
}

void Principal::MenuExe()
{
	int op = -1;
	while (op != 6)
	{
		cout << "Informe sua opcao :" << endl;
		cout << "1 Listar Universidades" << endl;
		cout << "2 Listar Departamentos " << endl;
		cout << "3 Listar Disciplinas" << endl;
		cout << "4 Listar Professores" << endl;
		cout << "5 Listar Alunos" << endl;
		cout << "6 Sair" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
			objListaUniversidade->listaUniversidadeInicio();
			break;

		case 2:
			objListaDepartamento->listaDepartInicial();
			break;

		case 3:
			objListaDisciplina->listeDisciplinasInicio();
			break;

		case 4:
			objListaProfessor->listeProfessoresInicio();
			break;

		case 5:
			objListaAluno->listarAlunosInicio();
			break;

		case 6:
			cout << "FIM" << endl;
			break;

		default:
			cout << "Valor invalido" << endl;
			system("pause");

		}


	}
}

void Principal::Executar()
{
	SYSTEMTIME st;
	GetLocalTime(&st);

	diaH = st.wDay;
	mesH = st.wMonth;
	anoH = st.wYear;

}
