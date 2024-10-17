#pragma once
#include <string>
class Pessoa
{
protected:
	int ID;
	int diaP;
	int mesP;
	int anoP;
	int idadeP;
	std::string nome;

public:
	Pessoa(int dia, int mes, int ano);
	Pessoa();
	~Pessoa();

	void inicializa(int diaNa, int mesNa, int anoNa);
	void calcIdade(int diaAt, int mesAt, int anoAt);
	int getIdade() { return idadeP; }

	void setNome(std::string& name) { nome = name; };
	std::string& getNome() { return nome; };

	void setID(int id) { ID = id; };
	int getID() { return ID; };


};
