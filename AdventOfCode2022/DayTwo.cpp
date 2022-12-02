//
//  DayTwo.cpp
//  AdventOfCode2022
//
//  Created by Steven Coull on 02/12/2022.
//  https://adventofcode.com/2022/day/2
//

#include <fstream>
#include <iostream>
#include <string>

#include "DayTwo.hpp"

using namespace advent_of_code;
using namespace std;

void DayTwo::part_one()
{
    string line;
    ifstream input_file("Inputs/Day2.txt");
    int score = 0;
    while (getline (input_file, line)) {
        Play opp_play = parse_input_to_play(line[0]);
        Play your_play = parse_input_to_play(line[2]);
        score += calculate_outcome_score(opp_play, your_play) + play_score(your_play);
    }
    input_file.close();
    
    cout << "PART ONE: Score: " << score << "\n";
}

void DayTwo::part_two()
{
    string line;
    ifstream input_file("Inputs/Day2.txt");
    int score = 0;
    while (getline (input_file, line)) {
        Play opp_play = parse_input_to_play(line[0]);
        Play your_play = parse_strategy(opp_play, line[2]);
        score += calculate_outcome_score(opp_play, your_play) + play_score(your_play);
    }
    input_file.close();
    
    cout << "PART Two: Score: " << score << "\n";
}

DayTwo::Play DayTwo::parse_input_to_play(char input)
{
    if(input == 'A' || input == 'X') return rock;
    if(input == 'B' || input == 'Y') return paper;
    return scissors;
}

DayTwo::Play DayTwo::parse_strategy(Play opp_play, char input)
{
    if(input == 'Y') return opp_play;
    bool win = input == 'Z';
    if(opp_play == rock) return win ? paper : scissors;
    if(opp_play == paper) return win ? scissors : rock;
    return win ? rock : paper;
}

int DayTwo::calculate_outcome_score(Play opp_play, Play your_play)
{
    if(opp_play == your_play)
    {
        return 3;
    }
    if(opp_play == rock && your_play == paper ||
        opp_play == paper && your_play == scissors ||
        opp_play == scissors && your_play == rock)
    {
        return 6;
    }
    return 0;
}

int DayTwo::play_score(Play play)
{
    if(play == rock) return 1;
    if(play == paper) return 2;
    return 3;
}
