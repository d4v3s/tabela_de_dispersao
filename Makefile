main:
	g++ -Wall -pedantic -std=c++11 main.cpp -o prog
	./prog < in_text.txt
clean:
	rm prog


