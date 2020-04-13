/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Rombongan         : C
* Kelompok          : 1
* Hari dan Tanggal  : Selasa, 14 April 2018
* Asisten (NIM)     : Rahma R. A. (18316003)
* Nama File         : display.c
* Deskripsi         : 
*   Implementasi Fungsi Display dan Delay
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct cell{
    char data;
    int neighbor;
} cell;

void Delay(int time) // ide diambil dari https://c-for-dummies.com/blog/?p=69, diakses  14 Apr 2020, 02:30
{   //time dalam milidetik
    long pause;
    clock_t now,start;

    now = start = clock();
    pause = time*(CLOCKS_PER_SEC/1000);

    while( (now-start) < pause )
        now = clock();
}

void Display(int row, int col, cell** matrix){
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%c", matrix[i][j].data);
        }
        printf("\n");
    }
    printf("\n");

    Delay(250);
}
