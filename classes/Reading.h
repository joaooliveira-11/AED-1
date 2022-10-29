///@file Reading.h

#ifndef AED_1_READING_H
#define AED_1_READING_H

#include "Aula.h"
#include "Aluno.h"
#include <string>
#include <list>
#include "Bst.h"
#include "Turma.h"
using namespace std;

///@brief A class to read and manage the csv files.
class Reading {
    public:
        ///@brief Reads classes.csv.
        ///@returns All the classes.
        ///@see Aula.h
        static vector<Aula> readAulas();

        ///@brief Reads classes_per_uc.
        ///@returns All the classes per UC.
        ///@see Turma.h
        static list<Turma> readTurmas();

        ///@brief Reads students_classes.csv.
        ///@returns All the students.
        ///@see Aula.h
        ///@see Aluno.h
        static Bst* readAlunos();
};

#endif
