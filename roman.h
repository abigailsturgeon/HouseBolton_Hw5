//
// Created by Owner on 10/26/2017.
//

#ifndef HOUSEBOLTON_HW5_ROMAN_H
#define HOUSEBOLTON_HW5_ROMAN_H
#include<iostream>
using namespace std;

// Function prototypes
void testConstructor();
void testOperatorPlus();
void testOperatorPlusEqual();
//void testOperatorIncrement();
//void testConsoleID();

// Class definition
class Roman
{
private:
    unsigned int value;
    //string convertToRoman() const;  //The method that helps us take an integer and turn it into a roman numeral
    void convertFromRoman(const string &r);  //The method that helps us take an roman numeral in a string and convert it into the integer.
public:
    Roman();  // Default constructor that allows us to make empty objects.
    Roman(const string&);  //The constructor which accepts a string and  converts it internally to an integer.  It actually just forwards it onto convertFromRoman()
    Roman operator+(const Roman &s1) const;  //The left and right operands are Roman objects
    Roman operator+(const int dec) const; //The left operand is a Roman object, the right is an int number.
    //Roman operator+(const int i) const;
    void operator +=(const Roman &r1);  //The left and right operands are Roman objects, but the left operand can change.
    void operator +=(const int);  //The left operand is a Roman object, the right is an int number.  The left operand can change.
    //Roman operator++();  //The prefix ++ operator

    //These two are for testing purposes only.  They have been given to you.
    friend bool checkTest(string, int, const Roman&);  //A testing function.  It is friended so it can access the class.
    friend void testOutput();   // Another test function that needs to access private class members.
};

#endif //HOUSEBOLTON_HW5_ROMAN_H
