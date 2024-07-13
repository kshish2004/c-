#include <iostream>
#include <vector>
#include <algorithm> // for std::find_if

// Book class
class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;

public:
    Book(const std::string& title, const std::string& author, const std::string& isbn, bool available = true)
        : title(title), author(author), isbn(isbn), available(available) {}

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    std::string getISBN() const {
        return isbn;
    }

    bool isAvailable() const {
        return available;
    }

    void setAvailable(bool available) {
        this->available = available;
    }
};

// Library class
class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    std::vector<Book> searchBooks(const std::string& keyword) {
        std::vector<Book> results;
        for (const auto& book : books) {
            if (book.getTitle().find(keyword) != std::string::npos ||
                book.getAuthor().find(keyword) != std::string::npos ||
                book.getISBN().find(keyword) != std::string::npos) {
                results.push_back(book);
            }
        }
        return results;
    }

    bool checkoutBook(const std::string& isbn) {
        auto it = std::find_if(books.begin(), books.end(), [&isbn](const Book& book) {
            return book.getISBN() == isbn && book.isAvailable();
        });

        if (it != books.end()) {
            it->setAvailable(false);
            return true;
        }

        return false;
    }

    bool returnBook(const std::string& isbn) {
        auto it = std::find_if(books.begin(), books.end(), [&isbn](const Book& book) {
            return book.getISBN() == isbn && !book.isAvailable();
        });

        if (it != books.end()) {
            it->setAvailable(true);
            return true;
        }

        return false;
    }
};

int main() {
    Library library;

    int choice;
    std::string keyword;
    std::vector<Book> searchResults;

    while (true) {
        std::cout << "\nLibrary Management System Menu\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Search Books\n";
        std::cout << "3. Checkout Book\n";
        std::cout << "4. Return Book\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                {
                    std::string title, author, isbn;
                    bool available;
                    std::cout << "Enter book title: ";
                    std::cin.ignore();
                    std::getline(std::cin, title);
                    std::cout << "Enter book author: ";
                    std::getline(std::cin, author);
                    std::cout << "Enter book ISBN: ";
                    std::getline(std::cin, isbn);
                    std::cout << "Is book available? (1 for yes, 0 for no): ";
                    std::cin >> available;

                    Book newBook(title, author, isbn, available);
                    library.addBook(newBook);
                    std::cout << "Book added successfully.\n";
                }
                break;
            case 2:
                {
                    std::cout << "Enter title, author, or ISBN to search: ";
                    std::cin.ignore();
                    std::getline(std::cin, keyword);
                    searchResults = library.searchBooks(keyword);
                    if (searchResults.empty()) {
                        std::cout << "No books found matching the search criteria.\n";
                    } else {
                        std::cout << "Search Results:\n";
                        for (const auto& book : searchResults) {
                            std::cout << "Title: " << book.getTitle() << "\n";
                            std::cout << "Author: " << book.getAuthor() << "\n";
                            std::cout << "ISBN: " << book.getISBN() << "\n";
                            std::cout << "Availability: " << (book.isAvailable() ? "Available" : "Not Available") << "\n";
                            std::cout << "---------------------------\n";
                        }
                    }
                }
                break;
            case 3:
                {
                    std::string isbn;
                    std::cout << "Enter ISBN of the book to checkout: ";
                    std::cin >> isbn;
                    if (library.checkoutBook(isbn)) {
                        std::cout << "Book checked out successfully.\n";
                    } else {
                        std::cout << "Failed to checkout book.\n";
                    }
                }
                break;
            case 4:
                {
                    std::string isbn;
                    std::cout << "Enter ISBN of the book to return: ";
                    std::cin >> isbn;
                    if (library.returnBook(isbn)) {
                        std::cout << "Book returned successfully.\n";
                    } else {
                        std::cout << "Failed to return book.\n";
                    }
                }
                break;
            case 5:
                std::cout << "Exiting program...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
                break;
        }
    }

    return 0;
}
