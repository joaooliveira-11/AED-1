///@file Aula.h

#ifndef AED_1_AULA_H
#define AED_1_AULA_H

#include <string>
#include <vector>
using namespace std;

///@brief Class for classes.
class Aula {
    private:
        ///@brief The UC's code, the class code, the type of class and it's weekday.
        string UcCode, ClassCode, Type, WeekDay;

        ///@brief The class's starting hour and duration.
        double StartHour, Duration;
    public:
        ///@brief Constructor of new class given it's class code, the UC's code, weekday, starting hour, duration and type.
        Aula(string classCode, string ucCode, string weekDay, double startHour, double duration, string type);

        ///@returns A UC's code.
        string get_UcCode() const;

        ///@returns A class's code.
        string get_ClassCode() const;

        ///@returns The weekday in which a class occurs.
        string get_WeekDay() const;

        ///@returns A class's starting hour.
        double get_StartHour() const;

        ///@returns A class's duration.
        double get_Duration() const;

        ///@returns A class's type (PL, T or TP).
        string get_Type() const;

        ///@returns Our class's code as the parameter it receives.
        void setClassCode(string classCode);

        ///@returns Our UC's code as the parameter it receives.
        void setUcCode(string ucCode);

        ///@returns Our class's weekday as the parameter it receives.
        void setWeekDay(string weekDay);

        ///@returns Our class's starting hour as the parameter it receives.
        void setStartHour(double startHour);

        ///@returns Our class's duration as the parameter it receives.
        void setDuration(double duration);

        ///@returns Our class's type as the parameter it receives.
        void setClassType(string classType);

        ///@brief Operator< overload.
        ///@returns True if our class happens first in the week when compared to the one received as a parameter.
        bool operator<(const Aula&) const;
};

#endif
