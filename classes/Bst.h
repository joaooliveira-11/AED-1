///@file Bst.h

#ifndef AED_1_BST_H
#define AED_1_BST_H

#include "Aluno.h"
#include <iostream>
#include "Turma.h"
#include <list>
using namespace std;

///@brief Class for all the bst we need (i.e.: all students, the students enrolled in more than n UC's).
class Bst {
    private:
        ///@brief The current student.
        Aluno atual;

        ///@brief The left branch.
        Bst* Left;

        ///@brief The right branch.
        Bst* Right;
    public:
        ///@brief Empty binary search tree constructor.
        ///@see Aluno.h
        Bst();

        ///@brief Constructor of a new binary search tree given a student.
        ///@see Aluno.h
        explicit Bst(Aluno imp);

        ///@returns Updated BST after adding a new student.
        ///@param base The student's BST we want to add a new student to.
        ///@param atual The student we are going to add to the BST.
        ///@see Aluno.h
        Bst* insert_by_upcode(Bst* base, const Aluno& atual);

        ///@brief Prints all students (sorted by UC code by default).
        ///@see Aluno.h
        void view(Bst* base);

        ///@brief Prints all students that are enrolled in more than n UC's.
        ///@param x The number (n) UC's we want to check.
        ///@see Aluno.h
        void view_by_NUCS(Bst* base, int x);

        ///@returns Student in BST who's UP code is the same as the upcode the function receives.
        ///@see Aluno.h
        Aluno find_by_upcode(Bst* base, int upcode);

        ///@brief Prints all students that are in the same UC/class.
        ///@see Aluno.h
        ///@see Horario.h
        ///@see Aula.h
        void view_by_turma(Bst* base, const string& uccode, const string& classcode);

        ///@brief Prints all students that are in an UC.
        ///@see Aluno.h
        ///@see Horario.h
        ///@see Aula.h
        void view_by_uc(Bst* base, const string& uccode);

        ///@brief Counts the number of students in an UC.
        ///@see Aluno.h
        ///@see Horario.h
        ///@see Aula.h
        ///@see Turma.h
        void num_students_uc(Bst* base, list<Turma> &turmas);

        void removerAula(Bst* base, int upcode, const string& uccode, const string& classcode);
};

#endif
