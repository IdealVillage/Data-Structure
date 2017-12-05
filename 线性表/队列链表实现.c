#include <stdio.h>
#include <malloc.h>

typedef int ElementType;

typedef struct QNode{
	ElementType data;
	struct QNode *next;
}*QueuePtr;

struct Queue{
	QueuePtr front,rear;
};

typedef struct Queue *LinkQueue;

void InitQueue(LinkQueue q);

int main(){
	LinkQueue q;
	InitQueue(q);
		
}

void InitQueue(LinkQueue q){
	q->front=q->rear=malloc(sizeof(struct QNode));
	q->rear->next=NULL;
}









