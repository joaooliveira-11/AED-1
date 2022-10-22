#include "Aluno.h"
using namespace std;

Aluno::Aluno(){
    StudentCode = 0;
    StudentName = "";
    horarioAluno = Horario();
}

Aluno::Aluno(int studentcode, string studentname, Horario horario): StudentCode(studentcode), StudentName(studentname), horarioAluno(horario){}

int Aluno::getStudentCode() const {return StudentCode;}
string Aluno::getStudentName() {return StudentName;}
Horario Aluno::getHorario() {return horarioAluno;}

void Aluno::setHorario(Horario horario) {this->horarioAluno = horario;}
void Aluno::setStudentCode(int studentcode) {this->StudentCode = studentcode;}
void Aluno::setStudentName(std::string studentname) {this->StudentName = studentname;}
bool Aluno::operator<(const Aluno &other) const{
    return (this->getStudentCode()<other.getStudentCode());
}
bool Aluno::operator>(const Aluno &other) const{
    return (this->getStudentCode()>other.getStudentCode());
}

