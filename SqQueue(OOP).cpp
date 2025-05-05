#include<iostream>
#define MAXQSIZE 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

template<class Type>
class SqQueue {
private:

 	static const int SIZE = MAXQSIZE;
	Type* Location;
	int Front;
	int Rear;
	int Len;

public:

	SqQueue();
	~SqQueue();

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
SqQueue<Type>::SqQueue()
{
	try
	{
		InitQueue();
	}
	catch (const char *s)
	{
		std::cout << s << std::endl;
	}
}

template<class Type>
Status SqQueue<Type>::InitQueue()
{
	Location = new Type[SIZE];
	Len = Front = Rear = 0;
	if (!Location)
	{
		throw "cache diliver failure.";
	}
	return OK;
}

template<class Type>
SqQueue<Type>::~SqQueue()
{
	DestroyQueue();
}

template<class Type>
Status SqQueue<Type>::DestroyQueue() {
	delete[] Location;
	Location = nullptr;
	Len = Front = Rear = 0;
	return OK;
}


template<class Type>
Status SqQueue<Type>::ClearQueue() {
	Front = Rear = Len = 0;
	return OK;
}


template<class Type>
Status SqQueue<Type>::QueueTraverse()
{
	if (QueueEmpty())
	{
		std::cout << std::endl;
		return ERROR;
	}

	int index = Front;
	for (int i = 0; i < Len; i++)
	{
		std::cout << Location[index] << " ";
		index = (index + 1) % SIZE;
	}
	std::cout << std::endl;

	return OK;

}

template<class Type>
bool SqQueue<Type>::QueueEmpty()
{
	return Front == Rear;
}

template<class Type>
int SqQueue<Type>::QueueLength()
{
	return Len;
}

template<class Type>
const Type& SqQueue<Type>::GetHead()
{
	return Location[Front];
}

template<class Type>
Status SqQueue<Type>::EnQueue(Type& Obj)
{
	if (Len == SIZE)
	{
		return ERROR;
	}

	Location[Rear] = Obj;
	Rear = (Rear + 1) % SIZE;
	Len++;

	return OK;
}

template<class Type>
Status SqQueue<Type>::DeQueue()
{
	if (QueueEmpty())
	{
		return ERROR;
	}

	Front = (Front + 1) % SIZE;
	Len--;
	return OK;
}



int main()
{
	SqQueue<int> IntQueue;
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