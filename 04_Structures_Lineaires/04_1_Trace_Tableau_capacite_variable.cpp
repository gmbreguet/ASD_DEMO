//---------------------------------------------------------
// Fichier        : 04_1_Trace_Tableau_capacite_variable.cpp
// Version        : 01 - 2022-04-14
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
Trace f1(int i)            { cout << "f1 : "; return Trace(i); }
Trace f2(Trace t)          { cout << "f2 : "; return t;        }
Trace f3(const Trace& t)   { cout << "f3 : "; return t;        }

//---------------------------------------------------------
int main() {

   cout << endl;
   cout << "----------------------------------------" << endl;
   cout << "   constructeurs"                         << endl;
   cout << "----------------------------------------" << endl;
   cout << "vector<Trace> v0;";
   vector<Trace> v0;
   cout << endl;


   cout << "vect(3, Trace(2)) : ";
   vector<Trace> vect(3, Trace(2));              cout << endl;

   cout << "push_back         : ";
   vect.push_back(trace1a);                      cout << endl;

   cout << "emplace_back      : ";
   vect.emplace_back(trace1a);                   cout << endl;
   cout << endl;



   cout << endl;
   cout << "----------------------------------------" << endl;
   cout << "   sortie de main"                        << endl;
   cout << "----------------------------------------" << endl;
   return EXIT_SUCCESS;
}

