/*
 ============================================================================
 Name        : soft5.c
 Author      : 加藤平大23122011
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//本課題においては最大値抽出法のアルゴリズムを使用した。

void inputfunc(FILE *fp, int **a, int *c);
void sortfunc(int *a, int *c);
void outputfunc(FILE *fp, int *a, int *c);

int main(int argc, char *argv[])
{
    //エラー処理
    FILE *fpi, *fpo;
    int *array;
    int cnt = 0;
    if (argc != 3) {
        fprintf(stderr, "Illegal number of argument.\n");
        return (-1);
    }

    if ((fpi = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open input file <%s>.\n", argv[1]);
        return (-1);
    }

    if ((fpo = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Can't open output file <%s>.\n", argv[2]);
        return (-1);
    }
//入力
inputfunc(fpi, &array, &cnt);
//ソート
sortfunc(array, &cnt);
//出力
outputfunc(fpo, array, &cnt);
    fclose(fpi);
    fclose(fpo);
    free(array);
    return (0);
}

//入力関数の定義
void inputfunc(FILE *fp, int **a, int *c)
{
    //int meta = 0;
    int ch;
    //int cnt2 = 0;
    ch = fscanf( fp, "%d", c);
    if(ch == EOF){printf("No data in infile.\n");}
    //printf("%d", *c);
    *a = (int *)malloc(sizeof(int)*(*c));
    if(*a == NULL){printf("Malloc failed.\n");}
    /*
    int meta = 0;
    while( ( ch = fscanf( fp, "%d", &meta) ) != EOF ){
        if (cnt2 >= *c){
            printf("First number in infile is wrong.\n");
            exit(0);
        }
        (*a)[cnt2] = meta;
        //printf( "%d\n", a[cnt2]);
        cnt2++;
  }
  */
   for (int i = 0; i < *c; i++) {
        if (fscanf(fp, "%d", &(*a)[i]) == EOF) {
            printf("First number in infile is wrong.\n");
            exit(0);
        }
    }
  //printf("%d\n", a[0]);
}

//ソート関数の定義
void sortfunc(int *a, int *c)
{
    int i, j, max, temp;
    for (j = 0; j < *c - 1; j++) {
        max = j;
        for (i = j + 1; i < *c; i++) {
            if (a[i] > a[max]) {
                max = i;
            }
        }
        temp = a[max];
        a[max] = a[j];
        a[j] = temp;
    }
    //printf( "%d\n", a[0]);
    /*int i,j;
    int temp;
    int max;
    for (j=0;j<(*c);j++)
    {
        max = 0;
    for (i=0;i<(*c)-j;i++){
        if (a[i+1] > a[max]){
            max = i+1;
        }
    }
    temp = a[max];
    a[max] = a[(*c)-j];
    a[(*c)-j] = temp;
    }
    */
    //printf( "%d\n", a[0]);
}

//出力関数の定義
void outputfunc(FILE *fp, int *a, int *c)
{
    int i;
    for (i=0;i<(*c);i++){
        fprintf(fp, "%d ", a[*c-i-1]);
    }
}