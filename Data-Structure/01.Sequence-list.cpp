#include<iostream>
#include<stdarg.h>
#include<math.h>
using namespace std;
/*
线性顺序表初始化大小
顺序表增量
定义错误代码
*/
#define INI_SIZE 10
#define INCREASE_SIZE 5
#define ERROR 0
#define CORRECT 1
typedef int ElementType;
/*
@name 线性顺序表组成
@ElementType  struct
@param slist  指针  指向数组。
@param length int  记录数组已经使用的长度
@param size   int  记录数组当前大小
*/
struct Sqlist
{
	int *slist = NULL;
	int length;
	int size;
};
/*
@name 初始化线性顺序表
@ElementType method
@param Sqlist *sqlist 顺序表变量
@return 初始化成功: CORRECT 初始化失败:ERROR
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
@name 线性顺序表多个赋值
@ElementType method
@param Sqlist *sqlist
@param int count（添加值的个数)
@param ...(int) 可输入多个值，逗号隔开
@return 添加成功: CORRECT 添加失败:ERROR
*/
int sqlistAppendList(Sqlist *sqlist, int count, ...) {
	if (sqlist->slist == NULL) {
		return ERROR;
	}
	//1.空间是否不足
	if ((sqlist->length + count) > sqlist->size) {
		//1.2.不足计算需要多少INCREASE_SIZE
		int sum = ceil((sqlist->length + count - sqlist->size) / (double)INCREASE_SIZE)*INCREASE_SIZE;
		sqlist->slist = (ElementType *)realloc(sqlist->slist, sizeof(ElementType)*(sqlist->size + sum));
		sqlist->size += sum;
		if (sqlist->slist == NULL) {
			return ERROR;
		}
	}
	//2.调用可变参数宏
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++) {
		sqlist->slist[sqlist->length++] = va_arg(args, int);
	}
	va_end(args);
	return CORRECT;
}
/*
@name 线性顺序表单个赋值
@ElementType method
@param Sqlist *sqlist
@param int ele 添加的值
@return 添加成功: CORRECT 添加失败:ERROR
*/
int sqlistAppend(Sqlist *sqlist, int ele) {
	if (sqlist->slist == NULL) {
		return ERROR;
	}
	//1.判断空间是否足够
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
@name 线性顺序表打印
@ElementType method
@param Sqlist sqlist
@param int type 输出模式：0输出已经初始化的，1全部输出，默认0
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
@name 在i位置之前插入值
@ElementType method
@param Sqlist *sqlist
@param int i 插入的位置
@param ele 元素
@return 成功：CORRECT 失败：ERROR
*/
int sqlistInsertByIndex(Sqlist *sqlist,int i,int ele){
	//判断插入是否合法
	//1.线性表是否未初始化，插入位置是否错误
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
@name 反转线性表
@param Sqlist *sqlist
@return 成功:CORRECT 失败:ERROR
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
@name 线性表排序
@param Sqlist *sqlist
@param int mode 0默认升序排列，1降序排列
@return 成功:CORRECT 失败:ERROR
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
@保持原有次序有序插入单个元素
@param Sqlist *sqlist
@param ElementType element 添加的元素
@param int mode 默认0：增序 1：降序
@return 成功:CORRECT 失败:ERROR
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
@name 删除第i个元素，并返回元素值
@param Sqlist *sqlist
@param int i 删除第i个元素
@param ElementType *element 接收删除后元素
@return 成功:CORRECT 失败:ERROR
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
	/*--线性表的初始化以及三种两种添加方式--*/
	/*sqlistAppendList(&sqlist, 8, 0, 3,4, 5, 6, 7, 8, 9);
	sqlistAppend(&sqlist, 10);
	sqlistPrint(sqlist);
	sqlistInsertByIndex(&sqlist,2,2);
	sqlistPrint(sqlist);
	sqlistInsertByIndex(&sqlist, 2, 1);
	sqlistPrint(sqlist);
	sqlistInsertByIndex(&sqlist, 11, 11);
	sqlistPrint(sqlist);*/

	/*--线性表的反转--*/
	/*sqlistAppendList(&sqlist, 7, 1, 2, 3, 4, 5, 6,7);
	sqlistPrint(sqlist);
	sqlistInverse(&sqlist);
	sqlistPrint(sqlist);*/

	/*--线性表排序--*/
	/*sqlistAppendList(&sqlist, 7, 1, 2, 3, 4, 5, 6,7);
	sqlistPrint(sqlist);
	sqlistSort(&sqlist,1);
	sqlistPrint(sqlist);*/

	/*--线性表有序插入--*/
	/*sqlistAppendList(&sqlist, 6, 7, 6, 5, 4, 3, 1);
	sqlistPrint(sqlist);
	sqlistInsertBySequence(&sqlist, 3,1);
	sqlistPrint(sqlist);*/

	/*--线性表删除第i个元素--*/
	/*int element;
	sqlistAppendList(&sqlist, 6, 1, 2, 3, 4, 5, 6);
	sqlistDeleteByIndex(&sqlist,2,&element);
	sqlistPrint(sqlist);
	printf("%d", element);*/
	system("pause");
	return 0;
}