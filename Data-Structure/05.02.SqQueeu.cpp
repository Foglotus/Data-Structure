#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define MAXQSIZE 10
typedef  int QElemType; /*定义元素的类型*/
						/*（1）---循环队列顺序存储表示*/
typedef struct
{
	QElemType *base;
	int front;
	int rear;
}SqQueue;
int QueueEmpty(SqQueue *Q);
/*（2）---构造一个空循环队列*/
int InitQueue(SqQueue *Q)
{
	Q->base = (QElemType *)malloc(sizeof(QElemType) * MAXQSIZE);
	if (!Q->base)return ERROR;
	Q->front = 0;
	Q->rear = 0;
	return OK;
}/*InitQueue*/

 /*（3）---返回循环队列的长度*/
int QueueLength(SqQueue *Q)
{
	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
}/*QueueLentgh*/

 /*（4）---入队操作*/
int EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXQSIZE == Q->front)return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}/*EnQuese*/

 /*（5）---出队操作*/
int DeQueue(SqQueue *Q, QElemType *e)
{
	if (QueueEmpty(Q))return ERROR;
	*e = Q->base[Q->front++];
	return OK;
}/*DeQueue*/

 /*（6）---判断队列是否为空*/
int QueueEmpty(SqQueue *Q)
{
	if (Q->rear == Q->front)return OK;
	else return ERROR;

}/*QueueEmpty*/

 /*（7）---取队头元素*/
int GetHead(SqQueue *Q, QElemType *e)
{
	if (QueueEmpty(Q))return ERROR;
	*e = Q->base[Q->front];
	return OK;
}/*GetHead*/

 /*销毁队列*/
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

	printf("当前队列长度：");
	q_length = QueueLength(&Q);
	printf("%d\n", q_length);

	printf("当前队列是否为空:");
	is_empty = QueueEmpty(&Q);
	is_empty == 1 ? printf("YES\n") : printf("NO\n");

	printf("1进队:");
	result = EnQueue(&Q, 1);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("2进队:");
	result = EnQueue(&Q, 2);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("3进队:");
	result = EnQueue(&Q, 3);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("当前队列长度：");
	q_length = QueueLength(&Q);
	printf("%d\n", q_length);

	printf("当前对头元素:");
	result = GetHead(&Q, &head);
	result == 1 ? printf("%d\n", head) : printf("ERROR\n");

	printf("元素出队:");
	result = DeQueue(&Q, &del);
	result == 1 ? printf("%d\n", del) : printf("ERROR\n");

	printf("元素出队:");
	result = DeQueue(&Q, &del);
	result == 1 ? printf("%d\n", del) : printf("ERROR\n");

	printf("元素出队:");
	result = DeQueue(&Q, &del);
	result == 1 ? printf("%d\n", del) : printf("ERROR\n");

	printf("当前队列是否为空:");
	is_empty = QueueEmpty(&Q);
	is_empty == 1 ? printf("YES\n") : printf("NO\n");

	printf("元素出队:");
	result = DeQueue(&Q, &del);
	result == 1 ? printf("%d\n", del) : printf("ERROR\n");

	printf("1进队:");
	result = EnQueue(&Q, 1);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("2进队:");
	result = EnQueue(&Q, 2);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("3进队:");
	result = EnQueue(&Q, 3);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("4进队:");
	result = EnQueue(&Q, 4);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("5进队:");
	result = EnQueue(&Q, 5);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("6进队:");
	result = EnQueue(&Q, 6);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("7进队:");
	result = EnQueue(&Q, 7);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("8进队:");
	result = EnQueue(&Q, 8);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	printf("当前队列长度：");
	q_length = QueueLength(&Q);
	printf("%d\n", q_length);

	printf("销毁队列Q：");
	result = DestroyQueue(&Q);
	result == 1 ? printf("OK\n") : printf("ERROR\n");

	getchar();
	return 0;
}