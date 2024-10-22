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
	Executar();
}

Menu::~Menu()
{
	delete objListaAluno;
	delete objListaDepartamento;
	delete objListaDisciplina;
	delete objListaProfessor;
	delete objListaUniversidade;
}

void Menu::CadUniversidade()
{
	string nome;
	Universidade* puniv = nullptr;

	cout << "Qual o nome da Universidade ?" << endl;
	cin >> nome;

	puniv = new Universidade(nome);
	puniv->setNome(nome);
	objListaUniversidade->incluiUniversidade(puniv);

}

void Menu::CadDepartamento()
{
	string nomeUniversidade;
	string nomeDepartamento;
	Universidade* pUniv = nullptr;
	Departamento* pDepart = nullptr;

	objListaUniversidade->listaUniversidadeInicio();

	cout << "Qual o nome da Universidade do novo Departamento ?" << endl;
	cin >> nomeUniversidade;
	pUniv = objListaUniversidade->buscaUniv(nomeUniversidade);

	if (pUniv != nullptr)
	{
		cout << "Qual o nome do Departamento ?" << endl;
		cin >> nomeDepartamento;

		pDepart = new Departamento();
		pDepart->setNome(nomeDepartamento);
		pDepart->setUniversidade(pUniv);
		objListaDepartamento->incluiDepart(pDepart);
		pUniv->incluiDepart(pDepart);

	}
	else
	{
		cout << "Universidade inexistente" << endl;
	}

}

void Menu::CadDisciplina()
{
	string nomeDisciplina;
	string nomeUniversidade;
	string nomeDepartamento;
	string areaDeConhecimneto;

	Disciplina* pDisciplina = nullptr;
	Universidade* pUniversidade = nullptr;
	Departamento* pDepart = nullptr;

	objListaUniversidade->listaUniversidadeInicio();

	cout << "Qual o nome da Universidade da nova Disciplina ?" << endl;
	cin >> nomeUniversidade;

	pUniversidade = objListaUniversidade->buscaUniv(nomeUniversidade);

	if (pUniversidade != nullptr)
	{
		objListaDepartamento->listaDepartInicial();
		cout << "Qual o nome do Departamento dessa Disciplina ?" << endl;
		cin >> nomeDepartamento;

		pDepart = objListaDepartamento->buscaDepartamento(nomeDepartamento);

		if (pDepart != nullptr)
		{
			cout << "Qual o nome da Disciplina a ser cadastrada ?" << endl;
			cin >> nomeDisciplina;

			cout << "Qual a area de conhecimento da Disciplina a ser cadastrada ?" << endl;
			cin >> areaDeConhecimneto;


			pDisciplina = new Disciplina();
			pDisciplina->setNome(nomeDisciplina);
			pDisciplina->setArea(areaDeConhecimneto);
			pDisciplina->setDepartamento(pDepart);
			
			objListaDisciplina->incluiDisciplina(pDisciplina);
			pDepart->incluiDisciplina(pDisciplina);
			
		}
		else
		{
			cout << "Departamento Invalido" << endl;
		}
	}
	else
	{
		cout << "Universidade invalida" << endl;
	}


}

void Menu::CadProfessor()
{
	string nomeProfessor;
	string nomeUniversidade;
	string nomeDepartamento;

	Professor* pProf = nullptr;
	Universidade* pUniv = nullptr;
	Departamento* pDepart = nullptr;
	int dia = 0, mes = 0, ano = 0;

	objListaUniversidade->listaUniversidadeInicio();

	cout << "Qual o nome da Universidade que esse Professor trabalha ?" << endl;
	cin >> nomeUniversidade;

	pUniv = objListaUniversidade->buscaUniv(nomeUniversidade);

	if (pUniv != nullptr)
	{
		objListaDepartamento->listaDepartInicial();

		cout << "Qual o nome do Departamento onde esse Professor Trabalha ?" << endl;
		cin >> nomeDepartamento;

		pDepart = objListaDepartamento->buscaDepartamento(nomeDepartamento);

		if (pDepart != nullptr)
		{
			cout << "Qual o nome do Professor a ser cadastrado ?" << endl;
			cin >> nomeProfessor;

			cout << "Qual a data de Nascimento do Professor ? dd//mm/aaaa" << endl;
			cin >> dia >> mes >> ano;

			pProf = new Professor(dia, mes, ano);
			pProf->setNome(nomeProfessor);
			pProf->setDepartamento(pDepart);
			pProf->setUniv(pUniv);
			pProf->calcIdade(diaAT, mesAT, anoAT);

			objListaProfessor->incluiProfessor(pProf);

			pDepart->incluiProfessor(pProf);
			pUniv->incluiProfessor(pProf);
		}
		else
		{
			cout << "Departamento inválido" << endl;
		}

	}
	else
	{
		cout << "Universidade Invalida" << endl;
	}

}

void Menu::CadAluno()
{
	string nomeAluno;
	string nomeUniversidade;
	string nomeDepart;
	string nomeDisciplina;

	Aluno* pAluno = nullptr;
	Universidade* pUniversidade = nullptr;
	Departamento* pDepart = nullptr;
	Disciplina* pDisciplina = nullptr;

	int dia = 0, mes = 0, ano = 0;
	int ra = -1;

	objListaUniversidade->listaUniversidadeInicio();

	cout << "Qual o nome da Universidade que esse Aluno Estuda  ?" << endl;
	cin >> nomeUniversidade;

	pUniversidade = objListaUniversidade->buscaUniv(nomeUniversidade);

	if (pUniversidade != nullptr)
	{
		objListaDepartamento->listaDepartInicial();

		cout << "Qual o nome do Departamento onde esse Aluno Estuda ?" << endl;
		cin >> nomeDepart;

		pDepart = objListaDepartamento->buscaDepartamento(nomeDepart);

		if (pDepart != nullptr)
		{
			cout << "Qual o nome do Aluno a ser cadastrado ?" << endl;
			cin >> nomeAluno;

			cout << "Qual a data de Nascimento do Aluno ? dd//mm/aaaa" << endl;
			cin >> dia >> mes >> ano;

			cout << "Qual o Registro Academido desse Aluno ?" << endl;
			cin >> ra;

			pAluno = new Aluno(dia, mes, ano);
			pAluno->setNome(nomeAluno);
			pAluno->setDepartamento(pDepart);
			pAluno->setUniversidade(pUniversidade);
			pAluno->calcIdade(diaAT, mesAT, anoAT);
			objListaAluno->incluirAluno(pAluno);

			pAluno->setRa(ra);

			while (true)
			{
				objListaDisciplina->listeDisciplinasInicio();

				cout << "Digite o nome da disciplina que o Aluno deseja cadastrar (ou 'sair' para encerrar): ";
				cin >> nomeDisciplina;

				if (nomeDisciplina == "sair")
				{
					break;
				}

				pDisciplina = objListaDisciplina->buscaDisciplina(nomeDisciplina);

				if (pDisciplina != nullptr)
				{

					pDisciplina->incluirAluno(pAluno);
					pAluno->incluiDisciplina(pDisciplina);
				}
				else
				{
					cout << "Disciplina não encontrada." << endl;
				}

			}
		}
		else
		{
			cout << "Departamento inválido" << endl;
		}

	}
	else
	{
		cout << "Universidade Invalida" << endl;
	}

}


void Menu::MenuPrin()
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

void Menu::MenuCad()
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

void Menu::MenuExe()
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

void Menu::Executar()
{
	MenuPrin();
}
