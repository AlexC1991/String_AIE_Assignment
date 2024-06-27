#include <iostream>
#include "String.h"

#include <string.h>

int main() {
}
String::String() {



    int lengthChar = strlen(name);

    std::cout << "\nMy Name Is: " << name <<"\n"<< "My Name Is This Long: " << lengthChar << "\n\n";
    std::cout << "What is your Name?: ";
    std::cin >> theirName;


    if (strcmp(name, theirName) == 0 ) {
        std::cout <<"That is my name!. Choose another name \n";
    }
    else
        std::cout << "Your Name is " << theirName << "\n";
}

String::String(const char *_str) {
    char name[] = "Alex";
}

String::String(const String &_other) {
    char theirName[20];
}

String::~String() {
    char theirName[20];
}

size_t String::Length() const {
}

char & String::CharacterAt(size_t _index) {
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

String & String::WriteToConsole() {
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
