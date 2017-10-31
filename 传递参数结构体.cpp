#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct Student
{
	int id;
	char name[10];
}Stu;// 这样写用了typedef ，如果没有用就比较麻烦


Stu* InitialStructOne()
{
	Stu* p = (Stu*)malloc(sizeof(Stu));
	p->id = 123;
	strcpy_s(p->name, "szr");
	return p;
}

void InitialStructTwo(Stu** pp)
{
	(*pp) = (Stu*)malloc(sizeof(Stu));
	(*pp)->id = 234;
	strcpy_s((*pp)->name, "lxt");
}

void InitialStructError(Stu** ppp)
{
	Stu* pt = (Stu*)malloc(sizeof(Stu));
	pt->id = 111;
	strcpy_s(pt->name, "error");
	*ppp = pt;//这样写是没有问题的
	//ppp = &pt;//这样写 最后那边是00000000  理解就有错误！！！！！！！！！！！！！
}

// 目的是初始化结构体，能得到结构体并输出
int main3()
{
	//如果还用结构体变量作为形参的话，因为是拷贝，会占用非常大的地址空间，因此选择用指向结构体的指针
	Stu* p1 = NULL;
	p1 = InitialStructOne();
	printf("%p\n", p1);//004474E8


	Stu* p2 = NULL;
	InitialStructTwo(&p2);//swap联系起来
	printf("%p\n", p2);//00447538


	Stu* p3 = NULL;
	InitialStructError(&p3);//细节里面看
	printf("%p\n", p3);
	printf("%d\n", p3->id);

	system("pause");
	return 0;
}