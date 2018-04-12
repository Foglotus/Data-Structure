#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//初始化参数
#define INITSIZE 10
#define INCREASE 20
//初始化状态信息参数
#define OK 1
#define ERROR 0

using namespace std;

typedef struct {
	char *data;
	int length;
	int size;
}SqString;
//函数申明
int InitString(SqString *);
int StrAssign(SqString *, char *);


int StrNext(SqString *S,int *next) {
	int m = strlen(S->data);
	next[0] = 0;
	int p , k;
	for (p = 1, k = 0; p < m; p++) {
		
		while (k > 0 && S->data[k] != S->data[p])
			k = next[k - 1];
		if (S->data[k] == S->data[p])k++;
		next[p] = k;
	}

	return OK;
}

int KMPStr(SqString *S1, SqString *S2, int *next) {
	int p_length = S1->length;
	int t_length = S2->length;
	int i = 0,j=0;
	while (i < p_length) {
		if (S1->data[i] == S2->data[j]) {
			j++;
		}
		else {
			j = j - next[j];
		}
		i++;
		if (j == t_length) {
			printf("find at %d length:%d", i - j + 1, j);
			return OK;
		}
	}
	printf("false");
}

int main() {
	SqString S1;
	InitString(&S1);
	StrAssign(&S1, "ababxbababcadfdsss");

	SqString S2;
	InitString(&S2);
	StrAssign(&S2, "abcad");

	int *next = (int *)malloc(sizeof(int)*S2.length);

	StrNext(&S2, next);

	printf("%s\n%s\n", S1.data, S2.data);
	KMPStr(&S1, &S2, next);

	getchar();


}