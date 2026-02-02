#include <vector>
#include <limits>
#include "players.h"

Play PlayerPlaysAs = Play::X;

bool isFull(const std::vector<Play>& state);
int value(const std::vector<Play>& state);

int bestValue(std::vector<Play>& state,bool maxPlays){
    // get cases 
    // calc value
    // 
}