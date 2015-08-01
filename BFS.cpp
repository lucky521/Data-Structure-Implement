#include <stdio.h>
#include <malloc.h>
#define VERTEXNUM 5

//双向链表存储的队列
typedef struct  qElement{
	int value;
	struct  qElement* pre;
	struct  qElement* next;
}st_qElement;

st_qElement* front = NULL;
st_qElement* rear = NULL;

void putQueue(int vertex);
int* getQueue();
void putRelatedInQueue(int (*edge)[VERTEXNUM], int vertex);

void createGraph(int (*edge)[VERTEXNUM], int start, int end);
void display(int (*edge)[VERTEXNUM]);

void bfs(int (*edge)[VERTEXNUM],int i,int* vetexStatusArr);
void bfscore(int (*edge)[VERTEXNUM], int i, int* vetexStatusArr);


void putQueue(int vertex)
{
	st_qElement* qe = (st_qElement*)malloc(sizeof(st_qElement));
	qe->value = vertex;
	qe-next = NULL;
	qe->pre = NULL;

	if(front == NULL || rear == NULL)
		front = rear = qe;
	else{
		rear->next = qe;
		qe->pre = rear;
		rear = qe;
	}
}

int* getQueue()
{
	if(front ==NULL || rear == NULL)
		return NULL;
	else{
		int* res = (int*)malloc(sizeof(int));
		*res = front->value;
		st_qElement* p = front;
		front = front->next;
		if(front == NULL)
			rear = front;
		else
		{
			front->pre = NULL;
		}
		free(p);
		p = NULL;
		return res;
	}
}

void putRelatedInQueue(int (*edge)[VERTEXNUM], int vertex)
{
	int i;
	for(i=0;i<VERTEXNUM;i++)
		if(edge[vertex][i]==1)
			putQueue(i);
}
