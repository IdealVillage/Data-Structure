#include <stdio.h>
#include <malloc.h>


typedef int DataType;
typedef struct sNode *Stack;

struct sNode{
	DataType data;
	Stack next;
};

Stack CreateStack();
void push(Stack s,DataType x);
int isEmpty(Stack s);
DataType pop(Stack s);


int main(){
	Stack s;
	s=CreateStack();
	push(s,1);
	push(s,2);
	push(s,3);
	pop(s);
	printf("%d\n",s->next->data);
	return 1;
}

Stack CreateStack(){
	Stack s;
	s=(Stack)malloc(sizeof(struct sNode));
	s->next=NULL;
	return s;
}

int isEmpty(Stack s){
	return (s->next==NULL);
}

void push(Stack s,DataType x){
	Stack p=(Stack)malloc(sizeof(struct sNode));
	p->next=s->next;
	p->data=x;
	s->next=p;
}

DataType pop(Stack s){
	if(isEmpty(s)){
		printf("Õ»¶Ñ¿Õ");
		return -1;
	}else{
		Stack tmp;
		DataType topElement;
		tmp=s->next;
		s->next=tmp->next;
		topElement=tmp->data;
		return topElement;
	}
}










