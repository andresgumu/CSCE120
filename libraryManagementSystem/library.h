// provided. do not change. do not submit.
#ifndef PROVIDED_LIBRARY_H_
#define PROVIDED_LIBRARY_H_

#include <iostream>
#include <string>
#include <vector>
#include "book.h"
#include "member.h"

class Library { // uses default constructor
    std::vector<Book> books{};
    std::vector<Member> members{};

 public:
    void add_book(Book book); // adds a book to vector of books
    void register_member(Member member); // adds a member to the vector of members (needs to be unsorted, just add to end of vector)
    bool borrow_book(const std::string& isbn, int member_id, std::string& message); // attempts to lend a book from the library to a member (check doc)
    bool return_book(const std::string& isbn, std::string& message); // attempts to return a book to the library (check doc)
    void display_available_books(std::ostream& = std::cout); // lists books available in the library, one per line, using the overloaded operator for BOOK
    void display_library_members(std::ostream& = std::cout); // lists all the members, one per line, using the overloaded operator for MEMBER
    bool is_book_available(const std::string& isbn); // returns true if book available, otherwise returns false (if book unavailable or if ISBN invalid or no book with that ISBN)

    // for testing purposes only
    const std::vector<Book>& get_books() { return books; }
    const std::vector<Member>& get_members() { return members; }
};

#endif  // PROVIDED_LIBRARY_H_
