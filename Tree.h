#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <string>
using namespace std;

class Book {
    //Stored information for each book
    string author;
    string title;
    string ISBN;
    double price;
    int quantity;
	
    //Linker pointers
    Book* left;
	Book* right;
    Book* parent;
    
public:
	//Default and explicit constuctors
    Book();
	Book(string aAuthor, string aTitle, string aISBN, double aPrice, int aQuantity);
    
    //Setters
	void setAuthor(string aAuthor);
    void setTitle(string aTitle);
    void setISBN(string aISBN);
    void setQuantity(int number);
    void setPrice(double aPrice);
	void setLeft(Book *aLeft);
	void setRight(Book *aRight);
    void setParent(Book *aParent);
    
    //Getters
	string getAuthor();
    string getTitle();
    string getISBN();
    int getQuantity();
    double getPrice();
    
	Book* getLeft(Book *tmp);
    Book* getLeft();
	Book* getRight(Book *tmp);
    Book* getRight();
    Book* getParent();
    
};

class Library {
	
    //Pointer for root book of tree
	Book* root;
    
public:
	//Default constructor
    Library();
    
    //Getters
    Book* returnroot();
    Book* findBook(double price, Book* aBook);
    Book* max(Book* book);
    Book* successor(double price, Book *book);
    Book* predecessor(double price, Book *book);
    
    
    //Member functions (setters)
    void addBook(string aAuthor, string aTitle, string aISBN, double aPrice, int aQuantity);
	void addNewBook(Book *tmp, string aAuthor, string aTitle, string aISBN, double aPrice, int aQuantity);
    void printBooks(Book *tmp);
    void printBargainBooks(Book *tmp, double aPrice);
    void SearchBooks_ISBN(Book *tmp, string aISBN);
    void SearchBooks_Title(Book *tmp, string aTitle);
    void SellBookbyISBN(Book *tmp, string aISBN);
    void SellBookbyTitle(Book *tmp, string aTitle);
    
    
};


#endif // TREE_H_INCLUDED
