#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string DATA_FILE = "library_books.txt";

struct Book {
    string isbn;
    string title;
    string author;
    string category;
    bool isAvailable;
};

Book createBook(const string& isbn, const string& title, 
                const string& author, const string& category) {
    Book book;
    book.isbn = isbn;
    book.title = title;
    book.author = author;
    book.category = category;
    book.isAvailable = true;
    return book;
}

void saveBookToFile(const Book& book, ofstream& out) {
    out << book.isbn << ","
        << book.title << ","
        << book.author << ","
        << book.category << ","
        << (book.isAvailable ? "Available" : "Issued") << "\n";
}

bool loadBookFromLine(const string& line, Book& book) {
    string isbn, title, author, category, status;
    stringstream stream(line);

    if (!getline(stream, isbn, ',')) return false;
    if (!getline(stream, title, ',')) return false;
    if (!getline(stream, author, ',')) return false;
    if (!getline(stream, category, ',')) return false;
    if (!getline(stream, status)) return false;

    book.isbn = isbn;
    book.title = title;
    book.author = author;
    book.category = category;
    book.isAvailable = (status == "Available");

    return true;
}

void addBook(vector<Book>& library) {
    string isbn, title, author, category;

    cout << "\nEnter ISBN: ";
    cin >> isbn;

    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    cout << "Enter Category: ";
    getline(cin, category);

    Book newBook = createBook(isbn, title, author, category);
    library.push_back(newBook);

    ofstream outFile(DATA_FILE, ios::app);
    if (outFile) {
        saveBookToFile(newBook, outFile);
        outFile.close();
        cout << "\n Book added successfully!" << endl;
    } else {
        cout << "\n Failed to save to file." << endl;
    }
}

void loadLibrary(vector<Book>& library) {
    ifstream inFile(DATA_FILE);
    if (!inFile) return;

    string line;
    while (getline(inFile, line)) {
        Book book;
        if (loadBookFromLine(line, book)) {
            library.push_back(book);
        }
    }
    inFile.close();
}

int findBookByISBN(const vector<Book>& library, const string& isbn) {
    for (size_t i = 0; i < library.size(); ++i) {
        if (library[i].isbn == isbn) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void searchBooks(const vector<Book>& library) {
    if (library.empty()) {
        cout << "\nNo books in library." << endl;
        return;
    }

    string searchTerm;
    cout << "\nEnter search term (ISBN, title, or author): ";
    cin.ignore();
    getline(cin, searchTerm);

    int count = 0;
    cout << fixed << left;
    cout << setw(15) << "ISBN" 
         << setw(35) << "Title" 
         << setw(25) << "Author" 
         << setw(15) << "Category" 
         << setw(10) << "Status" << endl;
    cout << string(100, '-') << endl;

    for (const auto& book : library) {
        if (book.isbn.find(searchTerm) != string::npos ||
            book.title.find(searchTerm) != string::npos ||
            book.author.find(searchTerm) != string::npos) {
            cout << setw(15) << book.isbn
                 << setw(35) << book.title.substr(0, 34)
                 << setw(25) << book.author.substr(0, 24)
                 << setw(15) << book.category
                 << setw(10) << (book.isAvailable ? "Available" : "Issued") << endl;
            count++;
        }
    }

    if (count == 0) {
        cout << "\nNo books found matching '" << searchTerm << "'." << endl;
    } else {
        cout << "\nFound " << count << " book(s)." << endl;
    }
}

void issueBook(vector<Book>& library) {
    if (library.empty()) {
        cout << "\nNo books available in library." << endl;
        return;
    }

    string isbn;
    cout << "\nEnter ISBN of book to issue: ";
    cin >> isbn;

    int index = findBookByISBN(library, isbn);
    if (index == -1) {
        cout << "\n Book with ISBN '" << isbn << "' not found." << endl;
        return;
    }

    if (!library[index].isAvailable) {
        cout << "\n Book is already issued." << endl;
        return;
    }

    library[index].isAvailable = false;

    ofstream outFile(DATA_FILE, ios::trunc);
    for (const auto& book : library) {
        saveBookToFile(book, outFile);
    }
    outFile.close();

    cout << "\n Book '" << library[index].title << "' issued successfully." << endl;
}

void returnBook(vector<Book>& library) {
    if (library.empty()) {
        cout << "\nNo books to return." << endl;
        return;
    }

    string isbn;
    cout << "\nEnter ISBN of book to return: ";
    cin >> isbn;

    int index = findBookByISBN(library, isbn);
    if (index == -1) {
        cout << "\n✗ Book with ISBN '" << isbn << "' not found." << endl;
        return;
    }

    if (library[index].isAvailable) {
        cout << "\n Book was not issued yet." << endl;
        return;
    }

    library[index].isAvailable = true;

    ofstream outFile(DATA_FILE, ios::trunc);
    for (const auto& book : library) {
        saveBookToFile(book, outFile);
    }
    outFile.close();

    cout << "\n Book '" << library[index].title << "' returned successfully." << endl;
}

void updateBook(vector<Book>& library) {
    if (library.empty()) {
        cout << "\nNo books to update." << endl;
        return;
    }

    string isbn;
    cout << "\nEnter ISBN of book to update: ";
    cin >> isbn;

    int index = findBookByISBN(library, isbn);
    if (index == -1) {
        cout << "\n✗ Book with ISBN '" << isbn << "' not found." << endl;
        return;
    }

    cout << "\nCurrent details:" << endl;
    cout << "Title: " << library[index].title << endl;
    cout << "Author: " << library[index].author << endl;
    cout << "Category: " << library[index].category << endl;

    cout << "\nEnter new Title (or press Enter to skip): ";
    cin.ignore();
    string newTitle;
    getline(cin, newTitle);
    if (!newTitle.empty()) library[index].title = newTitle;

    cout << "Enter new Author (or press Enter to skip): ";
    getline(cin, newTitle);
    if (!newTitle.empty()) library[index].author = newTitle;

    cout << "Enter new Category (or press Enter to skip): ";
    getline(cin, newTitle);
    if (!newTitle.empty()) library[index].category = newTitle;

    ofstream outFile(DATA_FILE, ios::trunc);
    for (const auto& book : library) {
        saveBookToFile(book, outFile);
    }
    outFile.close();

    cout << "\n Book updated successfully." << endl;
}

void generateReport(const vector<Book>& library) {
    if (library.empty()) {
        cout << "\nNo books in library." << endl;
        return;
    }

    int availableCount = 0;
    int issuedCount = 0;

    cout << fixed << left << "\n=== LIBRARY BOOK AVAILABILITY REPORT ===\n" << endl;
    cout << setw(15) << "ISBN" 
         << setw(35) << "Title" 
         << setw(25) << "Author" 
         << setw(15) << "Category" 
         << setw(10) << "Status" << endl;
    cout << string(100, '=') << endl;

    for (const auto& book : library) {
        if (book.isAvailable) availableCount++;
        else issuedCount++;

        cout << setw(15) << book.isbn
             << setw(35) << book.title.substr(0, 34)
             << setw(25) << book.author.substr(0, 24)
             << setw(15) << book.category
             << setw(10) << (book.isAvailable ? "Available" : "Issued") << endl;
    }

    cout << string(100, '=') << endl;
    cout << "Total Books: " << library.size() 
         << " | Available: " << availableCount 
         << " | Issued: " << issuedCount << endl;
}

void displayMenu() {
    cout << "\n========================================" << endl;
    cout << "   LIBRARY BOOK MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << "1. Add New Book" << endl;
    cout << "2. Search Books" << endl;
    cout << "3. Issue Book" << endl;
    cout << "4. Return Book" << endl;
    cout << "5. Update Book Details" << endl;
    cout << "6. Generate Availability Report" << endl;
    cout << "7. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    vector<Book> library;
    loadLibrary(library);

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                searchBooks(library);
                break;
            case 3:
                issueBook(library);
                break;
            case 4:
                returnBook(library);
                break;
            case 5:
                updateBook(library);
                break;
            case 6:
                generateReport(library);
                break;
            case 7:
                cout << "\nExiting system. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid option! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}