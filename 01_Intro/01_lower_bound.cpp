//---------------------------------------------------------
// Fichier        : 01_lower_bound.cpp
// Version        : 01 - 2022-01-31
// Auteur(s)      : BREGUET Guy-Michel
// But            : tester std::lower_bound
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

//------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
   os << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   }
   os << "]";
   return os;
}

//------------------------------------------------------
template <class ForwardIterator, class T>
ForwardIterator lowerBound (ForwardIterator first, ForwardIterator last, const T& val)
{
   ForwardIterator it;
   unsigned count, step;
   count = distance(first,last);

   while (count>0) {

      it = first;
      step=count/2;

      // traces
      cout << "vecteur  : " << vector<int>{first, first+count} << endl;
      cout << "*it      : " << *it                             << endl;
      cout << "count    : " << count                           << endl;
      cout << "step     : " << step                            << endl;
      cout << endl;

      step=count/2;
      advance(it,step);
      
      if (*it<val) {
         first=++it;
         count-=step+1;
      }
      else
         count=step;
   }
   return first;
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   vector<int> v = {10,20,30,30,20,10,10,20};

   cout << "v        : " << v << endl;
   sort(v.begin(), v.end());
   cout << "v (trié) : " << v << endl;
   cout << endl;

        
        
   auto it = lowerBound(v.begin(), v.end(), 20);


   cout << endl;
   cout << "indice   : " << distance(v.begin(), it);
   cout << endl;

   return EXIT_SUCCESS;
}  // main

