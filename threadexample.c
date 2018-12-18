#include <pthread.h>
#include <stdio.h>

/* This is our thread function.  It is like main(), but for a thread*/
pthread_mutex_t lock;

void *threadFunc(void *arg)
{

	char *str;
	static int i = 0;

	str=(char*)arg;
		printf("start %s\n",str);

        pthread_mutex_lock(&lock);

	while(i < 110 )
	{
		usleep(1);
		printf("threadFunc says: %s\t%d\n",str,++i);
	}
    	pthread_mutex_unlock(&lock);
		printf("end %s\n",str);

	return NULL;
}

int main(void)
{
	pthread_t pth;	// this is our thread identifier
	int i = 0;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&pth,NULL,threadFunc,"foo1");
	pthread_create(&pth,NULL,threadFunc,"foo2");

	while(i < 100)
	{
		usleep(1);
		printf("main is running...\n");
		++i;
	}

	printf("main waiting for thread to terminate...\n");
	pthread_join(pth,NULL);
	pthread_join(pth,NULL);

    pthread_mutex_destroy(&lock);
	return 0;
}

