/*
Student Name: Robert Ward
Student NetID: rww189
Compiler Used: Visual Studio
Program Description:
A Binary Search tree that stores userIDs and UserNames 
and can search for both
*/
#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include "userData_ticket.h"
#include "userData_UID.h"
#include"BinarySearchTree.h"
using namespace std;
void parse(string cmd);

BinarySearchTree<userData_ticket> userTick;
BinarySearchTree<userData_UID> userID;

string loadFile(string FileToLoad)
{
	string tmp;
	stringstream FileContents;
	fstream File;
	File.open(FileToLoad);
	if(File.is_open())
	{
		cout << "Successfully opened: " << FileToLoad << endl;
		while(getline(File, tmp,'\n'))
		{
			FileContents << tmp<<" ";		
		}
		File.close();
	}
	else
	{
		cout << "File ERROR: \"" << FileToLoad << "\" could not be loaded or located" << endl;
		return FileToLoad;
	}
	
	return  FileContents.str();
}
void parse(string ToBeParsed)
{
	string TOKEN;
	stringstream parseStream(ToBeParsed);
	while(getline(parseStream, TOKEN, ' '))
	{

		if(!TOKEN.empty())
		{
			if(TOKEN == "exit")
			{				
				cout << "GOODBYE!" << endl;
				system("pause");
				exit(0);
			}
			if(TOKEN == "load")
			{
				getline(parseStream, TOKEN, ' ');
				string CONTENTS_OF_FILE = loadFile(TOKEN);
				parse(CONTENTS_OF_FILE);
			}
			else if(TOKEN == "find")
			{
				getline(parseStream, TOKEN, ' ');
				std::string tmpUserID = TOKEN;
				getline(parseStream, TOKEN, ' ');
				int tmpticketNum;
				try
				{
					 tmpticketNum = stoi(TOKEN);
				}
				catch(...)
				{
					cerr << "Could not convert string to int" << endl;
				};
				
				if(userID.Find(userID.root, tmpUserID, tmpticketNum) == false)
				{

					std::cout << "User with ticket number not found "<<std::endl;
				}
				
				
				
				
			}
			else if(TOKEN == "add")
			{
				getline(parseStream, TOKEN, ' ');
				std::string tmpUserID = TOKEN;
				getline(parseStream, TOKEN, ' ');
				int tmpticketNum;
				try
				{
					tmpticketNum = stoi(TOKEN);
				}
				catch(...)
				{
					cerr << "Could not convert string to int" << endl;
				}
				if(userTick.add(userTick.root, userData_ticket(tmpUserID, tmpticketNum))&& userID.add(userID.root, userData_UID(tmpUserID, tmpticketNum)))
				{
					cout << "User: " << tmpUserID << " with ticket number: " << tmpticketNum << " added to the system" << endl;
				}
				
			}
			else if(TOKEN == "remove")
			{
				getline(parseStream, TOKEN, ' ');
				std::string tmpUserID = TOKEN;
				getline(parseStream, TOKEN, ' ');
				int tmpticketNum;
				try
				{
					tmpticketNum = stoi(TOKEN);
				}
				catch(...)
				{
					cerr << "Could not convert string to int" << endl;
				}
				if(userID.remove(userID.root, userData_UID(tmpUserID, tmpticketNum)) && userTick.remove(userTick.root, userData_ticket(tmpUserID, tmpticketNum)))
				{
					cout << "User: " << tmpUserID << " with ticketnumber: " << tmpticketNum << " was removed from the system"<<endl;
				}
				
			}
			else if(TOKEN == "new")
			{
				userID.clear(userID.root);
				userTick.clear(userTick.root);

			}
			else if(TOKEN == "display")
			{
				getline(parseStream, TOKEN,' ');
				if(TOKEN == "ticket")
				{
					getline(parseStream, TOKEN,' ');
					if(TOKEN == "in")
					{
						if(userTick.root != nullptr)
						{
							cout << "\n\tTicket in order" << endl;
							userTick.inOrder(userTick.root, std::cout);
						}
						else
						{
							cout << "No data in system"<<std::endl;
						}
					}
					else if(TOKEN == "pre")
					{
						if(userTick.root != nullptr)
						{
							cout << "\n\tTicket in pre order"<<endl;
							userTick.preOrder(userTick.root, std::cout);

						}
						else
						{
							cout << "No data in system" << std::endl;
						}
					}
					else if(TOKEN == "post")
					{
						if(userTick.root != nullptr)
						{
							cout << "\n\tTicket in post order" << endl;
							userTick.postOrder(userTick.root, std::cout);
						}
						else
						{
							cout << "No data in system" << std::endl;
						}
					}
					else
					{
						cout << TOKEN << " is an unrecognized command" << std::endl;
					}
				}
				else if(TOKEN == "user")
				{
					getline(parseStream, TOKEN, ' ');

					if(TOKEN == "in")
					{
						if(userID.root != nullptr)
						{
							cout << "\n\tUser in order"<<endl;
							userID.inOrder(userID.root, std::cout);
						}
						else
						{
							cout << "No data in system" << std::endl;
						}
					}
					else if(TOKEN == "pre")
					{
						if(userID.root != nullptr)
						{
							cout << "\n\tUser in pre order" << endl;
							userID.preOrder(userID.root, std::cout);
						}
						else
						{
							cout << "No data in system" << std::endl;
						}
					}
					else if(TOKEN == "post")
					{
						if(userID.root != nullptr)
						{
							cout << "\n\tUser in post order" << endl;
							userID.postOrder(userID.root, std::cout);
						}
						else
						{
							cout << "No data in system" << std::endl;
						}
					}
					else
					{
						cout <<"ERROR: \""<< TOKEN << "\" is an unrecognized Token" << std::endl;
					}
				}
				else
				{
					cout << "ERROR: \"" << TOKEN << "\" is an unrecognized Token" << std::endl;
				}
			}
			else if(TOKEN == "save")
			{
				getline(parseStream, TOKEN,' ');
				if(TOKEN == "ticket")
				{
					getline(parseStream, TOKEN,' ');
					if(TOKEN == "into")
					{
						getline(parseStream, TOKEN,' ');
						if(TOKEN == "file")
						{
							fstream fs("ticketPostorder.txt",fstream::out);
							userTick.postOrder(userTick.root, fs);
							fs.close();
							cout << "UserID post Order traversal saved into the file ticketpostOrder.txt\n";
						}
					}
				}
				else if(TOKEN == "user")
				{
					getline(parseStream, TOKEN, ' ');
					if(TOKEN == "into")
					{
						getline(parseStream, TOKEN, ' ');
						if(TOKEN == "file")
						{
							fstream fs("userIDpostOrder.txt", fstream::out);
							userID.postOrder(userID.root, fs);
							fs.close();
							cout << "UserID post Order traversal saved into the file userIDpostOrder.txt\n";
						}
					}
				}
			}
			else
			{
			cerr << "ERROR: " << TOKEN << " is an unrecognized Token" << std::endl;
			}
		}
		
	}
	if(ToBeParsed=="")
	{
		cout << "No command entered" << endl;
	}
	
}
int main()
{
	
	
	bool isRunning{ true };
	string inputStr;
	while(isRunning)
	{
		cout << ">>";
		getline(cin, inputStr);
		stringstream inputStream(inputStr);		
		parse(inputStream.str());
	}
	
}