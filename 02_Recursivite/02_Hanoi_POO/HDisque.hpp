#ifndef TOURSHANOI_DISQUE_CLASS
#define TOURSHANOI_DISQUE_CLASS
#include <string>
using namespace std;

/**
  Un disque est represente par sa taille
*/
class HDisque
{
  public:
    HDisque();
    HDisque(int s, int t);
    int getTaille() const;
    string toString() const;
  private:
    int m_taille; // taille du disque
    int m_szjeu;  // taille du jeu
};
#include "HDisque.cpp"
#endif
