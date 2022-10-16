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
    Aula(string UcCode, string WeekDay, float StartHour, float Duration, string Type){
        this->UcCode = UcCode;
        this->WeekDay = WeekDay;
        this->StartHour = StartHour;
        this->Duration = Duration;
        this->Type = Type;
    }
    string get_UcCode();
    string get_WeekDay();
    float get_StartHour();
    float get_Duration();
    string get_Type();
};

#endif
