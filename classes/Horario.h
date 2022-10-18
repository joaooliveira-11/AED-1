#ifndef AED_1_HORARIO_H
#define AED_1_HORARIO_H

#include <string>
#include <vector>
#include "Aula.h"
using namespace std;

class Horario {
private:
    vector<Aula> aulasMarcadas; // alterar depois;
public:
    void addAula(Aula nAula);
    void removeAula(Aula nAula);
    vector<Aula> getAulas();
    void printHorario();
};

#endif
