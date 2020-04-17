/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 * MODUL 8 – TUGAS BESAR
 * Kelompok		: 1
 * Hari dan Tanggal	: Jumat, 17 April 2020
 * Asisten (NIM)	: Rahma Rizky Alifia (18316003)
 * Nama File		: Simulate.c
 * Deskripsi		: Program berisi prosedur untuk mencari jumlah neighbor dan
 *          		  menyimulasikan Game of Life untuk 1 iterasi
 */

//Prosedur untuk mengisi data neighbor
void AliveNeighbor (cell*** A, int r, int c){
	int i, j, h, v;
	int row, column;
	for (i = 0; i < r; i = i + 1){
		for (j = 0; j < c; j = j + 1){
			(*A)[i][j].neighbor = 0;
			//Mengecek semua tetangga
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
			//else : tidak ada perubahan
		}
	}
}
