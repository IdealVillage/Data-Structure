#include <stdio.h>
#include <malloc.h>


#define MaxSize 100
typedef struct sNode *Stack;
typedef int DataType;

struct sNode{
	DataType data[MaxSize];
	int top;
};

Stack createStack();
void push(Stack s,DataType item);
int pop(Stack S);


int main(){
	Stack s;
	s=createStack();
	push(s,1);
	push(s,2);
	push(s,3);
	pop(s);
	printf("%d\n",s->data[s->top]);
}


Stack createStack(){
	Stack s;
	s=(Stack)malloc(sizeof(struct sNode));
	s->top=-1;
	return s;
}

void push(Stack s,DataType item){
	if(s->top==MaxSize-1){
		printf("¶ÑÕ»Âú");
		return;
	}else{
	s->data[++(s->top)] =item;
	return;
	}
}


DataType pop(Stack S){
    if (S->top==-1) {
        printf("¶ÑÕ»¿Õ");
        return -2;
    }
    else {
        return ( S->data[(S->top)--] );
	}
}

