//---------------------------------------------------------
// Demo           : 04_2_listStringSimple
// Fichier        : main.cpp
// Version        : 03 - 2023.04.06
// Auteur(s)      : BREGUET Guy-Michel
// But            : listString dynamique avec exceptions
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>

#include <string>
#include <cctype>    // toupper
#include "List_G.hpp"
 
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
   // Create an empty list
   List_G<int> listInt;
    
   cout << "Insert value   : "                        << endl;
   for (int i : {1, 2, 3, 4, 5} ) {
      cout << i << " ";
      listInt.addFirst(i);
   }

   cout << endl;
   cout << "listInt        : " << listInt             << endl;
   cout << "size           : " << listInt.size()      << endl;
   cout << endl;

   cout << "search for a value" << endl;
   if (int* ptrInt = listInt.ptrElement(4))
      cout << "ptrInt->       : "
           << *ptrInt << " (" << ptrInt << ")"        << endl;
   else
      cout << "ptrNom->       : NOT FOUND"            << endl;
   cout << endl;

   cout << "forEach => value + 1"                     << endl;
   listInt.forEach(PlusN<int>(1));
   cout << "listString     : " << listInt             << endl;
   cout << "Size           : " << listInt.size()      << endl;
   cout << endl;

   // First cell
   cout << "First cell     : " << listInt.first()     << endl;

   cout << endl;

   // remove each cell
   cout << "Remove all     : ";
   while (not listInt.isEmpty()) {
      cout << listInt.first() << " ";
      listInt.removeFirst();
   }

   cout << endl;
   cout << "listInt        : " << listInt             << endl;
   cout << "size           : " << listInt.size()      << endl;


   cout << endl;
   return EXIT_SUCCESS;
}

//      Insert value   : 1 2 3 4 5
//      listInt        : [ 5 (0x6000004e4080), 4 (0x6000004e4070), 3 (0x6000004e4060), 2 (0x6000004e4050), 1 (0x6000004e4040) ]
//      size           : 5
//
//      search for a value
//      ptrInt->       : 4 (0x6000004e4070)
//
//      forEach => value + 1
//      listString     : [ 6 (0x6000004e4080), 5 (0x6000004e4070), 4 (0x6000004e4060), 3 (0x6000004e4050), 2 (0x6000004e4040) ]
//      Size           : 5
//
//      First cell     : 6
//
//      Remove all     : 6 5 4 3 2
//      listInt        : [  ]
//      size           : 0




