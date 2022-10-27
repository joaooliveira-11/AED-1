#ifndef AED_1_TURMA_H
#define AED_1_TURMA_H

#include <string>
#include <vector>
#include <set>
#include "Aula.h"
using namespace std;

class Turma {
private:
    string Classcode;
    string Uccode;
    int numeroAlunos;
public:
    Turma(string Classcode,string Uccode,int numeroAlunos);
    string get_classcode();
    string get_uccode();
    int get_numeroalunos();
    void adder();
};

#endif
