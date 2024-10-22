#include "Menu.h"
#include <iostream>
#include <Windows.h>


using namespace std;
Menu::Menu()
{
	objListaAluno = new ListaAluno();
	objListaDepartamento = new ListaDepartamento();
	objListaDisciplina = new ListaDisciplina();
	objListaProfessor = new ListaProfessor();
	objListaUniversidade = new ListaUniversidade();

	SYSTEMTIME st;
	GetLocalTime(&st);

	diaAT = st.wDay;
	mesAT = st.wMonth;
	anoAT = st.wYear;
	MenuPrin();
}

Menu::~Menu()
{
	delete objListaAluno;
	delete objListaDepartamento;
	delete objListaDisciplina;
	delete objListaProfessor;
	delete objListaUniversidade;
}

void Menu::MenuPrin()
{
	int op = -1;

	while (op != 0)
	{
		cout << "Qual Menu voce deseja" << endl;
		cout << "Digite 1 para Menu de Criacao" << endl;
		cout << "Digite 2 para Menu de Execucao " << endl;
		cout << "Digite 0 para encerrar o Programa" << endl;

		cin >> op;
		switch (op)
		{
		case 1:
			MenuCriacao();
			break;

		case 2:
			MenuExecuta();
			break;

		case 0:
			cout << "Encerrando.....\n" << endl;
			break;

		default:
			cout << "Valor inválido tente Novamente....\n";
			break;

		}
	}
}

void Menu::MenuCriacao()
{
	int op = -1;

	while (op != 0)
	{
		cout << "Que tipo de objeto deseja criar:" << endl;
		cout << "Digite 1 para Universidade " << endl;
		cout << "Digite 2 para Departamento " << endl;
		cout << "Digite 3 para Disciplina " << endl;
		cout << "Digite 4 para Professor " << endl;
		cout << "Digite 5 para Aluno " << endl;
		cin >> op;
		switch (op)
		{
		case 1:
			criaUniv();
			break;

		case 2:
			criaDepart();
			break;

		case 3:
			criaDisciplina();
			break;

		case 4:
			criaProfessor();
			break;

		case 5:
			criaAluno();
			break;

		case 0:
			cout << "Saindo do Menu.....\n" << endl;
			break;

		default:
			cout << "Valor inválido tente Novamente....\n";
			break;

		}
	}

}

void Menu::MenuExecuta()
{
	string nula = " ";
	objListaUniversidade->listaUniversidadeInicio();
	objListaAluno->listarAlunosInicio(nula);
	objListaDepartamento->listaDepartInicial(nula);
	objListaDisciplina->listeDisciplinasInicio();
	objListaProfessor->listeProfessoresInicio(nula);

}


void Menu::criaUniv()
{
	string nome;
	cout << "Qual o nome da Universidade que voce deseja Cadastrar ?" << endl;
	cin >> nome;
	Universidade* novaUniversidade = new Universidade();
	novaUniversidade->setNome(nome);

	objListaUniversidade->incluiUniversidade(novaUniversidade);

}

void Menu::criaDepart()
{
	string nome;
	cout << "Qual o nome do Departamento que voce deseja Cadastrar ?" << endl;
	cin >> nome;
	Departamento* novoDepartamento = new Departamento();
	novoDepartamento->setNome(nome);

	objListaDepartamento->incluiDepart(novoDepartamento);

	string univ;
	cout << "Em Qual Universidade está cadastrado esse Departamento ?" << endl;
	cin >> univ;

	Universidade* universidade = objListaUniversidade->buscaUniv(univ);

	if (universidade)universidade->incluiDepart(novoDepartamento);


}

void Menu::criaDisciplina()
{
	string nome;
	string area;
	int ID;
	cout << "Qual o nome da Disciplina que voce deseja Cadastrar ?" << endl;
	cin >> nome;
	cout << "Qual a area de conhecimento da Disciplina ?" << endl;
	cin >> area;
	cout << "Qual o ID ?" << endl;
	cin >> ID;

	Disciplina* novaDisciplina = new Disciplina();
	novaDisciplina->setNome(nome);
	novaDisciplina->setArea(area);
	novaDisciplina->setID(ID);

	string depart;
	cout << "A Qual departamento essa Disciplina pertence ?" << endl;
	cin >> depart;

	Departamento* dp = objListaDepartamento->buscaDepartamento(depart);
	if (dp) dp->incluiDisciplina(novaDisciplina);

}

void Menu::criaProfessor() const
{
	string nome;
	int dia, mes, ano;
	int ID;

	cout << "Qual o nome do Professor que será cadastrado ?" << endl;
	cin >> nome;
	cout << "Qual a data de nascimento do Novo Professor ?" << endl;
	cin >> dia >> mes >> ano;
	cout << "Qual o ID do Professor ?" << endl;
	cin >> ID;

	Professor* novoProfessor = new Professor(dia, mes, ano);
	novoProfessor->calcIdade(diaAT,mesAT,anoAT);
	novoProfessor->setNome(nome);
	novoProfessor->setID(ID);

	string univ;
	cout << "Em Qual Universidade está cadastrado esse Professor ?" << endl;
	cin >> univ;

	Universidade* universidade = objListaUniversidade->buscaUniv(univ);

	if (universidade)universidade->incluiProfessor(novoProfessor);

	string depart;
	cout << "A Qual departamento esse Professor pertence ?" << endl;
	cin >> depart;

	Departamento* dp = objListaDepartamento->buscaDepartamento(depart);
	if (dp) dp->incluiProfessor(novoProfessor);
}

void Menu::criaAluno()
{
	string nome;
	int dia, mes, ano;
	int ID;
	int RA;

	cout << "Qual o nome do Aluno que será cadastrado ?" << endl;
	cin >> nome;
	cout << "Qual a data de nascimento do Novo Aluno ?" << endl;
	cin >> dia >> mes >> ano;
	cout << "Qual o ID do Aluno ?" << endl;
	cin >> ID;
	cout << "Qual o RA do Aluno ?" << endl;
	cin >> RA;

	Aluno* novoALuno = new Aluno(dia, mes, ano);
	novoALuno->setNome(nome);
	novoALuno->setID(ID);
	novoALuno->setRa(RA);

	string univ;
	cout << "Em Qual Universidade está cadastrado esse Aluno ?" << endl;
	cin >> univ;

	Universidade* universidade = objListaUniversidade->buscaUniv(univ);

	if (universidade)novoALuno->setUniversidade(universidade);

	string depart;
	cout << "A Qual departamento esse Aluno pertence ?" << endl;
	cin >> depart;

	Departamento* dp = objListaDepartamento->buscaDepartamento(depart);
	if (dp) novoALuno->setDepartamento(dp);

	int op = -1;

	while (op != 0)
	{
		string disciplina;
		cout << "Deseja cadastrar esse Aluno em alguma disciplina ?" << endl;
		cout << "1 SIM" << endl;
		cout << "0 Nao" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
			cout << "Qual o nome da Disciplina ?" << endl;
			cin >> disciplina;
			objListaDisciplina->buscaDisciplina(disciplina)->incluirAluno(novoALuno);
			break;
		case 0:
			cout << "Encerrando Cadastro de Disciplinas....." << endl;
			MenuPrin();
			break;

		default:
			cout << "Opção inválida,digite 1 ou 0....." << endl;
			break;
		}
	}
}



