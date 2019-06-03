// Shamsadean Mirghani
//
// Project 3
//

#ifndef MAZEH
#define MAZEH
#include <stack>
#include <queue>
#include <vector>
#include "Space.h"
using namespace std;
class Maze {
    
    public:
        Maze();
        Maze(string maze, int initialR, int initialC);
        bool setInitial(int r, int c);
        Space getSpace(int r, int c);
        stack<Space> getFreeNeighborsStack(Space currentSpace);
        bool findExitStack(Space currentSpace);
        stack<Space> getSolutionStack();
        queue<Space> getFreeNeighborsQueue(Space currentSpace);
        bool findExitQueue(Space currentSpace);
        queue<Space> getSolutionQueue();
        void errorFound(int n);
        void printMaze();
        void printStackMaze();
        
        
        
    private:
        Space grid [100][100]; 
        int rows;
        int cols;
        int currentR;
        int currentC;
        stack<Space> freeNeighborsStack;
        stack<Space> solutionStack;
        queue<Space> freeNeighborsQueue;
        queue<Space> solutionQueue;
    
};
#endif