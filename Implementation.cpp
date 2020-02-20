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

void Library::InsertBook(int bookId){
    books[BookCounter] = bookId;
    BookCounter++;
}

void Library::SelectBooks(bool* CheckedBooks,int *scores,int leftTime){
	int *scoresCopy = new int[BookCounter];
	for(int i=0;i<BookCounter;i++) {
        if(!CheckedBooks[i]) {
            scoresCopy[i] = scores[i];
        }
        else {
            scoresCopy[i] = 0;
        }
    }

	quickSort(scoresCopy,0,BookCounter-1,books);

    int sentBooks = min(BookCounter,ScannableBooks*leftTime);
    cout << sentBooks  << endl;
    for(int i=0;i<sentBooks;i++){
        cout << books[i] << " ";
        CheckedBooks[books[i]] = true;
    }
    cout << "\n";

}

int Library::get_SignUpTime(){
    return SignUpTime;
}


int Library::get_Score(int *scores,bool *CheckedBooks) {
    int sum = 0;
    for (int i = 0; i < BookCounter; i++) {
        if(!CheckedBooks[i]) {
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
