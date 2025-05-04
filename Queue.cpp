#define MAXQSIZE 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

template<class Type>
class SqQueue {
private:
	Type* Location;
	int Front;
	int Rear;
public:
	SqQueue();
	Status InitQueue();
	Status DestroyQueue();
	Status ClearQueue();
	Status QueueEmpty();
	int QueueLength();
	const Type& GetHead();
	Status EnQueue(Type& Obj);
	Status DeQueue();
	Status QueueTraverse();
	~SqQueue();
};