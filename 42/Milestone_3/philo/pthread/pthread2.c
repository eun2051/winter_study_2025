#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

typedef struct __myarg_t {
 int k;
 int a;
} myarg_t;
int gdata = 0;
void *mythread(void *arg) {
 myarg_t *ptr = (myarg_t *)arg;
 printf("%d %d\n", ptr->k, ptr->a);
 printf("%d ", gdata);
 sleep(2);
 printf("%d\n", gdata);
 pthread_exit(NULL);
}

int main(void){
 pthread_t p;
 int res;
 myarg_t args;
 args.k = 4;
 args.a = 6;
 res = pthread_create(&p, NULL, mythread, &args);
 sleep(1);
 gdata += res + 1;
 sleep(1);
 return(0);
}
