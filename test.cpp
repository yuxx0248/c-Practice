#include <iostream>
#include <string>
#include <cassert>
using namespace std;
#include "FootballTeam.h"

/**
 return true when the argument f has a better (overall) record than the argument g.
 By "better", I mean the team with more wins.
 If the number of wins are the same, "better" means the team then with fewer losses.
 If the number of wins and losses are the same, "better" means the team with more ties.
 If both teams have identical records, the function should return false.
*/
bool betterRecord( FootballTeam f, FootballTeam g ) {
    if ( f.getTotalWins() > g.getTotalWins()){
      return true;
    } else if ( f.getTotalWins() < g.getTotalWins() ) {
      return false;
    } else {
      if ( f.getTotalLoses() < g.getTotalLoses() ){
        return true;
      } else if (f.getTotalLoses() > g.getTotalLoses()){
        return false;
      } else {
        if ( f.getTotalTies() < g.getTotalTies() ){
          return true;
        } else
          return false;
      }
    }
}

int main(){
  FootballTeam f;
  FootballTeam pats( FootballTeam::Conference::AFC, "Foxboro", "New England Patriots" );

  assert( f.getCity() == "" );
  assert( f.getName() == "" );
  assert( f.getConference() == FootballTeam::Conference::NFC );
  assert( f.overallRecord() == "0 - 0 - 0" );
  assert( f.roadRecord() == "0 - 0 - 0" );
  assert( f.homeRecord() == "0 - 0 - 0" );

  pats.gameScore( 20, 3, true );
  pats.gameScore( 20, 40, true );
  pats.gameScore( 20, 3, false );
  pats.gameScore( 20, 40, false );
  pats.gameScore( 20, 20, true );
  assert( pats.overallRecord() == "2 - 2 - 1" );
  assert( pats.roadRecord() == "1 - 1 - 0" );
  assert( pats.homeRecord() == "1 - 1 - 1" );

  assert( pats.getHomeWins() == 1 );
  assert( pats.getHomeLosses() == 1 );
  assert( pats.getHomeTies() == 1 );
  assert( pats.getRoadWins() == 1 );
  assert( pats.getRoadLosses() == 1 );
  assert( pats.getRoadTies() == 0 );

  assert( betterRecord( pats, f ) == true );
  assert( betterRecord( f, pats ) == false );
  assert( betterRecord( pats, pats ) == false );
  assert( betterRecord( f, f ) == false );

  return 0;
}
