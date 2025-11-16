// TODO(student): Implement this header file

#ifndef _MY_STRING_H
#define _MY_STRING_H

#include <iostream>

// class definition for MyString
class MyString {

    private:
        char* m_data;
        size_t m_size;
        size_t m_capacity;
    public:
        static const size_t npos = -1; // member constant (publicly accessed)

        //----------Constructors-------------
        // default 
        MyString();
        // copy constructor
        MyString(const MyString& str);
        // from c-string
        MyString(const char* s);

        // Destructor
        ~MyString();

        // operator=
        MyString& operator=(const MyString& other);

        //----------Capacity----------------
        size_t size() const;
        size_t length() const;
        void resize(size_t n);
        size_t capacity() const;
        void clear();
        bool empty() const;

        //----------Element Access----------
        const char& at(size_t pos) const;
        const char& front() const;

        // Modifier
        MyString& operator+= (const MyString& other);


        //----------String Operations---------
        const char* data() const;
        size_t find(const MyString& str, size_t pos = 0) const;


};

//----------------non member function overloads----------------

std::ostream& operator<< (std::ostream& os, const MyString& str);



#endif