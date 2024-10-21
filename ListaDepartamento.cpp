#include "ListaDepartamento.h"

ListaDepartamento::ListaDepartamento()
{
	pDepartAtual = pDepartPrim = nullptr;
}

ListaDepartamento::~ListaDepartamento()
{
    // Liberar departamentos
    ElDepartamento* aux = pDepartPrim;
    while (aux != nullptr) {
        ElDepartamento* no = aux;
        aux = aux->getProx();
        delete no;
    }
}

bool ListaDepartamento::incluiDepart(Departamento* dp) {
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
 
    return true;
}

bool ListaDepartamento::removeDepart(Departamento* dp) {
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

void ListaDepartamento::listaDepartInicial() {
    ElDepartamento* aux = pDepartPrim;

    std::cout << "Departamentos da Universidade " << aux->getDepartamento()->getNomeUniversidade()
        << " (inicio -> fim):" << std::endl;
    while (aux != nullptr) {
        std::cout << aux->getDepartamento()->getNome() << " faz parte da Universidade " << 
        aux->getDepartamento()->getNomeUniversidade() << std::endl;
        aux = aux->getProx();
    }
    std::cout << std::endl;
}

void ListaDepartamento::listaDepartFinal() {
    ElDepartamento* aux = pDepartAtual;

    std::cout << "Departamentos da Universidade " << aux->getDepartamento()->getNomeUniversidade() << " (fim -> inicio):" << std::endl;
    while (aux != nullptr) {
        std::cout << aux->getDepartamento()->getNome() << " faz parte da Universidade " <<
        aux->getDepartamento()->getNomeUniversidade() << std::endl;
        aux = aux->getAnte();
    }
    std::cout << std::endl;
}

Departamento* ListaDepartamento::buscaDepart(std::string& nome)
{
    ElDepartamento* aux = pDepartPrim;

    while (aux != nullptr && aux->getDepartamento()->getNome() != nome)
    {
        aux = aux->getProx();

    }
    if (aux == nullptr) return nullptr;
    return aux->getDepartamento();
}

