#ifndef BOARDROW_H
#define BOARDROW_H
#include <string>

class BoardRow {
  private:
    bool mHumanWinner;
    bool mComputerWinner;
    bool mCurrentRound;
    int mRound;

  public:
    BoardRow();
    void setHumanAsWinner();
    void setComputerAsWinner();
    void setRound( int round );
    void setCurrentRound( bool b );
    bool didComputerWin();
    bool didHumanWin();
    int getWinner();
    void unmarkWinners();
    std::string display();
};

#endif
