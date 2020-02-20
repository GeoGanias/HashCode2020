#include <iostream>
#include <fstream>
#include "Interface.hpp"

double findcost(Library*,int *,int);

int selectLibrary(Library **libraries,int *scores,int time) {
  double cost = findcost(libraries[0],scores,time);
}


double findcost(Library *library,int *scores,int time) {
  return ((double) library->get_Score(scores)/(time-library->get_SignUpTime())) * ((double) library->get_bookCounter()/library->get_ScannableBooks());
}
