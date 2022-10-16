#ifndef AED_1_ALUNO_H
#define AED_1_ALUNO_H

#include <string>
#include <vector>
#include "Horario.h"
using namespace std;

class Aluno {
private:
    int codigoAluno;
    string nomeAluno;
    Horario horarioAluno;
public:
    void Aluno(int code, string name, Schedule schedule);
    int getCodigo(){return codigoAluno;}
    string getNome(){return nomeAluno;}
    Horario getHorario(){return horarioAluno;};
    void setHorario(Horario horario);
};

#endif //AED_1_ALUNO_H
