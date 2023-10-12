// ThreadTest.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/*
#include <iostream>

class A 
{
	int x;
public:
	A(int c) : x(c) {}
	A(const A& a) 
	{
		x = a.x;
		std::cout << "복사 생성" << std::endl;
	}
};

class B 
{
	A a;
public:
	B(int c) : a(c) {}
	B(const B& b) : a(b.a) {}
	A get_A() 
	{
		A temp(a);
		return temp;
	}
};

int main() 
{
	B b(10);
	std::cout << "---------" << std::endl;
	A a1 = b.get_A();

	getchar();
}
*/


/*
#include <iostream>
// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>
class MyString {
	char* string_content; // 문자열 데이터를 가리키는 포인터
	int string_length; // 문자열 길이
public:
	// 문자 하나로 생성
	MyString(char c);
	// 문자열로 부터 생성
	MyString(const char* str);
	// 복사 생성자
	MyString(const MyString& str);
	~MyString();
	int length() const;
	void print() const;
	void println() const;
};
MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
}
MyString::MyString(const char* str) {
	string_length = strlen(str);
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) {
		string_content[i] = str[i];
	}
}
MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }
void MyString::print() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
}
void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}
int main() {
	MyString str1("hello world!");
	MyString str2(str1);
	str1.println();
	str2.println();

	getchar();
}
*/


/*
#include <iostream>
// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>
class MyString 
{
	char* string_content; // 문자열 데이터를 가리키는 포인터
	int string_length; // 문자열 길이
	int memory_capacity; // 현재 할당된 용량
public:
	// 문자 하나로 생성
	MyString(char c);
	// 문자열로 부터 생성
	MyString(const char* str);
	// 복사 생성자
	MyString(const MyString& str);
	~MyString();
	int length() const;
	int capacity() const;
	void reserve(int size);
	void print() const;
	void println() const;
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
};

MyString::MyString(char c) 
{
	string_content = new char[1];
	string_content[0] = c;
	memory_capacity = 1;
	string_length = 1;
}

MyString::MyString(const char* str) 
{
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) 
	{
		string_content[i] = str[i];
	}
}

MyString::MyString(const MyString& str) 
{
	string_length = str.string_length;
	memory_capacity = str.string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) 
	{
		string_content[i] = str.string_content[i];
	}
}

MyString::~MyString() { delete[] string_content; }

int MyString::length() const { return string_length; }

void MyString::print() const 
{
	for (int i = 0; i != string_length; i++) 
	{
		std::cout << string_content[i];
	}
}

void MyString::println() const 
{
	for (int i = 0; i != string_length; i++) 
	{
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) 
{
	if (str.string_length > memory_capacity) 
	{
		// 그러면 다시 할당을 해줘야만 한다.
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) 
	{
		string_content[i] = str.string_content[i];
	}
	// 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
	// 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.
	string_length = str.string_length;
	return *this;
}

MyString& MyString::assign(const char* str) 
{
	int str_length = strlen(str);
	if (str_length > memory_capacity) 
	{
		// 그러면 다시 할당을 해줘야만 한다.
		delete[] string_content;
		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	for (int i = 0; i != str_length; i++) 
	{
		string_content[i] = str[i];
	}
	string_length = str_length;
	return *this;
}

int MyString::capacity() const { return memory_capacity; }

void MyString::reserve(int size) 
{
	if (size > memory_capacity) 
	{
		char* prev_string_content = string_content;
		string_content = new char[size];
		memory_capacity = size;
		for (int i = 0; i != string_length; i++)
			string_content[i] = prev_string_content[i];
		delete[] prev_string_content;
	}
	// 만일 예약하려는 size 가 현재 capacity 보다 작다면
	// 아무것도 안해도 된다.
}

int main() 
{
	MyString str1("very very very long string");
	str1.reserve(30);
	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();

	getchar();
}
*/

/*
#include <iostream>
// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>
class MyString {
	char* string_content; // 문자열 데이터를 가리키는 포인터
	int string_length; // 문자열 길이
	int memory_capacity; // 현재 할당된 용량
public:
	// 문자 하나로 생성
	MyString(char c);
	// 문자열로 부터 생성
	MyString(const char* str);
	// 복사 생성자
	MyString(const MyString& str);
	~MyString();
	int length() const;
	int capacity() const;
	void reserve(int size);
	void print() const;
	void println() const;
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
	char at(int i) const;
	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);
};
MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	memory_capacity = 1;
	string_length = 1;
}
MyString::MyString(const char* str) {
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) {
		string_content[i] = str[i];
	}
}
MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	memory_capacity = str.string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }
void MyString::print() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
}
void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}
MyString& MyString::assign(const MyString& str) {
	if (str.string_length > memory_capacity) {
		// 그러면 다시 할당을 해줘야만 한다.
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}
	// 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
	// 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.
	string_length = str.string_length;
	return *this;
}
MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length > memory_capacity) {
		// 그러면 다시 할당을 해줘야만 한다.
		delete[] string_content;
		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	for (int i = 0; i != str_length; i++) {
		string_content[i] = str[i];
	}
	string_length = str_length;
	return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = string_content;
		string_content = new char[size];
		memory_capacity = size;
		for (int i = 0; i != string_length; i++)
			string_content[i] = prev_string_content[i];
		delete[] prev_string_content;
	}
	// 만일 예약하려는 size 가 현재 capacity 보다 작다면
	// 아무것도 안해도 된다.
}
char MyString::at(int i) const {
	if (i >= string_length || i < 0) {
		return 0;
	}
	else {
		return string_content[i];
	}
}
MyString& MyString::insert(int loc, const MyString& str) {
	// 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
	// abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.
	// 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
	if (loc < 0 || loc > string_length) {
		return *this;
	}
	if (string_length + str.string_length > memory_capacity) {
		// 이제 새롭게 동적으로 할당을 해야 한다.
		memory_capacity = string_length + str.string_length;
		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];
		// 일단 insert 되는 부분 직전까지의 내용을 복사한다.
		int i;
		for (i = 0; i < loc; i++) {
			string_content[i] = prev_string_content[i];
		}
		// 그리고 새롭에 insert 되는 문자열을 넣는다.
		for (int j = 0; j != str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}
		// 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
		for (; i < string_length; i++) {
			string_content[str.string_length + i] = prev_string_content[i];
		}
		delete[] prev_string_content;
		string_length = string_length + str.string_length;
		return *this;
	}
	// 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
	// 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.
	for (int i = string_length - 1; i >= loc; i--) {
		// 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
		string_content[i + str.string_length] = string_content[i];
	}
	// 그리고 insert 되는 문자 다시 집어넣기
	for (int i = 0; i < str.string_length; i++)
		string_content[i + loc] = str.string_content[i];
	string_length = string_length + str.string_length;
	return *this;
}
MyString& MyString::insert(int loc, const char* str) {
	MyString temp(str);
	return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
	MyString temp(c);
	return insert(loc, temp);
}
int main() {
	MyString str1("very long string");
	MyString str2("<some string inserted between>");
	str1.reserve(30);
	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();
	str1.insert(5, str2);
	str1.println();

	getchar();
}
*/


/*
#include <iostream>
// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>
class MyString {
	char* string_content; // 문자열 데이터를 가리키는 포인터
	int string_length; // 문자열 길이
	int memory_capacity; // 현재 할당된 용량
public:
	// 문자 하나로 생성
	MyString(char c);
	// 문자열로 부터 생성
	MyString(const char* str);
	// 복사 생성자
	MyString(const MyString& str);
	~MyString();
	int length() const;
	int capacity() const;
	void reserve(int size);
	void print() const;
	void println() const;
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
	char at(int i) const;
	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);
	MyString& erase(int loc, int num);
};
MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	memory_capacity = 1;
	string_length = 1;
}
MyString::MyString(const char* str) {
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) {
		string_content[i] = str[i];
	}
}
MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	memory_capacity = str.string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }
void MyString::print() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
}
void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}
MyString& MyString::assign(const MyString& str) {
	if (str.string_length > memory_capacity) {
		// 그러면 다시 할당을 해줘야만 한다.
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}
	// 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
	// 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.
	string_length = str.string_length;
	return *this;
}
MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length > memory_capacity) {
		// 그러면 다시 할당을 해줘야만 한다.
		delete[] string_content;
		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	for (int i = 0; i != str_length; i++) {
		string_content[i] = str[i];
	}
	string_length = str_length;
	return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = string_content;
		string_content = new char[size];
		memory_capacity = size;
		for (int i = 0; i != string_length; i++)
			string_content[i] = prev_string_content[i];
		delete[] prev_string_content;
	}
	// 만일 예약하려는 size 가 현재 capacity 보다 작다면
	// 아무것도 안해도 된다.
}
char MyString::at(int i) const {
	if (i >= string_length || i < 0) {
		return 0;
	}
	else {
		return string_content[i];
	}
}
MyString& MyString::insert(int loc, const MyString& str) {
	// 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
	// abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.
	// 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
	if (loc < 0 || loc > string_length) return *this;
	if (string_length + str.string_length > memory_capacity) {
		// 이제 새롭게 동적으로 할당을 해야 한다.
		if (memory_capacity * 2 > string_length + str.string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + str.string_length;
		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];
		// 일단 insert 되는 부분 직전까지의 내용을 복사한다.
		int i;
		for (i = 0; i < loc; i++) {
			string_content[i] = prev_string_content[i];
		}
		// 그리고 새롭에 insert 되는 문자열을 넣는다.
		for (int j = 0; j != str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}
		// 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
		for (; i < string_length; i++) {
			string_content[str.string_length + i] = prev_string_content[i];
		}
		delete[] prev_string_content;
		string_length = string_length + str.string_length;
		return *this;
	}
	// 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
	// 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.
	for (int i = string_length - 1; i >= loc; i--) {
		// 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
		string_content[i + str.string_length] = string_content[i];
	}
	// 그리고 insert 되는 문자 다시 집어넣기
	for (int i = 0; i < str.string_length; i++)
		string_content[i + loc] = str.string_content[i];
	string_length = string_length + str.string_length;
	return *this;
}
MyString& MyString::insert(int loc, const char* str) {
	MyString temp(str);
	return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
	MyString temp(c);
	return insert(loc, temp);
}
MyString& MyString::erase(int loc, int num) {
	// loc 의 앞 부터 시작해서 num 문자를 지운다.
	if (num < 0 || loc < 0 || loc > string_length) return *this;
	// 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고
	// 생각하면 됩니다.
	for (int i = loc + num; i < string_length; i++) {
		string_content[i - num] = string_content[i];
	}
	string_length -= num;
	return *this;
}
int main() {
	MyString str1("very long string");
	MyString str2("<some string inserted between>");
	str1.reserve(30);
	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();
	str1.insert(5, str2);
	str1.println();
	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();

	getchar();
}
*/


/*
#include <iostream>
// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>
class MyString {
	char* string_content; // 문자열 데이터를 가리키는 포인터
	int string_length; // 문자열 길이
	int memory_capacity; // 현재 할당된 용량
public:
	// 문자 하나로 생성
	MyString(char c);
	// 문자열로 부터 생성
	MyString(const char* str);
	// 복사 생성자
	MyString(const MyString& str);
	~MyString();
	int length() const;
	int capacity() const;
	void reserve(int size);
	void print() const;
	void println() const;
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
	char at(int i) const;
	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);
	MyString& erase(int loc, int num);
	int find(int find_from, const MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;
};
MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	memory_capacity = 1;
	string_length = 1;
}
MyString::MyString(const char* str) {
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) {
		string_content[i] = str[i];
	}
}
MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	memory_capacity = str.string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }
void MyString::print() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
}
void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}
MyString& MyString::assign(const MyString& str) {
	if (str.string_length > memory_capacity) {
		// 그러면 다시 할당을 해줘야만 한다.
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}
	// 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
	// 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.
	string_length = str.string_length;
	return *this;
}
MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length > memory_capacity) {
		// 그러면 다시 할당을 해줘야만 한다.
		delete[] string_content;
		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	for (int i = 0; i != str_length; i++) {
		string_content[i] = str[i];
	}
	string_length = str_length;
	return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = string_content;
		string_content = new char[size];
		memory_capacity = size;
		for (int i = 0; i != string_length; i++)
			string_content[i] = prev_string_content[i];
		delete[] prev_string_content;
	}
	// 만일 예약하려는 size 가 현재 capacity 보다 작다면
	// 아무것도 안해도 된다.
}
char MyString::at(int i) const {
	if (i >= string_length || i < 0) {
		return 0;
	}
	else {
		return string_content[i];
	}
}
MyString& MyString::insert(int loc, const MyString& str) {
	// 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
	// abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.
	// 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
	if (loc < 0 || loc > string_length) return *this;
	if (string_length + str.string_length > memory_capacity) {
		// 이제 새롭게 동적으로 할당을 해야 한다.
		if (memory_capacity * 2 > string_length + str.string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + str.string_length;
		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];
		// 일단 insert 되는 부분 직전까지의 내용을 복사한다.
		int i;
		for (i = 0; i < loc; i++) {
			string_content[i] = prev_string_content[i];
		}
		// 그리고 새롭에 insert 되는 문자열을 넣는다.
		for (int j = 0; j != str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}
		// 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
		for (; i < string_length; i++) {
			string_content[str.string_length + i] = prev_string_content[i];
		}
		delete[] prev_string_content;
		string_length = string_length + str.string_length;
		return *this;
	}
	// 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
	// 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.
	for (int i = string_length - 1; i >= loc; i--) {
		// 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
		string_content[i + str.string_length] = string_content[i];
	}
	// 그리고 insert 되는 문자 다시 집어넣기
	for (int i = 0; i < str.string_length; i++)
		string_content[i + loc] = str.string_content[i];
	string_length = string_length + str.string_length;
	return *this;
}
MyString& MyString::insert(int loc, const char* str) {
	MyString temp(str);
	return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
	MyString temp(c);
	return insert(loc, temp);
}
MyString& MyString::erase(int loc, int num) {
	// loc 의 앞 부터 시작해서 num 문자를 지운다.
	if (num < 0 || loc < 0 || loc > string_length) return *this;
	// 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고
	// 생각하면 됩니다.
	for (int i = loc + num; i < string_length; i++) {
		string_content[i - num] = string_content[i];
	}
	string_length -= num;
	return *this;
}
int MyString::find(int find_from, const MyString& str) const {
	int i, j;
	if (str.string_length == 0) return -1;
	for (i = find_from; i <= string_length - str.string_length; i++) {
		for (j = 0; j < str.string_length; j++) {
			if (string_content[i + j] != str.string_content[j]) break;
		}
		if (j == str.string_length) return i;
	}
	return -1; // 찾지 못했음
}
int MyString::find(int find_from, const char* str) const {
	MyString temp(str);
	return find(find_from, temp);
}
int MyString::find(int find_from, char c) const {
	MyString temp(c);
	return find(find_from, temp);
}
int main() {
	MyString str1("this is a very very long string");
	std::cout << "Location of first <very> in the string : " << str1.find(0, "very")
		<< std::endl;
	std::cout << "Location of second <very> in the string : "
		<< str1.find(str1.find(0, "very") + 1, "very") << std::endl;

	getchar();
}
*/

/*
#include <iostream>
// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>
#include <algorithm>

class MyString 
{
	char* string_content; // 문자열 데이터를 가리키는 포인터
	int string_length; // 문자열 길이
	int memory_capacity; // 현재 할당된 용량
public:
	// 문자 하나로 생성
	MyString(char c);
	// 문자열로 부터 생성
	MyString(const char* str);
	// 복사 생성자
	MyString(const MyString& str);
	~MyString();
	int length() const;
	int capacity() const;
	void reserve(int size);
	void print() const;
	void println() const;
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
	char at(int i) const;
	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);
	MyString& erase(int loc, int num);
	int find(int find_from, const MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;
	int compare(const MyString& str) const;
};

MyString::MyString(char c) 
{
	string_content = new char[1];
	string_content[0] = c;
	memory_capacity = 1;
	string_length = 1;
}

MyString::MyString(const char* str) 
{
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) 
	{
		string_content[i] = str[i];
	}
}

MyString::MyString(const MyString& str) 
{
	string_length = str.string_length;
	memory_capacity = str.string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) 
	{
		string_content[i] = str.string_content[i];
	}
}

MyString::~MyString() { delete[] string_content; }

int MyString::length() const { return string_length; }

void MyString::print() const 
{
	for (int i = 0; i != string_length; i++) 
	{
		std::cout << string_content[i];
	}
}

void MyString::println() const 
{
	for (int i = 0; i != string_length; i++) 
	{
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) 
{
	if (str.string_length > memory_capacity) 
	{
		// 그러면 다시 할당을 해줘야만 한다.
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) 
	{
		string_content[i] = str.string_content[i];
	}
	// 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
	// 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.
	string_length = str.string_length;
	return *this;
}

MyString& MyString::assign(const char* str) 
{
	int str_length = strlen(str);
	if (str_length > memory_capacity) 
	{
		// 그러면 다시 할당을 해줘야만 한다.
		delete[] string_content;
		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	for (int i = 0; i != str_length; i++) 
	{
		string_content[i] = str[i];
	}
	string_length = str_length;
	return *this;
}

int MyString::capacity() const { return memory_capacity; }

void MyString::reserve(int size) 
{
	if (size > memory_capacity) 
	{
		char* prev_string_content = string_content;
		string_content = new char[size];
		memory_capacity = size;
		for (int i = 0; i != string_length; i++)
			string_content[i] = prev_string_content[i];
		delete[] prev_string_content;
	}
	// 만일 예약하려는 size 가 현재 capacity 보다 작다면
	// 아무것도 안해도 된다.
}

char MyString::at(int i) const 
{
	if (i >= string_length || i < 0) 
	{
		return 0;
	}
	else {
		return string_content[i];
	}
}

MyString& MyString::insert(int loc, const MyString& str) 
{
	// 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
	// abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.
	// 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
	if (loc < 0 || loc > string_length) return *this;

	if (string_length + str.string_length > memory_capacity) 
	{
		// 이제 새롭게 동적으로 할당을 해야 한다.
		if (memory_capacity * 2 > string_length + str.string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + str.string_length;
		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];
		// 일단 insert 되는 부분 직전까지의 내용을 복사한다.
		int i;
		for (i = 0; i < loc; i++) 
		{
			string_content[i] = prev_string_content[i];
		}
		// 그리고 새롭에 insert 되는 문자열을 넣는다.
		for (int j = 0; j != str.string_length; j++) 
		{
			string_content[i + j] = str.string_content[j];
		}
		// 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
		for (; i < string_length; i++) 
		{
			string_content[str.string_length + i] = prev_string_content[i];
		}
		delete[] prev_string_content;
		string_length = string_length + str.string_length;
		return *this;
	}
	// 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
	// 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.
	for (int i = string_length - 1; i >= loc; i--) 
	{
		// 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
		string_content[i + str.string_length] = string_content[i];
	}
	// 그리고 insert 되는 문자 다시 집어넣기
	for (int i = 0; i < str.string_length; i++)
		string_content[i + loc] = str.string_content[i];

	string_length = string_length + str.string_length;
	return *this;
}

MyString& MyString::insert(int loc, const char* str) 
{
	MyString temp(str);
	return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) 
{
	MyString temp(c);
	return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) 
{
	// loc 의 앞 부터 시작해서 num 문자를 지운다.
	if (num < 0 || loc < 0 || loc > string_length) return *this;
	// 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고
	// 생각하면 됩니다.
	for (int i = loc + num; i < string_length; i++) 
	{
		string_content[i - num] = string_content[i];
	}
	string_length -= num;
	return *this;
}

int MyString::find(int find_from, const MyString& str) const 
{
	int i, j;
	if (str.string_length == 0) return -1;
	for (i = find_from; i <= string_length - str.string_length; i++) 
	{
		for (j = 0; j < str.string_length; j++) 
		{
			if (string_content[i + j] != str.string_content[j]) break;
		}
		if (j == str.string_length) return i;
	}
	return -1; // 찾지 못했음
}

int MyString::find(int find_from, const char* str) const 
{
	MyString temp(str);
	return find(find_from, temp);
}

int MyString::find(int find_from, char c) const 
{
	MyString temp(c);
	return find(find_from, temp);
}

int MyString::compare(const MyString& str) const 
{
	// (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다
	// 1 은 (*this) 가 사전식으로 더 뒤에 온다는 의미. 0 은 두 문자열
	// 이 같다는 의미, -1 은 (*this) 가 사전식으로 더 앞에 온다는 의미이다.
	for (int i = 0; i < std::min(string_length, str.string_length); i++) 
	{
		if (string_content[i] > str.string_content[i])
			return 1;
		else if (string_content[i] < str.string_content[i])
			return -1;
	}
	// 여기 까지 했는데 끝나지 않았다면 앞 부분 까지 모두 똑같은 것이 된다.
	// 만일 문자열 길이가 같다면 두 문자열은 아예 같은 문자열이 된다.
	if (string_length == str.string_length) return 0;
	// 참고로 abc 와 abcd 의 크기 비교는 abcd 가 더 뒤에 오게 된다.
	else if (string_length > str.string_length)
		return 1;
	return -1;
}

int main() 
{
	MyString str1("abcdef");
	MyString str2("abcde");
	std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;

	getchar();
}
*/


/*
#include <iostream>
class MyString 
{
	char* string_content; // 문자열 데이터를 가리키는 포인터
	int string_length; // 문자열 길이
	int memory_capacity;
public:
	// capacity 만큼 미리 할당함. (explicit 키워드에 주목)
	explicit MyString(int capacity);
	//MyString(int capacity) {};
	// 문자열로 부터 생성
	MyString(const char* str) {};
	// 복사 생성자
	MyString(const MyString& str) {};
	~MyString() {};
	int length() const { return string_length; };
	int capacity() const { return memory_capacity; };
};

// .. (생략) ..
void DoSomethingWithString(MyString s) 
{
	// Do something...
}

int main() 
{
	DoSomethingWithString(3); // ????
}
*/

/*
#include <iostream>
class A 
{
	//int data_;
	mutable int data_;

public:
	A(int data) : data_(data) {}
	void DoSomething(int x) const 
	{
		data_ = x; // 불가능!
	}
	void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main() 
{
	A a(10);
	a.DoSomething(3);
	a.PrintData();

	getchar();
}
*/


/*
#include <string.h>
#include <iostream>
#include <algorithm>
class MyString {
	char* string_content; // 문자열 데이터를 가리키는 포인터
	int string_length; // 문자열 길이
	int memory_capacity; // 현재 할당된 용량
public:
	// 문자 하나로 생성
	MyString(char c);
	// 문자열로 부터 생성
	MyString(const char* str);
	// 복사 생성자
	MyString(const MyString& str);
	~MyString();
	int length() const;
	int capacity() const;
	void reserve(int size);
	void print() const;
	void println() const;
	char at(int i) const;
	int compare(MyString& str);
	bool operator==(MyString& str);
};
MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	memory_capacity = 1;
	string_length = 1;
}
MyString::MyString(const char* str) {
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }
void MyString::print() const {
	for (int i = 0; i != string_length; i++) std::cout << string_content[i];
}
void MyString::println() const {
	for (int i = 0; i != string_length; i++) std::cout << string_content[i];
	std::cout << std::endl;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = string_content;
		string_content = new char[size];
		memory_capacity = size;
		for (int i = 0; i != string_length; i++)
			string_content[i] = prev_string_content[i];
		delete[] prev_string_content;
	}
	// 만일 예약하려는 size 가 현재 capacity 보다 작다면
	// 아무것도 안해도 된다.
}
char MyString::at(int i) const {
	if (i >= string_length || i < 0)
		return 0;
	else
		return string_content[i];
}
int MyString::compare(MyString& str) {
	// (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다
	// 1 은 (*this) 가 사전식으로 더 뒤에 온다는 의미. 0 은 두 문자열
	// 이 같다는 의미, -1 은 (*this) 사 사전식으러 더 앞에 온다는 의미이다.
	for (int i = 0; i < std::min(string_length, str.string_length); i++) {
		if (string_content[i] > str.string_content[i])
			return 1;
		else if (string_content[i] < str.string_content[i])
			return -1;
	}
	// 여기 까지 했는데 끝나지 않았다면 앞 부분 까지 모두 똑같은 것이 된다.
	// 만일 문자열 길이가 같다면 두 문자열은 아예 같은 문자열이 된다.
	if (string_length == str.string_length) return 0;
	// 참고로 abc 와 abcd 의 크기 비교는 abcd 가 더 뒤에 오게 된다.
	else if (string_length > str.string_length)
		return 1;
	return -1;
}
bool MyString::operator==(MyString& str) {
	return !compare(str); // str 과 같으면 compare 에서 0 을 리턴한다.
}
int main() {
	MyString str1("a word");
	MyString str2("sentence");
	MyString str3("sentence");
	if (str1 == str2)
		std::cout << "str1 와 str2 같다." << std::endl;
	else
		std::cout << "st1 와 str2 는 다르다." << std::endl;
	if (str2 == str3)
		std::cout << "str2 와 str3 는 같다." << std::endl;
	else
		std::cout << "st2 와 str3 는 다르다" << std::endl;

	getchar();
}
*/


/*
#include <iostream>
class Complex {
private:
	double real, img;
public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);
	void println() {
		std::cout << "( " << real << " , " << img << " ) " << std::endl;
	}
};
Complex Complex::operator+(const Complex& c) {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex Complex::operator-(const Complex& c) {
	Complex temp(real - c.real, img - c.img);
	return temp;
}
Complex Complex::operator*(const Complex& c) {
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}
Complex Complex::operator/(const Complex& c) {
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}
int main() {
	Complex a(1.0, 2.0);
	Complex b(3.0, -2.0);
	Complex c = b + a;
	Complex d = b - a;
	c.println();
	d.println();

	getchar();
}
*/


/*
#include <iostream>
class Complex {
private:
	double real, img;
public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);
	//Complex& operator=(const Complex& c);
	void println() {
		std::cout << "( " << real << " , " << img << " ) " << std::endl;
	}
};
Complex Complex::operator+(const Complex& c) {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex Complex::operator-(const Complex& c) {
	Complex temp(real - c.real, img - c.img);
	return temp;
}
Complex Complex::operator*(const Complex& c) {
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}
Complex Complex::operator/(const Complex& c) {
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}
//Complex& Complex::operator=(const Complex& c) {
//	real = c.real;
//	img = c.img;
//	return *this;
//}
int main() {
	Complex a(1.0, 2.0);
	Complex b(3.0, -2.0);
	Complex c(0.0, 0.0);
	c = a * b + a / b + a + b;
	c.println();

	getchar();
}
*/


/*
#include <iostream>
class Complex {
private:
	double real, img;
public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);
	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);
	void println() {
		std::cout << "( " << real << " , " << img << " ) " << std::endl;
	}
};
Complex Complex::operator+(const Complex& c) {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex Complex::operator-(const Complex& c) {
	Complex temp(real - c.real, img - c.img);
	return temp;
}
Complex Complex::operator*(const Complex& c) {
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}
Complex Complex::operator/(const Complex& c) {
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}
Complex& Complex::operator+=(const Complex& c) {
	(*this) = (*this) + c;
	return *this;
}
Complex& Complex::operator-=(const Complex& c) {
	(*this) = (*this) - c;
	return *this;
}
Complex& Complex::operator*=(const Complex& c) {
	(*this) = (*this) * c;
	return *this;
}
Complex& Complex::operator/=(const Complex& c) {
	(*this) = (*this) / c;
	return *this;
}
int main() {
	Complex a(1.0, 2.0);
	Complex b(3.0, -2.0);
	a += b;
	a.println();
	b.println();

	getchar();
}
*/


/*
#include <iostream>
#include <cstring>
class Complex {
private:
	double real, img;
	double get_number(const char* str, int from, int to);
public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex(const char* str);
	Complex operator+(const Complex& c);
	Complex operator+(const char* str);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);
	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);
	Complex& operator=(const Complex& c);
	void println() {
		std::cout << "( " << real << " , " << img << " ) " << std::endl;
	}
};
Complex::Complex(const char* str) {
	// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
	// 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
	// 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)
	int begin = 0, end = strlen(str);
	img = 0.0;
	real = 0.0;
	// 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
	int pos_i = -1;
	for (int i = 0; i != end; i++) {
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}
	// 만일 'i' 가 없다면 이 수는 실수 뿐이다.
	if (pos_i == -1) {
		real = get_number(str, begin, end - 1);
		return;
	}
	// 만일 'i' 가 있다면, 실수부와 허수부를 나누어서 처리하면 된다.
	real = get_number(str, begin, pos_i - 1);
	img = get_number(str, pos_i + 1, end - 1);
	if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
Complex Complex::operator+(const Complex& c) {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
double Complex::get_number(const char* str, int from, int to) {
	bool minus = false;
	if (from > to) return 0;
	if (str[from] == '-') minus = true;
	if (str[from] == '-' || str[from] == '+') from++;
	double num = 0.0;
	double decimal = 1.0;
	bool integer_part = true;
	for (int i = from; i <= to; i++) {
		if (isdigit(str[i]) && integer_part) {
			num *= 10.0;
			num += (str[i] - '0');
		}
		else if (str[i] == '.')
			integer_part = false;
		else if (isdigit(str[i]) && !integer_part) {
			decimal /= 10.0;
			num += ((str[i] - '0') * decimal);
		}
		else
			break; // 그 이외의 이상한 문자들이 올 경우
	}
	if (minus) num *= -1.0;
	return num;
}

//Complex Complex::operator+(const char* str) {
//	// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
//	// 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
//	// 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)
//	int begin = 0, end = strlen(str);
//	double str_img = 0.0, str_real = 0.0;
//	// 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
//	int pos_i = -1;
//	for (int i = 0; i != end; i++) {
//		if (str[i] == 'i') {
//			pos_i = i;
//			break;
//		}
//	}
//	// 만일 'i' 가 없다면 이 수는 실수 뿐이다.
//	if (pos_i == -1) {
//		str_real = get_number(str, begin, end - 1);
//		Complex temp(str_real, str_img);
//		return (*this) + temp;
//	}
//	// 만일 'i' 가 있다면, 실수부와 허수부를 나누어서 처리하면 된다.
//	str_real = get_number(str, begin, pos_i - 1);
//	str_img = get_number(str, pos_i + 1, end - 1);
//	if (pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0;
//	Complex temp(str_real, str_img);
//	return (*this) + temp;
//}

Complex Complex::operator+(const char* str) {
	Complex temp(str);
	return (*this) + temp;
}

Complex Complex::operator-(const Complex& c) {
	Complex temp(real - c.real, img - c.img);
	return temp;
}
Complex Complex::operator*(const Complex& c) {
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}
Complex Complex::operator/(const Complex& c) {
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}
Complex& Complex::operator+=(const Complex& c) {
	(*this) = (*this) + c;
	return *this;
}
Complex& Complex::operator-=(const Complex& c) {
	(*this) = (*this) - c;
	return *this;
}
Complex& Complex::operator*=(const Complex& c) {
	(*this) = (*this) * c;
	return *this;
}
Complex& Complex::operator/=(const Complex& c) {
	(*this) = (*this) / c;
	return *this;
}
Complex& Complex::operator=(const Complex& c) {
	real = c.real;
	img = c.img;
	return *this;
}
int main() {
	Complex a(0, 0);
	a = a + "-1.1 + i3.923";
	a.println();

	getchar();
}
*/


/*
#include <cstring>
#include <iostream>
class Complex {
private:
	double real, img;
	double get_number(const char* str, int from, int to);
public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex(const char* str);
	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);
	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);
	Complex& operator=(const Complex& c);
	void println() {
		std::cout << "( " << real << " , " << img << " ) " << std::endl;
	}

	friend Complex operator+(const Complex& a, const Complex& b);
};

//Complex operator+(const Complex& a, const Complex& b) { return a.operator+(b); } // const Complex& a : a is const.
//Complex operator+(const Complex& a, const Complex& b) { return a + b; } // 재귀적 호출로 무한반복 실행. 
//Complex operator+(const Complex& a, const Complex& b) {
//	Complex temp(a);
//	return temp.operator+(b);
//	//return temp + b;
//}
Complex operator+(const Complex& a, const Complex& b) {
	Complex temp(a.real + b.real, a.img + b.img);
	return temp;
}

Complex::Complex(const char* str) {
	// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
	// 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
	// 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)
	int begin = 0, end = strlen(str);
	img = 0.0;
	real = 0.0;
	// 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
	int pos_i = -1;
	for (int i = 0; i != end; i++) {
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}
	// 만일 'i' 가 없다면 이 수는 실수 뿐이다.
	if (pos_i == -1) {
		real = get_number(str, begin, end - 1);
		return;
	}
	// 만일 'i' 가 있다면, 실수부와 허수부를 나누어서 처리하면 된다.
	real = get_number(str, begin, pos_i - 1);
	img = get_number(str, pos_i + 1, end - 1);
	if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) {
	bool minus = false;
	if (from > to) return 0;
	if (str[from] == '-') minus = true;
	if (str[from] == '-' || str[from] == '+') from++;
	double num = 0.0;
	double decimal = 1.0;
	bool integer_part = true;
	for (int i = from; i <= to; i++) {
		if (isdigit(str[i]) && integer_part) {
			num *= 10.0;
			num += (str[i] - '0');
		}
		else if (str[i] == '.')
			integer_part = false;
		else if (isdigit(str[i]) && !integer_part) {
			decimal /= 10.0;
			num += ((str[i] - '0') * decimal);
		}
		else
			break; // 그 이외의 이상한 문자들이 올 경우
	}
	if (minus) num *= -1.0;
	return num;
}
Complex Complex::operator+(const Complex& c) {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex Complex::operator-(const Complex& c) {
	Complex temp(real - c.real, img - c.img);
	return temp;
}
Complex Complex::operator*(const Complex& c) {
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}
Complex Complex::operator/(const Complex& c) {
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}
Complex& Complex::operator+=(const Complex& c) {
	(*this) = (*this) + c;
	return *this;
}
Complex& Complex::operator-=(const Complex& c) {
	(*this) = (*this) - c;
	return *this;
}
Complex& Complex::operator*=(const Complex& c) {
	(*this) = (*this) * c;
	return *this;
}
Complex& Complex::operator/=(const Complex& c) {
	(*this) = (*this) / c;
	return *this;
}
Complex& Complex::operator=(const Complex& c) {
	real = c.real;
	img = c.img;
	return *this;
}

int main() 
{
	Complex a(0, 0);
	a = "-1.1 + i3.923" + a;
	a.println();

	getchar();
}
*/


/*
#include <cstring>
#include <iostream>
class Complex {
private:
	double real, img;
	double get_number(const char* str, int from, int to);
public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex(const char* str);
	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);
	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);
	Complex& operator=(const Complex& c);
	friend Complex operator+(const Complex& a, const Complex& b);
	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
	void println() {
		std::cout << "( " << real << " , " << img << " ) " << std::endl;
	}
};
std::ostream& operator<<(std::ostream& os, const Complex& c) {
	os << "( " << c.real << " , " << c.img << " ) ";
	return os;
}
Complex operator+(const Complex& a, const Complex& b) {
	Complex temp(a.real + b.real, a.img + b.img);
	return temp;
}
Complex::Complex(const char* str) {
	// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
	// 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
	// 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)
	int begin = 0, end = strlen(str);
	img = 0.0;
	real = 0.0;
	// 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
	int pos_i = -1;
	for (int i = 0; i != end; i++) {
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}
	// 만일 'i' 가 없다면 이 수는 실수 뿐이다.
	if (pos_i == -1) {
		real = get_number(str, begin, end - 1);
		return;
	}
	// 만일 'i' 가 있다면, 실수부와 허수부를 나누어서 처리하면 된다.
	real = get_number(str, begin, pos_i - 1);
	img = get_number(str, pos_i + 1, end - 1);
	if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) {
	bool minus = false;
	if (from > to) return 0;
	if (str[from] == '-') minus = true;
	if (str[from] == '-' || str[from] == '+') from++;
	double num = 0.0;
	double decimal = 1.0;
	bool integer_part = true;
	for (int i = from; i <= to; i++) {
		if (isdigit(str[i]) && integer_part) {
			num *= 10.0;
			num += (str[i] - '0');
		}
		else if (str[i] == '.')
			integer_part = false;
		else if (isdigit(str[i]) && !integer_part) {
			decimal /= 10.0;
			num += ((str[i] - '0') * decimal);
		}
		else
			break; // 그 이외의 이상한 문자들이 올 경우
	}
	if (minus) num *= -1.0;
	return num;
}
Complex Complex::operator+(const Complex& c) {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex Complex::operator-(const Complex& c) {
	Complex temp(real - c.real, img - c.img);
	return temp;
}
Complex Complex::operator*(const Complex& c) {
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}
Complex Complex::operator/(const Complex& c) {
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}
Complex& Complex::operator+=(const Complex& c) {
	(*this) = (*this) + c;
	return *this;
}
Complex& Complex::operator-=(const Complex& c) {
	(*this) = (*this) - c;
	return *this;
}
Complex& Complex::operator*=(const Complex& c) {
	(*this) = (*this) * c;
	return *this;
}
Complex& Complex::operator/=(const Complex& c) {
	(*this) = (*this) / c;
	return *this;
}
Complex& Complex::operator=(const Complex& c) {
	real = c.real;
	img = c.img;
	return *this;
}
int main() {
	Complex a(0, 0);
	a = "-1.1 + i3.923" + a;
	std::cout << "a 의 값은 : " << a << " 이다. " << std::endl;

	getchar();
}
*/


/*
#include <iostream>
#include <cstring>
class MyString {
	char* string_content; // 문자열 데이터를 가리키는 포인터
	int string_length; // 문자열 길이
	int memory_capacity; // 현재 할당된 용량
public:
	// 문자 하나로 생성
	MyString(char c);
	// 문자열로 부터 생성
	MyString(const char* str);
	// 복사 생성자
	MyString(const MyString& str);
	~MyString();
	int length();
	void print() const;
	void println() const;
	char& operator[](const int index);
};
MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	memory_capacity = 1;
	string_length = 1;
}
MyString::MyString(const char* str) {
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() { return string_length; }
void MyString::print() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
}
void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}
char& MyString::operator[](const int index) { return string_content[index]; }

int main() {
	MyString str("abcdef");
	str[3] = 'c';
	str.println();

	getchar();
}
*/


/*
#include <iostream>

class Int
{
	int data;
	// some other data
public:
	Int(int data) : data(data) {}
	Int(const Int& i) : data(i.data) {}

	operator int() { return data; } // int() : 캐스팅 연산자 오버로딩
};

int main() {
	Int x = 3;
	int a = x + 4;
	x = a * 2 + x + 4;
	std::cout << x << std::endl;

	getchar();
}
*/

/*
#include <iostream>
class Test {
	int x;
public:
	Test(int x) : x(x) {}
	Test(const Test& t) : x(t.x) {}
	Test& operator++() {
		x++;
		std::cout << "전위 증감 연산자" << std::endl;
		return *this;
	}
	// 전위 증감과 후위 증감에 차이를 두기 위해 후위 증감의 경우 인자로 int 를
	// 받지만 실제로는 아무것도 전달되지 않는다.
	Test operator++(int) {
		Test temp(*this);
		x++;
		std::cout << "후위 증감 연산자" << std::endl;
		return temp;
	}
	int get_x() const {
		return x;
	}
};

void func(const Test& t) {
	std::cout << "x : " << t.get_x() << std::endl;
}

int main() {
	Test t(3);
	func(++t); // 4
	func(t++); // 4 가 출력됨
	std::cout << "x : " << t.get_x() << std::endl;

	getchar();
	return 0;
}
*/

/*
#include <iostream>
#include <string>
int main() {
	// 표준이므로 std 안에string 이 정의되어 있습니다.
	std::string s = "abc";
	std::cout << s << std::endl;

	getchar();
	return 0;
}
*/



#include <iostream>
#include <string>

class Employee 
{
	std::string name;
	int age;
	std::string position; // 직책 (이름)
	int rank; // 순위 (값이 클 수록 높은 순위)

public:
	Employee(std::string name, int age, std::string position, int rank)
		: name(name), age(age), position(position), rank(rank) {}

	// 복사 생성자
	Employee(const Employee& employee) 
	{
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	// 디폴트 생성자
	Employee() {}

	void print_info() 
	{
		std::cout << name << " (" << position << " , " << age << ") ==> "
			<< calculate_pay() << "만원" << std::endl;
	}
	int calculate_pay() { return 200 + rank * 50; }
};

class EmployeeList 
{
	int alloc_employee; // 할당한 총 직원 수
	int current_employee; // 현재 직원 수
	Employee** employee_list; // 직원 데이터
public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) 
	{
		employee_list = new Employee*[alloc_employee];
		current_employee = 0;
	}

	void add_employee(Employee* employee) 
	{
		// 사실 current_employee 보다 alloc_employee 가 더
		// 많아지는 경우 반드시 재할당을 해야 하지만, 여기서는
		// 최대한 단순하게 생각해서 alloc_employee 는
		// 언제나 current_employee 보다 크다고 생각한다.
		// (즉 할당된 크기는 현재 총 직원수 보다 많음)
		employee_list[current_employee] = employee;
		current_employee++;
	}

	int current_employee_num() { return current_employee; }

	void print_employee_info() 
	{
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++) 
		{
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}
		std::cout << "총 비용 : " << total_pay << "만원 " << std::endl;
	}

	~EmployeeList() 
	{
		for (int i = 0; i < current_employee; i++) 
		{
			delete employee_list[i];
		}
		delete[] employee_list;
	}
};

int main() 
{
	EmployeeList emp_list(10);
	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));
	emp_list.add_employee(new Employee("유재석", 41, "부장", 7));
	emp_list.add_employee(new Employee("정준하", 43, "과장", 4));
	emp_list.add_employee(new Employee("박명수", 43, "차장", 5));
	emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.print_employee_info();

	getchar();
	return 0;
}


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


/*
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
*/

