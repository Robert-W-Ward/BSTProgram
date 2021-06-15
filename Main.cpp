#pragma once
#include <fstream>
#include <iostream>
#include <sstream>

#include"BinarySearchTree.h"
using std::string;
using std::stringstream;
using std::fstream;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

BinarySearchTree<int> ticketNums;
BinarySearchTree<std::string> userIDs;

void parse(string cmd);
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
		cout << "File: " << FileToLoad << " could not be loaded or located" << endl;
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
				}
				if(userIDs.Find(tmpUserID,userIDs.root) && ticketNums.Find(tmpticketNum ,ticketNums.root))
				{
					cout << "user with ticket number found!";
				}
				else
				{
					cout << "Combonation not found";
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
				userIDs.add(tmpUserID);
				ticketNums.add(tmpticketNum);
			}
			else
			{
				cerr << "\"" << TOKEN << "\"" << ":Is not a recognized command" << endl;
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