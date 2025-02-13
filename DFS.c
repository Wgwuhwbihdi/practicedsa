#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node{
    struct node*next;
    int vertex;
}node;
node*G[20];
int visited[20],n;
void read_graph();
void insert(int,int);
void main(){
    int i;
    read_graph();
    for (i=0;i<n; i++)
    {
        visited[i]=0;
        DFS(0);
    }
}
void DFS(int i ){
    node*p;
    printf("\n %d",i);
    p = G[i];
    visited[i]=1;
    while (p!=NULL)
    {
        i=p->vertex;
        if (!visited[i])
        {
            DFS(i);
            p=p->next;
        }
        
    }
    
}
void read_graph(){
    int i,vi,vj,no_of_edge;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    for ( i = 0; i <n; i++)
    {
      G[i]=NULL;
      printf("Enter the number of edge");
      scanf("enter the no of edge %d",&no_of_edge);
      for (i = 0; i <no_of_edge; i++)
      {
        printf("\n Enter an edge(u,v):");
        scanf("%d%d",&vi,&vj);
        insert(vi,vj);
      }
    }
}
void insert(int vi,int vj){
    node*p,*q;
    q=(node*)malloc(sizeof(node));
    q->vertex = vj;
    q->next = NULL;
    if (G[vi]==NULL)
    {
      G[vi]=q;
    }else{
        p=G[vi];
        while (p->next!=NULL)
        {
            p=p->next;
            p->next=q;
        }
        
    }
    
}