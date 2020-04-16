#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct cell {
	char data;
	int neighbor;
} cell;

void PrintCell (cell** Arr, int r, int c){
	int i, j;
	for (i = 0; i < r; i = i + 1){
		for (j = 0; j < c; j = j + 1){
			printf ("%c ", Arr[i][j].data);
		}
		printf ("\n");
	}
}

void input_file(cell*** A, int* r, int* c){
	char isi_file[100][101];
	char in_file[101];
	int count = 0;
	int i, j;
	char buf[101];
	
	printf("Masukkan nama file : ");
	scanf ("%s", in_file);
	
	//Membuka nama file yang telah diinput diatas
	//Dan memindahkan setiap baris pada file tsb ke array char isi_file
	FILE *teks = fopen(in_file, "r");
	while(!feof (teks)){
		fgets(buf, 101, teks);
		strcpy(isi_file[count],buf);
		count++;
		
	}
	fclose(teks);
	
	//Mengisi variabel row dengan nilai jumlah baris seed yang ada pada file, dimana terletak pada isi_file[0]
	*r = atoi(isi_file[0]);
	//Mengisi variabel column dengan nilai jumlah kolom seed yang ada pada file, dimana terletak pada isi_file[1]
	*c = atoi(isi_file[1]);
	
	//Menginisialisasi jumlah alamat pada matrix agar sesuai dengan jumlah row dan column seed
    *A = (cell**)malloc((*r) * sizeof(cell*));
    for(i = 0; i < (*r); i++){
        (*A)[i] = (cell*)malloc((*c) * sizeof(cell));
    }
	
	//Mengisi array matrix dengan seed yang ada pada array isi_file 
	for(i = 0; i < (*r); i++){
		for (j = 0; j < *c; j = j + 1){
			//Seed pada array isi_file terletak mulai isi_file[2]
			(*A)[i][j].data = isi_file[i + 2][j];
		}
	}
}

//Test Function
int main (){
	cell** A;
	int r;
	int c;
	
	input_file (&A, &r, &c);
	printf ("r = %d, c = %d\n\n", r, c);
	
	PrintCell (A, r, c);
	printf ("\n");
	
	//Mencoba rewrite jika ukuran lebih besar apakah ada masalah
	input_file (&A, &r, &c);
	printf ("r = %d, c = %d\n\n", r, c);
	
	PrintCell (A, r, c);
	printf ("\n");
	
	//Mencoba rewrite jika ukuran lebih kecil apakah ada masalah
	input_file (&A, &r, &c);
	printf ("r = %d, c = %d\n\n", r, c);
	
	PrintCell (A, r, c);
	printf ("\n");
	return 0;
}
