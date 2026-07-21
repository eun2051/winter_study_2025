#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

typedef struct graph {
    int n; //정점의 개수
    int adj_m[MAX_VERTICES][MAX_VERTICES];
} Graph;

int visited[MAX_VERTICES];

// 그래프 0으로 초기화
void create_graph(Graph *g)
{
    g->n = 0;

    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->adj_m[i][j] = 0;
        }
    }
}

// 정점 삽입  
void insert_vertex(Graph *g, int v)
{
    if ((g->n) + 1 > MAX_VERTICES) {
        fprintf(stderr, "vertex error\n");
        return ;
    }
    g->n++;
}

// 간선 삽입
void insert_edge(Graph *g, int v1, int v2)
{
    if (v1 >= g->n || v2 >= g->n) {
        fprintf(stderr, "vertex error\n");
        return ;
    }
    g->adj_m[v1][v2] = 1;
    g->adj_m[v2][v1] = 1;
    // 정점을 우선 삽입, 해당 정점 번호를 이용해 간선 삽입
}

void print_graph(Graph *g)
{
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%d ", g->adj_m[i][j]);
        }
        printf("\n");
    }
}

void dfs_matrix(Graph *g, int v)
{
    visited[v] = TRUE;

    printf("%d ", v);
    for (int i = 0; i < g->n; i++) {
        if (g->adj_m[v][i] && (visited[i] == FALSE))
            dfs_matrix(g, i);
    }
}

int main()
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    create_graph(g);
    for (int i = 0; i < 4; i++) {
        insert_vertex(g, i);
    }
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    print_graph(g);
    free(g);
    return 0;
}