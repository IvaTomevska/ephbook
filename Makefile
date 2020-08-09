fonbook: fonbook.o evaluation.o hashimplement.o
	g++ fonbook.o evaluation.o hashimplement.o -o fonbook
fonbook.o: fonbook.cpp
	g++ -c fonbook.cpp
evaluation.o: evaluation.cpp evaluation.h
	g++ -c evaluation.cpp
hashimplement.o: hashimplement.cpp hashimplement.h
	g++ -c hashimplement.cpp

clean:
	rm *.o fonbook

