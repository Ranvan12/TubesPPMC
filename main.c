/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 * MODUL 8 – TUGAS BESAR
 * Kelompok		: 1
 * Hari dan Tanggal	: Senin, 13 April 2020
 * Asisten (NIM)	: Rahma Rizky Alifia (18316003)
 * Nama File		: main.c
 * Deskripsi		: Program yang main function dari simulasi Game of Life
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

void Delay(int ms);

int main(){
    char apapun;
    int choice, num_it;
    char next;

    //deskripsi biar lucu
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

    //looping menu
    next = 'Y';
    while (next == 'Y'|| next == 'y'){
        printf("\nMasukkan nama file : \n");
        //input_file(A, r, c, fileName);
        Delay(750);
        printf("\nMemulai simulasi."); Delay(750); printf("."); Delay(750); printf("."); Delay(750);
        printf("\n");

        printf("Bentuk seed saat ini: \n");
        //Display(r, c, A, 250);
        
        printf("Apa yang ingin Anda lakukan?\n");
        printf("1. Animate\n2. Tick\n3. Quit\n");
        printf("Pilih 1/2/3 : ");
        scanf("%d", &choice);

        while (choice != 3){
            if (choice == 1){
                printf("\nMasukkan banyak iterasi yang ingin dilakukan!\n");
                printf("Banyak iterasi : ");
                scanf("%d", &num_it);
                //loop sebanyak num_it
                for(i=0; i<=num_it; i++){
                    //Update(A, r, c);
                    //Display(r, c, A, 250);
                    printf("tick ke = %d\n", i);
                    Delay(250); //ini biar ada isi aja
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
    }

    printf("Terima kasih telah bermain! Simulasi berakhir.");
    return 0;
}

void Delay(int time) // ide diambil dari https://c-for-dummies.com/blog/?p=69, diakses  14 Apr 2020, 02:30
{   //time dalam milidetik
    long pause;
    clock_t now,start;

    now = start = clock();
    pause = time*(CLOCKS_PER_SEC/1000);

    while( (now-start) < pause )
        now = clock();
}
