//
// Created by nikas on 13/10/2022.
//

#ifndef AED_1_STUDENT_H
#define AED_1_STUDENT_H

#include <string>
#include <vector>
#include "Schedule.h"

using namespace std;


class Student {
private:
    int studentCode;
    string studentName;
    Schedule studentSchedule;
public:

    void Student(int code, string name, Schedule schedule);
    int getCode(){return studentCode;}
    string getName(){return studentName;}
    Schedule getSchedule(){return studentSchedule;};
    void setSchedule(Schedule schedule);
};


#endif //AED_1_STUDENT_H
