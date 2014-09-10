//  Ryan Goss
//  Assignment 3
//  Dr. Fleming
//  Due Sunday, July 27 @ 5 pm

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include "tree.h"
using namespace std;

//See comment below in function defintion
Library* LibraryFromFile(const char* filename);

//The main function essentially contains the user interface of text and a while loop to allow the user to input their
//choices of operations. Based on input, the program executes the LibraryFromFile function or Library class member functions
int main()
{
    cout << "Hello! This program manages your library. Select an option from the menu below." << endl;
    cout << "NOTE: Valid entries are 1, 2, 3, 4, 5 or 6" << endl << endl;
    
    Library* myLib;
    bool done = false;
    string user_input;
    while (done == false) {
        cout << "1) Insert all books in tree. NOTE: This MUST be done first to do any of the other options." << endl;
        cout << "2) Find a book." << endl;
        cout << "3) Sell a book." << endl;
        cout << "4) Print Inventory." << endl;
        cout << "5) Print bargain books." << endl;
        cout << "6) Terminate program." << endl;
        cin >> user_input;
        while (user_input != "1" && user_input != "2" && user_input != "3" && user_input != "4" && user_input != "5" && user_input != "6") {
            cout << "That is not a valid entry. Enter either 1, 2, 3, 4, 5, or 6" << endl;
            cin >> user_input;
		}
        if (user_input == "1") {
            cout << "Opening inventory..." << endl;
            myLib = LibraryFromFile("inventory.txt");
        }
        else if (user_input == "2") {
            string user_input2;
            cout << "Find a book by 1) ISBN or 2) Title. (Enter 1 or 2)" << endl;
            cin >> user_input2;
            while (user_input2 != "1" && user_input2 != "2") {
                cout << "That is not a valid entry. Enter either 1 or 2" << endl;
                cin >> user_input2;
            }
            if (user_input2 == "1") {
                string user_ISBN;
                cout << "Please enter the ISBN you wish to find: ";
                cin >> user_ISBN;
                myLib->SearchBooks_ISBN(myLib->returnroot(), user_ISBN);
            }
            else if (user_input2 == "2") {
                string user_title;
                cout << "Please enter the title you wish to find: ";
                getline(cin, user_title);
                getline(cin, user_title);
                myLib->SearchBooks_Title(myLib->returnroot(), user_title);
            }
        }
        else if (user_input == "3") {
            string user_input3;
            cout << "Sell a book by 1) ISBN or 2) Title. (Enter 1 or 2)" << endl;
            cin >> user_input3;
            while (user_input3 != "1" && user_input3 != "2") {
                cout << "That is not a valid entry. Enter either 1 or 2" << endl;
                cin >> user_input3;
            }
            if (user_input3 == "1") {
                string user_ISBN;
                cout << "Please enter the ISBN of the book you are selling: ";
                cin >> user_ISBN;
                myLib->SellBookbyISBN(myLib->returnroot(), user_ISBN);
            }
            else if (user_input3 == "2") {
                string user_title;
                cout << "Please enter the title of the book you are selling: " << endl;
                getline(cin, user_title);
                getline(cin, user_title);
                myLib->SellBookbyTitle(myLib->returnroot(), user_title);
            }

        }
        else if (user_input == "4") {
            Book* top = myLib->returnroot();
            myLib->printBooks(top);
        }
        else if (user_input == "5") {
            double user_price;
            cout << "Please enter the maximum price you are willing to pay: ";
            cin >> user_price;
            myLib->printBargainBooks(myLib->returnroot(), user_price);
        }
        else if (user_input == "6") {
            cout << "Thanks! Exiting program now!" << endl;
            done = true;
        }
    }
}

//The following function takes a filename string and opens the file with ifstream. Lines are read and modified accordingly
//to be inserted into a new Book which takes all of the imported and stored variables.
Library* LibraryFromFile(const char * filename)
{
    Library *myLibrary = new Library;
    vector <string> record;
	ifstream fin(filename);
	if (!fin) {
		cout << "Could not open file: " << filename << endl;
	}
	
    
	ifstream openin(filename);
	while (fin) {
		string s;
        if (!getline( fin, s )) break;
        
        istringstream ss( s );
        
        
        while (ss)
        {
            string s;
            if (!getline( ss, s, ';' )) break;
            record.push_back( s );
            
        }
        
    }
    
    //This loop checks for ancillary text such as "ISBN" and $ sign
    for (unsigned int i = 0; i < record.size(); i++) {
        string extract;
        if (record[i].substr(0, 1) == " ") {
            extract = record[i].substr(1, record[i].size());
            record[i] = extract;
        }
        if (record[i].substr(0, 6) == "ISBN: ") {
            extract = record[i].substr(6, record[i].size());
            record[i] = extract;
        }
        if (record[i].substr(0, 1) == "$") {
            extract = record[i].substr(1, record[i].size());
            record[i] = extract;
        }
        
        //cout << record[i] << endl;
    }
    cout << endl << endl;
    //This loop creates variables from the captured vector to use the explicit constructor and create a book
    for (unsigned int m = 1; m <= record.size()/5; m++) {
        string aAuthor;
        string aTitle;
        string aISBN;
        double aPrice = 0;
        int aQuantity = 0;
        
        for (unsigned int k = 1; k <= 5; k++) {
            if (k == 1) {
                aAuthor = record[m*5-(5-k)-1];
            }
            if (k == 2) {
                aTitle = record[m*5-(5-k)-1];
            }
            if (k == 3) {
                aISBN = record[m*5-(5-k)-1];
            }
            if (k == 4) {
                aPrice = atof(record[m*5-(5-k)-1].c_str());
            }
            if (k == 5) {
                aQuantity = atoi(record[m*5-(5-k)-1].c_str());
            }
        }
        //cout << aPrice << endl;
        myLibrary->addBook(aAuthor, aTitle, aISBN, aPrice, aQuantity);
    }

    
    return myLibrary;
}
