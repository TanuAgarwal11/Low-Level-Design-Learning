#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    string bookTitle;
    string authorName;
    string isbn;
    bool isAvailable = true;

public:
    Book(string title, string author, string isbn)
    {
        bookTitle = title;
        authorName = author;
        isbn = isbn;
    }

    bool borrowBook()
    {
        if (isAvailable)
        {
            isAvailable = false;
            return true;
        }
        return false;
    }

    void returnBook()
    {
        isAvailable = true;
    }

    void displayInfo()
    {
        cout << bookTitle << " by " << authorName << " (ISBN : " << isbn << ") - " << (isAvailable ? "Available" : "Borrowed") << endl;
    }
};

int main()
{
    Book b1("Mathematics", "RD Sharma", "11-21-4");
    b1.displayInfo();
    if(b1.borrowBook()){
        cout<<"Book borrowed successfully"<<endl;
    }
    else{
        cout<<"Already borrowed"<<endl;
    }
    b1.returnBook();
    return 0;
}