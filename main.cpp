#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(void) {
  ifstream infile("./input/a_example.txt");
  if(!infile.is_open()) {
    printf("file error\n");
    return -1;
  }
  int B,L,D;
  infile >> B >> L >> D;

  int *scores = new int[B];
  int i;
  for(i=0;i<B;i++) {
    infile >> scores[i];
  }

  for(i=0;i<L;i++) {
    int N,T,M;
    infile >> N >> T >> M;

    for(j=0;j<N;j++) {
      // infile >> 
    }
  }

  infile.close();

  delete[] scores;
  return 0;
}
