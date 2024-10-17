#pragma once
#include <iostream>
#include "Universidade.h"
#include "Departamento.h"
#include "Professor.h"
#include "Aluno.h"
#include "Disciplina.h"

class Principal {
private:
    Universidade* universidades[3];
    int totalProfessores = 6;
    int totalAlunos = 24;

    void criarUniversidades() {
        universidades[0] = new Universidade("Cambridge");
        universidades[1] = new Universidade("Oxford");
        universidades[2] = new Universidade("Princeton");
    }

    void criarDepartamentos() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                Departamento* departamento = new Departamento();
                departamento->setNome("Departamento " + std::to_string(j + 1));
                universidades[i]->incluiDepart(departamento);
                criarDisciplinas(departamento);
            }
        }
    }

    void criarProfessores() {
        for (int i = 0; i < totalProfessores; ++i) {
            Professor* professor = new Professor("Professor " + std::to_string(i + 1));
            universidades[i % 3]->incluiProfessor(professor);
        }
    }

    void criarAlunos() {
        for (int i = 0; i < totalAlunos; ++i) {
            Aluno* aluno = new Aluno("Aluno " + std::to_string(i + 1));
            universidades[i % 3]->incluiAluno(aluno);
        }
    }

    void criarDisciplinas(Departamento* departamento) {
        for (int i = 0; i < 2; ++i) {
            Disciplina* disciplina = new Disciplina("Disciplina " + std::to_string(i + 1));
            departamento->incluiDisciplina(disciplina);
        }
    }

public:
    Principal() {
        criarUniversidades();
        criarDepartamentos();
        criarProfessores();
        criarAlunos();
    }

    ~Principal() {
        for (int i = 0; i < 3; ++i) {
            delete universidades[i];
        }
    }

    void listarUniversidades() {
        for (int i = 0; i < 3; ++i) {
            std::cout << "Universidade: " << universidades[i]->getNome() << std::endl;
            universidades[i]->listaDepartInicial();
            universidades[i]->listaProfessorInicial();
        }
    }
};

int main() {
    Principal principal;
    principal.listarUniversidades();
    return 0;
}
