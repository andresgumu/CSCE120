#include "member.h"

Member::Member(std::string firstName,  // firstName
               std::string last_name,  // last_name
               int id          // id
            ) : name{}, id{} {
    // TODO(student)

    // member's name is not empty and consists of only letters
    if (firstName.empty() && last_name.empty()){
        throw std::invalid_argument("Invalid name");
    }
    for (char ch : firstName) {
      if (!std::isalpha(static_cast<unsigned char>(ch))) {
         throw std::invalid_argument("Invalid name");
      }
    }
    for (char ch : last_name) {
      if (!std::isalpha(static_cast<unsigned char>(ch))) {
         throw std::invalid_argument("Invalid name");
      }
    }
    
    // member's ID is an integer greater than or equal to 1000
    if (id < 1000){
        throw std::invalid_argument("Invalid id");
    }

    // if everything passes, assign member values
    this->name.first_name = firstName; // name is getting passed (which is a struct)
    this->name.last_name = last_name;
    this->id = id;
}

Member::Member(MemberName name,  // name
               int id          // id
               ) : name{}, id{} {
    // TODO(student)
    if (name.first_name.empty() && name.last_name.empty()){
        throw std::invalid_argument("Invalid name");
    }
    for (char ch : name.first_name) {
      if (!std::isalpha(static_cast<unsigned char>(ch))) {
         throw std::invalid_argument("Invalid name");
      }
    }
    for (char ch : name.last_name) {
      if (!std::isalpha(static_cast<unsigned char>(ch))) {
         throw std::invalid_argument("Invalid name");
      }
    }
    
    // member's ID is an integer greater than or equal to 1000
    if (id < 1000){
        throw std::invalid_argument("Invalid id");
    }

    // if everything passes, assign member values
    this->name = name;
    this->id = id;
}

MemberName Member::get_name() const {
    // TODO(student)
    return name;
}

int Member::get_id() const {
    // TODO(student)
    return id;
}

std::ostream& operator<<(std::ostream& os, const Member& m) {
   // TODO(student)
   MemberName n = m.get_name();
   os << "Member: " << n.first_name << " " << n.last_name << ", id: " << m.get_id();
   return os;
}
