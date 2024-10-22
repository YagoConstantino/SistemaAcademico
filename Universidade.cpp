#include "Universidade.h"
#include "Professor.h"
#include "ElProfessor.h"
#include "ElDepartamento.h"
#include <iostream>

Universidade::Universidade(std::string& name) 
{
    setNome(name);
    objListaDepartamento = new ListaDepartamento();

    objListaProfessor = new ListaProfessor();
}

Universidade::Universidade()
{
    nome = " ";
    objListaDepartamento = new ListaDepartamento();

    objListaProfessor = new ListaProfessor();
}

Universidade::~Universidade() 
{

    delete objListaDepartamento;
    delete objListaProfessor;
}

bool Universidade::incluiDepart(Departamento* dp)
{
    
    dp->setUniversidade(this);
    return objListaDepartamento->incluiDepart(dp);;
}

bool Universidade::removeDepart(Departamento* dp)
{
    
    return objListaDepartamento->removeDepart(dp);;
}

void Universidade::listaDepartInicial()
{
    objListaDepartamento->listaDepartInicial();
}

void Universidade::listaDepartFinal()
{
    objListaDepartamento->listaDepartFinal();
}

bool Universidade::incluiProfessor(Professor* pr) 
{
    
    pr->setUniv(this);
    return objListaProfessor->incluiProfessor(pr);
}

bool Universidade::removeProfessor(Professor* pr) 
{


    return objListaProfessor->excluiProfessor(pr);
}

void Universidade::listaProfessorInicial() {
    
    objListaProfessor->listeProfessoresInicio();
}

void Universidade::listaProfessorFinal()
{
    objListaProfessor->listeProfessoresFinal();
}
