#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct __myarg_t {
 int k, a;
} myarg_t;
typedef struct __myret_t {
 int x, y;
} myret_t;
int gdata = 0;
void *mythread(void *arg) {
 myarg_t *ptr = (myarg_t *)arg;
 printf("%d %d\n", ptr->k, ptr->a);
 printf("%d ", gdata);
 sleep(2);
 printf("%d\n", gdata);
 myret_t *m = (myret_t *)malloc(sizeof(myret_t));
 m->x = 1; m->y = 2;
 pthread_exit(m);
}

int main(void){
 pthread_t p;
 int res;
 myret_t *n;

 myarg_t args;
 args.k = 4;
 args.a = 6;
 res = pthread_create(&p, NULL, mythread, &args);
 gdata += res + 1;
 pthread_join(p, (void **)&n);
 printf("Returned values: %d %d\n", n->x, n->y);
 free(n);
 return(0);
}
