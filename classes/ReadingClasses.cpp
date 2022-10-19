#include "ReadingClasses.h"
#include "Aula.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

void Reading() {}
    vector<Aula*> ReadingClasses::readAulas() {
    vector<Aula*> aulas;
    string CLASSCODE, UCCODE, WEEKDAY, TYPE;
    double STARTHOUR, DURATION;
    char c;

    ifstream in("../classes.csv");
    in >> CLASSCODE >> c;
    for (string line; getline(in, line);) {
        istringstream iss(line);
        getline(iss, CLASSCODE, ',');
        getline(iss, UCCODE, ',');
        getline(iss, WEEKDAY, ',');
        iss >> STARTHOUR >> c;
        iss >> DURATION >> c;
        getline(iss, TYPE, ',');
        Aula* raula = new Aula(CLASSCODE, UCCODE, WEEKDAY, (STARTHOUR), (DURATION), TYPE);
        aulas.push_back(raula);
    }

    return aulas;
}

/*vector<Aula*> ReadingClasses::readAulas() {

    vector<Aula*> aulas;
    string CLASSCODE;string UCCODE;string WEEKDAY;double STARTHOUR;double DURATION;string TYPE;

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
            //std::cout << str;
            //cout << "\n";
            str >> CLASSCODE >> UCCODE >> WEEKDAY >> STARTHOUR >> DURATION >> TYPE;
            Aula* raula = new Aula(CLASSCODE, UCCODE, WEEKDAY, (STARTHOUR), (DURATION), TYPE);
            aulas.push_back(raula);

        }
        //std::cout << std::endl;
    }
    return aulas;
}

*/