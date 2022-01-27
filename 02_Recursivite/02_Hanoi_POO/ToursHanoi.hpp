#ifndef TOURSHANOI_CLASS
#define TOURSHANOI_CLASS
#include <iostream>
#include <string>
using namespace std;

/**
  Les Tours de Hanoi
*/
#include "HTour.hpp"
const int NMAXTOURS = 3;
class ToursHanoi
{
  public:
    explicit ToursHanoi(int n);
    void afficherTours() const;
    void jouer();
  private:
    void deplacer(int o, int d);
    void hanoi(int n, int orig, int dest, int inter);
    void initialiser();
    
    HTour m_tours[NMAXTOURS]; // les tours
    int m_hauteur; // nombre de disques
    
    int m_ndeplts; // nombre de deplacements
};
#include "ToursHanoi.cpp"
#endif
