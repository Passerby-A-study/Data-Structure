#include<iostream>
#define MAXQSIZE 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

template<class Type>
class SqStack {
private:

	static const int SIZE = MAXQSIZE;
	Type* Location;
	int* Top;
	int* Base;
	int Len;

public:

	SqStack();
	~SqStack();

	Status InitStack();
	Status DestroyStack();
	Status ClearStack();
	Status StackTraverse();

	bool StackEmpty();
	int StackLength();
	const Type& GetTop();

	Status Push(Type& Obj);
	Status Pop();
};


template<class Type>
SqStack<Type>::SqStack()
{
	try
	{
		InitStack();
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}
}

template<class Type>
Status SqStack<Type>::InitStack()
{
	Location = new Type[SIZE];
	Len = 0;
	Top = Base = Location;
	if (!Location)
	{
		throw "cache diliver failure.";
	}
	return OK;
}

template<class Type>
SqStack<Type>::~SqStack()
{
	DestroyStack();
}

template<class Type>
Status SqStack<Type>::DestroyStack()
{
	delete[] Location;
	Len = 0;
	Top = Base = nullptr;
	if (!Location)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

template<class Type>
Status SqStack<Type>::ClearStack()
{
	Top = Base;
	Len = 0;
	return OK;
}

template<class Type>
Status SqStack<Type>::StackTraverse()
{
	if (StackEmpty())
	{
		std::cout << "(空栈)" << std::endl;
		return ERROR;
	}

	Type* index = Top - 1;
	for (Type* p = Top - 1; p >= Base; --p) {
		std::cout << *p << " ";
	}
	std::cout << std::endl;

	return OK;

}

template<class Type>
bool SqStack<Type>::StackEmpty()
{
	return Top == Base;
}

template<class Type>
int SqStack<Type>::StackLength()
{
	return Len;
}

template<class Type>
const Type& SqStack<Type>::GetTop()
{
	Type* index = Top - 1;
	return *index;
}

template<class Type>
Status SqStack<Type>::Push(Type& Obj)
{
	if (Len == SIZE)
	{
		return ERROR;
	}

	*Top = Obj;
	Top++;
	Len++;

	return OK;
}

template<class Type>
Status SqStack<Type>::Pop()
{
	if (StackEmpty())
	{
		return ERROR;
	}

	Top--;
	Len--;
	return OK;
}



int main()
{
	SqStack<int> IntStack;
	int choice;
	int value;

	do {
		std::cout << "\nint栈操作菜单：" << std::endl;
		std::cout << "1. 入栈" << std::endl;
		std::cout << "2. 出栈" << std::endl;
		std::cout << "3. 遍历栈" << std::endl;
		std::cout << "4. 清空栈" << std::endl;
		std::cout << "5. 获取栈长度" << std::endl;
		std::cout << "6. 获取栈顶元素" << std::endl;
		std::cout << "0. 退出" << std::endl;
		std::cout << "请输入你的选择: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			std::cout << "请输入要入栈的元素: ";
			std::cin >> value;
			if (IntStack.Push(value) == OK) {
				std::cout << "入栈成功！" << std::endl;
			}
			else {
				std::cout << "栈已满，入栈失败！" << std::endl;
			}
			break;
		case 2:
			if (IntStack.Pop() == OK) {
				std::cout << "出栈成功！" << std::endl;
			}
			else {
				std::cout << "栈为空，出栈失败！" << std::endl;
			}
			break;
		case 3:
			if (IntStack.StackLength() == 0)
			{
				std::cout << "栈无元素！" << std::endl;
				break;
			}
			else
			{
				std::cout << "栈元素为: ";
				IntStack.StackTraverse();
				break;
			}
		case 4:
			if (IntStack.ClearStack() == OK) {
				std::cout << "栈清空成功！" << std::endl;
			}
			else {
				std::cout << "栈清空失败！" << std::endl;
			}
			break;
		case 5:
			std::cout << "栈长度为: " << IntStack.StackLength() << std::endl;
			break;
		case 6:
			if (!IntStack.StackEmpty()) {
				std::cout << "栈首元素为: " << IntStack.GetTop() << std::endl;
			}
			else {
				std::cout << "栈为空，没有栈顶元素！" << std::endl;
			}
			break;
		case 0:
			std::cout << "退出程序。" << std::endl;
			break;
		default:
			std::cout << "无效的选择，请重新输入！" << std::endl;
		}
	} while (choice != 0);

	return 0;
}