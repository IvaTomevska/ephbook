Fonbook
is a program which loads lines with people's records and has several commands to inspect them.
It was written in C++ to be run on Linux operating system.

User first compiles the program by accessing the folder through terminal and typing "make".
This creates executable called "fonbook".

To invocate the program write:
./fonbook -f <input_file.txt>

All the lines have to follow this format and especially the number of spaces!
Delancey James 162 SaadiyatStr SaadiyatIsland AbuDhabi UAE +971343456569

Hashmap SIZE is set to be 20000.

There are several commands:
1. init:
	-> type the word into the terminal
	=> initializes the hashmap by inserting the data from <input_file.txt>
	=> can be run only once and no other command is allowed before init is written
2. add e:
	-> e is the whole record like:
	Delancey James 162 SaadiyatStr SaadiyatIsland AbuDhabi UAE +971343456569
	=> if e already exist it prints an error
3. find k:
	-> k is the name and surmane of the person we are looking for
	=> print outs the record for person k and the time it took it to find it
4. delete k:
	-> k is the name and surmane of the person we are looking for
	=> deletes the record for person k
5. load f:
	-> f is the file we want to load
	=> loads the file to our hashmap
6. dump f:
	-> f is the file we want to dump to
	=> dumps the content of the hashmap into file f
7. allinCity c:
	-> c is the city from which we want to have all the records
	=> saves all the records from city c to outputFile.txt
8. quit:
	=> exits the program and deallocates the memory

After a query is processed the program will ask the user for another query.

Fonbook was created by Magdalena Gunkova and Iva Tomevska as part of their Data Structures class at NYU Abu Dhabi in Fall 2018.

We would like to give credit to Khalid Mengal for providing us with the original MAKEFILE which we have modified for this project.
We have also used the starter code for lab6.
