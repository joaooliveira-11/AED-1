//
// Created by nikas on 13/10/2022.
//

#ifndef AED_1_LECTURE_H
#define AED_1_LECTURE_H

#include <string>
#include <vector>
using namespace std;

class Lecture {
private:
    string UcCode;
    string WeekDay;
    float StartHour;
    float Duration;
    string Type;
public:
    Lecture(string UcCode, string WeekDay, float StartHour, float Duration, string Type){
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

#endif //AED_1_LECTURE_H
