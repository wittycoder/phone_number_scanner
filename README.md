phone_number_scanner
====================

This C program is the basis of other software that was used to scan through web data to get phone numbers.  The intent of this was to get the phone number of the a string and generate TEL: links with the numbers for mobile browsers or plugins that supported sending phone numbers to GoogleVoice or Skype.

This program was used as Dual license for a client using NPAPI for plugin on Firefox/Chrome so that is an available option instead of the GPL license this software is using.

To compile with tests, use the following (This is not a stand-along project so no makefile):
g++ main.cpp phoneNumber.cpp -o getnum
