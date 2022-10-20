#ifndef AED_1_READINGCLASSES_H
#define AED_1_READINGCLASSES_H

#include "Aula.h"
#include "Aluno.h"
#include <string>
using namespace std;

class ReadingClasses {
public:
    vector<Aluno> readAlunos();
    vector<Aula> readAulas();
};

#endif
