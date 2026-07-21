#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct graphnode {
    int vertex;
    struct graphnode *next;
} Graph_node;

typedef struct graph {
    int n;
    Graph_node *adj_list[MAX_VERTICES];
} Graph;

void create_graph(Graph *g)
{
    g->n = 0;
    for (int i = 0; i < MAX_VERTICES; i++)
        g->adj_list[i] = NULL;
}
void insert_vertex(Graph *g, int v)
{
    if ((g->n) + 1 > MAX_VERTICES) {
        fprintf(stderr, "max list\n");
        return ;
    }
    g->n++;
}

void insert_edge(Graph *g, int v1, int v2)
{
    if (v1 >= g->n || v2 >= g->n) {
        fprintf(stderr, "vertex error\n");
        return ;
    }
    Graph_node *new = (Graph_node *)malloc(sizeof(Graph_node));
    new->vertex = v2;
    new->next = g->adj_list[v1];
    g->adj_list[v1] = new;
}

// delete_vertex(graph, v) {}
// delete_edge(graph, v1, v2) {}

void print_adj_list(Graph *g)
{
    for (int i = 0; i < g->n; i++) {
        Graph_node *ptr = g->adj_list[i];
        printf("정점 %d의 인접리스트", i);
        while (ptr != NULL) {
            printf("-> %d ", ptr->vertex);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    create_graph(g);
    for (int i = 0; i < 4; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 3);
    insert_edge(g, 3, 0);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0);
    insert_edge(g, 0, 1);
    insert_edge(g, 1, 0);
    insert_edge(g, 3, 2);
    insert_edge(g, 2, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);

    print_adj_list(g);
    free(g);
    return 0;
}