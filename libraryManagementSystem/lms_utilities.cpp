#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "book.h"
#include "member.h"
#include "library.h"
#include "lms_utilities.h"

int read_list_of_books(Library& library, const std::string& filename) { // loads book data from txt file into a Library
   // TODO(student)
   std::ifstream iff(filename);

   // handle error if can't open file
   if (!iff.is_open()){
      throw std::runtime_error("Cannot open " + filename);
   }

   // initialize variables
   int booksAdded = 0;
   std:: string title, fullAuthor, isbn; // isbn needs to be store as an int

   // read until end of file
   while (std::getline(iff, title)){ 
      // check if file doesn't have enough info
      if (!std::getline(iff, fullAuthor)){ // reads one line from the file stream iff into the string variable fullAuthor
         break;
      }
      if (!std::getline(iff, isbn)){ // reads next line from the file stream iff into string variable isbn
         break;
      }
      // from the line read above, parse it into first and last names
      std:: istringstream iss(fullAuthor);
      std:: string first_name, last_name;
      iss >> first_name >> last_name;

      // try catch to catch exception that might be thrown by constructor
      try{
         // create and add book 
         Book book (title, first_name, last_name, isbn, true); // last parameter is bool available
         library.add_book(book);
         booksAdded++;

      } catch (const std::exception& e){ // best practice to make the exception a reference and constant
         // try code will not execute (book will be ignored), and it will move to the next input
      }
   }

   return booksAdded;
}

int read_list_of_members(Library&, const std::string&) { // loads member data from a txt file into a Library
   // TODO(student)

   
   return 0;
}

int read_list_of_borrowed_books(Library&, const std::string&) { // loads book borrowing data from a txt file into a Library
  // TODO(student)
  return 0;
}

int read_list_of_returned_books(Library&, const std::string&) { // loads book returning data from a txt file into a Library
   // TODO(student)
   return 0;
}
