#include <iostream>
#define OK 1
#define ERROR 0

typedef int ElementType;
typedef struct StackNode {
	ElementType data;
	StackNode *next;
}StackNode,*LinkStack;

using namespace std;

int initLinkStack(LinkStack top) {
	top = NULL;
	return OK;
}

LinkStack pushLinkStack(LinkStack top,ElementType ele) {
	StackNode *sn = (StackNode *)malloc(sizeof(StackNode));
	if (sn == NULL)return NULL;
	sn->data = ele;
	sn->next = top;
	top = sn;
	return top;
}
LinkStack popLinkStack(LinkStack top,ElementType *ele) {
	if (top == NULL)return NULL;
	StackNode *temp;
	*ele = top->data;
	temp = top;
	top = top->next;
	free(temp);
	return top;
}
LinkStack printStack(LinkStack top) {
	int element;
	cout << "LinkStack=>>\n";
	while (top) {
		top = popLinkStack(top, &element);
		cout << "||---" << element << "---||\n";
	}
	cout << "-----------\n";
	return top;
}
int main4() {
	LinkStack top=NULL;
	initLinkStack(top);
	top = pushLinkStack(top, 1);
	top = pushLinkStack(top, 2);
	top = pushLinkStack(top, 3);
	top = pushLinkStack(top, 4);
	top = pushLinkStack(top, 5);
	top = pushLinkStack(top, 6);
	top = pushLinkStack(top, 7);
	top = pushLinkStack(top, 8);
	top = printStack(top);
	return 0;
}

