//
//  DayOne.cpp
//  AdventOfCode2022
//
//  Created by Steven Coull on 01/12/2022.
//  https://adventofcode.com/2022/day/1
//

#include <fstream>
#include <iostream>
#include <string>

#include "DayOne.hpp"

using namespace advent_of_code;
using namespace std;

void DayOne::partOne()
{
    string my_text;
    ifstream my_read_file("Inputs/Day1.txt");
    int largestCalories = 0;
    int currentCalories = 0;
    while (getline (my_read_file, my_text)) {
        if(my_text.empty())
        {
            if(currentCalories > largestCalories)
            {
                largestCalories = currentCalories;
            }
            currentCalories = 0;
        }
        else
        {
            currentCalories += stoi(my_text);
        }
    }
    my_read_file.close();
    
    cout << "PART ONE: Most Calories: " << largestCalories << "\n";
}

void DayOne::partTwo()
{
    string my_text;
    ifstream my_read_file("Inputs/Day1.txt");
    int topCalories[] = {0, 0, 0};
    int currentCalories = 0;
    while (getline (my_read_file, my_text)) {
        if(my_text.empty())
        {
            int smallestIndex = 0;
            for(int i = 1; i < sizeof(topCalories) / sizeof(int); i++)
            {
                if(topCalories[i] < topCalories[smallestIndex])
                {
                    smallestIndex = i;
                }
            }

            if(topCalories[smallestIndex] < currentCalories)
            {
                topCalories[smallestIndex] = currentCalories;
            }
            
            currentCalories = 0;
        }
        else
        {
            currentCalories += stoi(my_text);
        }
    }
    my_read_file.close();

    int allCalories = 0;
    for(int i : topCalories)
    {
        allCalories += i;
    }
    
    cout << "PART TWO: Top 3 Calories: " << allCalories << "\n";
}
