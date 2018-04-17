#include<pthread.h>
#include<stdio.h>
#define NUM_THREADS 5

int main(int args,char *args[])
{
int i,scope;
pthread_t tid[NUM_THREADS];
pthread_attr_t attr;
/*get the default attribute*/
pthread_atte_init(&attr);
/*first inquire on the current scope*/
if(pthread_attr_getscope(&attr,&scope)!=0)
fprintf(stderr,"unable to get scheduling scope\n");
else
{
if(scope==PTHREAD_SCOPE_PROCESS)
printf("PTHREAD_SCOPE_PROCESS");
elseif(scope==PTHREAD_SCOPE_SYSTEM)
printf("PTHREAD_SCOPE_SYSTEM");
else
fprintf(strderr,"illegal scope value.\n");
}
/*set the scheduling algorith to pcs or scs */
pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM);
/* create the threads */
for(i=0;i<NUM_THREADS;i++)
pthread_create(&tid[i],&attr,runner,NULL);
/* now join on each thread*/
for(i=0;i<NUM_THREAD;i++)
   pthread_join(tid[i],NULL);
}
/* each thread will begin control in the function */
void *runner(void *param)
{
/* do some work....*/
pthread_exit(0);
}
