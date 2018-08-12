#include "Bunco.h"
#include <iostream>
using namespace std;

// 创建新游戏， 初始化所有数值
Bunco::Bunco() {
  mHuman = Player();
  mComputer = Player();
  mRound = 0;
  mBoard = Board();
  humanNum = -1;
  computerNum = -1;
}

// 设置当前游戏轮数
void Bunco::setRound( int round ) {
  mRound = round;
  mHuman.setRound( round );
  mComputer.setRound( round );
  mBoard.setCurrentRound( round );
  humanNum = -1;
  computerNum = -1;
}

// 人类玩家play
int Bunco::humanPlay() {
  mHuman.roll();
  return mHuman.getScore();
}

// 电脑玩家play
int Bunco::computerPlay() {
  mComputer.roll();
  return mComputer.getScore();
}

// 人类玩家play 伪随机数字
int Bunco::humanPlay( int num ) {
  humanNum = mHuman.roll( num );
  updateScore();
  return humanNum;
}

// 电脑玩家play 伪随机数字
int Bunco::computerPlay( int num ) {
  computerNum = mComputer.roll( num );
  updateScore();
  return computerNum;
}

// 更新比分，只在人类电脑双方都已扔过骰子之后触发
void Bunco::updateScore() {
  if ( computerNum == -1 || humanNum == -1 )
    return;

  int won = compareScore();
  if ( won == 1 )
    mBoard.markHumanAsWinner();
  else if ( won == -1 )
    mBoard.markComputerAsWinner();

  computerNum = -1;
  humanNum = -1;
}

// 计算当前比分领先的一方
int Bunco::compareScore() {
  if ( mHuman.getScore() > mComputer.getScore() )
    return 1;
  else if ( mHuman.getScore() < mComputer.getScore() )
    return -1;
  else
    return 0;
}

// 计算证据比赛结果
Bunco::GAMEOUTCOME Bunco::determineGameOutcome() {
  int humanWin = mBoard.countUpHumanRoundWins();
  int computerWin = mBoard.countUpComputerRoundWins();

  if ( humanWin + computerWin < 6 )
    return Bunco::GAMEOUTCOME::GAMENOTOVER;
  else if ( humanWin > computerWin )
    return Bunco::GAMEOUTCOME::HUMANWONGAME;
  else if ( computerWin > humanWin )
    return Bunco::GAMEOUTCOME::COMPUTERWONGAME;
  else
    return Bunco::GAMEOUTCOME::TIEDGAME;
}

// 计算当前轮比赛结果
Bunco::ROUNDOUTCOME Bunco::determineRoundOutcome() {
  int winner = mBoard.getCurrentRoundWinner();
  if ( winner == 1 )
    return Bunco::ROUNDOUTCOME::HUMANWON;
  else if ( winner == -1 )
    return Bunco::ROUNDOUTCOME::COMPUTERWON;
  else
    return Bunco::ROUNDOUTCOME::NOTDECIDED;
}

// 显示？？？ 你们老师没说显示啥，就说call sub method
std::string Bunco::display( std::string msg ) {
  mBoard.display();
}
