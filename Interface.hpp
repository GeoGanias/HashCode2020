/*class Book{
    private:
        int BookID;
        int Score;
    public:
        Book();
        Book(int,int);
        ~Book();
};*/

class Library{
    private:
        int *books;
        int BookCounter;
        int ScanTime;
        int ScannableBooks; //per day
    public:
        Library(int,int,int);
        ~Library();
        void InsertBook(int);
        int get_ScanTime();
        int get_ScannableBooks();
        int get_book(int);
};

