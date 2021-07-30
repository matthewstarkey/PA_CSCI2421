//
// Created by Matt Starkey on 7/25/21.
// This is the main running program for the Library class
//
#include <iostream>
#include "Library.h"
using namespace std;
int main() {

    Library library("CSE Library", "123 StreetName Ave.", "9am-9pm");
    int userChoice = 0;
    const string fileName = "library.txt";
    ofstream File(fileName);
    while (userChoice != 99) {

        cout << endl<< string(40, '=') << endl;
        cout << "        CSE LIBRARY MAIN MENU" << endl;
        cout << string(40, '=') << endl;

        cout << "   1) Book:Add" << endl;
        cout << "   2) Book:List Available" << endl;
        cout << "   3) Book:List Checked Out" << endl;
        cout << "   4) Book:Remove By Title" << endl;
        cout << "   5) Book:Search" << endl;

        cout << string(20, '-') << endl;

        cout << "   6) Patron:Add" << endl;
        cout << "   7) Patron:List" << endl;

        cout << string(20, '-') << endl;

        cout << "   8) Check Out Book" << endl;
        cout << "   9) Place Hold" << endl;
        cout << "   10) Place Book to Drop Box" << endl;
        cout << "   11) Check In Books From Drop Box" << endl;

        cout << string(20, '-') << endl;

        cout << "   20) Save Data" << endl;
        cout << "   21) Load Data" << endl;

        cout << string(20, '-') << endl;

        cout << "   99) Quit" << endl;
        cin >> userChoice;

        switch (userChoice) {
            case 1: {
                string title;
                string isbn;
                string publisher;
                int numOfAuthors;
                cout << "Please enter the title of the new book: ";
                cin >> title;
                cout << "Please enter the isbn of the new book: ";
                cin >> isbn;
                cout << "Please enter the publisher of the new book: ";
                cin >> publisher;
                auto newBook = make_shared<Book>(title, isbn, publisher);

                cout << "How many authors does the book have? ";
                cin >> numOfAuthors;
                while (numOfAuthors > 0) {
                    string authorName;
                    cout << "Enter the name of author " << numOfAuthors << ": ";
                    cin >> authorName;
                    auto anAuthor = make_shared<Author>(authorName);
                    newBook->addAuthor(anAuthor);
                    numOfAuthors--;
                }

                int month;
                int day;
                int year;

                cout << "Enter the date (using numbers) the book was published:\nMonth(1-12): ";
                cin >> month;

                cout << "Day(1-31): ";
                cin >> day;

                cout << "Year: ";
                cin >> year;

                auto aDate = make_shared<Date>(month, day, year);
                newBook->setDate(aDate);

                cout << "Adding book to library: " << library.addBook(newBook) << " (should be 1)";
                break;
            }
            case 2: {
                cout << "Printing a list of available books:" << endl;
                LinkedList<shared_ptr<Book>> foundBooks = library.getAvailable();
                cout << "total found books: " << foundBooks.getLength() << endl;
                for (int i = 1; i <= foundBooks.getLength(); i++) {
                    cout << *foundBooks.getEntry(i);
                }
                break;
            }

            case 3: {
                cout << "Printing a list of checked out books:" << endl;
                LinkedList<shared_ptr<Book>> foundBooks = library.getUnavailable();
                for (int i = 1; i <= foundBooks.getLength(); i++) {
                    cout << *foundBooks.getEntry(i);
                }
                break;
            }
            case 4: {
                string bookName;
                cout << "Enter the name of the book you would like to remove: " << endl;
                cin >> bookName;
                if (library.removeBook(bookName))
                    cout << bookName << " successfully removed!" << endl;
                else
                    cout << bookName << " not found in library." << endl;
                break;
            }
            case 5: {
                string keyword;
                cout << "Enter a keyword to search by: ";
                cin >> keyword;
                auto books = library.search(keyword);
                cout << "Books found were: " << endl;
                for (int i = 1; i <= books.getLength(); i++) {
                    auto book = books.getEntry(i);
                    cout << *book << endl;
                }
                break;
            }
            case 6: {
                string patron_name;
                string patron_address;
                string patron_phone_number;
                cout << "Enter Patron's name: ";
                cin >> patron_name;
                cout << endl << "Enter Patron's address: ";
                cin >> patron_address;
                cout << endl << "Enter Patron's Phone #";
                cin >> patron_phone_number;
                auto patron = make_shared<Patron>(patron_name, patron_address, patron_phone_number);
                library.addPatron(patron);
                cout << "Patron added!" << endl;
                break;
            }
            case 7: {
                LinkedList<shared_ptr<Patron>> patrons = library.getPatrons();
                for (int i = 1; i <= patrons.getLength(); i++) {
                    cout << patrons.getEntry(i)->getName() << std::endl;
                }
                break;
            }
            case 8: {

                string patronName;
                string bookName;
                cout << "Enter Patron's name: ";
                cin >> patronName;
                cout << "Enter Book name: ";
                cin >> bookName;
                if(library.checkout(patronName, bookName)) {
                    cout << "Successfully checkout book" << endl;

                } else {
                    cout << "Failed to checkout" << endl;
                }


                break;
            }
            case 9: {
                string patron_name;
                string book_name;
                cout << "Enter book's name: " << endl;
                cin >> book_name;
                cout << "Enter Patron's name: " << endl;
                cin >> patron_name;
                if(library.addHold(book_name,patron_name)) {
                    cout << "Successfully put book on hold" << endl;
                } else {
                    cout << "Failed to put book on hold" << endl;
                }
                break;
            }
            case 10: {
                string bookName;
                string patronName;
                bool foundBook = false;
                cout << "Enter the name of the book to place in drop box: ";
                cin >> bookName;
                cout << "Enter the name of the patron dropping off the book ";
                cin >> patronName;
                LinkedList<shared_ptr<Book>> checkedBooks = library.getUnavailable();

                for (int i = 1; i <= checkedBooks.getLength(); i++) {
                    if (checkedBooks.getEntry(i)->getTitle() == bookName) {
                        library.dropoff(bookName, patronName);
                        foundBook = true;
                        cout << "Book dropped off!" << endl;
                    }
                }
                if (!foundBook)
                    cout << "Cannot find that book in checked books." << endl;

                break;
            }

            case 11: {
                library.emptyReturn();
                cout << "Dropbox emptied." << endl;
                break;
            }

            case 20: {
                File << library;
                break;
            }

            case 21: {
                Library library(fileName);
                break;
            }

            default:{
                cout << "Please enter a number of a menu option." <<endl;
                break;
            }

        }

    }
}
