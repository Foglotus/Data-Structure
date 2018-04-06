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
	//�����ڵ�
	QNode *new_ele = (QNode *)malloc(sizeof(QNode));
	new_ele->data = e;
	//�½ڵ����һ����ͷָ��
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
	printf("��ʼ��֮��Q��ַ��%p Q.rear��ַ��%p Q.rear->next��ַ��%p\n", &Q, Q.rear, Q.rear->next);
	printf("��ǰ�����Ƿ�Ϊ�գ�%d\n\n", Queue_Link_Empty(&Q));

	EnQueue_Link(&Q, 1);
	printf("����Ԫ�غ�Q��ַ��%p Q.rear��ַ��%p Q.rear->next��ַ��%p\n", &Q, Q.rear, Q.rear->next);
	printf("��ǰ���е�һ��Ԫ�أ�%d ��ַΪ��%p\n", Q.rear->next->next->data, Q.rear->next->next);
	printf("��ǰ�����Ƿ�Ϊ�գ�%d\n\n", Queue_Link_Empty(&Q));

	EnQueue_Link(&Q, 2);
	printf("����Ԫ�غ�Q��ַ��%p Q.rear��ַ��%p Q.rear->next��ַ��%p\n", &Q, Q.rear, Q.rear->next);
	printf("��ǰ����βԪ�أ�%d\n", Q.rear->data);
	printf("��ǰ�����Ƿ�Ϊ�գ�%d\n\n", Queue_Link_Empty(&Q));

	EnQueue_Link(&Q, 3);
	printf("����Ԫ�غ�Q��ַ��%p Q.rear��ַ��%p Q.rear->next��ַ��%p\n", &Q, Q.rear, Q.rear->next);
	printf("��ǰ����βԪ�أ�%d\n", Q.rear->data);
	printf("��ǰ�����Ƿ�Ϊ�գ�%d\n\n", Queue_Link_Empty(&Q));


	EnQueue_Link(&Q, 4);
	printf("����Ԫ�غ�Q��ַ��%p Q.rear��ַ��%p Q.rear->next��ַ��%p\n", &Q, Q.rear, Q.rear->next);
	printf("��ǰ����βԪ�أ�%d\n", Q.rear->data);
	printf("��ǰ�����Ƿ�Ϊ�գ�%d\n\n", Queue_Link_Empty(&Q));
	int del;
	while (DelQueue_Link(&Q, &del)) {
		printf("%d\t", del);
		printf("��ǰ�����Ƿ�Ϊ�գ�%d\n", Queue_Link_Empty(&Q));

		printf("ɾ��֮��Q��ַ��%p Q.rear��ַ��%p Q.rear->next��ַ��%p\n", &Q, Q.rear, Q.rear->next);

		getchar();
	}
	return 0;
}
