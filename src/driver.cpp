#include "io_helpers.hpp"
#include "enumerate_cb_cliques.hpp"
//#include "cb3tree_dp.hpp"
int main(int argc, char * argv[]){
	std::cout << "Starting run..." << std::endl;
	CBEnumerator * enumerator = new CBEnumerator();
	enumerator->readDotBrackets("testfile.txt");
	//enumerator->printSecondary();
	enumerator->enumerate();
	enumerator->printReport();
    enumerator->printEnumerated();
}
