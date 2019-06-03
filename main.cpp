// Shamsadean Mirghani
//
// Project 3
//

#include <fstream>
#include <iostream>
#include <stack>
#include <queue>
#include "Maze.h"
using namespace std;

int main(int argc, char *argv[]) {
    

    if(argc != 2) {
        cout << "usage :" << argv[0] << " <filename>\n";
    }else {
        ifstream the_file(argv[1]);
        if(!the_file.is_open()) {
            cout << "Could not open the file\n";
        }else {
            
            string fileName = (string)argv[1];
            int r = 1;
            int c = 0;

            Maze maze(argv[1], 1, 0);
            Maze maze1(argv[1], 1, 0);
            stack<Space> stackSolution= maze.getSolutionStack();
            
            cout<< endl;
            
            queue<Space> queueSolution= maze1.getSolutionQueue();
            
            
           
        }
    } 
   
    
}
