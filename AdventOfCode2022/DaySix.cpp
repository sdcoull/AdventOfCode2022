//  https://adventofcode.com/2022/day/6

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "DaySix.hpp"

using namespace advent_of_code;
using namespace std;

void DaySix::part_one()
{
    string line;
    ifstream input_file("Inputs/Day6.txt");
    getline (input_file, line);
    input_file.close();

    int marker = -1;
    constexpr int message_size = 4;
    
    for(int i = 0; i < line.size() - message_size; i++)
    {
        string s = line.substr(i, message_size);
        if(is_marker(s))
        {
            marker = i + message_size;
            break;
        }
    }
    
    cout << "PART ONE: Marker: " << marker << "\n";
}

void DaySix::part_two()
{
    string line;
    ifstream input_file("Inputs/Day6.txt");
    getline (input_file, line);
    input_file.close();

    int marker = -1;
    constexpr int message_size = 14;
    
    for(int i = 0; i < line.size() - message_size; i++)
    {
        string s = line.substr(i, message_size);
        if(is_marker(s))
        {
            marker = i + message_size;
            break;
        }
    }
    
    cout << "PART Two: Marker: " << marker << "\n";
}

bool DaySix::is_marker(std::string input)
{
    std::vector<char> characters;

    for (char c : input)
    {
        for (const char character : characters)
        {
            if(character == c)
            {
                return false;
            }
        }
        characters.push_back(c);
    }
    return true;
}

