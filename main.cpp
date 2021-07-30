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
        cout << "Enter your option [1-11 / 20 / 21 / 99]: ";
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
                cout << "Enter the date (using numbers) the book was published:\nMonth: ";
                cin >> month;
                cout << "Day: ";
                cin >> day;
                cout << "Year: ";
                cin >> year;
                auto aDate = make_shared<Date>(month, day, year);
                newBook->setDate(aDate);

                cout << "Adding book to library: " << library.addBook(newBook) << " (should be 1)";
                break;
            }
            case 2: {
                cout << "Listing available books: " << endl;
                for (int i = 0; i < library.getAvailable().getLength(); i++) {
                    cout << library.getAvailable().getEntry(i)->getTitle() << endl;
                }
                break;
            }

            case 3: {

                cout << "Listing checked out books: " << endl;
                for (int i = 0; i < library.getUnavailable().getLength(); i++) {
                    cout << library.getUnavailable().getEntry(i)->getTitle() << endl;
                }
                break;
            }

            case 4: {
                string titleToRemove;
                cout << "Enter the title of the book to remove: ";
                cin >> titleToRemove;
                if(library.removeBook(titleToRemove)) {
                    cout << "Book was removed" << endl;
                } else {
                    cout << "There was an error removing the book" << endl;
                }
                break;
            }
            case 5:
                string keyword;
                cout << "Enter a keyword to search by: ";
                cin >> keyword;
                auto books = library.search(keyword);
                cout << "Books found were: " << endl;
                for (int i = 1; i <= books.getLength(); i++) {
                    auto book = books.getEntry(i);
                    cout << book << endl;
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
                string patrons_name;
                cout << "Enter Patron's name: " << endl;
                cin >> patrons_name;
                if (library.removePatron(patrons_name)) {
                    cout << "Successfully removed patron" << endl;
                } else {
                    cout << "Failed to remove patron" << endl;
                }
                break;
            }
            case 8: {
                auto patrons = library.getPatrons();
                for (int i = 1; i <= patrons.getLength(); i++) {
                    auto patron = patrons.getEntry(i);
                    cout << i << ": " << patron << endl;
                }
                break;
            }
            case 9: {
                string patronName;
                string bookName;
                cout << "Enter Patron's name: ";
                cin >> patronName;
                cout << "Enter Book name: ";
                cin >> bookName;
                library.checkout(patronName, bookName);
                break;
            }
            case 10:

                break;

            case 11:

                break;

            case 20:
                File << library;
                break;

            case 21:
                Library library(fileName);
                break;

        }

    }













}
