#include "Turma.h"

Turma::Turma(string Classcode,string Uccode,int numeroAlunos){
    this->Classcode = Classcode;
    this->Uccode = Uccode;
    this->numeroAlunos = numeroAlunos;
}

string Turma::get_classcode() {return Classcode;}
string Turma::get_uccode() {return Uccode;}
int Turma::get_numeroalunos() {return numeroAlunos;}

void Turma::adder() {this->numeroAlunos = this->get_numeroalunos() + 1;}


