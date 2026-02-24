#include <vector>
#include <limits>
#include "../players.h"

Play PlayerPlaysAs = Play::X;

bool isFull(const std::vector<Play>& state);
int value(const std::vector<Play>& state);

struct Node{
    std::vector<Play> state;
    bool maxPlays;
    int depth;
    int parentIndex;
    int moveIndex;
};

int bestValue(std::vector<Play>& state,bool maxPlays){
    const int maxDepth = 9;

    std::vector<Node> allNodes;
    std::vector<int> scores;

    allNodes.reserve(362880);
    scores.reserve(362880);

    allNodes.push_back({state,maxPlays,0,-1,-1});
    scores.push_back(0);

    int front = 0;

    while (front < (int)allNodes.size()) {
        int score = value(allNodes[front].state);

        if (score != 0 || isFull(allNodes[front].state) || allNodes[front].depth >= MAX_DEPTH) {
            scores[front] = score;
            front++;
            continue;
        }

        Play currentPlay = allNodes[front].maxPlays ? Play::O : Play::X;

        for (int i = 0; i < 9; i++) {
            if (allNodes[front].state[i] == Play::_) {
                Node child;
                child.state = allNodes[front].state;
                child.state[i] = currentPlay;
                child.maxPlays = !allNodes[front].maxPlays;
                child.depth = allNodes[front].depth + 1;
                child.parentIndex = front;
                child.moveIndex = i;
                allNodes.push_back(child);
                scores.push_back(0);
            }
        }

        front++;
    }

    for (int i = (int)allNodes.size() - 1; i > 0; i--) {
        int parent = allNodes[i].parentIndex;
        if (allNodes[parent].maxPlays) {
            scores[parent] = std::max(scores[parent], scores[i]);
        } else {
            scores[parent] = std::min(scores[parent], scores[i]);
        }
    }

    return scores[0];
}