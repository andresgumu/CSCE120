#include "book.h"

Book::Book(std::string title,  // title                    class_name::member_name notation used since this is outside the class implementation
           std::string author_first_name,  // author_first_name
           std::string author_last_name,  // author_last_name
           std::string isbn,  // isbn
           bool available          // available
         ) :title{}, author{}, isbn{}, available{} { // member initializer list
   // TODO(student)
   // title cannot be empty and has to consist of letters, spaces, colons, and dashes
   std::string badChars = ".><?'_,1234567890;!@#$%^&*()[{}]\\|~`+=";
   if (title.empty()){
      throw std::invalid_argument("Invalid title");
   }
   if (title.find_first_of(badChars) != std::string::npos){ // checks if title contains one of those forbidden chars
      throw std::invalid_argument("Invalid title");
   }

   // author's name is not empty and consists of only letters
   if (author_first_name.empty() && author_last_name.empty()){
      throw std::invalid_argument("Invalid author");
   }

   // use for loop to iterate through string and check if chars are only letters
   for (char ch : author_first_name) {
      if (!std::isalpha(static_cast<unsigned char>(ch))) {
         throw std::invalid_argument("Invalid author");
      }
   }
   for (char ch : author_last_name) {
      if (!std::isalpha(static_cast<unsigned char>(ch))) {
         throw std::invalid_argument("Invalid author");
      }
   }

   // ISBN consists of 10 or 13 digits (saved as string)
   if (isbn.size() != 10 && isbn.size() != 13){
      throw std::invalid_argument("Invalid ISBN");
   }
   // check if saved as string, not digit
   for (char ch : isbn) {
      if (!std::isdigit(static_cast<unsigned char>(ch))) {
         throw std::invalid_argument("Invalid ISBN");
      }
   }


   // assign members if all tests passed
   this->title = title;
   this->author.first_name = author_first_name;
   this->author.last_name = author_last_name;
   this->isbn = isbn;
   this->available = available;

}

Book::Book(std::string title,  // title
           AuthorName author,   // author
           std::string isbn,  // isbn
           bool available        // available
         ) : title{}, author{}, isbn{}, available{} {
   // TODO(student)

   std::string badChars = ".><_?,'1234567890;!@#$%^&*()[{}]\\|~`+=";
   if (title.empty()){
      throw std::invalid_argument("Invalid title");
   }
   if (title.find_first_of(badChars) != std::string::npos){ // checks if title contains one of those forbidden chars
      throw std::invalid_argument("Invalid title");
   }

   // author's (AuthorName struct) name is not empty and consists of only letters
   if (author.first_name.empty() && author.last_name.empty()){
      throw std::invalid_argument("Invalid author");
   }

   // use for loop to iterate through string and check if chars are only letters
   for (char ch : author.first_name) {
      if (!std::isalpha(static_cast<unsigned char>(ch))) {
         throw std::invalid_argument("Invalid author");
      }
   }
   for (char ch : author.last_name) {
      if (!std::isalpha(static_cast<unsigned char>(ch))) {
         throw std::invalid_argument("Invalid author");
      }
   }

   // ISBN consists of 10 or 13 digits (saved as string)
   if (isbn.size() != 10 && isbn.size() != 13){
      throw std::invalid_argument("Invalid ISBN");
   }
   // check if saved as string, not digit
   for (char ch : isbn) {
      if (!std::isdigit(static_cast<unsigned char>(ch))) {
         throw std::invalid_argument("Invalid ISBN");
      }
   }

   this->title = title;
   this->author = author;
   this->isbn = isbn;
   this->available = available;

}

std::string Book::get_title() const {
   // TODO(student)
   return title;
}

AuthorName Book::get_author() const {
   // TODO(student)
   return author;
}

std::string Book::get_isbn() const {
   // TODO(student)
   return isbn;
}

bool Book::is_available() const {
   // TODO(student)
   return available;
}

bool Book::borrow_book() {
   // TODO(student)
   if (available){
      available = false; // since you are borrowing book
      return true;
   }
   return false; // if available is false return false
}

bool Book::return_book() {
   // TODO(student)
   if (!available){
      available = true;
      return true;
   }
   return false; // if book was already returned (available is already true)
}

std::ostream& operator<<(std::ostream& os, const Book& b) {
   // TODO(student)
   AuthorName authorN = b.get_author();
   os << "title: \"" << b.get_title() << "\" by " << authorN.first_name << " " << authorN.last_name << ", isbn: " << b.get_isbn();
   return os;
}
