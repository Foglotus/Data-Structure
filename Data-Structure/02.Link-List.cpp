#include<iostream>
using namespace std;
#define ERROR 0
#define OK 1
typedef struct LNode {
	int data;
	LNode *next;
}LNode,*LinkList;
/*
@name ��ʼ������
@return �ɹ���ͷ����ַ  ��ʼ��ʧ��:ERROR
*/
LNode * ini_LinkList() {
	LNode *node = (LNode *)malloc(sizeof(LNode));
	if (!node)return ERROR;
	node->data = NULL;
	node->next = NULL;
	return node;
}
/*
@name �������Ԫ��
@ElementType method
@param LinkList L
@param int element ��ӵ�ֵ
@return ��ӳɹ�: CORRECT ���ʧ��:ERROR
*/
int linklistAppendElement(LinkList L,int element) {
	if (!L)return ERROR;
	LNode * node = L;
	while (node->next != NULL)node= node->next;
	node->next = (LNode *)malloc(sizeof(LNode));
	node->next->data = element;
	node->next->next = NULL;
	return true;
}
/*
@name �����ӡ
@ElementType method
@param LinkList L
@output ������Ϣ
*/
void printLinkList(LinkList L) {
	LNode *node = L->next;
	cout << "LinkList\n=>";
	int num = 1;
	while (node) {
		cout << "[key:" << num++ << ",data:" << node->data <<",self:"<<node<< ",next:" << node->next << "]\n=>";
		node = node->next;
	}
	cout << "[NULL]\n";
}
/*
@name ��������
@ElementType method
@param LinkList L
*/
void invertLinkList(LinkList L) {
	//LNode *head=L;
	//LNode *tail=L->next;
	//LNode *temp;
	//temp = tail;
	//tail = tail->next;//tail����һ��
	//temp->next =NULL;
	//head->next = temp;
	//while (tail !=NULL) {
	//	temp = tail;//tail����һ����temp
	//	tail = tail->next;//tail����һ��
	//	temp->next = head->next;
	//	head->next = temp;
	//}	
	//L = head;
	LNode *head = L;
	LNode * p;
	LNode *tail = L->next;
	head->next = NULL;
	while (tail != NULL) {
		p = tail->next;
		tail->next = head->next;
		head->next = tail;
		tail = p;
	}
	L = head;
}
/*
@name ɾ����i���ڵ㣬�����ؽڵ�
@param LinkList L
@param int i ɾ����i���ڵ�
@param LNode *element ����ɾ���ڵ�
@return �ɹ�:CORRECT ʧ��:ERROR
*/
int linkListDeleteByIndex(LinkList L,int i) {
	LNode *p = L;
	while (--i>=1)
	{
		if(p->next)p = p->next;
		else return ERROR;
	}

	LNode *del = p->next;
	p->next = p->next->next;
	cout << "[data:" << del->data << ",self:" << del << ",next:" << del->next << "]\n";
	free(del);
	return OK;
}
void main2() {
	/*--�����ʼ��--*/
	/*LinkList linklist = ini_LinkList();
	linklistAppendElement(linklist,1);
	linklistAppendElement(linklist, 2);
	linklistAppendElement(linklist, 3);
	linklistAppendElement(linklist, 4);
	printLinkList(linklist);
	invertLinkList(linklist);
	printLinkList(linklist);*/

	/*LinkList linklist = ini_LinkList();
	linklistAppendElement(linklist, 1);
	linklistAppendElement(linklist, 2);
	linklistAppendElement(linklist, 3);
	linklistAppendElement(linklist, 4);
	printLinkList(linklist);
	linkListDeleteByIndex(linklist, 2);
	printLinkList(linklist);*/
}