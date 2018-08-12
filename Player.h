#ifndef PLAYER_H
#define PLAYER_H
#include "Die.h"

class Player {
  private:
    Die mDie;
    int mScore;
    int mRound;

  public:
    Player();
    int roll( int num );
    int roll();
    void setRound ( int round );
    int getScore ();
};

#endif
