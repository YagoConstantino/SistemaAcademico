#include "Universidade.h"
#include "Professor.h"
#include "ElProfessor.h"
#include <iostream>

Universidade::Universidade(std::string& name) {
    setNome(name);
    pDepartPrim = nullptr;
    pDepartAtual = nullptr;

    pProfessorPrim = nullptr;
    pProfessorAtual = nullptr;
}

Universidade::Universidade() {
    nome = " ";
    pDepartPrim = nullptr;
    pDepartAtual = nullptr;

    pProfessorPrim = nullptr;
    pProfessorAtual = nullptr;
}

Universidade::~Universidade() {
    // Liberar departamentos
    ElDepartamento* aux = pDepartPrim;
    while (aux != nullptr) {
        ElDepartamento* no = aux;
        aux = aux->getProx();
        delete no;
    }

    // Liberar professores
    ElProfessor* aux2 = pProfessorPrim;
    while (aux2 != nullptr) {
        ElProfessor* no = aux2;
        aux2 = aux2->getProx();
        delete no;
    }

    pDepartPrim = nullptr;
    pDepartAtual = nullptr;
    pProfessorPrim = nullptr;
    pProfessorAtual = nullptr;
}

bool Universidade::incluiDepart(Departamento* dp) {
    if (dp == nullptr) return false;  // Verificação de nulo

    ElDepartamento* el = new ElDepartamento();
    el->setDepartamento(dp);

    if (pDepartAtual == nullptr && pDepartPrim == nullptr) {
        pDepartAtual = pDepartPrim = el;
    }
    else {
        pDepartAtual->setProx(el);
        el->setAnte(pDepartAtual);
        pDepartAtual = el;
    }
    dp->setUniversidade(this);
    return true;
}

bool Universidade::removeDepart(Departamento* dp) {
    if (dp == nullptr) return false;  // Verificação de nulo

    ElDepartamento* aux = pDepartPrim;

    while (aux != nullptr && aux->getDepartamento()->getNome() != dp->getNome()) {
        aux = aux->getProx();
    }
    if (aux == nullptr) return false; // Departamento não encontrado

    // Ajustar ponteiros
    if (aux == pDepartPrim) {
        pDepartPrim = aux->getProx();
        if (pDepartPrim != nullptr) {
            pDepartPrim->setAnte(nullptr);
        }
    }
    else if (aux == pDepartAtual) {
        pDepartAtual = aux->getAnte();
        if (pDepartAtual != nullptr) {
            pDepartAtual->setProx(nullptr);
        }
    }
    else {
        if (aux->getAnte() != nullptr) {
            aux->getAnte()->setProx(aux->getProx());
        }
        if (aux->getProx() != nullptr) {
            aux->getProx()->setAnte(aux->getAnte());
        }
    }

    delete aux;
    return true;
}

void Universidade::listaDepartInicial() {
    ElDepartamento* aux = pDepartPrim;

    std::cout << "Departamentos da Universidade " << nome << " (inicio -> fim):" << std::endl;
    while (aux != nullptr) {
        std::cout << "O Departamento " << aux->getDepartamento()->getNome() << " faz parte da Universidade " << nome << std::endl;
        aux = aux->getProx();
    }
    std::cout << std::endl;
}

void Universidade::listaDepartFinal() {
    ElDepartamento* aux = pDepartAtual;

    std::cout << "Departamentos da Universidade " << nome << " (fim -> inicio):" << std::endl;
    while (aux != nullptr) {
        std::cout << "O Departamento " << aux->getDepartamento()->getNome() << " faz parte da Universidade " << nome << std::endl;
        aux = aux->getAnte();
    }
    std::cout << std::endl;
}

bool Universidade::incluiProfessor(Professor* pr) {
    if (pr == nullptr) return false;  // Verificação de nulo

    ElProfessor* el = new ElProfessor();
    el->setProfessor(pr);

    if (pProfessorAtual == nullptr && pProfessorPrim == nullptr) {
        pProfessorAtual = pProfessorPrim = el;
    }
    else {
        pProfessorAtual->setProx(el);
        el->setAnte(pProfessorAtual);
        pProfessorAtual = el;
    }
    pr->setUniv(this);
    return true;
}

bool Universidade::removeProfessor(Professor* pr) {
    if (pr == nullptr) return false;  // Verificação de nulo

    ElProfessor* aux = pProfessorPrim;
    while (aux != nullptr && aux->getProfessor()->getNome() != pr->getNome()) {
        aux = aux->getProx();
    }

    if (aux == nullptr) return false; // Professor não encontrado

    // Ajustar ponteiros
    if (aux == pProfessorPrim) {
        pProfessorPrim = aux->getProx();
        if (pProfessorPrim != nullptr) {
            pProfessorPrim->setAnte(nullptr);
        }
    }
    else if (aux == pProfessorAtual) {
        pProfessorAtual = aux->getAnte();
        if (pProfessorAtual != nullptr) {
            pProfessorAtual->setProx(nullptr);
        }
    }
    else {
        if (aux->getAnte() != nullptr) {
            aux->getAnte()->setProx(aux->getProx());
        }
        if (aux->getProx() != nullptr) {
            aux->getProx()->setAnte(aux->getAnte());
        }
    }

    delete aux;
    return true;
}

void Universidade::listaProfessorInicial() {
    ElProfessor* aux = pProfessorPrim;

    std::cout << "Professores da Universidade " << nome << " (inicio -> fim):" << std::endl;
    while (aux != nullptr) {
        std::cout << "O Professor " << aux->getProfessor()->getNome() << " Trabalha na Universidade "
            << nome << " no " << aux->getProfessor()->getDepart()->getNome() << std::endl;
        aux = aux->getProx();
    }
    std::cout << std::endl;
}

void Universidade::listaProfessorFinal() {
    ElProfessor* aux = pProfessorAtual;

    std::cout << "Professores da Universidade " << nome << " (fim -> inicio):" << std::endl;
    while (aux != nullptr) {
        std::cout << "O Professor " << aux->getProfessor()->getNome() << " Trabalha na Universidade " << nome << std::endl;
        aux = aux->getAnte();
    }
    std::cout << std::endl;
}
