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
};

//======================================
// ACTUAL IMPLIMENTATION
//=====================================


#endif
