#include<iostream>
#include<String>
#include"dLinkedlist.H"
#include<fstream>
#include "Textreader.h"
using namespace std;
int main()
{	
	fstream myFile;
	int linecount;
	string wholetext;
	cout << "to stop type stop" << endl;
	cout << "enter the text" << endl;
	myFile.open("Test1.txt", ios::out);
	if (myFile.is_open()) {
		myFile << "" << endl;
		myFile.close();
	}
	myFile.open("Test1.txt", ios::app);
	if (myFile.is_open()) {
		while (wholetext !="stop")
		{
			getline(cin, wholetext);
			if(wholetext!="stop")
			myFile << wholetext << endl;
		}
		myFile.close();
	}

	int choice = -1;
	int dothething = 0;
	string theword;

	cout << "press the number of your choice \n\n1-display the file\n\n2-find words postion in the text  \n\n3-delete words from the text \n\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << endl << "----link list Text------" << endl;
		dothething = 1;

		break;
	case 2:
		cout << "enter the word : ";
		cin >> theword;
		dothething = 2;
		break;
	case 3:
		cout << "enter the word : ";
		cin >> theword;
		dothething = 3;
		break;
	default:
		cout << "invalied choice try again " << endl;
	}
	
	myFile.open("Test1.txt", ios::in);

	int lnum = 1;
	dLinkedList<dLinkedList<string>> lines{};

	if (myFile.is_open())
	{
		string line = "";
		while (getline(myFile, line))
		{
			dLinkedList<string> words{};
			int i = 0;
			string word = "";
			while(line[i]!=NULL)
			{
				if (line[i] == ' ')
				{
					words.add(word);
					word = "";
				}
				else {
					word = word + line[i];
				}
				i++;
			}
			words.add(word);
			lines.add(words);
			switch (dothething)
			{
			case 1:
				words.displayAll();
				cout << endl;
				break;
			case 2:
			{
				words.FindWord(theword);
			}
			break;
			case 3:
				words.remove(theword);
				break;
			default:
				cout << "invalied choice try again " << endl;
			}
		}
		lnum++;
	}
	myFile.close();
	while(choice != 0)
	{

		cout << "\n \n\n1-display the file\n\n2-find words postion in the text  \n\n3-delete words from the text \n\npress 0 to exit \n\n";

		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << endl << "----link list Text------" << endl;
			lines.display(); 
			cout << "\n\n\n\n\n\n\n\n\n\n\n";
			break;
		case 2:
			cout << "enter the word : ";
			cin >> theword;
			lines.FInd(theword);
			break;
		case 3:
			cout << "enter the word : ";
			cin >> theword;
			lines.del(theword);
			cout << "\n\n\n\n\n\n\n";
			break;
		default:
			cout << "invalied choice try again " << endl;
		}
    }

}

	

