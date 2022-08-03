//
// Created by Piotr on 10.01.2022.
//

#ifndef MAX3SAT_CGAOPTIMIZER_H
#define MAX3SAT_CGAOPTIMIZER_H

#include "CGAIndividual.h"

class CGAOptimizer {
public:

    CGAOptimizer();

    ~CGAOptimizer();

    void vInitialize(string s_FileName);

    void vRunIteration();

    void setDMutationProbability(double dMutationProbability);

    void setDCrossoverProbability(double dCrossoverProbability);

    void setDPopulationSize(double dPopulationSize);

    double dGetBestResult();

    vector<bool> bVecGetBestResult();


private:
    vector<CGAIndividual *> *pc_vec_Population;
    vector<CGAIndividual *> *pc_vec_newPopulation;
    CMax3SatProblem *pc_CM3SProb;
    double d_mutation_probability;
    double d_crossover_probability;
    double d_population_size;

    CGAIndividual *CGAI_chooseParent();
};


#endif //MAX3SAT_CGAOPTIMIZER_H
