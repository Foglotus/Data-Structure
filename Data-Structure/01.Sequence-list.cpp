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
@return 1：初始化成功 0：初始化失败
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
@name 线性顺序表多个赋值
@ElementType method
@param Sqlist *sqlist
@param int count（添加值的个数)
@param ...(int) 可输入多个值，逗号隔开
@return 1:添加成功 0：添加失败
*/
int sqlist_append_list(Sqlist *sqlist, int count, ...) {
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
@return 1:添加成功 0：添加失败
*/
int sqlist_append(Sqlist *sqlist, int ele) {
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
void print_sqlist(Sqlist sqlist, int type = 0) {
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
@param Sqlist sqlist
@param int i 插入的位置
@param ele 元素
*/
int insert_sq_by_index(Sqlist *sqlist,int i,int ele){
	//判断插入是否合法
	//1.线性表是否未初始化，插入位置是否错误
	if (sqlist->slist == NULL || i < 1 || i > sqlist->length) {
		return ERROR;
	}
	if (sqlist->size <= sqlist->length) {
		sqlist->slist = (ElementType *)realloc(sqlist->slist, sizeof(ElementType)*(sqlist->size + INCREASE_SIZE));
		sqlist->size += INCREASE_SIZE;
	}
	for (int start = sqlist->length-1; start>=i-1; start--) {
		sqlist->slist[start + 1] = sqlist->slist[start];
	}
	sqlist->slist[i - 1] = ele;
	sqlist->length++;
	return CORRECT;
}
int main() {
	Sqlist sqlist;
	ini_sqlist(&sqlist);	
	sqlist_append_list(&sqlist, 8, 0, 3,4, 5, 6, 7, 8, 9);
	sqlist_append(&sqlist, 10);
	print_sqlist(sqlist);
	insert_sq_by_index(&sqlist,2,2);
	print_sqlist(sqlist);
	insert_sq_by_index(&sqlist, 2, 1);
	print_sqlist(sqlist);
	insert_sq_by_index(&sqlist, 11, 11);
	print_sqlist(sqlist);
	system("pause");
	return 0;
}