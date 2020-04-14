/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 * MODUL 8 – TUGAS BESAR
 * Kelompok		: 1
 * Hari dan Tanggal	: Senin, 13 April 2020
 * Asisten (NIM)	: Rahma Rizky Alifia (18316003)
 * Nama File		: mainmenu.c
 * Deskripsi		: Program yang berisi prosedur menu dan main function dari simulasi
 *                    Game of Life
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


typedef struct cell {
	char data;
	int neighbor;
} cell;

cell** A;
int r, c;
int i, j;
char fileName;

void delay(int ms);
void menu();

int main(){
    char apapun;
    printf("\n");
    printf(" ----------------------------------------------------------------------------- \n");
    printf("x                                Game of Life                                 x\n");
    printf("o   Game of Life adalah sebuah permainan yang bergantung pada kondisi awal.   o\n");
    printf("x   Sesuai dengan perintah yang anda berikan, game ini akan melakukan         x\n");
    printf("o   iterasi sesuai dengan peraturan. Peraturan game ini adalah:               o\n");
    printf("x    1. Sel hidup dengan tetangga berjumlah kurang dari 2 sel akan mati       x\n");
    printf("o    2. Sel hidup dengan tetangga berjumlah 2 atau 3 sel akan tetap hidup     o\n");
    printf("x    3. Sel hidup dengan tetangga berjumlah lebih dari 3 sel akan mati        x\n");
    printf("o    4. Sel mati dengan tetangga berjumlah 3 sel akan hidup                   o\n");
    printf("x                                                                             x\n");
    printf(" ----------------------------------------------------------------------------- \n\n");
    printf("Tekan enter untuk mulai bermain!");
    scanf("%c", &apapun);
    
    menu();

    printf("Terima kasih telah bermain! Simulasi berakhir.");
    return 0;
}

void menu(){
    int choice, num_it;
    char next;
    printf("\nMasukkan nama file : \n");
    //input_file(A, r, c, fileName);
    printf("\nMemulai simulasi."); delay(750); printf("."); delay(750); printf("."); delay(750);
    printf("\n");

    printf("Bentuk seed saat ini: \n");
    //Display(r, c, A, 250);
    printf("\nApa yang ingin Anda lakukan?\n");
    printf("1. Animate\n2. Tick\n3. Quit\n");
    printf("Pilih 1/2/3 : ");
    scanf("%d", &choice);

    while (choice != 3){
        if (choice == 1){
            printf("\nMasukkan banyak iterasi yang ingin dilakukan!\n");
            printf("Banyak iterasi : ");
            scanf("%d", &num_it);
            for(i=0; i<=num_it; i++){
                //Update(A, r, c);
                //Display(r, c, A, 250);
                printf("tick ke = %d\n", i);
                delay(250); //ini biar ada isi aja
            }
        }
        else if (choice==2){
            printf("\n");
            //Update(A, r, c);
            //Display(r, c, A, 250);
            printf("1 kali tick\n");
        }
        else{
            printf("Anda salah memasukkan pilihan!\n");
            printf("Masukkan pilihan kembali.\n");
        }
        printf("\nApa yang ingin Anda lakukan?\n");
        printf("1. Animate\n2. Tick\n3. Quit\n");
        printf("Pilih 1/2/3 : ");
        scanf("%d", &choice);
        printf("\n");
    }
    printf("Simulasi selesai!\n");
    printf("Apakah Anda ingin memasukkan file baru?\n");
    printf("Y/N : ");
    scanf(" %c", &next);
    if (next == 'Y'|| next == 'y')
        menu();
    else if (next == 'N'|| next == 'n')
        return;
}


// sebenarnya delay gabung sama display, tapi untuk nyoba-nyoba diambil dari internet dulu
void delay(int ms){ //diambil dari https://c-for-dummies.com/blog/?p=69
    long pause;
    clock_t now, then;

    pause = ms*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while((now-then) < pause )
        now = clock();
}