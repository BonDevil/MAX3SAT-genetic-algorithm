//
// Created by Piotr on 11.01.2022.
//

#ifndef MAX3SAT_CLAUSE_H
#define MAX3SAT_CLAUSE_H

using namespace std;
#include <ostream>
#include <iostream>
#include <vector>

class Clause {
private:
    double var_array[3];
    int index_array[3];
public:
    Clause(double var1, double var2, double var3, int index1, int index2, int index3);
    int check(vector<bool>& vec_solution);

    int iGetIndex(int offset);

};


#endif //MAX3SAT_CLAUSE_H
