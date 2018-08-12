#include <iostream>
#include <string>
#include <cassert>
#include "Die.h"
#include "Player.h"
#include "Board.h"
#include "Bunco.h"

int main() {
  using namespace std;

  Die d;
  for (int i = 1; i <= 100; i++)
  {
      d.roll();
      int value = d.getValue();
      assert( value >=1 && value <= 6 );
  }

  Player p;
  assert( p.getScore() == 0 );
  p.setRound( 1 );
  assert( p.getScore() == 0 );
  assert( p.roll( 6 ) == 6 );
  assert( p.getScore() == 0 );
  assert( p.roll( 5 ) == 5 );
  assert( p.getScore() == 0 );
  assert( p.roll( 1 ) == 1);
  assert( p.getScore() == 1 );
  p.setRound( 6 );
  assert( p.getScore() == 0 );
  assert( p.roll( 6 ) == 6 );
  assert( p.getScore() == 1 );

  Board board;
  //Test setting rounds
  board.setCurrentRound( 1 );
  assert( board.getCurrentRound() == 1 );
  board.setCurrentRound( 5 );
  assert( board.getCurrentRound() == 5 );

  //Test setting winners
  board.markHumanAsWinner();
  assert( board.getCurrentRoundWinner() == 1 );
  board.unmarkCurrentWinners();
  board.markComputerAsWinner();
  assert( board.getCurrentRoundWinner() == -1);
  board.markHumanAsWinner();
  assert( board.getCurrentRoundWinner() == 0 );

  //Test win countUpHumanRoundWins
  Board board2;
  board2.setCurrentRound( 1 );
  board2.markHumanAsWinner();
  board2.setCurrentRound( 2 );
  board2.markComputerAsWinner();
  board2.setCurrentRound( 3 );
  board2.markHumanAsWinner();
  board2.setCurrentRound( 4 );
  board2.markComputerAsWinner();
  board2.setCurrentRound( 5 );
  board2.markComputerAsWinner();
  board2.setCurrentRound( 6 );
  board2.markComputerAsWinner();

  assert( board2.countUpHumanRoundWins() == 2 );
  assert( board2.countUpComputerRoundWins() == 4);

  Bunco b;
  b.setRound( 1 );
  assert( b.determineRoundOutcome() == Bunco::ROUNDOUTCOME::NOTDECIDED );
  b.computerPlay( 5 );
  b.humanPlay( 5 );
  assert( b.determineRoundOutcome() == Bunco::ROUNDOUTCOME::NOTDECIDED );
  b.computerPlay( 1 );
  b.humanPlay( 1 );
  assert( b.determineRoundOutcome() == Bunco::ROUNDOUTCOME::NOTDECIDED );
  b.computerPlay( 1 );
  b.humanPlay( 2 );
  assert( b.determineRoundOutcome() == Bunco::ROUNDOUTCOME::COMPUTERWON );

  //Test GameOutcome human -> 1, comp -> 2
  Bunco game;
  game.setRound( 1 );
  game.computerPlay( 2 );
  game.humanPlay( 1 );
  game.setRound( 2 );
  game.computerPlay( 2 );
  game.humanPlay( 1 );
  game.setRound( 3 );
  game.computerPlay( 3 );
  game.humanPlay( 1 );
  game.setRound( 4 );
  game.computerPlay( 4 );
  game.humanPlay( 1 );
  game.setRound( 5 );
  game.computerPlay( 3 );
  game.humanPlay( 5 );
  assert( game.determineGameOutcome() == Bunco::GAMEOUTCOME::GAMENOTOVER );
  game.setRound( 6 );
  game.computerPlay( 5 );
  game.humanPlay( 6 );
  assert( game.determineGameOutcome() == Bunco::GAMEOUTCOME::TIEDGAME );
  game.setRound( 6 );
  game.computerPlay( 6 );
  game.humanPlay( 1 );
  assert( game.determineGameOutcome() == Bunco::GAMEOUTCOME::COMPUTERWONGAME );
  game.setRound( 6 );
  game.computerPlay( 5 );
  game.humanPlay( 6 );
  game.setRound( 3 );
  game.computerPlay( 1 );
  game.humanPlay( 3 );
  game.setRound( 2 );
  game.computerPlay( 1 );
  game.humanPlay( 2 );
  assert( game.determineGameOutcome() == Bunco::GAMEOUTCOME::HUMANWONGAME );

  return 0;
}
