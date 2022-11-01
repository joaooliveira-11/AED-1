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

        ///@brief Getter for the UcCode.
        ///@returns An UC's code.
        string get_UcCode() const;

        ///@brief Getter for the ClassCode.
        ///@returns A class' code.
        string get_ClassCode() const;

        ///@brief Getter for the class' WeekDay.
        ///@returns The weekday in which a class occurs.
        string get_WeekDay() const;

        ///@brief Getter for the class StartHour.
        ///@returns A class's starting hour.
        double get_StartHour() const;

        ///@brief Getter for the class' Duration.
        ///@returns A class's duration.
        double get_Duration() const;

        ///@brief Getter for the class' Type.
        ///@returns A class's type (PL, T or TP).
        string get_Type() const;

        ///@brief Setter for the ClassCode.
        ///@param classCode
        void setClassCode(string classCode);

        ///@brief Setter for the class' UcCode.
        ///@param ucCode
        void setUcCode(string ucCode);

        ///@brief Setter for the class' Weekday.
        ///@param weekDay
        void setWeekDay(string weekDay);

        ///@brief Setter for the class' StartHour.
        ///@param startHour
        void setStartHour(double startHour);

        ///@brief Setter for the class' Duration.
        ///@param duration
        void setDuration(double duration);

        ///@brief Setter for the class' Type.
        ///@param classType
        void setClassType(string classType);

        ///@brief Operator< overload.
        ///@returns True if our class happens first in the week when compared to the one received as a parameter.
        ///@note This function compares both classes' weekday.
        /// If this->get_WeekDay() is earlier in the week than other.get_WeekDay() it immediately returns true.
        /// Similarly, if it's later it'll return false.
        /// If both classes are on the same day, the starting times will be compared and the function returns true if this->get_WeekDay() starts earlier than other.get_WeekDay().
        ///@note Time complexity: O(1)
        bool operator<(const Aula&) const;
};

#endif
