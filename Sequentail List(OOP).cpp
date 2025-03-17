#include <iostream>
#include <stdexcept>

template <typename Type>
class SequentialList {
private:
    int size;      
    int capacity;  
    Type* Elem;    

public:
    SequentialList(int Len);
    ~SequentialList();

    bool isEmpty() const;
    bool isFull() const;

    Type& Get(int index);
    int Find(const Type& object);

    void Pop(int index);
    void Insert(const Type& target, int index);
    void Clear();
};


template <typename Type>
SequentialList<Type>::SequentialList(int Len) : size(0), capacity(Len) {
    if (Len <= 0) {
        throw std::invalid_argument("Capacity must be greater than zero.");
    }
    Elem = new Type[capacity];
}


template <typename Type>
SequentialList<Type>::~SequentialList() {
    delete[] Elem;
}


template <typename Type>
bool SequentialList<Type>::isEmpty() const {
    return size == 0;
}


template <typename Type>
bool SequentialList<Type>::isFull() const {
    return size == capacity;
}


template <typename Type>
Type& SequentialList<Type>::Get(int index) {
    if (index < 1 || index > size) {
        throw std::out_of_range("Index out of range in Get().");
    }
    return Elem[index - 1];
}


template <typename Type>
int SequentialList<Type>::Find(const Type& object) {
    for (int i = 0; i < size; i++) {
        if (Elem[i] == object) {
            return i + 1;  
        }
    }
    throw std::runtime_error("Element not found in Find().");
}



template <typename Type>
void SequentialList<Type>::Pop(int index) {
    if (index < 1 || index > size) {
        throw std::out_of_range("Index out of range in Pop().");
    }
    for (int i = index - 1; i < size - 1; i++) {
        Elem[i] = Elem[i + 1];
    }
    size--;
}


template <typename Type>
void SequentialList<Type>::Insert(const Type& target, int index) {
    if (isFull()) {
        throw std::overflow_error("List is full. Cannot insert.");
    }
    if (index < 1 || index > size + 1) {
        throw std::out_of_range("Index out of range in Insert().");
    }

    
    for (int i = size; i >= index; i--) {
        Elem[i] = Elem[i - 1];
    }

    Elem[index - 1] = target;
    size++;  
}


template <typename Type>
void SequentialList<Type>::Clear() {
    size = 0;
}

int main() {
    try {
        SequentialList<int> list(5);

        list.Insert(10, 1);
        list.Insert(20, 2);
        list.Insert(30, 3);

        std::cout << "Element at index 2: " << list.Get(2) << std::endl;

        list.Pop(2);
        std::cout << "After Pop, Element at index 2: " << list.Get(2) << std::endl;

        list.Insert(40, 2);
        std::cout << "After Insert, Element at index 2: " << list.Get(2) << std::endl;

        list.Get(10); 

    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
