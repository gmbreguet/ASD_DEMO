#include <iostream>
using namespace std;

#include "ToursHanoi.hpp"
int main()
{
  int n;
  cout<<"# de disques? ";
  cin>>n;
  ToursHanoi h(n);
  h.jouer();
}
