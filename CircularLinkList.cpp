#include<iostream>
using std::cin;
using std::cout;
using std::endl;
template<typename Type>
class CirLinkList {
private:
	struct ListNode {
		Type data;
		ListNode* Next;
	}HeadNode;
	ListNode* Link;
public:
	CirLinkList() { Link = &HeadNode; HeadNode.Next = Link; }
	bool Insert(int n);
	bool Delete(int n);
	ListNode* Find(Type& target);
	Type Find(int n);
	void CreatList_H();
	void CreatList_R();
	bool isEmpty();
	~CirLinkList();
};


template<typename Type>
void CirLinkList<Type>::CreatList_R() {
	int n;
	ListNode* p = Link;
	cout << "Pls Enter the scale of List: ";
	cin >> n;
	if (n <= 0) return;
	cout << "Pls Enter the data of List: ";
	while (n--) {
		ListNode* cur = new ListNode;
		cin >> cur->data;
		p->Next = cur;
		p = p->Next;

	}
	p->Next = Link;
	cout << "Done!" << endl;
}

template<typename Type>
bool CirLinkList<Type>::isEmpty() {
	return Link->Next == Link;
}

template<typename Type>
void CirLinkList<Type>::CreatList_H() {
	int n;
	cout << "Pls Enter the scale of List: ";
	cin >> n;
	if (n <= 0) return;

	cout << "Pls Enter the data of List: ";
	while (n--) {
		ListNode* cur = new ListNode;
		cin >> cur->data;
		cur->Next = Link->Next;
		Link->Next = cur;
	}
	cout << "Done!" << endl;
}

template<typename Type>
bool CirLinkList<Type>::Insert(int n) {
	ListNode* p = Link;
	while (n--) {
		if (p->Next == Link) break;
		p = p->Next;
	}

	ListNode* cur = new ListNode;
	cout << "Pls Enter the Data: ";
	cin >> cur->data;
	cur->Next = p->Next;
	p->Next = cur;
	cout << "Done !" << endl;
	return true;
}

template<typename Type>
bool CirLinkList<Type>::Delete(int n) {
	if (isEmpty() || n < 1) return false;
	ListNode* p = Link;
	for (int i = 0; i < n - 1; i++) {
		if (p->Next == Link) return false;
		p = p->Next;
	}
	ListNode* tmp = p->Next;
	p->Next = p->Next->Next;
	delete tmp;
	cout << "Done !" << endl;
	return true;
}


template<typename Type>
typename CirLinkList<Type>::ListNode* CirLinkList<Type>::Find(Type& target) {
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
Type CirLinkList<Type>::Find(int n) {
	if (isEmpty()) return {};

	ListNode* p = Link;
	for (int i = 1; i <= n; i++) {
		p = p->Next;
		if (p == Link) return {};
	}
	return p->data;
}

template<typename Type>
CirLinkList<Type>::~CirLinkList() {
	ListNode* p = Link->Next;
	while (p != Link) {
		ListNode* temp = p;
		p = p->Next;
		delete temp;
	}
	Link->Next = Link;
}