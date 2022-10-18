#ifndef AED_1_AULA_H
#define AED_1_AULA_H

#include <string>
#include <vector>
using namespace std;

class Aula {
private:
    string UcCode;
    string ClassCode;
    string WeekDay;
    float StartHour;
    float Duration;
    string Type;
public:
    Aula(string classcode,string ucCode, string weekDay, double startHour, double duration, string type);
    string get_UcCode() const;
    string get_ClassCode() const;
    string get_WeekDay() const;
    double get_StartHour() const;
    double get_Duration() const;
    string get_Type() const;
    void setClassCode(string classCode);
    void setUcCode(string ucCode);
    void setWeekDay(string weekDay);
    void setStartHour(double startHour);
    void setDuration(double duration);
    void setClassType(string classType);
    //bool operator<(const Aula& ) const;
};

#endif
