#include "Aula.h"

Aula::Aula(string classCode, string ucCode, string weekDay, double startHour, double duration, string type): ClassCode(classCode), UcCode(ucCode), WeekDay(weekDay), StartHour(startHour), Duration(duration), Type(type){}

string Aula::get_UcCode() const {return UcCode;}
string Aula::get_WeekDay() const {return WeekDay;}
double Aula::get_StartHour() const {return StartHour;}
double Aula::get_Duration() const {return Duration;}
string Aula::get_Type() const {return Type;}
string Aula::get_ClassCode() const {return ClassCode;}

void Aula::setUcCode(std::string ucCode) {this->UcCode = ucCode;}
void Aula::setClassCode(std::string classCode) {this->ClassCode = classCode;}
void Aula::setClassType(std::string classType) {this->Type = classType;}
void Aula::setDuration(double duration) {this->Duration = duration;}
void Aula::setStartHour(double startHour) {this->StartHour = startHour;}
void Aula::setWeekDay(std::string weekDay) {this->WeekDay = weekDay;}

bool Aula::operator<(const Aula &other) const {
    if ((this->get_WeekDay() == "Monday") and (other.get_WeekDay() != "Monday")) return true;
    if ((this->get_WeekDay() != "Monday") and (other.get_WeekDay() == "Monday")) return false;
    if ((this->get_WeekDay() == "Monday") and (other.get_WeekDay() == "Monday")){
        if (this->get_StartHour() == other.get_StartHour()){
            return (this->get_ClassCode()<other.get_ClassCode());
        }
        return (this->get_StartHour() < other.get_StartHour());
    }
    if ((this->get_WeekDay() == "Tuesday") and (other.get_WeekDay() != "Tuesday")) return true;
    if ((this->get_WeekDay() != "Tuesday") and (other.get_WeekDay() == "Tuesday")) return false;
    if ((this->get_WeekDay() == "Tuesday") and (other.get_WeekDay() == "Tuesday")){
        if (this->get_StartHour() == other.get_StartHour()){
            return (this->get_ClassCode()<other.get_ClassCode());
        }
        return (this->get_StartHour() < other.get_StartHour());
    }
    if ((this->get_WeekDay() == "Wednesday") and (other.get_WeekDay() != "Wednesday")) return true;
    if ((this->get_WeekDay() != "Wednesday") and (other.get_WeekDay() == "Wednesday")) return false;
    if ((this->get_WeekDay() == "Wednesday") and (other.get_WeekDay() == "Wednesday")){
        if (this->get_StartHour() == other.get_StartHour()){
            return (this->get_ClassCode()<other.get_ClassCode());
        }
        return (this->get_StartHour() < other.get_StartHour());
    }
    if ((this->get_WeekDay() == "Thursday") and (other.get_WeekDay() != "Thursday")) return true;
    if ((this->get_WeekDay() != "Thursday") and (other.get_WeekDay() == "Thursday")) return false;
    if ((this->get_WeekDay() == "Thursday") and (other.get_WeekDay() == "Thursday")){
        if (this->get_StartHour() == other.get_StartHour()){
            return (this->get_ClassCode()<other.get_ClassCode());
        }
        return (this->get_StartHour() < other.get_StartHour());
    }
    if ((this->get_WeekDay() == "Friday") and (other.get_WeekDay() != "Friday")) return true;
    if ((this->get_WeekDay() != "Friday") and (other.get_WeekDay() == "Friday")) return false;
    if ((this->get_WeekDay() == "Friday") and (other.get_WeekDay() == "Friday")){
            if (this->get_StartHour() == other.get_StartHour()){
                return (this->get_ClassCode()<other.get_ClassCode());
            }
            return (this->get_StartHour() < other.get_StartHour());
    }
    return true;
}
