#pragma once
#include <string>
#include <iostream>
using namespace std;
template <typename P, typename Q>
bool isEqual(P p, Q q)
{
	return p == q;
}
template <typename R,typename S>
bool isGreater(R r, S s)
{
	return r > s;
}
template<typename T>
class BinarySearchTree
{
public:
	struct Node
	{
		
		T data{};
		Node* left{nullptr};
		Node* right{nullptr};
		Node():data(),left(nullptr),right(nullptr){}
		Node(T data):data(data){}
		Node(Node* L,Node*R):left(L),right(R){}		
	};

	Node* root;
	BinarySearchTree():root(nullptr){}
	
	
	void sort(Node* root, Node* newNode)
	{
		if(isGreater(newNode->data, root->data))
		{
			if(root->right == nullptr)
			{
				root->right = newNode;
			}
			else
			{
				sort(root->right, newNode);
			}
		}
		if(!isGreater(newNode->data, root->data))
		{
			if(root->left == nullptr)
			{
				root->left = newNode;
			}
			else
			{
				sort(root->left, newNode);
			}
		}
	}

	bool Find(T data,Node* root)
	{
		Node* tmp = root;
		
		if(tmp->data == data)
		{
			return true;
		}
		else if(tmp->left != nullptr && tmp->right != nullptr)
		{
			if(tmp->left->data == data)
			{
				return true;
			}
			else if(tmp->right->data == data)
			{
				return true;
			}
			else
			{
				Find(data, tmp);
			}
		}
		
	}
	Node* add(T data)
	{
		Node* tmp = new Node;

		tmp->data = data;
		tmp->left = nullptr;
		tmp->right = nullptr;
		if(root == nullptr)
		{
			root = tmp;
		}
		else
		{
			sort(root, tmp);
		}
		return root;
	}
	


	
};

