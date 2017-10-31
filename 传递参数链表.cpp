#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;
void InitLinkListError(LNode* L2)//这里的形参的LNode指针变量又是另外一个地址，不予实参变量的地址相同，
{
	L2 = (LNode* )malloc(sizeof(LNode));
	L2->data = 0;
	L2->next = NULL;
}
//因此要真正能创建链表头，则如下修改
//1.可以把指针作为返回值,没有参数
LNode* InitLinkListOk_One()
{
	LNode* lp = (LNode*)malloc(sizeof(LNode));
	lp->data = 0;
	lp->next = NULL;
	return lp;
}
//2.同样是把指针作为返回值,有参数
LNode* InitLinkListOk_Two(LNode* pTmp)
{
	pTmp = (LNode*)malloc(sizeof(LNode));
	pTmp->data = 0;
	pTmp->next = NULL;
	return pTmp;
}
//3.返回值为void类型，二级指针作为参数传出,ps:一级指针变量代表对象的地址，二级指针变量代表一级指针的地址
void InitLinkListOk_Three(LNode** pp)
{
	//*pp 代表的是一级指针变量的值
	*pp = (LNode*)malloc(sizeof(LNode));
	(*pp)->data = 1;
	(*pp)->next = NULL;
}


int main4()
{
	LNode* L = NULL;
	InitLinkListError(L);//原本实参的LNode指针变量是一个地址,返回的结果任然是NULL
	printf("%p\n", L);//00000000

	LNode* L2 = NULL;
	L2 = InitLinkListOk_One();
	printf("%p\n", L2);//006C7530
	//会有地址分配，并且这里是特殊在lp使用malloc动态开辟的内存，如果是局部变量，再次使用堆栈或L2->data 是不能得到正确值的。

	LNode* L3 = NULL;
	L3 = InitLinkListOk_Two(L3);
	printf("%p\n", L3);//006C7578

	LNode* L4 = NULL;
	InitLinkListOk_Three(&L4);
	printf("%p\n", L4);//006C75C0
	printf("%d\n", L4->data);//1
	
	/* 联系到  swap(int* a,int* b） swap(aa,bb）*/


	system("pause");
	return 0;
}