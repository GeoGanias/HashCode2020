#include <iostream>
#include "Interface.hpp"

//Book::Book(int id, int score):BookID(id), Score(score){};

Library::Library(int BookNum,int sTime, int maxBooks):ScanTime(sTime),ScannableBooks(maxBooks){
    BookCounter = 0;
    books = new int[BookNum];
}

void Library::InsertBook(int bookId){
    books[BookCounter] = bookId;
    BookCounter++;
}

int Library::get_ScanTime(){
    return ScanTime;
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
