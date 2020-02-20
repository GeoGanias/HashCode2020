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
        bool Signed;
        int BookCounter;
        int SignUpTime;
        int ScannableBooks; //per day
    public:
        Library(int,int,int);
        ~Library();
        void InsertBook(int);
        void SelectBooks(bool*,int*,int);
        int get_Score(int *,bool *);
        int get_bookCounter();
        int get_SignUpTime();
        int get_ScannableBooks();
        int get_book(int);
        bool isSigned();
        void setSigned();
};
