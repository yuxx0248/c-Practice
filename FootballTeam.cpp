#include <string>
#include <iostream>
using namespace std;
#include "FootballTeam.h"

FootballTeam::FootballTeam (){
  conference = FootballTeam::Conference::NFC;
  homeWin = 0;
  homeLose = 0;
  roadWin = 0;
  roadLose = 0;
  roadEven = 0;
  homeEven = 0;
}

FootballTeam::FootballTeam (Conference con, string ci, string na){
  conference = con;
  city = ci;
  name = na;
  homeWin = 0;
  homeLose = 0;
  roadWin = 0;
  roadLose = 0;
  roadEven = 0;
  homeEven = 0;
}

string FootballTeam::getCity (){
  return city;
}

string FootballTeam::getName() {
  return name;
}

string FootballTeam::overallRecord() {
  std::string rtn;
  rtn += std::to_string(roadWin + homeWin);
  rtn += " - ";
  rtn += std::to_string(roadLose + homeLose);
  rtn += " - ";
  rtn += std::to_string(roadEven+homeEven);

  return rtn;
}

string FootballTeam::roadRecord() {
  std::string rtn;
  rtn += std::to_string(roadWin);
  rtn += " - ";
  rtn += std::to_string(roadLose);
  rtn += " - ";
  rtn += std::to_string(roadEven);

  return rtn;
}

string FootballTeam::homeRecord() {
  std::string rtn;
  rtn += std::to_string(homeWin);
  rtn += " - ";
  rtn += std::to_string(homeLose);
  rtn += " - ";
  rtn += std::to_string(homeEven);

  return rtn;
}

FootballTeam::Conference FootballTeam::getConference() {
  return conference;
}

void FootballTeam::gameScore( int x, int y, bool b) {
  if(b){
    if ( x == y ){
      homeEven++;
    }else if ( x > y ) {
      homeWin++;
    }else{
      homeLose++;
    }
  }else{
    if (x == y){
      roadEven++;
    }else if (x > y) {
      roadWin++;
    }else{
      roadLose++;
    }
  }
}

int FootballTeam::getHomeWins(){
  return homeWin;
}

int FootballTeam::getHomeLosses() {
  return homeLose;
}

int FootballTeam::getHomeTies() {
  return homeEven;
}

int FootballTeam::getRoadWins() {
  return roadWin;
}

int FootballTeam::getRoadLosses() {
  return roadLose;
}

int FootballTeam::getRoadTies() {
  return roadEven;
}

int FootballTeam::getTotalWins(){
  return homeWin + roadWin;
}

int FootballTeam::getTotalLoses(){
  return homeLose + roadLose;
}

int FootballTeam::getTotalTies(){
  return homeEven + roadEven;
}
