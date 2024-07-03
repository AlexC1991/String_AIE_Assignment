#include <iostream>
#include "String.h"
#include <cstring>

String::String(const char *_str)
{
   // Step 1: Calculate the length of the input C-string
   length = std::strlen(_str);

   // Step 2: Allocate a new char array to hold the input C-string plus null terminator
   charDataVariab = new char[length + 1]; // +1 for the null terminator

   // Step 3: Copy the input C-string into the new char array
   std::strcpy(charDataVariab, _str);
}

String::String(const String &_other)
{
   // Step 1: Set the length of the current string to the length of the other string
   length = _other.length;

   // Step 2: Allocate a new char array to hold the other string's data plus null terminator
   charDataVariab = new char[length + 1]; // +1 for the null terminator

   // Step 3: Copy the other string's data into the new char array
   std::strcpy(charDataVariab, _other.charDataVariab);
}

String::~String()
{
   // Delete the char array to free memory.
   delete[] charDataVariab;
}

size_t String::Length() const
{
   // Return the length of the string.
   return length;
}

char & String::CharacterAt(size_t _index)
{
   // Return a reference to the character at the specified index.
   return charDataVariab[_index];
}

const char & String::CharacterAt(size_t _index) const
{
   // Return a const reference to the character at the specified index.
   return charDataVariab[_index];
}

bool String::EqualTo(const String &_other) const
{
   // Compare the current string's char array with the other string's char array using std::strcmp, return true if equal.
   return std::strcmp(charDataVariab, _other.charDataVariab) == 0;
}

String & String::Append(const String &_str)
{
   // Step 1: Calculate the new length
   size_t newLength = length + _str.length;

   // Step 2: Allocate new char array
   char* newCharDataVariab = new char[newLength + 1]; // +1 for the null terminator

   // Step 3: Copy current string data
   std::strcpy(newCharDataVariab, charDataVariab);

   // Step 4: Concatenate new string data
   std::strcat(newCharDataVariab, _str.charDataVariab);

   // Step 5: Delete old char array to free memory
   delete[] charDataVariab;

   // Step 6: Point to the new array
   charDataVariab = newCharDataVariab;

   // Step 7: Update length
   length = newLength;

   // Step 8: Return reference to this object
   return *this;
}

String & String::Prepend(const String &_str)
{
   // Step 1: Calculate the new length of the combined strings
   size_t newLength = length + _str.length;

   // Step 2: Allocate new char array to hold the combined string plus null terminator
   char* newCharDataVariab = new char[newLength + 1]; // +1 for the null terminator

   // Step 3: Copy the new string data into the new array
   std::strcpy(newCharDataVariab, _str.charDataVariab);

   // Step 4: Concatenate the current string data to the new array
   std::strcat(newCharDataVariab, charDataVariab);

   // Step 5: Delete the old char array to free memory
   delete[] charDataVariab;

   // Step 6: Point to the new array
   charDataVariab = newCharDataVariab;

   // Step 7: Update length to the new length
   length = newLength;

   // Step 8: Return reference to this object
   return *this;
}

const char * String::CStr() const
{
   // Return a pointer to the character array representing the string.
   return charDataVariab;
}

String & String::ToLower()
{
   // Convert each character in the string to lowercase
   for (size_t i = 0; i < length; ++i)
   {
      charDataVariab[i] = std::tolower(charDataVariab[i]);
   }
   return *this;
}

String & String::ToUpper()
{
   // Convert each character in the string to uppercase.
   for (size_t i = 0; i < length; ++i)
   {
      charDataVariab[i] = std::toupper(charDataVariab[i]);
   }
   return *this;
}

size_t String::Find(const String &_str)
{
   // Step 1: Use std::strstr to find the first occurrence of _str.charDataVariab in charDataVariab
   const char* found = std::strstr(charDataVariab, _str.charDataVariab);

   // Step 2: If a match is found
   if (found)
   {
      // Return the index of the found substring by subtracting the base pointer charDataVariab
      return found - charDataVariab;
   }

   // Step 3: If no match is found, return std::string::npos
   return std::string::npos;
}

size_t String::Find(size_t _startIndex, const String &_str)
{
   // Step 1: Check if the start index is beyond the length of the current string
   if (_startIndex >= length)
   {
      // If so, return npos to indicate no match found
      return std::string::npos;
   }

   // Step 2: Use std::strstr to find the first occurrence of _str.charDataVariab in charDataVariab starting from _startIndex
   const char* found = std::strstr(charDataVariab + _startIndex, _str.charDataVariab);

   // Step 3: If a match is found
   if (found)
   {
      // Return the index of the found substring
      return found - charDataVariab;
   }

   // Step 4: If no match is found, return npos
   return std::string::npos;
}

String & String::Replace(const String &_find, const String &_replace)
{
   // Step 1: Find the first occurrence of the substring _find
   size_t pos = Find(_find);

   // Step 2: Loop while the substring _find is found
   while (pos != std::string::npos)
   {
      // Step 3: Calculate the new length of the string after replacement
      size_t newLength = length - _find.length + _replace.length;

      // Step 4: Allocate a new char array to hold the modified string plus null terminator
      char* newCharData = new char[newLength + 1]; // +1 for the null terminator

      // Step 5: Copy the part of the original string before the found position
      std::strncpy(newCharData, charDataVariab, pos);

      // Step 6: Copy the replacement string into the new array at the found position
      std::strcpy(newCharData + pos, _replace.CStr());

      // Step 7: Copy the part of the original string after the found substring
      std::strcpy(newCharData + pos + _replace.length, charDataVariab + pos + _find.length);

      // Step 8: Delete the old char array to free memory
      delete[] charDataVariab;

      // Step 9: Point to the new array
      charDataVariab = newCharData;

      // Step 10: Update length to the new length
      length = newLength;

      // Step 11: Find the next occurrence of the substring _find starting after the last replacement
      pos = Find(pos + _replace.length, _find);
   }
   return *this;
}

String & String::ReadFromConsole()
{
   // Step 1: Create a buffer to hold input data from the user
   char buffer[100];

   // Step 2: Use std::cin.getline to read a line of input into the buffer
   std::cin.getline(buffer, 100);

   // Step 3: Delete the old char array to free memory
   delete[] charDataVariab;

   // Step 4: Calculate the length of the input string
   length = std::strlen(buffer);

   // Step 5: Allocate a new char array to hold the input string plus null terminator
   charDataVariab = new char[length + 1]; // +1 for the null terminator

   // Step 6: Copy the input string from the buffer to the new char array
   std::strcpy(charDataVariab, buffer);

   // Step 7: Return reference to this object
   return *this;
}

String & String::WriteToConsole()
{
   // Output the string data to the console
   std::cout << "String Name: " << (charDataVariab ? charDataVariab : "null") << std::endl;
   return *this;
}

int String::LessThanOperator(const String& rhs) const
{
   // Return 1 (true) if this string is less than rhs, otherwise return 0 (false)
   return std::strcmp(charDataVariab, rhs.charDataVariab) < 0 ? 1 : 0;
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
   std::cout << "Find with 1 Argument Test Start" << std::endl;
   char *findThis= "l";
   size_t locationFoundIn = myStringClass.Find(findThis);
   // First checks if letter to find is out of range
   if (locationFoundIn > myStringClass.Length() || locationFoundIn <= 0)
   {
      std::cout << findThis << " <- This is not in " << myStringClass.CStr() << std::endl;
      std::cout << "Find with 1 Argument Test Failed" << std::endl;
      std::cout << "----------------------" << std::endl;
   }
   else
         {
            std::cout << "Found " << findThis << " at index " << locationFoundIn << " of Char " << std::endl;
            std::cout << "Find with 1 Argument Test Complete" << std::endl;
            std::cout << "----------------------" << std::endl;
         }

   // removes char from memory.
   --findThis;

   // Finds location of the char character using indexNumber.
   char *charToFindInChar = "x";
   int thisIndexNum = 3;
   locationFoundIn = myStringClass.Find(charToFindInChar);

   std::cout << "Test Ten" << std::endl;
   std::cout << "Find with 2 Arguments Test Start" << std::endl;
   // First checks if index is out of range
   if (thisIndexNum >= myStringClass.Length())
   {
      std::cout << thisIndexNum << " <- This is out of Range" << std::endl;
      std::cout << "Find with 2 Arguments Test Failed" << std::endl;
      std::cout << "----------------------" << std::endl;
   }
   // Second check if the char even exists in the charDataVariab variable.
   else if (locationFoundIn > myStringClass.Length() || locationFoundIn <= 0)
   {
      std::cout << charToFindInChar << " <- This is out of Range" << std::endl;
      std::cout << "Find with 2 Arguments Failed" << std::endl;
      std::cout << "----------------------" << std::endl;
   }
   // Finally gives where its located if it reaches this far.
   else
   {
      std::cout << "Found " << charToFindInChar << " at index " << myStringClass.Find(thisIndexNum,charToFindInChar) << std::endl;
      std::cout << "Find with 2 Arguments Completed" << std::endl;
      std::cout << "----------------------" << std::endl;
   }

   --charToFindInChar;

   // Replaces Char with Another
   std::cout << "Test Eleven" << std::endl;
   std::cout << "Replace Test Start" << std::endl;
   char *replacementChar = "Alex";
   myStringClass.Replace(myStringClass.CStr(), replacementChar);
   myStringClass.WriteToConsole();
   std::cout << "Replace Test Complete" << std::endl;
   std::cout << "----------------------" << std::endl;

   // removes char from memory.
   --replacementChar;

   // Read From Console Test.
   std::cout << "Test Twelve" << std::endl;
   std::cout << "Read From Console Test Start" << std::endl;
   std::cout << "Type the replacement string: ";
   myStringClass.Replace(myStringClass.CStr(), myStringClass.ReadFromConsole());
   std::cout <<"Result Of Replacement: " << myStringClass.CStr() << std::endl;
   std::cout << "Read From Console Test Complete" << std::endl;
   std::cout << "----------------------" << std::endl;

   //Write To Console Test.
   std::cout << "Test Thirteen" << std::endl;
   std::cout << "Write To Console Test Start" << std::endl;
   myStringClass.WriteToConsole();
   std::cout << "Write To Console Test Complete" << std::endl;
   std::cout << "----------------------" << std::endl;

   //Compare current Char to a new Char and Sort it alphabetically.
   std::cout << "Test Fourteen" << std::endl;
   std::cout << "LessThanOperator Test Start" << std::endl;
   if (myStringClass.LessThanOperator("greg"))
   {
      std::cout << myStringClass.CStr() << " comes before greg in the alphabet" << std::endl;
      std::cout << "LessThanOperator Test Complete" << std::endl;
      std::cout << "----------------------" << std::endl;
   }
   else
   {
      std::cout << myStringClass.CStr() << " comes after greg in the alphabet" << std::endl;
      std::cout << "LessThanOperator Test Complete" << std::endl;
      std::cout << "----------------------" << std::endl;
   }

   // This statement is to pause the program
   std::cout << "Press Enter to exit...";
   std::cin.get(); // Wait for user to press Enter

   // Successful end of CPP Script it sets the int main to 0.
   return 0;
}
