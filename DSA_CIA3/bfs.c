#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node* next;
};

struct g {
    struct node *adj[7];
    int visited[7];
};

struct g* Graph;

struct queue {
    int items[7];
    int front;
    int rear;
};

struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct queue* q) {
    return q->rear == -1;
}

void enqueue(struct queue* q, int value) {
    if (q->rear == 6)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

void BFS(int start) {
    struct queue* q = createQueue();

    Graph->visited[start] = 1;
    enqueue(q, start);

    while (!isEmpty(q)) {
        int current = dequeue(q);
        printf("%d   ", current);

        struct node* temp = Graph->adj[current];
        while (temp) {
            int data = temp->data;
            if (!Graph->visited[data]) {
                Graph->visited[data] = 1;
                enqueue(q, data);
            }
            temp = temp->next;
        }
    }

    free(q);
}

struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    return n;
}

void insert(int start, int desc) {
    struct node* new = createNode(desc);
    new->next = Graph->adj[start];
    Graph->adj[start] = new;
}

int main() {
    // Allocate memory for Graph
    Graph = (struct g*)malloc(sizeof(struct g));
    
    if (Graph == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 7; i++) {
        Graph->adj[i] = NULL;
        Graph->visited[i] = 0;
    }

    insert(0, 1);
    insert(0, 2);
    insert(0, 3);
    insert(1, 3);
    insert(2, 4);
    insert(3, 5);
    insert(3, 6);
    insert(4, 5);
    insert(5, 2);

    BFS(0);

    // Free allocated memory
    for (int i = 0; i < 7; i++) {
        struct node* temp = Graph->adj[i];
        while (temp) {
            struct node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(Graph);

    return 0;
}
