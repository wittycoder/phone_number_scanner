/***************************************************************************
*    Copyright(c) Jeff Karau
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

// Define all consts for this array
const unsigned char VALID_PHONE_CHAR_LEN = 48;
const unsigned char NUMBERS_INDEX = 9;
const unsigned char L_INDEX = 40;
const unsigned char I_INDEX = 41;
const unsigned char SPECIAL_CHAR_INDEX = 42;
const unsigned char PLUS_INDEX = 47;
char validPhoneChars[VALID_PHONE_CHAR_LEN] =
{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
  'e', 'f', 'g', 'h', 'i', 'n', 'o', 'r', 's', 't',
  'u', 'v', 'w', 'x', 'z', 'E', 'F', 'G', 'H', 'I',
  'N', 'O', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Z',
  'l', 'I', '(', ')', '-', ',', ' ', '+'};

// Valid name strings:
// one, two, three, four, five, six, seven, eight, nine, zero

// Store the last phone number string so when get is called it can be parsed
static string lastPhoneNumberString;

bool stringCouldContainPhoneNumber(string inStr, int* indexRtn);

int
main(int argc, char* argv[])
{
   char inStr[255];
   bool retVal = false;
   int index = 0;

   ifstream infile;

   infile.open("numbers.txt");
   while (infile.getline(inStr, 255))
   {
      // Pass each phone number into the detection function
      cout << "Input string: " << inStr << endl;
      retVal = stringCouldContainPhoneNumber(inStr, &index);
      cout << '\t' << retVal << endl;
   }

   infile.close();

   return 0;
}

bool
stringCouldContainPhoneNumber(string inStr, int* indexRtn)
{
   int curNumCount;
   bool foundPartialTextNum = false;
   int i = 0, j = 0;
   bool phoneNumberAppearsOk = false;

   // Clear the last phone number string
   lastPhoneNumberString.clear();

   for (i = 0; i < inStr.length(); i++)
   {
      foundPartialTextNum = false;

      // First just check the string to see if the values appear 
      for (j = 0; j < VALID_PHONE_CHAR_LEN; j++)
      {
         // Check if the char is in the range of valid chars
	      if (inStr[i] == validPhoneChars[j])
         {
            // set the flag that we found the partial number
            foundPartialTextNum = true;

            // store the value we just got
            lastPhoneNumberString += inStr[i];

            break;
         }
      }
      if (foundPartialTextNum == true)
      {
         // We have added a character, validate what we have so far in the string
         // Check if the current char added was a number, check j which is the index last found
         cout << "Number index added: " << j << endl;
		 
         if (j > NUMBERS_INDEX)
         {
            cout << "Added char or special char, checking required" << endl;
            // Check if this is an 'l' char, if so convert into a 1 and treat as a number
            if (j == L_INDEX || j == I_INDEX)
            {
               lastPhoneNumberString[lastPhoneNumberString.length() - 1] = '1';
            }
            // Check if last char of a known number ending character in english, specific case for each
            else if (j == 10 || j == 25) // e
            {
            }
            else if (j == 16 || j == 31) // o
            {
            }
            else if (j == 15 || j == 30) // n
            {
            }
            else if (j == 17 || j == 32) // r
            {
            }
            else if (j == 19 || j == 34) // t
            {
            }
            else if (j == 23 || j == 38) // x
            {
            }
            else if (j > SPECIAL_CHAR_INDEX)
            {
               // Just remove the last char as it shouldn't be needed later for dialing
               lastPhoneNumberString.erase(lastPhoneNumberString.length() - 1);
            }
            else
            {
               // In this case nothing special
            }
            // Valid name strings:
            // one, two, three, four, five, six, seven, eight, nine, zero
         }
      }
   }
   cout << lastPhoneNumberString << endl;

   return foundPartialTextNum;
}
