#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;
void InitLinkListError(LNode* L2)//������βε�LNodeָ�������������һ����ַ������ʵ�α����ĵ�ַ��ͬ��
{
	L2 = (LNode* )malloc(sizeof(LNode));
	L2->data = 0;
	L2->next = NULL;
}
//���Ҫ�����ܴ�������ͷ���������޸�
//1.���԰�ָ����Ϊ����ֵ,û�в���
LNode* InitLinkListOk_One()
{
	LNode* lp = (LNode*)malloc(sizeof(LNode));
	lp->data = 0;
	lp->next = NULL;
	return lp;
}
//2.ͬ���ǰ�ָ����Ϊ����ֵ,�в���
LNode* InitLinkListOk_Two(LNode* pTmp)
{
	pTmp = (LNode*)malloc(sizeof(LNode));
	pTmp->data = 0;
	pTmp->next = NULL;
	return pTmp;
}
//3.����ֵΪvoid���ͣ�����ָ����Ϊ��������,ps:һ��ָ������������ĵ�ַ������ָ���������һ��ָ��ĵ�ַ
void InitLinkListOk_Three(LNode** pp)
{
	//*pp �������һ��ָ�������ֵ
	*pp = (LNode*)malloc(sizeof(LNode));
	(*pp)->data = 1;
	(*pp)->next = NULL;
}


int main4()
{
	LNode* L = NULL;
	InitLinkListError(L);//ԭ��ʵ�ε�LNodeָ�������һ����ַ,���صĽ����Ȼ��NULL
	printf("%p\n", L);//00000000

	LNode* L2 = NULL;
	L2 = InitLinkListOk_One();
	printf("%p\n", L2);//006C7530
	//���е�ַ���䣬����������������lpʹ��malloc��̬���ٵ��ڴ棬����Ǿֲ��������ٴ�ʹ�ö�ջ��L2->data �ǲ��ܵõ���ȷֵ�ġ�

	LNode* L3 = NULL;
	L3 = InitLinkListOk_Two(L3);
	printf("%p\n", L3);//006C7578

	LNode* L4 = NULL;
	InitLinkListOk_Three(&L4);
	printf("%p\n", L4);//006C75C0
	printf("%d\n", L4->data);//1
	
	/* ��ϵ��  swap(int* a,int* b�� swap(aa,bb��*/


	system("pause");
	return 0;
}