#define taille 9

void envoyerAuServeur(int s,int tab[taille][taille]);
void receptionDuServeur(int s,int tab[taille][taille]);
int CreationSocketEtConnexion(int V_connect, struct sockaddr_in padin, char *adr_serv);

void creationFichier(int sol[taille][taille], char* nom, int TypeResolution);
void lire_fichier_(char *fichier, int tabprincipal[taille][taille]);

void affichetableau(int tabk []);
void affichetableauTotal(int TAB[taille][taille]);
