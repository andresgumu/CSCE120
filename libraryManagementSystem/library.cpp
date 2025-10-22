#include <iostream>
#include <sstream>
#include "library.h"
#include "lms_utilities.h"

void Library::add_book(Book book) {
   // TODO(student)

   // vector of books should be unsorted
   // add each new book to the end of the vector
   books.push_back(book);

}


void Library::register_member(Member member) {
   // TODO(student)

   // vector of members should be unsorted
   // add each new member to the end of the vector
   members.push_back(member);
}


bool Library::borrow_book(const std::string& isbn, int member_id, std::string& message) {
   // TODO(student)

   // for loop to check if isbn in the catalog
   size_t bookLocation = books.size();
   for (size_t i = 0; i < books.size(); i++){
      if (isbn == books[i].get_isbn()){
         bookLocation = i; // store book location with matching isbn (parameter)
         break;
      }
   }
   // handle error if book ISBN not in catalog
   if (bookLocation == books.size()){ 
      std::ostringstream oss;
      oss << "Book ISBN: " << isbn << " not available";
      message = oss.str(); // store error message into message
      return false;
   }
   // handle error if book is unavailable
   if (!books[bookLocation].is_available()){ 
      std::ostringstream oss;
      oss << "Book ISBN: " << isbn << " not available";
      message = oss.str(); // store error message into message
      return false;
   }

   // check if member ID registered (handle error if not)
   size_t memberLocation = members.size();
   for (size_t j = 0; j < members.size(); j++){
      if (member_id == members[j].get_id()){
         memberLocation = j; // store member location with matching member_id (parameter)
         break;
      }
   }
   if (memberLocation == members.size()){ // if id is not registered, execute the code block
      std::ostringstream oss;
      oss << "Member " << member_id << " not found";
      message = oss.str();
      return false;
   }
   
   // if above conditions are satisfied, change status of book and update message
   books[bookLocation].borrow_book();
   std::ostringstream oss;
   oss << members[memberLocation] << " borrowed " << books[bookLocation];
   message = oss.str();
   return true;
}


bool Library::return_book(const std::string& isbn, std::string& message) {
   // TODO(student)

   // check if book is unavailable and if ISBN is in library catalog
   // find location of book
   size_t bookLocation = books.size(); // same logic as borrow_book section
   for (size_t i = 0; i < books.size(); i++){
      if (isbn == books[i].get_isbn()){
         bookLocation = i; // store book location with matching isbn (parameter)
         break;
      }
   }
   if (bookLocation == books.size()){ // if bookLocation didn't get reassigned a value (didn't find it)
      std::stringstream oss;
      oss << "Book ISBN: " << isbn << " not found";
      message = oss.str();
      return false;
   }
   if (books[bookLocation].is_available()){ // throw error if book is available
      std::stringstream oss;
      oss << "Book ISBN: " << isbn << " still available (cannot be returned)";
      message = oss.str();
      return false;
   }
   // return book if conditions pass
   books[bookLocation].return_book();
   std::stringstream oss;
   oss << "Book \"" << books[bookLocation].get_title() << "\"" << " returned";
   message = oss.str();

   return true;
}


void Library::display_available_books(std::ostream& os) {
   // TODO(student)
   // use the ostream parameter, NOT std::cout
   for (const auto& b: books){ // reference so that less memory is used
      if (b.is_available()){
         os << b << "\n";
      }
   }
}


void Library::display_library_members(std::ostream& os) {
   // TODO(student)
   // use the ostream parameter, NOT std::cout
   for (const auto& m: members){ // reference so that less memory is used
      os << m << "\n";
   }
}


bool Library::is_book_available(const std::string& isbn) {
   // TODO(student)
   size_t bookLocation = books.size();
   for (size_t i = 0; i < books.size(); i++){
      if (isbn == books[i].get_isbn()){
         bookLocation = i; // store book location with matching isbn (parameter)
         break;
      }
   }
   // check if book isnt found
   if (bookLocation == books.size()){
      return false;
   }
   // else return true if available, false if not
   return books[bookLocation].is_available();
}
