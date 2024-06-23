#include <stdio.h>
#include <string.h>
//関数プロトタイプ
void get_Yazirushi(char *arg);
void get_BackslashEqualnotequal(char *arg);
void get_Backslashgreek(char *arg);
void get_Onegreek(char *arg);
void get_OneEqualnotequal(char *arg);
void get_Superscript(char *arg);
void get_Subscript(char *arg);
void get_Supersubscript(char *arg);

//引数の数が足りない、もしくは多すぎる場合の処理
int main(int argc, char *argv[]) {
	if ( argc > 10 ) {
		printf("Illegal number of argument.\n");
		return (-1);
	}
    else if ( argc < 2 ){
        printf("Please input argument.\n");
		return (-1);
    }
	
    char input[100];  // 入力文字列のサイズを十分に大きく
    int a;
	int k = argc;
	for (a = 1; a < k; a++) {
        strcpy(input, argv[a]);
        get_Yazirushi(input);
        get_BackslashEqualnotequal(input);
		get_Backslashgreek(input);
		get_Onegreek(input);
		get_OneEqualnotequal(input);
        get_Superscript(input);
		get_Subscript(input);
        get_Supersubscript(input);
        printf("%s", input);//変換後の文字列を出力
	}

	return 0;
}


//矢印記号の処理
void get_Yazirushi(char *arg) {
	char yazirushi[][100] = { "\\Rightarrow", "\\Leftarrow", "\\Leftrightarrow" };
	
	char yazirushi2[][100] = { "rArr", "lArr", "hArr" };
	int i;
	for (i=0;i<3;i++){
        if(strstr(arg, yazirushi[i]) != NULL ){
			char str[100];
			strcpy(str, yazirushi2[i]);
			sprintf(arg, "&%s;", str);
        }
    }
}

//等号不等号の処理
void get_BackslashEqualnotequal(char *arg) {
	char equal[][100] = { "\\le", "\\leq", "\\ge", "\\geq", "\\neq" };
	
	char equal2[][100] = { "le", "le", "ge", "ge", "ne" };
	int i;
	for (i=0;i<5;i++){
        if(strstr(arg, equal[i]) != NULL ){
			char str[100];
			strcpy(str, equal2[i]);
			sprintf(arg, "&%s;", str);
        }
    }
}

//ギリシャ文字の処理
void get_Backslashgreek(char *arg) {

	char greek[][100] = { "\\alpha", "\\beta", "\\gamma", "\\delta", "\\epsilon", "\\zeta",
			"\\eta", "\\theta", "\\iota", "\\kappa", "\\lambda", "\\mu", "\\nu", "\\xi", "\\pi",
			"\\rho", "\\sigma", "\\tau", "\\upsilon", "\\phi", "\\chi", "\\psi", "\\omega",
			"\\Gamma", "\\Delta", "\\Theta", "\\Lambda", "\\Xi", "\\Pi", "\\Sigma", "\\Upsilon",
			"\\Phi", "\\Psi", "\\Omega" };
    int i;
	for (i=0;i<34;i++){
        if(strstr(arg, greek[i]) != NULL ){
            char str[100];
			strcpy(str, arg);
			int n = 1;
			while ((greek[i][n] >= 'a') && (greek[i][n] <= 'z')){
				n++;
			}
			int j;
			char rts[100];
			char strr[100];
			strcpy(strr, str+1);
			for (j=0;j<n-1;j++){
				rts[j] = strr[j];
			}
			rts[n-1] = '\0';
			sprintf(arg, "&%s;%s", rts, str+n);
        }
    }
}

//ギリシャ文字の処理
void get_Onegreek(char *arg) {
	char greek2[][100] = { "A", "B", "E", "Z", "H", "I", "K", "M", "N", "O", "P", "T", "X", "o" };
	
	char greek3[][100] = { "Alpha", "Beta", "Epsilon", "Zeta", "Eta",
			"Iota", "Kappa", "Mu", "Nu", "Omicron", "Rho", "Tau", "Chi", "omicron" };
	int i;
	for (i=0;i<14;i++){
        if(strstr(arg, greek2[i]) != NULL ){
			char str1[100];
			char str2[100];
			strcpy(str1, greek3[i]);
			strcpy(str2, arg);
			sprintf(arg, "&%s;%s", str1, str2+1 );
        }
    }
}

//等号不等号の処理
void get_OneEqualnotequal(char *arg) {
	char equal3[][100] = { "=", "<", ">"};
	char equal4[][100] = { "equals", "lt", "gt"};
	int i;
	for (i=0;i<3;i++){
        if(strstr(arg, equal3[i]) != NULL ){
			char str[100];
			strcpy(str, equal4[i]);
			sprintf(arg, "&%s;", str);
        }
    }
}

//上付きの処理
void get_Superscript(char *arg) {
        if((strstr(arg, "^") != NULL) && (strstr(arg, "_") == NULL) ){
			char str[100];
            char str1[100];
            char str2[100];
			strcpy(str, arg);
            strcpy(str1, strtok(str, "^"));
            strcpy(str2, strtok(NULL, "^"));
			sprintf(arg, "%s<sup>%s</sup>", str1, str2);
        }
}

//下付きの処理
void get_Subscript(char *arg) {
        if((strstr(arg, "_") != NULL) && (strstr(arg, "^") == NULL) ){
			char str[100];
            char str1[100];
            char str2[100];
			strcpy(str, arg);
            strcpy(str1, strtok(str, "_"));
            strcpy(str2, strtok(NULL, "_"));
			sprintf(arg, "%s<sub>%s</sub>", str1, str2);
        }
}

//上付きかつ下付きの処理
void get_Supersubscript(char *arg) {
        if((strstr(arg, "^") != NULL) && (strstr(arg, "_") != NULL)){
			char str[100];
            char str1[100];
            char str2[100];
            char str3[100];
            char str4[100];
			strcpy(str, arg);
            strcpy(str1, strtok(str, "_"));
            strcpy(str2, strtok(NULL, "_"));
            strcpy(str3, strtok(str2, "^"));
            strcpy(str4, strtok(NULL, "^"));
			sprintf(arg, "%s<sub>%s</sub><sup>%s</sup>", str1, str3, str4);
        }
}