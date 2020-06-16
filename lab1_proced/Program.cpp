#include "Program.h"
using namespace std;
	 
struct container* In(container *lst,ifstream &ifst){
		struct container *last = Init2(In(ifst));
		struct container *tmp;
		tmp = lst->next; 
		lst->next = last; 
		last->next = tmp; 
		lst->prev=last;
		last->prev=lst;
	while(!ifst.eof()) {			
		  struct container *newItem = Init2(In(ifst));
		  struct container *tmp;
		  struct container *tmp2;		  
		  tmp = last->next; 
		  last->next = newItem;
		  newItem->next = tmp;
		  newItem->prev=last;
		  lst->prev=newItem;
		  last=newItem;
		}
		return(last);
}
 	
void In(diagol &a, ifstream &ifst) {
	ifst.get();
	ifst>>a.y;
 	a.x=new int*;
 	for (int count=0;count<a.y;count++){
 		a.x[count]=new int[a.y];
 	}
	for (int count=0;count<a.y;count++){
 		ifst>>	a.x[count][count];
 	}
}
 
  void In(square &p, ifstream &ifst){
	ifst.get();
	p.a=new int*;
	ifst>>p.b;
	for (int count=0;count<p.b;count++){
 		p.a[count]=new int[p.b];
 	}
	for (int count=0;count<p.b;count++){
 		for (int count2=0;count2<p.b;count2++){
 		ifst>>	p.a[count][count2];
 	}
 	}
 }
 
 matr* In(ifstream &ifst){
 	matr *sp;
 	int k;
 	ifst >> k;
 	switch(k) {
 		case 1:
 			sp = new matr({});
 			sp->k = matr::key::SQUARE;
 			In(sp->s, ifst);
 		//	return sp;
 			break;
 		case 2:
 			sp = new matr({});
 			sp->k = matr::key::DIAGOL;
 			In(sp->d, ifst);
 			//return sp;
 			break;
 		default:
 		return 0;
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
 
 void Out(matr &s, ofstream &ofst) {
	 switch(s.k) {
	 	case matr::key::SQUARE:
	 		Out(s.s, ofst);
	 		break;
	 	case matr::key::DIAGOL:
	 		Out(s.d, ofst);
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
  do 
  {
	struct container *temp;
	temp = p;
	while (temp->next != p) { 
			temp = temp->next;
		}
  	temp->next = p->next; 
	p = p->next; // ������� � ���������� ����
  } while (p != lst); // ������� ��������� ������

}

 
 
 
 
