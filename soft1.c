/*
 ============================================================================
 Name        : soft1.c
 Author      : 加藤平大23122011
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//本課題においてはバブルソートのアルゴリズムを使用した。

void inputfunc(FILE *fp, int *a, int *c);
void sortfunc(int *a, int *c);
void outputfunc(FILE *fp, int *a, int *c);

int main(int argc, char *argv[])
{
    //エラー処理
    FILE *fpi, *fpo;
    int array[10];
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
inputfunc(fpi, array, &cnt);
//ソート
sortfunc(array, &cnt);
//出力
outputfunc(fpo, array, &cnt);
    fclose(fpi);
    fclose(fpo);
    return (0);
}

//入力関数の定義
void inputfunc(FILE *fp, int *a, int *c)
{
    int meta = 0;
    int ch;
     while( ( ch = fscanf( fp, "%d", &meta) ) != EOF ){
        if ((*c) > 9){
            printf("Too many integer numbers in infile.\nMax is 10.");
            exit(0);
        }
        a[(*c)] = meta;
        //printf( "%d\n", a[(*c)]);
        (*c)++;
  }
  
}

//ソート関数の定義
void sortfunc(int *a, int *c)
{
    int i,j;
    int temp;
    for (j=0;j<(*c);j++)
    {
    for (i=0;i<(*c);i++){
        if (a[i] > a[i+1]){
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
    }
    }
}

//出力関数の定義
void outputfunc(FILE *fp, int *a, int *c)
{
    int i;
    for (i=0;i<(*c);i++){
        fprintf(fp, "%d ", a[i]);
    }
}
