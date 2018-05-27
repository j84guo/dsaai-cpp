#include "scores.h"

Scores::Scores(int maxEnt){
  maxEntries = maxEnt;
  entries = new GameEntry[maxEntries];
  numEntries = 0;
}

Scores::~Scores(){
  delete[] entries;
}

void Scores::add(const GameEntry &e){
  int newScore = e.getScore();
  if(numEntries == maxEntries && newScore <= entries[numEntries-1].getScore()){
    return;
  }

  /*
  * start at numEntries-2 when numEntries == maxEntries since we know we can overwrite the last element
  * when numEntries < maxEntries we start at numEntries-1 because we have room to keep all entries
  * if necessary, shift elements to the right to make room, then decrement i
  * when we've stopped looping, the index to insert at is one greater than the current i
  */
  int i = numEntries == maxEntries ? numEntries - 2 : numEntries - 1;
  while(i >= 0 && entries[i].getScore() < newScore){
    entries[i+1] = entries[i];
    --i;
  }

  entries[i+1] = e;

  if(numEntries < maxEntries){
    ++numEntries;
  }
}

/*
* it is not the responsibility of the scores class to delete entry objects
* also, it seems these objects are only allocated on the stack anyways
*/
GameEntry Scores::remove(int i) throw(runtime_error){
  if(i < 0 || i >= maxEntries){
    throw runtime_error("Index out of bounds.");
  }

  GameEntry e = entries[i];
  for(int j=i+1; j<numEntries; ++j){
    entries[j-1] = entries[j];
  }

  --numEntries;
  return e;
}

// returning by value
int Scores::size() const{
  return numEntries;
}

// returning by value
int Scores::capacity() const{
  return maxEntries;
}

ostream& operator<<(ostream& out, const Scores& s){
  cout << "Scores object at: " << &s << "..." << endl;
  for(int i=0; i<s.numEntries; ++i){
    cout << s.entries[i];
  }
  return out;
}

int main(){
  Scores s(3);

  GameEntry a("gameA", 100);
  s.add(a);

  GameEntry b("gameA", 120);
  s.add(b);

  GameEntry c("gameA", 130);
  s.add(c);

  GameEntry d("gameA", 140);
  s.add(d);

  cout << s;
}
