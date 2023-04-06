//---------------------------------------------------------
// Demo           : 04_2_List_G
// Fichier        : List_G_Impl.hpp
// Version        : 03 - 2023.04.06
// Auteur(s)      : BREGUET Guy-Michel
// But            : List_G with exception
// Modifications  :
// Remarque(s)    : très incomplète (déplacement, copie profonde, ...)
//---------------------------------------------------------

//---------------------------------------------------
#ifndef LIST_G_IMPL_HPP
#define LIST_G_IMPL_HPP

//---------------------------------------------------
// friend
//---------------------------------------------------
template <typename T>
std::ostream& operator<< (std::ostream& os, const List_G<T>& List_G) {
   os << "(";
   const Noeud<T>* crt = List_G.head;
   while (crt != nullptr){
      if (crt != List_G.head)
         os << ", ";
      os << crt->data;
      crt = crt->next;
   }
   os << ")";
   return os;
}

//---------------------------------------------------
// Constructeur
template <typename T>
List_G<T>::List_G ()
:head(nullptr), nElement(0) {}

//---------------------------------------------------
// Destructeur
template <typename T>
List_G<T>::~List_G() {

   Noeud<T>* tmp = head;

   while (head) {
      tmp  = head;
      head = head->next;
      destroy_at(tmp);
      delete tmp;
   }
}

//---------------------------------------------------
template <typename T>
T List_G<T>::first() const{
   if (this->nElement == 0)
      throw ListIsEmpty("List is empty");
    return head->data;
}

//---------------------------------------------------
template <typename T>
bool List_G<T>::isEmpty() const{
    return nElement == 0;
}

//---------------------------------------------------
template <typename T>
size_t List_G<T>::size() const{
    return nElement;
}

//---------------------------------------------------
template <typename T>
T* List_G<T>::ptrElement(const T& value) const {
   Noeud<T>* crt = head;
   while (crt and value != crt->data) {
      crt = crt->next;
   }
   return &(crt->data);
}

//---------------------------------------------------
template <typename T>
void List_G<T>::add(const T& value) {

   // réservation mémoire
   Noeud<T>* ptrNew;
   try {
      ptrNew = (Noeud<T>*)::operator new(sizeof(Noeud<T>));
   }
   catch (std::bad_alloc& ba) {
      throw ListIsFull("memory full");
   }

   // construction de l'objet en place
   try {
      new(ptrNew) Noeud<T>{value, head};
   }
   catch(...) {
      delete ptrNew;
      throw;
   }

   // tout ok, connecter le nouvel élément
   head = ptrNew;
   nElement++;
}

//---------------------------------------------------
template <typename T>
void List_G<T>::remove() {
   Noeud<T>* tmp = head;
   head          = head->next;
   delete tmp;
   nElement--;
}

//---------------------------------------------------
template <typename T>
template <typename Fonction>
void List_G<T>::forEach(Fonction fonction) {
   Noeud<T>* crt = head;
   while (crt) {
      crt->data = fonction(crt->data);
      crt = crt->next;
   }
}

#endif /* List_G_SIMPLE_IMPL_HPP */
