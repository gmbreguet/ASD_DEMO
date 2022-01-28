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

size_t nbreAppels;      // variable globale pour compter les appels

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
void transfert(Tour& from, Tour& via, Tour& to, size_t n) {

   ++nbreAppels;

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

   vector<Tour> tours(3);                    // 3 tours
   Tour& gauche = tours[0];
   Tour& centre = tours[1];
   Tour& droite = tours[2];

   // tours à déplacer
   gauche = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

   //        from    via     to      height
   transfert(gauche, centre, droite, gauche.size());

   cout << tours << endl;

   cout << "hauteur     : " << droite.size() << endl;
   cout << "nbre appels : " << nbreAppels    << endl;

   return EXIT_SUCCESS;
}
