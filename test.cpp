#include <iostream>
using namespace std;



struct Stu
{
	char a;
	int id;
};
//������ʽ--2
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
	//��ͬ���͵Ķ���
	int a1=2,a2=3;
	std::cout<<sizeof(a1)<<"---"<<sizeof(a2)<<std::endl;

	//ָ��
	int a3=6;
	int* p1 =&a3;
	float a4 = 6.0;
	float* p2 = &a4;
	double a5 = 234.21;
	double* p3 =&a5;
	std::cout<<sizeof(p1)<<"--"<<sizeof(p1)<<"--"<<sizeof(p3)<<std::endl;

	//������ʽ--1
	int data[]={1,2,3};//ret=12
	int data2[6];//ret=24  ����ֻ�������˾ͻ�ռ���ڴ��ַ�ռ䣿������
	std::cout<<sizeof(data)<<"--"<<sizeof(data2)<<endl;
	//������ʽ--2
	char data3[] = {'a','b','c'};
	char data4[] = {'a','b','c','d'};
	foo3(data3);//!!!!!!!! ret=4
	foo4(data4);//!!!!!!!!! ret=4
	//��ʵ��ϸ����������ף���Ϊ�Ǻ������ã�����ȥ����ʵ�ǵ�ַ

	//�ṹ��
	std::cout<<"struct:"<<sizeof(Stu); // ���Ǽ򵥵�����������������ռ���ֽ���
	//���ڴӸ�����ʼ���������ڴ�������ʲô

	/*
	struct Stu student1;
	student1 = (struct Stu){'a',2};//��������
	*/

	struct Stu student1;
	struct Stu* p  = &student1;
	student1.a = 'a';
	student1.id = 666;
	//0x003AFAA4  61 cc cc cc 9a 02 00 00   û��ָ����Ĭ������Ȼ����
	
	char str[] = "szr"; // 0x003BFC54  73 7a 72 00 (�ַ�����ֵ��ʱ����Զ����0)
	std::cout<<sizeof(str)<<endl;
	//sizeof�������飬�������������ֽڴ�С�������������ʶ����ָ���С��

	//λ�� 
	struct WY
	{
		unsigned int a:4;
		unsigned int :0;  //����λ���������͵���λ�õģ�������ô����ૣ���
		char c:4;
		unsigned int d:4;
	}positionArea,*pArea;
	pArea = &positionArea;
	//�ṹ������Ķ��壬ָ��ṹ���ָ��  a����ֱ��struct name{}vary,*p;
	positionArea.a  = 12;
	positionArea.c = '1';
	positionArea.d  = 11;
	// �ڴ��еĽ��  0x0046FA90  cc cc cc cc c1 cc cc cc cb  Ϊʲô��������������Ҳ�����




	char str2[4] = "abc";  //��ô����������sizeof�Ե�ǰ������ģ�������ȡ��С

	// �������ַ�������ʽ��ֵ��ʱ��
	char str3[3] = {'a','b','c'};

}