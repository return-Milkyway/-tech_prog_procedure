
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

 	struct square 
	{
		int b;
		int** a;
 	};
 
 	struct diagol 
	{
		int y;
		int** x;
  	};
  	
	struct matr {
	enum  key{SQUARE, DIAGOL};
	key k;    
	union 
	{ 
		square s;
		diagol d;
	};
	enum var_print{POSTROCHNO,POSTOLBZAM,ODNOMERNO,INCORRECT};//1,2,3
	var_print variant;
};
	
	 struct container
 	{
 		matr *cont;
 		struct container *next;
 		struct container *prev;
 	};
 	
 	struct container* In(container *lst,ifstream &ifst);
	void In(square &a, ifstream &ifst);
	void In(diagol &p, ifstream &ifst);
	matr* In(ifstream &ifst);
	void Out(diagol &p, ofstream &ofst);
	void Out(square &a,ofstream &ofst);
	void Out(matr &m, ofstream &ofst);
	void Out(container *lst,ofstream &ofst);
	struct container *  Init();
	struct container *  Init2(matr  *a);
	struct container * Clear(container *lst);

 	
	


 
