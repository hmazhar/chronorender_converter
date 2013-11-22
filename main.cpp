#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

std::string ZeroPadNumber(int num, int pad)
{
    std::ostringstream ss;
    ss << std::setw( pad ) << std::setfill( '0' ) << num;
    return ss.str();
}




int main(int argc, char * argv[]){
	string prefix,filetype;
	int pad_zeros;
	int start,end;

	prefix = argv[1];
	pad_zeros = atoi(argv[2]);
	filetype= argv[3];

	start = atoi(argv[4]);
	end = atoi(argv[5]);


for(int i=start; i<end; i++){
	stringstream fname;
	fname<<prefix<<ZeroPadNumber(i,pad_zeros)<<filetype;
	cout<<fname.str();
}

}