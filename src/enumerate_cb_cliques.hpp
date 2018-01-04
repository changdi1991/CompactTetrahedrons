//======================================
// HEADER GUARD
//=====================================
#ifndef __ENUMERATE_CB_CLIQUES__   
#define __ENUMERATE_CB_CLIQUES__  
//======================================
// CLASS DEFINITIONS
//===================================== 
class CBEnumerator;

//======================================
// DEPENDENCIES
//=====================================
#include "io_helpers.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <map>

//======================================
// CLASS PROTOTYPES
//===================================== 
class CBEnumerator {
public:
	//Members
    IOHelper IO;
	std::vector<int*> secondary_edges;
    std::map<int,int> secondary_map;
    std::vector<int*> enumerated_cliques;
	std::vector<char> ntString;
	//Constructors
	CBEnumerator();   
	CBEnumerator(std::string dotbracket);
	CBEnumerator(std::string dotbracket, int n);
	CBEnumerator(std::vector<char> nts, std::string dotbracket, int n);
    //Class Methods
	void readDotBrackets(std::string filename);
	void readNtString(std::string filename);
    void printSecondary();
	void enumerate();
    void printEnumerated();
    void writeEnumerated(std::string outpath);
private:
    int length;
    void output(int x, int y, int z, int w);
};

//======================================
// ACTUAL IMPLIMENTATIONS
//=====================================
CBEnumerator::CBEnumerator(){}

/**
 * enumerate
 *      @Pre:
 *      * readDotBrackets has been called
 *      @Post:
 *      * all possible cliques have been enumerated and exist in an stl vector
 *
 *  Notes: This algorithm is directly derived from the CompactTetrahedron.pdf page 2.
 */
void CBEnumerator::output(int x, int y, int z, int w){
    int * tmpclq = new int[4];
    tmpclq[0] = x; tmpclq[1] = y;
    tmpclq[2] = z; tmpclq[3] = w;
    enumerated_cliques.push_back(tmpclq);
}
void CBEnumerator::enumerate(){
    std::cout << "enumerating all valid cliques..." << std::endl;
    for(int x = 0; x <= length-3; x++){
        for(int y = 0; y <= length-2; y++){
            if( (y == x+1) || (y == secondary_map[x])){
                for(int z = y+1; z <= length-1; z++){
                    for(int w = z+1; w <= length; w++){
                        output(x,y,z,w);
                    }//for ws
                }//for zs
            }//if x-y cWW or bb
            else{
                for(int z = y+1; z <= length-1; z++){
                    if((z == y+1) ||
                       (z == secondary_map[x]) ||
                       (z == secondary_map[y])){
                        for(int w = z+1; w <= length; w++){
                            output(x,y,z,w);
                        }//for ws
                    }//if x-z or y-z is cWW or bb
                    else{
                        output(x,y,z,z+1);
                        if(secondary_map[x] > (z+1)){
                            output(x,y,z,secondary_map[x]);
                        }
                        if(secondary_map[y] > (z+1)){
                            output(x,y,z,secondary_map[y]);
                        }
                        if(secondary_map[z] > (z+1)){
                            output(x,y,z,secondary_map[z]);
                        }
                    }//else
                }//for zs
            }//else
        }//for ys
    }//for xs
}

/**
 * printSecondary
 *      @Pre:
 *      * readDotBrackets has been called
 *      @Post:
 *      * secondary edge constraints printed to console
 */
void CBEnumerator::printSecondary(){
    for(std::vector<int*>::iterator it = secondary_edges.begin(); it != secondary_edges.end(); ++it) {
        std::cout << (*it)[0] << "--" << (*it)[1] << std::endl;
    }
}

/**
 * [Subject to optimization later]
 * readDotBrackets - 
 *      @Pre:
 *      * file only contains dot-bracket notation or dot-bracket and seq
 *      * dot-bracket is valid
 *      * file exists
 *      @Post:
 *      * secondary_edges member is filled with cWW edges
 *      * secondary_map member is filled with cWW edges
 *  Notes:
 *      Result of this method is checkable with "print_secondary"
 */
void CBEnumerator::readDotBrackets(std::string filename){
    std::string dbstring = IO.readfile(filename);
    std::string validdb;
    for(char x : dbstring){
        if(x != '(' & x != ')' & x != '.' & x != '[' & x != ']'){
            continue;
        }
        else{
            validdb.append(1, x);
        }
    }
    
    length = validdb.size();
    
    // Use the validated dot-bracket string to create a graph
    int current_index = 0;
    for(char x : validdb){
        char searching_for;
        int openp = 0; int openb = 0;
        if(x == '.' || x == ')' || x == ']'){current_index++; continue;}
        else if(x == '('){
            searching_for = ')'; openp++;
        }
        else if(x == '['){searching_for = ']'; openb++;}
        int check_index = 0;
        for(char y : validdb){
            if(check_index > current_index){
                if(y == '.'){check_index++; continue;}
                else if(y == '('){openp++;}
                else if(y == '['){openb++;}
                else if(y == ')'){openp--;}
                else if(y == ']'){openb--;}
                if(y == searching_for){
                    if(searching_for == ')' && openp == 0){
                        // Fill edge list
                        int * edge = new int[2];
                        edge[0] = current_index; edge[1] = check_index;
                        secondary_edges.push_back(edge);
                        // Fill edge map
                        std::pair<int, int> PAIR1;
                        PAIR1.first = current_index;
                        PAIR1.second = check_index;
                        std::pair<int, int> PAIR2 ;
                        PAIR2.first = check_index;
                        PAIR2.second = current_index;
                        secondary_map.insert(PAIR1);
                        secondary_map.insert(PAIR2);
                        break;
                    }
                    else if(searching_for == ']' && openb == 0){
                        // Fill edge list
                        int * edge = new int[2];
                        edge[0] = current_index; edge[1] = check_index;
                        secondary_edges.push_back(edge);
                        // Fill edge map
                        std::pair <int, int> PAIR1 ;
                        PAIR1.first = current_index;
                        PAIR1.second = check_index;
                        std::pair <int, int> PAIR2 ;
                        PAIR2.first = check_index;
                        PAIR2.second = current_index;
                        secondary_map.insert(PAIR1);
                        secondary_map.insert(PAIR2);
                        break;
                    }
                }
            }
            check_index++;
        }
        current_index++;
    }
    
}


#endif 
