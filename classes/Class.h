#ifndef AED_1_CLASS_H
#define AED_1_CLASS_H

#include <string>
#include <vector
using namespace std;

class Class {
private:
    int classCode;
public:
    Class(int classCode){
        this->classCode = classCode;
    }
    // falta o resto como o horário etc

    int get_classCode();
};

#endif //AED_1_CLASS_H
