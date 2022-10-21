#ifndef AED_1_ALUNO_H
#define AED_1_ALUNO_H

#include <string>
#include <vector>
#include "Horario.h"
using namespace std;

class Aluno {
    private:
        int StudentCode;
        string StudentName;
        Horario horarioAluno;
    public:
        Aluno();
        Aluno(int StudentCode, string StudentName, Horario horario);
        int getStudentCode() const;
        string getStudentName();
        Horario getHorario();
        void setStudentCode(int studentcode);
        void setStudentName(string studentname);
        void setHorario(Horario horario);
        bool operator<(const Aluno&) const;
        bool operator>(const Aluno&) const;
};

#endif
