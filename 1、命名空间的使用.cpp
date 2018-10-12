#include <stdio.h>



// 1、命名空间的定义
// 定义一个名字为 Name1 的命名空间
// 和全局空间一样使用：定义变量、宏、函数、结构体....
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



// 2、命名空间的使用
// 2.1 通过 命名空间的名字::要使用的内容 ::===> 域解析符
int main1()
{
	Name1::a = 10;   // 使用命名空间 Name1 中的 a
	
	printf ("name1 a = %d\n", Name1::a);
	
	printf ("2 + 3 = %d\n", Name1::add(2, 3));
	return 0;
}

// 2.2 通过 using 关键字打开命名空间
int main2()
{
	//打开命名空间Name1,之后如果使用Name1中的内容 可以不用加域解析符，直接使用
	using namespace Name1;  
	
	a = 20;
	printf ("name1 a = %d\n", a);
	printf ("2 + 3 = %d\n", add(2, 3));
	
	return 0;
}

// 2.3 通过 using 使用单个成员
int main3()
{
	using Name1::add;  // 之后使用add 可以不用加域解析符
	printf ("2 + 3 = %d\n", add(2, 3));
	
	// a 不可以直接使用
	// a = 10;
	
	return 0;
}

// 2.4 命名空间内容冲突
int main4()
{
	using namespace Name1;
	using namespace Name2;
	
	printf ("2 + 3 = %d\n", add(2, 3));
	printf ("2 + 3 = %d\n", sub(2, 3));
	
	// 两个空间都有 a 不能直接使用
	// a  = 20;
	Name1::a = 10;
	Name2::a = 20;
	
	return 0;
}

int a;   // 全局的 a

// 2.5 默认命名空间
int main()
{
	using namespace Name1;
	Name1::a = 10;

	// 使用默认命名空间的成员  ::成员
	::a = 20;
	
	// 命名空间的嵌套
	Name2::Name3::c = 1;
	
	return 0;
}












