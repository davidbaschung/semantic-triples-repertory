#include "library.h"

int match(char* s, char* p, char* o, long result) {
	/* assert vérifie si les SPO sont des strings convenables */
	assert(s);
	assert(p);
	assert(o);

	/* on vérifie que result n'est pas négatif */
	if (result < 0) {
		printf("Result must be 0 or higher\n");
		return 1;
	}

	/* on utilise countdown pour compter le nombre de match */
	long countdown = result;
	/* on utilise temp comme noeud qui parcourt la file */
	TripleNode *temp = queue->front;

	if (temp==NULL) {
		fprintf(stderr, "Couldn't allocate memory\n");
		return 1;
	}
	
	/* on vérifie que s, p et o ont une valeur au début et on cherche un SPO correspondant */
	if (s[0] != 0 && p[0] != 0 && o[0] != 0) {
		while (temp != NULL) {
			/* on compare les string de l'argument avec ceux du noeuds temp */
			if ( (strcmp(temp->triple.s, s)==0) && (strcmp(temp->triple.p, p)==0) && (strcmp(temp->triple.o, o)==0) ) {
				/* si on trouve un match on baisse le countdown et une fois le countdown à 0, on a trouvé le match qu'on veut */
				if (countdown != 0) {
					countdown--;
				} else if (countdown == 0) {
					printf("matched triplet : %s , %s , %s \n", temp->triple.s, temp->triple.p, temp->triple.o);
					return 0;
				}
			}
			/* on parcours la liste */
			temp = temp->next;
		}
	}

	/* vérification pour PO */
	if (s[0] == 0 && p[0] != 0 && o[0] != 0 ) {
		while (temp != NULL) {
			if ( (strcmp(temp->triple.p, p)==0) && (strcmp(temp->triple.o, o)==0) ) {
				if (countdown != 0) {
					countdown--;
				} else if (countdown == 0) {
					printf("matched triplet : %s , %s , %s \n", temp->triple.s, temp->triple.p, temp->triple.o);
					/* lorsqu'on trouve notre match, on modifie le string S vide avec le s du triplet trouvé */
					strcpy(s, temp->triple.s);
					return 0;
				}
			}
			temp = temp->next;
		}
	}

	/* vérification pour SO */
	if (s[0] != 0 && p[0] == 0 && o[0] != 0 ) {
		while (temp != NULL) {
			if ( (strcmp(temp->triple.s, s)==0) && (strcmp(temp->triple.o, o)==0) ) {
				if (countdown != 0) {
					countdown--;
				} else if (countdown == 0) {
					printf("matched triplet : %s , %s , %s \n", temp->triple.s, temp->triple.p, temp->triple.o);
					strcpy(p, temp->triple.p);
					return 0;
				}
			}
			temp = temp->next;
		}
	}

	/* vérification pour O */
	if (s[0] == 0 && p[0] == 0 && o[0] != 0 ) {
		while (temp != NULL) {
			if ( (strcmp(temp->triple.o, o)==0 && strlen(temp->triple.o)>0) ) {
				if (countdown != 0) {
					countdown--;
				} else if (countdown == 0) {
					printf("matched triplet : %s , %s , %s \n", temp->triple.s, temp->triple.p, temp->triple.o);
					strcpy(s, temp->triple.s);
					strcpy(p, temp->triple.p);
					return 0;
				}
			}
			temp = temp->next;
		}
	}

	/* vérification pour SP */
	if (s[0] != 0 && p[0] != 0 && o[0] == 0) {
		while (temp != NULL) {
			if ( (strcmp(temp->triple.s, s)==0 && (strcmp(temp->triple.p, p)==0) ) )  {
				if (countdown != 0) {
					countdown--;
				} else if (countdown == 0) {
					printf("matched triplet : %s , %s , %s \n", temp->triple.s, temp->triple.p, temp->triple.o);
					strcpy(o, temp->triple.o);
					return 0;
				}
			}
			temp = temp->next;
		}
	}

	/* vérification pour P */
	if (s[0] == 0 && p[0] != 0 && o[0] == 0 ) {
		while (temp != NULL) {
			if ( (strcmp(temp->triple.p, p)==0 && strlen(temp->triple.p)>0) ) {
				if (countdown != 0) {
					countdown--;
				} else if (countdown == 0) {
					printf("matched triplet : %s , %s , %s \n", temp->triple.s, temp->triple.p, temp->triple.o);
					strcpy(s, temp->triple.s);
					strcpy(o, temp->triple.o);
					return 0;
				}
			}
			temp = temp->next;
		}
	}

	/* vérification pour S */
	if (s[0] != 0 && p[0] == 0 && o[0] == 0 ) {
		while (temp != NULL) {
			if ( strcmp(temp->triple.s, s)==0 ) {
				if (countdown != 0) {
					countdown--;
				} else if (countdown == 0) {
					printf("matched triplet : %s , %s , %s \n", temp->triple.s, temp->triple.p, temp->triple.o);
					strcpy(p, temp->triple.p);
					strcpy(o, temp->triple.o);
					return 0;
				}
			}
			temp = temp->next;
		}
	}

	/* on vérifie si on ne trouve pas de match à cause de l'argument result ou si le triplet n'est pas dans la file */
	if (countdown != result) {
	    fprintf(stderr, "There aren't enough results\n");
        return 1;
	} else {
	    fprintf(stderr, "No match\n");
	    return 1;
	}
}
