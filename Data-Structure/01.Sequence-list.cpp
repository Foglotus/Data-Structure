#include<iostream>
#include<stdarg.h>
#include<math.h>
using namespace std;
/*
˳�����ʼ����С
˳�������
����������
*/
#define INI_SIZE 10
#define INCREASE_SIZE 5
#define ERROR 0
#define CORRECT 1
typedef int ElementType;
/*
@name �ɱ��������
@ElementType  struct
@param slist  ָ��  ָ�����顣
@param length int  ��¼�����Ѿ�ʹ�õĳ���
@param size   int  ��¼���鵱ǰ��С
*/
struct Sqlist
{
	int *slist = NULL;
	int length;
	int size;
};
/*
@name ��ʼ������
@ElementType method
@param Sqlist *sqlist ˳�������
@return 1����ʼ���ɹ� 0����ʼ��ʧ��
*/
int	ini_sqlist(Sqlist *sqlist) {
	if (sqlist->slist == NULL) {
		sqlist->slist = (ElementType *)malloc(sizeof(ElementType)*INI_SIZE);
		if (!sqlist->slist)return ERROR;
	}
	sqlist->length = 0;
	sqlist->size = INI_SIZE;
	return CORRECT;
}
/*
@name ��������ֵ
@ElementType method
@param Sqlist *sqlist
@param int count������ֵ�ĸ���)
@param ...(int) ��������ֵ�����Ÿ���
@return 1:���ӳɹ� 0������ʧ��
*/
int sqlist_append_list(Sqlist *sqlist, int count, ...) {
	if (sqlist->slist == NULL) {
		return ERROR;
	}
	//1.�ռ��Ƿ���
	if ((sqlist->length + count) > sqlist->size) {
		//1.2.���������Ҫ����INCREASE_SIZE
		int sum = ceil((sqlist->length + count - sqlist->size) / (double)INCREASE_SIZE)*INCREASE_SIZE;
		sqlist->slist = (ElementType *)realloc(sqlist->slist, sizeof(ElementType)*(sqlist->size + sum));
		sqlist->size += sum;
		if (sqlist->slist == NULL) {
			return ERROR;
		}
	}
	//2.���ÿɱ������
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++) {
		sqlist->slist[sqlist->length++] = va_arg(args, int);
	}
	va_end(args);
	return CORRECT;
}
/*
@name ���鵥����ֵ
@ElementType method
@param Sqlist *sqlist
@param int ele ���ӵ�ֵ
@return 1:���ӳɹ� 0������ʧ��
*/
int sqlist_append(Sqlist *sqlist, int ele) {
	if (sqlist->slist == NULL) {
		return ERROR;
	}
	//1.�жϿռ��Ƿ��㹻
	if (sqlist->length >= sqlist->size) {
		sqlist->slist = (ElementType *)realloc(sqlist->slist, sizeof(ElementType)*(sqlist->size + INCREASE_SIZE));
		if (sqlist->slist == NULL) {
			return ERROR;
		}
		sqlist->size += INCREASE_SIZE;
	}
	sqlist->slist[sqlist->length++] = ele;
	return CORRECT;
}
/*
@name �����ӡ
@ElementType method
@param Sqlist sqlist
@param int type ���ģʽ��0����Ѿ���ʼ���ģ�1ȫ�������Ĭ��0
@output json
*/
void print_sqlist(Sqlist sqlist, int type = 0) {
	cout << "sqlist[" << sqlist.size << "]=\n(\n";
	int number = type == 1 ? sqlist.size : sqlist.length;
	for (int i = 0; i < number; i++) {
		cout << "  [" << i << "] = " << sqlist.slist[i] << "\n";
	}
	cout << ")\n";
}
int main() {
	Sqlist sqlist;
	ini_sqlist(&sqlist);
	sqlist_append_list(&sqlist, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8);
	sqlist_append(&sqlist, 9);
	sqlist_append(&sqlist, 10);
	sqlist_append(&sqlist, 11);
	print_sqlist(sqlist);
	system("pause");
	return 0;
}