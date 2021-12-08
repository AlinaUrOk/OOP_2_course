// laba_oop_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*  6.(**) Дерева з довільною кількістю дітей (на основі зв’язного списку та бібліотечних засобів для списку), бінарні дерева,
		   дерева бінарного пошуку. Додавання елементів, видалення елементів (за батьківським вузлом та індексом, за значенням),
		   пошук за значенням.
*/






#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;

typedef int T;

typedef struct Node {
	T data;
	T index;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
} Node;

int Index;
int Count = -1;
list<int> List;

Node* getFreeNode(T value, Node* parent) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	Index++;
	List.push_back(value);
	/*Count++;*/
	tmp->index = Index;
	return tmp;
}

void insert(Node** head, int value) {

	Node* tmp = NULL;
	Node* ins = NULL;
	if (*head == NULL) {
		Index = 0;
		*head = getFreeNode(value, NULL);

		return;
	}

	tmp = *head;
	while (tmp) {
		if (value > tmp->data) {
			if (tmp->right) {
				tmp = tmp->right;
				continue;
			}
			else {
				tmp->right = getFreeNode(value, tmp);
				return;
			}

		}
		else if (value < tmp->data) {
			if (tmp->left) {
				tmp = tmp->left;
				continue;
			}
			else {
				tmp->left = getFreeNode(value, tmp);
				return;
			}
		}
		else {
			exit(2);
		}
	}
}

Node* findMinNode(Node* root) {
	while (root->left) {
		root = root->left;
	}
	return root;
}

Node* findMaxNode(Node* root) {
	while (root->right) {
		root = root->right;
	}
	return root;
}

Node* getNodeByValue(Node* root, T value) {
	while (root) {
		if (root->data > value) {
			root = root->left;
			continue;
		}
		else if (root->data < value) {
			root = root->right;
			continue;
		}
		else if (root->data == value)
		{
			cout << value << " Complete!" << endl;
			return root;
		}
	}
	cout << value << " Error..." << endl;;
	return NULL;
}



//template <class T>
//void Depth(Node* t)
//{
//	int depthLeft, depthRight, depthval;
//
//	if (t == NULL)
//		depthval = -1;
//	else
//	{
//		depthLeft = Depth(t->Left());
//		depthRight = Depth(t->Right());
//		depthval = 1 + (depthLeft > depthRight , depthLeft : depthRight);
//		cout << t->data << " depth- " << depthval << endl;
//	}
//	return depthval;
//}

void removeNodeByPtr(Node* target) {
	if (target->left && target->right) {
		Node* localMax = findMaxNode(target->left);
		target->data = localMax->data;
		removeNodeByPtr(localMax);
		return;
	}
	else if (target->left) {
		if (target == target->parent->left) {
			target->parent->left = target->left;
			/*target->parent->left->index = target->parent->left->index - 1;*/
			if (target->right)
			{
				target->right->index--;
			}
			if (target->left)
			{
				target->left->index--;
			}
		}
		else {
			target->parent->right = target->left;
			/*target->parent->right->index = target->parent->right->index - 1;*/
			if (target->right)
			{
				target->right->index--;
			}
			if (target->left)
			{
				target->left->index--;
			}
		}
	}
	else if (target->right) {
		if (target == target->parent->right) {
			target->parent->right = target->right;
			/*target->parent->right->index = target->parent->right->index - 1;*/
			if (target->right)
			{
				target->right->index--;
			}
			if (target->left)
			{
				target->left->index--;
			}
		}
		else {
			target->parent->left = target->right;
			/*target->parent->left->index = target->parent->left->index - 1;*/
			if (target->right)
			{
				target->right->index--;
			}
			if (target->left)
			{
				target->left->index--;
			}
		}
	}
	else {
		if (target == target->parent->left) {
			target->parent->left = NULL;
		}
		else {
			target->parent->right = NULL;
		}
	}

	free(target);
}

//void removeNodeByIndex(Node* target) {
//	if (target->left && target->right) {
//		Node* localMax = findMaxNode(target->left);
//		target->data = localMax->data;
//		removeNodeByIndex(localMax);
//		return;
//	}
//	else if (target->left) {
//		if (target == target->parent->left) {
//			target->parent->left = target->left;
//		}
//		else {
//			target->parent->right = target->left;
//		}
//	}
//	else if (target->right) {
//		if (target == target->parent->right) {
//			target->parent->right = target->right;
//		}
//		else {
//			target->parent->left = target->right;
//		}
//	}
//	else {
//		if (target == target->parent->left) {
//			target->parent->left = NULL;
//		}
//		else {
//			target->parent->right = NULL;
//		}
//	}
//
//	free(target);
//}



void deleteValue(Node* root, T value) {
	Node* target = getNodeByValue(root, value);
	removeNodeByPtr(target);
}


//void deleteIndex(Node* root, T value) {
//	Node* target = Circle(root, value);
//	removeNodeByIndex(target);
//}


void printTree(Node* root, const char* dir, int level) {
	if (root) {
		cout << "level " << level << " " << dir << " = " << root->data << " || " << root->index << endl;
		printTree(root->left, "left", level + 1);
		printTree(root->right, "right", level + 1);
	}
}

void inorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main() {
	Node* root = NULL;
	insert(&root, 10);
	insert(&root, 12);
	insert(&root, 8);
	insert(&root, 9);
	insert(&root, 7);
	insert(&root, 3);

	printTree(root, "root", 0);
	cout << "----------------------------------------" << endl;
	deleteValue(root, 7);
	printTree(root, "root", 0);
	cout << "----------------------------------------" << endl;
	/*getNodeByIndex(root, 2);*/
	//printTree(root, "root", 0);
	//cout << "----------------------------------------" << endl;
	//deleteIndex(root, 3);
	//printTree(root, "root", 0);
	//cout << "----------------------------------------" << endl;
	getNodeByValue(root, 3);
	cout << "----------------------------------------" << endl;
	getNodeByValue(root, 5);
	cout << "----------------------------------------" << endl;
	/*Depth<int>(root);*/
	inorder(root);
}


//
//struct Data
//{
//	int data;
//	Data* left;
//	Data* right;
//	Data* parent;
//};
//
//class List
//
//{
//	List* head;
//public:
//	Data* Add(int data)
//	{
//		Data* temp = new Data;
//		temp->data = data;
//		temp->left = NULL;
//		temp->right = NULL;
//		temp->parent = NULL;
//		return temp;
//	}
//
//	Data* push_back(Data* node, int key)
//	{
//		if (node == NULL)
//			return Add(key);
//		if (key < node->data) {
//			node->left = push_back(node->left, key);
//			node->left->parent = node;
//		}
//		else if (key > node->data) {
//			node->right = push_back(node->right, key);
//			node->right->parent = node;
//		}
//		return node;
//	}
//
//	Data* print(Data* node) {
//		if (node == NULL) {
//			return;
//		}
//		print(node->left);
//		if (node->parent != NULL && node->parent->data % 2) {
//			std::cout << node->data << " => " << node->parent->data << "\n";
//		}
//		print(node->right);
//	}
//
//};
//
//int main()
//{
//	Data* root = NULL;
//	std::list <int> lst;
//	lst.push_back(27);
//	lst.push_back(5);
//	lst.push_back(100);
//	lst.push_back(4);
//	lst.push_back(1);
//
//	lst.print(root);
//}

//template<typename T>
//void List<T>::push_back(T data) {
//	if (head == nullptr) {
//		head = new Node<T>(data);
//	}
//	else {
//		Node<T>* current = this->head;
//		while (current->pNext != nullptr) {
//			current = current->pNext;
//		}
//		current->pNext = new Node<T>(data);
//	}
//	Size++;
//}

//class Tree
//{
//public:
//	int data;
//	Tree* left=NULL, * right=NULL;
//
//	Tree* AddNode(Tree* tree, int data)
//	{
//		if (!tree)
//		{
//			tree = new Tree;
//			tree->data = data;
//			tree->left = NULL;
//			tree->right = NULL;
//		}
//		if (data > tree->data)
//		{
//			AddNode(tree->left, data);
//		}
//		if (data < tree->data)
//		{
//			AddNode(tree->right, data);
//		}
//		return tree;
//	};
//
//	void Print(Tree* tree)
//	{
//		if(tree != NULL)
//		{
//			Print(tree->left);
//			std::cout << tree->data;
//			Print(tree->right);
//		}
//	}
//
//};
//
// int main()
//{
//	 Tree tree, *root=NULL;
//	 tree.AddNode(root, 2);
//	 tree.AddNode(root, 5);
//	 tree.AddNode(root, 3);
//	 tree.AddNode(root, 7);
//	 tree.AddNode(root, 9);
//
//	 tree.Print(root);
//	 return 0;
//}