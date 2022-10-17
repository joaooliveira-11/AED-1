#ifndef AED_1_AULA_H
#define AED_1_AULA_H

#include <string>
#include <vector>
using namespace std;

class Aula {
private:
    string UcCode;
    string WeekDay;
    float StartHour;
    float Duration;
    string Type;
public:
    Aula(string ucCode, string weekDay, float startHour, float duration, string type): UcCode(ucCode), WeekDay(weekDay), StartHour(startHour), Duration(duration), Type(type){}
    string get_UcCode();
    string get_WeekDay();
    float get_StartHour();
    float get_Duration();
    string get_Type();
};

#endif
