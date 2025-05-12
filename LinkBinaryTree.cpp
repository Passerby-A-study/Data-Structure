#include<iostream>
#define OK 1
#define ERROR 0
typedef int Status;

template<class Type>
class LinkBinaryTree
{
private:
	struct TreeNode
	{
		Type Data;
		TreeNode* Lchild, Rchild;
	};
	TreeNode* Head;
public:
	LinkBinaryTree();
	Status InitTree();
	Status CreatTree(TreeNode* Pos);
	Status InOrder(TreeNode* Pos);
	TreeNode* ReturnHead();
	Status DestoryTree(TreeNode* Pos);
	~LinkBinaryTree();
};

template<class Type>
LinkBinaryTree<Type>::LinkBinaryTree()
{
	InitTree();
}

template<class Type>
Status LinkBinaryTree<Type>::InitTree()
{
	Head = nullptr;
	return OK;
}

template<class Type>
Status LinkBinaryTree<Type>::CreatTree(TreeNode* Pos)
{
	Type Target;
	std::cin >> Target;
	if (Target == '#')
	{
		return OK;
	}
	Pos = new TreeNode;
	Pos->Data = Target;
	Pos->Lchild = Pos->Rchild = nullptr;
	CreatTree(Pos->Lchild);
	CreatTree(Pos->Rchild);
	return OK;
}

template<class Type>
Status LinkBinaryTree<Type>::InOrder(TreeNode* Pos)
{
	if (Pos == nullptr)
	{
		return OK;
	}
	InOrder(Pos->Lchild);
	cout << Pos->Data<<" ";
	InOrder(Pos->Rchild);
	return OK;
}

template<class Type>
LinkBinaryTree<Type>::TreeNode* LinkBinaryTree<Type>::ReturnHead()
{
	return Head;
}

template<class Type>
Status LinkBinaryTree<Type>::DestoryTree(TreeNode* Pos)
{
	if (Pos == nullptr)
	{
		return OK;
	}
	DestoryTree(Pos->Lchild);
	DestoryTree(Pos->Rchild);
	delete Pos;
	return OK;
}

template<class Type>
LinkBinaryTree<Type>::~LinkBinaryTree()
{
	DestoryTree(Head);
}

int main()
{
	LinkBinaryTree<char> A;
	A.InitTree();
	A.CreatTree(A.ReturnHead());
	A.InOrder(A.ReturnHead());
	return 0;
}
