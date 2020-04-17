/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Rombongan         : C
* Kelompok          : 1
* Hari dan Tanggal  : Jumat, 17 April 2018
* Asisten (NIM)     : Rahma R. A. (18316003)
* Nama File         : Display_test.c
* Deskripsi         : Program test untuk Display.c
*/

#include "../lib.h"

int main(){
    cell** A;
	int r=5, c=5;
    int i, j;

    //Alokasi Matrix
    A = (cell**)malloc(r*sizeof(cell*));
    for(i=0; i<r; i++){
        A[i] = (cell*)malloc(c*sizeof(cell));
    }

    /* Isi Seed
     * ----- 
     * --X-- 
     * -X-X- 
     * --X-- 
     * ----- 
     */
     
    // Pengisian Seed
    for (i = 0; i<r; i++){
        for (j = 0; j<c; j++){
            A[i][j].data = '-';
        }
    }
    
    A[1][2].data = 'X';
    A[2][1].data = 'X';
    A[2][3].data = 'X';
    A[3][2].data = 'X';

/* Display */
    printf("\nIni adalah isi seed : \n\n");

    Display(r, c, A);

    return 0;
}
