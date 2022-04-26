//---------------------------------------------------------
// Fichier        : 03_Fusion.cpp
// Version        : 02 - 2022-04-25
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithm de fusion (sans tri)
// Modifications  : vecteur.reserve(..) pour éviter les constructeurs
// Remarque(s)    : une version compacte mais qui ne crée
//                : pas de vecteur est disponible sur
//                : https://www.cplusplus.com/reference/algorithm/merge
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//---------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const vector<T> v) {
   os << "[";
   for (auto it=v.begin(); it!=v.end(); ++it) {
      if (it!=v.begin())
         os << ", ";
      os << *it;
   }
   os << "]";
   return os;
}

//---------------------------------------------------------
template <typename T>
vector<T> fusionner1 (const vector<T>& lhs, const vector<T>& rhs) {

   // cas particuliers => gain de temps
   if (lhs.empty())
      return rhs;

   if (rhs.empty())
      return lhs;

   // vecteur de résultat (la taille est prête => gain de temps)
   vector<T> resultat;        // pour éviter les constructeurs
   resultat.reserve(lhs.size() + rhs.size());

   // iterateurs de travail
   auto lhs_it = lhs.begin();
   auto rhs_it = rhs.begin();
   auto res_it = resultat.begin();

   // copie alternative
   while (lhs_it != lhs.end() and rhs_it != rhs.end())
      *res_it++ = (*lhs_it < *rhs_it) ? *lhs_it++ : *rhs_it++;

   // copie la partie restante
   if (lhs_it == lhs.end())
      copy(rhs_it, rhs.end(), res_it);
   else
      copy(lhs_it, lhs.end(), res_it);

   // retour du résultat
   return resultat;
}

//---------------------------------------------------------
// https://www.cplusplus.com/reference/algorithm/merge
template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator fusionner2 (InputIterator1 first1, InputIterator1 last1,
                           InputIterator2 first2, InputIterator2 last2,
                           OutputIterator result) {
  while (true) {
    if (first1==last1) return std::copy(first2, last2, result);
    if (first2==last2) return std::copy(first1, last1, result);
    *result++ = (*first2 < *first1)? *first2++ : *first1++;
  }
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   const vector<int> A = {1, 3, 5, 7, 9};
   const vector<int> B = {2, 4, 6, 8};
   vector<int> v (A.size() + B.size());

   cout << "vecteur A         : " << A                << endl;
   cout << "vecteur B         : " << B                << endl;
   cout << "fusionner1(A, B)  : " << fusionner1(A, B) << endl;

   fusionner2(A.begin(), A.end(),
              B.begin(), B.end(),
              v.begin());
   cout << "fusionner2(...)   : " << v                << endl;

   cout << endl;
   return EXIT_SUCCESS;
}

//      vecteur A         : [1, 3, 5, 7, 9]
//      vecteur B         : [2, 4, 6, 8]
//      fusionner1(A, B)  : [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      fusionner2(...)   : [1, 2, 3, 4, 5, 6, 7, 8, 9]
