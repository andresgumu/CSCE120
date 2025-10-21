// provided. do not change. do not submit.
#ifndef PROVIDED_MEMBER_H_
#define PROVIDED_MEMBER_H_

#include <iostream>
#include <string>

struct MemberName {
    std::string first_name;
    std::string last_name;
};

class Member {
    MemberName name;
    int id;

 public:
       Member(std::string first_name, std::string last_name, int id); // paramtrized constructor
       Member(MemberName name, int id); // paramtrized constructor
       MemberName get_name() const; // access (getter)
       int get_id() const; // access (getter)
};

// prints this string: "Member: NAME, id: ID"
// where NAME is the first and last name of the member (separated by a space) and ID is an 
// assigned ID. No end of line after ID.
std::ostream& operator<<(std::ostream& os, const Member& member);

#endif  // PROVIDED_MEMBER_H_
