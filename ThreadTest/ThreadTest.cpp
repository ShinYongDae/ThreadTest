// ThreadTest.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

/*
// �� ���� ù ������
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

		cv->wait(lk, [&] { return !downloaded_pages->empty() || *num_processed == 25; });

		if (*num_processed == 25) 
		{
			lk.unlock();
			return;
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
	cv.notify_all();

	for (int i = 0; i < 3; i++) 
	{
		consumers[i].join();
	}

	getchar();
}