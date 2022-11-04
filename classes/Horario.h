///@file Horario.h

#ifndef AED_1_HORARIO_H
#define AED_1_HORARIO_H

#include <string>
#include <vector>
#include "Aula.h"
using namespace std;

///@brief Class for schedules.
class Horario {
    private:
        ///@brief The schedule, made of classes.
        vector<Aula> horarioAluno;
    public:
        ///@brief Empty schedule constructor.
        Horario();

        ///@brief Constructor of a new schedule given a student's classes.
        ///@param horarioaluno
        Horario(vector<Aula> horarioaluno);

        ///@brief Getter for the Student Schedule
        ///@returns A student's schedule.
        vector<Aula> getAulas();

        ///@brief Setter for the student's schedule
        ///@param aulas
         void setHorario(vector<Aula> aulas);

        ///@brief Adds a new class to schedule.
        ///@param nAula
        ///@note Time complexity: O(1)
        void addAula(const Aula& nAula);

        ///@brief Prints a student's schedule.
        ///@see Aula.h
        ///@note Time complexity: O(n)
        void printHorario();

        ///@brief Use of map to change a class' UcCode to its corresponding name.
        ///@param uccode
        ///@returns A class' name given it's UC code.
        ///@note Time complexity: O(1)
        static string UcCodeToName(const string& uccode);

        ///@brief Converts hour from float to time.
        ///@param hour The class' starting hour as a double that needs to be converted to time.
        ///@returns A class' starting time.
        ///@note Time complexity: O(1)
        static string Double_to_hour(double hour);

        ///@brief Removes a class from a student's schedule if someone wants to stop having a certain UC.
        ///@param Classcode
        ///@param Uccode
        ///@note Time complexity: O(n)
        void removerAula(const string& Uccode, const string& Classcode);
};

#endif
