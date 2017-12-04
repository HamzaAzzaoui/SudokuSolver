#include "Principal.h"
#define taille 9

//---DEBUT DES FONCTIONS POUR L'ALGO BRUTE FORCE------------------------------------------------------------------------------------------------------------

int ilEstPresent2fois(int t[], int x){
    int ilyest=0;
    int i=0;
    for(i=0; i<taille; i++){
        if(t[i]==x){
            ilyest++;
        }
    }
    return ilyest;
}

int parcoursTableau1D(int tab[]){
    int i=0;
    for(i=0;i<taille;i++){
        if(ilEstPresent2fois(tab,tab[i])>1){
            return 1;
        }
    }
    return 0;
}

int parcoursColonnes(int tab[taille][taille]){
    int i=0;
    for(i=0;i<taille;i++){
        if(parcoursTableau1D(tab[i])==1){
            return 1;
        }
    }
    return 0;
}

void obtenirTableauLigneLigne(int tab[taille][taille], int i, int table[]){
    int j=0;
    for(j=0; j<taille; j++){
        table[j]==tab[i][j];
    }
}

int parcoursLignes(int tab[taille][taille]){
    int table[taille];
    int i=0;
    for(i=0;i<taille;i++){
        obtenirTableauLigneLigne(tab,i,table);
        if(parcoursTableau1D(table)==1){
            return 1;
        }
    }
    return 0;
}

void obtenirTableauSousTableauLigne(int tab[taille][taille], int colonne, int ligne, int tableau[]){
    int i=0;
    int j=0;
    int compt=0;
    for(i=colonne; i<colonne+3; i++){
        for(j=ligne; j<ligne+3; j++){
            tableau[compt]=tab[i][j];
            compt++;
        }
    }
}

int parcoursSousTableau(int tab[taille][taille]){
    int table[taille];
    int i=0;
    int j=0;
    for(i=0;i<7;i=i+3){
        for(j=0;j<7;j=j+3){
            obtenirTableauSousTableauLigne(tab,i,j,table);
            if(parcoursTableau1D(table)==1){
                return 1;
            }
        }
    }
    return 0;
}

int verificationTotal1(int tab[taille][taille]){
    if(parcoursColonnes(tab)==1 || parcoursLignes(tab)==1 || parcoursSousTableau(tab)==1){
        return 1;
    }
    else{
        return 0;
    }
}

int ilyaZero(int tab[taille][taille]){
    int i=0;
    int j=0;
    for(i=0; i<taille; i++){
        for(j=0; j<taille; j++){
            if(tab[i][j]==0){
                return 1;
            }
        }
    }
    return 0;
}

void recup_1_0_TOTAL(int tab[taille][taille], int T[taille][taille]){
    int i=0;
    int j=0;
    for(i=0;i<taille;i++){
            for(j=0;j<taille;j++){
                if(tab[i][j]!=0){
                    T[i][j]=1;
                }
                else{
                    T[i][j]=0;
                }
            }
    }
}

void remplirBruteForce(int tab[taille][taille], int T[taille][taille]){
    TypeResolution=2;
    while(verificationTotal1(tab)==1 && ilyaZero(tab)==1){
        int i=0;
        int j=0;
        for(i=0;i<taille;i++){
            for(j=0;j<taille;j++){
                if(T[i][j]==0){
                    int compt=0;
                    if(verificationTotal2(tab,i,j,i-i%3,j-j%3,tab[i][j])==1){
                    tab[i][j]=compt;
                    while(verificationTotal2(tab,i,j,i-i%3,j-j%3,compt)==1){
                            if(compt>10){
                                compt=0;
                            }
                            compt++;
                        }
                        tab[i][j]=compt;
                    }
                    }
                }
            }
        }
    }

//---FIN DES FONCTIONS POUR L'ALGO BRUTE FORCE--------------------------------------------------------------------------------------------------------------

//---DEBUT DES FONCTIONS POUR BACKTRACKING------------------------------------------------------------------------------------------------------------------
int verificationTotal2(int tab[taille][taille], int ligne, int colonne, int debut, int fin, int x){
    int i=0;
    for(i=0;i<taille;i++){
        if(tab[ligne][i]==x){
            return 1;
        }
    }
    int p=0;
    for(p=0;p<taille;p++){
        if(tab[p][colonne]==x){
            return 1;
        }
    }
    int k=0;
    int j=0;
    for(k=0;k<3;k++){
        for(j=0;j<3;j++){
            if(tab[k+debut][j+fin]==x){
                return 1;
            }
        }
    }
    return 0;
}

int TrouverCasesVides(int tab[taille][taille], int tableau[]){
    int i=0;
    int j=0;
    for(i=0; i<taille; i++){
        for(j=0; j<taille; j++){
            if(tab[i][j]==0){
                tableau[0]=i;
                tableau[1]=j;
                return 1;
            }
        }
    }
    return 0;
}

int resoudreSudokuBackTrack(int tab[taille][taille]){
    TypeResolution=1;
    int table[2];
    if(TrouverCasesVides(tab,table)==0){
        return 1;
    }
    int x;
    for(x=1;x<=taille;x++){
        if(verificationTotal2(tab,table[0],table[1],table[0]-table[0]%3,table[1]-table[1]%3,x)==0){
            tab[table[0]][table[1]]=x;
            if(resoudreSudokuBackTrack(tab)==1){
                return 1;
            }
            else{
                tab[table[0]][table[1]]=0;
            }
        }
    }
    return 0;
}
//---FIN DES FONCTIONS POUR BACKTRACKING--------------------------------------------------------------------------------------------------------------------

int BruteForceOuBacktrack(int tab[taille][taille]){
    int compt=0;
    int i=0;
    int j=0;
    for(i=0; i<taille; i++){
        for(j=0; j<taille; j++){
            if(tab[i][j]==0){
                compt++;
            }
        }
    }
    return compt;
}

void ConseilDeMethode(int tab[taille][taille]){
    if(BruteForceOuBacktrack(tab)>9){
         printf("\n");
         printf("   Apres etude de la grille on vous coinseil d'utiliser le backtracking ");
         printf("\n");
    }
    else{
        printf("\n");
        printf("     Apres etude de la grille on vous conseil d'utiliser le brute-force ");
        printf("\n");
    }
}

//---DEBUT DES FONCTIONS THREADS----------------------------------------------------------------------------------------------------------------------------------
void *remplirBackTrackThread(int *tab[taille][taille]){
    pthread_mutex_lock(& MTX);
    resoudreSudokuBackTrack(tab);
    pthread_mutex_unlock(& MTX);
    pthread_cond_signal (& COND);
    pthread_exit(NULL);
}

void *remplirBruteForceThread(int *tab[taille][taille]){
    pthread_mutex_lock(& MTX);
    recup_1_0_TOTAL(tab,TAB);
    remplirBruteForce(tab,TAB);
    pthread_mutex_unlock(& MTX);
    pthread_cond_signal (& COND);
    pthread_exit(NULL);
}

void *affichetableauTotalThread(int *tab[taille][taille]){
    pthread_cond_wait (& COND, & MTX);
    affichetableauTotal(tabprincipal);
    pthread_exit(NULL);
}

void *ecrireDansFichierThread(void *t[3]){
    pthread_cond_wait (& COND, & MTX);
    creationFichier(t[0],t[1],t[2]);
    pthread_exit(NULL);

}

//---FIN DES FONCTIONS THREADS-------------------------------------------------------------------------------------------------------------------------------
