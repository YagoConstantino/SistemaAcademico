#include "Disciplina.h"
#include "Departamento.h"
#include "ElAluno.h"
#include <iostream>

Disciplina::Disciplina(int na, std::string ac)
    : numeroAlunos(na), areaConhecimento(ac) 
{
    contAlunos = 0;
    pDeptoAssociado = nullptr;
    id = -1;
    objListaAluno = new ListaAluno();
}

Disciplina::~Disciplina() 
{
    pDeptoAssociado = nullptr;
    objListaAluno = nullptr;
}

bool Disciplina::incluirAluno(Aluno* pa) {
    pa->incluiDisciplina(this);
    pa->setDepartamento(this->getDepartamento());
    pa->setUniversidade(this->getDepartamento()->getUniversidade());
    return objListaAluno->incluirAluno(pa);
}

bool Disciplina::excluirAluno(Aluno* pa) {
    return objListaAluno->excluirAluno(pa);
}

void Disciplina::listarAlunosInicio() {
    objListaAluno->listarAlunosInicio(nome);
}

void Disciplina::listarAlunosFinal() {
    objListaAluno->listarAlunosFinal(nome);
}

ElAluno* Disciplina::getAlunoPrim()
{
    return objListaAluno->getAlunoPrim();
}
