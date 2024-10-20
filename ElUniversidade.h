#pragma once
#include "Universidade.h"

class ElUniversidade
{
	private:
		Universidade* pUniv;
		ElUniversidade* pUniversidadeAnte;
		ElUniversidade* pUniversidadeProx;

	public:
		ElUniversidade();
		~ElUniversidade();

		void setPuniv(Universidade* pu) { pUniv = pu; }
		Universidade* getUniv() { return pUniv; }

		void setAnte(ElUniversidade* el) { pUniversidadeAnte = el; }
		ElUniversidade* getAnte() { return pUniversidadeAnte; }

		void setProx(ElUniversidade* el) { pUniversidadeProx = el; }
		ElUniversidade* getProx() { return pUniversidadeProx; }

};