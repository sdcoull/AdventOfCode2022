//  https://adventofcode.com/2022/day/9

#ifndef DAY_NINE_HPP
#define DAY_NINE_HPP

#include <string>
#include <vector>

namespace advent_of_code
{
    class node
    {
    public:
        int x = 0;
        int y = 0;
        std::string name() const
        {
            return std::to_string(x) + std::to_string(y);
        }
    };
    
    class day_nine
    {
    public:
        void part_one();
        void part_two();
    private:
        std::vector<node> move_rope(std::vector<node>, char);
        bool contains_node(std::vector<std::tuple<int, int>>, node);
    };
}

#endif /* day_hpp */