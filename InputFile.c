/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 * MODUL 9 – TUGAS BESAR
 * Kelompok		: 1
 * Asisten (NIM)	: Rahma Rizky Alifia (18316003)
 * Nama File		: input_file.c
 * Deskripsi		: Membuat fungsi untuk input file external, lalu bagian seed dimasukkan ke array
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Prosedur input_file
void input_file(cell*** A, int* r, int* c){
	//101 karena pada akhir string diisi null character
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
		fgets(buf, 101, teks);		//mengambil 1 baris dari teks
		strcpy(isi_file[count],buf);	//memindahkannya ke array isi_file
		count++;			//ganti baris
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
			//Seed pada array isi_file terletak mulai baris ketiga (isi_file[2])
			(*A)[i][j].data = isi_file[i + 2][j];
		}
	}
}
