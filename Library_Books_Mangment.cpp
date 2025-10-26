

#include <iostream>
#include <string>
using namespace std;

enum enStatusBook {Available=1,Borrowed=2};

struct stBook
{
    int BookID=0;
    string BookTitle;
    float BookPrice;
    string BookAuthor;
    enStatusBook BookStatus;
    stBook  *nextBook;
};

stBook* head=NULL;
stBook* tail = NULL;

void readStatusBook(stBook  &statusBook)
{
   
    string bookStatus;
    cout << "Does the Book available (Yes \\ No)\n";
    cin >> bookStatus;
    if (bookStatus == "Yes" || bookStatus == "yes")
    {
        statusBook.BookStatus = Available;
    }
    else
    {
        statusBook.BookStatus =Borrowed;
    }

}
//int globalBookID = 0;
stBook* readInfoBook(stBook*& newBook)
{
    // here we use static because every run the variable will take the last value the add 1
    // if you don't use static you should declare it outside the function 
    // because if you don't do that every run will create the variable from first
    static int globalBookID = 0;
     newBook = new stBook;
     newBook->BookID=++globalBookID;
     cout << "Enter Book's name\n";
     getline(cin, newBook->BookTitle);
     cout << "Enter Book's price\n";
     cin >> newBook->BookPrice;
     cout << "Enter Book's author\n";
     cin.ignore();
     getline(cin, newBook->BookAuthor);
     readStatusBook(*newBook);
     cin.ignore();
     return newBook;
   
}

void addBook(stBook* &newBook)
{
    readInfoBook(newBook);

    
    if (head == NULL)
    {
        head = newBook;
        tail = newBook;
        newBook->nextBook = NULL;
        cout << "✅ Book added as the first book.\n";
        return;
    }
    else
    {
        tail->nextBook = newBook;
        tail = newBook;
        newBook->nextBook = NULL;
        cout << "✅ Book added successfully.\n";

    }

}

void displayBooks()
{
    stBook* currentBook = head;
    if (head == NULL)
    {
        cout << "📚 No books in the library.\n";
        return;
    }
    cout << "\n====== Library Books ======\n";
    while (currentBook!=NULL)
    {
        cout << " | ID: " << currentBook->BookID << endl;
        cout << " | Title: " << currentBook->BookTitle << endl;
        cout << " | Author: " << currentBook->BookAuthor << endl;
        cout << " | Price: " << currentBook->BookPrice << " $ " << endl;
        cout << " | Status: The Book is" << (currentBook->BookStatus == Available ? " Available" : " Borrowed") << endl;
        currentBook = currentBook->nextBook;
        cout << endl;
    }
    cout << "===============================\n";
}

void searchBook(int ID)
{
    stBook* currentBook=head;
    if (head == NULL)
    {
        "The Library is empty\n";
        return;
    }
    while (currentBook!=NULL)
        
    {
        if (currentBook->BookID == ID)
        {
            cout << " | ID: " << currentBook->BookID << endl;
            cout << " | Title: " << currentBook->BookTitle << endl;
            cout << " | Author: " << currentBook->BookAuthor << endl;
            cout << " | Price: " << currentBook->BookPrice << " $ " << endl;
            cout << " | Status: The Book is" << (currentBook->BookStatus == Available ? " Available" : " Borrowed") << endl;
            currentBook = currentBook->nextBook;
            cout << endl;
            return;
        }
        currentBook->nextBook = currentBook;
        
    }
    cout << "The did not find\n";
   
    

}

void deleteBook(int ID)
{
    stBook *currentBook = head;
    stBook* preveBook = head;
    if (head == NULL)
    {
        cout << "The Library is empty\n";
        return;
    }
    while (currentBook!=NULL)
    {
        if (currentBook->BookID == ID)
        {
            preveBook->nextBook = currentBook->nextBook;
            delete currentBook;
            cout << "The Book deleted successfully\n";
            return;
        }
        preveBook = currentBook;
        currentBook = currentBook->nextBook;

    }
}

void rentBook(int ID)
{
    stBook *currentBook = head;
    while (currentBook != NULL)
    {
        if (currentBook->BookID == ID)
        {
            if (currentBook->BookStatus == Available)
            {
                cout << " The Book rent successfully\n\n";
                cout << " | ID: " << currentBook->BookID << endl;
                cout << " | Title: " << currentBook->BookTitle << endl;
                cout << " | Author: " << currentBook->BookAuthor << endl;
                cout << " | Price: " << currentBook->BookPrice << " $ " << endl;
                currentBook->BookStatus = Borrowed;
                return;
            }
            else
            {
                cout << "Sorry you can not rent this Book, try another Book\n";
                return;
            }
        }
        currentBook = currentBook->nextBook;
    }
    cout << "The Book is not found\n";

}

void returnBook(int ID)
{
    stBook* currentBook = head;
    while (currentBook != NULL)
    {
        if (currentBook->BookID == ID )
        {
            if(currentBook->BookStatus == Borrowed)
            {
                currentBook->BookStatus = Available;
                cout << "The Book returned successfully\n";
            return;
            }

            else
            {
                cout << "This book is not rented.\n";
                return;
            }
        }


        
        currentBook = currentBook->nextBook;
    }
    cout << "The Book is not found\n";
}

int main()
{
    stBook* book;
    addBook(book);
    addBook(book);
    addBook(book);
    searchBook(3);
   // displayBooks();
   /* deleteBook(2);
    displayBooks();
    
  
    rentBook(2);
    returnBook(2);
    rentBook(2);*/

}

