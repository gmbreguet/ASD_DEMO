//---------------------------------------------------------
// Demo           : 04_2_listStringSimple
// Fichier        : main.cpp
// Version        : 04 - 2023.04.26
// Auteur(s)      : BREGUET Guy-Michel
// But            : generic forward list
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include "ForwardList.hpp"
 
using namespace std;

//---------------------------------------------------------
template <typename T>
class PlusN {
public:
   PlusN(const T& N) : N(N) {};
   T operator() (const T& crt) { return crt + N; };
private:
   const T& N;
};

//---------------------------------------------------------
int main () {
   cout << "----------------------------------------" << endl;
   cout << "List_G<int> listInt"                      << endl;
   cout << "----------------------------------------" << endl;
   ForwardList<int> listInt;
   cout << listInt                                    << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "listInt.push_front(i) <= {1, 2, 3, 4, 5}" << endl;
   cout << "----------------------------------------" << endl;
   for (int i : {1, 2, 3, 4, 5} ) {
      listInt.push_front(i);
   }
   cout << listInt                                    << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "listInt.front()"                          << endl;
   cout << "----------------------------------------" << endl;
   cout << "front   : " << listInt.front()            << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "listInt.find(4)"                          << endl;
   cout << "----------------------------------------" << endl;
   if (int* ptrInt = listInt.find(4))
      cout << "ptrInt->: " << ptrInt                  << endl;
   else
      cout << "ptrNom-> : NOT FOUND"                  << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "forEach => value + 1"                     << endl;
   cout << "----------------------------------------" << endl;
   listInt.for_each(PlusN<int>(1));
   cout << listInt                                    << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "clear"                                    << endl;
   cout << "----------------------------------------" << endl;
   listInt.clear();
   cout << listInt                                    << endl;
   cout << endl;

   return EXIT_SUCCESS;
}

//      ----------------------------------------
//      List_G<int> listInt
//      ----------------------------------------
//      size    : 0
//      content : []
//
//      ----------------------------------------
//      listInt.push_front(i) <= {1, 2, 3, 4, 5}
//      ----------------------------------------
//      size    : 5
//      content : [0x600001778080 => 5, 0x600001778070 => 4, 0x600001778060 => 3, 0x600001778050 => 2, 0x600001778040 => 1]
//
//      ----------------------------------------
//      listInt.front()
//      ----------------------------------------
//      front   : 5
//
//      ----------------------------------------
//      listInt.find(4)
//      ----------------------------------------
//      ptrInt->: 0x600001778070
//
//      ----------------------------------------
//      forEach => value + 1
//      ----------------------------------------
//      size    : 5
//      content : [0x600001778080 => 6, 0x600001778070 => 5, 0x600001778060 => 4, 0x600001778050 => 3, 0x600001778040 => 2]
//
//      ----------------------------------------
//      clear
//      ----------------------------------------
//      size    : 0
//      content : []
//
