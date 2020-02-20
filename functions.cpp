#include <iostream>
#include <fstream>
#include "Interface.hpp"

using namespace std;

double findcost(Library*,int *,int);

int selectLibrary(Library **libraries,int *scores,int time, int L) {
    cout << "Called \n";
    double max = -1;
    int best = -1;
    for(int i=0; i<L; i++){
        if(libraries[i]->isSigned())
            continue;

        double cost = findcost(libraries[i],scores,time);
        if(cost > max){
            max = cost;
            best = i;
        }
    }
    return best;
}

double findcost(Library *library,int *scores,int time) {
    return ((double) library->get_Score(scores)/(time-library->get_SignUpTime())) * ((double) library->get_bookCounter()/library->get_ScannableBooks());
}
