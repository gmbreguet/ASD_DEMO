//---------------------------------------------------------
// Fichier        : 03-17.cpp
// Version        : 02 - 2023-02-28
// Auteur(s)      : BREGUET Guy-Michel
// But            : exercices récursivité
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//------------------------------------------------------
void f1 (unsigned a, unsigned b) {
   if (a < b) {
      cout << a << b << " ";
      f1(a+1, b);
      f1(a, b-2);
   }
}

//------------------------------------------------------
void f2 (unsigned a, unsigned b) {
   if (a < b) {
      f2(a+1, b);
      cout << a << b << " ";
      f2(a, b-2);
   }
}

//------------------------------------------------------
void f3 (unsigned a, unsigned b) {
   if (a < b) {
      f3(a+1, b);
      f3(a, b-2);
      cout << a << b << " ";
   }
}

//------------------------------------------------------
int main () {

   cout << "f1(0, 4) : ";
   f1(0, 4);

   cout << endl;
   cout << "f2(0, 4) : ";
   f2(0, 4);

   cout << endl;
   cout << "f3(0, 4) : ";
   f3(0, 4);

   cout << endl << endl;
   return EXIT_SUCCESS;
}

//                                    f(0, 4)
//                        _/                         \_
//                     f(1, 4)                          f(0, 2)
//                    _/     \_                         _/       \_
//               f(2, 4)        f(1, 2)              f(1, 2)     f(0, 0)
//               _/    \_       _/    \_             _/    \_
//         f(3, 4)  f(2, 2)  f(2, 2)   f(1, 0)  f(2, 2)    f(1, 0)
//         _/    \_
//      f(4, 4)  f(3, 2)
               

//    f1(0, 4) : 04 14 24 34 12 02 12 
//    f2(0, 4) : 34 24 14 12 04 12 02 
//    f3(0, 4) : 34 24 12 14 12 02 04 

