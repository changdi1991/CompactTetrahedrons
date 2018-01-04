//======================================
// HEADER GUARD
//=====================================
#ifndef __IO_HELPERS__
#define __IO_HELPERS__
//======================================
// CLASS DEFINITIONS
//===================================== 
class IOHelper;

//======================================
// DEPENDENCIES
//===================================== 
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

//======================================
// CLASS PROTOTYPES
//===================================== 
class IOHelper {
    public:
        std::string readfile(std::string filename);
};

//======================================
// ACTUAL IMPLIMENTATION
//=====================================
//Class Methods
std::string IOHelper::readfile(std::string filename){
    std::ifstream ifs(filename);
    std::string str((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    return str;
}
#endif
