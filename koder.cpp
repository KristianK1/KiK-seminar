#include<stdio.h>
#include<stdlib.h>

#include<iostream>
#include<string.h>

#define brZnakova 90
#define brZnakova2 8100
#define brZnakova3 729000

#define Ncombs 36

char* Popis[36] = {
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
	" o"
};


//char* Popis[36] = {
//"e ",
//"a ",
//"i ",
//"o ",
//"je",
//" s",
//"je ",
//" n",
//"u ",
//" je ",
//" p",
//" je",
//"na",
//", ",
//" j",
//" i",
//" d",
//" o",
//" se ",
//"li",
//"da",
//". ",
//" na",
//" se",
//"ko",
//"ti",
//"ra",
//"da ",
//"ni",
//" pr",
//"ne",
//" u",
//" da ",
//"se ",
//" k",
//" po",
//
//};

char tekst2[3];
char tekst3[4];
char tekst4[5];
char tekst5[6];
	
	
int find(){
	for(int i = 0; i<Ncombs; i++){
		if(strcmp(Popis[i], tekst5)==0){
			//printf("Naden za 5  |%s|\n", tekst5);
			return 4;
		}
		if(strcmp(Popis[i], tekst4)==0){
			//printf("Naden za 4  |%s|\n", tekst4);
			return 3;
		}
		if(strcmp(Popis[i], tekst3)==0){
			//printf("Naden za 3  |%s|\n", tekst3);
			return 2;
		}
		if(strcmp(Popis[i], tekst2)==0){
			//printf("Naden za 2  |%s|\n", tekst2);
			return 1;
		}
	}
	return 0;
}

char next(FILE *f){
	char c=fgetc(f);
	if(c==EOF) return EOF;

	tekst2[0]=tekst2[1];
	tekst2[1]=c;
	
	tekst3[0]=tekst3[1];
	tekst3[1]=tekst3[2];
	tekst3[2]=c;
	
	tekst4[0]=tekst4[1];
	tekst4[1]=tekst4[2];
	tekst4[2]=tekst4[3];
	tekst4[3]=c;
	
	tekst5[0]=tekst5[1];
	tekst5[1]=tekst5[2];
	tekst5[2]=tekst5[3];
	tekst5[3]=tekst5[4];
	tekst5[4]=c;
	
//	printf("%s\n", tekst2);
//	printf("%s\n", tekst3);
//	printf("%s\n", tekst4);
//	printf("%s\n\n", tekst5);
	return c;
}



int main(){
	int saved_places = 0;
	
//	FILE *f = fopen("cetvrti_svjetski_rat_HRV.txt","r");
//	FILE *f = fopen("testFile.txt","r");
//	FILE *f = fopen("Harry Potter books/TXT/HP_ALL.txt","r");
//	FILE *f = fopen("bible.txt","r");
//	FILE *f = fopen("TFIOS.txt","r");
	FILE *f = fopen("gatsby.txt","r");
//	FILE *f = fopen("wiki_hrv.txt","r");

	tekst2[2]='\0';
	tekst3[3]='\0';
	tekst4[4]='\0';
	tekst5[5]='\0';
	

	if(f==NULL){
		printf("nema fajla");
		return 7;
	}
	
	char c = fgetc(f);
	tekst2[0] = c;
	tekst3[0] = c;
	tekst4[0] = c;
	tekst5[0] = c;
	c = fgetc(f);
	tekst2[1] = c;
	tekst3[1] = c;
	tekst4[1] = c;
	tekst5[1] = c;
	c = fgetc(f);
	tekst3[2] = c;
	tekst4[2] = c;
	tekst5[2] = c;
	c = fgetc(f);
	tekst4[3] = c;
	tekst5[3] = c;
	c = fgetc(f);
	tekst5[4] = c;
	
	
	int saved = find();
	
	saved_places+=saved;
	
	
	for(int i=0;i<saved;i++) next(f);
	
	
	int n=0;
	while(1){
		//printf("NEW LOOP\n\n");
		
		if(next(f)==EOF) {
			break;
		}
		n++;
		
		saved = find();
		saved_places+=saved;
		for(int i=0;i<saved;i++) {
			n++;
			if(next(f)==EOF) break;
		}
		
	}
	printf("saved: %d, total: %d. %.2f\n", saved_places, n, 100.0*saved_places/n);
	return 0;
}
