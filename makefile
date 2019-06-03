run: main.cpp Maze.o Space.o
	g++ -std=c++11 main.cpp Maze.o Space.o
Maze.o:Maze.cpp
	g++ -std=c++11 -c Maze.cpp
Space.o:Space.cpp
	g++ -std=c++11 -c Space.cpp
clean:
	rm *.o a.out
