// ThreadTest.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/*
// 내 생에 첫 쓰레드
#include <iostream>
#include <thread>
using std::thread;

void func1() 
{
	for (int i = 0; i < 10; i++) 
	{
		std::cout << "쓰레드 1 작동중! \n";
	}
}

void func2() 
{
	for (int i = 0; i < 10; i++) 
	{
		std::cout << "쓰레드 2 작동중! \n";
	}
}

void func3() 
{
	for (int i = 0; i < 10; i++) 
	{
		std::cout << "쓰레드 3 작동중! \n";
	}
}
int main() 
{
	thread t1(func1);	// 쓰래드 생성 및 시작
	thread t2(func2);	// 쓰래드 생성 및 시작
	thread t3(func3);	// 쓰래드 생성 및 시작

	t1.join();			// 쓰래드 종료시 Return됨
	t2.join();			// 쓰래드 종료시 Return됨
	t3.join();			// 쓰래드 종료시 Return됨

	getchar();
}
*/

/*
#include <iostream>
#include <thread>
using std::thread;

void func1() {
	for (int i = 0; i < 10; i++) {
		std::cout << "쓰레드 1 작동중! \n";
	}
}

void func2() {
	for (int i = 0; i < 10; i++) {
		std::cout << "쓰레드 2 작동중! \n";
	}
}

void func3() {
	for (int i = 0; i < 10; i++) {
		std::cout << "쓰레드 3 작동중! \n";
	}
}
int main() {
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);

	t1.detach();		// 프로세스 종료시 자동으로 쓰래드 종료
	t2.detach();		// 프로세스 종료시 자동으로 쓰래드 종료
	t3.detach();		// 프로세스 종료시 자동으로 쓰래드 종료

	std::cout << "메인 함수 종료 \n";

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

	// 쓰레드의 id 를 구한다.
	thread::id this_id = std::this_thread::get_id();
	// printf는 컨텍스트 스위치가 되더라도 다른 쓰레드들이 그 사이에 메세지를 집어넣지 못하게 막습니다.
	//printf("쓰레드 %x 에서 %d 부터 %d 까지 계산한 결과 : %d \n", this_id, *start, *(end - 1), sum); 
	// std::cout << A << B의 경우 A 를 출력한 이후에 B 를 출력하기 전에 다른 쓰레드가 내용을 출력할 수 있습니다.
	std::cout << "쓰레드 " << std::hex << this_id << " 에서 " << std::dec << *start << " 부터 " << *(end - 1) << " 까지 계산한 결과 : " << sum << std::endl;
}

int main() 
{
	vector<int> data(10000);
	for (int i = 0; i < 10000; i++) 
	{
		data[i] = i;
	}

	// 각 쓰레드에서 계산된 부분 합들을 저장하는 벡터
	vector<int> partial_sums(4);

	vector<thread> workers;
	for (int i = 0; i < 4; i++) 
	{
		workers.push_back(thread(worker, data.begin() + i * 2500, data.begin() + (i + 1) * 2500, &partial_sums[i]));
	}

	// 모든 쓰레드에서 연산이 끝날 때까지 기다린다.
	for (int i = 0; i < 4; i++) 
	{
		workers[i].join();
	}

	int total = 0;
	for (int i = 0; i < 4; i++) 
	{
		total += partial_sums[i];
	}
	std::cout << "전체 합 : " << total << std::endl;

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
		// 레퍼런스로 전달하려면 ref 함수로 감싸야 한다 (지난 강좌 bind 함수 참조)
		workers.push_back(thread(worker, std::ref(counter)));
	}

	for (int i = 0; i < 4; i++) 
	{
		workers[i].join();
	}

	std::cout << "Counter 최종 값 : " << counter << std::endl;

	getchar();
}
*/

/*
#include <iostream>
#include <mutex>  // mutex 를 사용하기 위해 필요
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
	std::mutex m;  // 우리의 mutex 객체

	std::vector<std::thread> workers;
	for (int i = 0; i < 4; i++) 
	{
		workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)));
	}

	for (int i = 0; i < 4; i++) 
	{
		workers[i].join();
	}

	std::cout << "Counter 최종 값 : " << counter << std::endl;

	getchar();
}
*/

/*
#include <iostream>
#include <mutex>  // mutex 를 사용하기 위해 필요
#include <thread>
#include <vector>

void worker(int& result, std::mutex& m) 
{
	for (int i = 0; i < 10000; i++) 
	{
		// lock 생성 시에 m.lock() 을 실행한다고 보면 된다.
		std::lock_guard<std::mutex> lock(m);
		result += 1;

		// scope 를 빠져 나가면 lock 이 소멸되면서
		// m 을 알아서 unlock 한다.
	}
}

int main() 
{
	int counter = 0;
	std::mutex m;  // 우리의 mutex 객체

	std::vector<std::thread> workers;
	for (int i = 0; i < 4; i++) 
	{
		workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)));
	}

	for (int i = 0; i < 4; i++) 
	{
		workers[i].join();
	}

	std::cout << "Counter 최종 값 : " << counter << std::endl;

	getchar();
}
*/

/*
// 데드락이 발생하는 조건
#include <iostream>
#include <mutex>  // mutex 를 사용하기 위해 필요
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
	std::mutex m1, m2;  // 우리의 mutex 객체

	std::thread t1(worker1, std::ref(m1), std::ref(m2));
	std::thread t2(worker2, std::ref(m1), std::ref(m2));

	t1.join();
	t2.join();

	std::cout << "끝!" << std::endl;

	getchar();
}
*/


/*
#include <iostream>
#include <mutex>  // mutex 를 사용하기 위해 필요
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

			// m1 이 이미 lock 되어 있다면 "야 차 빼" 를 수행하게 된다.
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
	std::mutex m1, m2;  // 우리의 mutex 객체

	std::thread t1(worker1, std::ref(m1), std::ref(m2));
	std::thread t2(worker2, std::ref(m1), std::ref(m2));

	t1.join();
	t2.join();

	std::cout << "끝!" << std::endl;

	getchar();
}
*/

/*
// 생산자, 소비자
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
		// 웹사이트를 다운로드 하는데 걸리는 시간이라 생각하면 된다.
		// 각 쓰레드 별로 다운로드 하는데 걸리는 시간이 다르다.
		std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
		std::string content = "웹사이트 : " + std::to_string(i) + " from thread(" + std::to_string(index) + ")\n";

		// data 는 쓰레드 사이에서 공유되므로 critical section 에 넣어야 한다.
		m->lock();
		downloaded_pages->push(content);
		m->unlock();
	}
}

void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m, int* num_processed) 
{
	// 전체 처리하는 페이지 개수가 5 * 5 = 25 개.
	while (*num_processed < 25) 
	{
		m->lock();
		// 만일 현재 다운로드한 페이지가 없다면 다시 대기.
		if (downloaded_pages->empty()) 
		{
			m->unlock();  // (Quiz) 여기서 unlock 을 안한다면 어떻게 될까요?

						  // 10 밀리초 뒤에 다시 확인한다.
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			continue;
		}

		// 맨 앞의 페이지를 읽고 대기 목록에서 제거한다.
		std::string content = downloaded_pages->front();
		downloaded_pages->pop();

		(*num_processed)++;
		m->unlock();

		// content 를 처리한다.
		std::cout << content;
		std::this_thread::sleep_for(std::chrono::milliseconds(80));
	}
}

int main() 
{
	// 현재 다운로드한 페이지들 리스트로, 아직 처리되지 않은 것들이다.
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
		// 웹사이트를 다운로드 하는데 걸리는 시간이라 생각하면 된다.
		// 각 쓰레드 별로 다운로드 하는데 걸리는 시간이 다르다.
		std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
		std::string content = "웹사이트 : " + std::to_string(i) + " from thread(" +
			std::to_string(index) + ")\n";

		// data 는 쓰레드 사이에서 공유되므로 critical section 에 넣어야 한다.
		m->lock();
		downloaded_pages->push(content);
		m->unlock();

		// consumer 에게 content 가 준비되었음을 알린다.
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

		// 맨 앞의 페이지를 읽고 대기 목록에서 제거한다.
		std::string content = downloaded_pages->front();
		downloaded_pages->pop();

		(*num_processed)++;
		lk.unlock();

		// content 를 처리한다.
		std::cout << content;
		std::this_thread::sleep_for(std::chrono::milliseconds(80));
	}
}

int main() 
{
	// 현재 다운로드한 페이지들 리스트로, 아직 처리되지 않은 것들이다.
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

	// 나머지 자고 있는 쓰레드들을 모두 깨운다.
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

	std::cout << "Counter 최종 값 : " << counter << std::endl;

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
	b->store(1, memory_order_relaxed);      // b = 1 (쓰기)
	int x = a->load(memory_order_relaxed);  // x = a (읽기)

	printf("x : %d \n", x);
}

void t2(std::atomic<int>* a, std::atomic<int>* b) 
{
	a->store(1, memory_order_relaxed);      // a = 1 (쓰기)
	int y = b->load(memory_order_relaxed);  // y = b (읽기)

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
// 작업을 재배치 못하게 막을 필요가 없는 경우 : 어떤 스래드간에 하는 일이 그냥 1증가임.
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
using std::memory_order_relaxed;

void worker(std::atomic<int>* counter) 
{
	for (int i = 0; i < 10000; i++) 
	{
		// 다른 연산들 수행

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
// producer - consumer 관계 : 비동기
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
using std::memory_order_relaxed;

void producer(std::atomic<bool>* is_ready, int* data) 
{
	*data = 10;
	//is_ready->store(true, memory_order_relaxed); // 비동기
	is_ready->store(true, std::memory_order_release); // 동기 : 컴파일러가 *data = 10을 현재위치와 순서를 바꾸지 못하게 함.
}

void consumer(std::atomic<bool>* is_ready, int* data) 
{
	// data 가 준비될 때 까지 기다린다.
	//while (!is_ready->load(memory_order_relaxed)) // 비동기
	while (!is_ready->load(std::memory_order_acquire)) // 동기 : producer에서 store를 한경우에
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
// producer - consumer 관계 : 동기
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
	// data 가 준비될 때 까지 기다린다.
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
// 순차적 일관성(sequential consistency) : memory_order_seq_cst
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
// std::promise (생산자) 와 std::future (소비자)

#include <future>
#include <iostream>
#include <string>
#include <thread>
using std::string;

void worker(std::promise<string>* p) 
{
	// 약속을 이행하는 모습. 해당 결과는 future 에 들어간다.
	p->set_value("some data");
}

int main() 
{
	std::promise<string> p;

	// 미래에 string 데이터를 돌려 주겠다는 약속.
	std::future<string> data = p.get_future();

	std::thread t(worker, &p);

	// 미래에 약속된 데이터를 받을 때 까지 기다린다.
	data.wait();

	// wait 이 리턴했다는 뜻이 future 에 데이터가 준비되었다는 의미.
	// 참고로 wait 없이 그냥 get 해도 wait 한 것과 같다.
	std::cout << "받은 데이터 : " << data.get() << std::endl; // future 에서 get 을 호출하면, 설정된 객체가 이동하기때문에 절대로 get 을 두 번 호출하면 안됨.

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
		info = "some data";  // 위의 p->set_value("some data") 에 대응
		done = true;
	}
	cv.notify_all();
}

int main() 
{
	std::thread t(worker);

	std::unique_lock<std::mutex> lk(m);
	cv.wait(lk, [] { return done; });  // 위의 data.wait() 이라 보면 된다. : 조건이 false이면, lk는 lock상태에서 sleep모드로 들어감. 조건이 true이면, wait을 벗어남.
	lk.unlock();

	std::cout << "받은 데이터 : " << info << std::endl;

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
		// set_exception 에는 exception_ptr 를 전달해야 한다.
		p->set_exception(std::current_exception()); // catch 된 예외에 관한 정보를 반환하는 current_exception 함수가 리턴하는 객체 (make_exception_ptr 함수와 동일)
	}
}
int main() 
{
	std::promise<string> p;

	// 미래에 string 데이터를 돌려 주겠다는 약속.
	std::future<string> data = p.get_future();

	std::thread t(worker, &p);

	// 미래에 약속된 데이터를 받을 때 까지 기다린다.
	data.wait();

	try 
	{
		data.get();
	}
	catch (const std::exception& e) 
	{
		std::cout << "예외 : " << e.what() << std::endl;
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
	// void 의 경우 어떠한 객체도 전달하지 않지만, future 가 set 이 되었냐
	// 안되었느냐의 유무로 마치 플래그의 역할을 수행할 수 있습니다.
	std::promise<void> p;

	// 미래에 string 데이터를 돌려 주겠다는 약속.
	std::future<void> data = p.get_future();

	std::thread t(worker, &p);

	// 미래에 약속된 데이터를 받을 때 까지 기다린다.
	while (true) 
	{
		std::future_status status = data.wait_for(std::chrono::seconds(1)); // wait_for 에 전달된 시간 만큼 기다렸다가 바로 리턴
		// std::future_status 의 종류 [ std::future_status::ready , std::future_status::timeout , future_status::deferred ]
	
		// 아직 준비가 안됨
		if (status == std::future_status::timeout) 
		{
			std::cerr << ">";
		}
		// promise 가 future 를 설정함.
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
	std::cout << "출발!" << std::endl;
}

int main() 
{
	std::promise<void> p;
	std::shared_future<void> start = p.get_future(); // shared_future 의 경우 future 와는 다르게 복사가 가능 (레퍼런스나 포인터로 전달할 필요가 없음)

	thread t1(runner, start);
	thread t2(runner, start);
	thread t3(runner, start);
	thread t4(runner, start);

	// 참고로 cerr 는 std::cout 과는 다르게 버퍼를 사용하지 않기 때문에 터미널에
	// 바로 출력된다.
	std::cerr << "준비...";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cerr << "땅!" << std::endl;

	p.set_value();

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	getchar();
}
*/


/*
// packaged_task 를 사용하게 된다면 쓰레드에 굳이 promise 를 전달하지 않아도 알아서 packaged_task 가 함수의 리턴값을 처리

#include <future>
#include <iostream>
#include <thread>

int some_task(int x) { return 10 + x; }

int main() 
{
	// int(int) : int 를 리턴하고 인자로 int 를 받는 함수. (std::function 참조)
	std::packaged_task<int(int)> task(some_task);

	std::future<int> start = task.get_future();

	std::thread t(std::move(task), 5); // packaged_task 는 복사 생성이 불가능하므로 (promise 도 마찬가지 입니다.) 명시적으로 move 해줘야만 함.

	std::cout << "결과값 : " << start.get() << std::endl;
	t.join();

	getchar();
}
*/

/*
// std::async는 쓰레드를 알아서 만들어서 해당 함수를 비동기적으로 실행
#include <future>
#include <iostream>
#include <thread>
#include <vector>

// std::accumulate 와 동일
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
	// lower_half_future 는 1 ~ 500 까지 비동기적으로 더함
	// 참고로 람다 함수를 사용하면 좀 더 깔끔하게 표현할 수 도 있다.
	// --> std::async([&v]() { return sum(v, 0, v.size() / 2); });
	std::future<int> lower_half_future = std::async(std::launch::async, sum, cref(v), 0, v.size() / 2); // std::launch::async -> 바로 쓰레드를 생성해서 인자로 전달된 함수를 실행 (비동기)
																										// std::launch::deferred -> future 의 get 함수가 호출되었을 때 실행 (동기)

	// upper_half 는 501 부터 1000 까지 더함
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

	std::cout << "1 부터 1000 까지의 합 : " << parallel_sum(v) << std::endl;

	getchar();
}
*/

/*
#include <future>
#include <iostream>
#include <thread>

int do_work(int x) 
{
	// x 를 가지고 무슨 일을 한다.
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
	//double timeSecond = (double)(time / CLOCKS_PER_SEC); // 초 단위 변환

	//do_work_parallel(); 
	do_work_sequential(); 

	printf("The ellapsed time is %d [mSec].\n", (int)(clock() - time));

	getchar();
}
*/


// 쓰레드풀(ThreadPool) : 여러 개의 쓰레드들이 대기하고 있다가, 할 일이 들어오게 되면, 대기하고 있던 쓰레드들 중 하나가 이를 받아서 실행
// C++ 에는 일반적인 타입의 함수 포인터를 저장할 수 있는 컨테이너는 없음 : 일단은 void 형의 인자를 받지 않는 함수를 전달

// ThreadPool 첫 번째 버전
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

		// job 을 추가한다.
		void EnqueueJob(std::function<void()> job);

	private:
		// 총 Worker 쓰레드의 개수.
		size_t num_threads_;
		// Worker 쓰레드를 보관하는 벡터.
		std::vector<std::thread> worker_threads_;
		// 할일들을 보관하는 job 큐.
		std::queue<std::function<void()>> jobs_;
		// 위의 job 큐를 위한 cv 와 m.
		std::condition_variable cv_job_q_;
		std::mutex m_job_q_;

		// 모든 쓰레드 종료
		bool stop_all;

		// Worker 쓰레드
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

			// 맨 앞의 job 을 뺀다.
			std::function<void()> job = std::move(jobs_.front());
			jobs_.pop();
			lock.unlock();

			// 해당 job 을 수행한다 :)
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
			throw std::runtime_error("ThreadPool 사용 중지됨");
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



// 임의의 함수(return값) 받기 
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

		// job 을 추가한다.
		template <class F, class... Args> // class... : 가변 길이 템플릿으로 임의의 길이의 인자들을 받을 수 있음
		std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(F f, Args... args); // typename std::result_of<F(Args...)>::type : 함수 f 의 리턴값(std::result_of)의 type

	private:
		// 총 Worker 쓰레드의 개수.
		size_t num_threads_;
		// Worker 쓰레드를 보관하는 벡터.
		std::vector<std::thread> worker_threads_;
		// 할일들을 보관하는 job 큐.
		std::queue<std::function<void()>> jobs_;
		// 위의 job 큐를 위한 cv 와 m.
		std::condition_variable cv_job_q_;
		std::mutex m_job_q_;

		// 모든 쓰레드 종료
		bool stop_all;

		// Worker 쓰레드
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

			// 맨 앞의 job 을 뺀다.
			std::function<void()> job = std::move(jobs_.front());
			jobs_.pop();
			lock.unlock();

			// 해당 job 을 수행한다 :)
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
			throw std::runtime_error("ThreadPool 사용 중지됨");
		}
		//jobs_.push([f, args...]() { f(args...); }); // Worker 쓰레드 안에서 f(args...) 를 실행 할 수 있음. 단, f(args...) 의 리턴값을 얻을 길이 없음.

		using return_type = typename std::result_of<F(Args...)>::type;	// job 객체는 ThreadPool::EnqueueJob(F f, Args... args) 의 지역 변수 -> EnqueueJob 함수가 리턴하면 파괴됨. (해결책 : 1. packaged_task 를 따로 컨테이너에 저장, 2. shared_ptr 에 packaged_task 를 보관)
		//std::packaged_task<return_type()> job(std::bind(f, args...));	// 비동기적으로 실행되는 함수의 리턴값 (더 나아가 예외 까지) 받아내는 법 : packaged_task 를 이용
																		// packaged_task 의 생성자는 함수 만을 받기 때문에 job(std::bind(f, args...)처럼 인자들을 f 에 bind 시킴.
		//std::future<return_type> job_result_future = job.get_future();// job 의 실행 결과를 보관하는 job_result_future 를 정의
		auto job =														// (해결책 2) : packaged_task 를 사용하는 것이 없을 때 알아서 shared_ptr 가 객체를 소멸시켜주므로 훨씬 관리하기 편함. 
			std::make_shared<std::packaged_task<return_type()>>(std::bind(f, args...)); // make_shared 를 통해서 shared_ptr 을 생성
		std::future<return_type> job_result_future = job->get_future();

		{
			std::lock_guard<std::mutex> lock(m_job_q_);
			//jobs_.push([&job]() { job(); });							// obs_ 에 job 을 실행하는 람다 함수를 추가
			jobs_.push([job]() { (*job)(); });							// 람다 함수에 shared_ptr 의 복사본을 전달 , job 을 실행하는 시점에서도 packged_task 객체는 계속 살아있음
		}																// job 이 실행된다면, f 의 리턴값이 job_result_future 에 들어가게 되고, 이는 쓰레드풀 사용자가 접근할 수 있음
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

		// job 을 추가한다.
		template <class F, class... Args>
		//std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(F f, Args... args);
		std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(F&& f, Args&&... args);


	private:
		// 총 Worker 쓰레드의 개수.
		size_t num_threads_;
		// Worker 쓰레드를 보관하는 벡터.
		std::vector<std::thread> worker_threads_;
		// 할일들을 보관하는 job 큐.
		std::queue<std::function<void()>> jobs_;
		// 위의 job 큐를 위한 cv 와 m.
		std::condition_variable cv_job_q_;
		std::mutex m_job_q_;

		// 모든 쓰레드 종료
		bool stop_all;

		// Worker 쓰레드
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

			// 맨 앞의 job 을 뺀다.
			std::function<void()> job = std::move(jobs_.front());
			jobs_.pop();
			lock.unlock();

			// 해당 job 을 수행한다 :)
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
	//std::future<typename std::result_of<F(Args...)>::type> ThreadPool::EnqueueJob(F f, Args... args)		// 인자들의 복사본을 받는다
	std::future<typename std::result_of<F(Args...)>::type> ThreadPool::EnqueueJob(F&& f, Args&&... args)	// 완벽한 전달 패턴을 사용
	{
		if (stop_all) 
		{
			throw std::runtime_error("ThreadPool 사용 중지됨");
		}

		using return_type = typename std::result_of<F(Args...)>::type;
		auto job =
			std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...)); // bind 함수에 forward 로 인자를 전달, 불필요한 복사 없이 Enqueue 함수에 인자들을 완벽히 전달
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



// 최종 ThreadPool 구현 버전

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

		// job 을 추가한다.
		template <class F, class... Args>
		std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(
			F&& f, Args&&... args);

	private:
		// 총 Worker 쓰레드의 개수.
		size_t num_threads_;
		// Worker 쓰레드를 보관하는 벡터.
		std::vector<std::thread> worker_threads_;
		// 할일들을 보관하는 job 큐.
		std::queue<std::function<void()>> jobs_;
		// 위의 job 큐를 위한 cv 와 m.
		std::condition_variable cv_job_q_;
		std::mutex m_job_q_;

		// 모든 쓰레드 종료
		bool stop_all;

		// Worker 쓰레드
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

			// 맨 앞의 job 을 뺀다.
			std::function<void()> job = std::move(jobs_.front());
			jobs_.pop();
			lock.unlock();

			// 해당 job 을 수행한다 :)
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
			throw std::runtime_error("ThreadPool 사용 중지됨");
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

   // 사용 예시
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


