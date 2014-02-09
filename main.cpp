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
#include <string>
#include "phoneNumber.hpp"

using namespace std;

int
main(int argc, char* argv[])
{
   string outputStr;
   string teststring;
   int testspassed = 0;

   // TEST 1
   // 011 602-four five 6-five nine zero three
   outputStr.clear();
   teststring.clear();
   teststring.append("011 602-four five 6-five nine zero three");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      if (outputStr.compare("0116024565903") == 0)
      {
         cout << "test 1 passed, returned: " << outputStr << endl;
      }
      else
      {
         cout << "test 1 failed, returned: " << outputStr << endl;
      }
   }
   else
   {
      cout << "test string 1 failed, returned false" << endl;
   }

   // TEST 2
   // +44  07700 954 321
   outputStr.clear();
   teststring.clear();
   teststring.append("+44  07700 954 321 ");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      if (outputStr.compare("4407700954321") == 0)
      {
         cout << "test 2 passed, returned: " << outputStr << endl;
      }
      else
      {
         cout << "test 2 failed, returned: " << outputStr << endl;
      }
   }
   else
   {
      cout << "test 2 failed, returned false" << endl;
   }

   // TEST 3
   // 1-866-343-4324
   outputStr.clear();
   teststring.clear();
   teststring.append("1-866-343-4324");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      if (outputStr.compare("18663434324") == 0)
      {
         cout << "test 3 passed, returned: " << outputStr << endl;
      }
      else
      {
         cout << "test 3 failed, returned: " << outputStr << endl;
      }
   }
   else
   {
      cout << "test 3 failed, returned false" << endl;
   }

   // TEST 4
   // (602) 555 - 8812
   outputStr.clear();
   teststring.clear();
   teststring.append("(602) 555 - 8812");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      if (outputStr.compare("6025558812") == 0)
      {
         cout << "test 4 passed, returned: " << outputStr << endl;
      }
      else
      {
         cout << "test 4 failed, returned: " << outputStr << endl;
      }
   }
   else
   {
      cout << "test 4 failed, returned false" << endl;
   }

   // TEST 5
   // 481-555-4256
   outputStr.clear();
   teststring.clear();
   teststring.append("481-555-4256");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      if (outputStr.compare("4815554256") == 0)
      {
         cout << "test 5 passed, returned: " << outputStr << endl;
      }
      else
      {
         cout << "test 5 failed, returned: " << outputStr << endl;
      }
   }
   else
   {
      cout << "test 5 failed, returned false" << endl;
   }

   // TEST 6
   // 86	(10) 69445464
   outputStr.clear();
   teststring.clear();
   teststring.append("86\t(10) 69445464");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      if (outputStr.compare("861069445464") == 0)
      {
         cout << "test 6 passed, returned: " << outputStr << endl;
      }
      else
      {
         cout << "test 6 failed, returned: " << outputStr << endl;
      }
   }
   else
   {
      cout << "test 6 failed, returned false" << endl;
   }

   // TEST 7
   // onefoursix - threefive0 five eight seven two
   outputStr.clear();
   teststring.clear();
   teststring.append("something here onefoursix - threefive0 five eight seven two");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      if (outputStr.compare("1463505872") == 0)
      {
         cout << "test 7 passed, returned: " << outputStr << endl;
      }
      else
      {
         cout << "test 7 failed, returned: " << outputStr << endl;
      }
   }
   else
   {
      cout << "test 7 failed, returned false" << endl;
   }

   // TEST 8
   // invalid
   outputStr.clear();
   teststring.clear();
   teststring.append("invalid");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      cout << "test 8 failed, returned true" << endl;
   }
   else
   {
      cout << "test 8 passed, string is not a phone number" << endl;
   }

   // TEST 9
   // on the first time this should fail.
   outputStr.clear();
   teststring.clear();
   teststring.append("on the first time this should fail.");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      cout << "test 9 failed, returned true" << endl;
   }
   else
   {
      cout << "test 9 passed, string is not a phone number" << endl;
   }

   // TEST 10
   // notanumber
   outputStr.clear();
   teststring.clear();
   teststring.append("notanumber");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      cout << "test 10 failed, returned true" << endl;
   }
   else
   {
      cout << "test 10 passed, string is not a phone number" << endl;
   }

   // TEST 11
   // 58 (0295) 416,72,16
   outputStr.clear();
   teststring.clear();
   teststring.append("58 (0295) 416,72,16");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      if (outputStr.compare("5802954167216") == 0)
      {
         cout << "test 11 passed, returned: " << outputStr << endl;
      }
      else
      {
         cout << "test 11 failed, returned: " << outputStr << endl;
      }
   }
   else
   {
      cout << "test 11 failed, returned false" << endl;
   }

   // TEST 12
   // 582954167216
   outputStr.clear();
   teststring.clear();
   teststring.append("582954167216");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      if (outputStr.compare("582954167216") == 0)
      {
         cout << "test 12 passed, returned: " << outputStr << endl;
      }
      else
      {
         cout << "test 12 failed, returned: " << outputStr << endl;
      }
   }
   else
   {
      cout << "test 12 failed, returned false" << endl;
   }

   // TEST 13
   // 468l890
   outputStr.clear();
   teststring.clear();
   teststring.append("468l890");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      if (outputStr.compare("4681890") == 0)
      {
         cout << "test 13 passed, returned: " << outputStr << endl;
      }
      else
      {
         cout << "test 13 failed, returned: " << outputStr << endl;
      }
   }
   else
   {
      cout << "test 13 failed, returned false" << endl;
   }

   // TEST 14
   // stuzeroonetron+3orf
   outputStr.clear();
   teststring.clear();
   teststring.append("stuzeroonetron+3orf");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      cout << "test 14 failed, returned true" << endl;
   }
   else
   {
      cout << "test 14 passed, string is not a phone number" << endl;
   }

   // TEST 15
   // **four-eight-zero**six-five-zero**three-six-five-seven
   outputStr.clear();
   teststring.clear();
   teststring.append("**four-eight-zero**six-five-zero**three-six-five-seven");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      if (outputStr.compare("4806503657") == 0)
      {
         cout << "test 15 passed, returned: " << outputStr << endl;
      }
      else
      {
         cout << "test 15 failed, returned: " << outputStr << endl;
      }
   }
   else
   {
      cout << "test 15 failed, returned false" << endl;
   }

   // TEST 16
   //(((((6O2****56l***67l3)))
   outputStr.clear();
   teststring.clear();
   teststring.append("(((((6O2****56l***67l3)))");
   // Check if this is a phone number string
   if (findPhoneNumber(teststring, outputStr) == true)
   {
      if (outputStr.compare("6025616713") == 0)
      {
         cout << "test 16 passed, returned: " << outputStr << endl;
      }
      else
      {
         cout << "test 16 failed, returned: " << outputStr << endl;
      }
   }
   else
   {
      cout << "test 16 failed, returned false" << endl;
   }
}
