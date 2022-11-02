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
string Aluno::getStudentName() const {return StudentName;}
Horario& Aluno::getHorario() {return horarioAluno;}
int Aluno::getNUCS() const {return NUCS;}

void Aluno::setNUCS(int NUCS) {this->NUCS = NUCS;}
void Aluno::setHorario(Horario& horario) {this->horarioAluno = horario;}
void Aluno::setStudentCode(int studentcode) {this->StudentCode = studentcode;}
void Aluno::setStudentName(std::string studentname) {this->StudentName = studentname;}

bool Aluno::operator<(const Aluno &other) const {return (this->getStudentCode()<other.getStudentCode());}
bool Aluno::operator>(const Aluno &other) const {return (this->getStudentCode()>other.getStudentCode());}

void Aluno::removeUcs() {this->NUCS -= 1;}
void Aluno::addUcs() {this->NUCS += 1;}

bool Aluno::verificar(Aula aula_1, Horario horario){
    vector<Aula> aulas = horario.getAulas();
    if (aula_1.get_Type()=="T") return true;
    for (Aula aula : aulas){
        if ((aula.get_Type() == "TP" or aula.get_Type() == "PL") and (aula_1.get_WeekDay()==aula.get_WeekDay()) and aula_1.get_Type()!=aula.get_Type()){
            if (aula_1.get_StartHour() + aula_1.get_Duration() > aula.get_StartHour() and aula_1.get_StartHour()< aula.get_StartHour() +aula.get_Duration())
                return false;
            if (aula.get_StartHour() + aula.get_Duration() > aula_1.get_StartHour() and aula.get_StartHour()< aula_1.get_StartHour() + aula_1.get_Duration())
                return false;
        }
    }
    return true;
}