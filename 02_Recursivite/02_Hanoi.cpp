//---------------------------------------------------------
// Fichier        : 01_Hanoi.cpp
// Version        : 01 - 2022-01-27
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme des tours de Hanoi
//                : en mode récursif
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

using Disque = char;
using Tour   = vector<Disque>;
using Tours  = vector<Tour>;

//------------------------------------------------------
// afficher le contenu d'une tour (les disques)
ostream& operator<< (ostream& os, const Tour& tour) {
   for (const Disque d : tour)
      os << d << " ";
   return os;
}

//------------------------------------------------------
// afficher les tours de Hanoi
ostream& operator<< (ostream& os, const Tours& tours) {
   int n=0;
   for (const Tour& t : tours)
      os << "T" << ++n << " " << t << endl;
   return os;
}

//------------------------------------------------------
void transfert(Tour& from, Tour& via, Tour& to, int n) {

   if (n > 0) {
      transfert(from, to, via, n-1);

      // afficher l'état actuel
      cout << "T0 " << from  << endl;
      cout << "T1 " << via   << endl;
      cout << "T2 " << to    << endl;
      cout << endl;

      // déplacement
      to.push_back( from.back() );
      from.pop_back();

      transfert(via, from, to, n-1);
   }
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   cout << "Tour de Hanoi" << endl;

   vector<Tour> tours(3);
   tours[0] = {'A', 'B', 'C'};

   transfert(tours[0], tours[1], tours[2], 3);
   cout << tours << endl;

   return EXIT_SUCCESS;
}
