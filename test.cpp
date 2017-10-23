#include <iostream>
using namespace std;



struct Stu
{
	char a;
	int id;
};
//数组形式--2
void foo3(char a3[3])
{
	int c3 = sizeof( a3 ); // c3 == 
	std::cout<<c3<<endl;
}
void foo4(char a4[])
{
	int c4 = sizeof( a4 ); // c4 == 
	std::cout<<c4<<endl;
}


void main()
{
	//不同类型的对象
	int a1=2,a2=3;
	std::cout<<sizeof(a1)<<"---"<<sizeof(a2)<<std::endl;

	//指针
	int a3=6;
	int* p1 =&a3;
	float a4 = 6.0;
	float* p2 = &a4;
	double a5 = 234.21;
	double* p3 =&a5;
	std::cout<<sizeof(p1)<<"--"<<sizeof(p1)<<"--"<<sizeof(p3)<<std::endl;

	//数组形式--1
	int data[]={1,2,3};//ret=12
	int data2[6];//ret=24  数组只有声明了就会占用内存地址空间？？？？
	std::cout<<sizeof(data)<<"--"<<sizeof(data2)<<endl;
	//数组形式--2
	char data3[] = {'a','b','c'};
	char data4[] = {'a','b','c','d'};
	foo3(data3);//!!!!!!!! ret=4
	foo4(data4);//!!!!!!!!! ret=4
	//其实仔细想想就能明白，因为是函数调用，传过去的其实是地址

	//结构体
	std::cout<<"struct:"<<sizeof(Stu); // 不是简单的像数组那样就是所占的字节数
	//现在从给他初始化来看看内存里面是什么

	/*
	struct Stu student1;
	student1 = (struct Stu){'a',2};//这样不行
	*/

	struct Stu student1;
	struct Stu* p  = &student1;
	student1.a = 'a';
	student1.id = 666;
	//0x003AFAA4  61 cc cc cc 9a 02 00 00   没有指明，默认是自然对齐
	
	char str[] = "szr"; // 0x003BFC54  73 7a 72 00 (字符串赋值的时候会自动添加0)
	std::cout<<sizeof(str)<<endl;
	//sizeof用于数组，计算的是数组的字节大小，而不是数组标识符的指针大小。

	//位域 
	struct WY
	{
		unsigned int a:4;
		unsigned int :0;  //无名位域。用来填充和调整位置的，至于怎么调整喃？？
		char c:4;
		unsigned int d:4;
	}positionArea,*pArea;
	pArea = &positionArea;
	//结构体变量的定义，指向结构体的指针  a：就直接struct name{}vary,*p;
	positionArea.a  = 12;
	positionArea.c = '1';
	positionArea.d  = 11;
	// 内存中的结果  0x0046FA90  cc cc cc cc c1 cc cc cc cb  为什么是这样？？？？也不清楚




	char str2[4] = "abc";  //那么接下来就用sizeof对当前的数组的？？？？取大小

	// 当是以字符串的形式赋值的时候
	char str3[3] = {'a','b','c'};

}