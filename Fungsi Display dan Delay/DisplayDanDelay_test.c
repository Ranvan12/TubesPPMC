#include "display.c"    

void main(){
    cell** matrix;
    int i, j, n;
    int row = 9, col = 9;
    int _delay, _tru_delay;
    float _disp_delay;
    clock_t start, end;

/* Alokasi matriks */
    matrix = (cell**)malloc(row*sizeof(cell*));
    for(int i=0; i<row; i++){
        matrix[i] = (cell*)malloc(col*sizeof(cell));
    }

/* Proses pengisian matriks */
    for (i = 0; i < row; i++)
    {   
        for (j = 0; j < col; j++)
        {
            matrix[i][j].data = '-';
        }
    }

    for (i = 3; i < 6; i++)
    {   
        for (j = 3; j < 6; j++)
        {
            matrix[i][j].data = 'X';
        }
    }

/* Display dan Delay */
    printf("Masukkan banyaknya pengulangan proses display : "); scanf("%d", &n);
    start = clock();

    for (i = 0; i < n; i++)
    {
        Display(row, col, matrix);
    }

    end = clock();

    _tru_delay = 250*n;
    _delay = end-start;
    _disp_delay = _delay-_tru_delay;
    printf("delay seharusnya : %d ms\n", _tru_delay);
    printf("delay program    : %d ms\n", _delay);
    printf("***delay dihitung dengan proses display\n\n");
    printf("proses display memakan waktu total selama : %d ms\n", _delay-_tru_delay);
    printf("satu proses display memakan waktu selama : %.2f ms\n", _disp_delay/(float) n);
}   