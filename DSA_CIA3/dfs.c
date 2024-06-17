#include "stdio.h"
#include "stdlib.h"



struct node {
    int data;
    struct node* next;
};

struct g{
    struct node *adj[7];
   int visited[7];
};

struct g* Graph;


void DFS(int start){
        Graph->visited[start] = 1;
       printf("%d   ",start);
       struct node* temp = Graph->adj[start];
       while(temp){
        int data = temp->data;
         if(!Graph->visited[data]){
            DFS(data);
         }
         temp = temp->next;
       }
}

struct node* createNode(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    return n;
}


void insert(int start,int desc){
      struct node* new = createNode(desc);
      new->next = Graph->adj[start];
      Graph->adj[start] = new;

}
int main(){
    Graph =  (struct g*)malloc(sizeof(struct g));
    for(int i = 0 ;i < 7; i++){
         Graph->adj[i] = NULL;
         Graph->visited[i] = 0;
    }

     insert(0,1);
     insert(0,2);
     insert(0,3);
     insert(1,3);
     insert(2,4);
     insert(3,5);
     insert(3,6);
     insert(4,5);
     insert(5,2);
     DFS(0);


}