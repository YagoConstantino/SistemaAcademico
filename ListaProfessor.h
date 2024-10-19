#pragma once
#include <iostream>
class Professor;
class ElProfessor;

class ListaProfessor
{
private:
	ElProfessor* pProfessorPrim;
	ElProfessor* pProfessorAtual;
public:
	ListaProfessor();
	~ListaProfessor();

	bool incluiProfessor(Professor* pr);
	bool excluiProfessor(Professor* pr);

	void listeProfessoresInicio(std::string& nome);
	void listeProfessoresFinal(std::string& nome);
};