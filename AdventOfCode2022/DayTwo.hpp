//
//  DayTwo.hpp
//  AdventOfCode2022
//
//  Created by Steven Coull on 02/12/2022.
//  https://adventofcode.com/2022/day/2
//

#ifndef dayTwO_hpp
#define DAY_TWO_HPP

namespace advent_of_code
{
    class DayTwo
    {
        enum Play { rock, paper, scissors };
        public:
            void part_one();
            void part_two();
        private:
            Play parse_input_to_play(char input);
            int calculate_outcome_score(Play opp_play, Play your_play);
            int play_score(Play play);
            Play parse_strategy(Play opp_play, char input);
    };

}

#endif /* day_hpp */
