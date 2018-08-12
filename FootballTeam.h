#include <string>
#ifndef FOOTBALLTEAM_H
#define FOOTBALLTEAM_H

class FootballTeam {
public:
  enum class Conference { AFC, NFC };
  FootballTeam();
  FootballTeam( Conference con, std::string ci, std::string na );
  std::string getCity();
  std::string getName();
  std::string overallRecord();
  std::string roadRecord();
  std::string homeRecord();
  Conference getConference();
  void gameScore( int x, int y, bool b);
  int getHomeWins();
  int getHomeLosses();
  int getHomeTies();
  int getRoadWins();
  int getRoadLosses();
  int getRoadTies();
  int getTotalWins();
  int getTotalLoses();
  int getTotalTies();

private:
  Conference conference;
  std::string city;
  std::string name;
  int homeWin;
  int homeLose;
  int homeEven;
  int roadEven;
  int roadWin;
  int roadLose;
};

#endif
