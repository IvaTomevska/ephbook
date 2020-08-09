#ifndef HASHIMPLEMENT_H
#define HASHIMPLEMENT_H

#include<iostream>
#include<fstream>
#include<cmath>
#include<chrono>
#include<sstream>
#include<list>
#include<algorithm>

using namespace std;
using namespace std::chrono;

class HashNode
{
	private:
		string key;
		string city;
		string value;
	public:
		HashNode(string key, string city, string value);

		string getKey();

		string getCity();

		string getValue();

		void changeValue(string newValue);


};

class HashMap
{
	private:
		HashNode **nodeArray;		// Array of Pointers to Hash Nodes
		int size;					//Current Size of HashMap
		int capacity;				// Total Capacity of HashMap
	public:
		HashMap(int capacity);

		int getCapacity();
		
		int hashCode(const string key);
		
		void insert(const string key, const string city, const string value);

		string search(const string key);

		void allinCity(const string city);

		void erase(const string name);

		void listCreate (string& fileName);

		int getSize();

		~HashMap();
};

#endif