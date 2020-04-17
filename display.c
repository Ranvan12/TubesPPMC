/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Rombongan         : C
* Kelompok          : 1
* Hari dan Tanggal  : Jumat, 17 April 2018
* Asisten (NIM)     : Rahma Rizky Alifia (18316003)
* Nama File         : display.c
* Deskripsi         : 
*   Implementasi Fungsi Display dan Delay
*/

void Delay(int time)// ide diambil dari https://c-for-dummies.com/blog/?p=69, diakses  14 Apr 2020, 02:30
{                   // time dalam milidetik
    long pause;     // delay yang diinginkan dalam satuan clock ticks per milidetik
    clock_t now;    // waktu saat ini
    clock_t start;  // waktu saat fungsi ini mulai berjalan

    now = start = clock();
    pause = time*(CLOCKS_PER_SEC/1000);

    // loop dilakukan sampai jeda waktu sudah mencapai delay yang diinginkan (now-start) == pause
    while( (now-start) < pause )
        now = clock();
}

void Display(int row, int col, cell** matrix){
    int i, j;
    // iterasi setiap elemen dalam matriks 2D "matrix.data"
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%c", matrix[i][j].data);
        }
        printf("\n");   // berpindah baris
    }
    printf("\n");       // menambahkan baris kosong setelah semua elemen ditampilkan

    Delay(250);         // menambah jeda waktu 250 ms
}
