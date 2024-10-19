#pragma once
#include "Departamento.h"
#include "ListaDepartamento.h"
#include <string>
#include "ListaProfessor.h"

class Professor;
class ElProfessor;
class ElDepartamento;
class Universidade
	{
	private:
		std::string nome;

		ListaDepartamento* objListaDepartamento;

		ListaProfessor* objListaProfessor;

	public:

		Universidade(std::string& name);
		Universidade();
		~Universidade();

		void setNome(std::string name){ nome = name; }
		std::string& getNome() { return nome; };

		bool incluiDepart(Departamento* dp);
		bool removeDepart(Departamento* dp);
		void listaDepartInicial();
		void listaDepartFinal();

		bool incluiProfessor(Professor* pr);
		bool removeProfessor(Professor* pr);
		void listaProfessorInicial();
		void listaProfessorFinal();
	};