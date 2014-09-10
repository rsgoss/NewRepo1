#include <iostream>
#include "tree.h"
#include <string>
using namespace std;

//---------------------------
// Book Class Functions Below
//---------------------------

//Constuctors below (default and explicit)
Book::Book() {
    left = 0;
    right = 0;
    parent = 0;
}

Book::Book(string aAuthor, string aTitle, string aISBN, double aPrice, int aQuantity) {
    author = aAuthor;
    title = aTitle;
    ISBN = aISBN;
    price = aPrice;
    quantity = aQuantity;
    
    left = 0;
    right = 0;
    parent = 0;
}


//Setter functions below
void Book::setAuthor(string aAuthor) {
    author = aAuthor;
}

void Book::setTitle(string aTitle) {
    title = aTitle;
}

void Book::setISBN(string aISBN) {
    ISBN = aISBN;
}

void Book::setQuantity(int number) {
    quantity = number;
}

void Book::setPrice(double aPrice) {
    price = aPrice;
}

void Book::setLeft(Book *aLeft) {
    left = aLeft;
}

void Book::setRight(Book *aRight) {
    right = aRight;
}

void Book::setParent(Book *aParent) {
    parent = aParent;
}


//Getter functions below (Get key, left and right)
string Book::getAuthor() {
    return author;
}

string Book::getTitle() {
    return title;
}

string Book::getISBN() {
    return ISBN;
}

int Book::getQuantity() {
    return quantity;
}

double Book::getPrice() {
    return price;
}

//Overloaded getLeft and getRight functions below to allow getLeft and getRight to return a null value. Important for non-recursive function.
Book* Book::getLeft(Book *tmp) {
    if (left == NULL) {
        tmp = NULL;
        return tmp;
    }
    else {
        return left;
    }
}

Book* Book::getLeft() {
    return left;
}

Book* Book::getRight(Book *tmp){
    if (right == NULL) {
        tmp = NULL;
        return tmp;
    }
    else {
        return right;
    }
}

Book* Book::getRight() {
    return right;
}

Book* Book::getParent(){
    return parent;
}


//---------------------------
// Library Class Functions Below
//---------------------------


//Default constructor function below
Library::Library() {
    root = NULL;
}

//A single getter function to get the root Book
Book* Library::returnroot() {
    return root;
}

/*
 *The following two functions addBook and addNewBook first check if Library is empty (if it is, it adds the Book with
 *the new value), then recursively calls the next function or itself to find the end of the binary search Library
 *by checking values if they are greater than or less than the inputted value. Once it
 *reaches the end, it adds the new Book to the appropriate side of the Library.
*/
void Library::addBook(string aAuthor, string aTitle, string aISBN, double aPrice, int aQuantity) {
    
    if (root == NULL) {
        cout << "Empty" << endl;
        Book* myBook = new Book;
        root = myBook;
        
        myBook->setAuthor(aAuthor);
        myBook->setTitle(aTitle);
        myBook->setISBN(aISBN);
        myBook->setQuantity(aQuantity);
        myBook->setPrice(aPrice);
         
        myBook->setLeft(0);
        myBook->setRight(0);
        myBook->setParent(0);
        
        cout << "new root! " << root->getPrice() << endl;
    }
    else {
        cout << "Add other book" << endl;
        addNewBook(root, aAuthor, aTitle, aISBN, aPrice, aQuantity);
        }
    
}

//Recursive function for adding a book, initiated by the function above
void Library::addNewBook(Book *tmp, string aAuthor, string aTitle, string aISBN, double aPrice, int aQuantity) {
    
  
    if (aPrice > tmp->getPrice() && tmp->getRight() != 0) {
        cout << "Getting right!" << "Because " << aPrice << " is more than " << tmp->getPrice() << endl;
        Book* new_tmp = tmp->getRight();
        addNewBook(new_tmp, aAuthor, aTitle, aISBN, aPrice, aQuantity);
    }
    else if (aPrice <= tmp->getPrice() && tmp->getLeft() != 0) {
        cout << "Getting left!" << " Because " << aPrice << " is less than " << tmp->getPrice() << endl;
        Book* new_tmp = tmp->getLeft();
        addNewBook(new_tmp, aAuthor, aTitle, aISBN, aPrice, aQuantity);
    }
    else if (aPrice > tmp->getPrice() && tmp->getRight() == 0) {
        cout << "At the end! (right)" << " Because " << aPrice << " is more than " << tmp->getPrice() << endl;
        Book* myBook = new Book;
        myBook->setAuthor(aAuthor);
        myBook->setTitle(aTitle);
        myBook->setISBN(aISBN);
        myBook->setQuantity(aQuantity);
        myBook->setPrice(aPrice);
        tmp->setRight(myBook);
        myBook->setParent(tmp);
    }
    else if (aPrice <= tmp->getPrice() && tmp->getLeft() == 0) {
        cout << "At the end! (left)" << " Because " << aPrice << " is less than " << tmp->getPrice() << endl;
        Book* myBook = new Book;
        myBook->setAuthor(aAuthor);
        myBook->setTitle(aTitle);
        myBook->setISBN(aISBN);
        myBook->setQuantity(aQuantity);
        myBook->setPrice(aPrice);
        tmp->setLeft(myBook);
        myBook->setParent(tmp);
    }
}

//This function uses recursion to keep checking an if statement for a matching ISBN number inputted by the user.
//If it matches, it outputs the book information. Otherwise, it keeps calling itself to traverse the tree to find it.
void Library::SearchBooks_ISBN(Book *tmp, string aISBN) {
    
    //If there are no Books
    if (root == NULL) {
        cout << "Library is empty." << endl;
    }
    else if (tmp == NULL) {
        
    }
    //If there is only one Book (i.e., the root)
    else if (tmp->getLeft() == 0 && tmp->getRight() == 0) {
        if (tmp->getISBN() == aISBN) {
            cout << "Found your book. Here is all of the information:" << endl;
            cout << tmp->getTitle() << " by " << tmp->getAuthor() << endl;
            cout << "Price: $" << tmp->getPrice() << endl;
            cout << "Quantity in stock: " << tmp->getQuantity() << endl;
            cout << "ISBN: " << tmp->getISBN() << endl;
        }
    }
    //Recursive function runs through and counts all Books
    else {
        if (tmp->getISBN() == aISBN) {
            cout << "Found your book. Here is all of the information:" << endl;
            cout << tmp->getTitle() << " by " << tmp->getAuthor() << endl;
            cout << "Price: $" << tmp->getPrice() << endl;
            cout << "Quantity in stock: " << tmp->getQuantity() << endl;
            cout << "ISBN: " << tmp->getISBN() << endl;
        }
        SearchBooks_ISBN(tmp->getRight(), aISBN);
        SearchBooks_ISBN(tmp->getLeft(), aISBN);
    }
}

//This function uses recursion to keep checking an if statement for a matching title inputted by the user.
//If it matches, it outputs the book information. Otherwise, it keeps calling itself to traverse the tree to find it.
void Library::SearchBooks_Title(Book *tmp, string aTitle) {
    
    
    //If there are no Books
    if (root == NULL) {
        cout << "Library is empty." << endl;
    }
    else if (tmp == NULL) {
        
    }
    //If there is only one Book (i.e., the root)
    else if (tmp->getLeft() == 0 && tmp->getRight() == 0) {
        if (tmp->getTitle() == aTitle) {
            cout << "Found your book. Here is all of the information:" << endl;
            cout << tmp->getTitle() << " by " << tmp->getAuthor() << endl;
            cout << "Price: $" << tmp->getPrice() << endl;
            cout << "Quantity in stock: " << tmp->getQuantity() << endl;
            cout << "ISBN: " << tmp->getISBN() << endl;
        }
        
    }
    //Recursive function runs through and counts all Books
    else {
        if (tmp->getTitle() == aTitle) {
            cout << "Found your book. Here is all of the information:" << endl;
            cout << tmp->getTitle() << " by " << tmp->getAuthor() << endl;
            cout << "Price: $" << tmp->getPrice() << endl;
            cout << "Quantity in stock: " << tmp->getQuantity() << endl;
            cout << "ISBN: " << tmp->getISBN() << endl;
        }
        SearchBooks_Title(tmp->getRight(), aTitle);
        SearchBooks_Title(tmp->getLeft(), aTitle);
    }
}

//This is the non-recursive function which is useful to traverse the tree of books creating a stack.
//As it comes back, it removes books from the stack in order of the sorted parameter (price) and outputs to the user.
//This produces a sorted output by price.
void Library::printBooks(Book *tmp) {

    cout << "SORTED BY PRICE LOW TO HIGH" << endl;
    //If there are no Books
    if (root == NULL) {
        cout << "There are no books in the library." << endl;
    }
    
    //If there is only one Book
    else if (tmp->getLeft() == 0 && tmp->getRight() == 0) {
        cout << "$" << tmp->getPrice() << " " << tmp->getTitle() << " by " << tmp->getAuthor() << endl;
    }
    
    else {
        Book *stack[200];
        int L = 0;
        Book *current = tmp;
        bool done = false;
        
        while (done == false) {
            
            if (current != NULL) {
                stack[L] = current;
                L++;
                current = current->getLeft(current);
            }
            
            else {
                if (L != 0 && current == NULL) {
                    L--;
                    current = stack[L];
                    cout << "$" << current->getPrice() << " " << current->getTitle() << " by " << current->getAuthor() << endl;
                    current = current->getRight(current);
                }
                else {
                    done = true;
                }
                
            }
        }
    }

    
}

//This function is much the the one above.
//It is non-recursive to traverse the tree of books creating a stack.
//As it comes back, it removes books from the stack in order of the sorted parameter (price) and outputs to the user.
//This produces a sorted output by price but cuts off at the max price the user is willing to pay.
void Library::printBargainBooks(Book *tmp, double aPrice) {
    
    cout << "SORTED BY PRICE LOW TO HIGH" << endl;
    //If there are no Books
    if (root == NULL) {
        cout << "There are no books in the library." << endl;
    }
    
    //If there is only one Book
    else if (tmp->getLeft() == 0 && tmp->getRight() == 0) {
        cout << "$" << tmp->getPrice() << " " << tmp->getTitle() << " by " << tmp->getAuthor() << endl;
    }
    
    else {
        Book *stack[200];
        int L = 0;
        Book *current = tmp;
        bool done = false;
        
        while (done == false) {
            
            if (current != NULL) {
                stack[L] = current;
                L++;
                current = current->getLeft(current);
            }
            
            else {
                if (L != 0 && current == NULL) {
                    L--;
                    current = stack[L];
                    if (current->getPrice() <= aPrice) {
                    cout << "$" << current->getPrice() << " " << current->getTitle() << " by " << current->getAuthor() << endl;
                    }
                    current = current->getRight(current);
                }
                else {
                    done = true;
                }
                
            }
        }
    }
    
    
}


//The following function uses a non-recursive method to traverse the tree, adding books into a stack array.
//As it comes back, it pops books from the stack and checks if they are the book to be sold. If they are, the quantity
//parameter is subtracted by 1. If there is only one left, the function removes the book from the binary search tree
//by rearranging it appropriately. 
void Library::SellBookbyISBN(Book *tmp, string aISBN) {
    
    //If there are no Books
    if (root == NULL) {
        cout << "There are no books in the library." << endl;
    }
    
    //If there is only one Book
    else if (tmp->getLeft() == 0 && tmp->getRight() == 0) {
        cout << "Only one book in the library." << endl;
        cout << "$" << tmp->getPrice() << " " << tmp->getTitle() << " by " << tmp->getAuthor() << endl;
    }
    
    else {
        Book *stack[200];
        int L = 0;
        Book *current = tmp;
        bool done = false;
        
        while (done == false) {
            
            if (current != NULL) {
                stack[L] = current;
                L++;
                current = current->getLeft(current);
            }
            
            else {
                if (L != 0 && current == NULL) {
                    L--;
                    current = stack[L];
                    if (current->getISBN() == aISBN) {
                        if (current->getQuantity() == 1) {
                            Book* parent = stack[L-1];
                            cout << "Oh, looks like you are selling the last one. Removing from tree." << endl;
                            if (current->getLeft() == NULL && current->getRight() == NULL) {
                                if (current->getPrice() > parent->getPrice()) {
                                    parent->setRight(NULL);
                                }
                                else {
                                    parent->setLeft(NULL);
                                }
                            }
                            else if (current->getLeft() != NULL && current->getRight() == NULL) {
                                if (current->getPrice() > parent->getPrice()) {
                                    parent->setRight(current->getLeft());
                                }
                                else {
                                    parent->setLeft(current->getRight());
                                }
                            }
                            else if (current->getLeft() == NULL && current->getRight() != NULL) {
                                if (current->getPrice() > parent->getPrice()) {
                                    parent->setRight(current->getRight());
                                }
                                else {
                                    parent->setLeft(current->getLeft());
                                }
                            }
                            else if (current->getLeft() != NULL && current->getRight() != NULL) {
                                Book* prev = predecessor(current->getPrice(), current);
                                if (prev == NULL) {
                                    prev = successor(current->getPrice(), current);
                                }
                                if (prev->getPrice() > prev->getParent()->getPrice()) {
                                    prev->getParent()->setRight(prev->getRight());
                                }
                                else if (prev->getPrice() <= prev->getParent()->getPrice()) {
                                    prev->getParent()->setLeft(prev->getRight());
                                }
                                current->setPrice(prev->getPrice());
                                delete prev;
                            }
                        }
                        else {
                        int new_quant = current->getQuantity()-1;
                        current->setQuantity(new_quant);
                        cout << "$" << current->getPrice() << " " << current->getTitle() << " by " << current->getAuthor() << endl;
                        cout << "New quantity: " << current->getQuantity() << endl;
                        }
                    }
                    current = current->getRight(current);
                }
                else {
                    done = true;
                }
                
            }
        }
    }
    
    
}


//See comment for function above. This function is essentially identical, simply takes a title instead of ISBN.
void Library::SellBookbyTitle(Book *tmp, string aTitle) {
    
    //If there are no Books
    if (root == NULL) {
        cout << "There are no books in the library." << endl;
    }
    
    //If there is only one Book
    else if (tmp->getLeft() == 0 && tmp->getRight() == 0) {
        cout << "Only one book in the library." << endl;
        cout << "$" << tmp->getPrice() << " " << tmp->getTitle() << " by " << tmp->getAuthor() << endl;
    }
    
    else {
        Book *stack[200];
        int L = 0;
        Book *current = tmp;
        bool done = false;
        
        while (done == false) {
            
            if (current != NULL) {
                stack[L] = current;
                L++;
                current = current->getLeft(current);
            }
            
            else {
                if (L != 0 && current == NULL) {
                    L--;
                    current = stack[L];
                    if (current->getTitle() == aTitle) {
                        if (current->getQuantity() == 1) {
                            Book* parent = stack[L-1];
                            cout << "Oh, looks like you are selling the last one. Removing from tree" << endl;
                            if (current->getLeft() == NULL && current->getRight() == NULL) {
                                if (current->getPrice() > parent->getPrice()) {
                                    parent->setRight(NULL);
                                }
                                else {
                                    parent->setLeft(NULL);
                                }
                            }
                            else if (current->getLeft() != NULL && current->getRight() == NULL) {
                                if (current->getPrice() > parent->getPrice()) {
                                    parent->setRight(current->getLeft());
                                }
                                else {
                                    parent->setLeft(current->getRight());
                                }
                            }
                            else if (current->getLeft() == NULL && current->getRight() != NULL) {
                                if (current->getPrice() > parent->getPrice()) {
                                    parent->setRight(current->getRight());
                                }
                                else {
                                    parent->setLeft(current->getLeft());
                                }
                            }
                            else if (current->getLeft() != NULL && current->getRight() != NULL) {
                                Book* prev = predecessor(current->getPrice(), current);
                                if (prev == NULL) {
                                    prev = successor(current->getPrice(), current);
                                }
                                if (prev->getPrice() > prev->getParent()->getPrice()) {
                                    prev->getParent()->setRight(prev->getRight());
                                }
                                else if (prev->getPrice() <= prev->getParent()->getPrice()) {
                                    prev->getParent()->setLeft(prev->getRight());
                                }
                                current->setPrice(prev->getPrice());
                                delete prev;
                            }
                        }
                        else {
                            int new_quant = current->getQuantity()-1;
                            current->setQuantity(new_quant);
                            cout << "$" << current->getPrice() << " " << current->getTitle() << " by " << current->getAuthor() << endl;
                            cout << "New quantity: " << current->getQuantity() << endl;
                        }
                    }
                    current = current->getRight(current);
                }
                else {
                    done = true;
                }
                
            }
        }
    }
    
    
}

//This function recursively searches tree for a book with a matching price as inputted. Needed for sell book function.
Book* Library::findBook(double price, Book* aBook) {
    if ( aBook == NULL ) {
        return NULL;
    }
    else if ( aBook->getPrice() == price ) {
        return aBook;
    }
    else if ( price <= aBook->getPrice() ) {
        findBook(price, aBook->getLeft());
    }
    else if ( price > aBook->getPrice() ) {
        findBook(price, aBook->getRight());
    }
    else {
        return NULL;
    }
    return 0;
}

//Traverses the right side of the tree recursively for max value
Book* Library::max(Book* book) {
    if ( book == NULL ) {
        return NULL;
    }
    else if ( book->getRight(book) ) {
        max(book->getRight());
    }
    else {
        return book;
    }
    return 0;
}

// Finds successor to a book
// Finds the book, gets the book with max value for the right sub-tree
Book* Library::successor(double price, Book *book) {
    Book* tmp = findBook(price, book);
    if ( tmp ) {
        return max(tmp->getRight(tmp));
    }
    return 0;
}

// Finds predecessor to a book
// Finds the book, gets the book with max value for the left sub-tree
Book* Library::predecessor(double price, Book *book)
{
    Book* tmp = findBook(price, book);
    if ( tmp ) {
        return max(tmp->getLeft(tmp));
    }
    return 0;
}

