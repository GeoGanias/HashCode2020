#include <iostream>
#include <fstream>
#include "Interface.hpp"

using namespace std;

double findcost(Library*,int *,int,bool *);
// int minSignUp(Library **,int ,int );

int selectLibrary(Library **libraries,int *scores,int time, int L,bool *CheckedBooks) {
    double max = -1;
    int best = -1;
    for(int i=0; i<L; i++){
        if(libraries[i]->isSigned())
            continue;
        if(best == -1) {
            best = i;
            max = ((double)libraries[i]->findBestScore(CheckedBooks,scores,time))/((double) libraries[i]->get_SignUpTime());
            //max = findcost(libraries[i],scores,time,CheckedBooks);
            continue;
        }
        double cost = ((double)libraries[i]->findBestScore(CheckedBooks,scores,time))/((double) libraries[i]->get_SignUpTime());

        //double cost = findcost(libraries[i],scores,time,CheckedBooks);
        if(cost > max){
            max = cost;
            best = i;
        }
    }

    return best;
}


double findcost(Library *library,int *scores,int time,bool *CheckedBooks) {
    return ((double) library->get_Score(scores,CheckedBooks)/(library->get_SignUpTime())) * ((double) library->get_bookCounter()/library->get_ScannableBooks());
}

// int minSignUp(Library **libraries,int signUpTime,int L) {
//     int i;
//     int min = -1;
//     int index = -1;
//     for(i=0;i<L;i++) {
//         if(libraries[i]->isSigned())
//             continue;
//         if(libraries[i]->get_SignUpTime() < signUpTime && min == -1) {
//             // cout << "signed up " << signUpTime << endl;
//             min = libraries[i]->get_SignUpTime();
//             index = i;
//             continue;
//         }
//         if(libraries[i]->get_SignUpTime() < min) {
//             min = libraries[i]->get_SignUpTime();
//             index = i;
//         }
//     }
//     return index;
// }
