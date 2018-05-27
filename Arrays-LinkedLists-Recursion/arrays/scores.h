#ifndef SCORES_H
#define SCORES_H

#include <iostream>
#include "game_entry.h"

using std::endl;
using std::cout;
using std::runtime_error;

class Scores{

public:
  Scores(int maxEnt=10);
  ~Scores();
  void add(const GameEntry& e);
  GameEntry remove(int i) throw(runtime_error);
  int size() const;
  int capacity() const;
  friend ostream& operator<<(ostream& out, const Scores& s);

private:
  int maxEntries;
  int numEntries;
  GameEntry *entries;

};

#endif
