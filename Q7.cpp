#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Book {
    int book_id;
    string author_name;
    double price;
    int no_of_pages;
    string publisher;
    int year_of_publishing;
};

void swap(Book &a, Book &b) {
    Book temp = a;
    a = b;
    b = temp;
}

void sortBooks(Book books[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (books[j].author_name > books[j + 1].author_name) {
                swap(books[j], books[j + 1]);
            }
        }
    }
}

void printBooks(Book books[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Book ID: " << books[i].book_id << endl;
        cout << "Author Name: " << books[i].author_name << endl;
        cout << "Price: " << books[i].price << endl;
        cout << "No. of Pages: " << books[i].no_of_pages << endl;
        cout << "Publisher: " << books[i].publisher << endl;
        cout << "Year of Publishing: " << books[i].year_of_publishing << endl;
    }
}

int main() {
    ifstream file("books.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int n;
    file >> n;

    Book books[n];

    for (int i = 0; i < n; i++) {
        file >> books[i].book_id;
        file >> books[i].author_name;
        file >> books[i].price;
        file >> books[i].no_of_pages;
        file >> books[i].publisher;
        file >> books[i].year_of_publishing;
    }

    file.close();

    sortBooks(books, n);

    cout << "Sorted Books:" << endl;
    printBooks(books, n);

    return 0;
}
