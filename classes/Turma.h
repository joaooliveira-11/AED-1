#ifndef AED_1_TURMA_H
#define AED_1_TURMA_H

#include <string>
#include <vector
using namespace std;

class Turma {
private:
    int codigoTurma;
public:
    Turma(int codigoTurma){
        this-> codigoTurma = codigoTurma;
    }
    // falta o resto como o horário etc

    int get_codigoTurma();
};

#endif
