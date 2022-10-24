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
        void view_by_NUCS(Bst* base, int x);
        Aluno find_by_upcode(Bst* base,int upcode );
};
#endif
