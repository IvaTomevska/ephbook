#include<iostream>
#include<fstream>
#include<cmath>
#include<chrono>
#include<sstream>
#include<list>
#include<algorithm>

#include "hashimplement.h"
#include "evaluation.h"

using namespace std;
using namespace std::chrono;



HashNode::HashNode(string key, string city, string value)
{
	this->key = key;
	this->city = city;
	this->value = value;
}
string HashNode::getKey()
{
	return this->key;
}
string HashNode::getCity()
{
	return this->city;
}
string HashNode::getValue()
{
	return this->value;
}
void HashNode::changeValue(string newValue)
{
	this->value=newValue;
	this->city=newValue;
	this->key=newValue;
}


HashMap::HashMap(int capacity)
{
	nodeArray = new HashNode*[capacity];
	this->capacity = capacity;
	this->size = 0;
}

int HashMap::getCapacity()
{
	return this->capacity;
}
		
int HashMap::hashCode(const string key)
{
	//Create Hashcode for key
	int keySum=0; 
	for (int i=0; i<key.size(); i++)
	{
		keySum+= (int)key[i]*i; // casting ch to its ascii value
	}
	keySum= keySum*key.size();
	return keySum%(this->capacity);
}
		
void HashMap::insert(const string key, const string city, const string value)
{
	// Insert the key and value in Hash Map using Linear Probling
	int arIndex= hashCode(key);
	HashNode* temp= new HashNode(key, city, value);
	while(nodeArray[arIndex]!= NULL && nodeArray[arIndex]->getValue()!= "deleted")	
	{												// co mom doprdele robic jak se mi to zapelni
		arIndex= (arIndex+1)%this->capacity;
	}
	nodeArray[arIndex]= temp;
	this->size++; 
}

string HashMap::search(const string key)
{
	// Search for a key in HashMap and return its value
	int cnt= 0;
	int fIndex= hashCode(key);
	while (nodeArray[fIndex]!=NULL && cnt<= this->capacity)
	{
		if (nodeArray[fIndex]->getKey()==key)
		{
			return string(nodeArray[fIndex]->getValue());
		}
		else {
				cnt++;
				fIndex= (fIndex+1)%this->capacity;
			}
	}
	return "not found";
				//+"count: "+std::to_string(cnt);
}

void HashMap::allinCity(const string city)
{
	ofstream outFile;
	outFile.open("outputFile.txt");
	int cnt = 0;
	for (int i=0; i<this->capacity; i++)
	{
		if (nodeArray[i] != NULL && nodeArray[i]->getCity() == city)			//checks for NULL first so that getCity doesn't crash
		{		
			outFile << nodeArray[i]->getValue() << endl;
			cnt++;
		}
	}
	outFile.close();
	if (cnt==0)
		cerr << "City not found" << endl;
	else
		cout << "The residents of "+city+" have been saved to file outputFile.txt" << endl;

}
		
void HashMap::erase(const string name)
{
	int cnt= 0;
	int fIndex= hashCode(name);
	while (nodeArray[fIndex]!=NULL && cnt<= this->capacity)
	{
		if (nodeArray[fIndex]->getKey()==name)
		{
			nodeArray[fIndex]->changeValue("deleted");
			this->size--;
			break;
		}
		else 
			fIndex=(fIndex+1)%this->capacity;
		cnt++;
	}
}
void HashMap::listCreate (string& fileName)
{
	ofstream dumpFile;
	list<string> dumpPrep;
	dumpFile.open(fileName);
	for (int i=0; i<this->capacity; i++)
	{
		if (nodeArray[i] != NULL && nodeArray[i]->getValue()!= "deleted")			//checks for NULL first so that getCity doesn't crash
		{		
			string nameSwap2;
			string valOrig=nodeArray[i]->getValue();
			swapNames(valOrig,nameSwap2);
			dumpPrep.push_back(nameSwap2);
		}
	}
	dumpPrep.sort();
	while (!dumpPrep.empty())
	{
		dumpFile << dumpPrep.front() << endl; //CHANGE to all elements in the list going there
		dumpPrep.pop_front();
	}
	dumpFile.close();
}		

int HashMap::getSize()
{
	return this->size;
}

HashMap::~HashMap()
{
	delete[] this->nodeArray;
}