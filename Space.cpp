// Shamsadean Mirghani
//
// Project 3
//

#ifndef SPACECPP
#define SPACECPP
#include "Space.h"
#include "Maze.h"
#include <vector>
#include <iostream>
using namespace std;

        //make a set visited and a set intersection nethod

        Space::Space() {
            
        }
        
        Space::Space(char type, int row, int col) {
            
            listType.push_back(type);
            this->path=false;
            this->row = row;
            this->col = col;
            
        }
        
        int Space::getRow() {
            return row;
        }
        
        char Space::getType() {
            return listType.at(0);
        }
        
        void Space::setType(char type) {
            listType.at(0) = type; 
            
        }
        int Space::getCol() {
            return col;
        }
        
        void Space::setVisited(bool v) {
            visited = v;
            
        }
    
        bool Space::getVisited() {
            return visited;
        }
        
        bool Space::getIntersection() {
            return intersection;
        }
        
        
        void Space::setIntersection(bool inter) {
            intersection = inter;
        }
        
        bool Space::getPath(){
            return path;
        }
        void Space::setPath(bool path){
            this->path= path;
        }
        
        
        
        

#endif