#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Book {
    string id;
    string author;
    float price;
    int pages;
    string publisher;
    int year;
};

void readBooks(Book books[], int& count) {
    ifstream file("input.txt");
    count = 0;
    while (file >> books[count].id >> books[count].author >> books[count].price >> books[count].pages >> books[count].publisher >> books[count].year) {
        count++;
    }
    file.close();
}

void sortBooks(Book books[], int count) {
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (books[i].author > books[j].author) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

void writeBooks(Book books[], int count) {
    ofstream file("output.txt");
    for (int i = 0; i < count; i++) {
        file << books[i].id << " " << books[i].author << " " << books[i].price << " " << books[i].pages << " " << books[i].publisher << " " << books[i].year << endl;
    }
    file.close();
}

int main() {
    Book books[100];
    int count = 0;

    readBooks(books, count);
    sortBooks(books, count);
    writeBooks(books, count);

    return 0;
}
