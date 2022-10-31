///@file Turma.h

#ifndef AED_1_TURMA_H
#define AED_1_TURMA_H


#include <string>
#include <vector>
#include <set>
#include "Aula.h"
#include "map"
using namespace std;

///@brief Class for classes.
class Turma {
    private:
        ///@brief The class code and the UC code.
        string Classcode, Uccode;

        ///@brief The number of students in a class.
        int numeroAlunos;
    public:
        ///@brief Constructor of a new class given it's class code, the UC code and the number of students in the class/UC.
        Turma(string Classcode,string Uccode,int numeroAlunos);

        ///@returns Our class's code.
        string get_classcode();

        ///@returns Our UC's code.
        string get_uccode();

        ///@returns The amount of students in our class/UC.
        int get_numeroalunos() const;

        ///@brief Increments the number of students in this class/UC.
        void adder();

       bool can_add( map<string, int> Max_students_by_UC);
};

#endif
