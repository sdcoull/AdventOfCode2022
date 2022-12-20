//
//  DayFive.cpp
//  AdventOfCode2022
//
//  Created by Steven Coull on 06/12/2022.
//  https://adventofcode.com/2022/day/5
//

#include <fstream>
#include <iostream>
#include <string>

#include "DayFive.hpp"

using namespace advent_of_code;
using namespace std;

void DayFive::part_one()
{
    string line;
    ifstream input_file("Inputs/Day5.txt");
    std::vector<string> rawColumns;
    for(int i = 0; i < 8; i++)
    {
        getline (input_file, line);
        rawColumns.push_back(line);
    }
    getline (input_file, line);
    getline (input_file, line);

    std::vector<std::vector<char>> columns = parse_input(rawColumns);

    while(getline (input_file, line))
    {
        vector<int> command = parse_command(line);
        for(int i = 0; i < command[0]; i++)
        {
            char c = columns[command[1]].back();
            columns[command[1]].pop_back();
            columns[command[2]].push_back(c);
        }
    }

    input_file.close();

    string crate_output;

    for (auto& column : columns)
    {
        crate_output.push_back(column.back());
    }
    
    cout << "PART ONE: Contain Count: " << crate_output << "\n";
}

void DayFive::part_two()
{
    string line;
    ifstream input_file("Inputs/Day5.txt");
    std::vector<string> rawColumns;
    for(int i = 0; i < 8; i++)
    {
        getline (input_file, line);
        rawColumns.push_back(line);
    }
    getline (input_file, line);
    getline (input_file, line);

    std::vector<std::vector<char>> columns = parse_input(rawColumns);

    while(getline (input_file, line))
    {
        vector<int> command = parse_command(line);
        for(int i = 0; i < command[0]; i++)
        {
            int pop_position = columns[command[1]].size() - (command[0] - i);
            char c = columns[command[1]][pop_position];
            columns[command[1]].erase(columns[command[1]].begin() + pop_position);
            columns[command[2]].push_back(c);
        }
    }

    input_file.close();

    string crate_output;

    for (auto& column : columns)
    {
        crate_output.push_back(column.back());
    }
    
    cout << "PART TWO: Contain Count: " << crate_output << "\n";
}

std::vector<std::vector<char>> DayFive::parse_input(std::vector<std::string> input)
{
    int columnCount = 9; //should do this programmatically!
    std::vector<std::vector<char>> output(columnCount);
    
    for(int i = input.size() - 1; i >= 0; i--)
    {
        for(int j = 0; j < columnCount; j++)
        {
            char c = input[i][1 + j * 4];
            if(c == ' ') continue;
            output[j].push_back(c);
        }
    }
    return output;
}

std::vector<int> DayFive::parse_command(std::string command)
{
    std::vector<int> output(3, 0);
    bool two_digit_move = command[6] != ' ';
    output[0] = stoi(command.substr(5, two_digit_move ? 2 : 1));
    output[1] = command[two_digit_move ? 13 : 12] - '1';
    output[2] = command[two_digit_move ? 18 : 17] - '1';
    return output;
}

