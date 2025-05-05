#include <iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

template<class Type>
class LinkQueue {
private:
	struct LQNode {
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
LinkQueue<Type>::LinkQueue() {
	InitQueue();
}

template<class Type>
Status LinkQueue<Type>::InitQueue() {
	LQNode* Head = new LQNode;
	Head->Next = nullptr;
	Front = Rear = Head;
	Len = 0;
	return OK;
}

template<class Type>
LinkQueue<Type>::~LinkQueue() {
	DestroyQueue();
}

template<class Type>
Status LinkQueue<Type>::DestroyQueue() {
	LQNode* pos = Front;
	while (pos != nullptr) {
		LQNode* temp = pos;
		pos = pos->Next;
		delete temp;
	}
	Front = Rear = nullptr;
	Len = 0;
	return OK;
}

template<class Type>
Status LinkQueue<Type>::ClearQueue() {
	LQNode* pos = Front->Next;
	while (pos != nullptr) {
		LQNode* temp = pos;
		pos = pos->Next;
		delete temp;
	}
	Front->Next = nullptr;
	Rear = Front;
	Len = 0;
	return OK;
}

template<class Type>
Status LinkQueue<Type>::QueueTraverse() {
	if (QueueEmpty()) {
		std::cout << "队列为空。" << std::endl;
		return ERROR;
	}

	LQNode* pos = Front->Next;
	while (pos != nullptr) {
		std::cout << pos->Data << " ";
		pos = pos->Next;
	}
	std::cout << std::endl;
	return OK;
}

template<class Type>
bool LinkQueue<Type>::QueueEmpty() {
	return Front == Rear;
}

template<class Type>
int LinkQueue<Type>::QueueLength() {
	return Len;
}

template<class Type>
const Type& LinkQueue<Type>::GetHead() {
	if (QueueEmpty()) {
		throw "队列为空，无法获取队首元素！";
	}
	return Front->Next->Data;
}

template<class Type>
Status LinkQueue<Type>::EnQueue(Type& Obj) {
	LQNode* node = new LQNode;
	node->Data = Obj;
	node->Next = nullptr;
	Rear->Next = node;
	Rear = node;
	Len++;
	return OK;
}

template<class Type>
Status LinkQueue<Type>::DeQueue() {
	if (QueueEmpty()) {
		return ERROR;
	}

	LQNode* temp = Front->Next;
	Front->Next = temp->Next;
	if (Rear == temp) {
		Rear = Front; 
	}
	delete temp;
	Len--;
	return OK;
}

int main() {
	LinkQueue<int> IntQueue;
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
			IntQueue.QueueTraverse();
			break;
		case 4:
			if (IntQueue.ClearQueue() == OK) {
				std::cout << "队列清空成功！" << std::endl;
			}
			break;
		case 5:
			std::cout << "队列长度为: " << IntQueue.QueueLength() << std::endl;
			break;
		case 6:
			try {
				std::cout << "队首元素为: " << IntQueue.GetHead() << std::endl;
			}
			catch (const char* msg) {
				std::cout << msg << std::endl;
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
