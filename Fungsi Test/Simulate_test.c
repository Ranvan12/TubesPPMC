/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Rombongan         : C
* Kelompok          : 1
* Hari dan Tanggal  : Jumat, 17 April 2018
* Asisten (NIM)     : Rahma R. A. (18316003)
* Nama File         : Simulate_test.c
* Deskripsi         : 
*   program test untuk Simulate.c
*/

#include "../lib.h"

int main(){
    cell** matrix;
    cell*** A;
	int row, col;
    int i, j, k, N;

	row = 5;
	col = 5;

/* Alokasi matrix */
    matrix = (cell**)malloc(row*sizeof(cell*));
    for(int i=0; i<row; i++){
        matrix[i] = (cell*)malloc(col*sizeof(cell));
    }

/* Proses Pengisian Seed */
    /* Seed yang diisi pada matriks
     * ----- 
     * ----- 
     * -XXX- 
     * ----- 
     * ----- 
     */
    
    for ( i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            matrix[i][j].data = '-';
        }
    }

    matrix[2][1].data = 'X';
    matrix[2][2].data = 'X';
    matrix[2][3].data = 'X';

/* Display */
    A = &matrix;
    printf("Here is the seed:\n");
    // Display isi matriks.data
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%c", matrix[i][j].data);
        }
        printf("\n");
    }
    printf("\n");

    // loop akan berhenti bila masukan N == 0
    while(N != 0)
    {
        printf("How many iteration would you like? \n(input 0 to exit)"); scanf("%d", &N);
        for (k = 0; k < N; k++)
        {   
            Update(A, row, col);    

            // Display isi matriks.data
            printf("iteration: %d\n", k);
            for (i = 0; i < row; i++)
            {
                for (j = 0; j < col; j++)
                {
                    printf("%c", matrix[i][j].data);
                }
                printf("\n");
            }

            // Display isi matriks.neighbor
            for (i = 0; i < row; i++)
            {
                for (j = 0; j < col; j++)
                {
                    printf("%d", matrix[i][j].neighbor);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
	return 0;
}

