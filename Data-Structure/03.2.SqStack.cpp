#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define ERROR 0
#define OK 1
#define STACK_INT_SIZE 10  /*�洢�ռ��ʼ������*/
#define STACKINCREMENT 5  /*�洢�ռ��������*/
typedef  char ElemType; /*����Ԫ�ص�����*/

						/*��1��---����ջ��˳��洢�����ʾ�����ö����Ϳɱ䳤�ȴ洢����*/
typedef struct SqStack {
	ElemType *base;
	ElemType *top;
	int stack_size;
}SqStack;


int InitStack(SqStack *S);         /*�����ջ*/
int Push(SqStack *S, ElemType e);   /*��ջ*/
int Pop(SqStack *S, ElemType *e);   /*��ջ*/
int GetTop(SqStack *S, ElemType *e); /*��ȡջ��Ԫ��*/
int ClearStack(SqStack *S);         /*���ջ*/
int StackEmpty(SqStack *S);        /*�ж�ջ�Ƿ�Ϊ��*/
int StackLength(SqStack *S);        /*��ջ�ĳ���*/

void conversion();                 /*ʮ����ת��Ϊ������*/
void Correct();                    /*�жϱ��ʽ�����Ƿ�ƥ��*/

								   /*��2��---��ʼ��ջ����*/
int InitStack(SqStack *S)
{
	S->base = (ElemType *)malloc(sizeof(ElemType)*STACK_INT_SIZE);
	if (!S->base)return ERROR;
	S->top = S->base;
	S->stack_size = STACK_INT_SIZE;
	return OK;
}/*InitStack*/

 /*��3��---��ջ����*/
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

 /*��4��---��ջ����*/
int Pop(SqStack *S, ElemType *e)
{
	if (StackEmpty(S) == OK)return ERROR;
	*e = *(S->top - 1);
	S->top--;
	return OK;
}/*Pop*/

 /*��5��---����ջ��Ԫ�غ���*/
int GetTop(SqStack *S, ElemType *e)
{
	if (StackEmpty(S))return ERROR;
	*e = *(S->top - 1);
	return OK;
}/*GetTop*/

 /*��6��---���ջ����*/
int ClearStack(SqStack *S)
{
	S->top = S->base;
	return OK;
}/*ClearStack*/

 /*��8��---�ж�ջ�Ƿ�Ϊ�պ���*/
int StackEmpty(SqStack *S)
{
	if (S->top == S->base)return OK;
	return ERROR;
}/*StackEmpty*/

 /*��9��---����ջ�ĳ��Ⱥ���*/
int StackLength(SqStack *S)
{
	return S->top - S->base;
}/*StackLength*/

 /*��10��---ʮ��������ת��Ϊ�����Ʋ��������*/
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

 /*��11��---�жϱ��ʽ�����Ƿ�ƥ�䣨����ֻ��һ��С����������*/
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
				printf("��Ų�ƥ��");
				return;
			}
		}
		fx++;
	}
	if (StackEmpty(S))printf("���ƥ��\n");
	else { printf("��Ų�ƥ��\n"); }
}/*Correct*/

int main3_2() {
	SqStack S;
	InitStack(&S);
	int result = 0;

	printf("����Ԫ��1");
	result = Push(&S, '1');
	if (result)printf(" OK\n");
	else printf(" FALSE\n");

	printf("����Ԫ��2");
	result = Push(&S, '2');
	if (result)printf(" OK\n");
	else printf(" FALSE\n");

	char ele;
	printf("��ջһ��Ԫ��:");
	Pop(&S, &ele);
	printf("%c\n", ele);

	printf("��ǰջ����");
	int length = StackLength(&S);
	printf("%d\n", length);

	printf("��ջһ��Ԫ��:");
	Pop(&S, &ele);
	printf("%c\n", ele);

	printf("ʮ����4096�Ķ������ǣ�");
	Conversion(&S, 4096);
	printf("\n");

	printf("����Ԫ��2");
	result = Push(&S, '2');
	if (result)printf(" OK\n");
	else printf(" FALSE\n");

	char top;
	GetTop(&S, &top);
	printf("ջ��Ԫ���ǣ�%c", top);

	printf("��ջһ��Ԫ��:");
	Pop(&S, &ele);
	printf("%c\n", ele);

	if (StackEmpty(&S))printf("��ǰջ��\n");

	Correct(&S, "3+4+(5+1+(1+3))");
	getchar();
	return 0;
}
