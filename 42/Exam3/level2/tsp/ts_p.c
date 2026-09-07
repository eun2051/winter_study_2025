#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

typedef struct s_city
{
    float x;
    float y;
}   t_city;

/*
** You must implement this function
** It should return the Euclidean distance between 2 cities
*/
float   distance(t_city a, t_city b)
{
    float x_min = a.x - b.x;
    float y_min = a.y - b.y;
    return (sqrtf(x_min * x_min + y_min * y_min));
}

/*
** You must implement this function
** It should compute total distance of the path
** including the return to the starting city
*/
float   total_distance(t_city *cities, int *path, int n)
{
    float sum = 0.0;
    for (int i = 0; i < n - 1; i++)
    {
        // 수정됨: path 배열의 값을 인덱스로 사용하여 cities 배열의 실제 구조체를 전달
        sum += distance(cities[path[i]], cities[path[i + 1]]);
    }
    // 수정됨: 출발지로 돌아가는 거리 계산에도 동일하게 적용
    sum += distance(cities[path[n - 1]], cities[path[0]]);
    return (sum);
}

/*
** You must implement this function
** Use backtracking to try all permutations
*/
void    solve(t_city *cities, int *path, int n, int pos, float *min)
{
    if (pos == n)
    {
        // 수정됨: total_distance의 반환형인 float에 맞추어 자료형 변경
        float dis = total_distance(cities, path, n);
        if (dis < *min)
            *min = dis;
        return ;
    }
    for (int i = pos; i < n; i++)
    {
        int tmp = path[i];
        path[i] = path[pos];
        path[pos] = tmp;
        
        solve(cities, path, n, pos + 1, min);
        
        tmp = path[i];
        path[i] = path[pos];
        path[pos] = tmp;
    }
}

int main(void)
{
    t_city  cities[11];
    int     n = 0;

    // Read input from stdin
    while (n < 11 && fscanf(stdin, "%f, %f", &cities[n].x, &cities[n].y) == 2)
        n++;

    // If less than 2 cities → distance = 0
    if (n < 2)
    {
        printf("0.00\n");
        return (0);
    }

    // Initialize path: [0,1,2,...]
    int path[11];
    for (int i = 0; i < n; i++)
        path[i] = i;

    float min = FLT_MAX;

    /*
    ** Optimization:
    ** Fix first city → start from pos = 1
    */
    solve(cities, path, n, 1, &min);

    printf("%.2f\n", min);
    return (0);
}
