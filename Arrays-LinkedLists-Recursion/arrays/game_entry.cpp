#include "game_entry.h"

GameEntry::GameEntry(const string &n, int s):
  name(n),
  score(s){
}

// todo : how to return variables as const and/or as references
string GameEntry::getName() const{
  return name;
}

int GameEntry::getScore() const{
  return score;
}

ostream& operator<<(ostream &out, const GameEntry &e){
  cout << e.name << " : " << e.score << endl;
  return out;
}
