#include<iostream>
#include<stdarg.h>
#include<math.h>
using namespace std;
/*
����˳����ʼ����С
˳�������
����������
*/
#define INI_SIZE 10
#define INCREASE_SIZE 5
#define ERROR 0
#define CORRECT 1
typedef int ElementType;
/*
@name ����˳������
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
@name ��ʼ������˳���
@ElementType method
@param Sqlist *sqlist ˳������
@return ��ʼ���ɹ�: CORRECT ��ʼ��ʧ��:ERROR
*/
int	iniSqlist(Sqlist *sqlist) {
	if (sqlist->slist == NULL) {
		sqlist->slist = (ElementType *)malloc(sizeof(ElementType)*INI_SIZE);
		if (!sqlist->slist)return ERROR;
	}
	sqlist->length = 0;
	sqlist->size = INI_SIZE;
	return CORRECT;
}
/*
@name ����˳�������ֵ
@ElementType method
@param Sqlist *sqlist
@param int count�����ֵ�ĸ���)
@param ...(int) ��������ֵ�����Ÿ���
@return ��ӳɹ�: CORRECT ���ʧ��:ERROR
*/
int sqlistAppendList(Sqlist *sqlist, int count, ...) {
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
@name ����˳�������ֵ
@ElementType method
@param Sqlist *sqlist
@param int ele ��ӵ�ֵ
@return ��ӳɹ�: CORRECT ���ʧ��:ERROR
*/
int sqlistAppend(Sqlist *sqlist, int ele) {
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
@name ����˳����ӡ
@ElementType method
@param Sqlist sqlist
@param int type ���ģʽ��0����Ѿ���ʼ���ģ�1ȫ�������Ĭ��0
@output json
*/
void sqlistPrint(Sqlist sqlist, int type = 0) {
	cout << "sqlist[" << sqlist.size << "]\n(\n";
	int number = type == 1 ? sqlist.size : sqlist.length;
	for (int i = 0; i < number; i++) {
		cout << "  [" << i << "] = " << sqlist.slist[i] << "\n";
	}
	cout << ")\n";
}
/*
@name ��iλ��֮ǰ����ֵ
@ElementType method
@param Sqlist *sqlist
@param int i �����λ��
@param ele Ԫ��
@return �ɹ���CORRECT ʧ�ܣ�ERROR
*/
int sqlistInsertByIndex(Sqlist *sqlist,int i,int ele){
	//�жϲ����Ƿ�Ϸ�
	//1.���Ա��Ƿ�δ��ʼ��������λ���Ƿ����
	if (sqlist->slist == NULL || i < 1 || i > sqlist->length) {
		return ERROR;
	}
	if (sqlist->size <= sqlist->length) {
		sqlist->slist = (ElementType *)realloc(sqlist->slist, sizeof(ElementType)*(sqlist->size + INCREASE_SIZE));
		if (!sqlist->slist)return ERROR;
		sqlist->size += INCREASE_SIZE;
	}
	for (int start = sqlist->length-1; start>=i-1; start--) {
		sqlist->slist[start + 1] = sqlist->slist[start];
	}
	sqlist->slist[i - 1] = ele;
	sqlist->length++;
	return CORRECT;
}
/*
@name ��ת���Ա�
@param Sqlist *sqlist
@return �ɹ�:CORRECT ʧ��:ERROR
*/
int sqlistInverse(Sqlist *sqlist) {
	if (!sqlist->slist) { return ERROR; }
	int *start, *end,temp;
	start = sqlist->slist;
	end = &sqlist->slist[sqlist->length - 1];
	while (end > start) {
		temp = *start;
		*start = *end;
		*end = temp;
		start++; 
		end--;
	}
	return CORRECT;
}
/*
@name ���Ա�����
@param Sqlist *sqlist
@param int mode 0Ĭ���������У�1��������
@return �ɹ�:CORRECT ʧ��:ERROR
*/
int sqlistSort(Sqlist *sqlist,int mode=0) {
	if (!sqlist->slist)return ERROR;
	int i,j,temp;
	for (i = 0; i < sqlist->length-1; i++) {
		for (j = i+1; j <= sqlist->length-1; j++) {
			if (sqlist->slist[i] > sqlist->slist[j] ^ mode) {
				temp = sqlist->slist[i];
				sqlist->slist[i] = sqlist->slist[j];
				sqlist->slist[j] = temp;
			}
		}
	}
	return CORRECT;
}
/*
@����ԭ�д���������뵥��Ԫ��
@param Sqlist *sqlist
@param ElementType element ��ӵ�Ԫ��
@param int mode Ĭ��0������ 1������
@return �ɹ�:CORRECT ʧ��:ERROR
*/
int sqlistInsertBySequence(Sqlist *sqlist,ElementType element,int mode=0) {
	if (!sqlist->slist)return ERROR;
	if (sqlist->length >= sqlist->size) {
		sqlist->slist =(ElementType *) realloc(&sqlist->slist, (sqlist->size + INCREASE_SIZE) * sizeof(ElementType));
		if (!sqlist->slist)return ERROR;
		sqlist->size + INCREASE_SIZE;
	}
	int *end = &sqlist->slist[sqlist->length];
	int *start = sqlist->slist;
	while (end >= start) {
		if ((element <= *(end - 1)) ^ mode) {
			*end = *(end - 1);
		}
		else {
			*end = element;
			break;
		}
		end--;
	}
	if (end < start)*start = element;
	sqlist->length++;
	return CORRECT;
}
/*
@name ɾ����i��Ԫ�أ�������Ԫ��ֵ
@param Sqlist *sqlist
@param int i ɾ����i��Ԫ��
@param ElementType *element ����ɾ����Ԫ��
@return �ɹ�:CORRECT ʧ��:ERROR
*/
int sqlistDeleteByIndex(Sqlist *sqlist,int i,ElementType *element) {
	if (sqlist->length < i || i < 1)return ERROR;
	int *end = &sqlist->slist[sqlist->length - 1];
	int *start = &sqlist->slist[i - 1];
	*element = sqlist->slist[i - 1];
	while (start != end) {
		*start = *(start + 1);
		start++;
	}
	sqlist->length--;
	return CORRECT;
}
int main1() {
	Sqlist sqlist;
	iniSqlist(&sqlist);	
	/*--���Ա�ĳ�ʼ���Լ�����������ӷ�ʽ--*/
	/*sqlistAppendList(&sqlist, 8, 0, 3,4, 5, 6, 7, 8, 9);
	sqlistAppend(&sqlist, 10);
	sqlistPrint(sqlist);
	sqlistInsertByIndex(&sqlist,2,2);
	sqlistPrint(sqlist);
	sqlistInsertByIndex(&sqlist, 2, 1);
	sqlistPrint(sqlist);
	sqlistInsertByIndex(&sqlist, 11, 11);
	sqlistPrint(sqlist);*/

	/*--���Ա�ķ�ת--*/
	/*sqlistAppendList(&sqlist, 7, 1, 2, 3, 4, 5, 6,7);
	sqlistPrint(sqlist);
	sqlistInverse(&sqlist);
	sqlistPrint(sqlist);*/

	/*--���Ա�����--*/
	/*sqlistAppendList(&sqlist, 7, 1, 2, 3, 4, 5, 6,7);
	sqlistPrint(sqlist);
	sqlistSort(&sqlist,1);
	sqlistPrint(sqlist);*/

	/*--���Ա��������--*/
	/*sqlistAppendList(&sqlist, 6, 7, 6, 5, 4, 3, 1);
	sqlistPrint(sqlist);
	sqlistInsertBySequence(&sqlist, 3,1);
	sqlistPrint(sqlist);*/

	/*--���Ա�ɾ����i��Ԫ��--*/
	/*int element;
	sqlistAppendList(&sqlist, 6, 1, 2, 3, 4, 5, 6);
	sqlistDeleteByIndex(&sqlist,2,&element);
	sqlistPrint(sqlist);
	printf("%d", element);*/
	system("pause");
	return 0;
}