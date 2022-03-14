#include "library.h"


int insert(char* s, char* p, char* o) {
	/* assert vérifie si les SPO sont des strings convenables */
	assert(s);
	assert(p);
	assert(o);

	/* dans insert on crée un noeud temp avec un espace alloué dynamiquement */
	struct TripleNode *temp = (struct TripleNode*)malloc(sizeof(struct TripleNode)); 

	if (temp==NULL) {
		fprintf(stderr, "Couldn't allocate memory\n");
		return 1;
	}

	/* on assigne les strings de temp avec ceux reçus en arguments de insert */
    temp->triple.s = s;
	temp->triple.p = p;
	temp->triple.o = o; 
    temp->next = NULL; 

	/* si la file dans laquelle on garde tous les triplets est vide,
	 on assigne son front et rear
	*/
	if (queue->front == NULL) { 
       queue->front = queue->rear = temp; 
       return 0; 
    }

	/* si la file existe déjà on pose simplement le nouveau noeud à la fin et on décalle rear */
	queue->rear->next = temp; 
    queue->rear = temp;

	return 0; 
}