#include <iostream>
using namespace std;

class Book {
    string title;
    string author;

public:
    void setDetails(string t, string a) {
        title = t;
        author = a;
    }

    void displayDetails() {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

int main() {
    Book b1, b2;

    b1.setDetails("The Great Gatsby", "F. Scott Fitzgerald");
    b1.displayDetails();

    cout << endl;

    b2.setDetails("1984", "George Orwell");
    b2.displayDetails();

    return 0;
}
