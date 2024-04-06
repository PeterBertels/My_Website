// Author: Peter Bertels
// Date Created: Jun 9th, 2021
// Date Modified: Jun 21st, 2021
// Library Management System

#include <iostream>

using namespace std;

// function prototypes
struct Book;
struct Library;
void initialize(Book& _book, string _id, string _title, string _authorName, string _publisher);
void displayBook(Book& _book);
void displayLibrary (Library& l, int n);
Book bookInfo (Book b);
int indexOfLastBook(Library& l);
void addBook (Library& l, Book b, int n);
void addNewBook (Library& l, int n);
bool compareBooks (Book a, Book b);
int findBook (Library& l, int n);
void removeBook (Library& l, int n);
void modifyBook (Library& l, int n);
int genericMenu(string prompt, string anArray[], int sizeOfArray);
void borrowReturnBook (Library& l, int n);
void initialize (Library& l, int n);

struct Book {
    // book info
    string id;
    string title;
    string authorName;
    string publisher;
    bool checkedOut = false;
};

struct Library {
    // array of type book
    static const int n = 10;
    struct Book arr[n];
    // items in library
    int total = 0;
};

// function to initialize book
void initialize(Book& _book, string _id, string _title, string _authorName, string _publisher) {
    _book.id = _id;
    _book.title = _title;
    _book.authorName = _authorName;
    _book.publisher = _publisher;
}

// function to display book
void displayBook(Book& _book) {
    string status = "Available";
    if (_book.checkedOut) { status = "Borrowed"; }
    cout << "Book id: " << _book.id << endl;
    cout << "Title: " << _book.title << endl;
    cout << "Author: " << _book.authorName << endl;
    cout << "Publisher: " << _book.publisher << endl;
    cout << "Status: " << status << endl;
    cout << endl;
}

// function to display library contents
void displayLibrary (Library& l, int n) {
    cout << "Library Contents:\n " << endl;
    // display all actual books until total
    for (int i = 0; i < l.total; i++) {
        displayBook(l.arr[i]);
        // stop displaying at total
        if (i == l.total) {
            break;
        }
    }
    cout << endl;
}

// function to receive new book information
Book bookInfo (Book b) {
    cout << "Enter the book id: " << endl;
    getline(cin, b.id);
    cout << "Enter the title of the book: " << endl;
    getline(cin, b.title);
    cout << "Enter the author's name: " << endl;
    getline(cin, b.authorName);
    cout << "Enter the publisher's name: " << endl;
    getline(cin, b.publisher);
    cout << endl;
    return b;
}

// function to return index of last book according to total
int indexOfLastBook(Library& l){
    return l.total - 1;
}

// function to add book
void addBook (Library& l, Book b, int n) {
    // put a book in the library(array) at the end
    // add 1 to total to add book
    l.total++;
    if (l.total <= n) {
        l.arr[indexOfLastBook(l)] = b;
    }
}

// function to add new book
void addNewBook (Library& l, int n) {
    Book b;
    cout << "NEW BOOK ENTRY..." << endl;
    // call cin.ignore for bookInfo
    cin.ignore();
    // initialize new book (b) with book info
    b = bookInfo(b);
    cout << endl;
    displayBook(b);
    // call addBook to add book to library(array)
    addBook(l,b,n);
    cout << "Book Added To Database! " << endl;
    cout << endl;
}

// function to compare two books
bool compareBooks (Book a, Book b) {
    bool flag = false;
    // flag will return true at first match
    if (a.id == b.id) {
        return flag = true;
    }
    if (a.title == b.title) {
        return flag = true;
    }
    if (a.authorName == b.authorName) {
        return flag = true;
    }
    if (a.publisher == b.publisher) {
        return flag = true;
    }
    return flag;
}

// search function to find book and return index in library(array)
int findBook (Library& l, int n) {
    Book b;
    // added statement to inform user about search function
    cout << "If you are unsure of a Book Property press Enter - Search will return the first match..." << endl;
    // i.e. you could search for a book based off one property by inputing enter or even incorrect detials for the other properties, all that is required is for one property to be correct (for a match)
    // call cin.ignore for bookInfo
    cin.ignore();
    // initialize book being searched for (b) with bookInfo
    b = bookInfo(b);
    for (int i = 0; i < n; i++) {
        // call compareBook to compare b with each book in library(array)
        // return index at first true flag
        if (compareBooks(b, l.arr[i])) {
            cout << "Book Found: " << endl;
            displayBook(l.arr[i]);
            return i;
        }
    }
    cout << "Book not found in Library. Please search again. " << endl;
    cout << endl;
    return n+1;
}

// function to remove a book in the library(array)
void removeBook (Library& l, int n) {
    cout << "Search for a Book to Remove... " << endl;
    // call findBook to search for book to be removed
    int index = findBook(l, n);
    if ( index <= indexOfLastBook(l)) {
        // move last book to index of book to be removed
        l.arr[index] = l.arr[indexOfLastBook(l)];
        // subtract 1 from total to remove book
        l.total--;
        cout << "Book Removed Successfully!" << endl;
        cout << endl;
    }
}

// function to modify a book in the library(array)
void modifyBook (Library& l, int n) {
    cout << "Search for a Book to Modify... " << endl;
    Book b;
    // call findBook to search for book to be modified
    int index = findBook(l, n);
    if ( index <= indexOfLastBook(l)) {
        cout << "Modify Book... " << endl;
        // call bookInfo to initialize book to be modified (b)
        // replace at index returned by findBook
        l.arr[index] = bookInfo(b);
        cout << "Book Modified Successfully! " << endl;
        cout << endl;
    }
}

// genericMenu function
int genericMenu(string prompt, string anArray[], int sizeOfArray) {
    int choice = 0;
    while (choice > sizeOfArray or choice < 1) {
        cout << prompt << endl;
        for (int i = 0; i < sizeOfArray; i++) {
            cout << i + 1 << ") " << anArray[i] << endl;
        }
        while (!(cin >> choice) or choice > sizeOfArray or choice < 1) {
            cout << "This is an invalid input, please enter one of the menu options: ";
            cin.clear();
            cin.ignore(123, '\n');
        }
        cout << endl;
    }
    return choice;
}

// function to borrow or return a book
void borrowReturnBook (Library& l, int n)  {
    cout << "Search for a book to Borrow or Return... " << endl;
    // call findBook to find book to be borrowed
    int index = findBook (l, n);
    // genericMenu
    string borrowOrReturn [] = {"Borrow Book", "Return Book", "Return to Menu"};
    int choice = genericMenu("Would you like to...", borrowOrReturn, 3);
    switch (choice) {
        case 1:
            // set checkedOut to true
            l.arr[index].checkedOut = true;
            cout << l.arr[index].title << " has been checked out by you. " << endl;
            break;
        case 2:
            // set checkedOut to false
            l.arr[index].checkedOut = false;
            cout << l.arr[index].title << " has been returned by you. " << endl;
            break;
        case 3:
            break;
    }
    cout << endl;
}

// function to initialize 5 books in library(array)
void initialize (Library& l, int n) {
    // intialize 5 books
    Book tempBook;
    initialize(tempBook, "book/0", "War and Peace", "Leo Tolstoy", "The Russian Messenger");
    addBook(l, tempBook, n);
    initialize(tempBook, "book/1", "The Intelligent Investor", "Benjamin Graham", "Harper");
    addBook(l, tempBook, n);
    initialize(tempBook, "book/2", "The Hobbit", "J. R. R. Tolkien", "Allen & Unwin");
    addBook(l, tempBook, n);
    initialize(tempBook, "book/3", "Bridge to Terabithia", "Katherine Paterson", "Thomas Y. Crowell Co.");
    addBook(l, tempBook, n);
    initialize(tempBook, "book/4", "Harry Potter and the Philosopher's Stone", "J.K. Rowling", "Bloomsbury");
    addBook(l, tempBook, n);
    // intialize the rest of the library to avoid whitespace matching issues
    for (int i = 5; i <= n + 1; i++) {
        initialize(tempBook, "empty", "empty", "empty", "empty");
        addBook(l, tempBook, n);
    }
    // there are 5 books in total
    l.total = 5;
}

int main() {
    // size of library(array)
    const int n = 10;
    // library
    Library lib;
    // initializing five books
    initialize(lib, n);
    bool keepGoing = true;
    
    // intro menu declaring if someone is a user or librarian
    string introMenu [] = {"LIBRARIAN", "USER"};
    int choice = genericMenu("Welcome to the Library Database. \nPlease Declare Your Status:", introMenu, 2);
    
    if (choice == 1) {
        // Librarian menu
        string optionsLibrarian[] = {"Add A Book To The Library","Remove A Book From The Library","Modify A Book In The Library","Search For A Particular Book And Display It","Examine The Library’s Contents","Quit"};
        while(keepGoing) {
            int choice = genericMenu("Welcome Librarian, would you like to... ", optionsLibrarian, 6);
            switch (choice) {
                case 1:
                    addNewBook(lib,n);
                    break;
                case 2:
                    removeBook(lib,n);
                    break;
                case 3:
                    modifyBook(lib,n);
                    break;
                case 4:
                    cout << "Search for a book in the library to be displayed... " << endl;
                    findBook(lib, n);
                    break;
                case 5:
                    displayLibrary(lib, n);
                    break;
                case 6:
                    cout << "The program will now quit..." << endl;
                    keepGoing = false;
                    break;
            }
        }
    }
    else {
        // User menu
        string optionsUser[] = {"Examine The Library’s Contents","Search For A Particular Book And Display It","Borrow or Return A Book","Quit"};
        while(keepGoing) {
            int choice = genericMenu("Welcome User, would you like to... ",optionsUser, 4);
            switch (choice) {
                case 1:
                    displayLibrary(lib,n);
                    break;
                case 2:
                    cout << "Search for a book in the library to be displayed... " << endl;
                    findBook(lib, n);
                    break;
                case 3:
                    borrowReturnBook(lib, n);
                    break;
                case 4:
                    cout << "The program will now quit..." << endl;
                    keepGoing = false;
                    break;
            }
        }
    }
    return 0;
}// end main
