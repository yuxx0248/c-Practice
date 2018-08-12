#include "BoardRow.h"

// 创建游戏的新一轮
BoardRow::BoardRow() {
  mHumanWinner = false;
  mComputerWinner = false;
  mRound = 0;
  mCurrentRound = false;
}

// 设人类获胜
void BoardRow::setHumanAsWinner() {
  mHumanWinner = true;
}

// 设电脑获胜
void BoardRow::setComputerAsWinner() {
  mComputerWinner = true;
}

// 返回人类是否获胜
bool BoardRow::didHumanWin() {
  return mHumanWinner;
}

// 返回电脑是否获胜
bool BoardRow::didComputerWin() {
  return mComputerWinner;
}

// 设置当前轮为第几轮
void BoardRow::setRound( int round ) {
  mRound = round;
}

// ？？？
void BoardRow::setCurrentRound( bool b ){

}

// 返回获胜玩家， 人类 -> 1， 电脑 -> -1， 其他 -> 0
int BoardRow::getWinner() {
  if ( mHumanWinner && !mComputerWinner )
    return 1;
  else if ( mComputerWinner && !mHumanWinner )
    return -1;
  else
    return 0;
}

// 重置当前获胜玩家
void BoardRow::unmarkWinners() {
  mHumanWinner = false;
  mComputerWinner = false;
}

std::string BoardRow::display() {
  return "";
}
