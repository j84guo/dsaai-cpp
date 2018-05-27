#ifndef GAME_ENTRY_H
#define GAME_ENTRY_H

#include <string>
#include <iostream>

using std::endl;
using std::cout;
using std::string;
using std::ostream;

class GameEntry{

public:
  GameEntry(const string &n="", int s=0);
  string getName() const;
  int getScore() const;
  friend ostream& operator<<(ostream& out, const GameEntry& e);

private:
  string name;
  int score;

};

#endif
