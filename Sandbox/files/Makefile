.PHONY: clean

all: files.out colors.out

files.out: files.cpp
	g++ -o $@ -std=c++17 -Wall $<

colors.out: colors.cpp
	g++ -o $@ -std=c++17 -Wall $<

clean:
	rm *.out
