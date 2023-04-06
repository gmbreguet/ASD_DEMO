//---------------------------------------------------------
// Demo           : 04_2_List_G
// Fichier        : List_G.hpp
// Version        : 03 - 2023.04.06
// Auteur(s)      : BREGUET Guy-Michel
// But            : List_G with exception
// Modifications  : nommages
// Remarque(s)    : très incomplète (déplacement, copie profonde, ...)
//---------------------------------------------------------

#ifndef LIST_G_HPP
#define LIST_G_HPP

//-------------------------------------------------
#include <iostream>
#include <string>
#include <exception>
#include <memory>       // destroy_at

//-------------------------------------------------
class ListIsEmpty : public std::runtime_error {
public:
   explicit ListIsEmpty(const std::string& s) : std::runtime_error(s) {}
   explicit ListIsEmpty(const char*   s)      : std::runtime_error(s) {}
};

//---------------------------------------------------
class ListIsFull : public std::runtime_error {
public:
   explicit ListIsFull(const std::string& s) : std::runtime_error(s) {}
   explicit ListIsFull(const char*   s)      : std::runtime_error(s) {}
};

//---------------------------------------------------
// Déclaration
template <typename T>
class List_G;

//---------------------------------------------------
// Struct Noeud
template <typename T>
struct Noeud {
   T         data;
   Noeud<T>* next;
};
 
//---------------------------------------------------
// operator <<
template <typename T>
std::ostream& operator<< (std::ostream& os, const List_G<T>& list);

//---------------------------------------------------
// classe list
template <typename T>
class List_G {
   friend std::ostream& operator<< <T>(std::ostream& os, const List_G<T>& list);

public:
   List_G();
  ~List_G();

   T      first()    const;
   bool   isEmpty()  const;
   size_t size()     const;

   T*     ptrElement(const T& value) const;

   void   add(const T& value);
   void   remove();

   template<typename Fonction>
   void   forEach(Fonction fonction);

private:
    Noeud<T>* head;
    size_t    nElement;
};

#include "List_G_Impl.hpp"

#endif /* list_G_HPP */

