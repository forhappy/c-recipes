/*
 * ========================================================================
 *
 *       Filename:  SingleProducerSingleConsumer.cc
 *
 *    Description:  single producer single consumer example.
 *
 *        Created:  08/09/2013 10:33:00 AM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE         5       //产品库存大小
#define PRODUCT_CNT         50      //产品生产总数

struct ProductRepository
{
    int buffer[BUFFER_SIZE];  //生产产品值
    pthread_mutex_t lock;     //互斥锁 volatile int
    int readpos, writepos;    //读写位置
    pthread_cond_t notempty;  //条件变量，非空
    pthread_cond_t notfull;   //非满
} ProductBuffer;

void init(struct ProductRepository *p)
{
    pthread_mutex_init(&p->lock, NULL);     //互斥锁
    pthread_cond_init(&p->notempty, NULL);  //条件变量
    pthread_cond_init(&p->notfull, NULL);   //条件变量
    p->readpos = 0;                         //读写位置
    p->writepos = 0;
}

void fini(struct ProductRepository *p)
{
    pthread_mutex_destroy(&p->lock);     //互斥锁
    pthread_cond_destroy(&p->notempty);  //条件变量
    pthread_cond_destroy(&p->notfull);   //条件变量
    p->readpos = 0;                      //读写位置
    p->writepos = 0;
}

void cleanup_handler(void *arg)
{
    printf("cleanup_handler exec!\n");
    pthread_mutex_t *lock = (pthread_mutex_t*)arg;
    pthread_mutex_unlock(lock); //解锁
}

//存储 一个数据 到 ProductBufferr
void put(struct ProductRepository *p, int data) //输入产品子函数
{
    pthread_mutex_lock(&p->lock); //上锁

    /*等待，直到 ProductBuffer 不为 满*/
    while((p->writepos + 1) % BUFFER_SIZE == p->readpos) //测试空间是否已满
    {
        printf("producer wait for not full\n");
        pthread_cond_wait(&p->notfull, &p->lock); //阻塞等待
        //这里，生产者 notfull 等待消费者 pthread_cond_signal(&p->notfull);信号
        //如果，消费者发送了 signal 信号，表示有了 空闲
    }

    p->buffer[p->writepos] = data; //写数据
    p->writepos++;

    if(p->writepos >= BUFFER_SIZE) //如果写到 尾部,返回
        p->writepos = 0;

    pthread_cond_signal(&p->notempty); //发送有数据信号
    pthread_mutex_unlock(&p->lock); //解锁
}

//读，移除 一个数据 从 ProductBuffer
int get(struct ProductRepository *p)
{
    int data = 0;
    pthread_mutex_lock(&p->lock);

    /*等待，直到不为空*/
    while(p->writepos == p->readpos)
    {
        printf("consumer wait for not empty\n");
        pthread_cond_wait(&p->notempty,&p->lock);
    }

    /*读 一个 数据*/
    data = p->buffer[p->readpos];
    p->readpos++;

    if(p->readpos >= BUFFER_SIZE) //如果读到 尾
        p->readpos = 0;

    pthread_cond_signal(&p->notfull);
    pthread_mutex_unlock(&p->lock);

    return data;
}

void *producer(void *data) //子线程 ，生产
{
    int n;
    for(n = 1; n <= 50; ++n) //生产 50 个产品
    {
        sleep(1);
        printf("put the %d product\n",n);
        put(&ProductBuffer,n);
    }

    printf("producer stopped\n");

    return NULL;
}

void *consumer(void *data)
{
    static int cnt = 0;
    while(1)
    {
        sleep(2);
        printf("get the %d product\n", get(&ProductBuffer));
        if(++cnt == PRODUCT_CNT)
            break;
    }

    printf("consumer stopped\n");
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t th_a,th_b;
    void *retval;

    init(&ProductBuffer);

    pthread_create(&th_a, NULL, producer, 0);
    pthread_create(&th_b, NULL, consumer, 0);

    pthread_join(th_a, &retval);
    pthread_join(th_b, &retval);

    fini(&ProductBuffer);

    return 0;
}

