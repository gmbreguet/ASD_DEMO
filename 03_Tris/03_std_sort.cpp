//---------------------------------------------------------
// Fichier        : 03_std_sort.cpp
// Version        : 01 - 2022.03.28
// Auteur(s)      : BREGUET Guy-Michel
// But            : exemple de tri avec std::sort
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <algorithm>    // std::sort
#include <cmath>        // hypot
#include <vector>

using namespace std;

//---------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

//---------------------------------------------------
template <typename T>
class Coord;                     // pré-déclaration pour la fonction amie

//---------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const Coord<T>& c);

//---------------------------------------------------
// sort x->y
template <typename T>
bool plusPetit_XY (const Coord<T>& lhs, const Coord<T>& rhs) {
   if (lhs.x != rhs.x)
      return lhs.x < rhs.x;
   else
      return lhs.y < rhs.y;
}

//---------------------------------------------------
// sort y->x
template <typename T>
bool plusPetit_YX (const Coord<T>& lhs, const Coord<T>& rhs) {
   if (lhs.x != rhs.x)
      return lhs.y < rhs.y;
   else
      return lhs.x < rhs.x;
}

//---------------------------------------------------
template <typename T>
class Coord {
   friend ostream& operator<< <T>(ostream& os, const Coord<T>& c);
   friend bool plusPetit_XY <T>(const Coord<T>& lhs, const Coord<T>& rhs);
   friend bool plusPetit_YX <T>(const Coord<T>& lhs, const Coord<T>& rhs);

public:
   Coord() : x(0), y(0) {}
   Coord(T x, T y) : x(x), y(y) {}
   Coord(const Coord& c) { x = c.x; y = c.y; } 

   // distance de (0, 0)
   bool operator< (const Coord& c) const {
      return hypot(x, y) < hypot(c.x, c.y);      
   }

   Coord& operator= (const Coord& c) {
      x = c.x;
      y = c.y;
      return *this;
   }

private:
   T x;
   T y;
};

//---------------------------------------------------
// vecteur en copie pour ne pas modifier l'original
template <typename T>
void test (vector<T> vecteur) {
   cout << endl;
   cout << "vecteur " << vecteur << endl; 
   sort(vecteur.begin(), vecteur.end());
   cout << "vecteur " << vecteur << endl; 
}

//---------------------------------------------------
// exemples de using génériques
using VectInt        = vector<int>;
using VectDouble     = vector<double>;
using VectCoordInt   = vector<Coord<int>>;

//---------------------------------------------------
int main() {

   // vecteurs à traiter
   VectInt      vInt        = {4,   8,   3,   9,   8,   2,   1,   5,   6};
   VectDouble   vDouble     = {4.1, 8.1, 3.1, 9.1, 8.1, 2.1, 1.1, 5.1, 6.1};
   VectCoordInt vCoordInt   = {{0, 1}, {1, 0}, {4, 8}, {1, 4}, {4, 5}};

   test<int>(vInt);
   test<double>(vDouble);
   test<Coord<int>>(vCoordInt);

   // tri à 2 critères
   cout << endl << "tri X puis Y" << endl;
   cout << vCoordInt << endl;
   sort(vCoordInt.begin(), vCoordInt.end(), plusPetit_XY<int>);
   cout << vCoordInt << endl;

   cout << endl << "tri Y puis X" << endl;
   cout << vCoordInt << endl;
   sort(vCoordInt.begin(), vCoordInt.end(), plusPetit_YX<int>);
   cout << vCoordInt << endl;

   return EXIT_SUCCESS;
}

//---------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
   os << "[";
   for(size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   } 
   os << "]";
   return os;
}

//---------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const Coord<T>& c) {
   os << "(" << c.x << ", " << c.y << ")";
   return os;
}


//      vecteur [4, 8, 3, 9, 8, 2, 1, 5, 6]
//      vecteur [1, 2, 3, 4, 5, 6, 8, 8, 9]
//
//      vecteur [4.1, 8.1, 3.1, 9.1, 8.1, 2.1, 1.1, 5.1, 6.1]
//      vecteur [1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 8.1, 8.1, 9.1]
//
//      vecteur [(0, 1), (1, 0), (4, 8), (1, 4), (4, 5)]
//      vecteur [(0, 1), (1, 0), (1, 4), (4, 5), (4, 8)]
//
//      tri X puis Y
//      [(0, 1), (1, 0), (4, 8), (1, 4), (4, 5)]
//      [(0, 1), (1, 0), (1, 4), (4, 5), (4, 8)]
//
//      tri Y puis X
//      [(0, 1), (1, 0), (1, 4), (4, 5), (4, 8)]
//      [(1, 0), (0, 1), (1, 4), (4, 5), (4, 8)]
