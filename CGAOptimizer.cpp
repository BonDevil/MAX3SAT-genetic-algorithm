//
// Created by Piotr on 10.01.2022.
//

#include "CGAOptimizer.h"
#include <chrono>
#include <algorithm>

CGAOptimizer::CGAOptimizer() {
    d_mutation_probability = 25;
    d_crossover_probability = 25;
    d_population_size = 1000;
    pc_vec_Population = new vector<CGAIndividual *>;
    pc_vec_newPopulation = new vector<CGAIndividual *>;
    pc_CM3SProb = new CMax3SatProblem;
    srand(time(NULL));
}

CGAOptimizer::~CGAOptimizer() {
    for (int i = 0; i < pc_vec_Population->size(); i++)
        delete pc_vec_Population->at(i);

    for (int i = 0; i < pc_vec_newPopulation->size(); i++)
        delete pc_vec_newPopulation->at(i);

    delete pc_vec_Population;
    delete pc_vec_newPopulation;
    delete pc_CM3SProb;

    pc_vec_Population = NULL;
    pc_CM3SProb = NULL;
    pc_vec_newPopulation = NULL;

}


void CGAOptimizer::vInitialize(string s_FileName) {

    pc_CM3SProb->Load(s_FileName);
    for (int i = 0; i < d_population_size; i++) {
        pc_vec_Population->push_back(new CGAIndividual());
        pc_vec_Population->at(i)->vInitialize(pc_CM3SProb->getIMapClauseCount());
        pc_vec_Population->at(i)->dFitness(*pc_CM3SProb);
    }
}

CGAIndividual *CGAOptimizer::CGAI_chooseParent() {
    int i_index1 = rand() % (int) d_population_size;
    int i_index2 = rand() % (int) d_population_size;

    if (i_index1 < i_index2)
        return pc_vec_Population->at(i_index1);
    else
        return pc_vec_Population->at(i_index2);
}

bool Compare(CGAIndividual *pc_Individual1, CGAIndividual *pc_Individual2) {
    return pc_Individual1->getDCurrentSolutionFitness() > pc_Individual2->getDCurrentSolutionFitness();
}

void CGAOptimizer::vRunIteration() {

    CGAIndividual *pc_CGAI_parent1 = NULL;
    CGAIndividual *pc_CGAI_parent2 = NULL;

    sort(pc_vec_Population->begin(), pc_vec_Population->end(), Compare);
    for (int i = 0; i < d_population_size/50; i++)
        pc_vec_newPopulation->push_back(new CGAIndividual(pc_vec_Population->at(i)));

    while (pc_vec_newPopulation->size() < pc_vec_Population->size()) {
        CGAIndividual *pc_CGAI_child1 = new CGAIndividual;
        CGAIndividual *pc_CGAI_child2 = new CGAIndividual;


        pc_CGAI_parent1 = CGAI_chooseParent();
        pc_CGAI_parent2 = CGAI_chooseParent();

        pc_CGAI_child1->Crossover(pc_CGAI_parent1, pc_CGAI_parent2, d_crossover_probability);
        pc_CGAI_child2->Crossover(pc_CGAI_parent2, pc_CGAI_parent1, d_crossover_probability);

        pc_CGAI_child1->Mutation(d_mutation_probability);
        pc_CGAI_child2->Mutation(d_mutation_probability);

        pc_CGAI_child1->dFitness(*pc_CM3SProb);
        pc_CGAI_child2->dFitness(*pc_CM3SProb);

        pc_vec_newPopulation->push_back(pc_CGAI_child1);
        pc_vec_newPopulation->push_back(pc_CGAI_child2);
        pc_CGAI_parent1 = NULL;
        pc_CGAI_parent2 = NULL;
    }
    swap(pc_vec_Population, pc_vec_newPopulation);

    for (int i = 0; i < d_population_size; i++)
        delete pc_vec_newPopulation->at(i);
    pc_vec_newPopulation->clear();
    pc_vec_newPopulation = new vector<CGAIndividual *>;
}

void CGAOptimizer::setDMutationProbability(double dMutationProbability) {
    if(dMutationProbability > 100 || dMutationProbability < 0)
        cout<<"Wrong input, mutation probability set to default = "<<d_mutation_probability<<endl;
    else
        d_mutation_probability = dMutationProbability;
}

void CGAOptimizer::setDCrossoverProbability(double dCrossoverProbability) {
    if(dCrossoverProbability> 100 || dCrossoverProbability < 0)
        cout<<"Wrong input, crossover probability set to default = "<<d_crossover_probability<<endl;
    else
        d_crossover_probability = dCrossoverProbability;
}

void CGAOptimizer::setDPopulationSize(double dPopulationSize) {
    if(dPopulationSize < 2)
        cout<<"Wrong input, population size set to default = "<<d_population_size<<endl;
    else
        d_population_size = dPopulationSize;
}

double CGAOptimizer::dGetBestResult() {
    return pc_vec_Population->at(0)->getDCurrentSolutionFitness() / pc_CM3SProb->getINumberOfClauses() * 100;
}

vector<bool> CGAOptimizer::bVecGetBestResult() {
    return pc_vec_Population->at(0)->bVecGetResult(*pc_CM3SProb);
}






