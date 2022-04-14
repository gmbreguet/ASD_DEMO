//---------------------------------------------------------
// Fichier        : 04_Emplace.cpp
// Version        : 01 - 2022-04-12
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'utilisation de
//                : - emplace
//                : - emplace_back
// Modifications  :
// Remarque(s)    : pas forcement un exemple de choses à faire ;)
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>

using std::byte;
using namespace std;

//---------------------------------------------------------
class Trace {
   friend ostream& operator<< (ostream& os, const Trace& t)
                                             { return os << t.data;             }
public:
   Trace()           : data(0)               { cout << "C0(" << data << ") ";   }

   Trace(int data)   : data(data)            { cout << "Ci(" << data << ") ";   }

   Trace(const Trace& other)                 { this->data = other.data;
                                               cout << "CC(" << data << ") ";   }
   Trace(Trace&& other) noexcept
   : data(other.data)                        { other.data = 0;
                                               cout << "CD(" << data << ") ";   }

   ~Trace()                                  { cout << "D("  << data << ") ";   }

   void swap(Trace& other) noexcept          { // using std::swap;
                                               std::swap(data, other.data);
                                               cout << "swap(" << data << ") "; }

   Trace& operator=(const Trace& other)      { this->data = other.data;
                                               cout << "=C("  << data << ") ";
                                               return *this;                    }

   Trace& operator=(Trace&& other) noexcept  { this->swap(other);
                                               cout << "=D(" << data << ") ";
                                               return *this;                    }
private:
   int data;
};

//---------------------------------------------------------
// pas utilisé dans ce code
void swap(Trace& lhs, Trace& rhs) noexcept   { lhs.swap(rhs); }


//---------------------------------------------------------
int main() {

   cout << "----------------------------------------" << endl;
   cout << "   taille des éléments"                   << endl;
   cout << "----------------------------------------" << endl;
   cout << "sizeof(int)    : "   << sizeof(int)       << endl;
   cout << "sizeof(double) : "   << sizeof(double)    << endl;
   cout << "sizeof(Trace)  : "   << sizeof(Trace)     << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   mémoire et objets différents"          << endl;
   cout << "----------------------------------------" << endl;
   byte* ptr = new byte[20];     // espace de travail (bytes)
                                 //  0 -  3 : int
                                 //  4 - 11 : double
                                 // 12 - 15 : trace
                                 // 16 - 19 : trace
   // entier et double
   new(ptr+0) int(1);
   new(ptr+4) double(2.3);
   cout << endl;

   // trace
   Trace* ptrTrace = (Trace*)(ptr+12); // début des Trace
   new(ptrTrace+0) Trace(3);                     cout << endl;
   new(ptrTrace+1) Trace(*ptrTrace);             cout << endl;
   *ptrTrace = Trace(4);                         cout << endl;
   cout << endl;

   ptrTrace->~Trace();                           cout << endl;
   destroy_at(ptrTrace+1);                       cout << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   vecteurs et objets"                    << endl;
   cout << "----------------------------------------" << endl;
   vector<Trace> vecteur;
   vecteur.reserve(10);
   vecteur.emplace_back();                       cout << endl;
   vecteur.emplace_back(Trace());                cout << endl;
   vecteur.emplace_back(Trace(1));               cout << endl;
   vecteur.emplace_back(*vecteur.begin());       cout << endl;
   vecteur.emplace_back(2);                      cout << endl;
   cout << endl;

   cout << "vecteur.size() = " << vecteur.size()      << endl;
   vecteur.emplace(vecteur.begin(), 3);          cout << endl;
   cout << "vecteur.size() = " << vecteur.size()      << endl;
   cout << endl;

   cout << "vecteur.size() = " << vecteur.size()      << endl;
   vecteur[0] = Trace(10);                       cout << endl;
   destroy_at(&vecteur[0]);                      cout << endl;
   cout << "vecteur.size() = " << vecteur.size()      << endl;
   vecteur[0] = Trace(10);                       cout << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   sortie de main"                        << endl;
   cout << "----------------------------------------" << endl;
   return EXIT_SUCCESS;
}

//      ----------------------------------------
//         taille des éléments
//      ----------------------------------------
//      sizeof(int)    : 4
//      sizeof(double) : 8
//      sizeof(Trace)  : 4
//
//      ----------------------------------------
//         mémoire et objets différents
//      ----------------------------------------
//
//      Ci(3)
//      CC(3)
//      Ci(4) swap(4) =D(4) D(3)
//
//      D(4)
//      D(3)
//
//      ----------------------------------------
//         vecteurs et objets
//      ----------------------------------------
//      C0(0)
//      C0(0) CD(0) D(0)
//      Ci(1) CD(1) D(0)
//      CC(0)
//      Ci(2)
//
//      vecteur.size() = 5
//      Ci(3) CD(2) swap(0) =D(0) swap(1) =D(1) swap(0) =D(0) swap(0) =D(0) swap(3) =D(3) D(0)
//      vecteur.size() = 6
//
//      vecteur.size() = 6
//      Ci(10) swap(10) =D(10) D(3)
//      D(10)
//      vecteur.size() = 6
//      Ci(10) swap(10) =D(10) D(10)
//
//      ----------------------------------------
//         sortie de main
//      ----------------------------------------
//      D(2) D(0) D(1) D(0) D(0) D(10)
