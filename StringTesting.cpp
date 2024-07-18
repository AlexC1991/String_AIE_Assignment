#include <iostream>
#include "String.h"
#include <ctime>
#include <cstring>

String &String::PrintingTD()
{
    time_t currentDatenTime = time(0);
    tm *date_Time = localtime(&currentDatenTime);
    char* finalDateTime = asctime(date_Time);
    std::cout << finalDateTime << std::endl;
    --date_Time;
    --finalDateTime;
    return *this;
}

String &String::StringUnitTesting()
{
    String myStringClass("Alex");

    std::cout << "My Score Results: ";
    myStringClass.PrintingTD();

    std::cout << "Tests Passed: " << "[" << myStringClass.passed << "/14]" << std::endl;
    std::cout << "Tests Failed: " << "[" << myStringClass.failed << "/14]" << std::endl;


    // This statement is to pause the program
    /*std::cout << "Press Enter to exit...";
    std::cin.get(); // Wait for user to press Enter*/

    return *this;
}

