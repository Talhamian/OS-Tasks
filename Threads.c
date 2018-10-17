#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int chunk_size=100;
void * Add(void *arg){
    int start = (int)arg;
    int end = start + chunk_size;
    int sum=0,i=0;
    for(i=start;i<end;i++){
        sum = sum + i;
    }
    return ((void*)sum);
}

int main(void)
{
    int status_t1,status_t2,status_t3,status_t4,status_t5,status_t6,status_t7,status_t8,status_t9,status_t10;
	pthread_t thread_t1,thread_t2,thread_t3,thread_t4,thread_t5,thread_t6,thread_t7,thread_t8,thread_t9,thread_t10;

	int sum=0;
    pthread_create(&thread_t1,NULL,Add,(void*)(0*chunk_size));
	pthread_create(&thread_t2,NULL,Add,(void*)(1*chunk_size));
   	pthread_create(&thread_t3,NULL,Add,(void*)(2*chunk_size));
	pthread_create(&thread_t4,NULL,Add,(void*)(3*chunk_size));
	pthread_create(&thread_t5,NULL,Add,(void*)(4*chunk_size));
	pthread_create(&thread_t6,NULL,Add,(void*)(5*chunk_size));
	pthread_create(&thread_t7,NULL,Add,(void*)(6*chunk_size));
	pthread_create(&thread_t8,NULL,Add,(void*)(7*chunk_size));
	pthread_create(&thread_t9,NULL,Add,(void*)(8*chunk_size));
	pthread_create(&thread_t10,NULL,Add,(void*)(9*chunk_size));


	pthread_join(thread_t1,(void**) & sum);
    pthread_join(thread_t2,(void**) & sum);
	pthread_join(thread_t3,(void**) & sum);
    pthread_join(thread_t4,(void**) & sum);
	pthread_join(thread_t5,(void**) & sum);
   	pthread_join(thread_t6,(void**) & sum);
   	pthread_join(thread_t7,(void**) & sum);
   	pthread_join(thread_t8,(void**) & sum);
   	pthread_join(thread_t9,(void**) & sum);
   	pthread_join(thread_t10,(void**) & sum);

	printf("\nSum of values 0-1000 %d\n", sum);
   return 0;
}