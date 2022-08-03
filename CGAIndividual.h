//
// Created by Piotr on 10.01.2022.
//

#ifndef MAX3SAT_CGAINDIVIDUAL_H
#define MAX3SAT_CGAINDIVIDUAL_H

#include "CMax3SatProblem.h"
#include <vector>
using namespace std;


class CGAIndividual {
public:
    CGAIndividual();

    CGAIndividual(CGAIndividual *cOther);

    ~CGAIndividual();

    void Crossover(CGAIndividual *pc_parent1, CGAIndividual *pc_parent2, double d_crossover_probability);

    void Mutation(double d_mutation_probability);

    void vInitialize(double d_numberOfVariables);

    double dFitness(CMax3SatProblem &pc_CM3SProb);

    double getDCurrentSolutionFitness() const;

    vector<bool> bVecGetResult(CMax3SatProblem &pc_CM3SProb);


private:
    vector<bool> *b_vec_genotype;
    double d_CurrentSolutionFitness;
};


#endif //MAX3SAT_CGAINDIVIDUAL_H
