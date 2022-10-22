//
// Created by andre on 21/10/2022.
//

#ifndef AED_1_BST_H
#define AED_1_BST_H
#include "Aluno.h"
#include <iostream>

using namespace std;

class Bst {
        Aluno atual;
        Bst* Left;
        Bst* Right;
public:
        Bst();
        Bst(Aluno imp);
        Bst* insert_by_upcode(Bst* base, Aluno atual);
        void view(Bst* base);
        Aluno find_by_upcode(Bst* base,int upcode );
};
#endif
