#include "Player.h"
#include "Die.h"

// 创建一个新的玩家， 给这个玩家创建一个新的骰子，同时设他现在的得分为零
Player::Player() {
  mDie = Die();
  mScore = 0;
  mRound = 1;
}

// 设置当前回合数，重置玩家目前的得分。（不知道为什么要重置，不重置过不了你老师的test）
void Player::setRound( int round ) {
  mRound = round;
  mScore = 0;
}

// 返回玩家当前得分
int Player::getScore() {
  return mScore;
}

// 扔骰子， 如果骰子值等于当前回合数，得分+1
int Player::roll() {
  mDie.roll();

  if ( mRound == mDie.getValue() ){
    mScore ++;
  }

  return mDie.getValue();
}

// 假扔骰子，用于测试。 骰子值为输入值
int Player::roll( int num ) {
  if ( mRound == num ){
    mScore ++;
  }

  return num;
}
