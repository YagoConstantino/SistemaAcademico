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

void ListaAluno::listarAlunosInicio(std::string& nome) {
    ElAluno* aux = pAlunoPrim;
    std::cout << "Alunos da disciplina " << nome << " (inicio -> fim):" << std::endl;

    while (aux != nullptr) {
        std::cout << " - " << aux->getAluno()->getNome() << std::endl;
        aux = aux->getProx();
    }
    std::cout << std::endl;
}

void ListaAluno::listarAlunosFinal(std::string& nome) {
    ElAluno* aux = pAlunoAtual;
    std::cout << "Alunos da disciplina " << nome << " (fim -> inicio):" << std::endl;

    while (aux != nullptr) {
        std::cout << " - " << aux->getAluno()->getNome() << std::endl;
        aux = aux->getAnte();
    }
    std::cout << std::endl;
}

ElAluno* ListaAluno::buscaAluno(std::string& nome)
{
    ElAluno* aux = pAlunoPrim;

    while (aux != nullptr)
    {
        if (aux->getAluno()->getNome() == nome) return aux;
        else aux = aux->getProx();
    }
    std::cout << "Não encontrado o Aluno" << std::endl;
    return nullptr;
}
