#include "Reading.h"
#include "Aula.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

void Reading() {}
/*
string Reading::readAulas() {
    ifstream in("../classes.csv");
    int count = 0;
    for (string line; getline(in, line, ',');) {
        istringstream iss(line);
        if (count != 0) {
            for (string el; iss >> el;) {
                cout << el;
            }
            cout << "\n";
        }
        count++;
    }
}
*/
string Reading::readAulas() {

    vector<Aula> aulas;
    string classCode;string ucCode;string weekDay;float startHour;float duration;string type;

    std::ifstream data("../classes.csv");
    if (!data.is_open())
    {
        std::exit(EXIT_FAILURE);
    }
    std::string line;
    std::getline(data, line); // skip the first line
    while (std::getline(data, line))
    {
        std::istringstream iss(line);
        std::string str;
        while (std::getline(iss, str, ','))
        {
            // process each token
            std::cout << str;
            cout << "\n";

            /*
             iss >> classCode >> ucCode >>weekDay >> startHour >> duration >> type ;
            aulas.push_back(Aula(classCode, ucCode, weekDay, startHour, duration, type));
             */

        }
        std::cout << std::endl;
    }
}

