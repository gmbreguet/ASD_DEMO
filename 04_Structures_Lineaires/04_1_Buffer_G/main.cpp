//---------------------------------------------------------
// Fichier        : 04_1_Buffer_buffer.cpp
// Version        : 01 - 2022-04-20
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer une classe
//                : Buffer à taille fixe
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

#include "Buffer_G.h"
#include "Trace.cpp"

//---------------------------------------------------------
using namespace std;

//---------------------------------------------------------
int main() {
   cout << endl;
   cout << "----------------------------------------"    << endl;
   cout << "   constructeurs"                            << endl;
   cout << "----------------------------------------"    << endl;
   Buffer<Trace> buffer(10);
   cout << endl << buffer                                << endl;

   cout << endl;
   cout << "----------------------------------------"    << endl;
   cout << "   push_back"                                << endl;
   cout << "----------------------------------------"    << endl;
   for (int i=0; i<3; ++i) {
      buffer.push_back(Trace(11+i));
      cout << endl;
   }
   cout << endl << buffer                                << endl;

   cout << endl;
   cout << "----------------------------------------"    << endl;
   cout << "   push_front"                               << endl;
   cout << "----------------------------------------"    << endl;
   for (int i=0; i<3; ++i) {
      buffer.push_front(Trace(21+i));
      cout << endl;
   }
   cout << endl << buffer                                << endl;

   cout << endl;
   cout << "----------------------------------------"    << endl;
   cout << "   back / push_back"                         << endl;
   cout << "----------------------------------------"    << endl;
   cout << "back       :" << buffer.back()               << endl;
   buffer.pop_back();
   cout << endl << buffer                                << endl;

   cout << endl;
   cout << "----------------------------------------"    << endl;
   cout << "   front / push_front"                       << endl;
   cout << "----------------------------------------"    << endl;
   cout << "front      :" << buffer.front()              << endl;
   buffer.pop_front();
   cout << endl << buffer                                << endl;

   cout << endl;
   cout << "----------------------------------------"    << endl;
   cout << "   at"                                       << endl;
   cout << "----------------------------------------"    << endl;
   cout << "at(0)      :" << buffer.at(0)                << endl;
   cout << "at(1)      :" << buffer.at(1)                << endl;
   cout << "at(2)      :" << buffer.at(2)                << endl;
   cout << "at(3)      :" << buffer.at(3)                << endl;
//   cout << "at(4)      :" << buffer.at(4)                << endl;
   cout << endl << buffer                                << endl;

   cout << "----------------------------------------"    << endl;
   return EXIT_SUCCESS;
}

//      ----------------------------------------
//      constructeurs
//      ----------------------------------------
//
//      taille     : 0
//      capacité   : 10
//      debut      : 0
//      logique    : []
//      physique   : [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
//
//      ----------------------------------------
//      push_back
//      ----------------------------------------
//      Ci(11) swap(11) =D(11) D(0)
//      Ci(12) swap(12) =D(12) D(0)
//      Ci(13) swap(13) =D(13) D(0)
//
//      taille     : 3
//      capacité   : 10
//      debut      : 0
//      logique    : [11, 12, 13]
//      physique   : [11, 12, 13, 0, 0, 0, 0, 0, 0, 0]
//
//      ----------------------------------------
//      push_front
//      ----------------------------------------
//      Ci(21) swap(21) =D(21) D(0)
//      Ci(22) swap(22) =D(22) D(0)
//      Ci(23) swap(23) =D(23) D(0)
//
//      taille     : 6
//      capacité   : 10
//      debut      : 7
//      logique    : [23, 22, 21, 11, 12, 13]
//      physique   : [11, 12, 13, 0, 0, 0, 0, 23, 22, 21]
//
//      ----------------------------------------
//      back / push_back
//      ----------------------------------------
//      back       :CC(13) 13
//      D(13) D(13)
//      taille     : 5
//      capacité   : 10
//      debut      : 7
//      logique    : [23, 22, 21, 11, 12]
//      physique   : [11, 12, 13, 0, 0, 0, 0, 23, 22, 21]
//
//      ----------------------------------------
//      front / push_front
//      ----------------------------------------
//      front      :CC(23) 23
//      D(23) D(23)
//      taille     : 4
//      capacité   : 10
//      debut      : 8
//      logique    : [22, 21, 11, 12]
//      physique   : [11, 12, 13, 0, 0, 0, 0, 23, 22, 21]
//
//      ----------------------------------------
//      at
//      ----------------------------------------
//      at(0)      :22
//      at(1)      :21
//      at(2)      :11
//      at(3)      :12
//      libc++abi: terminating due to uncaught exception of type std::out_of_range: Buffer::at
//            at(4)      :
//      Process finished with exit code 134 (interrupted by signal 6: SIGABRT)
