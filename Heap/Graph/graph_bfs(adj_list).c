#include <stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;
}GraphNode;

typedef struct {
	int n;
	GraphNode *adj_list[MAX_VERTICES];
}GraphType;


void graph_init(GraphType *g)
{
	int v;
	g->n=0;
	for(v=0;v<MAX_VERTICES;v++)
		g->adj_list[v]=NULL;
}

void insert_vertex(GraphType *g, int v)
{
	if(((g->n)+1)>MAX_VERTICES){
		printf("그래프:정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType *g, int u,int v)
{
	GraphNode *node;
	if(u>=g->n || v>=g->n){
		printf("그래프: 정점 번호 오류");
		return;
	}

	//node=new GraphNode;
        node=(GraphNode*)malloc(sizeof(GraphNode));
	node->vertex=v;
	node->link=g->adj_list[u];
	g->adj_list[u]=node;
}

void print_graph(GraphType *g)
{
	int i;
	GraphNode *node;
	printf("List of edges:\n");
	for(i=0;i<g->n;i++){
		node=g->adj_list[i];
		while(node!=NULL){
			printf("<%d, %d>",i,node->vertex);
			node=node->link;
		}
		printf("\n");
	}
	printf("\n");
}

GraphNode *findNode(GraphNode *node, int vertex)
{
	while(node!=NULL){
		if(node->vertex==vertex) 
			return node;
		node=node->link;
	}
	return node;
}

void delete_edge(GraphType *g,int u,int v)
{
		if(u>=g->n || v>=g->n){
		printf("그래프: 정점 번호 오류");
		return;
	}
		GraphNode *node;
		node=findNode(g->adj_list[u],v);
		if(node!=NULL){
			if(g->adj_list[u]!=node){
				GraphNode *temp=g->adj_list[u];
				while(temp->link!=node)
					temp=temp->link;
				temp->link=node->link;
			}
			else{
				g->adj_list[u]=node->link;
			}
			free( node);
		}
}

int visited[MAX_VERTICES];

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct{
	element queue[MAX_QUEUE_SIZE];
	int front,rear;
}QueueType;


void error(char *message)
{
	printf("%s\n", message);
}

void init(QueueType *q)
{
	q->front=q->rear=0;
}

int is_empty(QueueType *q)
{
	return(q->front==q->rear);
}

int is_full(QueueType *q)
{
	return ((q->rear+1)%MAX_QUEUE_SIZE==q->front);
}

void enqueue(QueueType *q,element item)
{
	if(is_full(q))
		error("the queue is full\n");
	q->rear=(q->rear+1)%MAX_QUEUE_SIZE;
	q->queue[q->rear]=item;
}

element dequeue(QueueType *q)
{
	if(is_empty(q))
		error("the queue is empty\n");
	q->front=(q->front+1)%MAX_QUEUE_SIZE;
	return q->queue[q->front];
}


void init_visited()
{
	int i;
	for(i=0;i<MAX_VERTICES;i++)
		visited[i]=0;
}

void bfs_list(GraphType *g, int v)
{
	GraphNode *w;
	QueueType q;
	init(&q);
	visited[v]=TRUE;
	printf("%d ",v);
	enqueue(&q,v);
	while(!is_empty(&q)){
		v=dequeue(&q);
		for(w=g->adj_list[v];w;w=w->link)
			if(!visited[w->vertex]){
				visited[w->vertex]=TRUE;
				printf("%d ",w->vertex);
				enqueue(&q, w->vertex);
			}
	}
}
		
void main()
{
	int i;
	GraphType g;
	graph_init(&g);

	for(i=0;i<4;i++)
		insert_vertex(&g,i);
	insert_edge(&g,0,1);
	insert_edge(&g,1,0);
	insert_edge(&g,0,3);
	insert_edge(&g,3,0);
	insert_edge(&g,1,2);
	insert_edge(&g,2,1);
	insert_edge(&g,1,3);
	insert_edge(&g,3,1);
	insert_edge(&g,2,3);
	insert_edge(&g, 3,2);
	print_graph(&g);

	bfs_list(&g,0);
	delete_edge(&g,0,1);
	delete_edge(&g,1,0);
	print_graph(&g);
	delete_edge(&g,1,2);
	print_graph(&g);
}

