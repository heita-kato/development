/*
 ============================================================================
 Name        : soft11.c
 Author      : 加藤平大23122011
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//本課題においては二分探索法のアルゴリズムを使用した。

typedef int(*P)(const void * n1, const void * n2);

typedef struct school_record SRec;

struct school_record {
float gpa;
int credit;
char name[200];
SRec *next;
SRec *left, *right;
};

void inputfunc(FILE *fp, SRec **a);
void sortfunc(char *field, SRec *a, SRec **A);
void outputfunc(FILE *fp, SRec **A);

int main(int argc, char *argv[])
{
    char *field;

    //エラー処理
    FILE *fpi, *fpo;
    SRec *data;
    SRec *data2;
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
inputfunc(fpi, &data);
//ソート
sortfunc(field, data, &data2);
//出力
outputfunc(fpo, &data2);
    fclose(fpi);
    fclose(fpo);
    return (0);
}

//入力関数の定義
void inputfunc(FILE *fp, SRec **a) {
 SRec *head = NULL;
 SRec **tail = &head;
 SRec *p = NULL;
 int ch;
 float c = 0.0;
 while ((ch = fscanf(fp, "%f", &c)) != EOF ){
    if((p = malloc(sizeof(SRec))) == NULL) {
           printf("Malloc failed.\n");
    }
    p->next = NULL;
    *tail = p;
    tail = &(p->next);
    (*p).gpa = c;
    fscanf (fp, "%d", &((*p).credit));
    fscanf (fp, "%s", (*p).name);
    (*p).left = NULL;
    (*p).right = NULL;
}
 *a = head;
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
	if (strcmp(((SRec *)n1)->name , ((SRec *)n2)->name)> 0)
	{
		return -1;
	}
	else if (strcmp(((SRec *)n1)->name , ((SRec *)n2)->name)< 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//ソート関数の定義
void sortfunc(char *field, SRec *a, SRec **A) {
    P Pcomp;
    if (strcmp(field, "gpa") == 0) Pcomp = compgpa;
    if (strcmp(field, "credit") == 0) Pcomp = compcredit;
    if (strcmp(field, "name") == 0) Pcomp = compname;
    
    //根を作成
    SRec *tree;
    tree = a;
    //二分探索木への挿入プログラム
    while (a != NULL)
    {
        a = a->next;
    int order = 0;
    SRec **p;
    p=&tree;
    while( *p ) {
    order = Pcomp(*p, a);
    if (Pcomp(*p, a)==0) { return NULL; }
    /* すでに登録されている */
    else if (Pcomp(*p, a)>0) { p = &((*p)->left); }
    /* keyのほうが小さいなら，左部分木を探索 */
    else { p = &((*p)->right); }
    /* 右部分木を探索 */
    *p = a;
    /* 二分木に登録 */
    }
    }
    *A = tree;
}

//出力関数の定義
void outputfunc(FILE *fp, SRec **A)
{
    SRec *temp;
    while (*A != NULL){
        fprintf(fp, "%.6f\t", (**A).gpa);
        fprintf(fp, "%d\t", (**A).credit);
        fprintf(fp, "%s ", (**A).name);
        fprintf(fp, "\n");
        temp = (*A)->next;
        free(*A);
        *A = temp;
    }
}

/*
//バグ調査関数の定義
void dump_list(SRec *list) {
 if (list == NULL) {
 return;
 } else {
 printf("(%5.3f %3d %10s) n:%p l:%p r:%p \n"
,
 list->gpa, list->credit, list->name, list, list->left, list->right);
 dump_list(list->next);
 }
}
*/