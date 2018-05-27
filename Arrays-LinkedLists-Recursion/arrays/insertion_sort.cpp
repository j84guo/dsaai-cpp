#include <iostream>

using namespace std;

void insertionSort(char *A, int n){
  for(int i=1; i<n; i++){
    char c = A[i];

    int j = i-1;

    // compare current character with each character within the sorted section
    while(j >= 0 && A[j] > c){
      A[j+1] = A[j];
      --j;
    }

    A[j+1] = c;
  }
}

int main(){
  char A[] = {'f', 's', 'a', 'q', 'p', 'a'};
  insertionSort(A, 6);

  for(int i=0; i<6; i++){
    cout << A[i] << " ";
  }
}
