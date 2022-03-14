#include "library.h"

int main(int argc, char *argv[]) {
	init();

	printf("P01 : main()\n");

	char myS[100], myP[100], myO[100], *c;
	fflush(stdin);
	printf("Please enter values for a new SPO triplet.\nS : ");
	fgets(myS,sizeof(myS),stdin);
	if ((c = strchr(myS, '\n')) != 0) {
		*c = '\0';
	}
	printf("P : ");
	fgets(myP,sizeof(myP),stdin);
	if ((c = strchr(myP, '\n')) != 0) {
		*c = '\0';
	}
	printf("O : ");
	fgets(myO,sizeof(myO),stdin);
	if ((c = strchr(myO, '\n')) != 0) {
		*c = '\0';
	}
	printf("insert customized triplet : %d\n", insert(myS,myP,myO));
	printf("insert1 : %d\n", insert("SOP2019", "has teacher", "PCM"));
	printf("insert2 : %d\n", insert("SOP2019", "topic is", "C"));
	printf("insert3 : %d\n", insert("test", "test", "test"));
	printf("insert4 : %d\n", insert("PCM", "lastname", "Cudre-Mauroux"));
	printf("insert5 : %d\n", insert("test", "test", "test"));
	
	
	printf("match test test test : %d\n", match("test", "test", "test",0));
	printf("match test test test : %d\n", match("test", "test", "test",1));
	print_list();

	char * p = (char*)malloc(1024*sizeof(char));
    char * o = (char*)malloc(1024*sizeof(char));
	printf("match1 : %d\n", match("SOP2019",p,o,0));
	printf("verifie nouveau p : %s \n", p);
	p[0] = o[0] = 0;
	printf("match2 : %d\n", match("SOP2019",p,o,1));
	p[0] = o[0] = 0;
	printf("match3 : %d\n", match("SOP2019",p,o,2));
	p[0] = o[0] = 0;
	char * s = (char*)malloc(sizeof(char));
	printf("match4 : %d\n", match(s, "topic is", "C", 0));
	print_list();
	erase("test", "test", "test", 2);
	erase("test", "test", "test", 1);
	erase("test", "test", "test", 1);
	erase("test", "test", "test", 0);
	erase("test", "test", "test", 0);
	print_list();
	match("Pas", "de", "match", 2);
}
