#include "Program.h"
//using namespace std;
int main(int argc, char* argv[]) {
	if(argc !=3) {
		cout << "incorrect command line! "
		"Waited: command infile outfile" << endl;
		return(1);
	}
	if(FileIsExist2(argv[1])){}
	else{
		cout << "File is not exist!\n";
		return 1;
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	//ifstream ifst("in.txt");
	//ofstream ofst("out.txt");
	cout << "Start"<< endl;
	container* c;
	c= Init();
	int test=1;
	test=In(c, ifst);
	if (test==0) {
		return 1;
	}
	ofst << "Filled container. " << endl;
	//Out(c, ofst);
	test=Sort(c);
	if (test==0) {
		cout<< "incorrect input"<<endl;
		return 1;
	}
	Out_Sum(c, ofst);
	Out_Square(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop"<< endl;
	return 0;
}

