#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

bool FileIsExist(string filePath);

struct square {
	int razm;
	int** arr;
};
 
struct diagol {
	int razm;
	int** arr;
};

struct down_triangle {
	int razm;
	int* arr;
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

int In(container *head,ifstream &ifst);
int In(square &s, ifstream &ifst);
int In(diagol &d, ifstream &ifst);
int In(down_triangle &dt,ifstream &ifst);
matr* In(ifstream &ifst);
void Out(diagol &d, ofstream &ofst);
void Out(square &s,ofstream &ofst);
void Out(down_triangle &dt,ofstream &ofst);
void Out(matr &mtrx, ofstream &ofst);
void Out(container *head,ofstream &ofst);
void Out_Square(container *head,ofstream &ofst);
struct container * Init();
struct container * Init2(matr  *a);
struct container * Clear(container *lst);
int Sum(diagol* d);
int Sum(down_triangle* dt);
int Sum(square* s);
int Sum(matr *mtrx);
void Out_Sum(container *head,ofstream &ofst);
bool Compare(matr *first, matr *second);
int Sort(container* c);
struct container * Swap(struct container *lst1, struct container *lst2, struct container *head);


 
