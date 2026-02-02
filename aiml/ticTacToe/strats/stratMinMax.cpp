#include <vector>
#include <limits>
#include "players.h"

Play PlayerPlaysAs = Play::X;

bool isFull(const std::vector<Play>& state);
int value(const std::vector<Play>& state);

int bestValue(std::vector<Play>& state,bool maxPlays){
    int score = value(state);
    if (score != 0) return score;
    if (isFull(state)) return 0;

    if (maxPlays){
        int maxVal = std::numeric_limits<int>::min();
        for (int i=0; i<9; i++) {
            if (state[i] == Play::_){
                state[i] = Play::O;
                maxVal = std::max(maxVal , bestValue(state,false));
                state[i] = Play::_;
            }
        }
        return maxVal;
    } else {
        int minVal = std::numeric_limits<int>::max();
        for (int i=0; i<9; i++) {
            if (state[i] == Play::_){
                state[i] = Play::X;
                minVal = std::min(minVal , bestValue(state,true));
                state[i] = Play::_;
            }
        }
        return minVal;
    }
}

