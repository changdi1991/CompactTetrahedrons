//======================================
// HEADER GUARD
//=====================================
#ifndef __CB3TREE_DP__
#define __CB3TREE_DP__
//======================================
// CLASS DEFINITIONS
//=====================================
class CB3TreeDP;

//======================================
// DEPENDENCIES
//=====================================
#include "enumerate_cb_cliques.hpp"

//======================================
// CLASS PROTOTYPES
//=====================================
class CB3TreeDP {
public:
    CB3TreeDP();
    void top_down_M_score(int v1, int v2, int v3, int* interval);
    void dp_M_score(int v1, int v2, int v3, int* interval);
private:
    void td_case1(int v1, int v2, int v3, int* interval);
    void td_case2(int v1, int v2, int v3, int* interval);
    void td_case3(int v1, int v2, int v3, int* interval);
    void td_case4(int v1, int v2, int v3, int* interval);
    void random_score(int v1, int v2, int v3, int v4);
};

//======================================
// ACTUAL IMPLIMENTATION
//=====================================
void CB3TreeDP::top_down_M_score(int v1, int v2, int v3, int * interval){
    if(interval[0] == 1){
        this->td_case1(v1,v2,v3, interval);
    }
    if(interval[1] == 1){
        this->td_case2(v1,v2,v3, interval);
    }
    if(interval[2] == 1){
        this->td_case3(v1,v2,v3, interval);
    }
    if(interval[3] == 1){
        this->td_case4(v1,v2,v3, interval);
    }
}
/**
 * Called, given that i_1 was 1 in previous step.
 */
void CB3TreeDP::td_case1(int v1, int v2, int v3, int* interval){
    //Enumerating all possible solutions to the constraints
    //First, we think about the ways to satisfy the enumerated x constraints:
    std::string xs[] = {"100", "010", "001"};
    //Next, we think about the ways to satisfy the y constraint:
    std::string ys[] = {"10", "01"};
    //Next, we think about the ways to satisfy the 2 constraint:
    std::string * twos;
    if(interval[1] == 1){
        std::string twos[] = {"10", "01"};
    }
    else{
        std::string twos[] = {"00", "11"};
    }
    //Next, we think about the ways to satisfy the 3 constraint
    std::string * threes[];
    if(interval[2] == 1){
        std::string threes[] = {"10", "01"};
    }
    else{
        std::string threes[] = {"00", "11"};
    }
    //Next, we think about the ways to satisfy the 4 constraint
    std::string * fours[];
    if(interval[2] == 1){
        std::string fours[] = {"100", "010", "001"};
    }
    else{
        std::string fours[] = {"000", "111", "101", "110", "011"};
    }
    
    //Assemble all possibilities (worst case 3*2^3*5):
    /*for(x : xs){
        for(y : ys){
            for(two: twos){
                for(three: threes){
                    for(four: fours){
                        char* A = {x[0], y[0], two[1], 0};
                        char* B = {x[1], y[1], 0, four[0]};
                        char* C = {x[2], 0, three[0], four[1]};
                        char* D = {0, two[0], three[1], four[2]}
                    }
                }
            }
        }
    }*/
}

/**
 * Called, given that i_2 was 1 in previous step.
 
void CB3TreeDP::td_case2(int v1, int v2, int v3, int* interval){
    //Enumerating all possible solutions to the constraints
    //First, we think about the ways to satisfy the enumerated x constraints:
    std::string xs[] = {"10", "01"};
    //Next, we think about the ways to satisfy the y constraint:
    std::string ys[] = {"10", "01"};
    //Next, we think about the ways to satisfy the 1 constraint:
    std::string ones[];
    if(interval[0] == 1){
        ones = {"100", "010", "001"};
    }
    else{
        ones =  {"000", "111", "101", "110", "011"};
    }
    //Next, we think about the ways to satisfy the 3 constraint
    std::string threes[];
    if(interval[2] == 1){
        threes = {"10", "01"};
    }
    else{
        threes = {"00", "11"};
    }
    //Next, we think about the ways to satisfy the 4 constraint
    std::string fours[];
    if(interval[2] == 1){
        fours = {"100", "010", "001"};
    }
    else{
        fours = {"000", "111", "101", "110", "011"};
    }
}

/**
 * Called, given that i_3 was 1 in previous step.
 
void CB3TreeDP::td_case3(int v1, int v2, int v3, int* interval){
    //Enumerating all possible solutions to the constraints
    //First, we think about the ways to satisfy the enumerated x constraints:
    std::string xs[] = {"10", "01"};
    //Next, we think about the ways to satisfy the y constraint:
    std::string ys[] = {"10", "01"};
    //Next, we think about the ways to satisfy the 1 constraint:
    std::string ones[];
    if(interval[0] == 1){
        ones = {"100", "010", "001"};
    }
    else{
        ones =  {"000", "111", "101", "110", "011"};
    }
    //Next, we think about the ways to satisfy the 3 constraint
    std::string twos[];
    if(interval[1] == 1){
        twos = {"10", "01"};
    }
    else{
        twos = {"00", "11"};
    }
    //Next, we think about the ways to satisfy the 4 constraint
    std::string fours[];
    if(interval[2] == 1){
        fours = {"100", "010", "001"};
    }
    else{
        fours = {"000", "111", "101", "110", "011"};
    }
}

/**
 * Called, given that i_4 was 1 in previous step.
 
void CB3TreeDP::td_case4(int v1, int v2, int v3, int* interval){
    //Enumerating all possible solutions to the constraints
    //First, we think about the ways to satisfy the enumerated x constraints:
    std::string xs[] = {"10", "01"};
    //Next, we think about the ways to satisfy the y constraint:
    std::string ys[] = {"100", "010", "001"};
    //Next, we think about the ways to satisfy the 1 constraint:
    std::string ones[];
    if(interval[0] == 1){
        ones = {"100", "010", "001"};
    }
    else{
        ones =  {"000", "111", "101", "110", "011"};
    }
    //Next, we think about the ways to satisfy the 3 constraint
    std::string twos[];
    if(interval[1] == 1){
        twos = {"10", "01"};
    }
    else{
        twos = {"00", "11"};
    }
    //Next, we think about the ways to satisfy the 4 constraint
    std::string threes[];
    if(interval[2] == 1){
        threes = {"10", "01"};
    }
    else{
        threes = {"00", "11"};
    }
}
*/
#endif
