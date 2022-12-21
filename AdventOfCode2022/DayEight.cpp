//  https://adventofcode.com/2022/day/8

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "DayEight.hpp"

#include <tuple>

using namespace advent_of_code;
using namespace std;

constexpr int grid_size = 99;

void day_eight::part_one()
{
    vector<vector<int>> trees = parse_input();
    vector<tuple<int, int>> visible_trees;
    
    for(int i = 0; i < grid_size; i++)
    {
        int smallest_tree = -1;
        for(int j = 0; j < grid_size; j++)
        {
            int tree = trees[i][j];
            if(tree > smallest_tree)
            {
                if(!contains_tree(visible_trees, i, j))
                {
                    visible_trees.emplace_back(i, j); 
                }
                
                smallest_tree = tree;
                if(tree == 9)
                {
                    break;
                }
            }
        }
    }

    for(int i = 0; i < grid_size; i++)
    {
        int smallest_tree = -1;
        for(int j = grid_size - 1; j >= 0; j--)
        {
            int tree = trees[i][j];
            if(tree > smallest_tree)
            {
                if(!contains_tree(visible_trees, i, j))
                {
                    visible_trees.emplace_back(i, j); 
                }
                
                smallest_tree = tree;
                if(tree == 9)
                {
                    break;
                }
            }
        }
    }

    for(int i = 0; i < grid_size; i++)
    {
        int smallest_tree = -1;
        for(int j = 0; j < grid_size; j++)
        {
            int tree = trees[j][i];
            if(tree > smallest_tree)
            {
                if(!contains_tree(visible_trees, j, i))
                {
                    visible_trees.emplace_back(j, i); 
                }
                
                smallest_tree = tree;
                if(tree == 9)
                {
                    break;
                }
            }
        }
    }

    for(int i = 0; i < grid_size; i++)
    {
        int smallest_tree = -1;
        for(int j = grid_size - 1; j >= 0; j--)
        {
            int tree = trees[j][i];
            if(tree > smallest_tree)
            {
                if(!contains_tree(visible_trees, j, i))
                {
                    visible_trees.emplace_back(j, i); 
                }
                
                smallest_tree = tree;
                if(tree == 9)
                {
                    break;
                }
            }
        }
    }
    
    cout << "PART ONE: Tree Count: " << visible_trees.size() << "\n";
}

void day_eight::part_two()
{
    vector<vector<int>> trees = parse_input();
    int best_scenic_score = 0;
    for(int i = 1; i < grid_size - 1; i++)
    {
        for(int j = 1; j < grid_size - 1; j++)
        {
            int tree = trees[i][j];
            int left_score = 0;
            int right_score = 0;
            int up_score = 0;
            int down_score = 0;

            for(int x = j + 1; x < grid_size; x++)
            {
                left_score++;
                if(trees[i][x] >= tree)
                {
                    break;
                }
            }

            for(int x = j - 1; x >= 0; x--)
            {
                right_score++;
                if(trees[i][x] >= tree)
                {
                    break;
                }
            }

            for(int x = i + 1; x < grid_size; x++)
            {
                down_score++;
                if(trees[x][j] >= tree)
                {
                    break;
                }
            }

            for(int x = i - 1; x >= 0; x--)
            {
                up_score++;
                if(trees[x][j] >= tree)
                {
                    break;
                }
            }

            int total_score = left_score * right_score * up_score * down_score;
            if(total_score > best_scenic_score)
            {
                best_scenic_score = total_score;
            }
        }
    }
    cout << "PART TWO: Best Score: " << best_scenic_score << "\n";
}

std::vector<std::vector<int>> day_eight::parse_input()
{
    vector<vector<int>> output(grid_size, vector<int>(grid_size));
    string line;
    ifstream input_file("Inputs/Day8.txt");
    for(int i = 0; i < grid_size; i++)
    {
        getline (input_file, line);
        for(int j = 0; j < grid_size; j++)
        {
            output[i][j] = line[j] - '0';
        }
    }
    return output;
}

bool day_eight::contains_tree(std::vector<std::tuple<int, int>> trees, int i, int j)
{
    return std::count(trees.begin(), trees.end(), std::make_tuple(i, j));
}
