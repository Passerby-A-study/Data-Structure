#include<exception>
template <typename Type>
class SequentialList:public::std::exception {
private:
	int Length;
	Type* Elem;
public:
	SequentialList(int Len);
	SequentialList(int Len, Type& Target);
	bool Init(Type& Target);
	bool isEmpty();
	bool isFull();
	Type& Get(int index);
	int Find(Type& object);
	bool Pop(int index);
	bool Insert(Type& target, int index);
	bool Clear();
	~SequentialList();
};

template <typename Type>
SequentialList<Type>::SequentialList(int Len) {
	Type* p = new Type[Len];
	Elem = p;
	Length = Len;
}
template <typename Type>
SequentialList<Type>::SequentialList(int Len, Type& Target) {
	Type* p = new Type[Len];
	Elem = p;
	Length = Len;
	Init(Target);
}
template <typename Type>
bool SequentialList<Type>::Init(Type& Target) {
	if (isEmpty == true)
		return false;
	for (auto element : *Elem)
		element = Target;
	return true;
}
template <typename Type>
bool SequentialList<Type>::isEmpty() {
	return Length > 0 ? 0 : 1;
}

template <typename Type>
bool SequentialList<Type>::isFull(){
	return Length < (sizeof(*Elem)/sizeof(Type)) ? 0 : 1;
}

template <typename Type>
Type& SequentialList<Type>::Get(int index) {
	return *(Elem + index - 1);
}

template <typename Type>
int SequentialList<Type>::Find(Type& object) {
	for (int i = 0; i < Length; i++)
		if (*(Elem + i) == object)
			return i + 1;
}

template <typename Type>
bool SequentialList<Type>::Pop(int index) {
	if (Length > 0) {
		*(Elem + Length - 1) = NULL;
		Length -= 1;
		for (int i = index - 1; i < Length; i++)
			*(Elem + i) = *(Elem + i + 1);
		return true;
	}
	return false;
}

template <typename Type>
bool SequentialList<Type>::Insert(Type& target,int index) {
	if (Length + 1 > sizeof(*Elem) / sizeof(Type)) 
		return false;
	Length += 1;
	for (int i = Length; i > index; i--)
		*(Elem + i) = *(Elem + i - 1);
	*(Elem + index - 1) = target;
	return true;
}

template <typename Type>
bool SequentialList<Type>::Clear() {
	if (isEmpty() == true)
		return false;
	for (auto element : *Elem)
		element = NULL;
	return true;
}

template <typename Type>
SequentialList<Type>::~SequentialList() {
	delete[] Elem;
}

int main() {

	return 0;
}