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

	//调用的话，传的是地址
	int a = 2, b = 3;
	int* paa = &a;
	int* pbb = &b;
	method(&a, &b);
	printf("a:%d b:%d\n",a,b);
	method(paa, pbb);//尽量不这样写吧，容易出错，主要是这里的paa，pbb是有值的，代表的是地址
	printf("a:%d b:%d\n", a, b);

	system("pause");
	return 0;
}