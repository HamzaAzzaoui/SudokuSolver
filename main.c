#include "Principal.h"


int main()
{
    int s=0;
    char nomSauvegarde[50];
    char nomSauvegarde2[100][50];
    char nomFichier[50];
    char nomFichier2[100][50];
    int version=0;
    int methode=0;
    int methode2[100];
    int nombreFi=0;
    int i=0;
    pthread_t MethodeThread[100];
    pthread_t ecrireDansFichier;
    pthread_t display;

    printf("                _____________________________________________\n");
    printf("               |                                             |\n");
    printf("               |    Bienvenue dans le solveur de sudoku      |\n");
    printf("               |_____________________________________________|\n");
    printf("\n");
    printf("                --> Choisissez la version que vous voulez <-- \n");
    printf("\n");
    printf("                   - Version 1 Basique du Solveur : 1 -\n");
    printf("             - Version 2 avancee du Solveur avec Threads : 2 -\n");
    printf("          - Version 3 professionnelle du Solveur Serveur-Client : 3 -\n");
    printf("\n");
    printf("                  Veuillez entrez le numero correspondant : ");
    scanf("%d",&version);
    printf("\n");
    switch(version){
        case 1:
        printf("               ----------------Version-1------------------\n");
        printf("               Veuillez entrez le nom du fichier : ");
        scanf("%s",&nomFichier);
        printf("\n");
        lire_fichier_(nomFichier,tabprincipal);
        affichetableauTotal(tabprincipal);
        ConseilDeMethode(tabprincipal);
        printf("\n");
        printf("                --> Choisissez la methode que vous voulez <-- \n");
        printf("\n");
        printf("                           - Bactracking : 1 -\n");
        printf("                           - Brute-Force : 2 -\n");
        printf("\n");
        printf("                  Veuillez entrez le numero correspondant : ");
        scanf("%d",&methode);
        printf("\n");
        switch(methode){
            case 2:
                recup_1_0_TOTAL(tabprincipal,TAB);
                remplirBruteForce(tabprincipal,TAB);
                affichetableauTotal(tabprincipal);
                printf("\n");
                printf("               Veuillez entrez le nom de sauvegarde : ");
                scanf("%s",&nomSauvegarde);
                printf("\n");
                creationFichier(tabprincipal,nomSauvegarde,TypeResolution);
                printf("                 Fichier créé et sauvegardé   !");
            break;
            case 1:
                resoudreSudokuBackTrack(tabprincipal);
                affichetableauTotal(tabprincipal);
                printf("\n");
                printf("               Veuillez entrez le nom de sauvegarde : ");
                scanf("%s",&nomSauvegarde);
                printf("\n");
                creationFichier(tabprincipal,nomSauvegarde,TypeResolution);
                printf("\n");
                printf("                 Fichier créé et sauvegardé   !");
            break;
        }
        break;
        case 2:
               printf("               ----------------Version-2------------------\n");
               printf("               Combien de fichiers voulez vous resoudre ? : ");
               scanf("%d",&nombreFi);
               for(i=0;i<nombreFi;i++){
               printf("               Veuillez entrez le nom du fichier %d : ",(i+1));
               scanf("%s",&nomFichier2[i]);
               printf("\n");
               printf("\n");
               printf("                --> Choisissez la methode que vous voulez <-- \n");
               printf("\n");
               printf("                           - Bactracking : 1 -\n");
               printf("                           - Brute-Force : 2 -\n");
               printf("\n");
               printf("                  Veuillez entrez le numero correspondant : ");
               scanf("%d",&methode2[i]);
               printf("\n");
               printf("\n");
               }
               for(i=0;i<nombreFi;i++){
               printf("          Veuillez entrez le nom de sauvegarde pour le fichier %d : ",(i+1));
               scanf("%s",&nomSauvegarde2[i]);
               }
               printf("\n");
               for(i=0;i<nombreFi;i++){
               lire_fichier_(nomFichier2[i],tabprincipal);
               affichetableauTotal(tabprincipal);
               switch(methode2[i]){
                    case 2:
                        pthread_create(&MethodeThread[i],NULL,remplirBruteForceThread,tabprincipal);
                        tableauPourEcriture[0]=tabprincipal;
                        tableauPourEcriture[1]=nomSauvegarde2[i];
                        tableauPourEcriture[2]=TypeResolution;
                    break;
                    case 1:
                        pthread_create(&MethodeThread[i],NULL,remplirBackTrackThread,tabprincipal);
                        tableauPourEcriture[0]=tabprincipal;
                        tableauPourEcriture[1]=nomSauvegarde2[i];
                        tableauPourEcriture[2]=TypeResolution;
                        break;

                }
                pthread_create(&ecrireDansFichier,NULL,ecrireDansFichierThread,tableauPourEcriture);
                //pthread_create(&display,NULL,affichetableauTotalThread,tabprincipal);
                pthread_join(MethodeThread[i],NULL);
                //pthread_join(display,NULL);
                pthread_join(ecrireDansFichier, NULL);
                printf("\n");
                printf("                 Fichier créé et sauvegardé   !");
                printf("\n");
            }
        break;
        case 3:
               printf("               ----------------Version-3------------------\n");
               printf("\n");
               s=CreationSocketEtConnexion(V_connect,padin,"127.0.0.1");
               int finSession=2;
               methode=0;
               while (finSession==2) {
                        printf("               Combien de fichiers voulez vous resoudre ? : ");
                        scanf("%d",&nombreFi);
                        V_write=write(s,&nombreFi, sizeof(int));
                        for(i=0;i<nombreFi;i++){
                        printf("               Veuillez entrez le nom du fichier : ");
                        scanf("%s",&nomFichier2[i]);
                        printf("\n");
                        //ConseilDeMethode(tabprincipal);
                        printf("\n");
                        printf("                --> Choisissez la methode que vous voulez <-- \n");
                        printf("\n");
                        printf("                           - Bactracking : 1 -\n");
                        printf("                           - Brute-Force : 2 -\n");
                        printf("\n");
                        printf("                  Veuillez entrez le numero correspondant : ");
                        scanf("%d",&methode2[i]);
                        }
                        for(i=0;i<nombreFi;i++){
                        lire_fichier_(nomFichier2[i],tabprincipal);
                        V_write=write(s,&methode2[i], sizeof(int));
                        printf("                        Grille avant resolution \n");
                        printf("\n");
                        affichetableauTotal(tabprincipal);
                        envoyerAuServeur(s,tabprincipal);
                        if (V_write==-1)
                        {
                            perror("         !!!!   Problème d'ecriture   !!!!!\n");
                            exit(-4);
                        }

                        if (V_write==-1)
                        {
                            perror("         !!!!   Problème d'ecriture   !!!!!\n");
                            exit(-4);
                        }
                        printf("\n");
                        printf("                       Grille apres resolution \n");
                        receptionDuServeur(s,tabprincipal);
                        if (V_read==-1)
                        {
                            perror("         !!!!   Problème de lecture   !!!!!!\n");
                            exit(-4);
                        }
                        affichetableauTotal(tabprincipal);
                        }
                        printf("\n");
                        printf("\n");
                        printf("               Voulez vous mettre fin a la session ? \n");
                        printf("\n");
                        printf("                              1: oui\n");
                        printf("                              2: non : ");
                        scanf("%d",&finSession);
                        printf("\n");

            }
            V_shutdown=shutdown(s,2);
            if (V_shutdown==-1)
            {
                perror("         !!!!   Problème de fin de session   !!!!!\n");
                exit(-4);
            }
            close(s);
        break;

    }
    pthread_exit(NULL);
    return 0;
}
