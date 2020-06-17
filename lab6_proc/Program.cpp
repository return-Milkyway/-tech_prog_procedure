#include "Program.h"
using namespace std;
	 
int In(container *head,ifstream &ifst) {
	struct container *last = Init2(In(ifst));
	struct container *tmp;
	if(last->cont == 0){
		cout << "No completed: incorrect input" << endl;
		return 0;
	}
	tmp = head->next; 
	head->next = last; 
	last->next = tmp; 
	head->prev = last;
	last->prev = head;
	while(!ifst.eof()) {			
		struct container *newItem = Init2(In(ifst));
		struct container *tmp;
		if(newItem->cont==0){
			cout<<"No completed: incorrect input"<<endl;
			return 0;
		}
		struct container *tmp2;		  
		tmp = last->next; 
		last->next = newItem;
		newItem->next = tmp;
		newItem->prev=last;
		head->prev=newItem;
		last=newItem;
	}
	return(1);
}
 	
int In(diagol &d, ifstream &ifst) {
	ifst.get();
	ifst >> d.razm;
	if ((d.razm) > (1000)||(d.razm) < (1)){
		return 0;	
	}
 	d.arr = new int*;
 	for (int count = 0; count < d.razm; count++){
 		d.arr[count] = new int[d.razm];
 	}
	for (int count = 0; count < d.razm; count++){
 		ifst >> d.arr[count][count];
 	}
 	return 1;
}

int In(down_triangle &dt, ifstream &ifst) {
	ifst.get();
	ifst >> dt.razm;
	if ((dt.razm) > (1000)||(dt.razm) < (1)){
		return 0;	
	}
 	dt.arr = new int;
 	int len = 0;
 	for (int j = 1; j < (dt.razm); j++) {
		len = len+  (dt.razm -j);		
	}
 	len = (dt.razm * dt.razm) - len;
	for (int count = 0; count < len; count++){
 		ifst >> dt.arr[count];
 	}
 	return 1;
}

int In(square &s, ifstream &ifst) {
	ifst.get();
	s.arr = new int*;
	ifst >> s.razm;
	if ((s.razm) > (1000)||(s.razm) < (1)){
		return 0;	
	}
	for (int count = 0; count < s.razm; count++) {
 		s.arr[count] = new int[s.razm];
 	}
	for (int count = 0; count < s.razm; count++) {
 		for (int count2 = 0; count2 < s.razm; count2++) {
			ifst >> s.arr[count][count2];
 		}
	}
 	return 1;
}
 
matr* In(ifstream &ifst) {
 	matr *mtrx;
 	int k;
 	ifst >> k;
 	int test = 1;
 	switch(k) {
 		case 1:
 			mtrx = new matr({});
 			mtrx->k = matr::key::SQUARE;
 			test = In(mtrx->s, ifst);
 			break;
 		case 2:
 			mtrx = new matr({});
 			mtrx->k = matr::key::DIAGOL;
 			test = In(mtrx->d, ifst);
 			break;
 		case 3:
 			mtrx = new matr({});
 			mtrx->k = matr::key::DOWN_TRIANGLE;
 			test = In(mtrx->dt, ifst);
 			break;
 		default:
			return 0;
 	}
 	if (test==0) {
		cout<< "No completed: incorrect input"<<endl;
		mtrx=0;
		return mtrx;
	}
 	ifst >> k;
 		switch(k) {
 			case 1:	
		 		mtrx->variant=matr::var_print::POSTROCHNO;
		 		return mtrx;
		 	case 2:	
		 		mtrx->variant=matr::var_print::POSTOLBZAM;
				 return mtrx;	
		 	case 3:	
		 		mtrx->variant=matr::var_print::ODNOMERNO;
				 return mtrx;	
			default:
 				mtrx->variant=matr::var_print::INCORRECT;
 				return mtrx;				 		
		 }
 }
 
void Out(square &s, ofstream &ofst) {
	ofst << "It is Square matrix: len = "
	 << s.razm << ", matrix = " << endl;
	 for (int count = 0; count < s.razm; count++){
		for (int count2 = 0; count2 < s.razm; count2++){
			ofst << s.arr[count][count2] << " ";
		}
		ofst << endl;
	}
}
 
void Out(diagol &d, ofstream &ofst) {
 	ofst << "It is Diagol Matrix: len = " << d.razm
	<< ", matrix: = " << endl;
	for (int count = 0; count < d.razm; count++){
		for (int count2 = 0;count2<d.razm; count2++){
			if (count != count2){
				ofst << "0 ";
			}
			else{
				ofst << d.arr[count][count] << " ";
			}
		}
		ofst << endl;
	}
 }
 
void Out(down_triangle &dt, ofstream &ofst) {
 	ofst << "It is Down Triangle Matrix: len = " << dt.razm
	<< ", matr: = " << endl;
	int i = 0;
	for (int count = 0; count < dt.razm; count++) {
		for (int count2 = 0; count2 < dt.razm; count2++) {
			if (count < count2) {
				ofst << "0 ";
			}
			else {
				ofst << dt.arr[i]<<" ";
			i = i + 1;
			}
		}
		ofst << endl;
	}
}
 
void Out(matr &mtrx, ofstream &ofst) {
	 switch(mtrx.k) {
	 	case matr::key::SQUARE:
	 		Out(mtrx.s, ofst);
	 		break;
	 	case matr::key::DIAGOL:
	 		Out(mtrx.d, ofst);
	 		break;
	 	case matr::key::DOWN_TRIANGLE:
	 		Out(mtrx.dt, ofst);
	 		break;
	 	default:
	 		ofst << "Incorrect figure!" << endl;
 	};
 	if (mtrx.variant == 0)
        ofst << "Print need POSTROCHNO"<<endl;
    else if (mtrx.variant == 1)
         ofst << "Print need POSTOLBZAM"<<endl;
    else if (mtrx.variant == 2)
         ofst << "Print need ODNOMERNO"<<endl;
    else 
         ofst << "Incorrect variant of print"<<endl;
 };
 
void Out(container *head,ofstream &ofst) { 
	struct container *p;
	p = head;
	int num = 0;
	do {
		num = num + 1;
		p = p->next; 
	} while (p != head); 
	ofst << "Container contains " << num-1 << " elements." << endl;
	if(head->next == head){
		return;
	}
  	p = head->next;
	do {
		matr *mtrx = p->cont;
		Out(*mtrx,ofst);
		p = p->next; 
	} while (p != head); 
}

struct container *  Init() {
	struct container *c = new container;
	c->next = c;
	c->prev = c; 
	return c;
}

struct container *  Init2(matr  *mtrx) {
	struct container *c = new container;
	c->cont = mtrx;
	c->next = c;
	c->prev = c; 
	return c;
}

struct container * Clear(container *lst){
	struct container *p;
	p = lst->next;
	do {
		struct container *temp;
		temp = p;
		while (temp->next != p) { 
			temp = temp->next;
		}
  		temp->next = p->next; 
		p = p->next;
	} while (p != lst);
}

int Sum(diagol& d) {
	int sum = 0;
	for (int count = 0; count < d.razm; count++){
		for (int count2 = 0; count2 < d.razm; count2++){
			if (count == count2){
				sum = sum + d.arr[count][count];
			}
		}
	}
	return sum;
}

int Sum(square& s) {
	int sum = 0;
	for (int count = 0; count < s.razm; count++){
		for (int count2 = 0; count2 < s.razm; count2++){
			sum = sum + s.arr[count][count2];
		}
	}
	return sum;
}

int Sum(down_triangle& dt) {
	int sum = 0;
	int len = 0;
 	for (int j = 1; j<  (dt.razm); j++) {
		len = len+(dt.razm - j);		
	}
 	len = (dt.razm * dt.razm) - len;
	for (int count = 0; count < len; count++){
 		sum = sum + dt.arr[count];
 	}
	return sum;
}

int Sum(matr &mtrx) {
	
	switch(mtrx.k) {
		case matr::key::SQUARE:
			return Sum(mtrx.s);
		case matr::key::DOWN_TRIANGLE:
			return Sum(mtrx.dt);
		case matr::key::DIAGOL:
	 		return Sum(mtrx.d);
	 	default:
	 		return -1;
	};
}

void Out_Sum(container *head,ofstream &ofst) {
	struct container *p;
	p = head;
	int num = 0;
	do {
		num = num + 1;
		p = p->next; 
	} while (p != head); 
	ofst << "Container contains " << num-1 	<< " elements." << endl;
	if(head->next == head) {
		return;
	}
  	p = head->next;
	do {
	    matr *mtrx = p->cont;
	    Out(*mtrx,ofst);
	    ofst<<"Sum_matr = " << Sum(*mtrx)  << endl;
	    p = p->next; 
	} while (p != head); 
}

void Out_Square(container *head,ofstream &ofst) {
	struct container *p;
	p = head;
	int num = 0;
	do {
	    num = num+1;
	    p = p->next; 
	} while (p != head); 
	ofst << "Container contains " << num-1 	<< " elements." << endl;
	ofst << "Only square" << endl;
	if(head->next == head){
		return;
	}
  	p = head->next;
	do {
		matr *mtrx = p->cont;
		switch(mtrx->k) {
	 	case matr::key::SQUARE:
	 		Out(mtrx->s, ofst);
	 	}
	    p = p->next; 
	} while (p != head); 
}

bool Compare(matr *first, matr *second) {
	try{
		return Sum(*first) < Sum(*second);
		throw -1;
	}
	catch (int){
		return(-1);
	}
}

int Sort(container* c){
 	struct container *p;
	p = c->next;
	int num = 0;
	do {
	    num = num + 1;
	    p = p->next; 
	} while (p != c); 
	p = c->next; 
	for (int count3 = 0; count3 < num; count3++){
		for (int count2 = 0; count2 < num-1; count2++){
			p = c->next;
			for(int tmp = 0; tmp < count2; tmp++){
				p = p->next;
			}
			int tmp = 0;	
			tmp = Compare(p->cont, p->next->cont);
			if (tmp == -1){
				return 0;
			}
			if(tmp){
	 			c = Swap(p,p->next,c);
	 		}	
		}
	}
	return 1;
}

struct container * Swap(struct container *lst1, struct container *lst2, struct container *head){
	struct container *prev1, *prev2, *next1, *next2;
	prev1 = head;
	prev2 = head;
	while (prev1->next != lst1)
    prev1 = prev1->next;
	while (prev2->next != lst2){
		prev2 = prev2->next;
	}
  	next1 = lst1->next; 
  	next2 = lst2->next;
	if (lst2 == next1){	
		lst2->next = lst1;
    	lst1->next = next2;
    	prev1->next = lst2;
  	}
	else if (lst1 == next2){
    	lst1->next = lst2;
    	lst2->next = next1;
    	prev2->next = lst2;
  	}
	else{
		prev1->next = lst2;
    	lst2->next = next1;
    	prev2->next = lst1;
    	lst1->next = next2;
  	}
  	if (lst1 == head)
    	return(lst2);
  	if (lst2 == head)
    	return(lst1);
  	return(head);
}
bool FileIsExist(string filePath) {
    bool isExist = false;
    std::ifstream fin(filePath.c_str());
    if(fin.is_open())
        isExist = true;
    fin.close();
    return isExist;
}
