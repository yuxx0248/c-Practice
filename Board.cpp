#include "Board.h"
using namespace std;

// 创建平台，初设为第一轮
Board::Board() {
  mRound = 1;
}

// 设置当前轮数
void Board::setCurrentRound( int round ){
  mRound = round;
}

// 设置当前轮，人类获胜
void Board::markHumanAsWinner() {
  mBoardRow[mRound].setHumanAsWinner();
}

// 设置当前轮，电脑获胜
void Board::markComputerAsWinner() {
  mBoardRow[mRound].setComputerAsWinner();
}

// 返回当前轮获胜玩家
int Board::getCurrentRoundWinner() {
  mBoardRow[mRound].getWinner();
}

// 返回当前轮数
int Board::getCurrentRound() {
  return mRound;
}

// 重置当前轮获胜玩家
void Board::unmarkCurrentWinners() {
  mBoardRow[mRound].unmarkWinners();
}

// 统计当前游戏，人类获胜次数
int Board::countUpHumanRoundWins() {
  int count = 0;
  for ( int i=1; i<7; i++ ){
    if ( mBoardRow[i].didHumanWin() )
      count ++;
  }

  return count;
}

// 统计当前游戏，电脑获胜次数
int Board::countUpComputerRoundWins() {
  int count = 0;
  for ( int i=1; i<7; i++ ){
    if ( mBoardRow[i].didComputerWin() )
      count ++;
  }

  return count;
}

std::string Board::display() {
  return mBoardRow[mRound].display();
}
