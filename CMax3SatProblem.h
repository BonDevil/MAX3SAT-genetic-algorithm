//
// Created by Piotr on 10.01.2022.
//

#ifndef MAX3SAT_CMAX3SATPROBLEM_H
#define MAX3SAT_CMAX3SATPROBLEM_H

#include "Clause.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class CMax3SatProblem {
private:

    vector<Clause> vec_clauses;
    map<double, int> map_clauseVar_indexes;
    int i_map_clause_count;

    int i_find_clauseVar_index(double clauseVar);

public:
    CMax3SatProblem();

    ~CMax3SatProblem();

    bool Load(string sFileName);

    int Compute(vector<bool> &vec_solution);

    int getIMapClauseCount() const;

    int getINumberOfClauses();

    vector<Clause> &getVecClauses();
};


#endif //MAX3SAT_CMAX3SATPROBLEM_H
