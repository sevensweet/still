#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct Student
{
	int id;
	char name[10];
}Stu;// ����д����typedef �����û���þͱȽ��鷳


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
	*ppp = pt;//����д��û�������
	//ppp = &pt;//����д ����Ǳ���00000000  �����д��󣡣�����������������������
}

// Ŀ���ǳ�ʼ���ṹ�壬�ܵõ��ṹ�岢���
int main3()
{
	//������ýṹ�������Ϊ�βεĻ�����Ϊ�ǿ�������ռ�÷ǳ���ĵ�ַ�ռ䣬���ѡ����ָ��ṹ���ָ��
	Stu* p1 = NULL;
	p1 = InitialStructOne();
	printf("%p\n", p1);//004474E8


	Stu* p2 = NULL;
	InitialStructTwo(&p2);//swap��ϵ����
	printf("%p\n", p2);//00447538


	Stu* p3 = NULL;
	InitialStructError(&p3);//ϸ�����濴
	printf("%p\n", p3);
	printf("%d\n", p3->id);

	system("pause");
	return 0;
}