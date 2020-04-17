/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 * MODUL 8 – TUGAS BESAR
 * Kelompok		: 1
 * Hari dan Tanggal	: Jumat, 17 April 2020
 * Asisten (NIM)	: Rahma Rizky Alifia (18316003)
 * Nama File		: Simulate.c
 * Deskripsi		: Program Revisi input_file.c (sudah dites)
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../lib.h"

typedef struct cell {
	char data;
	int neighbor;
} cell;

//Prosedur untuk mencetak array cell 2 dimensi
void PrintCell (cell** Arr, int r, int c){
	int i, j;
	for (i = 0; i < r; i = i + 1){
		for (j = 0; j < c; j = j + 1){
			printf ("%c ", Arr[i][j].data);
		}
		printf ("\n");
	}
}

//Test Function
int main (){
	cell** A;
	int r;
	int c;
	
	//Mencoba input sebuah file
	input_file (&A, &r, &c);
	//Mencetak data yang diperoleh
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
