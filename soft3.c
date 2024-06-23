/*
 ============================================================================
 Name        : soft3.c
 Author      : 加藤平大23122011
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define N 10

//本課題においては行列の積の一般化の公式を使用した。

void input_matrix(float X[N][N], int *n);
void multiply_matrix(float Z[N][N], float X[N][N], float Y[N][N], int *n);
void output_matrix(float Z[N][N], int *n);

int main(void) {
float a[N][N];
float ak[N][N];
int number;
 //入力
 input_matrix(a, &number);
 //乗算
 multiply_matrix(ak, a, a, &number);
 //出力
 output_matrix(ak, &number);
}

//入力関数の定義
void input_matrix(float X[N][N], int *n){
    int i, j;
    printf("Aは何次正方行列？:");
    scanf("%d",n);
    for (i = 0; i < *n; i++) {
        for (j = 0; j < *n; j++) {
            printf("%d行%d列目の値は:", i + 1, j + 1);
            scanf("%f", &X[i][j]);
        }
    }
    printf("\n");
}

//乗算関数の定義
void multiply_matrix(float Z[N][N], float X[N][N], float Y[N][N], int *n) {
    for(int i=0; i<*n; i++) {
 for(int j=0; j<*n; j++) {
    Z[i][j] = 0;
    for(int k=0; k<*n; k++){
Z[i][j] += ( X[i][k] * Y[k][j] );
    }
 }
}
}

//出力関数の定義
void output_matrix(float Z[N][N], int *n){
    printf("%d次正方行列行列Aの二乗は\n", *n);
    int i, j;
    for (i = 0; i < *n; i++) {
        for (j = 0; j < *n; j++) {
            printf("%10f ", Z[i][j]);
        }
        printf("\n");
    }
}