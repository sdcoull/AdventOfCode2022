//
//  DayFour.cpp
//  AdventOfCode2022
//
//  Created by Steven Coull on 05/12/2022.
//  https://adventofcode.com/2022/day/4
//

#include <fstream>
#include <iostream>
#include <string>
#include <array>

#include "DayFour.hpp"

using namespace advent_of_code;
using namespace std;

void DayFour::part_one()
{
    string line;
    ifstream input_file("Inputs/Day4.txt");
    int containCount = 0;
    while (getline (input_file, line))
    {
        std::array<int, 4> assignments = parse_line(line);
        if(assignments[0] >= assignments[2] && assignments[1] <= assignments[3]
            || assignments[2] >= assignments[0] && assignments[3] <= assignments[1])
        {
            containCount++;
        }
    }
    input_file.close();
    
    cout << "PART ONE: Contain Count: " << containCount << "\n";
}

void DayFour::part_two()
{
    string line;
    ifstream input_file("Inputs/Day4.txt");
    int containCount = 0;
    while (getline (input_file, line))
    {
        std::array<int, 4> assignments = parse_line(line);
        if(assignments[1] >= assignments[2] && assignments[0] <= assignments[3]
            || assignments[3] >= assignments[1] && assignments[2] <= assignments[0])
        {
            containCount++;
        }
    }
    input_file.close();
    
    cout << "PART Two: Contain Count: " << containCount << "\n";
}

std::array<int, 4> DayFour::parse_line(std::string line)
{
    std::array<int, 4> assignments{};
    int index = 0;
    string number;
    for (char c : line)
    {
        if(c == '-' || c == ',')
        {
            assignments[index] = stoi(number);
            index++;
            number = "";
        }
        else
        {
            number += c;
        }
    }
    assignments[index] = stoi(number);
    return assignments;
}

