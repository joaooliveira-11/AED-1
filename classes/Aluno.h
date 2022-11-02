///@file Aluno.h

#ifndef AED_1_ALUNO_H
#define AED_1_ALUNO_H

#include <string>
#include <vector>
#include <set>
#include "Horario.h"
using namespace std;

///@brief Class for students.
class Aluno {
    private:
        ///@brief The student's code and the number of UCs he has.
        int StudentCode, NUCS;

        ///@brief The student's name.
        string StudentName;

        ///@brief The student's schedule.
        Horario horarioAluno;
    public:
        ///@brief Empty student constructor.
        Aluno();

        ///@brief Constructor of new student given it's student code, name, schedule and number of UCs.
        ///@param StudentName
        ///@param StudentCode
        ///@param horario
        ///@param NUCS
        Aluno(int StudentCode, string StudentName, Horario horario, int NUCS);

        ///@brief Getter for the student's code.
        ///@returns A student's code.
        int getStudentCode() const;

        ///@brief Getter for the student's name.
        ///@returns A student's name.
        string getStudentName() const;

        ///@brief Getter for the student's schedule.
        ///@returns A student's schedule.
        Horario& getHorario();

        ///@brief Getter for the number of UCs a student's enrolled in.
        ///@returns The number of UCs a student's enrolled in.
        int getNUCS() const;

        ///@brief Setter for the student's code.
        ///@param studentcode
        void setStudentCode(int studentcode);

        ///@brief Setter for the student's name.
        ///@param studentname
        void setStudentName(string studentname);

        ///@brief Setter for the student's schedule.
        ///@param horario
        void setHorario(Horario& horario);

        ///@brief Setter for the number of Ucs of the Student(Set Our student's number of UCs as the parameter it receives.)
        ///@param NUCS
        void setNUCS(int NUCS);

        ///@brief Operator< overload.
        ///@returns True if our student's code is lower than the one from the student received as parameter.
        ///@param Aluno
        ///@note Time complexity: O(1)
        bool operator<(const Aluno&) const;

        ///@brief Operator> overload.
        ///@returns True if our student's code is higher than the one from the student received as parameter.
        ///@param Aluno
        ///@note Time complexity: O(1)
        bool operator>(const Aluno&) const;

        ///@brief Decreases the number of UCs a student is enrolled in if that student leaves an UC.
        ///@note Time complexity: O(1)
        void removeUcs();

        ///@brief Increases the number of UCs a student is enrolled in if that student enrolls in an UC.
        ///@note Time complexity: O(1)
        void addUcs();

        bool verificar(Aula aula, Horario horario);
};

#endif
