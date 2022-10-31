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
        Horario(vector<Aula> horarioaluno);

        ///@returns A student's schedule.
        vector<Aula> getAulas();

        ///@returns Our schedule as the parameter it receives.
         void setHorario(vector<Aula> aulas);

        ///@brief Add new class to schedule.
        void addAula(const Aula& nAula);

        ///@brief Prints a student's schedule.
        ///@see Aula.h
        void printHorario();

        ///@returns A classe's name given it's UC code.
        static string UcCodeToName(const string& uccode);

        ///@returns A classe's starting time.
        ///@param hour The classe's starting hour as a double that needs to be converted to time.
        static string Double_to_hour(double hour);

        ///@brief Removes a class from a student's schedule if someone wants to stop having a certain UC.
        void removerAula(const string& Uccode, const string& Classcode);
};

#endif
