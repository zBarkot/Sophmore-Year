// In this assignment you will be creating a program that simulates a book invetory system. Each book should have attributes of title author publication year and price
//  Your program should be able to handle adding and removing books from the inventory
/***********************************************
Author: Barkot Zeyohannes
Date: Febrary 29, 2024
Purpose: Simulate a book inventory system
Sources of Help: <Please list any sources that you used
 for help: tutors, web sites, lab assistants etc.>
Time Spent: <Insert how much time you spent
on the assignment here>
***********************************************/
#include <iostream>
#include <string>

using namespace std;

// Task 1: Design a Book class

class Book
{
public:
    friend class BookInventory;

    // Default constructor
    Book();

    // Value constructor
    Book(string iTitle, string iAuthor, int iYear, double iPrice);

    // Accessor functions
    string getTitle() const;
    string getAuthor() const;
    int getYear() const;
    double getPrice() const;

private:
    string title;
    string author;
    int year;
    double price;
};

// Default constructor
Book::Book() : title(""), author(""), year(2023), price(0.0) {}

// Value constructor
Book::Book(string iTitle, string iAuthor, int iYear, double iPrice)
    : title(iTitle), author(iAuthor), year(iYear), price(iPrice) {}

// Accessor functions
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
double Book::getPrice() const { return price; }

// Task 2: Implement a BookInventory class

class BookInventory
{
public:
    // Constructor
    BookInventory();

    // Destructor
    ~BookInventory();

    // Copy constructor
    BookInventory(const BookInventory &oldInv);

    // Member functions
    void addBook(const Book &newBook);
    void removeBook(const string &title);
    void removeAll();
    void displayAll() const;

    // Accessor functions
    Book* getBooks() const;
    int getCapacity() const;
    int getNumOfBooks() const;

    //overloaded operators
    BookInventory operator=(const BookInventory &left);

private:
    Book *bookArray;
    int capacity;
    int numBooks;
};

// Constructor
BookInventory::BookInventory()
{
    capacity = 5;
    numBooks = 0;
    bookArray = new Book[capacity];
}

// Destructor
BookInventory::~BookInventory()
{
    delete[] bookArray;
}

// Copy constructor
BookInventory::BookInventory(const BookInventory &oldInv)
{
    capacity = oldInv.capacity;
    numBooks = oldInv.numBooks;
    bookArray = new Book[capacity];
    for (int i = 0; i < numBooks; ++i)
    {
        bookArray[i] = oldInv.bookArray[i];
    }
}

// Member function to add a book
void BookInventory::addBook(const Book &newBook)
{
    if (numBooks == capacity)
    {
        capacity *= 2;
        Book *temp = new Book[capacity];
        for (int i = 0; i < numBooks; ++i)
        {
            temp[i] = bookArray[i];
        }
        delete[] bookArray;
        bookArray = temp;
    }
    bookArray[numBooks++] = newBook;
}

// Member function to remove a book
void BookInventory::removeBook(const string &title)
{
    for (int i = 0; i < numBooks; ++i)
    {
        if (bookArray[i].getTitle() == title)
        {
            for (int j = i; j < numBooks - 1; ++j)
            {
                bookArray[j] = bookArray[j + 1];
            }
            numBooks--;
            return;
        }
    }
    cout << "Book with title '" << title << "' not found." << endl;
}

// Member function to remove all books
void BookInventory::removeAll()
{
    numBooks = 0;
}

// Member function to display all books
void BookInventory::displayAll() const
{
    for (int i = 0; i < numBooks; ++i)
    {
        cout << "Title: " << bookArray[i].getTitle() << endl;
        cout << "Author: " << bookArray[i].getAuthor() << endl;
        cout << "Year Published: " << bookArray[i].getYear() << endl;
        cout << "Price: " << bookArray[i].getPrice() << endl;
        cout << endl;
    }
    cout << "Capacity: " << capacity << endl;
    cout << "Number of Books: " << numBooks << endl;
}

// Accessor functions
Book* BookInventory::getBooks() const { return bookArray; }
int BookInventory::getCapacity() const { return capacity; }
int BookInventory::getNumOfBooks() const { return numBooks; }

BookInventory BookInventory::operator=(const BookInventory &left) {
    if(this != &left) {
        for(int i = 0; i < left.numBooks; i++){

            bookArray[i] = left.bookArray[i];

        }
    capacity = left.capacity;
    numBooks = left.numBooks;
    }
    return *this;

}


int main(void)
{
    // Create instances of Book objects
    Book book1("Title1", "Author1", 2000, 20.0);
    Book book2("Title2", "Author2", 2010, 15.0);

    // Add books to BookInventory object
    BookInventory inventory, inventory2;
    inventory.addBook(book1);
    inventory.addBook(book2);

    // Display list of books
    cout << "Inventory:" << endl;
    inventory.displayAll();

    // Test removal of a book
    inventory.removeBook("Title1");

    // Display list of books again
    cout << "\nInventory after removal:" << endl;
    inventory.displayAll();

    // Create a copy of the existing BookInventory object
    BookInventory copyInventory = inventory;

    // Remove all books from the first BookInventory object
    inventory.removeAll();

    // Display the first BookInventory object (should be empty)
    cout << "\nInventory after removing all books:" << endl;
    inventory.displayAll();

    // Display the second BookInventory object (should contain several books)
    cout << "\nCopied Inventory:" << endl;
    copyInventory.displayAll();

  //testing copy assignment operator
  inventory2 = inventory;
  cout << "\nInventory2 after copy assignment operator:" << endl;
  inventory2.displayAll();
  

    return 0;
}
