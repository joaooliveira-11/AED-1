#ifndef AED_1_READINGCLASSES_H
#define AED_1_READINGCLASSES_H

#include "Aula.h"
#include "Aluno.h"
#include <string>
#include <list>
#include "Bst.h"
using namespace std;

class ReadingClasses {
public:
    Bst* readAlunos();
    vector<Aula> readAulas();
};

#endif
