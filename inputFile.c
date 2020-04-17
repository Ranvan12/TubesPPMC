#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void input_file(cell*** A, int* r, int* c){
	char isi_file[100][100], in_file[50];
	int count = 0;
	char buf[100];

	//Menginput nama file seed yang akan dicoba
	printf("Masukkan nama file : ");
	gets(in_file);

	//Membuka nama file yang telah diinput diatas
	//Dan memindahkan setiap baris pada file tsb ke array char isi_file
	FILE *teks = fopen(in_file, "r");
	while(fgets(buf, 100, teks)){
		char *field = strtok(buf, "\n");
		strcpy(isi_file[count],buf);
		count++;
	}
	fclose(teks);

	//Mengisi variabel row dengan nilai jumlah baris seed yang ada pada file, dimana terletak pada isi_file[0]
	r = atoi(isi_file[0]);
	//Mengisi variabel column dengan nilai jumlah kolom seed yang ada pada file, dimana terletak pada isi_file[1]
	c = atoi(isi_file[1]);

	//Menginisialisasi jumlah alamat pada matrix agar sesuai dengan jumlah row dan column seed
    A = (char*)malloc(r*sizeof(char*));			//-> *A = (char**)malloc(r*sizeof(char*))
    for(int i=0; i<r; i++){
        A[i] = (char*)malloc(c*sizeof(char));	//A[i] -> (*A)[i]
    }

    //Mengisi array matrix dengan seed yang ada pada array isi_file 
	for(int i=0; i<r; i++){						//liat input_file_rev.c line 64
        int k;
        //Seed pada array isi_file terletak mulai isi_file[2]
        k = i+2;
        strcpy(A[i], isi_file[k]);				//gabisa strcpy karena (*A)[i] bukan char *, tapi cell *
	}

}