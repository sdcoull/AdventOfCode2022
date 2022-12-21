//  https://adventofcode.com/2022/day/7

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "DaySeven.hpp"

using namespace advent_of_code;
using namespace std;

void DaySeven::part_one()
{
    Folder root_folder = parse_input();
    int directory_size_count = count_directories(root_folder);
    cout << "PART ONE: Size Count: " << directory_size_count << "\n";
}

void DaySeven::part_two()
{
    Folder root_folder = parse_input();
    int used_space = 70000000 - root_folder.size;
    int required_space = 30000000 - used_space;
    int smallest = smallest_directory(root_folder, required_space, 30000000);
    cout << "PART ONE: Smallest Directory: " << smallest << "\n";
}

Folder DaySeven::parse_input()
{
    Folder output("/", nullptr);
    Folder* current_folder = &output;
    
    string line;
    ifstream input_file("Inputs/Day7.txt");
    getline (input_file, line);
    while(getline (input_file, line))
    {
        if(line == "$ ls")
        {
            while(getline (input_file, line))
            {
                if(line[0] == '$')
                {
                    break;
                }
                if(line[0] == 'd')
                {
                    (*current_folder).folders.emplace_back(line.substr(4, line.size() - 4), current_folder);
                }
                else
                {
                    string raw_size;
                    int name_index;
                    for(int i = 0; i < line.size(); i++)
                    {
                        if(line[i] == ' ')
                        {
                            name_index = i + 1;
                            break;
                        }
                        raw_size += line[i];
                    }
                    (*current_folder).files.emplace_back(line.substr(name_index, line.size() - name_index), stoi(raw_size));
                }
            }
        }
        if(line.substr(0, 4) == "$ cd")
        {
            string new_dir = line.substr(5, line.size() - 4);

            if(new_dir == "..")
            {
                (*current_folder).calculate_size();
                current_folder = (*current_folder).parent;
            }
            else
            {
                for (auto& folder : (*current_folder).folders)
                {
                    if(folder.name == new_dir)
                    {
                        current_folder = &folder;
                        break;
                    }
                }
            }
        }
    }
    input_file.close();

    while((*current_folder).parent != nullptr)
    {
        (*current_folder).calculate_size();
        current_folder = (*current_folder).parent;
    }
    (*current_folder).calculate_size();
    return output;
}

int DaySeven::count_directories(Folder folder)
{
    int directory_size_count = 0;
    if(folder.size <= 100000)
    {
        directory_size_count = folder.size;
    }

    for (auto& element : folder.folders)
    {
        directory_size_count += count_directories(element);
    }
    
    return directory_size_count;
}

int DaySeven::smallest_directory(Folder folder, int threshold, int current_smallest)
{
    if(folder.size >= threshold && folder.size < current_smallest)
    {
        current_smallest = folder.size;
    }

    for (auto& element : folder.folders)
    {
        current_smallest = smallest_directory(element, threshold, current_smallest);
    }

    return current_smallest;
}

