#include "Turma.h"
#include "map"

Turma::Turma(string Classcode, string Uccode, int numeroAlunos){
    this->Classcode = Classcode;
    this->Uccode = Uccode;
    this->numeroAlunos = numeroAlunos;
}

string Turma::get_classcode() {return Classcode;}
string Turma::get_uccode() {return Uccode;}
int Turma::get_numeroalunos() const {return numeroAlunos;}

void Turma::adder() {this->numeroAlunos = this->get_numeroalunos() + 1;}

bool Turma::can_add(map<string, int> Max_students_by_UC){
    return (Max_students_by_UC[this->Uccode] - this->numeroAlunos+1 >= 4);
}

