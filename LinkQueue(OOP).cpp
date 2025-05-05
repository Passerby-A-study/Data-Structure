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
		std::cout << "����Ϊ�ա�" << std::endl;
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
		throw "����Ϊ�գ��޷���ȡ����Ԫ�أ�";
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
			IntQueue.QueueTraverse();
			break;
		case 4:
			if (IntQueue.ClearQueue() == OK) {
				std::cout << "������ճɹ���" << std::endl;
			}
			break;
		case 5:
			std::cout << "���г���Ϊ: " << IntQueue.QueueLength() << std::endl;
			break;
		case 6:
			try {
				std::cout << "����Ԫ��Ϊ: " << IntQueue.GetHead() << std::endl;
			}
			catch (const char* msg) {
				std::cout << msg << std::endl;
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
