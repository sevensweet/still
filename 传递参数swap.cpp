#include <stdlib.h>
#include <stdio.h>

void swap(int ta, int tb)
{
	printf("swap_ta_address:%p  swap_tb_address:%p\n", &ta, &tb);//和main_a,main_b 不是相同的地址空间
	int tmp;
	tmp = ta;
	ta = tb;
	tb = tmp;
}

void swap2(int* pa, int* pb)
{
	printf("swap2_pa_address:%p swap2_pb_address:%p\n", &pa, &pb);
	// int* pa = &a,int* pb = &b 实质上还是原来参数的拷贝！！！
	printf("swap2_pa_value:%p swap2_pb_value:%p\n", pa, pb);//和main_a,main_b 是相同的地址空间
	/*
	int* pTmp = NULL;
	pTmp = pa;
	pa = pb;
	pb = pTmp;
	这种情况，只是局部变量的指向发生改变，而实参的地址空间中的值任然是没有任何改变的，因此要想改变实参，去改变地址空间中的值
	地址是分配好的，咋个改嘛，所以去对地址空间中的值改变。
	*/
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;

}

void main2()
{
	int a = 2, b = 3;
	printf("main_a_address:%p  main_b_address:%p\n", &a, &b);
	printf("----------------------------\n");
	printf("main_a_value:%d main_b_value:%d\n", a, b);
	swap(a , b);//地址空间不一样，形参的改变不能改变实参--------------你包水饺，我包水饺
	printf("main_a_value:%d main_b_value:%d\n", a, b);
	printf("\n----------------------------\n");

	swap2(&a, &b);//地址空间一样-------------书架上书换位置
	printf("main_a_value:%d main_b_value:%d\n", a, b);



	system("pause");
}