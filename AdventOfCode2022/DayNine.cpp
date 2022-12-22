//  https://adventofcode.com/2022/day/9

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <tuple>

#include "DayNine.hpp"

using namespace advent_of_code;
using namespace std;

constexpr int grid_size = 99;

void day_nine::part_one()
{
    string line;
    ifstream input_file("Inputs/Day9.txt");
    vector<tuple<int, int>> visited_nodes {tuple<int, int>{0, 0}};
    
    std::vector<node> rope(2);
    
    while(getline (input_file, line))
    {
        const char direction = line[0];
        const int move_amount = stoi(line.substr(2, line.size() - 2));
        for(int i = 0; i < move_amount; i++)
        {
            rope = move_rope(rope, direction);
            node tail = rope[rope.size() - 1];
            if(!contains_node(visited_nodes, tail))
            {
                visited_nodes.emplace_back(tail.x, tail.y);
            }
        }
    }
    cout << "PART ONE: Visit Count: " << visited_nodes.size() << "\n";
}

void day_nine::part_two()
{
    string line;
    ifstream input_file("Inputs/Day9.txt");
    vector<tuple<int, int>> visited_nodes {tuple<int, int>{0, 0}};

    std::vector<node> rope(10);
    
    while(getline (input_file, line))
    {
        const char direction = line[0];
        const int move_amount = stoi(line.substr(2, line.size() - 2));
        for(int i = 0; i < move_amount; i++)
        {
            rope = move_rope(rope, direction);
            node tail = rope[rope.size() - 1];
            if(!contains_node(visited_nodes, tail))
            {
                visited_nodes.emplace_back(tail.x, tail.y);
            }
        }
    }
    cout << "PART TWO: Visit Count: " << visited_nodes.size() << "\n";
}

std::vector<node> day_nine::move_rope(std::vector<node> rope, const char direction)
{
    if(direction == 'U')
    {
        rope[0].y++;
    }
    else if(direction == 'D')
    {
        rope[0].y--;
    }
    else if(direction == 'L')
    {
        rope[0].x--;
    }
    else if(direction == 'R')
    {
        rope[0].x++;
    }
    
    for(int i = 1; i < rope.size(); i++)
    {
        const node moved = rope[i - 1];
        node* next_node = &rope[i];

        const bool horizontal_part = std::abs((*next_node).x - moved.x) > 1;
        const bool vertical_apart = std::abs((*next_node).y - moved.y) > 1;
        if(horizontal_part && vertical_apart)
        {
            (*next_node).x = moved.x + ((*next_node).x > moved.x ? 1 : -1);
            (*next_node).y = moved.y + ((*next_node).y > moved.y ? 1 : -1);
        }
        else
        {
            if(horizontal_part)
            {
                if((*next_node).y != moved.y)
                {
                    (*next_node).y = moved.y;
                }
                (*next_node).x = moved.x + ((*next_node).x > moved.x ? 1 : -1);
            }
            if(vertical_apart)
            {
                if((*next_node).x != moved.x)
                {
                    (*next_node).x = moved.x;
                }
                (*next_node).y = moved.y + ((*next_node).y > moved.y ? 1 : -1);
            }
        }
    }
    return rope;
}

bool day_nine::contains_node(std::vector<std::tuple<int, int>> nodes, node node)
{
    return std::count(nodes.begin(), nodes.end(), std::make_tuple(node.x, node.y));
}
