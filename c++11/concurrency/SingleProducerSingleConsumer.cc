#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

static const int kItemBufferSize  = 4; // Item buffer size.
static const int kItemsToProduce = 10;  // How many items we plan to produce.

struct ItemRepository {
  std::mutex mtx;
	std::condition_variable repo_not_full;
	std::condition_variable repo_not_empty;

	int item_buffer[kItemBufferSize];
	size_t read_position;
	size_t write_position;
} gItemRepository;

typedef struct ItemRepository ItemRepository;


void ProduceItem(ItemRepository *ir, int item)
{
	std::unique_lock<std::mutex> lock(ir->mtx);
	while(((ir->write_position + 1) % kItemBufferSize)
		== ir->read_position) { // item buffer is full, just wait here.
		(ir->repo_not_full).wait(lock);
	}

	(ir->item_buffer)[ir->write_position] = item;
	(ir->write_position)++;

	(ir->repo_not_empty).notify_all();
}

int ConsumeItem(ItemRepository *ir)
{
	int data;
	std::unique_lock<std::mutex> lock(ir->mtx);
	
	// item buffer is empty, just wait here.
	while(ir->write_position == ir->read_position) {
		std::cout << "Consumer is waiting for items...\n";
		(ir->repo_not_empty).wait(lock);
	}

	data = (ir->item_buffer)[ir->read_position];
	(ir->read_position)++;

	if (ir->read_position >= kItemBufferSize)
		ir->read_position = 0;

	(ir->repo_not_full).notify_all();
	return data;
}


void ItemProducerTask()
{
	for (int i = 1; i <= kItemsToProduce; i ++) {
		sleep(2);
		std::cout << "Produce the " << i << " item..." << std::endl;
		ProduceItem(&gItemRepository, i);
	}
}

void ItemConsumerTask()
{
	static int cnt = 0;
	while(1) {
		sleep(1);
		int item = ConsumeItem(&gItemRepository);
		std::cout << "Consume the " << item << " item" << std::endl;
		if (++cnt >= kItemsToProduce) break;
	}
}

int main()
{
	std::thread producer(ItemProducerTask);
	std::thread consumer(ItemConsumerTask);
	producer.join();
	consumer.join();
}
