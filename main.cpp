#include <iostream>
#include <fstream>
#include <string>
#include "Interface.hpp"

using namespace std;

int selectLibrary(Library**,int *,int, int,bool *,int,int *);

int main(int argc,char **argv) {
    ifstream infile;
    if(argc > 1) {
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
    int *CommonBooks = new int[B];

    int i;
    for(i=0;i<B;i++) {
        infile >> scores[i];
        CheckedBooks[i] = false;
        CommonBooks[i] = 0;
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
            CommonBooks[book_id] += 1;
        }
        libraries[i]->sortBook(scores,CommonBooks);
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
        int x = selectLibrary(libraries, scores, D, L,CheckedBooks,B,CommonBooks);
        D -= libraries[x]->get_SignUpTime();

        if(D<=0) {
            break;
        }

        outputFile << x << " ";
        // cout << x <<endl;
        libraries[x]->setSigned();
        // libraries[x]->orderedBooks(scores);
        // libraries[x]->printBooks(scores);
        //Library Selected
        if(!libraries[x]->SelectBooks(CheckedBooks,scores,D,outputFile,&scoreSum)) {
            // cout << D << "   error\n";
            break;
        }

    }
    // uint sum2 = 0;
    // for(i=0;i<B;i++) {
    //     if(CheckedBooks[i]) {
    //         sum2 += scores[i];
    //     }
    // }

    // cout << "score is: " << sum2 <<endl;
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
    delete[] CommonBooks;
    for(i=0;i<L;i++) {
        delete libraries[i];
    }
    delete[] libraries;
    return 0;
}
