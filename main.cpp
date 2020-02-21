#include <iostream>
#include <fstream>
#include <string>
#include "Interface.hpp"

using namespace std;

int selectLibrary(Library**,int *,int, int,bool *);

int main(int argc,char **argv) {
    ifstream infile;
    if(argc > 2) {
        infile.open(argv[1]);
    }
    else {
        infile.open("./input/a_example.txt");
    }
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
    // print books
    for(i=0;i<L;i++) {
        int j;
        for(j=0;j<libraries[i]->get_bookCounter();j++) {
            cout << libraries[i]->get_book(j)<< " ";
        }
        cout << endl;
    }
*/
    /* create a temp file and keep the books*/
    int scoreSum = 0;
    ofstream outputFile("outputTmpFile");
    for(i=0; i<L ; i++){
        if(D <= 0) {
            break;
        }
        int x = selectLibrary(libraries, scores, D, L,CheckedBooks);
        outputFile << x << " ";
        libraries[x]->setSigned();
        //Library Selected
        D -= libraries[x]->get_SignUpTime();
        if(!libraries[x]->SelectBooks(CheckedBooks,scores,D,outputFile,&scoreSum)) {
            break;
        }

    }
    // cout << "score is: " << scoreSum <<endl;
    outputFile.close();
    /* print file to cout and add the number of libraries used */
    ifstream f("outputTmpFile");
    ofstream outfile;
    if(argc == 3) {
        outfile.open(argv[2]);
    }
    else { // set outfile cout
        outfile.basic_ios<char>::rdbuf(cout.rdbuf());
    }
    outfile << i << endl;
    string line;
    for(int j=0;j<i;j++) {
        getline(f, line);
        outfile << line << endl;
        getline(f, line);
        outfile << line << endl;
    }
    f.close();
    outfile.close();
    cout << scoreSum << endl;
    remove("outputTmpFile"); //delete the tmp file
    delete[] scores;
    delete[] CheckedBooks;
    for(i=0;i<L;i++) {
        delete libraries[i];
    }
    delete[] libraries;
    return 0;
}
