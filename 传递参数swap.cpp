#include <stdlib.h>
#include <stdio.h>

void swap(int ta, int tb)
{
	printf("swap_ta_address:%p  swap_tb_address:%p\n", &ta, &tb);//��main_a,main_b ������ͬ�ĵ�ַ�ռ�
	int tmp;
	tmp = ta;
	ta = tb;
	tb = tmp;
}

void swap2(int* pa, int* pb)
{
	printf("swap2_pa_address:%p swap2_pb_address:%p\n", &pa, &pb);
	// int* pa = &a,int* pb = &b ʵ���ϻ���ԭ�������Ŀ���������
	printf("swap2_pa_value:%p swap2_pb_value:%p\n", pa, pb);//��main_a,main_b ����ͬ�ĵ�ַ�ռ�
	/*
	int* pTmp = NULL;
	pTmp = pa;
	pa = pb;
	pb = pTmp;
	���������ֻ�Ǿֲ�������ָ�����ı䣬��ʵ�εĵ�ַ�ռ��е�ֵ��Ȼ��û���κθı�ģ����Ҫ��ı�ʵ�Σ�ȥ�ı��ַ�ռ��е�ֵ
	��ַ�Ƿ���õģ�զ���������ȥ�Ե�ַ�ռ��е�ֵ�ı䡣
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
	swap(a , b);//��ַ�ռ䲻һ�����βεĸı䲻�ܸı�ʵ��--------------���ˮ�ȣ��Ұ�ˮ��
	printf("main_a_value:%d main_b_value:%d\n", a, b);
	printf("\n----------------------------\n");

	swap2(&a, &b);//��ַ�ռ�һ��-------------������黻λ��
	printf("main_a_value:%d main_b_value:%d\n", a, b);



	system("pause");
}