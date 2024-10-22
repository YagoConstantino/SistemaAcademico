#include "ListaAluno.h"
#include <iostream>

ListaAluno::ListaAluno(int na) {
    pAlunoPrim = nullptr;
    pAlunoAtual = nullptr;
    numeroAlunos = na;
    contAlunos = 0;
}

ListaAluno::~ListaAluno() {
    ElAluno* aux = pAlunoPrim;
    while (aux != nullptr) {
        ElAluno* temp = aux;
        aux = aux->getProx();
        delete temp;
    }
}

bool ListaAluno::incluirAluno(Aluno* pa) {
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

bool ListaAluno::excluirAluno(Aluno* pa) {
    ElAluno* aux = pAlunoPrim;

    while (aux != nullptr && aux->getAluno()->getID() != pa->getID())
    {
        aux = aux->getProx();
    }

    if (aux == nullptr) 
    {
        std::cout << "Aluno não encontrado." << std::endl;
        return false;
    }

    if (aux == pAlunoPrim) 
    {
        pAlunoPrim = aux->getProx();
        if (pAlunoPrim != nullptr) pAlunoPrim->setAnte(nullptr);
    }
    else if (aux == pAlunoAtual) 
    {
        pAlunoAtual = aux->getAnte();
        if (pAlunoAtual != nullptr) pAlunoAtual->setProx(nullptr);
    }
    else 
    {
        aux->getAnte()->setProx(aux->getProx());
        aux->getProx()->setAnte(aux->getAnte());
    }

    delete aux;
    contAlunos--;
    return true;
}

void ListaAluno::listarAlunosInicio() {
    ElAluno* aux = pAlunoPrim;
    

    while (aux != nullptr) {
        std::cout << " - " << aux->getAluno()->getNome() << std::endl;
        std::cout << "Disciplinas do Aluno :" << std::endl;
        aux->getAluno()->listeDisciplinasInicio();
        aux = aux->getProx();
    }
    std::cout << std::endl;
}

void ListaAluno::listarAlunosFinal() {
    ElAluno* aux = pAlunoAtual;

    while (aux != nullptr) {
        std::cout << " - " << aux->getAluno()->getNome() << std::endl;
        std::cout << "Disciplinas do Aluno :" << std::endl;
        aux->getAluno()->listeDisciplinasInicio();
        aux = aux->getAnte();
    }
    std::cout << std::endl;
}

Aluno* ListaAluno::buscaAluno(std::string& nome)
{
    ElAluno* aux = pAlunoPrim;

    while (aux != nullptr)
    {
        if (aux->getAluno()->getNome() == nome) return aux->getAluno();
        else aux = aux->getProx();
    }
    std::cout << "Não encontrado o Aluno" << std::endl;
    return nullptr;
}
