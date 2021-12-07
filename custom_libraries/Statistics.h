#ifndef STATISTICS_H
#define STATISTICS_H

#define NUM_HI_SCORES 5
#define STATS_STR_SIZE ((LCD_WIDTH)/(CHAR_WIDTH))

class Statistics {
    private:
        int highScores[NUM_HI_SCORES];
    public:
        Statistics();
        int GetScorePlacing(int score);
        void Insert(int score, int place);
        int getScore(int i);

};

#endif