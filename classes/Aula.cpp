#include "Aula.h"

Aula::Aula(string classcode,string ucCode, string weekDay, float startHour, float duration, string type): ClassCode(classcode),UcCode(ucCode), WeekDay(weekDay), StartHour(startHour), Duration(duration), Type(type){}

string Aula::get_UcCode(){
    return UcCode;
}
string Aula::get_WeekDay(){
    return WeekDay;
}
float Aula::get_StartHour(){
    return StartHour;
}
float Aula::get_Duration(){
    return Duration;
}
string Aula::get_Type(){
    return Type;
}
string Aula::get_ClassCode(){
    return ClassCode;
}