//---------------------------------------------------------
// Fichier        : 04_1_Trace_vector.cpp
// Version        : 02 - 2022-04-14
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer les redimensionnements
//                : des tableaux à capacité variable
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>

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
template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

//---------------------------------------------------------
int main() {

   cout << "----------------------------------------" << endl;
   cout << "vector<Trace> v0"                         << endl;
   cout << "actions  : ";
   vector<Trace> vect;
   cout << endl << vect << endl << endl;

   cout << "vect.reserve(2)"                          << endl;
   cout << "actions  : ";
   vect.reserve(2);
   cout << endl << vect << endl << endl;

   cout << "vect.push_back(Trace(1))"                 << endl;
   cout << "actions  : ";
   vect.push_back(Trace(1));
   cout << endl << vect << endl << endl;

   cout << "vect.push_back(Trace(2))"                 << endl;
   cout << "actions  : ";
   vect.push_back(Trace(2));
   cout << endl << vect << endl << endl;

   cout << "vect.push_back(Trace(3))"                 << endl;
   cout << "actions  : ";
   vect.push_back(Trace(3));
   cout << endl << vect << endl << endl;

   cout << "vect.insert(vect.begin(), Trace(4))"      << endl;
   cout << "actions  : ";
   vect.insert(vect.begin(), Trace(4));
   cout << endl << vect << endl << endl;

   cout << "vect.insert(vect.begin()+1, Trace(5))"    << endl;
   cout << "actions  : ";
   vect.insert(vect.begin()+1, Trace(5));
   cout << endl << vect << endl << endl;

   cout << "vect.shrink_to_fit()"                     << endl;
   cout << "actions  : ";
   vect.shrink_to_fit();
   cout << endl << vect << endl << endl;

   cout << "vect.resize(4)"                           << endl;
   cout << "actions  : ";
   vect.resize(4);
   cout << endl << vect << endl << endl;

   cout << endl;
   cout << "----------------------------------------" << endl;
   cout << "   sortie de main"                        << endl;
   cout << "----------------------------------------" << endl;
   return EXIT_SUCCESS;
}

//---------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
   
   os << "capacity : " << v.capacity() << endl;
   os << "size     : " << v.size()     << endl;
   os << "vecteur  : ";
   
   os << "[";
   for (auto it=v.begin(); it!=v.end(); ++it) {
      if (it!=v.begin())
         os << ", ";
      os << *it;
   }
   os << "]";
   return os;
}

//      ----------------------------------------
//      vector<Trace> v0
//      actions  :
//      capacity : 0
//      size     : 0
//      vecteur  : []
//
//      vect.reserve(2)
//      actions  :
//      capacity : 2
//      size     : 0
//      vecteur  : []
//
//      vect.push_back(Trace(1))
//      actions  : Ci(1) CD(1) D(0)
//      capacity : 2
//      size     : 1
//      vecteur  : [1]
//
//      vect.push_back(Trace(2))
//      actions  : Ci(2) CD(2) D(0)
//      capacity : 2
//      size     : 2
//      vecteur  : [1, 2]
//
//      vect.push_back(Trace(3))
//      actions  : Ci(3) CD(3) CD(2) CD(1) D(0) D(0) D(0)
//      capacity : 4
//      size     : 3
//      vecteur  : [1, 2, 3]
//
//      vect.insert(vect.begin(), Trace(4))
//      actions  : Ci(4) CD(3) swap(2) =D(2) swap(1) =D(1) swap(4) =D(4) D(0)
//      capacity : 4
//      size     : 4
//      vecteur  : [4, 1, 2, 3]
//
//      vect.insert(vect.begin()+1, Trace(5))
//      actions  : Ci(5) CD(5) CD(4) CD(1) CD(2) CD(3) D(0) D(0) D(0) D(0) D(0)
//      capacity : 8
//      size     : 5
//      vecteur  : [4, 5, 1, 2, 3]
//
//      vect.shrink_to_fit()
//      actions  : CD(3) CD(2) CD(1) CD(5) CD(4) D(0) D(0) D(0) D(0) D(0)
//      capacity : 5
//      size     : 5
//      vecteur  : [4, 5, 1, 2, 3]
//
//      vect.resize(4)
//      actions  : D(3)
//      capacity : 5
//      size     : 4
//      vecteur  : [4, 5, 1, 2]
//
//
//      ----------------------------------------
//         sortie de main
//      ----------------------------------------
//      D(2) D(1) D(5) D(4) Program ended with exit code: 0
