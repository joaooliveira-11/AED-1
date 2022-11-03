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
        ///@note The function gets the ClassCode, UcCode, Weekday, StartHour, Duration and Type of each class from the file,
        /// stores them all in variables and creates a new class with them,
        /// which is then added to vector with all the classes that'll be returned.
        ///@see Aula.h
        static vector<Aula> readAulas();

        ///@brief Reads classes_per_uc.csv.
        ///@returns All the classes per UC.
        ///@note The function gets the UcCode and ClassCode of each class/UC from the file,
        /// stores them in variables and creates a new class/UC with them,
        /// which is then added to vector with all the classes per UC that'll be returned.
        ///@see Turma.h
        static list<Turma> readTurmas();

        ///@brief Reads students_classes.csv.
        ///@returns All the students with their classes updated.
        ///@note The function gets the StudentCode, StudentName, UcCode and ClassCode of each student and it's classes from the file,
        /// stores them in variables and updates each student's classes.
        ///@see Aula.h
        ///@see Aluno.h
        static Bst* readAlunos();

        static void writeDown(Bst*);
};

#endif
