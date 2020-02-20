#include <iostream>
#include "Interface.hpp"

//Book::Book(int id, int score):BookID(id), Score(score){};

Library::Library(int BookNum,int sTime, int maxBooks):SignUpTime(sTime),ScannableBooks(maxBooks){
    BookCounter = 0;
    books = new int[BookNum];
}

void Library::InsertBook(int bookId){
    books[BookCounter] = bookId;
    BookCounter++;
}

int Library::get_SignUpTime(){
    return SignUpTime;
}


int Library::get_Score(int *scores){
    int sum = 0;
    for (size_t i = 0; i < BookCounter; i++) {
      sum += scores[books[i]];
    }
    return sum;
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
