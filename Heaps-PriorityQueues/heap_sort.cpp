#include <iostream>

using std::cout;
using std::endl;

void heapSort(int* A, int n);
void heapifyDown(int* A, int i, int n);
void swap(int* A, int a, int b);
int left(int i);
int right(int i);
void printArr(int* A, int n);
void removeMin(int* A, int n);

int main(){

  int A[10] = {1, 2, 10, 2, 32, 22, 13, 31, 2, 11};

  heapSort(A, 10);

  printArr(A, 10);

}

void heapSort(int* A, int n){
  int mid = n/2;

  for(int i=mid; i>=0; --i){
    heapifyDown(A, i, n);
  }

  for(int i=0; i<n; ++i){
    removeMin(A, n-i);
  }
}

void removeMin(int* A, int n){
  swap(A, 0, --n);
  heapifyDown(A, 0, n);
}

void heapifyDown(int* A, int i, int n){
  if(i < 0 || i >= n) return;

  while(left(i) < n){
    int c = right(i) < n && A[right(i)] < A[left(i)] ? right(i) : left(i);

    if(A[c] < A[i]){
      swap(A, i, c);
      i = c;
    }else{
      break;
    }
  }
}

void swap(int* A, int a, int b){
  int tmp = A[a];
  A[a] = A[b];
  A[b] = tmp;
}

int left(int i){
  return 2 * i + 1;
}

int right(int i){
  return 2 * i + 2;
}

void printArr(int* A, int n){
  for(int i=0; i<n; ++i){
    cout << A[i] << " ";
  }

  cout << endl;
}
