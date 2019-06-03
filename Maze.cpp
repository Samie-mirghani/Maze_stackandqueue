// Shamsadean Mirghani
//
// Project 3
//

#ifndef MAZECPP
#define MAZECPP
#include "Maze.h"
#include <vector>
#include <stack>
#include <queue>
#include <deque> 
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;


    Maze::Maze() {
            
    }
    
    // read the file and set up maze
    Maze::Maze(string maze, int initialR, int initialC) {
       
     ifstream inFile;
     inFile.open(maze);

     string size;
     string line;
     string row;
     string col;
     stringstream tt;
     int rTemp;
     int cTemp;
     
     string dummyLine;
     getline(inFile, dummyLine);
     row = dummyLine[0];
     col = dummyLine[2];
     
     istringstream buffer_1(row);
     buffer_1 >> this->rows;
     
     istringstream buffer_2(col);
     buffer_2 >> this->cols;
     
     for(int q = 0; q < this->rows; q++) {
         for(int u = 0; u < this->cols; u++) {
            Space sp(' ' , q, u);
            grid[q][u] = sp;
            grid[q][u].setIntersection(false);
            grid[q][u].setVisited(false);
        }
    }
     
     while(getline(inFile, line)) {
         for(int i = 0; i < line.length(); i++) {
            row = line[0];
            col = line[2];
             
            istringstream buffer(row);
            buffer >> rTemp;
             
            istringstream buffer2(col);
            buffer2 >> cTemp;
    
            Space c('*', rTemp, cTemp);
            grid[rTemp][cTemp]=c;    
         }
     }
     
    setInitial(initialR,initialC);
    }
    
    bool Maze::setInitial(int r, int c) {
        if(r <= rows && c <= cols) {
            grid[r][c]= Space(' ', r, c);
            currentR = r;
            currentC = c;
            return true;
        }else {
             return false;    
        }
    }
    
    Space Maze::getSpace(int r, int c) {
        return grid[r][c];
    }
    
    stack<Space> Maze::getFreeNeighborsStack(Space currentSpace) {
        int spaceRow = currentSpace.getRow();
        int spaceCol = currentSpace.getCol();
        
        
        //Don't push a visited neighbor    
        
        if(spaceRow+1 < rows && grid[spaceRow + 1][spaceCol].getType() == ' ' && !grid[spaceRow + 1][spaceCol].getVisited()) {
            freeNeighborsStack.push(grid[spaceRow + 1][spaceCol]);
        }
        
        else if(spaceRow-1 > 0 && grid[spaceRow - 1][spaceCol].getType() == ' ' && !grid[spaceRow - 1][spaceCol].getVisited()) {
             freeNeighborsStack.push(grid[spaceRow - 1][spaceCol]);
        }
        
        else if(spaceCol+1 < cols && grid[spaceRow][spaceCol + 1].getType() == ' ' && !grid[spaceRow][spaceCol + 1].getVisited()) {
            freeNeighborsStack.push(grid[spaceRow][spaceCol + 1]);
        }
        
        else if(spaceCol-1 > 0 && grid[spaceRow][spaceCol - 1].getType() == ' ' && !grid[spaceRow][spaceCol - 1].getVisited()) {
            
            freeNeighborsStack.push(grid[spaceRow][spaceCol - 1]);
        }
         
        return freeNeighborsStack;
    }
    
    bool Maze::findExitStack(Space currentSpace) {
        if(currentSpace.getCol() == cols-1) {
            return true;
        }
        else { 
            return false;
        }
        
        
    }
    
    stack<Space> Maze::getSolutionStack() {
        printMaze();
        
        Space run = grid[currentR][currentC];
        freeNeighborsStack.push(run);
        while(!freeNeighborsStack.empty()) {
            
            bool done = findExitStack(run); 
            
            freeNeighborsStack= getFreeNeighborsStack(run);
            int row=run.getRow();
            int col=run.getCol();
            grid[row][col].setVisited(true);
            grid[row][col].setType('P');
            if(done) { 
                break;
            }
            
            if(run.getRow() == freeNeighborsStack.top().getRow() &&
            run.getCol() == freeNeighborsStack.top().getCol()){
               
                freeNeighborsStack.pop();
                
                run= freeNeighborsStack.top();
                
            }
            else{
                printMaze();
                
                run= freeNeighborsStack.top();
                
            }
            
        
        }
        while(!freeNeighborsStack.empty()){
            run=freeNeighborsStack.top();
            int row=run.getRow();
            int col=run.getCol();
            grid[row][col].setPath(true);
            freeNeighborsStack.pop();
        }
        printMaze();
        cout<<"Stack Solution\n";
        printStackMaze();
        return freeNeighborsStack;
        
        
        //set space to visited then move down the maze
        
    }
    
    
     /**
     * Given a specific space element, it returns a set of spaces around it that are free.
     *
     * @param currentSpace The space of which the neighbors need to be checked
     * @return Returns the set of free spaces neighboring in a queue structure
     * */
    
    queue<Space> Maze::getFreeNeighborsQueue(Space currentSpace) {
        int spaceRow = currentSpace.getRow();
        int spaceCol = currentSpace.getCol();
        
        
        //Don't push a visited neighbor    
        
        if(spaceRow+1 < rows && grid[spaceRow + 1][spaceCol].getType() == ' ' && !grid[spaceRow + 1][spaceCol].getVisited()) {
            freeNeighborsQueue.push(grid[spaceRow + 1][spaceCol]);
        }
        
        if(spaceRow-1 > 0 && grid[spaceRow - 1][spaceCol].getType() == ' ' && !grid[spaceRow - 1][spaceCol].getVisited()) {
             freeNeighborsQueue.push(grid[spaceRow - 1][spaceCol]);
        }
        
        if(spaceCol+1 < cols && grid[spaceRow][spaceCol + 1].getType() == ' ' && !grid[spaceRow][spaceCol + 1].getVisited()) {
            freeNeighborsQueue.push(grid[spaceRow][spaceCol + 1]);
        }
        
        if(spaceCol-1 > 0 && grid[spaceRow][spaceCol - 1].getType() == ' ' && !grid[spaceRow][spaceCol - 1].getVisited()) {
            
            freeNeighborsQueue.push(grid[spaceRow][spaceCol - 1]);
        }
         
        return freeNeighborsQueue;
    }

    bool Maze::findExitQueue(Space currentSpace) {
        if(currentSpace.getCol() == cols-1) {
            return true;
        }
        else { 
            return false;
        }
        
    }
    
    queue<Space> Maze::getSolutionQueue() {
        Space run;
        freeNeighborsQueue.push(grid[currentR][currentC]);
        while(!freeNeighborsQueue.empty()) {
            run= freeNeighborsQueue.front();
            int row=run.getRow();
            int col=run.getCol();
            grid[row][col].setVisited(true);
            grid[row][col].setType('P');
            freeNeighborsQueue.pop();
            
            bool done = findExitQueue(run); 
            
            
            
            if(done) { 
                break;
            }
            freeNeighborsQueue= getFreeNeighborsQueue(run);
            printMaze();
            
        
        }
        printMaze();
        cout<<endl;
        cout<<"Queue Solution\n";
        printMaze();
        return freeNeighborsQueue;
    }
    
    
    
    void Maze::errorFound(int n) {
        if(n == 0) { 
            cout << "The Maze is empty." << endl;    
        }
        else if(n == 1) {
            cout << "Invalid initial position." << endl;
        }
        else if(n == 2) {
            cout << "Invalid character." << endl;
        }
        else {
            exit(0);
        }
    }
    
    void Maze::printMaze() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++){
                cout << grid[i][j].getType();
                
                
            }
            cout << endl;
        }
        cout<< endl;
    }
    void Maze::printStackMaze() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++){
                if(grid[i][j].getPath()){
                    cout << grid[i][j].getType();
                }else{
                    if(grid[i][j].getType()=='P'){
                        cout << ' ';
                    }else{
                        cout << grid[i][j].getType();
                    }
                }
                
                
            }
            cout << endl;
        }
        cout<< endl;
    }
    
#endif