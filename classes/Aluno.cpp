#include "Aluno.h"
using namespace std;

class Aluno{

    void Aluno::Aluno(int codigo, string nome, Horario horario){
        codigoAluno = codigo;
        nomeAluno = nome;
        horarioAluno = horario;
    }

    void Aluno::setSchedule(Horario horario){
        horarioAluno = horario;
    }
};
