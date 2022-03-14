#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//typedef struct triplet_struct {char *s; char *p; char *o;} triplet;

typedef struct node_struct {
    //triplet s,p,o;
    char *s, *p, *o;
    struct node * next;
} node;

node * head;// = NULL;
node * last;// = NULL;



const char * to_string(node *n) {
	char * str = malloc(8 + strlen(n->s) + strlen(n->p) + strlen(n->o));
	sprintf(str, "s:%s p:%s o:%s", n->s, n->p, n->o);
	return str;
}

void print_list(node * head) {
    node * current = head;
	printf("print_list() -------\n");
    while (current != NULL) {
//        printf("%d\n", current-> s,p,o);
		char * str = to_string(current);
	    printf("%s\n",str);
	    free(str);
	    current = current->next;
    }
	printf("--------------------\n");
}

node* newTriple(char* s, char* p, char* o)
{
	// Allocate memory for new triple
	node* triple = (struct triple*)malloc(sizeof(struct triple *));
	if(triple == NULL) {
		// failed to allocate memory
		fprintf(stderr, "Couldn't allocate memory\n");
		exit(0);
	}

	// Assign data to this triple
	triple->s = s;
	triple->p = p;
	triple->o = o;

	// Initialize next triple as NULL
	triple->next = NULL;
	return(triple);
}




// NOTE : Ne pas enlever insert et match !!!!!!!!!!!!!!

int insert(char *s, char *p, char *o) {
	node *n = newTriple(s,p,o);
	if ((void *) head == NULL) {
		head = n;
		last = head;
	} else {
		last->next = n;
		last = n;
	}
	printf("added triplet : %s , %s , %s \n",last->s,last->p,last->o);
	return 0;
}

node * match(char* s, char* p, char* o, long result) {
	if(result < 1) {
		return 0;
	}
	int count = 1, i = 0;
	node* localTriple = head;

	while (localTriple != NULL){
		if ( (strcmp(localTriple->s, s)==0 && strlen(localTriple->s)>0)
		|| (strcmp(localTriple->p, p)==0 && strlen(localTriple->p)>0)
		|| (strcmp(localTriple->o, o)==0 && strlen(localTriple->s)>0) ) {
			if(count < result) {
				count++;
			} else {
//				localTriple->s = s;
//				localTriple->p = p;
//				localTriple->o = o;
				printf("match at position %d containing : s:%s p:%s o:%s\n",i,localTriple->s,localTriple->p,localTriple->o);
				return localTriple;
			}

		}
		++i;
		localTriple = localTriple->next;
	}

	return NULL;
}


// NOTE : Ce n'est pas une pile, pourquoi aurait-on besoin d'une méthode "pop" enlevant la tête de liste?

//int pop(node ** head) {
node pop(node * head, node * next_node) {
//    int ret_val = -1;
	node ret_val;
//    node * next_node = NULL;

//    if (head == NULL) {
////        return -1;
//    }

//    next_node = (*head).next;
    next_node = head->next;     // NOTE : les deux fonctionnent et expriment la même chose.
//    ret_val = (*head)-> s,p,o;
    ret_val = * head;
    free(head);
    head = next_node;
    head = head->next;

    return ret_val;
}

// NOTE :  les pointeurs doubles sont utilisés pour des arrays à deux dimension. Ici head correspond au premier noeud et non pas à toute la liste!

//int remove_by_value(node ** head, triplet s,p,o) {
/*int*/ void remove_by_value(node * head, node * to_remove) {
//	if (head == NULL) {
//		return NULL;
//	}

	node *previous = NULL, * current = head;

    while (current != NULL) {

//    if ((*head)-> s,p,o == s,p,o) {
//	        return pop(head);
//    }

//	    previous = current = (*head)->next;

//        if (current-> s,p,o == s,p,o) {
		if (current == to_remove) {
			if (current == head) {
				head = current->next;
			} else if (current == last) {
				last = previous;
				previous->next = NULL;
			} else {
				previous->next = current->next;
			}

//			current  = (node *) current->next;
			free(current);
			return;
//            return s,p,o;

//			return current;

        }

	    previous = current;
	    current = current->next;
//        previous = current;
    }
//    return -1;
}

//void delete_list(node *head) {
//    node  *current = head,
//            *next = head;
//
//    while (current) {
//        next = current->next;
//        free(current);
//        current = next;
//    }
//}

int main(void) {
//    node * test_list = malloc(sizeof(node));

//    test_list-> s,p,o = 1;
//    test_list->next = malloc(sizeof(node));
//    test_list->next-> s,p,o = 2;
//    test_list->next->next = malloc(sizeof(node));
//    test_list->next->next-> s,p,o = 3;
//    test_list->next->next->next = malloc(sizeof(node));
//    test_list->next->next->next-> s,p,o = 4;
//    test_list->next->next->next->next = NULL;
	insert("a","b","c");
	insert("Hello","world","!");
	insert("a","third","triplet");
	node* first_node = match("a","","",1);
	node* second_node = match("","world","",1);
	node* third_node = match("a","","",2);

//    remove_by_value( & test_list, 3); // on doit référencer le struct lui-même, pas un pointeur virtuel avec " & "
    remove_by_value( head, third_node);

    print_list(head);
//    delete_list(test_list);

	printf("end of the program\n");
    return EXIT_SUCCESS;
}

/*liste triée*/
//void sort(List *print_list){
//    Node *head , *p, *q, *last, *end;/*p et q permettent de parcourrir la liste*/
//    int permut;
//
//    head = print_list->first;
//    if(head == NULL){
//        printf("Empty\n");
//    }else{
//        do{
//            head = print_list->first;
//            last = print_list->last;
//            end = print_list->last;
//            p = head;
//            q = p->next;
//            permut = 0;
//            while(p != end){
//                if(p-> s,p,o > q-> s,p,o){
//                    permut = 1;
//                    p->next = q->next;
//                    q->next = p;
//                    if(p == print_list->first){
//                        last->next = print_list->first;
//                        head = q;
//                    }else if(q == print_list->last){
//                        print_list->last = p;
//                    }else{
//                        head->next = q;
//                        head = head->next;
//                    }
//                }else{
//                    p = q;
//                    if((p != print_list->first) && (p != (print_list->first)->next))
//                        head = head->next;
//                }
//                q = p->next;
//            }
//        }while(permut == 1);
//        printf("The list has been sort\n");
//    }
//}
