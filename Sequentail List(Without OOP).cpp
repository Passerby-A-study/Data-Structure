#include <iostream>
//Õë¶ÔintÀàĞÍ
struct SequentialList {
    int* data;       
    int size;        
    int capacity;    
};


bool InitList(SequentialList& list, int capacity) {
    if (capacity <= 0) {
        return false; 
    }
    list.data = new int[capacity];
    if (!list.data) return false; 
    list.size = 0;
    list.capacity = capacity;
    return true;
}


void DestroyList(SequentialList& list) {
    delete[] list.data;
    list.data = nullptr;
    list.size = 0;
    list.capacity = 0;
}


bool IsEmpty(const SequentialList& list) {
    return list.size == 0;
}


bool IsFull(const SequentialList& list) {
    return list.size == list.capacity;
}


bool Get(const SequentialList& list, int index, int& result) {
    if (index < 1 || index > list.size) {
        return false; 
    }
    result = list.data[index - 1];
    return true;
}


int Find(const SequentialList& list, int target) {
    for (int i = 0; i < list.size; i++) {
        if (list.data[i] == target) {
            return i + 1; 
        }
    }
    return 0; 
}


bool Insert(SequentialList& list, int target, int index) {
    if (IsFull(list)) {
        return false; 
    }
    if (index < 1 || index > list.size + 1) {
        return false; 
    }

    
    for (int i = list.size; i >= index; i--) {
        list.data[i] = list.data[i - 1];
    }

    list.data[index - 1] = target;
    list.size++;
    return true;
}


bool Pop(SequentialList& list, int index) {
    if (index < 1 || index > list.size) {
        return false; 
    }

    for (int i = index - 1; i < list.size - 1; i++) {
        list.data[i] = list.data[i + 1];
    }
    list.size--;
    return true;
}


void Clear(SequentialList& list) {
    list.size = 0;
}


void PrintList(const SequentialList& list) {
    if (IsEmpty(list)) {
        std::cout << "List is empty.\n";
        return;
    }
    std::cout << "List: ";
    for (int i = 0; i < list.size; i++) {
        std::cout << list.data[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    SequentialList list;

    if (!InitList(list, 5)) {
        std::cout << "Failed to initialize list.\n";
        return 1;
    }

    Insert(list, 10, 1);
    Insert(list, 20, 2);
    Insert(list, 30, 3);
    PrintList(list);

    int value;
    if (Get(list, 2, value)) {
        std::cout << "Element at index 2: " << value << std::endl;
    }
    else {
        std::cout << "Failed to get element at index 2.\n";
    }

    Pop(list, 2);
    PrintList(list);

    Insert(list, 40, 2);
    PrintList(list);

    int index = Find(list, 30);
    if (index) {
        std::cout << "Found 30 at index: " << index << std::endl;
    }
    else {
        std::cout << "30 not found.\n";
    }

    Clear(list);
    PrintList(list);

    DestroyList(list);
    return 0;
}
