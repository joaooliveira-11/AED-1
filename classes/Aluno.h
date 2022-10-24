#ifndef AED_1_ALUNO_H
#define AED_1_ALUNO_H

#include <string>
#include <vector>
#include <set>
#include "Horario.h"
using namespace std;

class Aluno {
    private:
        int StudentCode;
        string StudentName;
        Horario horarioAluno;
        int NUCS;
    public:
        Aluno();
        Aluno(int StudentCode, string StudentName, Horario horario, int NUCS);
        int getStudentCode() const;
        string getStudentName();
        Horario getHorario();
        int getNUCS();
        void setStudentCode(int studentcode);
        void setStudentName(string studentname);
        void setHorario(Horario horario);
        void setNUCS(int NUCS);
        bool operator<(const Aluno&) const;
        bool operator>(const Aluno&) const;
};

#endif
