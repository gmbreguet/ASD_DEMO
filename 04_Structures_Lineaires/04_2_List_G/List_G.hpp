//---------------------------------------------------------
// Demo           : 04_2_List_G
// Fichier        : List_G.hpp
// Version        : 04 - 2023.04.26
// Auteur(s)      : BREGUET Guy-Michel
// But            : forward list
// Modifications  :
// Remarque(s)    : basic methods only
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
   explicit ListIsEmpty(const char*        s) : std::runtime_error(s) {}
};

//---------------------------------------------------
class ListMemFull : public std::runtime_error {
public:
   explicit ListMemFull(const std::string& s) : std::runtime_error(s) {}
   explicit ListMemFull(const char*        s) : std::runtime_error(s) {}
};

//---------------------------------------------------
template <typename T>
class List_G;

//---------------------------------------------------
template <typename T>
struct Cell {
   T        data;
   Cell<T>* next;
};
 
//---------------------------------------------------
// operator <<
template <typename T>
std::ostream& operator<< (std::ostream& os, const List_G<T>& list);

//---------------------------------------------------
// operator <<
template <typename T>
std::ostream& operator<< (std::ostream& os, const Cell<T>& cell);

//---------------------------------------------------
// class List
template <typename T>
class List_G {
   friend std::ostream& operator<< <T>(std::ostream& os, const List_G<T>& list);
   friend std::ostream& operator<< <T>(std::ostream& os, const Cell<T>&   cell);

public:
   List_G();
  ~List_G();

   void     push_front(const T& value);
   void     pop_front();
   void     clear()     noexcept;

   T        front()     const;
   bool     empty()     const noexcept;
   size_t   size()      const noexcept;

   T*       find(const T& value) const;

   template<typename Fonction>
   void forEach(Fonction fonction);

private:
   Cell<T>*    createCell(const T& value = T(),
                          Cell<T>* next  = nullptr);
   Cell<T>*    head;
   size_t      nElement;
};

#include "List_G_Impl.hpp"

#endif /* list_G_HPP */

