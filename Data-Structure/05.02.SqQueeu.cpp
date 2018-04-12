#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define MAXQSIZE 10
typedef  int QElemType; /*����Ԫ�ص�����*/
						/*��1��---ѭ������˳��洢��ʾ*/
typedef struct
{
	QElemType *base;
	int front;
	int rear;
}SqQueue;
int QueueEmpty(SqQueue *Q);
/*��2��---����һ����ѭ������*/
int InitQueue(SqQueue *Q)
{
	Q->base = (QElemType *)malloc(sizeof(QElemType) * MAXQSIZE);
	if (!Q->base)return ERROR;
	Q->front = 0;
	Q->rear = 0;
	return OK;
}/*InitQueue*/

 /*��3��---����ѭ�����еĳ���*/
int QueueLength(SqQueue *Q)
{
	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
}/*QueueLentgh*/

 /*��4��---��Ӳ���*/
int EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXQSIZE == Q->front)return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}/*EnQuese*/

 /*��5��---���Ӳ���*/
int DeQueue(SqQueue *Q, QElemType *e)
{
	if (QueueEmpty(Q))return ERROR;
	*e = Q->base[Q->front++];
	return OK;
}/*DeQueue*/

 /*��6��---�ж϶����Ƿ�Ϊ��*/
int QueueEmpty(SqQueue *Q)
{
	if (Q->rear == Q->front)return OK;
	else return ERROR;

}/*QueueEmpty*/

 /*��7��---ȡ��ͷԪ��*/
int GetHead(SqQueue *Q, QElemType *e)
{
	if (QueueEmpty(Q))return ERROR;
	*e = Q->base[Q->front];
	return OK;
}/*GetHead*/

 /*���ٶ���*/
int DestroyQueue(SqQueue *Q)
{
	if (Q->base)
	{
		Q->rear = Q->front = 0;
		free(Q->base);
	}
	return OK;
}/*DestroyQueue*/


int main5_02() {
	SqQueue Q;
	InitQueue(&Q);
	int is_empty;
	int q_length;
	int result;
	int del;
	int head;

	printf("��ǰ���г��ȣ�");
	q_length = QueueLength(&Q);
	printf("%d\n", q_length);

	printf("��ǰ�����Ƿ�Ϊ��:");
	is_empty = QueueEmpty(&Q);
	is_empty == 1 ? printf("YES\n") : printf("NO\n");

	printf("1����:");
	result = EnQueue(&Q, 1);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("2����:");
	result = EnQueue(&Q, 2);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("3����:");
	result = EnQueue(&Q, 3);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("��ǰ���г��ȣ�");
	q_length = QueueLength(&Q);
	printf("%d\n", q_length);

	printf("��ǰ��ͷԪ��:");
	result = GetHead(&Q, &head);
	result == 1 ? printf("%d\n", head) : printf("ERROR\n");

	printf("Ԫ�س���:");
	result = DeQueue(&Q, &del);
	result == 1 ? printf("%d\n", del) : printf("ERROR\n");

	printf("Ԫ�س���:");
	result = DeQueue(&Q, &del);
	result == 1 ? printf("%d\n", del) : printf("ERROR\n");

	printf("Ԫ�س���:");
	result = DeQueue(&Q, &del);
	result == 1 ? printf("%d\n", del) : printf("ERROR\n");

	printf("��ǰ�����Ƿ�Ϊ��:");
	is_empty = QueueEmpty(&Q);
	is_empty == 1 ? printf("YES\n") : printf("NO\n");

	printf("Ԫ�س���:");
	result = DeQueue(&Q, &del);
	result == 1 ? printf("%d\n", del) : printf("ERROR\n");

	printf("1����:");
	result = EnQueue(&Q, 1);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("2����:");
	result = EnQueue(&Q, 2);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("3����:");
	result = EnQueue(&Q, 3);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("4����:");
	result = EnQueue(&Q, 4);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("5����:");
	result = EnQueue(&Q, 5);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("6����:");
	result = EnQueue(&Q, 6);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("7����:");
	result = EnQueue(&Q, 7);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("8����:");
	result = EnQueue(&Q, 8);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("��ǰ���г��ȣ�");
	q_length = QueueLength(&Q);
	printf("%d\n", q_length);

	printf("���ٶ���Q��");
	result = DestroyQueue(&Q);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	getchar();
	return 0;
}