#include <iostream>
#include "String.h"
#include <cstring>

#include <string.h>

String::String() : charDataVariab(nullptr), length(0)
{
   std::cout << "String Name: " << (charDataVariab ? charDataVariab : "null") << std::endl;
}

String::String(const char *_str)
{
   length = std::strlen(_str);
   charDataVariab = new char[length + 1];
   std::strcpy(charDataVariab, _str);
}

String::String(const String &_other) {

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

const char & String::CharacterAt(size_t _index) const {
}

bool String::EqualTo(const String &_other) const {
}

String & String::Append(const String &_str) {
}

String & String::Prepend(const String &_str) {
}

const char * String::CStr() const {
}

String & String::ToLower() {
}

String & String::ToUpper() {
}

size_t String::Find(const String &_str) {
}

size_t String::Find(size_t _startIndex, const String &_str) {
}

String & String::Replace(const String &_find, const String &_replace) {
}

String & String::ReadFromConsole() {
}

String & String::WriteToConsole()
{
   std::cout << charDataVariab << std::endl;
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
   String myStringClass("Alex");
   myStringClass.WriteToConsole();

   std::cout << "Char Length: " << myStringClass.Length() << std::endl;
   std::cout << "Char Length Test Complete" << std::endl;

   try {
      char& ch = myStringClass.CharacterAt(1);
      std::cout << "Character at index 1: " << ch << std::endl;
   } catch (const std::out_of_range& e) {
      std::cerr << e.what() << std::endl;
   }

   return 0;
}
