/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 * MODUL 8 – TUGAS BESAR
 * Kelompok		    : 1
 * Hari dan Tanggal	: Senin, 13 April 2020
 * Asisten (NIM)	: Rahma Rizky Alifia (18316003)
 * Nama File		: main.c
 * Deskripsi		: Program main function dari simulasi Game of Life
 */

#include "lib.h"

int main(){
    cell** A;
    int num_it;
    int r, c, i;
    char next;
    char apapun;
    char choice;
    
    //deskripsi dan peraturan game
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
    
    //user akan membaca deskripsi dan peraturan terlebih dahulu
    //game akan dimulai saat user menekan enter
    printf("Tekan enter untuk mulai bermain!");
    scanf("%c", &apapun);

    //looping menu, program akan mengulang saat user memasukkan 'Y' untuk file baru
    next = 'Y';
    while (next == 'Y'|| next == 'y'){
        //mengambil isi seed beserta baris dan kolom
        input_file(&A, &r, &c);
        printf("\nMemulai simulasi."); Delay(750); printf("."); Delay(750); printf("."); Delay(750);
        printf("\n\n");
        
        //menunjukkan isi seed
        printf("Bentuk seed saat ini: \n");
        Display(r, c, A);
        
        //pilihan menu
        printf("Apa yang ingin Anda lakukan?\n");
        printf("1. Animate\n2. Tick\n3. Quit\n");
        printf("Pilih 1/2/3 : ");
        while (fgetc(stdin) != '\n'){}
        choice = fgetc(stdin);
        //program akan terus menunjukkan menu selama user tidak memilih quit
        while (choice != '3'){
            //1. Animate
            if (choice == '1'){
                printf("Masukkan banyak iterasi yang ingin dilakukan!\n");
                printf("Banyak iterasi : ");
                scanf("%d", &num_it);
                //loop sebanyak num_it
                for(i=0; i<num_it; i++){
                    Update(&A, r, c);
                    Display(r, c, A);
                }
            }
            //2. Tick
            else if (choice=='2'){
                printf("\n");
                Update(&A, r, c);
                Display(r, c, A);
            }
            //jika user memasukkan bukan 1, 2, atau 3
            else{
                printf("Anda salah memasukkan pilihan!\n");
                printf("Masukkan pilihan kembali.\n\n");
            }
            printf("Apa yang ingin Anda lakukan?\n");
            printf("1. Animate\n2. Tick\n3. Quit\n");
            printf("Pilih 1/2/3 : ");
            while (fgetc(stdin) != '\n'){}
            choice = fgetc(stdin);
            printf("\n");
        }
        //3. Quit
        printf("Simulasi selesai!\n\n");
        printf("Apakah Anda ingin memasukkan file baru?\n");
        printf("Y/N : ");
        scanf(" %c", &next);
        printf("\n");
    }

    printf("Terima kasih telah bermain! Simulasi berakhir.\n");
    return 0;
}
