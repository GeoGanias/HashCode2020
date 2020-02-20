#include <iostream>
#include <fstream>
#include "Interface.hpp"
using namespace std;

int selectLibrary(Library**,int *,int, int,bool *);

int main(void) {
    ifstream infile("./input/c_incunabula.txt");
    if(!infile.is_open()) {
        cout << "file error\n";
        return -1;
    }
    int B,L,D;
    infile >> B >> L >> D;

    int *scores = new int[B];
    bool *CheckedBooks = new bool[B];

    int i;
    for(i=0;i<B;i++) {
        infile >> scores[i];
        CheckedBooks[i] = false;
    }

    Library **libraries = new Library*[L];
    for(i=0;i<L;i++) {
        int N,T,M;
        infile >> N >> T >> M;
        libraries[i] = new Library(N,T,M);
        int j;
        for(j=0;j<N;j++) {
            int book_id;
            infile >> book_id;
            libraries[i]->InsertBook(book_id);
        }
    }
    infile.close();

/*
    for(i=0;i<L;i++) {
        int j;
        for(j=0;j<libraries[i]->get_bookCounter();j++) {
            cout << libraries[i]->get_book(j)<< " ";
        }
        cout << endl;
    }
*/

    cout << L << endl;
    for(i=0; i<L ; i++){
        if(D < 0) {
            break;
        }
        int x = selectLibrary(libraries, scores, D, L,CheckedBooks);
        libraries[x]->setSigned();
        cout << x << " " ;
        //Library Selected
        D -= libraries[x]->get_SignUpTime();
        libraries[x]->SelectBooks(CheckedBooks,scores,D);


    }

    delete[] scores;
    return 0;
}
