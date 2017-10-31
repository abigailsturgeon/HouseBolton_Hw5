//
// Created by Owner on 10/26/2017.
//

#include "roman.h"

/*!
 * Default constructor set to 0
 */
Roman::Roman()
{
    value = 0;
}

/*!
 * Constructor that accepts string and converts it to an integer
 * @param roman
 */
Roman::Roman(const string &r)
{
    convertFromRoman(r);
}

/*!
 * Gets the value
 * @return
 */
unsigned int Roman::getValue() const
{
    return value;
}

/*!
 * Sets the value
 * @param value
 */
void Roman::setValue(unsigned int value)
{
    Roman::value = value;
}
/*!
 * Takes a string of roman numerals
 * and converts it to an integer
 * @param roman
 */
void Roman::convertFromRoman(const string &str)
{
    int temp = 0;

    for(int i = 0; i < str.length(); i++)
    {
        char c = str.at(i);
        switch(c)
        {
            case 'M':
                temp = temp + 1000;
                break;
            case 'D':
                temp = temp + 500;
                break;
            case 'C':
                temp = temp + 100;
                break;
            case 'L':
                temp = temp + 50;
                break;
            case 'X':
                temp = temp + 10;
                break;
            case 'V':
                temp = temp + 5;
                break;
            case'I':
                temp = temp + 1;
                break;
            default:
                temp = temp + 0;
                break;
        }
    }
    value = temp;

    cout << "Roman number " << str << " length " << str.length() << endl;
    cout << "Decimal value: " << value << endl;
}

/*!
 * Takes two roman objects and adds them
 * @param s1: roman object being passed in
 * @return s2: returns total
 */
Roman Roman::operator+(const Roman& s1) const
{
    Roman s2;
    s2.value = value + s1.value;
    return s2;
}

/*!
 * Adds a roman object and an int
 * @param dec: integer being passed in
 * @return s1: returns total
 */
Roman Roman::operator+(const int dec) const
{
    Roman s1;
    s1.value = dec + value;
    return s1;
}

/*!
 * Adds an int with an object
 * @param i: int
 * @param r1: roman object
 * @return r1: returns total
 */
Roman operator+(const int i, Roman r1)
{
    r1.setValue(i + r1.getValue());
    return r1;
}

/*!
 * The left and right operands are Roman objects, but the left operand can change.
 * @param r1
 */
void Roman::operator+=(const Roman &r1)
{
    value += r1.value;
}

/*!
 * //The left operand is a Roman object, the right is an int number.  The left operand can change.
 */
void Roman::operator+=(const int dec)
{
    value += dec;
}

/*!
 * Prefix ++ operator
 * @return increments roman
 */
Roman Roman::operator++()
{
    Roman s1;
    s1.value = ++value;
    return s1;
}

//This helps with testing, do not modify.
void testConstructor()
{
    //Test to make sure that empty objects are set to zero.
    Roman blank;
    checkTest("testConstructor #1", 0, blank);

    //Test reading in a number.
    Roman a("LXVI");
    checkTest("testConstructor #2", 66, a);

    //Test a bigger number.
    Roman b("MMMDDCCLLXXVVII");
    checkTest("testConstructor #3", 4332, b);
}

//This helps with testing, do not modify.
bool checkTest(string testName, int whatItShouldBe, const Roman& obj )
{
    if (whatItShouldBe == obj.value)
    {
        cout << "\nPassed " << testName << endl;
        return true;
    }
    else
    {
        cout << "\n****** Failed test " << testName << " ****** " << endl << "     Object contained: "<< obj.value << endl << "     Output should have contained: " << whatItShouldBe << endl;
        return false;
    }
}

//This helps with testing, do not modify.
bool checkTest(string testName, string whatItShouldBe, string whatItIs)
{
    if (whatItShouldBe == whatItIs)
    {
        cout << "\nPassed " << testName << endl;
        return true;
    }
    else
    {
        cout << "\n****** Failed test " << testName << " ****** " << endl << "     Object contained: "<< whatItIs << endl << "     Output should have contained: " << whatItShouldBe << endl;
        return false;
    }
}

void testOperatorPlus()
{
//Test adding two roman objects
    Roman a("XVI");
    Roman b("MDCLXVI");
    Roman c = a + b;
    checkTest("testOperatorPlus #1", 1682, c);
    //make sure the left and right operands weren't modified
    checkTest("testOperatorPlus #2", 16, a);
    checkTest("testOperatorPlus #3", 1666, b);

//Test adding an object with an int
    c = a + 52;
    checkTest("testOperatorPlus #4", 68, c);
// make sure the left operand wasn't modified
    checkTest("testOperatorPlus #5", 16, a);
//Test adding an int with an object
    c = 578 + a;
    checkTest("testOperatorPlus #6", 594, c);
    //make sure the right operand wasn't modified
    checkTest("testOperatorPlus #7", 16, a);
}

void testOperatorPlusEqual()
{
//Test adding two roman objects
Roman a("MLII");
    Roman b("DDCCI");
    a += b;
    checkTest("testOperatorPlusEqual #1", 2253, a);

    //make sure the right operand wasn't modified
    checkTest("testOperatorPlusEqual #2", 1201, b);

    //Test adding on an integer
    b += 17;
    checkTest("testOperatorPlusEqual #3", 1218, b);

}

void testOperatorIncrement()
{
//Test prefix increment
Roman a("MLII");
    Roman b("DDCCI");
    b = ++a;
    checkTest("testOperatorIncrement #1", 1053, a);
    checkTest("testOperatorIncrement #2", 1053, b);
}

/*
void testConsoleIO()
{
//Test reading in the data using the extraction operator >>
cout << "Enter the text CCLX: ";
    Roman a;
    cin >> a;
    checkTest("testConsoleIO #1", 260, a);
    //Test outputting data using the insertion operator <<
    cout << "testConsoleIO #2" << endl << "If this says 260, this test passed: " << a << endl;
}
/*
void testOutput()
{
    Roman a("MDCLXVI");
}string b = a.convertToRoman();
checkTest("testOutput #1", "MDCLXVI", b);
//This is really the value 7.  Your code should correctly read this in and convert it back to VII.
Roman c("IIIIIII");
b = c.convertToRoman();
checkTest("testOutput #2", "VII", b);
}
 */