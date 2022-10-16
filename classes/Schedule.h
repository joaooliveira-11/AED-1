#ifndef AED_1_SCHEDULE_H
#define AED_1_SCHEDULE_H

#include <string>
#include <vector>
#include "Class.h"
using namespace std;

class Schedule {
private:
    vector<Class> scheduledClasses; // alterar depois;
public:
    void addClass(Class nClass);
    void removeClass(Class nClass);
    vector<Class> getClasses{return scheduledClasses};
};

#endif //AED_1_SCHEDULE_H
