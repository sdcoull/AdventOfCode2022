//
//  DayThree.cpp
//  AdventOfCode2022
//
//  Created by Steven Coull on 05/12/2022.
//  https://adventofcode.com/2022/day/3
//

#include <fstream>
#include <iostream>
#include <string>

#include "DayThree.hpp"

#include <vector>

using namespace advent_of_code;
using namespace std;

void DayThree::part_one()
{
    string line;
    ifstream input_file("Inputs/Day3.txt");
    int priorityCount = 0;
    while (getline (input_file, line)) {
        std::vector<char> firstCompartment;
        std::vector<char> secondCompartment;
        int compartmentLength = line.size() / 2;
        for(int i = 0; i < line.size(); i++)
        {
            char c = line[i];
            if(i < compartmentLength)
            {
                firstCompartment.push_back(c);
            }
            else if(std::find(firstCompartment.begin(), firstCompartment.end(), c) != firstCompartment.end())
            {
                if(std::find(secondCompartment.begin(), secondCompartment.end(), c) != secondCompartment.end())
                {
                    continue;
                }
                int asciiCode = c;
                if(asciiCode > 90)
                {
                    priorityCount += asciiCode - 96;
                }
                else
                {
                    priorityCount += asciiCode - 38;
                }
                secondCompartment.push_back(c);
            }
        }
    }
    input_file.close();
    
    cout << "PART ONE: Priority Count: " << priorityCount << "\n";
}

void DayThree::part_two()
{
    string line;
    ifstream input_file("Inputs/Day3.txt");
    int priorityCount = 0;
    while (getline (input_file, line)) {
        std::vector<char> firstCompartment;
        std::vector<char> secondCompartment;
        for(int i = 0; i < 3; i++)
        {
            if(i != 0)
            {
                getline (input_file, line);
            }
            
            for(int j = 0; j < line.size(); j++)
            {
                char c = line[j];
                if(i == 0)
                {
                    firstCompartment.push_back(c);
                }
                else if(i == 1 && std::find(firstCompartment.begin(), firstCompartment.end(), c) != firstCompartment.end())
                {
                    secondCompartment.push_back(c);
                }
                else if(i == 2 && std::find(secondCompartment.begin(), secondCompartment.end(), c) != secondCompartment.end())
                {
                    int asciiCode = c;
                    if(asciiCode > 90)
                    {
                        priorityCount += asciiCode - 96;
                    }
                    else
                    {
                        priorityCount += asciiCode - 38;
                    }
                    break;
                }
            }
            
        }
    }
    input_file.close();
    
    cout << "PART Two: Priority Count: " << priorityCount << "\n";
}
