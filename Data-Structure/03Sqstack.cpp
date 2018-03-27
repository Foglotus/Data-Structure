#include<iostream>
typedef int ElementType;
#define ERROR 0
#define OK 1
#define INCREASEMENT 5
#define INI_SIZE 10

using namespace std;

typedef struct SqStack
{
	ElementType *base;
	ElementType *top;
	int stack_size;
}SqStack;

int initSqStack(SqStack *s) {
	s->base = (ElementType *)malloc(sizeof(ElementType)*INI_SIZE);
	if (s->base == NULL)return ERROR;
	s->stack_size = INI_SIZE;
	s->top = s->base;
	return OK;
}

int pushStock(SqStack *s, int ele) {
	//ÂúÕ»
	if (s->top - s->base >= s->stack_size) {
		s->base = (ElementType *)realloc(s->base, sizeof(ElementType *)*(s->stack_size + INCREASEMENT));
		if (s->base == NULL)return ERROR;
		s->top = s->base + s->stack_size;
		s->stack_size += INCREASEMENT;
	}
	*s->top = ele;
	s->top = s->top + 1;
	return OK;
}

int pop_Stack(SqStack *s, int *element) {
	if (s->top != s->base) {
		*element = *(s->top-1);
		s->top = s->top - 1;
		return OK;
	}
	return ERROR;
}

void printStack(SqStack *s) {
	int element;
	cout << "SqStack["<<s->stack_size <<"]=>>\n";
	while (pop_Stack(s, &element)) {
		cout << "||---" << element << "---||\n";
	}
	cout << "-----------\n";
}

int main3_1() {
	SqStack s;
	initSqStack(&s);
	pushStock(&s, 1);
	pushStock(&s, 2);
	pushStock(&s, 3);
	pushStock(&s, 4);
	pushStock(&s, 5);
	pushStock(&s, 6);
	pushStock(&s, 7);
	pushStock(&s, 8);
	pushStock(&s, 9);
	pushStock(&s, 10);
	pushStock(&s, 11);
	printStack(&s);
	system("pause");
}