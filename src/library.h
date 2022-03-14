#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* typedef de la structure des triplets */
typedef struct {
    char *s;
    char *p; 
    char *o;
} triplet;

/* typedef de la structure des noeuds de la file chainée */
typedef struct TripleNode { 
    triplet triple; 
    struct TripleNode  *next; 
} TripleNode ; 

/* typedef de la file utilisée */
typedef struct { 
    struct TripleNode *front; 
    struct TripleNode *rear;
} TripleQueue; 

/* déclaration des fonctions utilisées */
void print_list();
int match(char* s, char* p, char* o, long result);
int insert(char* s, char* p, char* o);
int erase(char* s, char* p, char* o, long position);
void init();

/* déclaration de la file utilisée dans le code */
TripleQueue *queue;
