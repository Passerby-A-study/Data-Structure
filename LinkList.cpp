#include<iostream>
using std::cin;
using std::cout;
using std::endl;
template<typename Type>
class LinkList {
private:
	struct ListNode {
		Type data;
		ListNode* Next;
	}HeadNode;
	ListNode* Link;
public:
	LinkList() { Link = &HeadNode; HeadNode.Next = nullptr; }
	bool Insert(int n);
	bool Delete(int n);
	ListNode* Find(Type& target);
	Type Find(int n);
	void CreatList_H();
	void CreatList_R();
	bool isEmpty();
};


template<typename Type>
void LinkList<Type>::CreatList_R() {
	int n;
	ListNode* p = Link;
	cout << "Pls Enter the scale of List: ";
	cin >> n;
	if (n <= 0) return;
	cout << "Pls Enter the data of List: ";
	while (n--) {
		ListNode* cur = new ListNode;
		cin >> cur->data;
		p->Next = &cur;
		p = p->Next;
	}
	cout << "Done!"<<endl;
}

template<typename Type>
bool LinkList<Type>::isEmpty() {
	if (Link->Next == nullptr) return true;
	return false;
}

template<typename Type>
void LinkList<Type>::CreatList_H() {
	int n;
	ListNode* p = Link;
	cout << "Pls Enter the scale of List: ";
	cin >> n;
	if (n <= 0) return;
	cout << "Pls Enter the data of List: ";
	ListNode* first = new ListNode;
	cin >> first->data;
	p = p->Next;
	n -= 1;
	while (n--) {
		ListNode* cur = new ListNode;
		cin >> cur->data;
		cur->Next = p;
		p = &cur;
	}
	cout << "Done!" << endl;
}

template<typename Type>
bool LinkList<Type>::Insert(int n) {
	ListNode* p = Link;
	while (n--) {
		p = p->Next;
	}
	ListNode* cur = new ListNode;
	cout << "Pls Enter the Data : ";
	cin >> cur->data;
	cur->Next = p->Next;
	p->Next = cur;
	cout << "Done !" << endl;
}

template<typename Type>
bool LinkList<Type>::Delete(int n) {
	if (isEmpty() == true) return false;
	ListNode* p = Link;
	while (n--) {
		p = p->Next;
	}
	ListNode* cur = new ListNode;
	cur->Next = p->Next;
	p->Next = cur;
	cout << "Done !" << endl;
}

template<typename Type>
LinkList<Type>::ListNode* LinkList<Type>::Find(Type& target) {
	if (isEmpty() == true) return nullptr;
	ListNode* p = Link;
	while (p->Next != nullptr) {
		p = p->Next;
		if (p->data == target)
			return p;
	}
	return nullptr;
}

template<typename Type>
Type LinkList<Type>::Find(int n) {
	if (isEmpty() == true) return NULL;
	ListNode* p = Link;
	if (int i=1;i<=n;i++)
	{
		p = p->Next;
	}
	return p->data;
}


