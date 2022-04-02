#ifndef LISTE_CPP
#define LISTE_CPP
 
#include "liste.h"
 
// Constructeur
template <typename T>
Liste <T> :: Liste ():entete (NULL), compteur (0) {}
 
// Destructeur
template <typename T>
Liste <T> :: ~Liste ()
{
    Noeud <T>* del = entete;
    while (entete){
        entete = entete -> suivant;
        delete del;
        del = entete;
    }
}
 
template <typename T>
Noeud <T>* Liste <T> :: CreerNoeud (const T& valeur){
    Noeud <T>* temp = new Noeud <T>;
    temp -> donnees = valeur;
    temp -> suivant = NULL;
    return temp;
}
 
template <typename T>
void Liste <T> :: inserer (int pos, const T& valeur)
{
    if (pos < 0 || pos > compteur){
        cout << "Erreur! La position est invalide." << endl;
        return;
    }
    Noeud <T>* nouveau = CreerNoeud (valeur);
 
    //Insertion au début
    if (pos == 0){
        nouveau -> suivant = entete;
        entete = nouveau;
    }
    // Insertion au milieu 
    else{
        Noeud <T>* courant = entete;
        for (int i = 1; i < pos; i++){
            courant = courant -> suivant;
        }
        nouveau -> suivant = courant -> suivant;
        courant -> suivant = nouveau;
    }
    compteur++;
}
 
template <typename T>
void Liste <T> :: supprimer (int pos){
    if (pos < 0 || pos > compteur-1){
        cout << "Erreur! La position est invalide." << endl;
        return;
    }
    if (pos == 0){
        Noeud <T>* del = entete;
        entete = entete -> suivant;
        delete del;
    }
    else{
        Noeud <T>* courant = entete;
        for (int i = 0; i < pos-1; i++){
            courant = courant -> suivant;
        }
        Noeud <T>* del = courant -> suivant;
        courant -> suivant = courant -> suivant -> suivant;
        delete del;
    }
    compteur--;
}
 
template <typename T>
T& Liste <T> :: getNoeud (int pos) const {
    if (pos < 0 || pos > compteur-1){
        cout << "Erreur! La position est invalide";
        assert (false);
    }
    else if (pos == 0){
        return entete -> donnees;
    }
    else{
        Noeud <T>* courant = entete;
        for (int i = 0 ; i < pos ; i++){
            courant = courant -> suivant;
        }
        return courant -> donnees;
    }
}
 
template <typename T>
void Liste <T> :: afficher () const {
    if (compteur == 0){
        cout << "La liste est vide!" << endl;
        return;
    }
    Noeud <T>* courant = entete;
    while (courant != 0){
        cout << courant -> donnees < endl;
        courant = courant -> suivant;
    }
}
 
template <typename T>
int Liste <T> :: taille () const{
    return compteur;
}
#endif
