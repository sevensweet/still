#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>



void method(int* pa, int* pb)
{
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;

}

int main()
{

	//���õĻ��������ǵ�ַ
	int a = 2, b = 3;
	int* paa = &a;
	int* pbb = &b;
	method(&a, &b);
	printf("a:%d b:%d\n",a,b);
	method(paa, pbb);//����������д�ɣ����׳�����Ҫ�������paa��pbb����ֵ�ģ�������ǵ�ַ
	printf("a:%d b:%d\n", a, b);

	system("pause");
	return 0;
}