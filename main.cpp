#include <iostream>
#include <fstream>
#include "Interface.hpp"
using namespace std;

int selectLibrary(Library**,int *,int, int);

int main(void) {
    ifstream infile("./input/a_example.txt");
    if(!infile.is_open()) {
        cout << "file error\n";
        return -1;
    }
    int B,L,D;
    infile >> B >> L >> D;

    int *scores = new int[B];
    int i;
    for(i=0;i<B;i++) {
        infile >> scores[i];
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


    for(i=0;i<L;i++) {
        int j;
        for(j=0;j<libraries[i]->get_bookCounter();j++) {
            cout << libraries[i]->get_book(j)<< " ";
        }
        cout << endl;
    }


    for(i=0; i<L ; i++){
        cout << "iter\n";
        int x;
        x = selectLibrary(libraries, scores, D, L);
        cout << x;

    }

    delete[] scores;
    return 0;
}
