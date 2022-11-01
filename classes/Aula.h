///@file Aula.h

#ifndef AED_1_AULA_H
#define AED_1_AULA_H

#include <string>
#include <vector>
using namespace std;

///@brief Class for classes/UC.
class Aula {
    private:
        ///@brief The UC's code, the class code, the type of class and it's weekday.
        string UcCode, ClassCode, Type, WeekDay;

        ///@brief The class's starting hour and duration.
        double StartHour, Duration;
    public:
        ///@brief Constructor of new class given it's class code, the UC's code, weekday, starting hour, duration and type.
        ///@param classCode
        ///@param ucCode
        ///@param weekDay
        ///@param startHour
        ///@param duration
        ///@param type
        Aula(string classCode, string ucCode, string weekDay, double startHour, double duration, string type);

        ///@brief Getter for the UcCode
        ///@returns A UC's code.
        string get_UcCode() const;

        ///@brief Getter for the ClassCode
        ///@returns A class's code.
        string get_ClassCode() const;

        ///@brief Getter for the Class WeekDay
        ///@returns The weekday in which a class occurs.
        string get_WeekDay() const;

        ///@brief Getter for the Class StartHour
        ///@returns A class's starting hour.
        double get_StartHour() const;

        ///@brief Getter for the Class Duration
        ///@returns A class's duration.
        double get_Duration() const;

        ///@brief Getter fpr the Class Type
        ///@returns A class's type (PL, T or TP).
        string get_Type() const;

        ///@brief Setter for the Class Code.(Set Our class's code as the parameter it receives.)
        ///@param classCode
        void setClassCode(string classCode);

        ///@brief Setter for the Class UcCode.(Set Our UC's code as the parameter it receives.)
        ///@param ucCode
        void setUcCode(string ucCode);

        ///@brief Setter for the Class Weekday.(Set Our class's weekday as the parameter it receives.)
        ///@param weekDay
        void setWeekDay(string weekDay);

        ///@brief Setter for the Class StartHour.(Set Our class's starting hour as the parameter it receives.)
        ///@param startHour
        void setStartHour(double startHour);

        ///@brief Setter for the Class Duration.(Set Our class's duration as the parameter it receives.)
        ///@param duration
        void setDuration(double duration);

        ///@brief Setter for the Class Type.(Set Our class's type as the parameter it receives.)
        ///@param classType
        void setClassType(string classType);

        ///@brief Operator< overload.
        ///@returns True if our class happens first in the week when compared to the one received as a parameter.
        ///@note This function compares both classes' weekday.
        /// If this->get_WeekDay() is earlier in the week than other.get_WeekDay() it immediately returns true.
        /// Similarly, if it's later it'll return false.
        /// If both classes are on the same day, the starting times will be compared and the function returns true if this->get_WeekDay() starts earlier than other.get_WeekDay().
        bool operator<(const Aula&) const;
};

#endif
