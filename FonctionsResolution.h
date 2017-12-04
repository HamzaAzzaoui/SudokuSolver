#define taille 9

int ilEstPresent2fois(int t[], int x);
int parcoursTableau1D(int tab[]);
int parcoursColonnes(int tab[taille][taille]);
void obtenirTableauLigneLigne(int tab[taille][taille], int i, int table[]);
int parcoursLignes(int tab[taille][taille]);
void obtenirTableauSousTableauLigne(int tab[taille][taille], int colonne, int ligne, int tableau[]);
int parcoursSousTableau(int tab[taille][taille]);
int verificationTotal1(int tab[taille][taille]);
int ilyaZero(int tab[taille][taille]);
void recup_1_0_TOTAL(int tab[taille][taille], int T[taille][taille]);
void remplirBruteForce(int tab[taille][taille], int T[taille][taille]);

int verificationTotal2(int tab[taille][taille], int ligne, int colonne, int debut, int fin, int x);
int TrouverCasesVides(int tab[taille][taille], int tableau[]);
int resoudreSudokuBackTrack(int tab[taille][taille]);

int BruteForceOuBacktrack(int tab[taille][taille]);
void ConseilDeMethode(int tab[taille][taille]);

void *remplirBackTrackThread(int *tab[taille][taille]);
void *remplirBruteForceThread(int *tab[taille][taille]);
void *affichetableauTotalThread(int *tab[taille][taille]);
void *ecrireDansFichierThread(void *t[2]);
