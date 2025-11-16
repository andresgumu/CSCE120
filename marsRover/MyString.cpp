// TODO(student): Implement this source file
#include "MyString.h"
#include <iostream>
#include <stdexcept>

//---------------default constructor-----------------------
MyString::MyString() : m_data(nullptr),m_size(0), m_capacity(1) {
    m_data = new char[1]; // allocate memory for null terminator
    m_data[0] = '\0';
};


//-------------copy constructor-----------------
MyString::MyString(const MyString& str) : m_data(nullptr), m_size(str.m_size), m_capacity(str.m_capacity) {
    // allocate memory on the heap
    m_data = new char[m_capacity];

    // copy the characters into the allocated memory object
    for (size_t i = 0; i < m_size; i++){
        m_data[i] = str.m_data[i];
    }

    // add the null terminator
    m_data[m_size] = '\0';

};


//----------------from c-string----------------------
MyString::MyString(const char* s) : m_data(nullptr), m_size(0), m_capacity(0){
    // find length of s
    size_t len = 0;
    while (s[len] != '\0'){
        len++;
    }

    m_size = len;
    m_capacity = len + 1; // extra space for the null terminator

    m_data = new char[m_capacity];

    // copy the chars
    for (size_t i = 0; i < m_size; i++){
        m_data[i] = s[i];
    }

    // add null terminator
    m_data[m_size] = '\0';
};


//---------------destructor-------------------------
MyString::~MyString() {
    delete[] m_data; // braces ensure you are deleting the whole c string (array), frees memory on the heap
};


//-------------------operator= ----------------------
MyString& MyString::operator=(const MyString& other) {

    if (this == &other){ // check for self-assignment
        return *this;
    }

    delete[] this->m_data;

    // make a copy
    this->m_data = new char[other.m_capacity]; // this-> can also be used (although a little redundant bc distinction on member variable name)
    this->m_size = other.m_size; 
    this->m_capacity = other.m_capacity;

    // for loop to copy
    for (size_t i = 0; i < this->m_size; i++){
        this->m_data[i] = other.m_data[i];
    }

    // null terminator
    this->m_data[this->m_size] = '\0'; // setting last element to null terminator

    // return reference;
    return *this; // "this" references the LHS of the assignment operator
    
};


size_t MyString::size() const{
    return this->m_size;
};


size_t MyString::length() const{
    return this->m_size;
};


void MyString::resize(size_t n){
    // handle shrinking string (n < m_size)
    if (n < this->m_size){
        this->m_data[n] = '\0'; // terminate string at location n
        this->m_size = n; // update size
    }

    // handle expanding the c-style string
    else if (n > this->m_size && n < this->m_capacity){
        // for loop to move null terminator
        for (size_t i = this->m_size; i < n; i++){
            this->m_data[i] = '\0';
        }
        this->m_data[n] = '\0';

        // update size
        this->m_size = n;
    }
    // handle when n > capacity
    else{
        size_t oldSize = this->m_size;
        this->m_capacity = n + 1; // make capacity bigger
        this->m_size = n; // update size

        // allocate memory 
        char* newData = new char[this->m_capacity];
        // populate it again (bigger)
        for (size_t j = 0; j < oldSize; j++){
            newData[j] = this->m_data[j];
        }

        for (size_t k = oldSize; k < this->m_size; k++){
            newData[k] = '\0';
        }
        newData[n] = '\0';
        char* temp = this->m_data;
        this->m_data = newData;
        delete[] temp;
    }
};


size_t MyString::capacity() const {
    return this->m_capacity;
};


void MyString::clear(){
    // update size
    this->m_size = 0;
    this->m_data[0] = '\0';

};


bool MyString::empty() const {
    return (this->m_size == 0);
};


const char& MyString::at(size_t pos) const  {
    // check if pos is the valid position of a character in the string
    if (pos >= this->m_size){
        throw std::out_of_range("invalid position");
    }

    return this->m_data[pos];
};

const char& MyString::front() const {
    return this->m_data[0];
};


MyString& MyString::operator+= (const MyString& other){

    // store starting index
    size_t startIndex = this->m_size;

    // save other string size before resizing
    size_t otherLength = other.size();

    // calculate new total size
    size_t newSize = this->m_size + other.size();

    // resize string to hold combined length
    resize(newSize);

    // copy other elements into m_data
    for (size_t i = 0; i < otherLength; i++){
        this->m_data[startIndex + i] = other.at(i);
    }

    return *this;
};


const char* MyString::data() const {

    return this->m_data;
};



size_t MyString::find(const MyString& str, size_t pos) const { // default argument ONLY specified in header file (cannot pos = 0 here)

    // check if substring is bigger than m_data itself
    if (this->m_size < str.size() || pos > this->m_size){
        return npos;
    }

    // iterate through main string
    for (size_t i = pos; i <= this->m_size - str.size(); i++){ // subtraction b/c substring needs to fit
        // bool flag
        bool isFound = true; 

        // logic to check if isFound is indeed false
        for (size_t j = 0; j < str.size(); j++){
            // compare main string to str
            if (this->m_data[i+j] != str.data()[j]){
                isFound = false;
                break;
            }
        }
        // if loop runs through all the way, return index
        if (isFound){
            return i;
        }
    }

    // if isFound set to false, return npos
    return npos;
};


std::ostream& operator<< (std::ostream& os, const MyString& str){

    os << str.data();

    return os;
};