//
//  DayFive.hpp
//  AdventOfCode2022
//
//  Created by Steven Coull on 06/12/2022.
//  https://adventofcode.com/2022/day/5
//

#ifndef dayFive_hpp
#define DAY_FIVE_HPP
#include <vector>

namespace advent_of_code
{
    class DayFive
    {
        public:
            void part_one();
            void part_two();
    private:
        std::vector<std::vector<char>> parse_input(std::vector<std::string>);
        std::vector<int> parse_command(std::string);
    };

}

#endif /* day_hpp */
