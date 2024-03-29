//---------------------------------------------------------
// Demo           : 04_4_Heap
// Fichier        : 04_4_xxx_heap.cpp
// Version        : 01 - 2023.05.09
// Auteur(s)      : BREGUET Guy-Michel
// But            : algorithm::xxx_heap
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using Data = int;

//---------------------------------------------------------
ostream& operator<< (ostream& os, const vector<Data>& v);

//---------------------------------------------------------
int main () {
   cout << "----------------------------------------" << endl;
   cout << "push_heap"                                << endl;
   cout << "----------------------------------------" << endl;
   vector<Data> tab;
   for (int i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
      tab.push_back(i);
      push_heap(tab.begin(), tab.end());
      cout << "tab : " << tab << endl;
   }

   cout << "----------------------------------------" << endl;
   cout << "is_heap"                                  << endl;
   cout << "----------------------------------------" << endl;
   cout << "tab : " << is_heap(tab.begin(),tab.end()) << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "pop_heap"                                 << endl;
   cout << "----------------------------------------" << endl;
   for (size_t i=0; tab.size(); ++i) {
      cout << "tab : " << tab;
      pop_heap(tab.begin(), tab.end());
      cout << " => " << tab << endl;
      tab.pop_back();
   }
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "make_heap"                                << endl;
   cout << "----------------------------------------" << endl;
   tab = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   cout << "tab : " << tab;
   make_heap(tab.begin(), tab.end());
   cout << " => " << tab << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "push_heap (wrong)"                        << endl;
   cout << "----------------------------------------" << endl;
   tab = {1, 2, 3, 4, 5, 6, 7};
   cout << "tab : " << tab;
   push_heap(tab.begin(), tab.end());
   cout << " => " << tab << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "pop_heap (wrong)"                         << endl;
   cout << "----------------------------------------" << endl;
   tab = {1, 2, 3, 4, 5, 6, 7};
   cout << "tab : " << tab;
   pop_heap(tab.begin(), tab.end());
   cout << " => " << tab << endl;
   cout << endl;

   cout << "fin de programme"                         << endl;
   return EXIT_SUCCESS;
}

//---------------------------------------------------------
ostream& operator<< (ostream& os, const vector<Data>& v) {
   os << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   }
   return os << "]";
}

//      ----------------------------------------
//      push_heap
//      ----------------------------------------
//      tab : [1]
//      tab : [2, 1]
//      tab : [3, 1, 2]
//      tab : [4, 3, 2, 1]
//      tab : [5, 4, 2, 1, 3]
//      tab : [6, 4, 5, 1, 3, 2]
//      tab : [7, 4, 6, 1, 3, 2, 5]
//      tab : [8, 7, 6, 4, 3, 2, 5, 1]
//      tab : [9, 8, 6, 7, 3, 2, 5, 1, 4]
//      tab : [10, 9, 6, 7, 8, 2, 5, 1, 4, 3]
//      ----------------------------------------
//      is_heap
//      ----------------------------------------
//      tab : 1
//
//      ----------------------------------------
//      pop_heap
//      ----------------------------------------
//      tab : [10, 9, 6, 7, 8, 2, 5, 1, 4, 3] => [9, 8, 6, 7, 3, 2, 5, 1, 4, 10]
//      tab : [9, 8, 6, 7, 3, 2, 5, 1, 4] => [8, 7, 6, 4, 3, 2, 5, 1, 9]
//      tab : [8, 7, 6, 4, 3, 2, 5, 1] => [7, 4, 6, 1, 3, 2, 5, 8]
//      tab : [7, 4, 6, 1, 3, 2, 5] => [6, 4, 5, 1, 3, 2, 7]
//      tab : [6, 4, 5, 1, 3, 2] => [5, 4, 2, 1, 3, 6]
//      tab : [5, 4, 2, 1, 3] => [4, 3, 2, 1, 5]
//      tab : [4, 3, 2, 1] => [3, 1, 2, 4]
//      tab : [3, 1, 2] => [2, 1, 3]
//      tab : [2, 1] => [1, 2]
//      tab : [1] => [1]
//
//      ----------------------------------------
//      make_heap
//      ----------------------------------------
//      tab : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] => [10, 9, 7, 8, 5, 6, 3, 1, 4, 2]
//
//      ----------------------------------------
//      push_heap (wrong)
//      ----------------------------------------
//      tab : [1, 2, 3, 4, 5, 6, 7] => [7, 2, 1, 4, 5, 6, 3]
//
//      ----------------------------------------
//      pop_heap (wrong)
//      ----------------------------------------
//      tab : [1, 2, 3, 4, 5, 6, 7] => [7, 2, 3, 4, 5, 6, 1]
//
//
