/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 * MODUL 8 – TUGAS BESAR
 * Kelompok		: 1
 * Hari dan Tanggal	: Senin, 13 April 2020
 * Asisten (NIM)	: Rahma Rizky Alifia (18316003)
 * Nama File		: Simulate.c
 * Deskripsi		: Program berisi prosedur untuk mencari jumlah neighbor dan
 *          		  menyimulasikan Game of Life untuk 1 iterasi
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
	char data;
	int neighbor;
} cell;

//Prosedur untuk mengisi data neighbor
void AliveNeighbor (cell*** A, int r, int c){
	int i, j, h, v;
	int row, column;
	for (i = 0; i < r; i = i + 1){
		for (j = 0; j < c; j = j + 1){
			(*A)[i][j].neighbor = 0;
			for (h = -1; h <= 1; h = h + 1){
				for (v = -1; v <= 1; v = v + 1){
					row = (i + h + r) % r;
					column = (j + v + c) % c;
					if (((row != i) || (column != j)) && ((*A)[row][column].data == 'X')){
						 (*A)[i][j].neighbor = (*A)[i][j].neighbor + 1;
					}
				}
			}
		}
	}
}

//Prosedur untuk menyimulasikan dalam satu iterasi
void Update (cell*** A, int r, int c){
	int i, j;
	AliveNeighbor (A, r, c);
	for (i = 0; i < r; i = i + 1){
		for (j = 0; j < c; j = j + 1){
			if (((*A)[i][j].data == 'X') && (((*A)[i][j].neighbor <= 1) || ((*A)[i][j].neighbor >= 4))){
				(*A)[i][j].data = '-';
			}
			else if (((*A)[i][j].data == '-') && ((*A)[i][j].neighbor == 3)){
				(*A)[i][j].data = 'X';
			}
		}
	}
}

/* Note: Prosedur di atas sudah dicoba dan berhasil untuk input array 5 x 5 berisi:
          - - - - -
          - - X - -
          - X X X -
          - - X - -
          - - - - -
         selama 3 iterasi
 */

//Bagian ini hanya untuk menguji kedua fungsi di atas
//Test function

void TestSimulate (){
	cell** A;
	int i, j, r, c;
	
	//Masukan jumlah baris dan kolom matriks
	r = 5;
	c = 5;
	A = (cell**) malloc (r * sizeof (cell*));
	for (i = 0; i < r; i = i + 1){
		A[i] = (cell*) malloc (c * sizeof (cell));
	}
	
	//Input data
	for (i = 0; i < r; i = i + 1){
		for (j = 0; j < c; j = j + 1){
			scanf ("%c", &A[i][j].data);
		}
	}
	
	printf ("\n");
	
	
	for (i = 0; i < r; i = i + 1){
		for (j = 0; j < c; j = j + 1){
			printf ("%c ", A[i][j].data);
		}
		printf ("\n");
	}
	
	printf ("\n");
	
	//Bagian ini bisa pakai for loop untuk jumlah iterasi tertentu
	//teapi karena awalnya hanya ingin menguji untuk 1 iterasi
	//lalu ternyata tiba-tiba ingin menambah jumlah iterasi tetapi tidak ingin membuat loop
	//jadi iterasi yang kedua, ketiga, dst hanya copy-paste dari yang pertama saja.
	
	Update (&A, r, c);
	
	for (i = 0; i < r; i = i + 1){
		for (j = 0; j < c; j = j + 1){
			printf ("%d ", A[i][j].neighbor);
		}
		printf ("\n");
	}
	
	printf ("\n");
	
	for (i = 0; i < r; i = i + 1){
		for (j = 0; j < c; j = j + 1){
			printf ("%c ", A[i][j].data);
		}
		printf ("\n");
	}
	
	printf ("\n");
	Update (&A, r, c);
	
	for (i = 0; i < r; i = i + 1){
		for (j = 0; j < c; j = j + 1){
			printf ("%d ", A[i][j].neighbor);
		}
		printf ("\n");
	}
	
	printf ("\n");
	
	for (i = 0; i < r; i = i + 1){
		for (j = 0; j < c; j = j + 1){
			printf ("%c ", A[i][j].data);
		}
		printf ("\n");
	}
	
	printf ("\n");
	Update (&A, r, c);
	
	for (i = 0; i < r; i = i + 1){
		for (j = 0; j < c; j = j + 1){
			printf ("%d ", A[i][j].neighbor);
		}
		printf ("\n");
	}
	
	printf ("\n");
	
	for (i = 0; i < r; i = i + 1){
		for (j = 0; j < c; j = j + 1){
			printf ("%c ", A[i][j].data);
		}
		printf ("\n");
	}
	
	printf ("\n");
	Update (&A, r, c);
	
	for (i = 0; i < r; i = i + 1){
		for (j = 0; j < c; j = j + 1){
			printf ("%d ", A[i][j].neighbor);
		}
		printf ("\n");
	}
	
	printf ("\n");
	
	for (i = 0; i < r; i = i + 1){
		for (j = 0; j < c; j = j + 1){
			printf ("%c ", A[i][j].data);
		}
		printf ("\n");
	}
	
	free (A);
	
	//Test Input Example : -------X---XXX---X-------
}
