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

void getNameCity (string &name, string &city, string &wValue) //passing by reference
{	
	string temp;
	istringstream strm(wValue);
	strm >> name >> temp;
	name += " "+temp;
	strm >> temp >> temp >> city;
}

void load(string& file, HashMap& myHashMap)
{
	ifstream fin;
	fin.open(file);
	if(!fin){
		cerr<<"Can not open the file...!" << endl;
		exit(-1); 
	}
			
	while(true)
	{
		string name, city, wValue;
		getline(fin,wValue);					// take the whole line and make key and city later
		if (fin.eof())							//otherwise it takes an empty line
			break;
		getNameCity(name, city, wValue);		// finds name for the key and city
		myHashMap.insert(name, city, wValue);	// line added to hashmap
	}
	fin.close();
	cout<<"Hash Map size = "<<myHashMap.getSize()<<endl;
}

void swapNames (string& wValue, string& nameSwap)
{
	string temp, temp2;
	istringstream strm(wValue);
	strm >> temp >> temp2;
	nameSwap= temp2+" "+temp+wValue.substr(wValue.find(temp2)+temp2.size(),string::npos);	//record with first and last name swapped
}	