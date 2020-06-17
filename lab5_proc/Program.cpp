#include "Program.h"
using namespace std;
	 
int In(container *lst,ifstream &ifst){
		struct container *last = Init2(In(ifst));
		struct container *tmp;
		if(last->cont==0){
			cout<<"Incorrect input"<<endl;
			return 0;
		}
		tmp = lst->next; 
		lst->next = last; 
		last->next = tmp; 
		lst->prev=last;
		last->prev=lst;
	while(!ifst.eof()) {			
		  struct container *newItem = Init2(In(ifst));
		  struct container *tmp;
		  if(newItem->cont==0){
			cout<<"Incorrect input"<<endl;
			return 0;
		}
		  struct container *tmp2;		  
		  tmp = last->next; 
		  last->next = newItem;
		  newItem->next = tmp;
		  newItem->prev=last;
		  lst->prev=newItem;
		  last=newItem;
		}
		return(1);
}
 	
int In(diagol &a, ifstream &ifst) {
	ifst.get();
	ifst>>a.y;
	if ((a.y)>(1000)){
	return 0;	
	}
 	a.x=new int*;
 	for (int count=0;count<a.y;count++){
 		a.x[count]=new int[a.y];
 	}
	for (int count=0;count<a.y;count++){
 		ifst>>	a.x[count][count];
 	}
 	return 1;
}

int In(down_triangle &dt, ifstream &ifst) {
	ifst.get();
	ifst>>dt.y;
	if (dt.y>(1000)){
	return 0;	
	}
 	dt.x=new int;
 	int len=0;
 	for (int j=1;j<(dt.y);j++) {
		len=len+(dt.y -j);		
	}
 	len=(dt.y*dt.y)-len;
	for (int count=0;count<len;count++){
 		ifst>>	dt.x[count];
 	}
 	return 1;
}

int In(square &p, ifstream &ifst){
	ifst.get();
	p.a=new int*;
	ifst>>p.b;
	if (p.b>(1000)){
	return 0;	
	}
	for (int count=0;count<p.b;count++){
 		p.a[count]=new int[p.b];
 	}
	for (int count=0;count<p.b;count++){
 		for (int count2=0;count2<p.b;count2++){
 		ifst>>	p.a[count][count2];
 	}
 	}
 	return 1;
 }
 
matr* In(ifstream &ifst) {
 	matr *sp;
 	int k;
 	ifst >> k;
 	int test=1;
 	switch(k) {
 		case 1:
 			sp = new matr({});
 			sp->k = matr::key::SQUARE;
 			test=In(sp->s, ifst);
 		//	return sp;
 			break;
 		case 2:
 			sp = new matr({});
 			sp->k = matr::key::DIAGOL;
 			test=In(sp->d, ifst);
 			break;
 		case 3:
 			sp = new matr({});
 			sp->k = matr::key::DOWN_TRIANGLE;
 			test=In(sp->dt, ifst);
 			break;
 		default:
 		return 0;
 	}
 	if (test==0) {
	cout<< "incorrect input"<<endl;
	sp=0;
	return sp;
	}
 	ifst >> k;
 		switch(k) {
 			case 1:	
		 		sp->variant=matr::var_print::POSTROCHNO;
		 		return sp;
		 	case 2:	
		 		sp->variant=matr::var_print::POSTOLBZAM;
				 return sp;	
		 	case 3:	
		 		sp->variant=matr::var_print::ODNOMERNO;
				 return sp;	
			default:
 				sp->variant=matr::var_print::INCORRECT;
 				return sp;		
		 		
		 }
 }
 
 void Out(square &p, ofstream &ofst){
	ofst << "It is Square matrix: len = "
	 << p.b << ", matr = " << endl;
	 for (int count=0;count<p.b;count++){
		for (int count2=0;count2<p.b;count2++){
			ofst<<p.a[count][count2]<<" ";
		}
		ofst<<endl;
	}
 }
 
void Out(diagol &a, ofstream &ofst) {
 	ofst << "It is Diagol Matrix: len = " << a.y
	<< ", matr: = " <<endl;
	for (int count=0;count<a.y;count++){
		for (int count2=0;count2<a.y;count2++){
			if (count!=count2){
				ofst<<"0 ";
			}
			else{
			ofst<<a.x[count][count]<<" ";
			}
		}
		ofst<<endl;
	}
 }
 
void Out(down_triangle &dt, ofstream &ofst) {
 	ofst << "It is Down Triangle Matrix: len = " << dt.y
	<< ", matr: = " <<endl;
	int i=0;
	for (int count=0;count<dt.y;count++){
		for (int count2=0;count2<dt.y;count2++){
			if (count<count2){
				ofst<<"0 ";
			}
			else{
			ofst<<dt.x[i]<<" ";
			i=i+1;
			}
		}
		ofst<<endl;
	}
 }
 
void Out(matr &s, ofstream &ofst) {
	 switch(s.k) {
	 	case matr::key::SQUARE:
	 		Out(s.s, ofst);
	 		break;
	 	case matr::key::DIAGOL:
	 		Out(s.d, ofst);
	 		break;
	 	case matr::key::DOWN_TRIANGLE:
	 		Out(s.dt, ofst);
	 		break;
	 	default:
	 		ofst << "Incorrect figure!" << endl;
 	};
 	if (s.variant == 0)
        ofst << "Print need POSTROCHNO"<<endl;
    else if (s.variant == 1)
         ofst << "Print need POSTOLBZAM"<<endl;
    else if (s.variant == 2)
         ofst << "Print need ODNOMERNO"<<endl;
    else 
         ofst << "Incorrect variant of print"<<endl;
 };
 
void Out(container *lst,ofstream &ofst){ 
	struct container *p;
	p=lst;
	int num=0;
	  do {
	    num=num+1;
	    p = p->next; 
	  } while (p != lst); 
	  ofst<<"Container contains " << num-1 	<< " elements." << endl;
  	if(lst->next==lst){
		return;
	}
  	p = lst->next;
	  do {
	    matr *s=p->cont;
	    Out(*s,ofst);
	    p = p->next; 
	  } while (p != lst); 
}

struct container *  Init(){
	struct container *c = new container;
	c->next = c;
	c->prev=c; 
	return c;
}

struct container *  Init2(matr  *a) {
  struct container *c = new container;
  c->cont = a;
  c->next = c;
  c->prev=c; 
  return c;
}

struct container * Clear(container *lst){
	struct container *p;
	p=lst->next;
	do {
		struct container *temp;
		temp = p;
		while (temp->next != p) { 
				temp = temp->next;
			}
  		temp->next = p->next; 
		p = p->next; // переход к следующему узлу
	} while (p != lst); // условие окончания обхода
}

int Sum(diagol& d) {
	int sum=0;
	for (int count=0;count<d.y;count++){
		for (int count2=0;count2<d.y;count2++){
			if (count==count2){
			sum=sum+d.x[count][count];
			}
		}
	}
	return sum;
}

int Sum(square& s) {
	int sum=0;
	for (int count=0;count<s.b;count++){
		for (int count2=0;count2<s.b;count2++){
			sum=sum+s.a[count][count2];
		}
	}
	return sum;
}

int Sum(down_triangle& dt) {
	int sum=0;
	int len=0;
 	for (int j=1;j<(dt.y);j++) {
		len=len+(dt.y -j);		
	}
 	len=(dt.y*dt.y)-len;
	for (int count=0;count<len;count++){
 		sum = sum + dt.x[count];
 	}
	return sum;
}


int Sum(matr &m){	
	
	switch(m.k) {
	case matr::key::SQUARE:
		return Sum(m.s);
	case matr::key::DOWN_TRIANGLE:
		return Sum(m.dt);
	case matr::key::DIAGOL:
 		return Sum(m.d);
 	default:
 		return -1;
	};
}

void Out_Sum(container *lst,ofstream &ofst){
	struct container *p;
	p=lst;
	int num=0;
	  do {
	    num=num+1;
	    p = p->next; 
	  } while (p != lst); 
	  ofst<<"Container contains " << num-1 	<< " elements." << endl;
  	if(lst->next==lst){
		return;
	}
  	p = lst->next;
	  do {
	    matr *s=p->cont;
	    Out(*s,ofst);
	    ofst<<"Sum_matr = " << Sum(*s)  << endl;
	    p = p->next; 
	  } while (p != lst); 
}

void Out_Square(container *lst,ofstream &ofst){
	struct container *p;
	p=lst;
	int num=0;
	do {
	    num=num+1;
	    p = p->next; 
	} while (p != lst); 
	ofst<<"Container contains " << num-1 	<< " elements." << endl;
	ofst<<"Only square"<< endl;
  	if(lst->next==lst){
		return;
	}
  	p = lst->next;
	do {
		matr *s=p->cont;
		switch(s->k) {
	 	case matr::key::SQUARE:
	 		Out(s->s, ofst);
	 	}
	 	//	break;
	    //Out(*s,ofst);
	    p = p->next; 
	} while (p != lst); 
	
}

bool Compare(matr *first, matr *second) {
	try
{
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
	int num=0;
	do {
	    num=num+1;
	    p = p->next; 
	} while (p != c); 
	p = c->next; 
	for (int count3=0;count3<num;count3++){
		for (int count2=0;count2<num-1;count2++){
			p=c->next;
			for(int tmp=0;tmp<count2;tmp++){
				p=p->next;
			}
			int tmp=0;	
			tmp=Compare(p->cont, p->next->cont);
			if (tmp==-1){
				return 0;
			}
			if(tmp){
	 			c=swap(p,p->next,c);
	 		}	
		}
	}
	 return 1;
}

struct container * swap(struct container *lst1, struct container *lst2, struct container *head){
	struct container *prev1, *prev2, *next1, *next2;
	prev1 = head;
	prev2 = head;
	while (prev1->next != lst1) // поиск узла предшествующего lst1
    prev1 = prev1->next;
  	while (prev2->next != lst2) // поиск узла предшествующего lst2
    	prev2 = prev2->next;
  	next1 = lst1->next; // узел следующий за lst1
  	next2 = lst2->next; // узел следующий за lst2
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

