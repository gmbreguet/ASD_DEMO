//---------------------------------------------------------
// Fichier        : 04_Liste_Dynamique.cpp
// Version        : 02 - 2022-03-02
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer une liste dynamique
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>

using namespace std;

//---------------------------------------------------------
// Définition du noeud en tant que struct
template <typename T>
struct Noeud {
    T donnees;
    Noeud <T>* suivant;
    // Pour définir une liste doublement chaînée
    // Noeud <T>* precedent;  
};

//---------------------------------------------------------
// Définition de la classe Liste
template <typename T>
class Liste {
    private:
        Noeud <T>* entete;
        int compteur;
        Noeud <T>* CreerNoeud (const T& valeur);
     
    public:
        Liste ();
        ~Liste ();
        void inserer (int pos, const T& valeur);
        void supprimer (int pos);
        T& getNoeud (int pos) const;
        void afficher () const;
        int taille () const;
};

//---------------------------------------------------------
template <typename T>
Noeud <T>* Liste <T> :: CreerNoeud (const T& valeur){
    Noeud <T>* temp = new Noeud <T>;
    temp -> donnees = valeur;
    temp -> suivant = NULL;
    return temp;
}

//---------------------------------------------------------
// Constructeur
template <typename T>
Liste <T> :: Liste ():entete (NULL), compteur (0) {}

//---------------------------------------------------------
// Destructeur
template <typename T>
Liste <T> :: ~Liste () {
    Noeud <T>* del = entete;
    while (entete){
        entete = entete -> suivant;
        delete del;
        del = entete;
    }
}

//---------------------------------------------------------
template <typename T>
void Liste <T> :: inserer (int pos, const T& valeur) {
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

//---------------------------------------------------------
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

//---------------------------------------------------------
template <typename T>
int Liste <T> :: taille () const {
    return compteur;
}

//---------------------------------------------------------
template <typename T>
void Liste <T> :: afficher () const {
    if (compteur == 0){
        cout << "La liste est vide!" << endl;
        return;
    }
    Noeud <T>* courant = entete;
    while (courant != 0){
        cout << courant -> donnees << endl;
        courant = courant -> suivant;
    }
}

//---------------------------------------------------------
int main() {

   return EXIT_SUCCESS;
}

