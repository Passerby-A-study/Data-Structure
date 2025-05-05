#include<iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

template<class Type>
class LinkQueue {
private:

	struct LQNode
	{
		Type Data;
		LQNode* Next;
	};

	LQNode* Front;
	LQNode* Rear;
	int Len;

public:

	LinkQueue();
	~LinkQueue();

	Status InitQueue();
	Status DestroyQueue();
	Status ClearQueue();
	Status QueueTraverse();

	bool QueueEmpty();
	int QueueLength();
	const Type& GetHead();

	Status EnQueue(Type& Obj);
	Status DeQueue();
};


template<class Type>
LinkQueue<Type>::LinkQueue()
{
	try
	{
		InitQueue();
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}
}

template<class Type>
Status LinkQueue<Type>::InitQueue()
{
	LQNode* Head = new LQNode;
	Head->Next = nullptr;
	Len = 0;
	Front = Rear = Head;

	if (!Head)
	{
		throw "cache diliver failure.";
	}
	return OK;
}

template<class Type>
LinkQueue<Type>::~LinkQueue()
{
	DestroyQueue();
}

template<class Type>
Status LinkQueue<Type>::DestroyQueue()
{
	LQNode* pos = Front->Next;
	Front->Next = nullptr;
	while (pos != nullptr)
	{
		LQNode* used = pos;
		pos = pos->Next;
		delete used;
	}
	Len = 0;
	Rear = Front;

	if (!Front->Next)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

template<class Type>
Status LinkQueue<Type>::ClearQueue()
{
	if (DestroyQueue())
	{
		return OK;
	}
	else
	{
		return ERROR;
	}

}

template<class Type>
Status LinkQueue<Type>::QueueTraverse()
{
	if (QueueEmpty())
	{
		std::cout << std::endl;
		return ERROR;
	}

	LQNode* pos = Front->Next;
	while (pos != nullptr)
	{
		std::cout << pos->Data << " ";
		pos = pos->Next;
	}
	std::cout << std::endl;
	return OK;

}

template<class Type>
bool LinkQueue<Type>::QueueEmpty()
{
	return Front == Rear;
}

template<class Type>
int LinkQueue<Type>::QueueLength()
{
	return Len;
}

template<class Type>
const Type& LinkQueue<Type>::GetHead()
{
	return Front->Next->Data;
}

template<class Type>
Status LinkQueue<Type>::EnQueue(Type& Obj)
{
	LQNode* target = new LQNode;
	target->Data = Obj;
	target->Next = nullptr;
	Rear->Next = target;
	Rear = Rear->Next;
	Len++;
	return OK;
}

template<class Type>
Status LinkQueue<Type>::DeQueue()
{
	if (QueueEmpty())
	{
		return ERROR;
	}

	LQNode* pos = Front->Next;
	Front->Next = Front->Next->Next;
	if (pos->Next == Rear)
	{
		Rear = Front->Next;
	}
	delete pos;
	Len--;
	return OK;
}



int main()
{
	LinkQueue<int> IntQueue;
	int choice;
	int value;

	do {
		std::cout << "\nint���в����˵���" << std::endl;
		std::cout << "1. ���" << std::endl;
		std::cout << "2. ����" << std::endl;
		std::cout << "3. ��������" << std::endl;
		std::cout << "4. ��ն���" << std::endl;
		std::cout << "5. ��ȡ���г���" << std::endl;
		std::cout << "6. ��ȡ����Ԫ��" << std::endl;
		std::cout << "0. �˳�" << std::endl;
		std::cout << "���������ѡ��: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			std::cout << "������Ҫ��ӵ�Ԫ��: ";
			std::cin >> value;
			if (IntQueue.EnQueue(value) == OK) {
				std::cout << "��ӳɹ���" << std::endl;
			}
			else {
				std::cout << "�������������ʧ�ܣ�" << std::endl;
			}
			break;
		case 2:
			if (IntQueue.DeQueue() == OK) {
				std::cout << "���ӳɹ���" << std::endl;
			}
			else {
				std::cout << "����Ϊ�գ�����ʧ�ܣ�" << std::endl;
			}
			break;
		case 3:
			if (IntQueue.QueueLength() == 0)
			{
				std::cout << "������Ԫ�أ�" << std::endl;
				break;
			}
			else
			{
				std::cout << "����Ԫ��Ϊ: ";
				IntQueue.QueueTraverse();
				break;
			}
		case 4:
			if (IntQueue.ClearQueue() == OK) {
				std::cout << "������ճɹ���" << std::endl;
			}
			else {
				std::cout << "�������ʧ�ܣ�" << std::endl;
			}
			break;
		case 5:
			std::cout << "���г���Ϊ: " << IntQueue.QueueLength() << std::endl;
			break;
		case 6:
			if (!IntQueue.QueueEmpty()) {
				std::cout << "����Ԫ��Ϊ: " << IntQueue.GetHead() << std::endl;
			}
			else {
				std::cout << "����Ϊ�գ�û�ж���Ԫ�أ�" << std::endl;
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