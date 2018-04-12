#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define ERROR 0
#define OK 1
#define STACK_INT_SIZE 10  /*存储空间初始分配量*/
#define STACKINCREMENT 5  /*存储空间分配增量*/
typedef  char ElemType; /*定义元素的类型*/

						/*（1）---补充栈的顺序存储分配表示，采用定长和可变长度存储均可*/
typedef struct SqStack {
	ElemType *base;
	ElemType *top;
	int stack_size;
}SqStack;


int InitStack(SqStack *S);         /*构造空栈*/
int Push(SqStack *S, ElemType e);   /*入栈*/
int Pop(SqStack *S, ElemType *e);   /*出栈*/
int GetTop(SqStack *S, ElemType *e); /*获取栈顶元素*/
int ClearStack(SqStack *S);         /*清空栈*/
int StackEmpty(SqStack *S);        /*判断栈是否为空*/
int StackLength(SqStack *S);        /*求栈的长度*/

void conversion();                 /*十进制转换为二进制*/
void Correct();                    /*判断表达式括号是否匹配*/

								   /*（2）---初始化栈函数*/
int InitStack(SqStack *S)
{
	S->base = (ElemType *)malloc(sizeof(ElemType)*STACK_INT_SIZE);
	if (!S->base)return ERROR;
	S->top = S->base;
	S->stack_size = STACK_INT_SIZE;
	return OK;
}/*InitStack*/

 /*（3）---入栈函数*/
int Push(SqStack *S, ElemType e)
{
	if (S->top - S->base == S->stack_size) {
		S->base = (ElemType *)realloc(S->base, sizeof(ElemType)*(S->stack_size + STACKINCREMENT));
		S->top = S->base + S->stack_size;
	}
	*S->top = e;
	S->top++;
	return OK;
}/*Push*/

 /*（4）---出栈函数*/
int Pop(SqStack *S, ElemType *e)
{
	if (StackEmpty(S) == OK)return ERROR;
	*e = *(S->top - 1);
	S->top--;
	return OK;
}/*Pop*/

 /*（5）---返回栈顶元素函数*/
int GetTop(SqStack *S, ElemType *e)
{
	if (StackEmpty(S))return ERROR;
	*e = *(S->top - 1);
	return OK;
}/*GetTop*/

 /*（6）---清空栈函数*/
int ClearStack(SqStack *S)
{
	S->top = S->base;
	return OK;
}/*ClearStack*/

 /*（8）---判断栈是否为空函数*/
int StackEmpty(SqStack *S)
{
	if (S->top == S->base)return OK;
	return ERROR;
}/*StackEmpty*/

 /*（9）---返回栈的长度函数*/
int StackLength(SqStack *S)
{
	return S->top - S->base;
}/*StackLength*/

 /*（10）---十进制整数转换为二进制并输出函数*/
void Conversion(SqStack *S, int number)
{
	char temp;
	while (number>0) {
		temp = number % 2;
		Push(S, temp);
		number /= 2;
	}
	while (Pop(S, &temp)) { printf("%d", temp); }
}/*Conversion*/

 /*（11）---判断表达式括弧是否匹配（假设只有一种小括弧）函数*/
void Correct(SqStack *S, char *fx)
{
	ElemType ele;
	ElemType temp;
	int result = 0;
	while (*fx != '\0') {
		temp = *fx;
		if (temp == '(') {
			Push(S, temp);
		}
		else if (temp == ')') {
			result = Pop(S, &ele);
			if (!result) {
				printf("跨号不匹配");
				return;
			}
		}
		fx++;
	}
	if (StackEmpty(S))printf("跨号匹配\n");
	else { printf("跨号不匹配\n"); }
}/*Correct*/

int main3_2() {
	SqStack S;
	InitStack(&S);
	int result = 0;

	printf("插入元素1");
	result = Push(&S, '1');
	if (result)printf(" OK\n");
	else printf(" FALSE\n");

	printf("插入元素2");
	result = Push(&S, '2');
	if (result)printf(" OK\n");
	else printf(" FALSE\n");

	char ele;
	printf("出栈一个元素:");
	Pop(&S, &ele);
	printf("%c\n", ele);

	printf("当前栈长：");
	int length = StackLength(&S);
	printf("%d\n", length);

	printf("出栈一个元素:");
	Pop(&S, &ele);
	printf("%c\n", ele);

	printf("十进制4096的二进制是：");
	Conversion(&S, 4096);
	printf("\n");

	printf("插入元素2");
	result = Push(&S, '2');
	if (result)printf(" OK\n");
	else printf(" FALSE\n");

	char top;
	GetTop(&S, &top);
	printf("栈顶元素是：%c", top);

	printf("出栈一个元素:");
	Pop(&S, &ele);
	printf("%c\n", ele);

	if (StackEmpty(&S))printf("当前栈空\n");

	Correct(&S, "3+4+(5+1+(1+3))");
	getchar();
	return 0;
}
