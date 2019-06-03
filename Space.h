// Shamsadean Mirghani
//
// Project 3
//

#ifndef SPACEH
#define SPACEH
#include <string>
#include <vector>
using namespace std;
class Space {
    
    public:
        Space();
        Space(char type, int row, int col);
        int getRow();
        char getType();
        void setType(char type);
        int getCol();
        void setVisited(bool v);
        bool getVisited();
        bool getIntersection();
        void setIntersection(bool inter);
        bool getPath();
        void setPath(bool path);

    private:
        vector<char> listType;
        int row;
        int col;
        bool visited;
        bool path;
        bool intersection;
    
    
};
#endif