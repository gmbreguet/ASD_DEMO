//---------------------------------------------------------
// Fichier        : 04_3_Iterateur_Invalide.cpp
// Version        : 01 - 2022-05-10
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer la porblématique des itérateurs invalides
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <vector>

//---------------------------------------------------------
using namespace std;

//---------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

//---------------------------------------------------------
void f1(vector<int>& v) {
   for(size_t i = 0; i != v.size(); ++i) {
      if(v[i] % 2 == 0) {
         v.insert(v.begin()+i,42);
         ++i;
       }
   }
}

//---------------------------------------------------------
void f2(vector<int>& v) {
   for(auto i = v.begin(); i != v.end(); ++i) {
      if(*i % 2 == 0) {
         v.insert(i,42);
         ++i;
      }
   }
}

//---------------------------------------------------------
int main() {

   vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   f1(v1);
   cout << v1 << endl;
   
   vector<int> v2 = v1;
   f2(v2);
   cout << v2 << endl;

   return EXIT_SUCCESS;
}

//---------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
   os << "[";
   for (auto it=v.cbegin(); it!=v.cend(); ++it) {
      if (it!=v.cbegin())
         os << ", ";
      os << *it;
   }
   os << "]";
   return os;
}

//      [1, 42, 2, 3, 42, 4, 5, 42, 6, 7, 42, 8, 9, 42, 10]
//      _Test_Cpp(48321,0x1000a4600) malloc: Incorrect checksum for freed object 0x101026f08: probably modified after being freed.
//      Corrupt value: 0x7ff8503d4748
//      _Test_Cpp(48321,0x1000a4600) malloc: *** set a breakpoint in malloc_error_break to debug
//      _Test_Cpp(48321,0x1000a4600) malloc: Incorrect checksum for freed object 0x101026f08: probably modified after being freed.
//      Corrupt value: 0x7ff8503d4748
//      warning: could not execute support code to read Objective-C class data in the process. This may reduce the quality of type information available.
