#include<stdio.h>
#include<stdlib.h>


#define brZ 90

char Znakovi[brZ] = "0123456789QWERTZUIOPŠÐASDFGHJKLÈÆŽÆYXCVBNMqwertzuiopšðasdfghjklèæžyxcvbnm,.-:()#%&?!ÔÇö\n ";
int main(){
	long int x = 0;
	long int total = 0;
	
//	FILE *f = fopen("testFile.txt","r");
//	FILE *f = fopen("Harry Potter books/TXT/HP_ALL.txt","r");
//	FILE *f = fopen("Harry Potter books/TXT/HP4.txt","r");

	FILE *f = fopen("bible.txt","r");
//	FILE *f = fopen("TFIOS.txt","r");
//	FILE *f = fopen("gatsby.txt","r");
//	FILE *f = fopen("wiki_hrv.txt","r");


	if(f==NULL){
		printf("nema fajla");
		return 7;
	}
	
	char c;
	while(true){
		c=fgetc(f);
		if(c==EOF) break;
		total++;
		//printf("hello\n");
		if(total%1000==0) printf("%d\n", total);
		
		int i=0;
		for(i=0;i<brZ;i++){
			if(c==Znakovi[i]) {
				x++;
				//printf("yes");
				break;	
			}
		}
		if(i==brZ) printf("%c\n", c);		
	}
	printf("%.5f" ,100.0*x/total);
	return 0;
}
