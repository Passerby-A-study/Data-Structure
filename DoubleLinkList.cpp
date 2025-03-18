#include<iostream>
using std::cin;
using std::cout;
using std::endl;
template<typename Type>
class DbLinkList {
private:
	struct ListNode {
		Type data;
		ListNode* Prior;
		ListNode* Next;
	}HeadNode;
	ListNode* Link;
public:
	DbLinkList() { Link = &HeadNode; HeadNode.Next = Link; HeadNode.Prior = Link; }
	bool Insert(int n);
	bool Delete(int n);
	ListNode* Find(Type& target);
	Type Find(int n);
	void CreatList_H();
	void CreatList_R();
	bool isEmpty();
	~DbLinkList();
};


template<typename Type>
void DbLinkList<Type>::CreatList_R() {
	int n;
	ListNode* p = Link;
	cout << "Pls Enter the scale of List: ";
	cin >> n;
	if (n <= 0) return;
	cout << "Pls Enter the data of List: ";
	while (n--) {
		ListNode* cur = new ListNode;
		cin >> cur->data;
		cur->Prior = p;
		p->Next = cur;
		p = p->Next;

	}
	Link->Prior = p;
	p->Next = Link;
	cout << "Done!" << endl;
}

template<typename Type>
bool DbLinkList<Type>::isEmpty() {
	return Link->Next == Link;
}

template<typename Type>
void DbLinkList<Type>::CreatList_H() {
	int n;
	cout << "Pls Enter the scale of List: ";
	cin >> n;
	if (n <= 0) return;
	ListNode* first = new ListNode;
	cin >> first->data;
	first->Prior = Link;
	first->Next = Link->Next;
	Link->Next->Prior = first;
	Link->Next = first;
	Link->Prior = first;
	n -= 1;
	cout << "Pls Enter the data of List: ";
	while (n--) {
		ListNode* cur = new ListNode;
		cin >> cur->data;
		cur->Prior = Link;
		cur->Next = Link->Next;
		Link->Next->Prior = cur;
		Link->Next = cur;
	}
	cout << "Done!" << endl;
}

template<typename Type>
bool DbLinkList<Type>::Insert(int n) {
	ListNode* p = Link;
	while (n--) {
		if (p->Next == Link) break;
		p = p->Next;
	}

	ListNode* cur = new ListNode;
	cout << "Pls Enter the Data: ";
	cin >> cur->data;
	cur->Next = p->Next;
	p->Next->Prior = cur;
	cur->Prior = p;
	p->Next = cur;
	cout << "Done !" << endl;
	return true;
}

template<typename Type>
bool DbLinkList<Type>::Delete(int n) {
	if (isEmpty() || n < 1) return false;
	ListNode* p = Link;
	for (int i = 0; i < n - 1; i++) {
		if (p->Next == Link) return false;
		p = p->Next;
	}
	ListNode* tmp = p->Next;
	p->Next = p->Next->Next;
	p->Next->Prior=p;
	delete tmp;
	cout << "Done !" << endl;
	return true;
}


template<typename Type>
typename DbLinkList<Type>::ListNode* DbLinkList<Type>::Find(Type& target) {
	if (isEmpty() == true) return nullptr;
	ListNode* p = Link;
	while (p->Next != Link) {
		p = p->Next;
		if (p->data == target)
			return p;
	}
	return nullptr;
}

template<typename Type>
Type DbLinkList<Type>::Find(int n) {
	if (isEmpty()) return {};

	ListNode* p = Link;
	for (int i = 1; i <= n; i++) {
		p = p->Next;
		if (p == Link) return {};
	}
	return p->data;
}

template<typename Type>
DbLinkList<Type>::~DbLinkList() {
	ListNode* p = Link->Next;
	while (p != Link) {
		ListNode* temp = p;
		p = p->Next;
		delete temp;
	}
	Link->Prior = Link;
	Link->Next = Link;
}