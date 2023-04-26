//---------------------------------------------------------
// Fichier        : 04_3_std_List.cpp
// Version        : 01 - 2022-05-10
// Auteur(s)      : BREGUET Guy-Michel
// But            : exemples de code avec std::list
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <list>

//---------------------------------------------------------
using namespace std;

//---------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const list<T>& v);

//---------------------------------------------------------
template < typename T >
void supprimer(std::list<T>& li, const T& val) {
   auto it = li.begin();
   while(it != li.end()) {
      if(*it == val)
         it = li.erase(it);
      else
         ++it;
   }
}

//---------------------------------------------------------
int main() {

   list<int> li = {1, 2, 2, 3, 4, 2, 2, 2, 5, 6, 7, 8, 9, 10};
   cout << li << endl;
   
   supprimer(li, 2);
   cout << li << endl;

   return EXIT_SUCCESS;
}

//---------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const list<T>& l) {
   os << "[";
   for (auto it=l.cbegin(); it!=l.cend(); ++it) {
      if (it!=l.cbegin())
         os << ", ";
      os << *it;
   }
   os << "]";
   return os;
}
