#include "io_helpers.hpp"
#include "enumerate_cb_cliques.hpp"

int main(int argc, char * argv[]){
	std::cout << "Starting run..." << std::endl;
	CBEnumerator * enumerator = new CBEnumerator();
	enumerator->readDotBrackets("testfile.txt");
	enumerator->printSecondary();
}
