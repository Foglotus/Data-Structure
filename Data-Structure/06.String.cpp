#include<iostream>
#include<malloc.h>

//初始化参数
#define INITSIZE 10
#define INCREASE 20
//初始化状态信息参数
#define OK 1
#define ERROR 0

typedef struct {
	char *data;
	int length;
	int size;
}SqString;
/*
 *初始化串
**/

int InitString(SqString *S) {
	S->data = (char *)malloc(sizeof(char )*INITSIZE);
	if (!S->data)return ERROR;
	S->size = INITSIZE;
	S->length = 0;
	return OK;
}

int StrInsert(SqString *S,int pos,char ch) {
	if (pos-1 > S->length || pos < 1) return ERROR;

	if (S->length+1 == S->size) {
		S->data = (char *)realloc(S->data, sizeof(char)*(S->size + INCREASE));
		if (!S->data)return ERROR;
		S->size += INCREASE;
	}

	int length = S->length;
	while (length >= pos) {
		S->data[length] = S->data[length - 1];
		length--;
	}
	S->data[pos - 1] = ch;
	S->length++;
	S->data[S->length] = '\0';
	return OK;
}

int StrAssign(SqString *S, char *str) {
	while (*str != '\0') {
		if (S->length == S->size) {
			S->data = (char *)realloc(S->data, sizeof(char)*(S->size + INCREASE));
			if (!S->data)return ERROR;
			S->size += INCREASE;
		}
		S->data[S->length++] = *str++;
	}

	if (S->length < S->size) {
		S->data[S->length] = '\0';
	}
	return OK;
}

void StrPrint(SqString *S) {
	printf("string[%d](%d)=%s\n",S->size,S->length,S->data);
}

int StrEmpty(SqString *S) {
	return !S->length;
}

int StrLength(SqString *S) {
	return S->length;
}

int StrCompare(SqString *S, SqString *T) {
	int i = 0;
	while (i < S->length && i < T->length) {
		if (S->data[i] != T->data[i])return S->data[i] - T->data[i];
		i++;
	}
	return S->length == T->length ? 0 : S->length - T->length;
}

int StrCopy(SqString *S,SqString *T) {
	if (T->length <= 0)return ERROR;

	int i = 0;

	int end = S->size < T->length ? S->size : T->length;

	while (i < end) S->data[i] = T->data[i++];

	S->length = i;
	if (S->length < S->size) S->data[S->length] = '\0';
	return OK;
}

int StrFilter(SqString *S, char ch) {
	int index = 0;
	int i = 0;
	for (; i < S->length; i++) {
		if (S->data[i] != ch)S->data[index++] = S->data[i];
	}
	S->length = index;
	if(S->length < S->size)	S->data[index] = '\0';
	return OK;
}

int StrConcat(SqString *S,SqString *s1,SqString *s2) {
	int i = 0,j=0;
	if (S->size < s1->length + s2->length) {
		S->data = (char *)realloc(s1->data, sizeof(char)*(s1->length + s2->length));
		if (!S->data)return ERROR;
		S->size = s1->length + s2->length;
		while (i < s2->length)S->data[s1->length + i] = s2->data[i++];
		S->length = s1->length + s2->length;
	}
	else {
		while (i < s1->length) {
			S->data[i] = s1->data[i];
		}
		while (j < s2->length) {
			S->data[i + j] = s2->data[j];
		}
		S->length = i + j;
		if (S->length < S->size)S->data[S->length] = '\0';
	}
	return OK;
}

int main() {
	SqString S,T,U;
	InitString(&S);
	InitString(&T);
	InitString(&U);
	//StrInsert(&S,1,'1');
	StrAssign(&S, "12345");
	//StrPrint(&S);
	StrAssign(&T, "1234567890");
	//StrPrint(&T);
	StrAssign(&U, "1123145678901");
	//StrPrint(&U);

	/*printf("复制前S:");
	StrPrint(&S);
	printf("T:");
	StrPrint(&T);
	StrCopy(&S, &T);
	printf("S复制后:");
	StrPrint(&S);*/

	/*printf("复制前U:");
	StrPrint(&U);
	printf("S:");
	StrPrint(&S);
	StrCopy(&U, &S);
	printf("U复制后:");
	StrPrint(&S);*/

	/*int result = StrCompare(&S, &T);
	printf("%d", result);*/

	/*printf("过滤【1】前U:");
	StrPrint(&U);
	printf("过滤【1】后U:");
	StrFilter(&U, '1');
	StrPrint(&U);*/

	printf("S:");
	StrPrint(&S);

	printf("T:");
	StrPrint(&T);

	printf("U:");
	StrPrint(&U);

	printf("S=T+U:");
	int retult = StrConcat(&S, &T, &U);
	StrPrint(&S);
	getchar();
	return 0;
}