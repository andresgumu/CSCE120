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


bool Library::return_book(const std::string&, std::string&) {
   // TODO(student)
   return false;
}


void Library::display_available_books(std::ostream&) {
   // TODO(student)
   // use the ostream parameter, NOT std::cout
}


void Library::display_library_members(std::ostream&) {
   // TODO(student)
   // use the ostream parameter, NOT std::cout
}


bool Library::is_book_available(const std::string&) {
   // TODO(student)


   return true;
}
