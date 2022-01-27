
/**
  Deplace le disque place au sommet de la tour o au sommet de la tour d
  @param[in] o - tour o(rigine)
  @param[in] d - tour d(estination)
*/
void ToursHanoi::deplacer(int o, int d)
{
  HTour &orig = m_tours[o];
  HTour &dest = m_tours[d];
  int top1 = orig.sommet();
  HDisque dk = orig.getDisque(top1);
  orig.pop();
  dest.push(dk);
  
  ++m_ndeplts;
}

/**
  Methode recursive principale
  @param[in] n - nombre de disques
  @param[in] orig - tour origine
  @param[in] dest - tour destination
  @param[in] inter - tour intermediaire
*/
void ToursHanoi::hanoi(int n, int orig, int dest, int inter)
{
  if (n > 0)
  {
    hanoi(n-1, orig, inter, dest);
    deplacer(orig, dest);
    afficherTours();
    hanoi(n-1, inter, dest, orig);
  }
}

/**
  Initialise le jeu
*/
void ToursHanoi::initialiser()
{
  m_tours[0].assign(m_hauteur, false);
  m_tours[1].assign(m_hauteur, true);
  m_tours[2].assign(m_hauteur, true);
  
  m_ndeplts = 0;
}

/**
  Constructeur normal
  @param[in] n - nombre de disques
 */  
ToursHanoi::ToursHanoi(int n)
: m_hauteur(n < NMAXDISQUES ? n : NMAXDISQUES)
{
  if (n >= NMAXDISQUES)
  {
    m_hauteur = NMAXDISQUES;
  }
}

/**
  Affiche l'etat du jeu
*/
void ToursHanoi::afficherTours() const
{
  // Construit l'equivalent "string" des tours
  string s;
  for (int ix = m_hauteur-1; ix >= 0; --ix)
  {
    s += m_tours[0].getDisque(ix).toString();
    s += m_tours[1].getDisque(ix).toString();
    s += m_tours[2].getDisque(ix).toString();
    s += "\n";
  }
  // Construit la "string" du socle
  s += string(6*m_hauteur-1, '*');
  s += "\n";
  // Affiche la chaine du jeu
  cout << s << endl;
}

/**
  Lance le jeu
*/
void ToursHanoi::jouer()
{
  initialiser();
  afficherTours();
  hanoi(m_hauteur, 0, 2, 1);
  cout<<"Nombre de deplacements = "<<m_ndeplts<<endl;
}

