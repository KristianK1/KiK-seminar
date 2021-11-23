#include<stdio.h>
#include<stdlib.h>

#include<iostream>
#include<string.h>

#define brZnakova 90
#define brZnakova2 8100
#define brZnakova3 729000

#define Ncombs 37

char* Popis[Ncombs] = {
	"and",
	" to",
	" an",
	" th",
	"the",
	"he ",
	"ing",
	"ed ",
	"ng ",
	"nd ",
	"e ",
	" t",
	"he",
	"d ",
	"th",
	" a",
	"t ",
	"in",
	"s ",
	" s",
	" h",
	"er",
	", ",
	". ",
	" w",
	" w",
	"ed",
	"an",
	"re",
	"ar",
	"ou",
	"ng",
	"y ",
	"n ",
	"on",
	"nd",
	" o",
};

//char tekst[] = "In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.";

int main(){
//	for(int i=0;i<37;i++){
//		printf("|%s|\n", Popis[i]);
//	}
	
	char tekst2[3];
	char tekst3[4];
	tekst2[2]='\0';
	tekst3[3]='\0';
	
	
	FILE *f = fopen("testFile.txt","r");
//	FILE *f = fopen("Harry Potter books/TXT/HP1.txt","r");
//	FILE *f = fopen("bible.txt","r");
//	FILE *f = fopen("TFIOS.txt","r");
//	FILE *f = fopen("gatsby.txt","r");

	if(f==NULL){
		printf("nema fajla");
		return 7;
	}
	
	char c = fgetc(f);
	tekst2[0] = c;
	tekst3[0] = c;
	c = fgetc(f);
	tekst2[1] = c;
	tekst3[1] = c;
	c = fgetc(f);
	tekst3[2] = c;
	
	printf("%s\n\n", tekst2);
	for(int i=0;i<Ncombs; i++){
		if(strcmp(tekst2, Popis[i])==0){
			printf("lol %d |%s| \n",i, Popis[i]);
		}
	}
	
	
	
	
}





















