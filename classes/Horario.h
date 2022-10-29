#ifndef AED_1_HORARIO_H
#define AED_1_HORARIO_H

#include <string>
#include <vector>
#include "Aula.h"
using namespace std;

class Horario {
private:
    vector<Aula> horarioAluno; // alterar depois;
public:
    Horario();
    Horario(vector<Aula> horarioaluno);
    void addAula(Aula nAula);
    vector<Aula> getAulas();
    void printHorario();
    string UcCodeToName(string uccode);
    string Double_to_hour(double hour);
    void removerAula( string Uccode,string Classcode );
    void setHorario(vector<Aula> aulas );
};

#endif
