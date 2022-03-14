#include "library.h"

/* erase fonctionne de manière semblable à match */
int erase(char* s, char* p, char* o, long position) {
	assert(s);
	assert(p);
	assert(o);

	/* on vérifie que result n'est pas négatif */
	if (position < 0) {
		fprintf(stderr, "Position must be 0 or higher\n");
		return 1;
	}

	TripleNode *temp = queue->front;
	long countdown = position;

	if (temp==NULL) {
		fprintf(stderr, "Couldn't allocate memory\n");
		return 1;
	}

	if (s[0] != 0 && p[0] != 0 && o[0] != 0 ) {
		/* on vérifie d'abord si le triplet à effacer est dans front */
		if( (strcmp(queue->front->triple.s, s)==0) && (strcmp(queue->front->triple.p, p)==0) && (strcmp(queue->front->triple.o, o)==0) ) {
		    if (countdown != 0) {
		        countdown--;
		    } else if (countdown == 0) {
				/* lorsqu'on trouve le triplet à effacer,
				   on saute d'un noeud par dessus le triplet en question 
				*/
    			queue->front = queue->front->next;
				/* une fois que la file est vider du triplet, on libère aussi la mémoire */
    			free(temp);
    			printf("Triple erased successfully\n");
    			return 0;
		    }
		}
		TripleNode *temp = queue->front->next;
		/* on utilise le noeud prev pour sauter le triplet à effacer */
		TripleNode *prev = queue->front;
		
		while (temp->next != NULL) {
    		if ( (strcmp(temp->triple.s, s)==0) && (strcmp(temp->triple.p, p)==0) && (strcmp(temp->triple.o, o)==0) ) {
    		    if (countdown != 0) {
    		        countdown--;
    		    } else if (countdown == 0) {
					/* on saute le triplet et on libère la mémoire */
        			prev->next = temp->next;
        			free(temp);
        			printf("Triple erased successfully\n");
        			return 0;
    		    }
    		}
			/* on parcourt avec prev et temp */
     		prev = prev->next;
        	temp = temp->next;
		}
		
		/* cas spécial si on est à la fin de la file, afin de bouger le rear */
		if( (strcmp(queue->rear->triple.s, s)==0) && (strcmp(queue->rear->triple.p, p)==0) && (strcmp(queue->rear->triple.o, o)==0) ) {
		    if (countdown != 0) {
		        countdown--;
		    } else if (countdown == 0) {
    			queue->rear = prev;
    			queue->rear->next = NULL;
    			free(temp);
    			printf("Triple erased successfully\n");
    			return 0;
    		}
		}
		if(countdown == position) {
			fprintf(stderr, "Triple doesn't exist\n");
			return 1;
		} else {
			fprintf(stderr, "Not enough triples in the data\n");
			return 1;
		}
		
	} else {
		fprintf(stderr, "Please give 3 strings\n");
		return 1;
	}

}

