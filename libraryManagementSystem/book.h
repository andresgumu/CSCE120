// provided. do not change. do not submit.
#ifndef PROVIDED_BOOK_H_
#define PROVIDED_BOOK_H_

#include <iostream>
#include <string>

struct AuthorName {
    std::string first_name;
    std::string last_name;
};

class Book {
    std::string title;
    AuthorName author;
    std::string isbn;
    bool available;

 public:
    Book(std::string title, // paramterized constructor (no default)
         std::string author_first_name,
         std::string author_last_name,
         std::string isbn,
         bool available = true);
    Book(std::string title, // constructor (no default)
         AuthorName author,
         std::string isbn,
         bool available = true);
    std::string get_title() const; // access (getter)
    AuthorName get_author() const; // access (getter) 
    std::string get_isbn() const; // access (getter) 
    bool is_available() const; // access (getter) 
    bool borrow_book(); // access (setter)
    bool return_book(); // access (setter)
};

// prints this string: title: “TITLE” by AUTHOR, isbn: ISBN
// where TITLE is the book title, AUTHOR is the first and last name of the author, and ISBN is 
// the ISBN number of the book. No end-of-line after ISBN. TITLE must be surrounded by double quotes.
std::ostream& operator<<(std::ostream& os, const Book& book);

#endif  // PROVIDED_BOOK_H_
