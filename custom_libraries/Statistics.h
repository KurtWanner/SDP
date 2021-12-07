#ifndef STATISTICS_H
#define STATISTICS_H

#define NUM_HI_SCORES 5
#define STATS_STR_SIZE ((LCD_WIDTH)/(CHAR_WIDTH))

/* Made by Hunter */
class Statistics {
    private:
        int highScores[NUM_HI_SCORES];
    public:
        // Initializes stats class
        Statistics();
        
        // Compares score argument to highscores and determines where it should go in the score placing
        // Returns -1 if the score isn't good enough
        int GetScorePlacing(int score);
        
        // Inserts a score into the highscore list
        void Insert(int score, int place);

        // Gets a score from the high score list
        int getScore(int i);

};

#endif