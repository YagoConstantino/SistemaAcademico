#include "Disciplina.h"
#include "Departamento.h"
#include "ElAluno.h"
#include <iostream>

Disciplina::Disciplina(int na, std::string ac)
    : numeroAlunos(na), areaConhecimento(ac) {
    contAlunos = 0;
    pDeptoAssociado = nullptr;
    pAlunoPrim = nullptr;
    pAlunoAtual = nullptr;
    pProx = nullptr;
    pAnte = nullptr;
    id = -1;
}

Disciplina::~Disciplina() {
    ElAluno* aux = pAlunoPrim;
    while (aux != nullptr) {
        ElAluno* no = aux;
        aux = aux->getProx();
        delete no;
    }
    pAlunoPrim = pAlunoAtual = nullptr;
}

bool Disciplina::incluirAluno(Aluno* pa) {
    if (contAlunos >= numeroAlunos) {
        std::cout << "Disciplina cheia! Não é possível adicionar mais alunos." << std::endl;
        return false;
    }

    ElAluno* el = new ElAluno();
    el->setAluno(pa);

    if (pAlunoPrim == nullptr) {
        pAlunoPrim = el;
        pAlunoAtual = el;
    }
    else {
        pAlunoAtual->setProx(el);
        el->setAnte(pAlunoAtual);
        pAlunoAtual = el;
    }

    contAlunos++;
    return true;
}

bool Disciplina::excluirAluno(Aluno* pa) {
    ElAluno* aux = pAlunoPrim;

    while (aux != nullptr && aux->getAluno()->getID() != pa->getID()) {
        aux = aux->getProx();
    }

    if (aux == nullptr) return false;

    if (aux == pAlunoPrim) {
        pAlunoPrim = aux->getProx();
        if (pAlunoPrim != nullptr) pAlunoPrim->setAnte(nullptr);
    }
    else if (aux == pAlunoAtual) {
        pAlunoAtual = aux->getAnte();
        if (pAlunoAtual != nullptr) pAlunoAtual->setProx(nullptr);
    }
    else {
        aux->getAnte()->setProx(aux->getProx());
        aux->getProx()->setAnte(aux->getAnte());
    }

    delete aux;
    contAlunos--;
    return true;
}

void Disciplina::listarAlunosInicio() {
    ElAluno* aux = pAlunoPrim;
    std::cout << "Alunos da disciplina " << nome << " (início -> fim):" << std::endl;

    while (aux != nullptr) {
        std::cout << " - " << aux->getAluno()->getNome() << std::endl;
        aux = aux->getProx();
    }
}

void Disciplina::listarAlunosFinal() {
    ElAluno* aux = pAlunoAtual;
    std::cout << "Alunos da disciplina " << nome << " (fim -> início):" << std::endl;

    while (aux != nullptr) {
        std::cout << " - " << aux->getAluno()->getNome() << std::endl;
        aux = aux->getAnte();
    }
}
