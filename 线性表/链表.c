#include <stdio.h>
#include <malloc.h>

typedef struct Node *List;
typedef int DataType;
struct Node{
    DataType data;
    List next;
};

List createHeadList();
List createTailList();
void printList(List L);
List Findkth(int i,List L);
List FindValue(List L,DataType x);
List FindPrevious(DataType x,List L);
int lengthList(List L);
int Insert1(List P,DataType x);
List Insert2(DataType x,int i,List L);
int isLast(List p);
int delete(DataType x,List L);
void reverse(List L);



int main()
{
	
    List L=createTailList();
//	List p=L->next;
//	Insert2(5,1,L);
//	delete(1,L);
	reverse(L);
	printList(L);
	return 1;
}

List createHeadList(){
    List L=(List)malloc(sizeof(struct Node));
    List s;
    DataType x;
    L->next=NULL;
    scanf("%d",&x);
    while(x!=-1){
        s=(List)malloc(sizeof(struct Node));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}

void printList(List L){
	List p=L->next;//获取指针域
	while(p){
		printf("%d",p->data);//输出数据域
		p=p->next;
	}
}



List FindKth(int k,List L){
	List p=L;
	int i=1;
	while(p!=NULL&&i<k){
		p=p->next;
		i++;
	}
	if(i==k)return p;
	else return NULL;
}


List FindValue(List L,DataType x){
	List p=L;
	while(p!=NULL&&p->data!=x){
		p=p->next;
	}
	return p;
} 


List FindPrevious(DataType x,List L){
	List p=L;
	while(p->next!=NULL&&p->next->data!=x)
		p=p->next;
	return p; 
} 



int lengthList(List L){
	List p=L;
	int j=0;
	while(p){
		p=p->next;
		j++;
	} 
	return j;
}

 
List createTailList(){
	List L=(List)malloc(sizeof(struct Node));
	List s,r=L;
	DataType x;
 	scanf("%d",&x);
 	while(x!=-1){
 		s=(List)malloc(sizeof(struct Node));
 		s->data=x;
 		s->next=r->next;
 		r->next=s;
 		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;
	return L; 
}


int Insert1(List p,DataType x){
	List s=(List)malloc(sizeof(struct Node));
	s->data=x;
	s->next=p->next;
	p->next=s;
	return 1;
}

List Insert2(DataType x,int i,List L){
	List p,s;
	if(i==1){
		s=(List)malloc(sizeof(struct Node));
		s->data=x;
		s->next=L->next->next;
		L->next->next=s;
		return s;
	}
	p=FindKth(i-1,L);
	if(p==NULL){
		printf("error");
		return NULL;
	}else{
		s=(List)malloc(sizeof(struct Node));
		s->data=x;
		s->next=p->next;
		p->next=s;
		return L;
	}
	
}



int isLast(List p){
	return p->next==NULL; 
}

int delete(DataType x,List L){
	List p,tmp;
	//find previous node 
	p=FindPrevious(x,L); 
	if(!isLast(p)){
		tmp=p->next;
		p->next=p->next->next;
		free(tmp);
	}
	return 1; 
} 

//reverse the list
void reverse(List L){
	List p,q;
	p=L->next;
	L->next=NULL;
	while(p){
		q=p;
		p=p->next;
		q->next=L->next;
		L->next=q;
	}
}



