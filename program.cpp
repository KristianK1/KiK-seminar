#include<stdio.h>
#include<stdlib.h>

#include<iostream>
#include<string.h>

#define brZnakova 90
#define brZnakova2 8100
#define brZnakova3 729000

struct znakStat {
	int Fi;
	char str[4];
};

void swap(struct znakStat *one, struct znakStat *two){
	struct znakStat temp;
	temp=*one;
	*one=*two;
	*two=temp;
}
void sortSigns(struct znakStat *polje, int size){
	for(int i=0;i<size-1; i++){
		if(i%1000 == 0) printf("%.2f\n", 100.0*i/size);
		for(int j=i+1;j<size; j++){
			if(polje[j].Fi > polje[i].Fi){
				swap(polje+i, polje+j);
			}
		}
	}	
}

void quickSort(struct znakStat *a, int low, int high) {
	int i = low, j = high;
	int s = a[(low + high) / 2].Fi;
	while (i <= j) {
		while (a[i].Fi < s) {
			i++;
		}
		while (a[j].Fi > s){
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

char znakovi[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,:;%&?!()[]/*-+='{}“”—_’… \n";
	
int pronadi(char x){
	
	for(int i=0;i<brZnakova;i++){
		if(znakovi[i]==x) return i;
	}
	return -1;
}

int main(){
	
	int i=0;
	for(;znakovi[i]!='\0';i++);
	printf("Broj znakova je %d\n", i);
	
	
	unsigned int statistika[brZnakova] = {0};
	unsigned int statistika2[brZnakova2] = {0};
	unsigned short int statistika3[brZnakova3] = {0};
	
	
	FILE *f = fopen("Harry Potter books/TXT/HP4.txt","r");
//	FILE *f = fopen("bible.txt","r");
//	FILE *f = fopen("TFIOS.txt","r");

	if(f==NULL){
		printf("nema fajla");
		return 7;
	}
	
	char c1, c2, c3;
	
	fscanf(f, "%c", &c1);
	if(c1 == EOF) return -3;
	statistika[pronadi(c1)]++;
	
	fscanf(f, "%c", &c2);
	if(c2 == EOF) return -4;
	statistika[pronadi(c2)]++;
	statistika2[pronadi(c1)*brZnakova+pronadi(c2)]++;
	
	
	c3=fgetc(f);
	if(c3 == EOF) return -5;
	statistika[pronadi(c1)]++;
	statistika2[pronadi(c2)*brZnakova+pronadi(c3)]++;
	statistika3[pronadi(c1)*brZnakova2+pronadi(c2)*brZnakova+pronadi(c3)]++;
	
	int temp1 = pronadi(c1), temp2 = pronadi(c2), temp3 = pronadi(c3);
	
	
	while(true){
		temp1=temp2;
		temp2=temp3;
		c3=fgetc(f);
		//printf("%c", c3);
		temp3=pronadi(c3);
		if(c3==EOF) {
			printf("Kraj fajla");
			break;
		}
		
		if(temp1!=-1){
			statistika[temp1]++;
			if(temp2!=-1){
				statistika2[temp1*brZnakova+temp2]++;
				if(temp3!=-1){
					statistika3[temp1*brZnakova2+temp2*brZnakova+temp3]++;
				}
			}
		}
		//else printf("%c %d\n", c3, c3);
	}
	
	
	/*for(int i=0;i<brZnakova; i++){
		printf("%c %d\n", znakovi[i], statistika[i]);
	}*/
	
	/*for(int i=0;i<brZnakova;i++){
		for(int j=0;j<brZnakova;j++){
			if(statistika2[brZnakova*i+j]>100)
				printf("%c%c %d\n", znakovi[i], znakovi[j], statistika2[brZnakova*i+j]);
		}
	}*/
	
	/*struct znakStat statsCombined1[brZnakova2] = {0};
	for(int i = 0;i<brZnakova; i++){
		for(int j = 0;j<brZnakova; j++){
		
		statsCombined1[i*brZnakova+j].Fi = statistika2[i*brZnakova+j];
		statsCombined1[i*brZnakova+j].str[0] = znakovi[i];
		statsCombined1[i*brZnakova+j].str[1] = znakovi[j];
		statsCombined1[i*brZnakova+j].str[2] = '\0';
		}
	}
	
	sortSigns(statsCombined1, brZnakova2);
	
	printf("\n");
	
	
	for(int i=0;i<40; i++){
		if(statsCombined1[i].Fi>1)
			printf("%s\n", statsCombined1[i].str);
	}
	for(int i=0;i<40; i++){
		if(statsCombined1[i].Fi>1)
			printf("%d\n",statsCombined1[i].Fi);
	}
	*/
	
	struct znakStat *statsCombined1;
	statsCombined1 = (struct znakStat*) calloc(brZnakova3, sizeof(struct znakStat));
	if(statsCombined1==NULL){
		printf("jebemti mrtvog isusa");
		return 9;
	}
	for(int i = 0;i<brZnakova; i++){
		for(int j = 0;j<brZnakova; j++){
			for(int k = 0;k<brZnakova; k++){
			
		
			statsCombined1[i*brZnakova2+j*brZnakova+k].Fi = statistika3[i*brZnakova2+j*brZnakova+k];
			statsCombined1[i*brZnakova2+j*brZnakova+k].str[0] = znakovi[i];
			statsCombined1[i*brZnakova2+j*brZnakova+k].str[1] = znakovi[j];
			statsCombined1[i*brZnakova2+j*brZnakova+k].str[2] = znakovi[k];
			statsCombined1[i*brZnakova2+j*brZnakova+k].str[3] = '\0';
			}
		}
	}
	
	
	
	
	
	
	
	
	quickSort(statsCombined1, 0, brZnakova3);
	
	printf("HELLO \n");
	
	
	for(int i=brZnakova3;i>(brZnakova3-40); i--){
			printf("%s\n", statsCombined1[i].str);
	}
	for(int i=brZnakova3;i>(brZnakova3-40); i--){
			printf("%d\n", statsCombined1[i].Fi);
	}
	
	
	return 0;
}
