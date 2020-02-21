#include <iostream>
#include <fstream>
#include "Interface.hpp"

using namespace std;

double findcost(Library*,int *,int,bool *);

int selectLibrary(Library **libraries,int *scores,int time, int L,bool *CheckedBooks) {
    double max = -1;
    int best = -1;
    for(int i=0; i<L; i++){
        if(libraries[i]->isSigned())
            continue;
        if(best == -1) {
            best = i;
            max = findcost(libraries[i],scores,time,CheckedBooks);
            continue;
        }
        double cost = findcost(libraries[i],scores,time,CheckedBooks);
        if(cost > max){
            max = cost;
            best = i;
        }
    }
    return best;
}

double findcost(Library *library,int *scores,int time,bool *CheckedBooks) {
    return ((double) library->get_Score(scores,CheckedBooks)/(time-library->get_SignUpTime())) * ((double) library->get_bookCounter()/library->get_ScannableBooks());
}
