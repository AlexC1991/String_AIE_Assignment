#include <iostream>
#include "String.h"
#include <ctime>
#include "String.cpp"

String &String::CheckingScore()
{
    testingResults testing_results;
    testing_results.baseScore = 40;

    if (testing_results.baseScore >= 50 && testing_results.baseScore < 101)
        std::cout << "Testing Passed" << std::endl;
    else
        std::cout << "Testing Failed" << std::endl;
    return *this;
}

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



int main()
{
    String myStringClass("Alex");

    std::cout << "My Score Results: ";
    myStringClass.CheckingScore();
    myStringClass.PrintingTD();



    std::cout << "Tests Passed: " << "[" << myStringClass.passed << "/14]" << std::endl;
    std::cout << "Tests Failed: " << "[" << myStringClass.failed << "/14]" << std::endl;


    // This statement is to pause the program
    /*std::cout << "Press Enter to exit...";
    std::cin.get(); // Wait for user to press Enter*/

    // Successful end of CPP Script it sets the int main to 0.
    return 0;
}