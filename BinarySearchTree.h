#pragma once
#include <string>
#include <iostream>
#include "userData_ticket.h"
using namespace std;


template <typename T>
struct BinarySearchTree
{
	struct Node;
	Node* root;
	struct Node
	{
		T data;
		int degree()const
		{
			if(left == nullptr && right == nullptr)
			{
				return 0;
			}
			else if(left != nullptr || right != nullptr)
			{
				return 1;
			}
			else
			{
				return 2;
			}

		};
		Node* left{ nullptr };
		Node* right{ nullptr };
		Node() :data(), left(nullptr), right(nullptr)
		{}
		Node(T data) :data(data), left(nullptr), right(nullptr)
		{}
		Node(Node* L, Node* R) :left(L), right(R)
		{}
		friend ostream& operator<<(ostream& os, Node node)
		{
			os << node.data.UID<<" "<< node.data.ticknum<<endl;
			return os;
		}
	};
	
	BinarySearchTree():root(nullptr){}
	
	bool Find(Node* node ,std::string UID,int ticket)
	{
		if(node != nullptr)
		{
			
			if(node->data.UID == UID &&node->data.ticknum==ticket)
			{
				std::cout << "User: "<<UID<<" with ticket number: "<<ticket<<" found! "<<std::endl;
				return true;
			}
			else if(Find(node->left, UID, ticket))
			{
				return true;
				
			}
			else if(Find(node->right, UID, ticket))
			{
				return true;
			}
			else
			{
				Find(node->right, UID, ticket);
				Find(node->left, UID, ticket);
			}
				
		}
			
			return false;

	}
	//from the slides
	bool remove(Node*& node, T data)
	{
		if(node == nullptr)
		{
			return false;
		}
		if(data < node->data)
		{
			return remove(node->left, data);
		}
		if(data > node->data)
		{
			return remove(node->right, data);
		}
		int deg = node->degree();
		if(deg == 0)
		{
			delete node;
			node = nullptr;
		}
		else if(deg == 1)
		{
			Node* tmp = node;
			if(node->left != nullptr)
			{
				node = node->left;
			}
			else
			{
				node = node->right;
			}
			delete tmp;
		}
		else
		{
			Node* tmp = node->left;
			while(tmp->right != nullptr)
			{
				tmp = tmp->right;
			}
			node->data = tmp->data;
			remove(node->left, tmp->data);
		}
	}
	bool add(Node*& node, T data)
	{
		//from slides 
		if(node == nullptr)
		{
			node = new Node(data);
			return true;
		}
		if(node->data>data)
		{
			return add(node->left, data);
		}
		if(node->data<data)
		{
			return add(node->right, data);
		}
		if(node->data == data)
		{
			if(node->data.UID == data.UID&&node->data.ticknum==data.ticknum)
			{
				std::cout << "User with ticket number already in the system"<<std::endl;
				return false;
			}
			else
			{
				if(node->data.UID > data.UID || node->data.ticknum > data.ticknum)
				{
					return add(node->left, data);
				}
				else if(node->data.UID < data.UID || node->data.ticknum < data.ticknum)
				{
					return add(node->right, data);
				}
			}
			
		}
		return false;

	}
	//i figured these out from the slides
	void inOrder(Node* root, ostream& os)
	{
		if(root == nullptr)return;
		inOrder(root->left, os);
		os <<"\t"<< *root;
		inOrder(root->right, os);
		
	}
	//from the slides
	void preOrder(Node*& root, ostream& os)
	{
		if(root == nullptr)return;
		os << "\t" << *root;
		preOrder(root->left, os);
		preOrder(root->right, os);
	}
	//from the slides
	void postOrder(Node*& root, ostream& os)
	{
		if(root == nullptr)return;
		postOrder(root->left, os);
		postOrder(root->right, os);
		os << "\t" << *root;
	}
	void clear(Node*& node)
	{
		if(node == nullptr)return;
		clear(node->left);
		clear(node->right);
		delete node;
		node = nullptr;
	}
};

