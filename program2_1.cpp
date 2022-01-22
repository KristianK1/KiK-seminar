#include<stdio.h>
#include<stdlib.h>

#include<iostream>
#include<string.h>

#define brZnakova 90
#define brZnakova2 8100
#define brZnakova3 729000

#define N 5

typedef struct znakStat {
	unsigned int Fi;
	char str[N+1];
}ZnakStat;


void swap(ZnakStat *one, ZnakStat *two){
	struct znakStat temp;
	temp=*one;
	*one=*two;
	*two=temp;
}
/*
void sortSigns(struct znakStat *polje, int size){
	for(int i=0;i<size-1; i++){
		if(i%1000 == 0) printf("%.2f\n", 100.0*i/size);
		for(int j=i+1;j<size; j++){
			if(polje[j].Fi > polje[i].Fi){
				swap(polje+i, polje+j);
			}
		}
	}	
}*/

void quickSort(ZnakStat *a, int low, int high) {
	int i = low, j = high;
	int s = a[(low + high) / 2].Fi;
	while (i <= j) {
		while (a[i].Fi > s) {
			i++;
		}
		while (a[j].Fi < s){
			j--;
		}
		if (i <= j) {
			swap(&a[i], &a[j]);
			i++;
 			j--;
		}
	}
	if (low < j)
		quickSort(a, low, j);
	if (i < high)
		quickSort(a, i, high);
}

/*char znakovi[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,:;%&?!()[]/*-+='{}“”—_’… \n";
	
int pronadi(char x){
	
	for(int i=0;i<brZnakova;i++){
		if(znakovi[i]==x) return i;
	}
	return -1;
}*/

void expandSize(ZnakStat *p, long size){
	printf("poceo");
	p = (ZnakStat*)realloc(p, size*sizeof(ZnakStat));
	if(p==NULL) {
		printf("allocation error");
		exit(EXIT_FAILURE);	
	}
	printf("zavrsio");
}

int increment(ZnakStat *p, long* current_size, long *max_size, char comb[N]){ //vraca 0 ako nije povecao velicinu polja, 1 ako jest
	for(int i=0;i<*current_size;i++){
		if(strcmp(p[i].str,comb)==0){
			p[i].Fi++;
			return 0;
		}
	}
	
	p[*current_size].Fi = 1;
	strcpy(p[*current_size].str, comb);
	
	(*current_size)++;
	if(*current_size >= *max_size){
		*max_size = *max_size + 5000;
		printf("\n%d %d||\n", *current_size, *max_size);
		printf("previse");
		expandSize(p, *max_size);
	}
	return 1;
}

void printResults(ZnakStat *p, long current_size, int total){
	printf("\n\n\n");
	for(int i=0;i<9;i++){
		//printf("|");
		printf("\"");
		for(int k = 0;k<N;k++){
			if(p[i].str[k] == '\n'){
				printf("_");
			}
			else
				printf("%c", p[i].str[k]);
		
		}
		printf("\"");
	
		printf("\n");
		//printf("|\t%6d\n", p[i].Fi);
	}
	
	for(int i=0;i<9;i++){
		printf("%.0f\n", 1000000.0*p[i].Fi/total);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
//	FILE *f = fopen("testFile.txt","r");
//	FILE *f = fopen("Harry Potter books/TXT/HP_ALL.txt","r");
	FILE *f = fopen("Harry Potter books/TXT/HP4.txt","r");

//	FILE *f = fopen("bible.txt","r");
//	FILE *f = fopen("TFIOS.txt","r");
//	FILE *f = fopen("gatsby.txt","r");

	if(f==NULL){
		printf("nema fajla");
		return 7;
	}
	
	long *current_size = (long*)calloc(1, sizeof(long));
	long *max_size = (long*)calloc(1, sizeof(long)); //inkrementi 10000
	
	*max_size=300000;
	ZnakStat *Stats = (ZnakStat*) calloc(*max_size, sizeof(ZnakStat));
	printf("MAX SIZE: %ld\n", *max_size);
	if(Stats == NULL) return 0;
	char comb[N];
	char temp;	
	
	for(int i=0;i<N;i++){
		fscanf(f, "%c", &comb[i]);
		if(temp == EOF) return -1;
	}
	comb[N] = '\0';
	increment(Stats, current_size, max_size, comb);
	int x=0;
	
	
	
	
	
	while(true){
		x++;
		if(x%100000==0){
			printf("%d %d %d\n",x,*current_size, *max_size);
		}
		
		
		if(x%5000==0) quickSort(Stats, 0, *current_size);
		
		
		for(int i=1;i<N;i++){
			comb[i-1] = comb[i];
		}
		temp = fgetc(f);
		if(temp==EOF) {
			printf("Kraj fajla\n");
			break;
		}
		comb[N-1] = temp;
		comb[N] = '\0';
		//printf("|%s|\n", comb);
		increment(Stats, current_size, max_size, comb);
	}
	quickSort(Stats, 0, *current_size);
	
	
	printResults(Stats, *current_size, x);
	return 0;
}
