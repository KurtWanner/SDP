#include "Statistics.h"

/* Made by Hunter */
/* Initializes stats class */
Statistics :: Statistics() {
    for (int i = 0; i < NUM_HI_SCORES; ++i) highScores[i] = 0;
}

/* Made by Hunter */
/* Compares score argument to highscores and determines where it should go in the score placing */
/* Returns -1 if the score isn't good enough */
int Statistics :: GetScorePlacing(int score) {
    for (int i = 0; i < NUM_HI_SCORES; ++i) {
        if (score > highScores[i]) return i;
    }

    return -1;
}

/* Made by Hunter */
/* Inserts a score into the highscore list */
void Statistics :: Insert(int score, int place) {
    for (int i = NUM_HI_SCORES - 1; i > place; --i) {
        highScores[i] = highScores[i - 1];
    }

    highScores[place] = score;
}

/* Made by Hunter */
/* Gets a score from the high score list */
int Statistics :: getScore(int i) {
    return highScores[i];
}