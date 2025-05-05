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
		std::cout << "(��ջ)" << std::endl;
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
		std::cout << "\nintջ�����˵���" << std::endl;
		std::cout << "1. ��ջ" << std::endl;
		std::cout << "2. ��ջ" << std::endl;
		std::cout << "3. ����ջ" << std::endl;
		std::cout << "4. ���ջ" << std::endl;
		std::cout << "5. ��ȡջ����" << std::endl;
		std::cout << "6. ��ȡջ��Ԫ��" << std::endl;
		std::cout << "0. �˳�" << std::endl;
		std::cout << "���������ѡ��: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			std::cout << "������Ҫ��ջ��Ԫ��: ";
			std::cin >> value;
			if (IntStack.Push(value) == OK) {
				std::cout << "��ջ�ɹ���" << std::endl;
			}
			else {
				std::cout << "ջ��������ջʧ�ܣ�" << std::endl;
			}
			break;
		case 2:
			if (IntStack.Pop() == OK) {
				std::cout << "��ջ�ɹ���" << std::endl;
			}
			else {
				std::cout << "ջΪ�գ���ջʧ�ܣ�" << std::endl;
			}
			break;
		case 3:
			if (IntStack.StackLength() == 0)
			{
				std::cout << "ջ��Ԫ�أ�" << std::endl;
				break;
			}
			else
			{
				std::cout << "ջԪ��Ϊ: ";
				IntStack.StackTraverse();
				break;
			}
		case 4:
			if (IntStack.ClearStack() == OK) {
				std::cout << "ջ��ճɹ���" << std::endl;
			}
			else {
				std::cout << "ջ���ʧ�ܣ�" << std::endl;
			}
			break;
		case 5:
			std::cout << "ջ����Ϊ: " << IntStack.StackLength() << std::endl;
			break;
		case 6:
			if (!IntStack.StackEmpty()) {
				std::cout << "ջ��Ԫ��Ϊ: " << IntStack.GetTop() << std::endl;
			}
			else {
				std::cout << "ջΪ�գ�û��ջ��Ԫ�أ�" << std::endl;
			}
			break;
		case 0:
			std::cout << "�˳�����" << std::endl;
			break;
		default:
			std::cout << "��Ч��ѡ�����������룡" << std::endl;
		}
	} while (choice != 0);

	return 0;
}