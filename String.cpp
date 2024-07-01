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
   if (_index >= length) {
      throw std::out_of_range("Index out of range");
   }
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
   if (found) {
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

String & String::Replace(const String &_find, const String &_replace) {
}

String & String::ReadFromConsole() {
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
   String myStringClass("Alex");
   myStringClass.WriteToConsole();
   std::cout << "----------------------" << std::endl;

   // Checking Length of Char.
   if (myStringClass.Length() > 0)
   {
      std::cout << "Char Length: " << myStringClass.Length() << std::endl;
      std::cout << "Char Length Test Complete" << std::endl;
      std::cout << "----------------------" << std::endl;
   }

   // CharacterAt Lookup Method Of Char "Alex"
   char *letterToFind = "x";
   int indexToLookup = 3;

   // First checks if index is out of range
   if (indexToLookup >= myStringClass.Length())
   {
      std::cout << indexToLookup << " <- This is out of Range" << std::endl;
      std::cout << "CharacterAt Test Failed" << std::endl;
      std::cout << "----------------------" << std::endl;
   }
   else
      // Second step checks if the character at the given index matches the letterToFind
      if (myStringClass.CharacterAt(indexToLookup) != *letterToFind)
      {
         std::cout << "Unable to find " << letterToFind << " at index " << indexToLookup << " of Char " << std::endl;
         char thisLetterFoundInstead = myStringClass.CharacterAt(indexToLookup);
         std::cout << "Found " << thisLetterFoundInstead << " at index " << indexToLookup << " of Char " << std::endl;
         std::cout << "----------------------" << std::endl;
      }
      else
      {
         std::cout << "Found " << letterToFind << " at index " << indexToLookup << " of Char " << std::endl;
         std::cout << "CharacterAt Test Complete" << std::endl;
         std::cout << "----------------------" << std::endl;
      }
   // removes char from memory.
   --letterToFind;

   // Append Value Added (At End Of Char)
   myStringClass.Append("h");
   myStringClass.WriteToConsole();
   std::cout << "Append Test Complete" << std::endl;
   std::cout << "----------------------" << std::endl;

   // Prepend Value Added (At Start Of Char)
   myStringClass.Prepend("h");
   myStringClass.WriteToConsole();
   std::cout << "Prepend Test Complete" << std::endl;
   std::cout << "----------------------" << std::endl;

   // Checking if Values Are Equal Char

   char *equalCharValue ="hAlexh";
   if (myStringClass.EqualTo(equalCharValue))
   {
      std::cout << equalCharValue << " is equal to the base string char" << std::endl;
      std::cout << "EqualTo Test Complete" << std::endl;
      std::cout << "----------------------" << std::endl;
   }
   else
   {
      std::cout << equalCharValue << " is not equal to the base string char" << std::endl;
      std::cout << "EqualTo Test Failed" << std::endl;
      std::cout << "----------------------" << std::endl;
   }

   // removes char from memory.
 --equalCharValue;

   // Starts again from top to bottom.
   return 0;
}
