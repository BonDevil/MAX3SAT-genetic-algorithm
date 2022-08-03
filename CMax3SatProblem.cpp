//
// Created by Piotr on 10.01.2022.
//

#include "CMax3SatProblem.h"


CMax3SatProblem::CMax3SatProblem(){
    i_map_clause_count = 0;
}

CMax3SatProblem::~CMax3SatProblem() {
    vec_clauses.clear();
}

bool CMax3SatProblem::Load(string sFileName) {
    ifstream file_stream_in(sFileName);
    double d_clause_var1,d_clause_var2,d_clause_var3;
    char ch_skip;

    if (!file_stream_in){
        cout << "No such file exists";
        return false;
    }
    else {
        while (true){

            file_stream_in >> ch_skip;
            file_stream_in >> d_clause_var1;
            file_stream_in >> d_clause_var2;
            file_stream_in >> d_clause_var3;
            file_stream_in >> ch_skip;
            if (file_stream_in.eof())
                break;

            vec_clauses.emplace_back(d_clause_var1, d_clause_var2, d_clause_var3,
                                          i_find_clauseVar_index(d_clause_var1), i_find_clauseVar_index(d_clause_var2),
                                          i_find_clauseVar_index(d_clause_var3));

        }
    }
    return true;
}

int CMax3SatProblem::Compute(vector<bool>& vec_solution) {

    int result = 0;
    for(int i = 0; i < vec_clauses.size(); i++)
        result += vec_clauses.at(i).check(vec_solution);

    return result;
}


int CMax3SatProblem::i_find_clauseVar_index(double clauseVar){
    auto it = map_clauseVar_indexes.find(clauseVar);
    if(it != map_clauseVar_indexes.end())
        return map_clauseVar_indexes.find(clauseVar)->second;
    else{
        map_clauseVar_indexes.insert(pair(clauseVar,i_map_clause_count));
        i_map_clause_count+=1;
        return i_map_clause_count-1;
    }
}


int CMax3SatProblem::getIMapClauseCount() const{
    return i_map_clause_count;
}

int CMax3SatProblem::getINumberOfClauses() {
    return vec_clauses.size();
}

vector<Clause> &CMax3SatProblem::getVecClauses() {
    return vec_clauses;
}




