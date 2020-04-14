/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Rombongan         : C
* Kelompok          : 1
* Hari dan Tanggal  : Selasa, 14 April 2018
* Asisten (NIM)     : Rahma R. A. (18316003)
* Nama File         : lib.h
* Deskripsi         : 
*   Implementasi Fungsi Display dan Delay
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct cell {
	char data;
	int neighbor;
} cell;

void input_file(**cell matrix, int *r, int *c, char *filename);
void AliveNeighbor (cell*** A, int r, int c);
void Update (cell*** A, int r, int c);
void Delay(int time);
void Display(int row, int col, cell** matrix);

#include "input_file.c"
#include "Simulate.c"
#include "display.c"