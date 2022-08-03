//
// Created by Piotr on 10.01.2022.
//

#include "CGAIndividual.h"

CGAIndividual::CGAIndividual() {
    b_vec_genotype = new vector<bool>;
    d_CurrentSolutionFitness = 0;
}

CGAIndividual::~CGAIndividual() {
    delete b_vec_genotype;
    b_vec_genotype = NULL;
}

CGAIndividual::CGAIndividual(CGAIndividual *cOther) {
    b_vec_genotype = new vector<bool>;
    d_CurrentSolutionFitness = cOther->d_CurrentSolutionFitness;
    for (int i = 0; i < cOther->b_vec_genotype->size(); i++)
        this->b_vec_genotype->push_back(cOther->b_vec_genotype->at(i));
}


void CGAIndividual::vInitialize(double d_numberOfVariables) {
    for (int i = 0; i < d_numberOfVariables; i++)
        b_vec_genotype->push_back(rand() % 2);
}

double CGAIndividual::dFitness(CMax3SatProblem &pc_CM3SProb) {
    d_CurrentSolutionFitness = pc_CM3SProb.Compute(*b_vec_genotype);
    return d_CurrentSolutionFitness;
}

void CGAIndividual::Crossover(CGAIndividual *pc_parent1, CGAIndividual *pc_parent2, double d_crossover_probability) {
    if (rand() % 100 > d_crossover_probability)
        for(int i = 0; i < pc_parent1->b_vec_genotype->size(); i++)
            this->b_vec_genotype->push_back(pc_parent1->b_vec_genotype->at(i));
    else {
        for (int i = 0; i < pc_parent1->b_vec_genotype->size(); i++) {
            if (rand() % 2 == 0)
                this->b_vec_genotype->push_back(pc_parent1->b_vec_genotype->at(i));
            else
                this->b_vec_genotype->push_back(pc_parent2->b_vec_genotype->at(i));
        }
    }
}

void CGAIndividual::Mutation(double d_mutation_probability) {
    for (int i = 0; i < b_vec_genotype->size(); i++) {
        if (rand() % 100 < d_mutation_probability)
            b_vec_genotype->at(i) = !b_vec_genotype->at(i);
    }
}

double CGAIndividual::getDCurrentSolutionFitness() const {
    return d_CurrentSolutionFitness;
}

vector<bool> CGAIndividual::bVecGetResult(CMax3SatProblem &pc_CM3SProb) {
    vector<bool> result;

    for(Clause& c:pc_CM3SProb.getVecClauses()){
        result.push_back(b_vec_genotype->at(c.iGetIndex(0)));
        result.push_back(b_vec_genotype->at(c.iGetIndex(1)));
        result.push_back(b_vec_genotype->at(c.iGetIndex(2)));
    }
    return result;

}



