//  https://adventofcode.com/2022/day/10

#include <fstream>
#include <iostream>
#include <string>

#include "DayTen.hpp"

using namespace advent_of_code;
using namespace std;

void day_ten::part_one()
{
    string line;
    ifstream input_file("Inputs/Day10.txt");

    int cycle_count = 0;
    int signal_strength = 1;
    int total_signal_strength = 0;
    
    while(getline (input_file, line))
    {
        const bool add_command = line.substr(0, 4) == "addx";
        const int add_amount = add_command ? stoi(line.substr(5, line.size() - 5)) : 0;

        for(int i = 0; i < (add_command ? 2 : 1); i++)
        {
            cycle_count++;
            if(cycle_count == 20 || cycle_count == 60 || cycle_count == 100 ||
                cycle_count == 140 || cycle_count == 180 || cycle_count == 220)
            {
                total_signal_strength += cycle_count * signal_strength;
            }
        }

        if(add_command)
        {
            signal_strength += add_amount;
        }
    }
    cout << "PART ONE: Signal Strength: " << total_signal_strength << "\n";
}

void day_ten::part_two()
{
    string line;
    ifstream input_file("Inputs/Day10.txt");

    int cycle_count = 0;
    int sprite_position = 1;

    cout << "PART TWO:\n";
    
    while(getline (input_file, line))
    {
        const bool add_command = line.substr(0, 4) == "addx";
        const int add_amount = add_command ? stoi(line.substr(5, line.size() - 5)) : 0;

        for(int i = 0; i < (add_command ? 2 : 1); i++)
        {
            if(cycle_count == sprite_position ||
                cycle_count == sprite_position - 1 ||
                cycle_count == sprite_position + 1)
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }

            cycle_count++;
            
            if(cycle_count == 40 || cycle_count == 80 || cycle_count == 120 ||
                cycle_count == 160 || cycle_count == 200 || cycle_count == 240)
            {
                cout << "\n";
                cycle_count = 0;
            }
        }

        if(add_command)
        {
            sprite_position += add_amount;
        }
    }
}