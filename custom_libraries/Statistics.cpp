#include "Statistics.h"

Statistics :: Statistics() {
    for (int i = 0; i < NUM_HI_SCORES; ++i) highScores[i] = 0;
}

int Statistics :: GetScorePlacing(int score) {
    for (int i = 0; i < NUM_HI_SCORES; ++i) {
        if (score > highScores[i]) return i;
    }

    return -1;
}
void Statistics :: Insert(int score, int place) {
    for (int i = NUM_HI_SCORES - 1; i > place; --i) {
        highScores[i] = highScores[i - 1];
    }

    highScores[place] = score;
}

int Statistics :: getScore(int i) {
    return highScores[i];
}