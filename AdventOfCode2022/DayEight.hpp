//  https://adventofcode.com/2022/day/8

#ifndef DAY_EIGHT_HPP
#define DAY_EIGHT_HPP

#include <vector>

namespace advent_of_code
{
    class day_eight
    {
    public:
        void part_one();
        void part_two();
    private:
        std::vector<std::vector<int>> parse_input();
        bool contains_tree(std::vector<std::tuple<int, int>>, int, int);
    };
}

#endif /* day_hpp */