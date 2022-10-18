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

bool Aula::operator<(const Aula &other) const {
    if ((this->get_WeekDay() == "Monday") and ( other.get_WeekDay() != "Monday")){
        return true;
    }
    if ((this->get_WeekDay() != "Monday") and ( other.get_WeekDay() == "Monday")){
        return true;
    }
    if ((this->get_WeekDay() == "Monday") and ( other.get_WeekDay() == "Monday")){
        return ( this->get_StartHour() < other.get_StartHour() );
    }
    if ((this->get_WeekDay() == "Tuesday") and ( other.get_WeekDay() != "Tuesday")){
        return true;
    }
    if ((this->get_WeekDay() != "Tuesday") and ( other.get_WeekDay() == "Tuesday")){
        return true;
    }
    if ((this->get_WeekDay() == "Tuesday") and ( other.get_WeekDay() == "Tuesday")){
        return ( this->get_StartHour() < other.get_StartHour() );
    }
    if ((this->get_WeekDay() == "Wednesday") and ( other.get_WeekDay() != "Wednesday")){
        return true;
    }
    if ((this->get_WeekDay() != "Wednesday") and ( other.get_WeekDay() == "Wednesday")){
        return true;
    }
    if ((this->get_WeekDay() == "Wednesday") and ( other.get_WeekDay() == "Wednesday")){
        return ( this->get_StartHour() < other.get_StartHour() );
    }
    if ((this->get_WeekDay() == "Thursday") and ( other.get_WeekDay() != "Thursday")){
        return true;
    }
    if ((this->get_WeekDay() != "Thursday") and ( other.get_WeekDay() == "Thursday")){
        return true;
    }
    if ((this->get_WeekDay() == "Thursday") and ( other.get_WeekDay() == "Thursday")){
        return ( this->get_StartHour() < other.get_StartHour() );
    }
    if ((this->get_WeekDay() == "Thursday") and ( other.get_WeekDay() == "Thursday")){
        return ( this->get_StartHour() < other.get_StartHour() );
    }
    if ((this->get_WeekDay() == "Friday") and ( other.get_WeekDay() != "Friday")){
        return true;
    }
    if ((this->get_WeekDay() != "Friday") and ( other.get_WeekDay() == "Friday")){
        return true;
    }
    if ((this->get_WeekDay() == "Friday") and ( other.get_WeekDay() == "Friday")) {
        return (this->get_StartHour() < other.get_StartHour());
    }
}