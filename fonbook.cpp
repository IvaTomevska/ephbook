#include<iostream>
#include<fstream>
#include<cmath>
#include<chrono>
#include<sstream>
#include<list>
#include<algorithm>

#include "evaluation.h"
#include "hashimplement.h"

using namespace std;
using namespace std::chrono;


int main(int argc, char **argv)
{
	int inCnt=0;
	string choice;
	HashMap myHashMap(20000);
	while(true)
	{
		cout<<"Enter a command: "; 
		getline(cin,choice);							//takes the whole line of input
		if (inCnt==0)									//if the hashmap has not been initialized yet
		{
			if (choice.find("init") != string::npos)
			{	
				string file=argv[2];
				load(file, myHashMap);
				inCnt++;
			}
			else
				cout << "First initialize the data structure by writing 'init'." << endl;
		}
		else	
		{
			if (choice.find("quit") != string::npos)
				break;
			else if(choice.find("find") != string::npos && (choice.size() > 5))
			{
				string query = choice.substr(choice.find(" ")+1, string::npos); 		//separates find from query
				auto start= high_resolution_clock::now();
				string result = myHashMap.search(query);
				auto stop= high_resolution_clock::now();
				auto duration= duration_cast<microseconds>(stop-start);
				cout << "Runtime: " << duration.count() << " ms" << endl;
				cout<< "The record for " << choice << " is: " << result << endl;
			}
			else if (choice.find("add") != string::npos)
			{
				string name, city;
				string query = choice.substr(choice.find("add")+4, string::npos);
				getNameCity(name, city, query);
				if (myHashMap.search(name)==query)
					cerr<<"The record already exists"<<endl;
				else
				{
					myHashMap.insert(name, city, query);
					cout << "The record has been added" << endl;
				}
				
			}
			else if (choice.find("load") != string::npos && (choice.size()>5))
			{
				string query = choice.substr(choice.find(" ")+1, string::npos);
				load(query, myHashMap);
				cout << "The content of file " << query << " has been added to the hashmap" << endl;
			}
			else if (choice.find("delete") != string::npos)
			{
				string query = choice.substr(choice.find(" ")+1, string::npos); 		//separates find from query
				string forsearch = myHashMap.search(query);
				string name, city;
				getNameCity(name, city, forsearch);
				if (name==query)
				{
					myHashMap.erase(query);
					cout << "The record for "+query+" has been deleted" << endl;
				}
				else
					cerr<<"The record was not found"<<endl;
			}
			else if (choice.find("allinCity") != string::npos && (choice.size()>10))
			{
				string query = choice.substr(choice.find(" ")+1, string::npos);
				myHashMap.allinCity(query);
			}
			else if (choice.find("dump") != string::npos && (choice.size()>5))
			{
				string dFile = choice.substr(choice.find(" ")+1, string::npos);
				myHashMap.listCreate(dFile);
				cout << "The content of the hashmap has been dumpted into file " << dFile << " sorted by last names." << endl;
				
			}
			else if (choice.find("init") != string::npos )
				cout << "The data structure has already been initialized."<< endl;
			else 
				cerr<<"Incorrect input"<<endl;
		}
	}
	exit(0);

}