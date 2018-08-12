#ifndef BUNCO_H
#define BUNCO_H
#include "Player.h"
#include "Board.h"
#include <string>
#include <iostream>

class Bunco {
  private:
    Player mHuman;
    Player mComputer;
    int mRound;
    Board mBoard;
    int humanNum;
    int computerNum;

  public:
    enum class ROUNDOUTCOME { HUMANWON, COMPUTERWON, NOTDECIDED };
    enum class GAMEOUTCOME { HUMANWONGAME, COMPUTERWONGAME, TIEDGAME, GAMENOTOVER };
    Bunco();
    void setRound( int round );
    int humanPlay();
    int computerPlay();
    int humanPlay( int num );
    int computerPlay( int num );
    int compareScore();
    bool gameIsOver();
    void updateScore();
    ROUNDOUTCOME determineRoundOutcome();
    GAMEOUTCOME determineGameOutcome();
    std::string display( std::string msg = "" );
};

#endif
