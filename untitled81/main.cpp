#include<iostream>
#include<cstring>
using namespace std;

class Book{
    char * ime;
    int * isbn;
    int brStr;
public:
    Book() {
        ime=new char[0];
        strcpy(ime,"");
        isbn=new int[0];
        brStr=0;
    }
    Book(char *ime, int * isbn, int brStr) {
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->isbn=new int[5];
        for(int i=0;i<5;i++) {
            this->isbn[i]=isbn[i];
        }
        this->brStr=brStr;
    }
    Book(const Book &o) {
        this->ime=new char[strlen(o.ime)+1];
        strcpy(this->ime,o.ime);
        this->isbn=new int[5];
        for(int i=0;i<5;i++) {
            this->isbn[i]=o.isbn[i];
        }
        this->brStr=o.brStr;
    }
    Book &operator= (const Book &o) {
        if(this!=&o) {
            delete [] ime;
            delete [] isbn;
            this->ime = new char[strlen(o.ime) + 1];
            strcpy(this->ime, o.ime);
            this->isbn = new int[5];
            for (int i = 0; i < 5; i++) {
                this->isbn[i] = o.isbn[i];
            }
            this->brStr = o.brStr;
        }
        return *this;
    }
    ~Book() {
        delete [] ime;
        delete [] isbn;
    }
    bool operator==(const Book &rhs) const {
        for(int i=0;i<5;i++) {
            if (isbn[i] != rhs.isbn[i]){
                return false;
            }
        }
        return true;
    }

    friend ostream &operator<<(ostream &os, const Book &book) {
        os << "Title: " << book.ime << " ISBN: [ ";
        for(int i=0;i<5;i++) {
            os<<book.isbn[i]<<" ";
        }
        cout<<"]"<<endl;
        return os;
    }
    int *getIsbn() {
        return isbn;
    }
    int getStranici(){
        return brStr;
    }
};
class BorrowABook{
    char imeB[100];
    Book * knigi;
    int brEl;
public:
    BorrowABook(char * imeB="") {
        strcpy(this->imeB,imeB);
        knigi=new Book[0];
        brEl=0;
    }
    BorrowABook(char * imeB, Book * knigi, int brEl) {
        strcpy(this->imeB,imeB);
        this->brEl=brEl;
        this->knigi=new Book[brEl];
        for(int i=0;i<brEl;i++) {
            this->knigi[i]=knigi[i];
        }
    }
    BorrowABook &operator+=(Book &b) {
        Book * tmp=new Book[brEl+1];
        for(int i=0;i<brEl;i++) {
            tmp[i]=knigi[i];
        }
        tmp[brEl++]=b;
        delete [] knigi;
        knigi=tmp;
        return *this;
    }
    BorrowABook &operator-=(Book &b) {
        int br=0;
        for(int i=0;i<brEl;i++) {
            if(b.getIsbn()!=knigi[i].getIsbn()) {
                br++;
            }
        }
        Book *tmp=new Book[br];
        int j=0;
        for(int i=0;i<brEl;i++) {
            if(b.getIsbn()!=knigi[i].getIsbn()) {
                tmp[j++]=knigi[i];
            }
        }
        brEl=br;
        delete [] knigi;
        knigi=tmp;
    }
    void printNumberOfPages(int max) {
        cout<<imeB<<endl;
        for(int i=0;i<brEl;i++) {
            if(knigi[i].getStranici()>150) {
                cout<<knigi[i];
            }
        }
    }
};
int main()
{
    BorrowABook library("FINKI-Library");
    int n;
    cin>>n;

    for (int i=0;i<n;i++)
    {
        char title[100];
        int isbn[5];
        int pages;

        cin>>title;

        for (int i=0;i<5;i++)
            cin>>isbn[i];

        cin>>pages;

        Book nov=Book(title,isbn,pages);

        //adding a new book
        library+=nov;
    }

    //the book which has the same isbn as some previous one
    char title[100];
    int isbn[5];
    int pages;
    cin>>title;
    for (int i=0;i<5;i++)
        cin>>isbn[i];
    cin>>pages;

    Book greshka=Book(title,isbn,pages);

    //deleting a book
    library-=greshka;

    library.printNumberOfPages(150);

    return 0;
}