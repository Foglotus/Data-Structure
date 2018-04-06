#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct QNode {
	int data;
	struct QNode *next;
}QNode;

typedef struct Queue_Link {
	QNode *rear;
}Queue_Link;

int InitQueue_Link(Queue_Link *Q) {
	Q->rear = (QNode *)malloc(sizeof(QNode));
	Q->rear->next = Q->rear;
	return 1;
}
int Queue_Link_Empty(Queue_Link *Q) {
	if (Q->rear == Q->rear->next)return 1;
	else return 0;
}
int EnQueue_Link(Queue_Link *Q, int e) {
	//申明节点
	QNode *new_ele = (QNode *)malloc(sizeof(QNode));
	new_ele->data = e;
	//新节点的下一个是头指针
	new_ele->next = Q->rear->next;
	Q->rear->next = new_ele;
	Q->rear = Q->rear->next;
	return 1;
}

int DelQueue_Link(Queue_Link *Q, int *del) {
	if (Queue_Link_Empty(Q))return 0;
	QNode *head = Q->rear->next;
	QNode *p = head->next;
	*del = p->data;
	head->next = p->next;
	if (head == head->next)Q->rear = head;
	free(p);
	return 1;
}

int main() {
	Queue_Link Q;
	InitQueue_Link(&Q);
	printf("初始化之后：Q地址：%p Q.rear地址：%p Q.rear->next地址：%p\n", &Q, Q.rear, Q.rear->next);
	printf("当前队列是否为空：%d\n\n", Queue_Link_Empty(&Q));

	EnQueue_Link(&Q, 1);
	printf("插入元素后：Q地址：%p Q.rear地址：%p Q.rear->next地址：%p\n", &Q, Q.rear, Q.rear->next);
	printf("当前队列第一个元素：%d 地址为：%p\n", Q.rear->next->next->data, Q.rear->next->next);
	printf("当前队列是否为空：%d\n\n", Queue_Link_Empty(&Q));

	EnQueue_Link(&Q, 2);
	printf("插入元素后：Q地址：%p Q.rear地址：%p Q.rear->next地址：%p\n", &Q, Q.rear, Q.rear->next);
	printf("当前队列尾元素：%d\n", Q.rear->data);
	printf("当前队列是否为空：%d\n\n", Queue_Link_Empty(&Q));

	EnQueue_Link(&Q, 3);
	printf("插入元素后：Q地址：%p Q.rear地址：%p Q.rear->next地址：%p\n", &Q, Q.rear, Q.rear->next);
	printf("当前队列尾元素：%d\n", Q.rear->data);
	printf("当前队列是否为空：%d\n\n", Queue_Link_Empty(&Q));


	EnQueue_Link(&Q, 4);
	printf("插入元素后：Q地址：%p Q.rear地址：%p Q.rear->next地址：%p\n", &Q, Q.rear, Q.rear->next);
	printf("当前队列尾元素：%d\n", Q.rear->data);
	printf("当前队列是否为空：%d\n\n", Queue_Link_Empty(&Q));
	int del;
	while (DelQueue_Link(&Q, &del)) {
		printf("%d\t", del);
		printf("当前队列是否为空：%d\n", Queue_Link_Empty(&Q));

		printf("删除之后：Q地址：%p Q.rear地址：%p Q.rear->next地址：%p\n", &Q, Q.rear, Q.rear->next);

		getchar();
	}
	return 0;
}
