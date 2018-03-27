#include<iostream>
using namespace std;
#define ERROR 0
#define OK 1
typedef struct LNode {
	int data;
	LNode *next;
}LNode,*LinkList;
/*
@name 初始化链表
@return 成功：头结点地址  初始化失败:ERROR
*/
LNode * ini_LinkList() {
	LNode *node = (LNode *)malloc(sizeof(LNode));
	if (!node)return ERROR;
	node->data = NULL;
	node->next = NULL;
	return node;
}
/*
@name 链表添加元素
@ElementType method
@param LinkList L
@param int element 添加的值
@return 添加成功: CORRECT 添加失败:ERROR
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
@name 链表打印
@ElementType method
@param LinkList L
@output 链表信息
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
@name 链表逆序
@ElementType method
@param LinkList L
*/
void invertLinkList(LinkList L) {
	//LNode *head=L;
	//LNode *tail=L->next;
	//LNode *temp;
	//temp = tail;
	//tail = tail->next;//tail减少一个
	//temp->next =NULL;
	//head->next = temp;
	//while (tail !=NULL) {
	//	temp = tail;//tail弹出一个给temp
	//	tail = tail->next;//tail减少一个
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
@name 删除第i个节点，并返回节点
@param LinkList L
@param int i 删除第i个节点
@param LNode *element 接收删除节点
@return 成功:CORRECT 失败:ERROR
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
	/*--链表初始化--*/
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