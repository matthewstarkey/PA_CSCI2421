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


                break;
            }

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                break;

            case 7:

                break;

            case 8:

                break;

            case 9:

                break;

            case 10:

                break;

            case 11:

                break;

            case 20:

                break;

            case 21:

                break;

        }

    }













}
