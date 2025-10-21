#include "member.h"

Member::Member(std::string firstName,  // firstName
               std::string last_name,  // last_name
               int id          // id
            ) : name{}, id{} {
    // TODO(student)

    // member's name is not empty and consists of only letters
    
    // member's ID is an integer greater than or equal to 1000
}

Member::Member(MemberName name,  // name
               int id          // id
               ) : name{}, id{} {
    // TODO(student)
}

MemberName Member::get_name() const {
    // TODO(student)
    return {};
}

int Member::get_id() const {
    // TODO(student)
    return 0;
}

std::ostream& operator<<(std::ostream& os, const Member&) {
   // TODO(student)
   return os;
}
