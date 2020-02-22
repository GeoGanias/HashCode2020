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
int Library::findBestScore(bool* CheckedBooks,int *scores,int leftTime){
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

	quickSort(scoresCopy,0,BookCounter-1,books);

    int sentBooks = min(BookCounter,ScannableBooks*leftTime);
    delete[] scoresCopy;
    if(sentBooks <= 0 ){
        return 0;
    }
    int score = 0;
    for(int i=1;i<=sentBooks;i++){
        if(!CheckedBooks[books[BookCounter-i]]) {
            score += scores[books[BookCounter-i]];
        }
    }
    return score;
}


bool Library::SelectBooks(bool* CheckedBooks,int *scores,int leftTime,ofstream &outputFile,int *scoreSum){
	int *scoresCopy = new int[BookCounter];
	for(int i=0;i<BookCounter;i++) {
        if(!CheckedBooks[books[i]]) {
            scoresCopy[i] = scores[books[i]];
        }
        else {
            // cout << "booked checked " << books[i] <<endl;
            scoresCopy[i] = 0;
        }
    }

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
    uint maxBooks = (uint)(ScannableBooks*leftTime);
    uint sentBooks;
    if((uint)BookCounter < maxBooks) {
        sentBooks = BookCounter;
    }
    else {
        sentBooks = maxBooks;
    }
    delete[] scoresCopy;
    if(sentBooks <= 0 ){
        return false;
    }else {
        outputFile << sentBooks  << endl;
    }
    for(uint i=1;i<=sentBooks;i++){
        outputFile << books[BookCounter-i] << " ";
        if(!CheckedBooks[books[BookCounter-i]]) {
            (*scoreSum) += scores[books[BookCounter-i]];
            CheckedBooks[books[BookCounter-i]] = true;
            // cout << "checked " << books[BookCounter-i] <<endl;
        }
    }
    outputFile << "\n";
    return true;
}

int Library::get_SignUpTime(){
    return SignUpTime;
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
