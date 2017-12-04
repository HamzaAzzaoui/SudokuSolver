#include "Principal.h"
#define taille 9

//---DEBUT DES FONCTIONS SERVEUR CLIENT-----------------------------------------------------------------------------------------------------------------------

void receptionDuServeur(int s,int tab[taille][taille]){
    int i=0;
    int j=0;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            V_read = read(s,&tab[i][j],sizeof(int));
        }
    }
}

void envoyerAuServeur(int s,int tab[taille][taille]){
    int i=0;
    int j=0;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            V_write=write(s,&tab[i][j], sizeof(int));
        }
    }
}

int CreationSocketEtConnexion(int V_connect, struct sockaddr_in padin, char *adr_serv){
    int s=socket(AF_INET, SOCK_STREAM, AF_UNSPEC);
    if (s==-1)
    {
        printf("          !!!!!    Erreur de creation socket    !!!!!!\n");
        exit(-1);
    }
    taille11 = sizeof(struct sockaddr_in);
    bzero((char*)&padin,taille11);
    un_entier=inet_aton(adr_serv,&padin.sin_addr);
    padin.sin_port = htons(LEPORT);
    padin.sin_family = AF_INET;
    printf("                 ------ Connexion au serveur...\n");
    V_connect=connect(s,(char*) &padin,taille11);
    if (V_connect==-1)
    {
        perror("       !!!!   Problème d'accord sur l'etablissement de connexion     !!!!\n");
        exit(-4);
    }
    printf("                 ------ Connexion au serveur effectué ------\n");
    return s;
}

//---FIN DES FONCTIONS SERVEUR CLIENT------------------------------------------------------------------------------------------------------------------------

//---DEBUT DES FONCTIONS UTILISANT LES FICHIERS, IL Y A DEUX FONCTIONS, LECTURE ET ECRITURE------------------------------------------------------------------

void creationFichier(int sol[taille][taille], char* nom, int TypeResolution){
    FILE *f=fopen(nom,"w");
    if(f != NULL){
        fprintf(f,"PUZZLE RESOLU: \n");
        int i=0;
        for(i=0;i<taille;i++){
            if(i%3==0){
                fprintf(f,"\n");
            }
            int j=0;
            for(j=0; j<taille; j++){
                if(j%3==0){
                fprintf(f,"  %d ",sol[i][j]);
                }
                else{
                fprintf(f,"%d ",sol[i][j]);
                }
                }
        fprintf(f," ");
        fprintf(f,"\n");
        }
        fprintf(f,"\n");
        if(TypeResolution==1){
            fprintf(f,"-BACTRACKING-");
        }
        else if(TypeResolution==2){
            fprintf(f,"-BRUTE FORCE-");
        }
        fclose(f);
    }
}

void lire_fichier_(char *fichier, int tabprincipal[taille][taille]){
    char chaine[1024];
    FILE *f=fopen(fichier,"r");
    int compt=0;
    int compt2=0;
    while(fscanf(f,"%s",&chaine) > 0){
        //printf("Chaine lue : %s \n", chaine);
        if(chaine[0]=='_' || chaine[0]=='1' || chaine[0]=='2' || chaine[0]=='3' || chaine[0]=='4' || chaine[0]=='5' || chaine[0]=='6' || chaine[0]=='7' || chaine[0]=='8' || chaine[0]=='9'){
                if(chaine[0]=='_'){
                    tabprincipal[compt][compt2]=0;
                    compt2++;
                }
                else{
                    tabprincipal[compt][compt2]=atoi(chaine);
                    compt2++;
                }
                if(compt2==9){
                    compt2=0;
                    compt++;
                }
                if(compt==9){
                return;
                }
        }

    }
    fclose(f);
}

//--FIN DES FONCTIONS SUR LES FICHIERS----------------------------------------------------------------------------------------------------------------------

//---DEBUT DES FONCTIONS D'AFFICHAGE DES GRILLES -----------------------------------------------------------------------------------------------------------

void affichetableau(int tabk []){
    int i=0;
    for(i=0; i<taille; i++){
    if(i==0){
        if(i%3==0){
        if(tabk[i]==0){
          printf("                       _ ");
        }
        else {printf("                       %d ",tabk[i]);}
    }
    else{
        if(tabk[i]==0){
            printf("_ ");
        }
        else{printf("%d ",tabk[i]);}
    }
    }
    else{
    if(i%3==0){
        if(tabk[i]==0){
          printf("  _ ");
        }
        else {printf("  %d ",tabk[i]);}
    }
    else{
        if(tabk[i]==0){
            printf("_ ");
        }
        else{printf("%d ",tabk[i]);}
    }
    }
    printf(" ");
}
}

void affichetableauTotal(int TAB[taille][taille]){
    int i=0;
    for(i=0;i<taille;i++){
    if(i%3==0){
    printf("\n");
    }
    affichetableau(TAB[i]);
    printf("\n");
    }
}

//---FIN DES FONCTIONS D'AFFICHAGE DES GRILLES--------------------------------------------------------------------------------------------------------------
