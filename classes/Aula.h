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
    Aula(string classcode,string ucCode, string weekDay, float startHour, float duration, string type);
    string get_UcCode();
    string get_ClassCode();
    string get_WeekDay();
    float get_StartHour();
    float get_Duration();
    string get_Type();
};

#endif
