// ThreadTest.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

/*
// �� ���� ù ������
#include <iostream>
#include <thread>
using std::thread;

void func1() 
{
	for (int i = 0; i < 10; i++) 
	{
		std::cout << "������ 1 �۵���! \n";
	}
}

void func2() 
{
	for (int i = 0; i < 10; i++) 
	{
		std::cout << "������ 2 �۵���! \n";
	}
}

void func3() 
{
	for (int i = 0; i < 10; i++) 
	{
		std::cout << "������ 3 �۵���! \n";
	}
}
int main() 
{
	thread t1(func1);	// ������ ���� �� ����
	thread t2(func2);	// ������ ���� �� ����
	thread t3(func3);	// ������ ���� �� ����

	t1.join();			// ������ ����� Return��
	t2.join();			// ������ ����� Return��
	t3.join();			// ������ ����� Return��

	getchar();
}
*/

/*
#include <iostream>
#include <thread>
using std::thread;

void func1() {
	for (int i = 0; i < 10; i++) {
		std::cout << "������ 1 �۵���! \n";
	}
}

void func2() {
	for (int i = 0; i < 10; i++) {
		std::cout << "������ 2 �۵���! \n";
	}
}

void func3() {
	for (int i = 0; i < 10; i++) {
		std::cout << "������ 3 �۵���! \n";
	}
}
int main() {
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);

	t1.detach();		// ���μ��� ����� �ڵ����� ������ ����
	t2.detach();		// ���μ��� ����� �ڵ����� ������ ����
	t3.detach();		// ���μ��� ����� �ڵ����� ������ ����

	std::cout << "���� �Լ� ���� \n";

	getchar();
}
*/

/*
#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>

using std::thread;
using std::vector;

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result) 
{
	int sum = 0;
	for (auto itr = start; itr < end; ++itr) 
	{
		sum += *itr;
	}
	*result = sum;

	// �������� id �� ���Ѵ�.
	thread::id this_id = std::this_thread::get_id();
	// printf�� ���ؽ�Ʈ ����ġ�� �Ǵ��� �ٸ� ��������� �� ���̿� �޼����� ������� ���ϰ� �����ϴ�.
	//printf("������ %x ���� %d ���� %d ���� ����� ��� : %d \n", this_id, *start, *(end - 1), sum); 
	// std::cout << A << B�� ��� A �� ����� ���Ŀ� B �� ����ϱ� ���� �ٸ� �����尡 ������ ����� �� �ֽ��ϴ�.
	std::cout << "������ " << std::hex << this_id << " ���� " << std::dec << *start << " ���� " << *(end - 1) << " ���� ����� ��� : " << sum << std::endl;
}

int main() 
{
	vector<int> data(10000);
	for (int i = 0; i < 10000; i++) 
	{
		data[i] = i;
	}

	// �� �����忡�� ���� �κ� �յ��� �����ϴ� ����
	vector<int> partial_sums(4);

	vector<thread> workers;
	for (int i = 0; i < 4; i++) 
	{
		workers.push_back(thread(worker, data.begin() + i * 2500, data.begin() + (i + 1) * 2500, &partial_sums[i]));
	}

	// ��� �����忡�� ������ ���� ������ ��ٸ���.
	for (int i = 0; i < 4; i++) 
	{
		workers[i].join();
	}

	int total = 0;
	for (int i = 0; i < 4; i++) 
	{
		total += partial_sums[i];
	}
	std::cout << "��ü �� : " << total << std::endl;

	getchar();
}
*/

/*
#include <iostream>
#include <thread>
#include <vector>
using std::thread;
using std::vector;

void worker(int& counter) 
{
	for (int i = 0; i < 10000; i++) 
	{
		counter += 1;
	}
}

int main() 
{
	int counter = 0;

	vector<thread> workers;
	for (int i = 0; i < 4; i++) 
	{
		// ���۷����� �����Ϸ��� ref �Լ��� ���ξ� �Ѵ� (���� ���� bind �Լ� ����)
		workers.push_back(thread(worker, std::ref(counter)));
	}

	for (int i = 0; i < 4; i++) 
	{
		workers[i].join();
	}

	std::cout << "Counter ���� �� : " << counter << std::endl;

	getchar();
}
*/

/*
#include <iostream>
#include <mutex>  // mutex �� ����ϱ� ���� �ʿ�
#include <thread>
#include <vector>

void worker(int& result, std::mutex& m) 
{
	for (int i = 0; i < 10000; i++) 
	{
		m.lock();
		result += 1;
		m.unlock();
	}
}

int main() 
{
	int counter = 0;
	std::mutex m;  // �츮�� mutex ��ü

	std::vector<std::thread> workers;
	for (int i = 0; i < 4; i++) 
	{
		workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)));
	}

	for (int i = 0; i < 4; i++) 
	{
		workers[i].join();
	}

	std::cout << "Counter ���� �� : " << counter << std::endl;

	getchar();
}
*/

/*
#include <iostream>
#include <mutex>  // mutex �� ����ϱ� ���� �ʿ�
#include <thread>
#include <vector>

void worker(int& result, std::mutex& m) 
{
	for (int i = 0; i < 10000; i++) 
	{
		// lock ���� �ÿ� m.lock() �� �����Ѵٰ� ���� �ȴ�.
		std::lock_guard<std::mutex> lock(m);
		result += 1;

		// scope �� ���� ������ lock �� �Ҹ�Ǹ鼭
		// m �� �˾Ƽ� unlock �Ѵ�.
	}
}

int main() 
{
	int counter = 0;
	std::mutex m;  // �츮�� mutex ��ü

	std::vector<std::thread> workers;
	for (int i = 0; i < 4; i++) 
	{
		workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)));
	}

	for (int i = 0; i < 4; i++) 
	{
		workers[i].join();
	}

	std::cout << "Counter ���� �� : " << counter << std::endl;

	getchar();
}
*/

/*
// ������� �߻��ϴ� ����
#include <iostream>
#include <mutex>  // mutex �� ����ϱ� ���� �ʿ�
#include <thread>

void worker1(std::mutex& m1, std::mutex& m2) 
{
	for (int i = 0; i < 10000; i++) 
	{
		std::lock_guard<std::mutex> lock1(m1);
		std::lock_guard<std::mutex> lock2(m2);
		// Do something
	}
}

void worker2(std::mutex& m1, std::mutex& m2) 
{
	for (int i = 0; i < 10000; i++) 
	{
		std::lock_guard<std::mutex> lock2(m2);
		std::lock_guard<std::mutex> lock1(m1);
		// Do something
	}
}

int main() 
{
	int counter = 0;
	std::mutex m1, m2;  // �츮�� mutex ��ü

	std::thread t1(worker1, std::ref(m1), std::ref(m2));
	std::thread t2(worker2, std::ref(m1), std::ref(m2));

	t1.join();
	t2.join();

	std::cout << "��!" << std::endl;

	getchar();
}
*/


/*
#include <iostream>
#include <mutex>  // mutex �� ����ϱ� ���� �ʿ�
#include <thread>

void worker1(std::mutex& m1, std::mutex& m2) 
{
	for (int i = 0; i < 10; i++) 
	{
		m1.lock();
		m2.lock();
		std::cout << "Worker1 Hi! " << i << std::endl;

		m2.unlock();
		m1.unlock();
	}
}

void worker2(std::mutex& m1, std::mutex& m2) 
{
	for (int i = 0; i < 10; i++) 
	{
		while (true) 
		{
			m2.lock();

			// m1 �� �̹� lock �Ǿ� �ִٸ� "�� �� ��" �� �����ϰ� �ȴ�.
			if (!m1.try_lock()) 
			{
				m2.unlock();
				continue;
			}

			std::cout << "Worker2 Hi! " << i << std::endl;
			m1.unlock();
			m2.unlock();
			break;
		}
	}
}

int main() 
{
	std::mutex m1, m2;  // �츮�� mutex ��ü

	std::thread t1(worker1, std::ref(m1), std::ref(m2));
	std::thread t2(worker2, std::ref(m1), std::ref(m2));

	t1.join();
	t2.join();

	std::cout << "��!" << std::endl;

	getchar();
}
*/

/*
// ������, �Һ���
#include <chrono>  // std::chrono::miliseconds
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

void producer(std::queue<std::string>* downloaded_pages, std::mutex* m, int index) 
{
	for (int i = 0; i < 5; i++) 
	{
		// ������Ʈ�� �ٿ�ε� �ϴµ� �ɸ��� �ð��̶� �����ϸ� �ȴ�.
		// �� ������ ���� �ٿ�ε� �ϴµ� �ɸ��� �ð��� �ٸ���.
		std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
		std::string content = "������Ʈ : " + std::to_string(i) + " from thread(" + std::to_string(index) + ")\n";

		// data �� ������ ���̿��� �����ǹǷ� critical section �� �־�� �Ѵ�.
		m->lock();
		downloaded_pages->push(content);
		m->unlock();
	}
}

void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m, int* num_processed) 
{
	// ��ü ó���ϴ� ������ ������ 5 * 5 = 25 ��.
	while (*num_processed < 25) 
	{
		m->lock();
		// ���� ���� �ٿ�ε��� �������� ���ٸ� �ٽ� ���.
		if (downloaded_pages->empty()) 
		{
			m->unlock();  // (Quiz) ���⼭ unlock �� ���Ѵٸ� ��� �ɱ��?

						  // 10 �и��� �ڿ� �ٽ� Ȯ���Ѵ�.
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			continue;
		}

		// �� ���� �������� �а� ��� ��Ͽ��� �����Ѵ�.
		std::string content = downloaded_pages->front();
		downloaded_pages->pop();

		(*num_processed)++;
		m->unlock();

		// content �� ó���Ѵ�.
		std::cout << content;
		std::this_thread::sleep_for(std::chrono::milliseconds(80));
	}
}

int main() 
{
	// ���� �ٿ�ε��� �������� ����Ʈ��, ���� ó������ ���� �͵��̴�.
	std::queue<std::string> downloaded_pages;
	std::mutex m;

	std::vector<std::thread> producers;
	for (int i = 0; i < 5; i++) 
	{
		producers.push_back(std::thread(producer, &downloaded_pages, &m, i + 1));
	}

	int num_processed = 0;
	std::vector<std::thread> consumers;
	for (int i = 0; i < 3; i++) 
	{
		consumers.push_back(std::thread(consumer, &downloaded_pages, &m, &num_processed));
	}

	for (int i = 0; i < 5; i++) 
	{
		producers[i].join();
	}
	for (int i = 0; i < 3; i++) 
	{
		consumers[i].join();
	}

	getchar();
}
*/


/*
// condition_variable

#include <chrono>              // std::chrono::miliseconds
#include <condition_variable>  // std::condition_variable
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

void producer(std::queue<std::string>* downloaded_pages, std::mutex* m, int index, std::condition_variable* cv) 
{
	for (int i = 0; i < 5; i++) 
	{
		// ������Ʈ�� �ٿ�ε� �ϴµ� �ɸ��� �ð��̶� �����ϸ� �ȴ�.
		// �� ������ ���� �ٿ�ε� �ϴµ� �ɸ��� �ð��� �ٸ���.
		std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
		std::string content = "������Ʈ : " + std::to_string(i) + " from thread(" +
			std::to_string(index) + ")\n";

		// data �� ������ ���̿��� �����ǹǷ� critical section �� �־�� �Ѵ�.
		m->lock();
		downloaded_pages->push(content);
		m->unlock();

		// consumer ���� content �� �غ�Ǿ����� �˸���.
		cv->notify_one();
	}
}

void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m, int* num_processed, std::condition_variable* cv) 
{
	while (*num_processed < 25) 
	{
		std::unique_lock<std::mutex> lk(*m);

		cv->wait(lk, [&] { return !downloaded_pages->empty() || *num_processed == 25; }); // return FALSE : lk(unlock) & Sleep for wake, return TRUE : lk(lock) & escape wait

		if (*num_processed == 25) // On complete to do process.
		{
			lk.unlock();
			return; // exit thread.
		}

		// �� ���� �������� �а� ��� ��Ͽ��� �����Ѵ�.
		std::string content = downloaded_pages->front();
		downloaded_pages->pop();

		(*num_processed)++;
		lk.unlock();

		// content �� ó���Ѵ�.
		std::cout << content;
		std::this_thread::sleep_for(std::chrono::milliseconds(80));
	}
}

int main() 
{
	// ���� �ٿ�ε��� �������� ����Ʈ��, ���� ó������ ���� �͵��̴�.
	std::queue<std::string> downloaded_pages;
	std::mutex m;
	std::condition_variable cv;

	std::vector<std::thread> producers;
	for (int i = 0; i < 5; i++) 
	{
		producers.push_back(std::thread(producer, &downloaded_pages, &m, i + 1, &cv));
	}

	int num_processed = 0;
	std::vector<std::thread> consumers;
	for (int i = 0; i < 3; i++) 
	{
		consumers.push_back(std::thread(consumer, &downloaded_pages, &m, &num_processed, &cv));
	}

	for (int i = 0; i < 5; i++) 
	{
		producers[i].join();
	}

	// ������ �ڰ� �ִ� ��������� ��� �����.
	cv.notify_all(); // for consumer thread join.

	for (int i = 0; i < 3; i++) 
	{
		consumers[i].join();
	}

	getchar();
}
*/

/*
// atomic
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

void worker(std::atomic<int>& counter) 
{
	for (int i = 0; i < 10000; i++) 
	{
		counter++;
	}
}

int main() 
{
	std::atomic<int> x;
	std::cout << "is lock free ? : " << std::boolalpha << x.is_lock_free() << std::endl;

	std::atomic<int> counter(0);

	std::vector<std::thread> workers;
	for (int i = 0; i < 4; i++) 
	{
		workers.push_back(std::thread(worker, ref(counter)));
	}

	for (int i = 0; i < 4; i++) 
	{
		workers[i].join();
	}

	std::cout << "Counter ���� �� : " << counter << std::endl;

	getchar();
}
*/


/*
// memory_order_relaxed
#include <atomic>
#include <cstdio>
#include <thread>
#include <vector>
using std::memory_order_relaxed;

void t1(std::atomic<int>* a, std::atomic<int>* b) 
{
	b->store(1, memory_order_relaxed);      // b = 1 (����)
	int x = a->load(memory_order_relaxed);  // x = a (�б�)

	printf("x : %d \n", x);
}

void t2(std::atomic<int>* a, std::atomic<int>* b) 
{
	a->store(1, memory_order_relaxed);      // a = 1 (����)
	int y = b->load(memory_order_relaxed);  // y = b (�б�)

	printf("y : %d \n", y);
}

int main() 
{
	std::vector<std::thread> threads;

	std::atomic<int> a(0);
	std::atomic<int> b(0);

	threads.push_back(std::thread(t1, &a, &b));
	threads.push_back(std::thread(t2, &a, &b));

	for (int i = 0; i < 2; i++) 
	{
		threads[i].join();
	}

	getchar();
}
*/

/*
// �۾��� ���ġ ���ϰ� ���� �ʿ䰡 ���� ��� : � �����尣�� �ϴ� ���� �׳� 1������.
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
using std::memory_order_relaxed;

void worker(std::atomic<int>* counter) 
{
	for (int i = 0; i < 10000; i++) 
	{
		// �ٸ� ����� ����

		counter->fetch_add(1, memory_order_relaxed);
	}
}
int main() 
{
	std::vector<std::thread> threads;

	std::atomic<int> counter(0);

	for (int i = 0; i < 4; i++) 
	{
		threads.push_back(std::thread(worker, &counter));
	}

	for (int i = 0; i < 4; i++) 
	{
		threads[i].join();
	}

	std::cout << "Counter : " << counter << std::endl;

	getchar();
}
*/

/*
// producer - consumer ���� : �񵿱�
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
using std::memory_order_relaxed;

void producer(std::atomic<bool>* is_ready, int* data) 
{
	*data = 10;
	//is_ready->store(true, memory_order_relaxed); // �񵿱�
	is_ready->store(true, std::memory_order_release); // ���� : �����Ϸ��� *data = 10�� ������ġ�� ������ �ٲ��� ���ϰ� ��.
}

void consumer(std::atomic<bool>* is_ready, int* data) 
{
	// data �� �غ�� �� ���� ��ٸ���.
	//while (!is_ready->load(memory_order_relaxed)) // �񵿱�
	while (!is_ready->load(std::memory_order_acquire)) // ���� : producer���� store�� �Ѱ�쿡
	{
	}

	std::cout << "Data : " << *data << std::endl;
}

int main() 
{
	std::vector<std::thread> threads;

	std::atomic<bool> is_ready(false);
	int data = 0;

	threads.push_back(std::thread(producer, &is_ready, &data));
	threads.push_back(std::thread(consumer, &is_ready, &data));

	for (int i = 0; i < 2; i++) 
	{
		threads[i].join();
	}

	getchar();
}
*/

/*
// producer - consumer ���� : ����
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
using std::memory_order_relaxed;

std::atomic<bool> is_ready;
std::atomic<int> data[3];

void producer() 
{
	data[0].store(1, memory_order_relaxed);
	data[1].store(2, memory_order_relaxed);
	data[2].store(3, memory_order_relaxed);
	is_ready.store(true, std::memory_order_release);
}

void consumer() 
{
	// data �� �غ�� �� ���� ��ٸ���.
	while (!is_ready.load(std::memory_order_acquire)) 
	{
	}

	std::cout << "data[0] : " << data[0].load(memory_order_relaxed) << std::endl;
	std::cout << "data[1] : " << data[1].load(memory_order_relaxed) << std::endl;
	std::cout << "data[2] : " << data[2].load(memory_order_relaxed) << std::endl;
}

int main() 
{
	std::vector<std::thread> threads;

	threads.push_back(std::thread(producer));
	threads.push_back(std::thread(consumer));

	for (int i = 0; i < 2; i++) 
	{
		threads[i].join();
	}

	getchar();
}
*/


/*
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<bool> x(false);
std::atomic<bool> y(false);
std::atomic<int> z(0);

void write_x() { x.store(true, std::memory_order_release); }

void write_y() { y.store(true, std::memory_order_release); }

void read_x_then_y() 
{
	while (!x.load(std::memory_order_acquire)) 
	{
	}
	if (y.load(std::memory_order_acquire)) 
	{
		++z;
	}
}

void read_y_then_x() 
{
	while (!y.load(std::memory_order_acquire)) 
	{
	}
	if (x.load(std::memory_order_acquire)) 
	{
		++z;
	}
}

int main() 
{
	std::thread a(write_x);
	std::thread b(write_y);
	std::thread c(read_x_then_y);
	std::thread d(read_y_then_x);
	a.join();
	b.join();
	c.join();
	d.join();
	std::cout << "z : " << z << std::endl;

	getchar();
}
*/

/*
// ������ �ϰ���(sequential consistency) : memory_order_seq_cst
#include <atomic>
#include <iostream>
#include <thread>
using std::memory_order_seq_cst;
using std::thread;

std::atomic<bool> x(false);
std::atomic<bool> y(false);
std::atomic<int> z(0);

void write_x() { x.store(true, memory_order_seq_cst); }

void write_y() { y.store(true, memory_order_seq_cst); }

void read_x_then_y() 
{
	while (!x.load(memory_order_seq_cst)) 
	{
	}
	if (y.load(memory_order_seq_cst)) 
	{
		++z;
	}
}

void read_y_then_x() 
{
	while (!y.load(memory_order_seq_cst)) 
	{
	}
	if (x.load(memory_order_seq_cst))
	{
		++z;
	}
}

int main() 
{
	thread a(write_x);
	thread b(write_y);
	thread c(read_x_then_y);
	thread d(read_y_then_x);
	a.join();
	b.join();
	c.join();
	d.join();
	std::cout << "z : " << z << std::endl;

	getchar();
}
*/

/*
// std::promise (������) �� std::future (�Һ���)

#include <future>
#include <iostream>
#include <string>
#include <thread>
using std::string;

void worker(std::promise<string>* p) 
{
	// ����� �����ϴ� ���. �ش� ����� future �� ����.
	p->set_value("some data");
}

int main() 
{
	std::promise<string> p;

	// �̷��� string �����͸� ���� �ְڴٴ� ���.
	std::future<string> data = p.get_future();

	std::thread t(worker, &p);

	// �̷��� ��ӵ� �����͸� ���� �� ���� ��ٸ���.
	data.wait();

	// wait �� �����ߴٴ� ���� future �� �����Ͱ� �غ�Ǿ��ٴ� �ǹ�.
	// ����� wait ���� �׳� get �ص� wait �� �Ͱ� ����.
	std::cout << "���� ������ : " << data.get() << std::endl; // future ���� get �� ȣ���ϸ�, ������ ��ü�� �̵��ϱ⶧���� ����� get �� �� �� ȣ���ϸ� �ȵ�.

	t.join();

	getchar();
}
*/


/*
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

std::condition_variable cv;
std::mutex m;
bool done = false;
std::string info;

void worker() 
{
	{
		std::lock_guard<std::mutex> lk(m);
		info = "some data";  // ���� p->set_value("some data") �� ����
		done = true;
	}
	cv.notify_all();
}

int main() 
{
	std::thread t(worker);

	std::unique_lock<std::mutex> lk(m);
	cv.wait(lk, [] { return done; });  // ���� data.wait() �̶� ���� �ȴ�. : ������ false�̸�, lk�� lock���¿��� sleep���� ��. ������ true�̸�, wait�� ���.
	lk.unlock();

	std::cout << "���� ������ : " << info << std::endl;

	t.join();

	getchar();
}
*/

/*
#include <exception>
#include <future>
#include <iostream>
#include <string>
#include <thread>
using std::string;

void worker(std::promise<string>* p) 
{
	try 
	{
		throw std::runtime_error("Some Error!");
	}
	catch (...) 
	{
		// set_exception ���� exception_ptr �� �����ؾ� �Ѵ�.
		p->set_exception(std::current_exception()); // catch �� ���ܿ� ���� ������ ��ȯ�ϴ� current_exception �Լ��� �����ϴ� ��ü (make_exception_ptr �Լ��� ����)
	}
}
int main() 
{
	std::promise<string> p;

	// �̷��� string �����͸� ���� �ְڴٴ� ���.
	std::future<string> data = p.get_future();

	std::thread t(worker, &p);

	// �̷��� ��ӵ� �����͸� ���� �� ���� ��ٸ���.
	data.wait();

	try 
	{
		data.get();
	}
	catch (const std::exception& e) 
	{
		std::cout << "���� : " << e.what() << std::endl;
	}
	t.join();

	getchar();
}
*/

/*
// wait_for

#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <string>
#include <thread>

void worker(std::promise<void>* p) 
{
	std::this_thread::sleep_for(std::chrono::seconds(10));
	p->set_value();
}
int main() 
{
	// void �� ��� ��� ��ü�� �������� ������, future �� set �� �Ǿ���
	// �ȵǾ������� ������ ��ġ �÷����� ������ ������ �� �ֽ��ϴ�.
	std::promise<void> p;

	// �̷��� string �����͸� ���� �ְڴٴ� ���.
	std::future<void> data = p.get_future();

	std::thread t(worker, &p);

	// �̷��� ��ӵ� �����͸� ���� �� ���� ��ٸ���.
	while (true) 
	{
		std::future_status status = data.wait_for(std::chrono::seconds(1)); // wait_for �� ���޵� �ð� ��ŭ ��ٷȴٰ� �ٷ� ����
		// std::future_status �� ���� [ std::future_status::ready , std::future_status::timeout , future_status::deferred ]
	
		// ���� �غ� �ȵ�
		if (status == std::future_status::timeout) 
		{
			std::cerr << ">";
		}
		// promise �� future �� ������.
		else if (status == std::future_status::ready) 
		{
			break;
		}
	}
	t.join();

	getchar();
}
*/


/*
// shared_future

#include <chrono>
#include <future>
#include <iostream>
#include <thread>
using std::thread;

void runner(std::shared_future<void> start) 
{
	start.get();
	std::cout << "���!" << std::endl;
}

int main() 
{
	std::promise<void> p;
	std::shared_future<void> start = p.get_future(); // shared_future �� ��� future �ʹ� �ٸ��� ���簡 ���� (���۷����� �����ͷ� ������ �ʿ䰡 ����)

	thread t1(runner, start);
	thread t2(runner, start);
	thread t3(runner, start);
	thread t4(runner, start);

	// ����� cerr �� std::cout ���� �ٸ��� ���۸� ������� �ʱ� ������ �͹̳ο�
	// �ٷ� ��µȴ�.
	std::cerr << "�غ�...";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cerr << "��!" << std::endl;

	p.set_value();

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	getchar();
}
*/


/*
// packaged_task �� ����ϰ� �ȴٸ� �����忡 ���� promise �� �������� �ʾƵ� �˾Ƽ� packaged_task �� �Լ��� ���ϰ��� ó��

#include <future>
#include <iostream>
#include <thread>

int some_task(int x) { return 10 + x; }

int main() 
{
	// int(int) : int �� �����ϰ� ���ڷ� int �� �޴� �Լ�. (std::function ����)
	std::packaged_task<int(int)> task(some_task);

	std::future<int> start = task.get_future();

	std::thread t(std::move(task), 5); // packaged_task �� ���� ������ �Ұ����ϹǷ� (promise �� �������� �Դϴ�.) ��������� move ����߸� ��.

	std::cout << "����� : " << start.get() << std::endl;
	t.join();

	getchar();
}
*/

/*
// std::async�� �����带 �˾Ƽ� ���� �ش� �Լ��� �񵿱������� ����
#include <future>
#include <iostream>
#include <thread>
#include <vector>

// std::accumulate �� ����
int sum(const std::vector<int>& v, int start, int end) 
{
	int total = 0;
	for (int i = start; i < end; ++i) 
	{
		total += v[i];
	}
	return total;
}

int parallel_sum(const std::vector<int>& v) 
{
	// lower_half_future �� 1 ~ 500 ���� �񵿱������� ����
	// ����� ���� �Լ��� ����ϸ� �� �� ����ϰ� ǥ���� �� �� �ִ�.
	// --> std::async([&v]() { return sum(v, 0, v.size() / 2); });
	std::future<int> lower_half_future = std::async(std::launch::async, sum, cref(v), 0, v.size() / 2); // std::launch::async -> �ٷ� �����带 �����ؼ� ���ڷ� ���޵� �Լ��� ���� (�񵿱�)
																										// std::launch::deferred -> future �� get �Լ��� ȣ��Ǿ��� �� ���� (����)

	// upper_half �� 501 ���� 1000 ���� ����
	int upper_half = sum(v, v.size() / 2, v.size());

	return lower_half_future.get() + upper_half; 
}

int main() 
{
	std::vector<int> v;
	v.reserve(1000);

	for (int i = 0; i < 1000; ++i) 
	{
		v.push_back(i + 1);
	}

	std::cout << "1 ���� 1000 ������ �� : " << parallel_sum(v) << std::endl;

	getchar();
}
*/

/*
#include <future>
#include <iostream>
#include <thread>

int do_work(int x) 
{
	// x �� ������ ���� ���� �Ѵ�.
	std::this_thread::sleep_for(std::chrono::seconds(3));
	return x;
}

void do_work_parallel() 
{
	auto f1 = std::async([]() { do_work(3); });
	auto f2 = std::async([]() { do_work(3); });
	do_work(3);

	f1.get();
	f2.get();
}

void do_work_sequential() 
{
	do_work(3);
	do_work(3);
	do_work(3);
}

int main() 
{ 
	clock_t time = clock();
	//double timeSecond = (double)(time / CLOCKS_PER_SEC); // �� ���� ��ȯ

	//do_work_parallel(); 
	do_work_sequential(); 

	printf("The ellapsed time is %d [mSec].\n", (int)(clock() - time));

	getchar();
}
*/


// ������Ǯ(ThreadPool) : ���� ���� ��������� ����ϰ� �ִٰ�, �� ���� ������ �Ǹ�, ����ϰ� �ִ� ������� �� �ϳ��� �̸� �޾Ƽ� ����
// C++ ���� �Ϲ����� Ÿ���� �Լ� �����͸� ������ �� �ִ� �����̳ʴ� ���� : �ϴ��� void ���� ���ڸ� ���� �ʴ� �Լ��� ����

// ThreadPool ù ��° ����
/*
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace ThreadPool 
{
	class ThreadPool 
	{
	public:
		ThreadPool(size_t num_threads);
		~ThreadPool();

		// job �� �߰��Ѵ�.
		void EnqueueJob(std::function<void()> job);

	private:
		// �� Worker �������� ����.
		size_t num_threads_;
		// Worker �����带 �����ϴ� ����.
		std::vector<std::thread> worker_threads_;
		// ���ϵ��� �����ϴ� job ť.
		std::queue<std::function<void()>> jobs_;
		// ���� job ť�� ���� cv �� m.
		std::condition_variable cv_job_q_;
		std::mutex m_job_q_;

		// ��� ������ ����
		bool stop_all;

		// Worker ������
		void WorkerThread();
	};

	ThreadPool::ThreadPool(size_t num_threads) : num_threads_(num_threads), stop_all(false) 
	{
		worker_threads_.reserve(num_threads_);
		for (size_t i = 0; i < num_threads_; ++i) 
		{
			worker_threads_.emplace_back([this]() { this->WorkerThread(); });
		}
	}

	void ThreadPool::WorkerThread() 
	{
		while (true) 
		{
			std::unique_lock<std::mutex> lock(m_job_q_);
			cv_job_q_.wait(lock, [this]() { return !this->jobs_.empty() || stop_all; });
			if (stop_all && this->jobs_.empty()) 
			{
				return;
			}

			// �� ���� job �� ����.
			std::function<void()> job = std::move(jobs_.front());
			jobs_.pop();
			lock.unlock();

			// �ش� job �� �����Ѵ� :)
			job();
		}
	}

	ThreadPool::~ThreadPool() 
	{
		stop_all = true;
		cv_job_q_.notify_all();

		for (auto& t : worker_threads_) 
		{
			t.join();
		}
	}

	void ThreadPool::EnqueueJob(std::function<void()> job) 
	{
		if (stop_all) 
		{
			throw std::runtime_error("ThreadPool ��� ������");
		}
		{
			std::lock_guard<std::mutex> lock(m_job_q_);
			jobs_.push(std::move(job));
		}
		cv_job_q_.notify_one();
	}

}  // namespace ThreadPool

void work(int t, int id) 
{
	printf("%d start \n", id);
	std::this_thread::sleep_for(std::chrono::seconds(t));
	printf("%d end after %ds\n", id, t);
}

int main() 
{
	ThreadPool::ThreadPool pool(3);

	for (int i = 0; i < 10; i++) 
	{
		pool.EnqueueJob([i]() { work(i % 3 + 1, i); });
	}

	getchar();
}
*/



// ������ �Լ�(return��) �ޱ� 
/*
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace ThreadPool 
{
	class ThreadPool 
	{
	public:
		ThreadPool(size_t num_threads);
		~ThreadPool();

		// job �� �߰��Ѵ�.
		template <class F, class... Args> // class... : ���� ���� ���ø����� ������ ������ ���ڵ��� ���� �� ����
		std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(F f, Args... args); // typename std::result_of<F(Args...)>::type : �Լ� f �� ���ϰ�(std::result_of)�� type

	private:
		// �� Worker �������� ����.
		size_t num_threads_;
		// Worker �����带 �����ϴ� ����.
		std::vector<std::thread> worker_threads_;
		// ���ϵ��� �����ϴ� job ť.
		std::queue<std::function<void()>> jobs_;
		// ���� job ť�� ���� cv �� m.
		std::condition_variable cv_job_q_;
		std::mutex m_job_q_;

		// ��� ������ ����
		bool stop_all;

		// Worker ������
		void WorkerThread();
	};

	ThreadPool::ThreadPool(size_t num_threads) : num_threads_(num_threads), stop_all(false) 
	{
		worker_threads_.reserve(num_threads_);
		for (size_t i = 0; i < num_threads_; ++i) 
		{
			worker_threads_.emplace_back([this]() { this->WorkerThread(); });
		}
	}

	void ThreadPool::WorkerThread() 
	{
		while (true) 
		{
			std::unique_lock<std::mutex> lock(m_job_q_);
			cv_job_q_.wait(lock, [this]() { return !this->jobs_.empty() || stop_all; });
			if (stop_all && this->jobs_.empty()) 
			{
				return;
			}

			// �� ���� job �� ����.
			std::function<void()> job = std::move(jobs_.front());
			jobs_.pop();
			lock.unlock();

			// �ش� job �� �����Ѵ� :)
			job();
		}
	}

	ThreadPool::~ThreadPool() 
	{
		stop_all = true;
		cv_job_q_.notify_all();

		for (auto& t : worker_threads_) 
		{
			t.join();
		}
	}

	template <class F, class... Args>
	std::future<typename std::result_of<F(Args...)>::type> ThreadPool::EnqueueJob(F f, Args... args) 
	{
		if (stop_all) 
		{
			throw std::runtime_error("ThreadPool ��� ������");
		}
		//jobs_.push([f, args...]() { f(args...); }); // Worker ������ �ȿ��� f(args...) �� ���� �� �� ����. ��, f(args...) �� ���ϰ��� ���� ���� ����.

		using return_type = typename std::result_of<F(Args...)>::type;	// job ��ü�� ThreadPool::EnqueueJob(F f, Args... args) �� ���� ���� -> EnqueueJob �Լ��� �����ϸ� �ı���. (�ذ�å : 1. packaged_task �� ���� �����̳ʿ� ����, 2. shared_ptr �� packaged_task �� ����)
		//std::packaged_task<return_type()> job(std::bind(f, args...));	// �񵿱������� ����Ǵ� �Լ��� ���ϰ� (�� ���ư� ���� ����) �޾Ƴ��� �� : packaged_task �� �̿�
																		// packaged_task �� �����ڴ� �Լ� ���� �ޱ� ������ job(std::bind(f, args...)ó�� ���ڵ��� f �� bind ��Ŵ.
		//std::future<return_type> job_result_future = job.get_future();// job �� ���� ����� �����ϴ� job_result_future �� ����
		auto job =														// (�ذ�å 2) : packaged_task �� ����ϴ� ���� ���� �� �˾Ƽ� shared_ptr �� ��ü�� �Ҹ�����ֹǷ� �ξ� �����ϱ� ����. 
			std::make_shared<std::packaged_task<return_type()>>(std::bind(f, args...)); // make_shared �� ���ؼ� shared_ptr �� ����
		std::future<return_type> job_result_future = job->get_future();

		{
			std::lock_guard<std::mutex> lock(m_job_q_);
			//jobs_.push([&job]() { job(); });							// obs_ �� job �� �����ϴ� ���� �Լ��� �߰�
			jobs_.push([job]() { (*job)(); });							// ���� �Լ��� shared_ptr �� ���纻�� ���� , job �� �����ϴ� ���������� packged_task ��ü�� ��� �������
		}																// job �� ����ȴٸ�, f �� ���ϰ��� job_result_future �� ���� �ǰ�, �̴� ������Ǯ ����ڰ� ������ �� ����
		cv_job_q_.notify_one();

		return job_result_future;
	}

}  // namespace ThreadPool

int work(int t, int id) 
{
	printf("%d start \n", id);
	std::this_thread::sleep_for(std::chrono::seconds(t));
	printf("%d end after %ds\n", id, t);
	return t + id;
}

int main() 
{
	ThreadPool::ThreadPool pool(3);

	std::vector<std::future<int>> futures;
	for (int i = 0; i < 10; i++) 
	{
		futures.emplace_back(pool.EnqueueJob(work, i % 3 + 1, i));
	}
	for (auto& f : futures) 
	{
		printf("result : %d \n", f.get());
	}

	getchar();
}
*/

/*
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace ThreadPool 
{
	class ThreadPool 
	{
	public:
		ThreadPool(size_t num_threads);
		~ThreadPool();

		// job �� �߰��Ѵ�.
		template <class F, class... Args>
		//std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(F f, Args... args);
		std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(F&& f, Args&&... args);


	private:
		// �� Worker �������� ����.
		size_t num_threads_;
		// Worker �����带 �����ϴ� ����.
		std::vector<std::thread> worker_threads_;
		// ���ϵ��� �����ϴ� job ť.
		std::queue<std::function<void()>> jobs_;
		// ���� job ť�� ���� cv �� m.
		std::condition_variable cv_job_q_;
		std::mutex m_job_q_;

		// ��� ������ ����
		bool stop_all;

		// Worker ������
		void WorkerThread();
	};

	ThreadPool::ThreadPool(size_t num_threads)
		: num_threads_(num_threads), stop_all(false) 
	{
		worker_threads_.reserve(num_threads_);

		for (size_t i = 0; i < num_threads_; ++i) 
		{
			worker_threads_.emplace_back([this]() { this->WorkerThread(); });
		}
	}

	void ThreadPool::WorkerThread() 
	{
		while (true) 
		{
			std::unique_lock<std::mutex> lock(m_job_q_);
			cv_job_q_.wait(lock, [this]() { return !this->jobs_.empty() || stop_all; });
			if (stop_all && this->jobs_.empty()) {
				return;
			}

			// �� ���� job �� ����.
			std::function<void()> job = std::move(jobs_.front());
			jobs_.pop();
			lock.unlock();

			// �ش� job �� �����Ѵ� :)
			job();
		}
	}

	ThreadPool::~ThreadPool() 
	{
		stop_all = true;
		cv_job_q_.notify_all();

		for (auto& t : worker_threads_) 
		{
			t.join();
		}
	}

	template <class F, class... Args>
	//std::future<typename std::result_of<F(Args...)>::type> ThreadPool::EnqueueJob(F f, Args... args)		// ���ڵ��� ���纻�� �޴´�
	std::future<typename std::result_of<F(Args...)>::type> ThreadPool::EnqueueJob(F&& f, Args&&... args)	// �Ϻ��� ���� ������ ���
	{
		if (stop_all) 
		{
			throw std::runtime_error("ThreadPool ��� ������");
		}

		using return_type = typename std::result_of<F(Args...)>::type;
		auto job =
			std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...)); // bind �Լ��� forward �� ���ڸ� ����, ���ʿ��� ���� ���� Enqueue �Լ��� ���ڵ��� �Ϻ��� ����
			//std::make_shared<std::packaged_task<return_type()>>(std::bind(f, args...));
		std::future<return_type> job_result_future = job->get_future();

		{
			std::lock_guard<std::mutex> lock(m_job_q_);
			jobs_.push([job]() { (*job)(); });
		}
		cv_job_q_.notify_one();

		return job_result_future;
	}

}  // namespace ThreadPool

int work(int t, int id) 
{
	printf("%d start \n", id);
	std::this_thread::sleep_for(std::chrono::seconds(t));
	printf("%d end after %ds\n", id, t);
	return t + id;
}

int main() 
{
	ThreadPool::ThreadPool pool(3);

	std::vector<std::future<int>> futures;
	for (int i = 0; i < 10; i++) 
	{
		futures.emplace_back(pool.EnqueueJob(work, i % 3 + 1, i));
	}
	for (auto& f : futures) 
	{
		printf("result : %d \n", f.get());
	}

	getchar();
}
*/



// ���� ThreadPool ���� ����

#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace ThreadPool {
	class ThreadPool {
	public:
		ThreadPool(size_t num_threads);
		~ThreadPool();

		// job �� �߰��Ѵ�.
		template <class F, class... Args>
		std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(
			F&& f, Args&&... args);

	private:
		// �� Worker �������� ����.
		size_t num_threads_;
		// Worker �����带 �����ϴ� ����.
		std::vector<std::thread> worker_threads_;
		// ���ϵ��� �����ϴ� job ť.
		std::queue<std::function<void()>> jobs_;
		// ���� job ť�� ���� cv �� m.
		std::condition_variable cv_job_q_;
		std::mutex m_job_q_;

		// ��� ������ ����
		bool stop_all;

		// Worker ������
		void WorkerThread();
	};

	ThreadPool::ThreadPool(size_t num_threads)
		: num_threads_(num_threads), stop_all(false) {
		worker_threads_.reserve(num_threads_);
		for (size_t i = 0; i < num_threads_; ++i) {
			worker_threads_.emplace_back([this]() { this->WorkerThread(); });
		}
	}

	void ThreadPool::WorkerThread() {
		while (true) {
			std::unique_lock<std::mutex> lock(m_job_q_);
			cv_job_q_.wait(lock, [this]() { return !this->jobs_.empty() || stop_all; });
			if (stop_all && this->jobs_.empty()) {
				return;
			}

			// �� ���� job �� ����.
			std::function<void()> job = std::move(jobs_.front());
			jobs_.pop();
			lock.unlock();

			// �ش� job �� �����Ѵ� :)
			job();
		}
	}

	ThreadPool::~ThreadPool() {
		stop_all = true;
		cv_job_q_.notify_all();

		for (auto& t : worker_threads_) {
			t.join();
		}
	}

	template <class F, class... Args>
	std::future<typename std::result_of<F(Args...)>::type> ThreadPool::EnqueueJob(
		F&& f, Args&&... args) {
		if (stop_all) {
			throw std::runtime_error("ThreadPool ��� ������");
		}

		using return_type = typename std::result_of<F(Args...)>::type;
		auto job = std::make_shared<std::packaged_task<return_type()>>(
			std::bind(std::forward<F>(f), std::forward<Args>(args)...));
		std::future<return_type> job_result_future = job->get_future();
		{
			std::lock_guard<std::mutex> lock(m_job_q_);
			jobs_.push([job]() { (*job)(); });
		}
		cv_job_q_.notify_one();

		return job_result_future;
	}

}  // namespace ThreadPool

   // ��� ����
int work(int t, int id) {
	printf("%d start \n", id);
	std::this_thread::sleep_for(std::chrono::seconds(t));
	printf("%d end after %ds\n", id, t);
	return t + id;
}

int main() {
	ThreadPool::ThreadPool pool(3);

	std::vector<std::future<int>> futures;
	for (int i = 0; i < 10; i++) {
		futures.emplace_back(pool.EnqueueJob(work, i % 3 + 1, i));
	}
	for (auto& f : futures) {
		printf("result : %d \n", f.get());
	}

	getchar();
}


