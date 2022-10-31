#include "Aluno.h"
#include "Turma.h"
using namespace std;

Aluno::Aluno(){
    StudentCode = 0;
    StudentName = "";
    horarioAluno = Horario();
}

Aluno::Aluno(int studentcode, string studentname, Horario horario, int NUCS): StudentCode(studentcode), StudentName(studentname), horarioAluno(horario), NUCS(NUCS){}

int Aluno::getStudentCode() const {return StudentCode;}
string Aluno::getStudentName() {return StudentName;}
Horario& Aluno::getHorario() {return horarioAluno;}
int Aluno::getNUCS() const {return NUCS;}

void Aluno::setNUCS(int NUCS) {this->NUCS = NUCS;}
void Aluno::setHorario(Horario& horario) {this->horarioAluno = horario;}
void Aluno::setStudentCode(int studentcode) {this->StudentCode = studentcode;}
void Aluno::setStudentName(std::string studentname) {this->StudentName = studentname;}
bool Aluno::operator<(const Aluno &other) const {return (this->getStudentCode()<other.getStudentCode());}
bool Aluno::operator>(const Aluno &other) const {return (this->getStudentCode()>other.getStudentCode());}
void Aluno::removeUcs(){this->NUCS -= 1;}