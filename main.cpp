#include <iostream> 

#include <fstream> 
#include <iomanip>
#include "token.h"
#include "scanner.h"
#include "testTree.h" 
#include "parser.h"
#include "staticSemantics.h"  

using namespace std; 

int main(int argc, char *argv[]) {
	ifstream inFile; 
	istream *input_stream;  
	string file; 
	
	if (argc > 2) { 
		cout << "Too many arguments" << endl; 
		return 1; 
	}

	if (argc == 1) {
        	input_stream = &cin; 
    	} else {
		file = string(argv[1]); 
		if (file.substr(file.size()-4) != ".f23") {
                        file += ".f23";
                }
		inFile.open(file); 
		if (!inFile.is_open()) { 
			cout << "ERROR: Cannot find requested file." << endl; 
			return 1; 
		} else { 
			input_stream = &inFile; 
		} 
	} 

	getStack stackID;
	// Calling Parser
	node *root = parser(*input_stream); 
	cout << "Starting static semantics... " << endl;
	staticSemantics(root, stackID);
	cout << "Finished static semantics with no errors!" << endl;
	
	
	if (inFile.is_open()) { 
		inFile.close(); 
	} 

	return 0; 
}

