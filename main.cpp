#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(void) {
  ifstream infile("./input/b_small.in");
  if(!infile.is_open()) {
    printf("file error\n");
    return -1;
  }
  int M,N;
  infile >> M >> N;

  int *arr = new int[N];
  int i;
  for(i=0;i<N;i++) {
    infile >> arr[i];
  }
  infile.close();


  delete[] arr;
  return 0;
}
