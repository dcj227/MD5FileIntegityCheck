MD5: md5.o main.o
	g++ -o MD5 md5.o main.o
md5.o: MD5.cpp
	g++ -c MD5.cpp -o md5.o
main.o: main.o
	g++ -c main.cpp

clean:
	rm md5.o main.o MD5
