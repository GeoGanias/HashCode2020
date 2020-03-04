#include <iostream>
#include <fstream>
#include "Interface.hpp"

using namespace std;


// bool findBetter(Library **,int *,int ,int ,int ,bool *,int,int *,ofstream&);
double findcost(Library*,int *,int,bool *);
// int minSignUp(Library **,int ,int );
int sumArr(int *arr,int N) {
    int sum = 0;
    for(int i=0;i<N;i++) {
        sum+=arr[i];
    }
    return sum;
}

int selectLibrary(Library **libraries,int *scores,int time, int L,bool *CheckedBooks,int B) {
    double max = -1;
    int best = -1;
    int bestSum = sumArr(scores,B);
    for(int i=0; i<L; i++){
        if(libraries[i]->isSigned())
            continue;
        if(best == -1) {
            best = i;
            // double perScore = ((double)libraries[i]->findBestScore(CheckedBooks,scores,time) / bestSum)*100.0;
            // double perDays = ((double)libraries[i]->get_SignUpTime()/time);
            // max = perScore / (perDays);
            max = ((double)libraries[i]->findBestScore(CheckedBooks,scores,time))/((double) libraries[i]->get_SignUpTime());
            //max = findcost(libraries[i],scores,time,CheckedBooks);
            continue;
        }
        // double perScore = ((double)libraries[i]->findBestScore(CheckedBooks,scores,time) / bestSum)*100.0;
        // double perDays = ((double)libraries[i]->get_SignUpTime()/time);
        // double cost = perScore / (perDays);
        double cost = ((double)libraries[i]->findBestScore(CheckedBooks,scores,time))/((double) libraries[i]->get_SignUpTime());
        // cout << cost << " ";
        //double cost = findcost(libraries[i],scores,time,CheckedBooks);
        if(cost > max){
            max = cost;
            best = i;
        }
    }

    return best;
}

// bool findBetter(Library **libraries,int *scores,int bestSign,int bestScore,int L,bool *CheckedBooks,int sumScore,int *time,ofstream &outputFile) {
//
//     int i;
//
//     bool flag = false;
//     int maxIndexI = -1;
//     int maxIndexJ = -1;
//     int bestScoreI = -1;
//     int bestScoreJ = -1;
//
//     for(i=0;i<L;i++) {
//         if(libraries[i]->get_SignUpTime() < bestSign) {
//             if(libraries[i]->isSigned() || libraries[i]->get_SignUpTime() >= bestSign ) {
//                 continue;
//             }
//             int iscore = libraries[i]->findBestScore(CheckedBooks,scores,*time);
//             for(int j=i+1;j<L;j++) {
//                 if(libraries[j]->isSigned() || libraries[i]->get_SignUpTime()+libraries[j]->get_SignUpTime() > bestSign) {
//                     continue;
//                 }
//                 // cout << "maybe best" << endl;
//                 int jscore =libraries[j]->findBestScore(CheckedBooks,scores,*time);
//                 if(iscore+jscore > bestScore) {
//                     // cout << "found better" << endl;
//                     flag = true;
//                     bestScoreI = iscore;
//                     bestScoreJ = jscore;
//                     // if( ((double)iscore / (double)libraries[i]->get_SignUpTime()) > ((double)jscore / (double)libraries[j]->get_SignUpTime()) ) {
//                     maxIndexI = i;
//                     //} else {
//                     maxIndexJ = j;
//                     // }
//                 }
//             }
//         }
//     }
//
//     if(flag) {
//         bool one = findBetter(libraries,scores,libraries[maxIndexI]->get_SignUpTime(),bestScoreI,L,CheckedBooks,sumScore,time,outputFile);
//         if(!one) {
//             // cout << maxIndexI << " ";
//             libraries[maxIndexI]->setSigned();
//             *time -= libraries[maxIndexI]->get_SignUpTime();
//             libraries[maxIndexI]->findBestScore(CheckedBooks,scores,*time);
//             libraries[maxIndexI]->SelectBooks(CheckedBooks,scores,*time,outputFile,&sumScore);
//         }
//         int two = findBetter(libraries,scores,libraries[maxIndexJ]->get_SignUpTime(),bestScoreJ,L,CheckedBooks,sumScore,time,outputFile);
//         if(!two) {
//             // cout << maxIndexJ << " ";
//             libraries[maxIndexJ]->setSigned();
//             *time -= libraries[maxIndexJ]->get_SignUpTime();
//             libraries[maxIndexJ]->SelectBooks(CheckedBooks,scores,*time,outputFile,&sumScore);
//         }
//     }
//     return flag;
// }
//
//
// double findcost(Library *library,int *scores,int time,bool *CheckedBooks) {
//     return ((double) library->get_Score(scores,CheckedBooks)/(library->get_SignUpTime())) * ((double) library->get_bookCounter()/library->get_ScannableBooks());
// }

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
