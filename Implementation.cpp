#include <iostream>
#include "Interface.hpp"
#include "quickSort.hpp"

//Book::Book(int id, int score):BookID(id), Score(score){};
using namespace std;

Library::Library(int BookNum,int sTime, int maxBooks):SignUpTime(sTime),ScannableBooks(maxBooks){
    BookCounter = 0;
    Signed = false;
    books = new int[BookNum];
}

Library::~Library(){
    delete[] books;
}

void Library::InsertBook(int bookId){
    books[BookCounter] = bookId;
    BookCounter++;
}
int Library::findBestScore(bool* CheckedBooks,int *scores,int leftTime,int *CommonBooks){
    leftTime -= SignUpTime;
	int *scoresCopy = new int[BookCounter];
	for(int i=0;i<BookCounter;i++) {
        if(!CheckedBooks[books[i]]) {
            scoresCopy[i] = scores[books[i]];
        }
        else {
            scoresCopy[i] = 0;
        }
    }

	// quickSort(scoresCopy,0,BookCounter-1,books);
    swift0(books,scoresCopy,BookCounter);
    int sentBooks = min(BookCounter,ScannableBooks*leftTime);
    delete[] scoresCopy;
    if(sentBooks <= 0 ){
        return 0;
    }
    int score = 0;
    int i;
    for(i=1;i<=sentBooks;i++){
        if(!CheckedBooks[books[BookCounter-i]]) {
            score += scores[books[BookCounter-i]] - (CommonBooks[books[BookCounter-i]]*CommonBooks[books[BookCounter-i]]);
        }
        else {
            break;
        }
    }
    return score;
}


void Library::sortBook(int *scores,int *CommonBooks) {
    int *scoresCopy = new int[BookCounter];
    for(int i=0;i<BookCounter;i++) {
        scoresCopy[i] = scores[books[i]]-(CommonBooks[books[i]]*CommonBooks[books[i]]);
    }
    quickSort(scoresCopy,0,BookCounter-1,books);
    delete[] scoresCopy;
}

bool Library::SelectBooks(bool* CheckedBooks,int *scores,int leftTime,ofstream &outputFile,int *scoreSum){
	// int *scoresCopy = new int[BookCounter];
	// for(int i=0;i<BookCounter;i++) {
    //     if(!CheckedBooks[books[i]]) {
    //         scoresCopy[i] = scores[books[i]];
    //     }
    //     else {
    //         // cout << "booked checked " << books[i] <<endl;
    //         scoresCopy[i] = 0;
    //     }
    // }
    //
    // cout << "books: ";
    // printArray(books,BookCounter);
    // cout << "soces: ";
    // printArray(scoresCopy,BookCounter);
	// quickSort(scoresCopy,0,BookCounter-1,books);
    // cout << "books: ";
    // printArray(books,BookCounter);
    // cout << "soces: ";
    // printArray(scoresCopy,BookCounter);
    // cout << endl;
    // int maxBooks = (ScannableBooks*leftTime);
    // uint sentBooks;
    // if(BookCounter / leftTime < ScannableBooks) {
    //     sentBooks = BookCounter;
    // }
    // else {
    //     sentBooks = (ScannableBooks*leftTime);
    // }
    int sentBooks = min(ScannableBooks*leftTime,BookCounter);
    // delete[] scoresCopy;
    if(sentBooks <= 0 ){
        // cout << "counter "<< BookCounter <<endl;
        // cout << "sent " <<sentBooks <<endl;
        return false;
    }else {
        outputFile << sentBooks  << endl;
    }
    for(int i=1;i<=sentBooks;i++){
        outputFile << books[BookCounter-i] << " ";
        if(!CheckedBooks[books[BookCounter-i]]) {
            (*scoreSum) += scores[books[BookCounter-i]];
            CheckedBooks[books[BookCounter-i]] = true;
            scores[books[BookCounter-i]] = 0;
            // cout << "checked " << books[BookCounter-i] <<endl;
        }
    }
    outputFile << "\n";
    return true;
}

int Library::get_SignUpTime(){
    return SignUpTime;
}


void Library::orderedBooks(int *scores){
    int i;
    for(i=1;i<BookCounter;i++) {
        if(scores[books[i-1]] > scores[books[i]]) {
            cout << "books not ordered\n";
            return;
        }
    }
    // cout << "books are ordered\n";
}


void Library::printBooks(int *scores){
    int i;
    // for(i=0;i<BookCounter;i++) {
    //     cout << books[i] << " ";
    // }
    cout << endl;
    for(i=0;i<BookCounter;i++) {
        cout << scores[books[i]] << " ";
    }
    cout << endl;
}


int Library::get_Score(int *scores,bool *CheckedBooks) {
    int sum = 0;
    for (int i = 0; i < BookCounter; i++) {
        if(!CheckedBooks[books[i]]) {
            sum += scores[books[i]];
        }
    }
    return sum;
}

bool Library::isSigned(){
    return Signed;
}

void Library::setSigned(){
    Signed = true;
}

int Library::get_bookCounter(){
    return BookCounter;
}


int Library::get_ScannableBooks(){
    return ScannableBooks;
}

int Library::get_book(int place){
    if(place < BookCounter)
        return books[place];
    else
        return -1;
}
