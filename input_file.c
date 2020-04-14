
int main(){
	char isi_file[100][100], in_file[50];
	printf("Masukkan nama file : ");
	gets(in_file);

	FILE *teks = fopen(in_file, "r");
	int count = 0;
	char buf[100];
	while(fgets(buf, 100, teks)){
		char *field = strtok(buf, "\n");
		strcpy(isi_file[count],buf);
		count++;
	}
	fclose(teks);

	int row, column;
	row = atoi(isi_file[0]);
	column = atoi(isi_file[1]);
	printf("%d %d \n", row, column);

    char **matrix;
    matrix = (char*)malloc(row*sizeof(char*));
    for(int i=0; i<row; i++){
        matrix[i] = (char*)malloc(column*sizeof(char));
    }

	for(int i=0; i<row; i++){
        int k;
        k = i+2;
        strcpy(matrix[i], isi_file[k]);
	}

	for(int j=0; j<row; j++){
		printf("%s\n",matrix[j]);
	}
    free(matrix);
	return 0;
}
