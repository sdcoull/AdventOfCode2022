//
//  main.cpp
//  AdventOfCode2022
//
//  Created by Steven Coull on 01/12/2022.
//  https://adventofcode.com/
//

#include <iostream>

#include "DayOne.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    cout << "Advent Of Code 2022: Starting...\n";

    advent_of_code::DayOne day;
    day.partOne();
    day.partTwo();
    
    return 0;
}
