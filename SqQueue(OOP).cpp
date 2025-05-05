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
		std::cout << "\nint队列操作菜单：" << std::endl;
		std::cout << "1. 入队" << std::endl;
		std::cout << "2. 出队" << std::endl;
		std::cout << "3. 遍历队列" << std::endl;
		std::cout << "4. 清空队列" << std::endl;
		std::cout << "5. 获取队列长度" << std::endl;
		std::cout << "6. 获取队首元素" << std::endl;
		std::cout << "0. 退出" << std::endl;
		std::cout << "请输入你的选择: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			std::cout << "请输入要入队的元素: ";
			std::cin >> value;
			if (IntQueue.EnQueue(value) == OK) {
				std::cout << "入队成功！" << std::endl;
			}
			else {
				std::cout << "队列已满，入队失败！" << std::endl;
			}
			break;
		case 2:
			if (IntQueue.DeQueue() == OK) {
				std::cout << "出队成功！" << std::endl;
			}
			else {
				std::cout << "队列为空，出队失败！" << std::endl;
			}
			break;
		case 3:
			if (IntQueue.QueueLength() == 0)
			{
				std::cout << "队列无元素！" << std::endl;
				break;
			}
			else
			{
				std::cout << "队列元素为: ";
				IntQueue.QueueTraverse();
				break;
			}
		case 4:
			if (IntQueue.ClearQueue() == OK) {
				std::cout << "队列清空成功！" << std::endl;
			}
			else {
				std::cout << "队列清空失败！" << std::endl;
			}
			break;
		case 5:
			std::cout << "队列长度为: " << IntQueue.QueueLength() << std::endl;
			break;
		case 6:
			if (!IntQueue.QueueEmpty()) {
				std::cout << "队首元素为: " << IntQueue.GetHead() << std::endl;
			}
			else {
				std::cout << "队列为空，没有队首元素！" << std::endl;
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