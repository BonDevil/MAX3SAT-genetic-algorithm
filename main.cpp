#include <chrono>
#include "CGAOptimizer.h"
#include <string>

int main() {


    ios_base::sync_with_stdio(0);

    string s_suf, s_filename;
    for(int i = 0; i < 350; i++){
        auto start = chrono::high_resolution_clock::now();

        if(i%50 == 0)
            s_suf = to_string(i + 50) + "_";
        s_filename = "m3s_" + s_suf + to_string(i % 51) + ".txt";

        CGAOptimizer my_CGAOptimizer;
        my_CGAOptimizer.setDCrossoverProbability(30);
        my_CGAOptimizer.setDMutationProbability(10);
        my_CGAOptimizer.setDPopulationSize(1000);
        my_CGAOptimizer.vInitialize(s_filename);
        if(i < 300)
            continue;
        for(int j = 0; j < 40; j++)
            my_CGAOptimizer.vRunIteration();


        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
        cout <<"Nazwa pliku: "<< s_filename << "\tProcent spelnionych klauzul: " << my_CGAOptimizer.dGetBestResult() << "\tCzas wykonania (ms): " << duration.count() << endl;
    }

}
