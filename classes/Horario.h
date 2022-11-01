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

        ///@brief Setter for the Student Schedule.(Set Our schedule as the parameter it receives.)
        ///@param aulas
         void setHorario(vector<Aula> aulas);

        ///@brief Add new class to schedule.
        ///@param nAula
        void addAula(const Aula& nAula);

        ///@brief Prints a student's schedule.
        ///@see Aula.h
        void printHorario();

        ///@brief Use of map to change a Class UcCode to its corresponding name
        ///@param uccode
        ///@returns A classe's name given it's UC code.
        static string UcCodeToName(const string& uccode);

        ///@brief Convert hour as a float number to time number
        ///@param hour The classe's starting hour as a double that needs to be converted to time.
        ///@returns A classe's starting time.
        static string Double_to_hour(double hour);

        ///@brief Removes a class from a student's schedule if someone wants to stop having a certain UC.
        ///@param Classcode
        ///@param Uccode
        void removerAula(const string& Uccode, const string& Classcode);
        
};

#endif
