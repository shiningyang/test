#include <stdio.h>



// 1�������ռ�Ķ���
// ����һ������Ϊ Name1 �������ռ�
// ��ȫ�ֿռ�һ��ʹ�ã�����������ꡢ�������ṹ��....
namespace Name1
{
	int a;
	
	int add(int a, int b)
	{
		return a + b;
	}
}

namespace Name2
{
	int a;
	
	int sub(int a, int b)
	{
		return a - b;
	}
	
	
	namespace Name3
	{
		int c;
	}
}



// 2�������ռ��ʹ��
// 2.1 ͨ�� �����ռ������::Ҫʹ�õ����� ::===> �������
int main1()
{
	Name1::a = 10;   // ʹ�������ռ� Name1 �е� a
	
	printf ("name1 a = %d\n", Name1::a);
	
	printf ("2 + 3 = %d\n", Name1::add(2, 3));
	return 0;
}

// 2.2 ͨ�� using �ؼ��ִ������ռ�
int main2()
{
	//�������ռ�Name1,֮�����ʹ��Name1�е����� ���Բ��ü����������ֱ��ʹ��
	using namespace Name1;  
	
	a = 20;
	printf ("name1 a = %d\n", a);
	printf ("2 + 3 = %d\n", add(2, 3));
	
	return 0;
}

// 2.3 ͨ�� using ʹ�õ�����Ա
int main3()
{
	using Name1::add;  // ֮��ʹ��add ���Բ��ü��������
	printf ("2 + 3 = %d\n", add(2, 3));
	
	// a ������ֱ��ʹ��
	// a = 10;
	
	return 0;
}

// 2.4 �����ռ����ݳ�ͻ
int main4()
{
	using namespace Name1;
	using namespace Name2;
	
	printf ("2 + 3 = %d\n", add(2, 3));
	printf ("2 + 3 = %d\n", sub(2, 3));
	
	// �����ռ䶼�� a ����ֱ��ʹ��
	// a  = 20;
	Name1::a = 10;
	Name2::a = 20;
	
	return 0;
}

int a;   // ȫ�ֵ� a

// 2.5 Ĭ�������ռ�
int main()
{
	using namespace Name1;
	Name1::a = 10;

	// ʹ��Ĭ�������ռ�ĳ�Ա  ::��Ա
	::a = 20;
	
	// �����ռ��Ƕ��
	Name2::Name3::c = 1;
	
	return 0;
}












