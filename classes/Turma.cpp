#include "Turma.h"
#include "map"

Turma::Turma(){
    this->Classcode = "";
    this->Uccode = "";
    this->numeroAlunos = 0;
}
Turma::Turma(string Classcode, string Uccode, int numeroAlunos){
    this->Classcode = Classcode;
    this->Uccode = Uccode;
    this->numeroAlunos = numeroAlunos;
}

string Turma::get_classcode() {return Classcode;}
string Turma::get_uccode() {return Uccode;}
int Turma::get_numeroalunos() const {return numeroAlunos;}
void Turma::set_numeroalunos_0() {this->numeroAlunos=0;}

void Turma::adder() {this->numeroAlunos = this->get_numeroalunos() + 1;}

void Turma::sub() {this->numeroAlunos = this->get_numeroalunos() - 1;}

bool Turma::can_add(map<string, int> Max_students_by_UC, Turma turma){
    if ( turma.get_classcode() != ""){
        return( (Max_students_by_UC[this->Uccode] >= this->numeroAlunos+1) and (Max_students_by_UC[this->Uccode] - this->numeroAlunos+ 1  <= 4)
            and (Max_students_by_UC[this->Uccode] - turma.get_numeroalunos() - 1 <= 4));
    }
    return  ((Max_students_by_UC[this->Uccode] >= this->numeroAlunos+1) and (Max_students_by_UC[this->Uccode] - this->numeroAlunos+ 1  <= 4));
}
