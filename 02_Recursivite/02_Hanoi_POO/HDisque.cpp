/**
  Constructeur par defaut (tableau)
*/
HDisque::HDisque()
: m_taille(0), m_szjeu(1)
{}

/**
  Constructeur normal
  @param[in] s - taille du jeu
  @param[in] t - taille du disque
 */  
HDisque::HDisque(int s, int t)
: m_taille(t), m_szjeu(s)
{}

/**
  Accesseur de la taille du disque
  @return la taille du disque
*/
int HDisque::getTaille() const
{
  return m_taille;
}

/**
  Equivalent "string" du disque
  @return Equivalent "string" du disque
*/
string HDisque::toString() const
{
  int nespaces = (getTaille() == 0 ? m_szjeu-1U : m_szjeu-getTaille());
  return string(nespaces, ' ')
       + (getTaille() == 0 ? "|" : string(2*getTaille()-1, '-'))
       + string(nespaces, ' ')
       + " ";
}

