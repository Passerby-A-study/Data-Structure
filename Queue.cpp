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
	Location = new Type(SIZE);
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
Status SqQueue<Type>::DestroyQueue()
{
	delete[] Location;
	Len = Front = Rear = 0;
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
Status SqQueue<Type>::ClearQueue()
{
	Type* used = Location;
	Location = nullptr;
	delete[] used;
	SqQueue();
	if (Location && Front == 0 && Rear == 0 && Len == 0)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

template<class Type>
Status SqQueue<Type>::QueueTraverse()
{
	if (QueueEmpty())
	{
		std::cout << std::endl;
		return OK;
	}

	int index = Front;
	for (int i = 0; i < Len; i++)
	{
		std::cout << Location[index] << " ";
		index = (index + 1) % SIZE;
	}
	std::cout << std::endl;

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

	Rear = (Rear + 1) % SIZE;
	Location[Rear] = Obj;
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

	return OK;
}
