//  https://adventofcode.com/2022/day/7

#ifndef daySeven_hpp
#define DAY_SEVEN_HPP

#include <string>
#include <vector>

namespace advent_of_code
{
    class File
    {
    public:
        std::string name;
        int size;
        File(std::string n, int s)
        {
            name = n;
            size = s;
        }
    };
    
    class Folder
    {
    public:
        std::string name;
        Folder* parent;
        std::vector<Folder> folders;
        std::vector<File> files;
        int size = 0;
        Folder(std::string n, Folder* p)
        {
            name = n;
            parent = p;
        }
        void calculate_size()
        {
            for (auto& file : files)
            {
                size += file.size;
            }
            for (auto& file : folders)
            {
                size += file.size;
            }
        }
    };
    
    class DaySeven
    {
    public:
        void part_one();
        void part_two();
    private:
        Folder parse_input();
        int count_directories(Folder);
        int smallest_directory(Folder, int, int);
    };
}

#endif /* day_hpp */