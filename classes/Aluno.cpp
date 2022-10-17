#include "Aluno.h"
using namespace std;

Aluno::Aluno(int studentcode, string studentname, Horario horario): StudentCode(studentcode), StudentName(studentname), horarioAluno(horario){}

int Aluno::getStudentCode(){
    return StudentCode;
}
string Aluno::getStudentName(){
    return StudentName;
}
Horario Aluno::getHorario(){
    return horarioAluno;
}

void Aluno::setHorario(Horario horario){
    this->horarioAluno = horario;
}

