using namespace std;
 
// Définition du noeud en tant que struct
template <typename T>
struct Noeud {
    T donnees;
    Noeud <T>* suivant;
};
 
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
#endif

