#include <iostream>
#include "String.h"
#include <cstring>
#include <string.h>

String::String(const char *_str)
{
   length = std::strlen(_str);
   charDataVariab = new char[length + 1];
   std::strcpy(charDataVariab, _str);
}

String::String(const String &_other)
{
   length = _other.length;
   charDataVariab = new char[length + 1];
   std::strcpy(charDataVariab, _other.charDataVariab);
}

String::~String()
{
   delete[] charDataVariab;
}

size_t String::Length() const
{
   return length;
}

char & String::CharacterAt(size_t _index)
{
   return charDataVariab[_index];
}

const char & String::CharacterAt(size_t _index) const
{
   if (_index >= length) {
      throw std::out_of_range("Index out of range");
   }
   return charDataVariab[_index];
}

bool String::EqualTo(const String &_other) const
{
   return std::strcmp(charDataVariab, _other.charDataVariab) == 0;
}

String & String::Append(const String &_str)
{
   size_t newLength = length + _str.length;
   char* newCharDataVariab = new char[newLength + 1];
   std::strcpy(newCharDataVariab, charDataVariab);
   std::strcat(newCharDataVariab, _str.charDataVariab);
   delete[] charDataVariab;
   charDataVariab = newCharDataVariab;
   length = newLength;
   return *this;
}

String & String::Prepend(const String &_str)
{
   size_t newLength = length + _str.length;
   char* newCharDataVariab = new char[newLength + 1];
   std::strcpy(newCharDataVariab, _str.charDataVariab);
   std::strcat(newCharDataVariab, charDataVariab);
   delete[] charDataVariab;
   charDataVariab = newCharDataVariab;
   length = newLength;
   return *this;
}

const char * String::CStr() const
{
   return charDataVariab;
}

String & String::ToLower()
{
   for (size_t i = 0; i < length; ++i) {
      charDataVariab[i] = std::tolower(charDataVariab[i]);
   }
   return *this;
}

String & String::ToUpper()
{
   for (size_t i = 0; i < length; ++i) {
      charDataVariab[i] = std::toupper(charDataVariab[i]);
   }
   return *this;
}

size_t String::Find(const String &_str)
{
   const char* found = std::strstr(charDataVariab, _str.charDataVariab);
   if (found)
   {
      return found - charDataVariab;
   }

   return std::string::npos;
}

size_t String::Find(size_t _startIndex, const String &_str)
{
   if (_startIndex >= length) {
      return std::string::npos;
   }
   const char* found = std::strstr(charDataVariab + _startIndex, _str.charDataVariab);
   if (found) {
      return found - charDataVariab;
   }
   return std::string::npos;
}

String & String::Replace(const String &_find, const String &_replace)
{
   size_t pos = Find(_find);
   while (pos != static_cast<size_t>(-1))
   {

      size_t newLength = length - _find.length + _replace.length;
      char* newCharData = new char[newLength + 1];

      std::strncpy(newCharData, charDataVariab, pos);
      std::strcpy(newCharData + pos, _replace.CStr());
      std::strcpy(newCharData + pos + _replace.length, charDataVariab + pos + _find.length);

      delete[] charDataVariab;
      charDataVariab = newCharData;
      length = newLength;

      pos = Find(pos + _replace.length, _find);
   }
   return *this;
}

String & String::ReadFromConsole()
{
   char buffer[1024];
   std::cin.getline(buffer, 1024);

   delete[] charDataVariab;
   length = std::strlen(buffer);
   charDataVariab = new char[length + 1];
   std::strcpy(charDataVariab, buffer);

   return *this;
}

String & String::WriteToConsole()
{
   std::cout << "String Name: " << (charDataVariab ? charDataVariab : "null") << std::endl;
   return *this;
}

bool String::operator==(const String &_other) {
}

bool String::operator!=(const String &_other) {
}

String & String::operator=(const String &_str) {
}

char & String::operator[](size_t _index) {
}

const char & String::operator[](size_t _index) const {
}

int main()
{
   // Start of script.
   std::cout << "-----------" << std::endl;
   std::cout << "Start of Script" << std::endl;
   std::cout << "-----------" << std::endl;
   String myStringClass("Alex");
   myStringClass.WriteToConsole();
   std::cout << "----------------------" << std::endl;

   // Checking Length of Char.
   std::cout << "Test One" << std::endl;
   std::cout << "Char Length Test Start" << std::endl;
   if (myStringClass.Length() > 0)
   {
      std::cout << "Char Length: " << myStringClass.Length() << std::endl;
      std::cout << "Char Length Test Complete" << std::endl;
      std::cout << "----------------------" << std::endl;
   }

   // CharacterAt Lookup Method Of Char "Alex"
   int indexToLookup = 0;
   char thisLetterFoundInstead = myStringClass.CharacterAt(indexToLookup);

   std::cout << "Test Two" << std::endl;
   std::cout << "CharacterAt Test Start" << std::endl;

   // First checks if index is out of range
   if (indexToLookup >= myStringClass.Length())
   {
      std::cout << indexToLookup << " <- This is out of Range" << std::endl;
      std::cout << "CharacterAt Test Failed" << std::endl;
      std::cout << "----------------------" << std::endl;
   }
   else
   {
      // Second checks what char character is at index.
      std::cout << "Found " << thisLetterFoundInstead << " at index " << indexToLookup << " of Char " << std::endl;
      std::cout << "CharacterAt Test Complete" << std::endl;
      std::cout << "----------------------" << std::endl;
   }

   // Append Value Added (At End Of Char)
   std::cout << "Test Three" << std::endl;
   std::cout << "Append Test Start" << std::endl;
   myStringClass.Append("h");
   myStringClass.WriteToConsole();
   std::cout << "Append Test Complete" << std::endl;
   std::cout << "----------------------" << std::endl;

   // Prepend Value Added (At Start Of Char)
   std::cout << "Test Four" << std::endl;
   std::cout << "Prepend Test Start" << std::endl;
   myStringClass.Prepend("h");
   myStringClass.WriteToConsole();
   std::cout << "Prepend Test Complete" << std::endl;
   std::cout << "----------------------" << std::endl;

   // Checking if Values Are Equal Char
   char *equalCharValue ="hAlexh";
   std::cout << "Test Five" << std::endl;
   std::cout << "EqualTo Test Start" << std::endl;
   if (myStringClass.EqualTo(equalCharValue))
   {
      std::cout << equalCharValue << " is equal to " << myStringClass.CStr() << std::endl;
      std::cout << "EqualTo Test Complete" << std::endl;
      std::cout << "----------------------" << std::endl;
   }
   else
   {
      std::cout << equalCharValue << " is not equal to " << myStringClass.CStr() << std::endl;
      std::cout << "EqualTo Test Failed" << std::endl;
      std::cout << "----------------------" << std::endl;
   }

   // removes char from memory.
 --equalCharValue;

   // Returns CStr and displays it.
   std::cout << "Test Six" << std::endl;
   std::cout << "CStr Test Start" << std::endl;
   std::cout << "Using CStr() Test:  " << myStringClass.CStr() << std::endl;
   std::cout << "CStr Test Complete" << std::endl;
   std::cout << "----------------------" << std::endl;

   // Displays the char in all uppercase.
   std::cout << "Test Seven" << std::endl;
   std::cout << "ToUpper Test Start" << std::endl;
   myStringClass.ToUpper();
   myStringClass.WriteToConsole();
   std::cout << "ToUpper Test Complete" << std::endl;
   std::cout << "----------------------" << std::endl;

   // Displays the char in all lowercase.
   std::cout << "Test Eight" << std::endl;
   std::cout << "ToLower Test Start" << std::endl;
   myStringClass.ToLower();
   myStringClass.WriteToConsole();
   std::cout << "ToLower Test Complete" << std::endl;
   std::cout << "----------------------" << std::endl;

   // Finds location of the char character.
   std::cout << "Test Nine" << std::endl;
   std::cout << "Find Test Start" << std::endl;
   char *findThis= "l";
   size_t locationFoundIn = myStringClass.Find(findThis);
   // First checks if letter to find is out of range
   if (locationFoundIn > myStringClass.Length() || locationFoundIn <= 0 )
   {
      std::cout << findThis << " <- This is not in " << myStringClass.CStr() << std::endl;
      std::cout << "Find Test Failed" << std::endl;
      std::cout << "----------------------" << std::endl;
   }
   else
         {
            std::cout << "Found " << findThis << " at index " << locationFoundIn << " of Char " << std::endl;
            std::cout << "Find Test Complete" << std::endl;
            std::cout << "----------------------" << std::endl;
         }

   // removes char from memory.
   --findThis;

   // Replaces Char with Another
   std::cout << "Test Ten" << std::endl;
   std::cout << "Replace Test Start" << std::endl;
   char *replacementChar = "Alex";
   myStringClass.Replace(myStringClass.CStr(), replacementChar);
   myStringClass.WriteToConsole();
   std::cout << "Replace Test Complete" << std::endl;
   std::cout << "----------------------" << std::endl;

   // removes char from memory.
   --replacementChar;



   // Starts again from line 0 in the .cpp script.
   return 0;
}
