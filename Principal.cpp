#include "Principal.h"
#include <Windows.h>

Principal::Principal()
{
	srand(time(NULL));
	inicializaUniversidade();
	inicializaDepartamento();
	inicializaDisciplina();
	inicializaProfessor();
	inicializaAluno();
	Executar();
}

Principal::~Principal()
{

}

void Principal::inicializaUniversidade()
{
	UTFPR.setNome("Universidade Tecnologica do Parana");
	UTFPR.incluiDepart(&DAINF);
	UTFPR.incluiDepart(&DAMAT);

	UTFPR.incluiProfessor(&Simao);
	UTFPR.incluiProfessor(&Leyza);
	UTFPR.incluiProfessor(&Thais);
	UTFPR.incluiProfessor(&Dorini);
}

void Principal::inicializaProfessor()
{
	Simao.inicializa(15, 10, 1975);
	Leyza.inicializa(12, 7, 1985);
	Thais.inicializa(27, 4, 1987);
	Dorini.inicializa(12, 3, 1984);
	
	Simao.setNome("Jean Simao");
	Leyza.setNome("Leyza Dorini");
	Thais.setNome("Thais Bimbergut");
	Dorini.setNome("Dorini");

	Simao.setDepartamento(&DAINF);
	Leyza.setDepartamento(&DAINF);

	Thais.setDepartamento(&DAMAT);
	Dorini.setDepartamento(&DAMAT);


}

void Principal::inicializaDepartamento()
{
	DAINF.setNome("Departamento de Informatica");
	DAMAT.setNome("Departamento de Matematica");

	DAINF.incluiDisciplina(&TecProg);
	DAINF.incluiDisciplina(&FundProg);

	DAMAT.incluiDisciplina(&Algebra);
	DAMAT.incluiDisciplina(&Calculo);

}

void Principal::inicializaDisciplina()
{
	Algebra.setNome("Algebra Linear");
	Calculo.setNome("Calculo Diferencial e Integral 1");

	TecProg.setNome("Tecnicas de Programacao");
	FundProg.setNome("Fundamentos de Programacao");

	Algebra.setArea("Fundamentos de Matematica Computacional");
	Calculo.setArea("Fundamentos de Matematica");
	TecProg.setArea("Programacao Essencial");
	FundProg.setArea("Programacao Essencial");

	Algebra.setID(1);
	Calculo.setID(2);
	TecProg.setID(3);
	FundProg.setID(4);

	Algebra.incluirAluno(&A);
	Algebra.incluirAluno(&B);
	Algebra.incluirAluno(&C);
	Algebra.incluirAluno(&D);

	Calculo.incluirAluno(&A);
	Calculo.incluirAluno(&B);
	Calculo.incluirAluno(&C);

	TecProg.incluirAluno(&A);
	TecProg.incluirAluno(&C);
	TecProg.incluirAluno(&D);

	FundProg.incluirAluno(&B);
	FundProg.incluirAluno(&C);
	FundProg.incluirAluno(&D);

}

void Principal::inicializaAluno()
{
	A.inicializa(15, 2, 2002);
	B.inicializa(25, 6, 2003);
	C.inicializa(22, 12, 2002);
	D.inicializa(22, 3, 2004);

	A.setNome("Amanda");
	B.setNome("Bruno");
	C.setNome("Camila");
	D.setNome("Daniel");

}

void Principal::CalcIdade()
{
	Simao.calcIdade(diaH, mesH, anoH);
	Leyza.calcIdade(diaH, mesH, anoH);
	Thais.calcIdade(diaH, mesH, anoH);
	Dorini.calcIdade(diaH, mesH, anoH);

	A.calcIdade(diaH, mesH, anoH);
	B.calcIdade(diaH, mesH, anoH);
	C.calcIdade(diaH, mesH, anoH);
	D.calcIdade(diaH, mesH, anoH);
}

void Principal::listaDepartamento()
{
	printf("Departamentos e Professores da UTFPR\n");
	UTFPR.listaDepartInicial();
	UTFPR.listaProfessorInicial();
	system("pause");
	system("cls");
}

void Principal::listaDisciplina()
{
	printf("\nDisciplinas dos Departamentos\n");
	DAINF.listeDisciplinasInicio();
	DAMAT.listeDisciplinasInicio();
	system("pause");
	system("cls");
}

void Principal::listaAluno()
{
	printf("\nAlunos nas Disciplinas \n");
	Algebra.listarAlunosInicio();
	Calculo.listarAlunosInicio();
	TecProg.listarAlunosInicio();
	FundProg.listarAlunosInicio();
	system("pause");
	system("cls");
}

void Principal::listaDisciplinaAluno()
{
	printf("\nDisciplinas de Cada Aluno\n");
	A.listeDisciplinasInicio();
	B.listeDisciplinasInicio();
	C.listeDisciplinasInicio();
	D.listeDisciplinasInicio();
	system("pause");
	system("cls");
}

void Principal::notasAlunos()
{
	
	ElAluno* aux = FundProg.getAlunoPrim();
	while (aux != nullptr)
	{
		aux->setN1(static_cast<float>(rand() % 11));
		aux->setN2(static_cast<float>(rand() % 11));
		std::cout << "O Aluno " << aux->getAluno()->getNome()
			<< " tem media Final em Fundamentos da Programacao: "
			<< aux->getNFinal() << std::endl;
		aux = aux->getProx();
	}

	
	aux = TecProg.getAlunoPrim();
	while (aux != nullptr)
	{
		aux->setN1(static_cast<float>(rand() % 11)); 
		aux->setN2(static_cast<float>(rand() % 11));
		std::cout << "O Aluno " << aux->getAluno()->getNome()
			<< " tem media Final em Tecnicas de Programacao: "
			<< aux->getNFinal() << std::endl;
		aux = aux->getProx();
	}

	
	aux = Algebra.getAlunoPrim();
	while (aux != nullptr)
	{
		aux->setN1(static_cast<float>(rand() % 11));
		aux->setN2(static_cast<float>(rand() % 11));
		std::cout << "O Aluno " << aux->getAluno()->getNome()
			<< " tem media Final em Algebra: "
			<< aux->getNFinal() << std::endl;
		aux = aux->getProx();
	}

	
	aux = Calculo.getAlunoPrim();
	while (aux != nullptr)
	{
		aux->setN1(static_cast<float>(rand() % 11));
		aux->setN2(static_cast<float>(rand() % 11));
		std::cout << "O Aluno " << aux->getAluno()->getNome()
			<< " tem media Final em Calculo: "
			<< aux->getNFinal() << std::endl;
		aux = aux->getProx();
	}
}


void Principal::Executar()
{
	SYSTEMTIME st;
	GetLocalTime(&st);

	diaH = st.wDay;
	mesH = st.wMonth;
	anoH = st.wYear;

	CalcIdade();
	listaDepartamento();
	listaDisciplina();
	listaAluno();
	listaDisciplinaAluno();
	notasAlunos();

}
