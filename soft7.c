/*
 ============================================================================
 Name        : soft7.c
 Author      : 加藤平大23122011
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//本課題においては最大値抽出法のアルゴリズムを使用した。

typedef struct school_record {
float gpa;
int credit;
char name[200];
} SRec;

typedef int(*P)(const void * n1, const void * n2);

void inputfunc(FILE *fp, SRec **a, int *c);
void sortfunc(SRec *a, int *c, char *field);
void outputfunc(FILE *fp, SRec *a, int *c);



int main(int argc, char *argv[])
{
    char *field;

    //エラー処理
    FILE *fpi, *fpo;
    SRec *data;
    int cnt = 0;
    if (argc != 4) {
        fprintf(stderr, "Illegal number of commandline argument.\n");
        return (-1);
    }

    field = argv[1];
    if ((strcmp(field,"gpa")!=0)&&(strcmp(field,"credit")!=0)&&(strcmp(field,"name")!=0) ){
        fprintf(stderr, "Invalid sorting field <%s>.\n", argv[1]);
        return (-1);
    }

    if ((fpi = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Can't open input file <%s>.\n", argv[2]);
        return (-1);
    }

    if ((fpo = fopen(argv[3], "w")) == NULL) {
        fprintf(stderr, "Can't open output file <%s>.\n", argv[3]);
        return (-1);
    }
//入力
inputfunc(fpi, &data, &cnt);
//ソート
sortfunc(data, &cnt, field);
//出力
outputfunc(fpo, data, &cnt);
    free(data);
    fclose(fpi);
    fclose(fpo);
    return (0);
}

//入力関数の定義
void inputfunc(FILE *fp, SRec **a, int *c){
    int ch;
    ch = fscanf( fp, "%d", c);
    if(ch == EOF){printf("No data in infile.\n");}
    if((*a = (SRec *)malloc(sizeof(SRec) * (*c))) == NULL) {
        printf("Malloc failed.\n");
}
    for (int i = 0; i < *c; i++) {
        fscanf (fp, "%f", &((*a)[i].gpa));
        fscanf (fp, "%d", &((*a)[i].credit));
        fscanf (fp, "%s", (*a)[i].name);
    }
}

//比較関数の定義
int compgpa(const void * n1, const void * n2)
{
	if (((SRec *)n1)->gpa > ((SRec *)n2)->gpa)
	{
		return -1;
	}
	else if (((SRec *)n1)->gpa < ((SRec *)n2)->gpa)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int compcredit(const void * n1, const void * n2)
{
	if (((SRec *)n1)->credit > ((SRec *)n2)->credit)
	{
		return -1;
	}
	else if (((SRec *)n1)->credit < ((SRec *)n2)->credit)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int compname(const void * n1, const void * n2)
{
	if ((int)(((SRec *)n1)->name[0]) > (int)(((SRec *)n2)->name[0]))
	{
		return -1;
	}
	else if ((int)(((SRec *)n1)->name[0]) < (int)(((SRec *)n2)->name[0]))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//ソート関数の定義
void sortfunc(SRec *a, int *c, char *field)
{
    P Pcomp;
    if (strcmp(field,"gpa")==0){Pcomp = &compgpa;}
    if (strcmp(field,"credit")==0){Pcomp = &compcredit;}
    if (strcmp(field,"name")==0){Pcomp = &compname;}
    int i, j, max;
    SRec temp;
    for (j = 0; j < *c - 1; j++) {
        max = j;
        for (i = j + 1; i < *c; i++) {
            if ((*Pcomp)(&a[i], &a[max])==-1){
                max = i;
            }
        }
        temp = a[max];
        a[max] = a[j];
        a[j] = temp;
    }
}

//出力関数の定義
void outputfunc(FILE *fp, SRec *a, int *c)
{
    int i;
    fprintf(fp, "%d\n", *c);
    for (i=0;i<(*c);i++){
        fprintf(fp, "%.1f ", a[(*c)-i-1].gpa);
        fprintf(fp, "%d ", a[(*c)-i-1].credit);
        fprintf(fp, "%s ", a[(*c)-i-1].name);
        fprintf(fp, "\n");
    }
}
