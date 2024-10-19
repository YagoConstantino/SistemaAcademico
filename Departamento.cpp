#include "Departamento.h"
#include "ElDisciplina.h"
#include "Universidade.h"
#include <iostream>
#include "ElProfessor.h"
#include "Professor.h"
Departamento::Departamento()
{
	nome = " ";
	pUniv = nullptr;
    objListaDisciplina = new ListaDisciplina();
    objListaProfessor = new ListaProfessor();

}

Departamento::~Departamento()
{
	pUniv = nullptr;
    delete objListaDisciplina;
    delete objListaProfessor;
}

bool Departamento::incluiDisciplina(Disciplina* pd) 
{
    pd->setDepartamento(this);
    return objListaDisciplina->incluiDisciplina(pd);
}

bool Departamento::removeDisciplina(Disciplina* pd) 
{
    return objListaDisciplina->removeDisciplina(pd);
}

void Departamento::listeDisciplinasInicio() {
    objListaDisciplina->listeDisciplinasInicio();
}

void Departamento::listeDisciplinasFinal() 
{
    objListaDisciplina->listeDisciplinasFinal();
}

bool Departamento::incluiProfessor(Professor* pr) {
    pr->setDepartamento(this);
    return objListaProfessor->incluiProfessor(pr);
}

bool Departamento::excluiProfessor(Professor* pr) 
{
    return objListaProfessor->excluiProfessor(pr);
}

void Departamento::listeProfessoresInicio() {
    objListaProfessor->listeProfessoresInicio(nome);
}

void Departamento::listeProfessoresFinal() {
    objListaProfessor->listeProfessoresFinal(nome);
}
