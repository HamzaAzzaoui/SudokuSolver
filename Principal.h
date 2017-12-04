#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <strings.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

#include "FonctionsResolution.h"
#include "AffichageClientFichier.h"

#define LEPORT 2100
#define taille 9

static pthread_cond_t COND = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t MTX = PTHREAD_MUTEX_INITIALIZER;

static  int tabprincipal[taille][taille];
static int TAB[taille][taille];
static void *tableauPourEcriture[2];
static int TypeResolution=0;

int taille11, taille1, taille2, bd, un_entier;
struct sockaddr_in padin; //adresse du serveur
struct hostent *host; //pointeur vers les info sur serveur

char *name = "127.0.0.1";
struct sockaddr *p_adr;
int *p_lgadr;

int V_connect;
int V_write;
int V_read;
int V_shutdown;
