//
//  DayFour.hpp
//  AdventOfCode2022
//
//  Created by Steven Coull on 05/12/2022.
//  https://adventofcode.com/2022/day/4
//

#ifndef dayFour_hpp
#define DAY_FOUR_HPP

namespace advent_of_code
{
    class DayFour
    {
        public:
            void part_one();
            void part_two();
        private:
            std::array<int, 4> parse_line(std::string);
    };

}

#endif /* day_hpp */
