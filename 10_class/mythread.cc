#include<iostream>
#include<pthread.h>
#include<string>
#include<sys/types.h>
#include<unistd.h>
#include<cstdio>
#include<stdlib.h>
using namespace std;

pthread_mutex_t lock;
pthread_cond_t cond;

void* Wait(void *arg)
{
	while(1)
	{
		pthread_cond_wait(&cond,&lock);//线程等待条件满足。
		cout << "active......" << endl;
	}
}

void* Signal(void *arg)
{
	while(1)
	{
		pthread_cond_signal(&cond);//唤醒等待
		sleep(1);
	}
}

int main()
{
	pthread_mutex_init(&lock,NULL);//初始化互斥量
	pthread_cond_init(&cond,NULL);//初始化条件变量

	pthread_t t1, t2;
	pthread_create(&t1, NULL, Wait, NULL);
	pthread_create(&t2, NULL, Signal, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&cond);
}
//int tickets = 100;
//pthread_mutex_t lock;//设置一个全局的锁
//
//void* GetTicket(void* args)
//{
//	while(1)
//	{
//		pthread_mutex_lock(&lock);//加锁
//		if(tickets > 0)
//		{
//			usleep(10000);
//			printf("get a ticket no . is : %d\n",tickets--);
//			pthread_mutex_unlock(&lock);//解锁
//		}
//		else
//		{
//			printf("%s ... quit\n", (char*)args);
//			pthread_mutex_unlock(&lock);//解锁
//			break;	
//		}
//	}
//}
//int main()
//{
//	pthread_t tid1, tid2, tid3, tid4;
//	pthread_mutex_init(&lock,NULL);//初始化互斥量（锁）
//	pthread_create(&tid1, NULL, GetTicket, (void *)"thread 1");
//	pthread_create(&tid2, NULL, GetTicket, (void *)"thread 2");
//	pthread_create(&tid3, NULL, GetTicket, (void *)"thread 3");
//	pthread_create(&tid4, NULL, GetTicket, (void *)"thread 4");
//
//	pthread_join(tid1, NULL);
//	pthread_join(tid2, NULL);
//	pthread_join(tid3, NULL);
//	pthread_join(tid4, NULL);
//
//	pthread_mutex_destroy(&lock);
//	return 0;	
//}


//void *thread_routine(void* arg)
//{
//	while(1)
//	{
//		printf("Hello I am a new thread,my name is : %s\n", (char*)arg);
//		sleep(1);
//		break;
//	}
//	//return (void*)11;
//	//exit(3);
//	pthread_exit((void*)3);//线程退出
//}
//int main()
//{
//	pthread_t tid;
//	pthread_create(&tid, NULL, thread_routine, (void *)"thread 1");//创建线程
//	printf("Hello I am main thread: %p\n", tid );
//	
//	pthread_cancel(tid);
//	
//	void * ret;
//	pthread_join(tid, &ret);//线程等待，jion的第二个参数是void* 的返回值
//	printf("ret : %d\n", ret);//打印退出码
//	return 0;	
//}

//void *thread_routine(void* arg)//调用函数指针
//{
//	string str = (char*) arg;
//	while(1)
//	{
//		cout << str << " run "	<< "pid : " << getpid() << endl;
//		sleep(1);
//	}
//}
//int main()//两个线程的pid相同
//{
//	pthread_t tid;
//	pthread_create(&tid, NULL, thread_routine, (void*) "thread 1");//创建线程
//	while(1)
//	{
//		cout << "main thread run " << " pid : " << getpid() << endl;
//		sleep(2);
//	}
//	return 0;	
//}
