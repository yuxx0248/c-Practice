#ifndef BOARD_H
#define BOARD_H
#include "BoardRow.h"
#include <string>

class Board {
  private:
    int mRound;
    BoardRow mBoardRow[7];

  public:
    Board();
    void setCurrentRound( int round );
    void markHumanAsWinner();
    void markComputerAsWinner();
    int countUpHumanRoundWins();
    int countUpComputerRoundWins();
    int getCurrentRoundWinner();
    int getCurrentRound();
    void unmarkCurrentWinners();
    std::string display();
};

#endif
