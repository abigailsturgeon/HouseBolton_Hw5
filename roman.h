//
// Created by Owner on 10/26/2017.
//

#ifndef HOUSEBOLTON_HW5_ROMAN_H
#define HOUSEBOLTON_HW5_ROMAN_H
#include<iostream>
using namespace std;

// Function prototypes
void testConstructor();

// Class definition
class Roman
{
private:
    unsigned int value;
public:

    Roman();        // Default constructor

    //These two are for testing purposes only.  They have been given to you.
    friend bool checkTest(string, int, const Roman&);  //A testing function.  It is friended so it can access the class.
    friend void testOutput();   // Another test function that needs to access private class members.
};

#endif //HOUSEBOLTON_HW5_ROMAN_H
