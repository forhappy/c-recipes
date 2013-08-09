/*
 * ========================================================================
 *
 *       Filename:  MultiProducerMultiConsumer.cc
 *
 *    Description:  multi producer and multi consumer example.
 *
 *        Created:  08/09/2013 10:51:48 AM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

/*多个生产者和多个消费者*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE         5       //产品库存大小
#define PRODUCT_CNT         50      //产品生产总数

struct product_cons
{
    int buffer[BUFFER_SIZE];  //生产产品值
    pthread_mutex_t lock;     //互斥锁 volatile int
    int readpos, writepos;    //读写位置
    pthread_cond_t notempty;  //条件变量，非空
    pthread_cond_t notfull;   //非满

    pthread_mutex_t lock2;    //互斥锁，控制cnt_p
    int cnt_p;                //完成生产产品数量

    pthread_mutex_t lock3;    //互斥锁，控制cnt_c
    int cnt_c;                //获得生产产品数量
}buffer;

void init(struct product_cons *p)
{
    pthread_mutex_init(&p->lock, NULL);     //互斥锁
    pthread_cond_init(&p->notempty, NULL);  //条件变量
    pthread_cond_init(&p->notfull, NULL);   //条件变量
    p->readpos = 0;                         //读写位置
    p->writepos = 0;

    pthread_mutex_init(&p->lock2, NULL);
    p->cnt_p = 0;

    pthread_mutex_init(&p->lock3, NULL);
    p->cnt_c = 0;
}

void fini(struct product_cons *p)
{
    pthread_mutex_destroy(&p->lock);     //互斥锁
    pthread_cond_destroy(&p->notempty);  //条件变量
    pthread_cond_destroy(&p->notfull);   //条件变量
    p->readpos = 0;                      //读写位置
    p->writepos = 0;

    pthread_mutex_destroy(&p->lock2);
    p->cnt_p = 0;

    pthread_mutex_destroy(&p->lock3);
    p->cnt_c = 0;
}

//存储 一个数据 到 bufferr
void put(struct product_cons *p, int data) //输入产品子函数
{
    pthread_mutex_lock(&p->lock); //上锁

    /*等待，直到 buffer 不为 满*/
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

//读，移除 一个数据 从 buffer
int get(struct product_cons *p)
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
    int flag = -1;
    while(1)
    {
        pthread_mutex_lock(&buffer.lock2);
        if(buffer.cnt_p < PRODUCT_CNT)
        {
            ++buffer.cnt_p;
            printf("%s put the %d product\n", (char*)data, buffer.cnt_p);
            put(&buffer, buffer.cnt_p);
        }
        else
            flag = 0;
        pthread_mutex_unlock(&buffer.lock2);

        if(!flag)
            break;

        sleep(2);
    }

    printf("%s producer stopped\n", (char*)data);
    return NULL;
}

void *consumer(void *data)
{
    int flag = -1;
    while(1)
    {
        pthread_mutex_lock(&buffer.lock3);
        if(buffer.cnt_c < PRODUCT_CNT)
        {
            printf("%s get the %d product\n", (char*)data, get(&buffer));
            ++buffer.cnt_c;
        }
        else
            flag = 0;
        pthread_mutex_unlock(&buffer.lock3);
        if(!flag)
            break;

        sleep(2);
    }

    printf("%s consumer stopped\n", (char*)data);
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t th_a[3],th_b[3];
    void *retval;

    init(&buffer);

    pthread_create(&th_a[0], NULL, producer, (void*)"th_a[0]");
    pthread_create(&th_a[1], NULL, producer, (void*)"th_a[1]");    
    pthread_create(&th_a[2], NULL, producer, (void*)"th_a[2]");
    pthread_create(&th_b[0], NULL, consumer, (void*)"th_b[0]");
    pthread_create(&th_b[1], NULL, consumer, (void*)"th_b[1]");
    pthread_create(&th_b[2], NULL, consumer, (void*)"th_b[2]");

    pthread_join(th_a[0], &retval);
    pthread_join(th_a[1], &retval);
    pthread_join(th_a[2], &retval);
    pthread_join(th_b[0], &retval);
    pthread_join(th_b[1], &retval);
    pthread_join(th_b[2], &retval);

    fini(&buffer);

    return 0;
}

