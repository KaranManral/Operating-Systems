#include <pthread.h>
#include <stdio.h>

int sum;
void *runner(void *param);

void main()
{
	pthread_t t1;
	pthread_attr_t t_attr;
	pthread_attr_init(&t_attr);
	pthread_create(&t1,&t_attr,runner,NULL);
	pthread_join(t1,NULL);
	printf("Sum= %d\n",sum);
}
void *runner(void *param)
{
	int i,upper = 10000;
	sum=0;
	for(int i=1;i<=upper;i++)
		sum+=i;
	pthread_exit(0);
}