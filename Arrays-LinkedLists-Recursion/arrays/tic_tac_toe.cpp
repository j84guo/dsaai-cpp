#include <iostream>

using namespace std;


// used to represent a player's move as well as the player himself
const int X = 1;
const int O = -1;
const int EMPTY = 0;

int board[3][3];
int currentPlayer;

void clearBoard(){
  for(int r=0; r<3; ++r){
    for(int c=0; c<3; ++c){
      board[r][c] = EMPTY;
    }
  }

  currentPlayer = X;
}

void putMark(int r, int c){
  board[r][c] = currentPlayer;
  currentPlayer *= -1;
}

bool isWin(int mark){
  int win = 3*mark;

  for(int r=0; r<3; ++r){
    if(board[r][0] + board[r][1] + board[r][2] == win){
      return true;
    }
  }

  for(int c=0; c<3; ++c){
    if(board[0][c] + board[1][c] + board[2][c] == win){
      return true;
    }
  }

  return board[0][0] + board[1][1] + board[2][2] == win
    || board[2][0] + board[1][1] + board[2][0] == win;
}

int getWinner(){
  if(isWin(X)){
    return X;
  }else if(isWin(O)){
    return O;
  }

  return EMPTY;
}

void printBoard(){
  for(int r=0; r<3; r++){
    for(int c=0; c<3; c++){
      switch(board[r][c]){
        case X:
          cout << "X";
          break;
        case O:
          cout << "O";
          break;
        case EMPTY:
          cout << " ";
          break;
      }

      if(c < 2){
        cout << "|";
      }
    }

    if(r < 2){
      cout << "\n-+-+-\n";
    }
  }

  cout << "\n";
}

int main(){
  clearBoard();

  putMark(0, 0);
  putMark(1, 1);

  putMark(2, 2);
  putMark(2, 0);

  putMark(0, 2);
  putMark(1, 2);

  putMark(0, 1);

  int winner = getWinner();
  printBoard();

  if(winner != EMPTY){
    cout << (winner == X ? "X" : "O") << " wins!" << endl;
  }else{
    cout << "Tie" << endl;
  }

  return 0;
}
