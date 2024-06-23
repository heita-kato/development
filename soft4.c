/*
 ============================================================================
 Name        : soft4.c
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

void input_matrix(float Z[N][N], float X[N][N], int *n, int *k);
void multiply_matrix(float Z[N][N], float X[N][N], float Y[N][N], int *n);
void power_matrix(float Z[N][N], float X[N][N], int *n, int *k);
void output_matrix(float Z[N][N], int *n, int *k);

int main(void) {
float a[N][N];
float ak[N][N];
int number;
int kernel;
 //入力
 input_matrix(ak, a, &number, &kernel);
 //累乗
 power_matrix(ak, a, &number, &kernel);
 //出力
 output_matrix(ak, &number, &kernel);
}

//入力関数の定義
void input_matrix(float Z[N][N], float X[N][N], int *n, int *k){
    int i, j;
    printf("Aは何次正方行列？:");
    scanf("%d",n);
    if((*n)<1){
        printf("自然数を入力して下さい\n");
        exit(0);
        }
    printf("Aの何乗を計算する？:");
    scanf("%d",k);
    if((*k)<1){
        printf("自然数を入力して下さい\n");
        exit(0);
        }
    for (i = 0; i < *n; i++) {
        for (j = 0; j < *n; j++) {
            printf("%d行%d列目の値は:", i + 1, j + 1);
            scanf("%f", &X[i][j]);
            Z[i][j] = X[i][j];
        }
    }
    printf("\n");
}

//乗算関数の定義
void multiply_matrix(float Z[N][N], float X[N][N], float Y[N][N], int *n) {
    for(int i=0; i<*n; i++) {
 for(int j=0; j<*n; j++) {
    Z[i][j] = 0;
    for(int l=0; l<*n; l++){
Z[i][j] += ( X[i][l] * Y[l][j] );
    }
 }
}
}

//累乗関数の定義
void power_matrix(float Z[N][N], float X[N][N], int *n, int *k){
    if(*k == 1){
        for(int i=0; i<*n; i++) {
 for(int j=0; j<*n; j++) {
    Z[i][j] = X[i][j];
 }
        }
    }
    else
{
    multiply_matrix(Z, X, X, n);
    for(int i=2; i<*k; i++) {
        float TEMP[N][N];
        for(int i=0; i<*n; i++) {
 for(int j=0; j<*n; j++) {
    TEMP[i][j] = Z[i][j];
 }
        }
    multiply_matrix(Z, X, TEMP, n);
    }
}
}

//出力関数の定義
void output_matrix(float Z[N][N], int *n, int *k){
    printf("%d次正方行列行列Aの%d乗は\n", *n, *k);
    int i, j;
    for (i = 0; i < *n; i++) {
        for (j = 0; j < *n; j++) {
            printf("%10f ", Z[i][j]);
        }
        printf("\n");
    }
}