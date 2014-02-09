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

#include "phoneNumber.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

// List names representing the numbers:
const unsigned char num_len = 10;
string numberStrings[num_len] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

// unused, better method finding all ascii numbers
//const unsigned char leave_len = 10;
//char leaveChars[leave_len] = {'0','1','2','3','4','5','6','7','8','9'}

// Issue came up with special chars for input, remove them, again unused
//const unsigned char remove_len = 9;
//char skipCars[remove_len] = {' ', '(', ')', '-', ',', '.', ':', ';', '#'};

bool
isDigits(string inStr)
{
   // loop through the entire passed in string to see if it is only digits
#ifdef _DEBUG
cout << "isDigits: string: " << inStr;
#endif
   for (int i = 0; i < inStr.length(); i++)
   {
      // check if a value is outside of the ascii ranges
      if (inStr[i] < 0x30 || inStr[i] > 0x39)
      {
#ifdef _DEBUG
cout << "returning false" << endl;
#endif
         return false;
      }
   }
#ifdef _DEBUG
cout << "returning true" << endl;
#endif
   return true;
}

string
removeSkipChars(string inStr)
{
   int i = 0;
   string outputstring;
   bool matchchar = false;
   int len = inStr.length();

   // scan the string
   for (i = 0; i < len; i++)
   {
      // Check for before after chars to make sure one is either a special char or a number
      if ((i > 0) && !(inStr[i-1] >= 0x41 && isalnum(inStr[i-1])) &&
          ((i + 1) < len) && !(inStr[i+1] >= 0x41 && isalnum(inStr[i+1])))
      {
         // Neither 'l' or 'I' are in the names representing numbers so just treat them as
         // special chars and add '1' to the string for each of those
         // 'O' as 0s are different becuase '0's can be part of zero, one, two, etc names
         if (inStr[i] == 'l' || inStr[i] == 'L')
         {
            outputstring += '1';
            continue;
         }
         else if (inStr[i] == 'i' || inStr[i] == 'I')
         {
            outputstring += '1';
            continue;
         }
         else if (inStr[i] == 'o' || inStr[i] == 'O')
         {
            outputstring += '0';
            continue;
         }
      }

      // Check if this is a special char by looking at ascii < 0x30 or > 0x7a
      // OR between 0x5B and 0x60
      if ((inStr[i] < 0x30 || inStr[i] > 0x7a) || (inStr[i] >= 0x5b && inStr[i] <= 0x60))
      {
         continue; 
      }
      else
      {
         outputstring += inStr[i];
      }
   }
   return outputstring;
}

bool
findPhoneNumber(string inStr, string& outputStr)
{
   string tempstring;
   int i = 0, j = 0, n = 0;
   string::iterator it;
   bool matchchar = false;

   // Remove all extraneous chars
   inStr = removeSkipChars(inStr);

   // Check if the string is already all digits
   if (isDigits(inStr) == true && inStr.length() >= 7)
   {
      // All digits, so just set the output to input and return true
      outputStr = inStr;
      return true;
   }

   // If we now know we have a string convert to lower to check chars:
   std::transform(inStr.begin(), inStr.end(), inStr.begin(), ::tolower);

   // Scan the string
   for (n = 0; n < inStr.length(); n++)
   {
      // leave numbers
      if (inStr[n] >= 0x30 && inStr[n] <= 0x39)
      {
         outputStr += inStr[n];
      }

      // Assign to the temp string
      tempstring += inStr[n];

      // search the temp string for elements of the numbers we are looking for
      for (i = 0; i < num_len; i++)
      {
         // iterate over the current string in the number list
         for (it = numberStrings[i].begin(); it < numberStrings[i].end(); it++)
         {
            // Check if we have a match
            if (*it == tempstring[tempstring.length() - 1])
            {
               // Check if this is the last char of the num string
               if (it - numberStrings[i].begin() == (numberStrings[i].length() - 1))
               {
                  // Now we have matched the last char, look in revese for the whole string
                  for (int curindex = n, j = it - numberStrings[i].begin();
                       j >= 0 && curindex >= 0; j--, curindex--)
                  {
                     #ifdef _DEBUG
                     cout << "i: " << i << " j: " << j << " searching char: " << numberStrings[i][j] <<
                     " compare with: " << curindex << " ('" << tempstring[curindex] << "')" << endl;
                     #endif

                     // Check cur string if it is long enough
                     if (numberStrings[i][j] == tempstring[curindex])
                     {
                        // Now check if we matched the full string
                        if (j == 0)
                        {
                           #ifdef _DEBUG
                           cout << "FOUND FULL NUM STRING MATCH!" << endl;
                           #endif

                           // Append the output based on the enum index + ascii for zero
                           outputStr += '0' + i;
                        }
                        continue;
                     }
                     else
                     {
                        // if current isn't long enough break out of loop checking for matching
                        // full string
                        break;
                     }
                  }
               }
            }
            else
            {
               // If we haven't matched a char just continue
               continue;
            }
         }
      }
   }

   // Check if the output string we have it long enough and full of only digits
   if ((isDigits(outputStr) == true) && outputStr.length() >= 7)
   {
      return true;
   }
   else 
   {
      return false;
   }
}

