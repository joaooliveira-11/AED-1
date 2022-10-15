//
// Created by nikas on 13/10/2022.
//

#include "Student.h"

using namespace std;

class Student{

    void Student::Student(int code, string name, Schedule schedule){
        studentCode = code;
        studentName = name;
        studentSchedule = schedule;
    }

    void Student::setSchedule(Schedule schedule){
        studentSchedule = schedule;
    }
};