
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

bool FileIsExist1(string filePath){
    bool isExist = false;
    std::ifstream fin(filePath.c_str());
    if(fin.is_open())
        isExist = true;
 
    fin.close();
    return isExist;
}

struct square {
	int b;
	int** a;
};
 
struct diagol {
	int y;
	int** x;
};
struct down_triangle {
	int y;
	int* x;
};

struct matr {
	enum  key{SQUARE, DIAGOL,DOWN_TRIANGLE};
	key k;    
	union { 
		square s;
		diagol d;
		down_triangle dt;
	};
	enum var_print{POSTROCHNO,POSTOLBZAM,ODNOMERNO,INCORRECT};//1,2,3
	var_print variant;
};


 

struct container {
 	matr *cont;
 	struct container *next;
 	struct container *prev;
};

int In(container *lst,ifstream &ifst);
int In(square &a, ifstream &ifst);
int In(diagol &p, ifstream &ifst);
int In(down_triangle &dt,ofstream &ofst);
matr* In(ifstream &ifst);
void Out(diagol &p, ofstream &ofst);
void Out(square &a,ofstream &ofst);
void Out(down_triangle &dt,ofstream &ofst);
	
void Out(matr &m, ofstream &ofst);
void Out(container *lst,ofstream &ofst);
void Out_Square(container *lst,ofstream &ofst);
struct container *  Init();
struct container *  Init2(matr  *a);
struct container * Clear(container *lst);



int Sum(diagol* d);
int Sum(down_triangle* dt);
int Sum(square* s);
int Sum(matr *m);
void Out_Sum(container *lst,ofstream &ofst);
bool Compare(matr *first, matr *second);
int Sort(container* c);
struct container * swap(struct container *lst1, struct container *lst2, struct container *head);


 
