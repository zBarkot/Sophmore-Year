
/***********************************************
Author: Barkot Zeyohannes
Date: Feburary 8, 20024
Purpose: Decode and encode mail zipcodes
Sources of Help: w3schools
***********************************************/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class ZipCode
{
public:
    // overloaded constructors
    ZipCode(int zipcode);
    ZipCode(string barcode);

    // getter functions
    int getZipCode(void);
    string getBarCode(void);

private:
    string barcode; // class stores zipcode as its encoded barcode

    int decodeDigit(const string barcode); // returns decoded zipcode
    string encodeDigit(int number); // returns encoded zipcode
};

ZipCode::ZipCode(int zipcode)
{
    // given a digital zipcode
    // encode the zipcode into a barcode
    barcode = encodeDigit(zipcode);
}

ZipCode::ZipCode(string barcode25)
{
   /* if (sizeof(barcode25) != 25)
    {
        cout << barcode25 << " is not a valid input. Doesn't contain 25 characters" << endl;
        exit(1);
    }
    for (int i = 0; i < 25; i++)
    {
        if (barcode25[i] != '1' || barcode25[i] != '0')
            cout << barcode25 << " is not a valid input. Contains erogenous values " << endl;
            exit(1);
    }
*/
    barcode = barcode25;
}

string ZipCode::getBarCode()
{
    return barcode;
}

int ZipCode::getZipCode()
{
    return decodeDigit(barcode);
}

string ZipCode::encodeDigit(int number)
{
    string codeVal[10] = {"11000", "00011", "00101", "00110", "01001", "01010", "01100", "10001", "10010", "10100"};
    string returnVal;
    string code1,
        code2,
        code3,
        code4,
        code5;
    int digit[5];
    int i;
    for (i = 0; i < 5; i++)
    {
        digit[i] = number % 10;
        number = number / 10;
    }

    code1 = codeVal[digit[4]];
    code2 = codeVal[digit[3]];
    code3 = codeVal[digit[2]];
    code4 = codeVal[digit[1]];
    code5 = codeVal[digit[0]];

    returnVal= "1" + code1 + code2 + code3 + code4 + code5 + "1"; // enclosed with 1s

    return returnVal;
    
}

int ZipCode::decodeDigit(const string barcode)
{
    string codeVal[10] = {"11000", "00011", "00101", "00110", "01001", "01010", "01100", "10001", "10010", "10100"};
    string temp1 = barcode.substr(1, 5);
    string temp2 = barcode.substr(6, 5);
    string temp3 = barcode.substr(11, 5);
    string temp4 = barcode.substr(16, 5);
    string temp5 = barcode.substr(21, 5);
    int num1, num2, num3, num4, num5;
    int returnVal;

    int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; i++)
    {
        if (temp1 == codeVal[i])
        {
            num1 = digits[i];
        }
        if (temp2 == codeVal[i])
        {
            num2 = digits[i];
        }
        if (temp3 == codeVal[i])
        {
            num3 = digits[i];
        }
        if (temp4 == codeVal[i])
        {
            num4 = digits[i];
        }
        if (temp5 == codeVal[i])
        {
            num5 = digits[i];
        }
    }

    returnVal = (10000*num1) +(1000*num2) +(100*num3) + (10*num4) + num5;

    return returnVal;

}

int main(int argc, char *argv[])
{
    ZipCode zip(99504),
        zip2("100101010011100001100110001"),
        zip3(12345),
        zip4(67890);
    cout << zip.getZipCode() << "'s bar code is '"
         << zip.getBarCode() << "'" << endl;
    cout << zip2.getZipCode() << "'s bar code is '"
         << zip2.getBarCode() << "'" << endl;
    cout << zip3.getZipCode() << "'s bar code is '"
         << zip3.getBarCode() << "'" << endl;
    cout << zip4.getZipCode() << "'s bar code is '"
         << zip4.getBarCode() << "'" << endl;

    cout << endl;

    // Test a range of values by first constructing a zip code
    // with an integer, then retrieving the bar code and using
    // that to construct another ZipCode.
    int zip_int = 0;
    for (int i = 0; i < 25; i++)
    {
        // Make an aribrary 5-digit zip code integer, and use it
        // to construct a ZipCode
        int five_digit_zip = (zip_int * zip_int) % 100000;
        ZipCode z1(five_digit_zip);

        // Construct a second ZipCode from the first's bar code
        string z1_barcode = z1.getBarCode();
        ZipCode z2(z1_barcode);

        cout.width(3);
        cout << (i + 1) << ": ";
        cout.width(5);
        cout << z2.getZipCode() << " has code '"
             << z1_barcode << "'";

        if ((z1_barcode == z2.getBarCode()) &&
            (z1.getZipCode() == z2.getZipCode()) &&
            (z2.getZipCode() == five_digit_zip))
        {
            cout << " [OK]" << endl;
        }
        else
        {
            cout << " [ERR]" << endl;
        }

        // Increment the test value arbitrarily
        zip_int += (233 + zip_int % 7);
    }
    cout << endl;
    // Test some error conditions. This test assumes that
    // ZipCode will simply set its value to a flag that indicates
    // an error, and will not exit the program.
    int BAD_ZIP_COUNT = 2;
    string bad_zips[][2] = {
        {"100101010011100001100110000", "bad start/end character"},
        {"100101010011100001100110021", "bad digit"},
    };
    for (int i = 0; i < BAD_ZIP_COUNT; i++)
    {
        cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] << endl;
        ZipCode test(bad_zips[i][0]);
        cout << endl;
    }
    cout << "Enter a character to quit." << endl;
    char c;
    cin >> c;
    return 0;
}
