// ThreadTest.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
		std::cout << "���� ����" << std::endl;
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
// string.h �� strlen ������ include �ߴµ�, ��� �������� ���� strlen
// �� ���� �Լ��� ���� �ᵵ �˴ϴ�.
#include <string.h>
class MyString {
	char* string_content; // ���ڿ� �����͸� ����Ű�� ������
	int string_length; // ���ڿ� ����
public:
	// ���� �ϳ��� ����
	MyString(char c);
	// ���ڿ��� ���� ����
	MyString(const char* str);
	// ���� ������
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
// string.h �� strlen ������ include �ߴµ�, ��� �������� ���� strlen
// �� ���� �Լ��� ���� �ᵵ �˴ϴ�.
#include <string.h>
class MyString 
{
	char* string_content; // ���ڿ� �����͸� ����Ű�� ������
	int string_length; // ���ڿ� ����
	int memory_capacity; // ���� �Ҵ�� �뷮
public:
	// ���� �ϳ��� ����
	MyString(char c);
	// ���ڿ��� ���� ����
	MyString(const char* str);
	// ���� ������
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
		// �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) 
	{
		string_content[i] = str.string_content[i];
	}
	// �׸��� ���� str.string_length + 1 ~ string_length �κ��� �ʱ�ȭ
	// ��ų �ʿ�� ����. �ֳ��ϸ� �ű� ������ �о������ �ʱ� �����̴�.
	string_length = str.string_length;
	return *this;
}

MyString& MyString::assign(const char* str) 
{
	int str_length = strlen(str);
	if (str_length > memory_capacity) 
	{
		// �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
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
	// ���� �����Ϸ��� size �� ���� capacity ���� �۴ٸ�
	// �ƹ��͵� ���ص� �ȴ�.
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
// string.h �� strlen ������ include �ߴµ�, ��� �������� ���� strlen
// �� ���� �Լ��� ���� �ᵵ �˴ϴ�.
#include <string.h>
class MyString {
	char* string_content; // ���ڿ� �����͸� ����Ű�� ������
	int string_length; // ���ڿ� ����
	int memory_capacity; // ���� �Ҵ�� �뷮
public:
	// ���� �ϳ��� ����
	MyString(char c);
	// ���ڿ��� ���� ����
	MyString(const char* str);
	// ���� ������
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
		// �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}
	// �׸��� ���� str.string_length + 1 ~ string_length �κ��� �ʱ�ȭ
	// ��ų �ʿ�� ����. �ֳ��ϸ� �ű� ������ �о������ �ʱ� �����̴�.
	string_length = str.string_length;
	return *this;
}
MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length > memory_capacity) {
		// �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
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
	// ���� �����Ϸ��� size �� ���� capacity ���� �۴ٸ�
	// �ƹ��͵� ���ص� �ȴ�.
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
	// �̴� i �� ��ġ �ٷ� �տ� ���ڸ� �����ϰ� �ȴ�. ���� ��
	// abc ��� ���ڿ��� insert(1, "d") �� �ϰ� �ȴٸ� adbc �� �ȴ�.
	// ������ ����� �Է¿� ���ؼ��� ������ �������� �ʴ´�.
	if (loc < 0 || loc > string_length) {
		return *this;
	}
	if (string_length + str.string_length > memory_capacity) {
		// ���� ���Ӱ� �������� �Ҵ��� �ؾ� �Ѵ�.
		memory_capacity = string_length + str.string_length;
		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];
		// �ϴ� insert �Ǵ� �κ� ���������� ������ �����Ѵ�.
		int i;
		for (i = 0; i < loc; i++) {
			string_content[i] = prev_string_content[i];
		}
		// �׸��� ���ӿ� insert �Ǵ� ���ڿ��� �ִ´�.
		for (int j = 0; j != str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}
		// ���� �ٽ� �� ���ڿ��� ������ �޺κ��� �����Ѵ�.
		for (; i < string_length; i++) {
			string_content[str.string_length + i] = prev_string_content[i];
		}
		delete[] prev_string_content;
		string_length = string_length + str.string_length;
		return *this;
	}
	// ���� �ʰ����� �ʴ� ��� ���� �����Ҵ��� �� �ʿ䰡 ���� �ȴ�.
	// ȿ�������� insert �ϱ� ����, �и��� �κ��� ���� �ڷ� �о������.
	for (int i = string_length - 1; i >= loc; i--) {
		// �ڷ� �б�. �� �� ������ ���ڿ� �����Ͱ� ������� �ʰ� ��
		string_content[i + str.string_length] = string_content[i];
	}
	// �׸��� insert �Ǵ� ���� �ٽ� ����ֱ�
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
// string.h �� strlen ������ include �ߴµ�, ��� �������� ���� strlen
// �� ���� �Լ��� ���� �ᵵ �˴ϴ�.
#include <string.h>
class MyString {
	char* string_content; // ���ڿ� �����͸� ����Ű�� ������
	int string_length; // ���ڿ� ����
	int memory_capacity; // ���� �Ҵ�� �뷮
public:
	// ���� �ϳ��� ����
	MyString(char c);
	// ���ڿ��� ���� ����
	MyString(const char* str);
	// ���� ������
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
		// �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}
	// �׸��� ���� str.string_length + 1 ~ string_length �κ��� �ʱ�ȭ
	// ��ų �ʿ�� ����. �ֳ��ϸ� �ű� ������ �о������ �ʱ� �����̴�.
	string_length = str.string_length;
	return *this;
}
MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length > memory_capacity) {
		// �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
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
	// ���� �����Ϸ��� size �� ���� capacity ���� �۴ٸ�
	// �ƹ��͵� ���ص� �ȴ�.
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
	// �̴� i �� ��ġ �ٷ� �տ� ���ڸ� �����ϰ� �ȴ�. ���� ��
	// abc ��� ���ڿ��� insert(1, "d") �� �ϰ� �ȴٸ� adbc �� �ȴ�.
	// ������ ����� �Է¿� ���ؼ��� ������ �������� �ʴ´�.
	if (loc < 0 || loc > string_length) return *this;
	if (string_length + str.string_length > memory_capacity) {
		// ���� ���Ӱ� �������� �Ҵ��� �ؾ� �Ѵ�.
		if (memory_capacity * 2 > string_length + str.string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + str.string_length;
		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];
		// �ϴ� insert �Ǵ� �κ� ���������� ������ �����Ѵ�.
		int i;
		for (i = 0; i < loc; i++) {
			string_content[i] = prev_string_content[i];
		}
		// �׸��� ���ӿ� insert �Ǵ� ���ڿ��� �ִ´�.
		for (int j = 0; j != str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}
		// ���� �ٽ� �� ���ڿ��� ������ �޺κ��� �����Ѵ�.
		for (; i < string_length; i++) {
			string_content[str.string_length + i] = prev_string_content[i];
		}
		delete[] prev_string_content;
		string_length = string_length + str.string_length;
		return *this;
	}
	// ���� �ʰ����� �ʴ� ��� ���� �����Ҵ��� �� �ʿ䰡 ���� �ȴ�.
	// ȿ�������� insert �ϱ� ����, �и��� �κ��� ���� �ڷ� �о������.
	for (int i = string_length - 1; i >= loc; i--) {
		// �ڷ� �б�. �� �� ������ ���ڿ� �����Ͱ� ������� �ʰ� ��
		string_content[i + str.string_length] = string_content[i];
	}
	// �׸��� insert �Ǵ� ���� �ٽ� ����ֱ�
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
	// loc �� �� ���� �����ؼ� num ���ڸ� �����.
	if (num < 0 || loc < 0 || loc > string_length) return *this;
	// ����ٴ� ���� �ܼ��� ���� ���ڵ��� ������ ���� �´ٰ�
	// �����ϸ� �˴ϴ�.
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
// string.h �� strlen ������ include �ߴµ�, ��� �������� ���� strlen
// �� ���� �Լ��� ���� �ᵵ �˴ϴ�.
#include <string.h>
class MyString {
	char* string_content; // ���ڿ� �����͸� ����Ű�� ������
	int string_length; // ���ڿ� ����
	int memory_capacity; // ���� �Ҵ�� �뷮
public:
	// ���� �ϳ��� ����
	MyString(char c);
	// ���ڿ��� ���� ����
	MyString(const char* str);
	// ���� ������
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
		// �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}
	// �׸��� ���� str.string_length + 1 ~ string_length �κ��� �ʱ�ȭ
	// ��ų �ʿ�� ����. �ֳ��ϸ� �ű� ������ �о������ �ʱ� �����̴�.
	string_length = str.string_length;
	return *this;
}
MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length > memory_capacity) {
		// �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
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
	// ���� �����Ϸ��� size �� ���� capacity ���� �۴ٸ�
	// �ƹ��͵� ���ص� �ȴ�.
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
	// �̴� i �� ��ġ �ٷ� �տ� ���ڸ� �����ϰ� �ȴ�. ���� ��
	// abc ��� ���ڿ��� insert(1, "d") �� �ϰ� �ȴٸ� adbc �� �ȴ�.
	// ������ ����� �Է¿� ���ؼ��� ������ �������� �ʴ´�.
	if (loc < 0 || loc > string_length) return *this;
	if (string_length + str.string_length > memory_capacity) {
		// ���� ���Ӱ� �������� �Ҵ��� �ؾ� �Ѵ�.
		if (memory_capacity * 2 > string_length + str.string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + str.string_length;
		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];
		// �ϴ� insert �Ǵ� �κ� ���������� ������ �����Ѵ�.
		int i;
		for (i = 0; i < loc; i++) {
			string_content[i] = prev_string_content[i];
		}
		// �׸��� ���ӿ� insert �Ǵ� ���ڿ��� �ִ´�.
		for (int j = 0; j != str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}
		// ���� �ٽ� �� ���ڿ��� ������ �޺κ��� �����Ѵ�.
		for (; i < string_length; i++) {
			string_content[str.string_length + i] = prev_string_content[i];
		}
		delete[] prev_string_content;
		string_length = string_length + str.string_length;
		return *this;
	}
	// ���� �ʰ����� �ʴ� ��� ���� �����Ҵ��� �� �ʿ䰡 ���� �ȴ�.
	// ȿ�������� insert �ϱ� ����, �и��� �κ��� ���� �ڷ� �о������.
	for (int i = string_length - 1; i >= loc; i--) {
		// �ڷ� �б�. �� �� ������ ���ڿ� �����Ͱ� ������� �ʰ� ��
		string_content[i + str.string_length] = string_content[i];
	}
	// �׸��� insert �Ǵ� ���� �ٽ� ����ֱ�
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
	// loc �� �� ���� �����ؼ� num ���ڸ� �����.
	if (num < 0 || loc < 0 || loc > string_length) return *this;
	// ����ٴ� ���� �ܼ��� ���� ���ڵ��� ������ ���� �´ٰ�
	// �����ϸ� �˴ϴ�.
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
	return -1; // ã�� ������
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
// string.h �� strlen ������ include �ߴµ�, ��� �������� ���� strlen
// �� ���� �Լ��� ���� �ᵵ �˴ϴ�.
#include <string.h>
#include <algorithm>

class MyString 
{
	char* string_content; // ���ڿ� �����͸� ����Ű�� ������
	int string_length; // ���ڿ� ����
	int memory_capacity; // ���� �Ҵ�� �뷮
public:
	// ���� �ϳ��� ����
	MyString(char c);
	// ���ڿ��� ���� ����
	MyString(const char* str);
	// ���� ������
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
		// �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) 
	{
		string_content[i] = str.string_content[i];
	}
	// �׸��� ���� str.string_length + 1 ~ string_length �κ��� �ʱ�ȭ
	// ��ų �ʿ�� ����. �ֳ��ϸ� �ű� ������ �о������ �ʱ� �����̴�.
	string_length = str.string_length;
	return *this;
}

MyString& MyString::assign(const char* str) 
{
	int str_length = strlen(str);
	if (str_length > memory_capacity) 
	{
		// �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�.
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
	// ���� �����Ϸ��� size �� ���� capacity ���� �۴ٸ�
	// �ƹ��͵� ���ص� �ȴ�.
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
	// �̴� i �� ��ġ �ٷ� �տ� ���ڸ� �����ϰ� �ȴ�. ���� ��
	// abc ��� ���ڿ��� insert(1, "d") �� �ϰ� �ȴٸ� adbc �� �ȴ�.
	// ������ ����� �Է¿� ���ؼ��� ������ �������� �ʴ´�.
	if (loc < 0 || loc > string_length) return *this;

	if (string_length + str.string_length > memory_capacity) 
	{
		// ���� ���Ӱ� �������� �Ҵ��� �ؾ� �Ѵ�.
		if (memory_capacity * 2 > string_length + str.string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + str.string_length;
		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];
		// �ϴ� insert �Ǵ� �κ� ���������� ������ �����Ѵ�.
		int i;
		for (i = 0; i < loc; i++) 
		{
			string_content[i] = prev_string_content[i];
		}
		// �׸��� ���ӿ� insert �Ǵ� ���ڿ��� �ִ´�.
		for (int j = 0; j != str.string_length; j++) 
		{
			string_content[i + j] = str.string_content[j];
		}
		// ���� �ٽ� �� ���ڿ��� ������ �޺κ��� �����Ѵ�.
		for (; i < string_length; i++) 
		{
			string_content[str.string_length + i] = prev_string_content[i];
		}
		delete[] prev_string_content;
		string_length = string_length + str.string_length;
		return *this;
	}
	// ���� �ʰ����� �ʴ� ��� ���� �����Ҵ��� �� �ʿ䰡 ���� �ȴ�.
	// ȿ�������� insert �ϱ� ����, �и��� �κ��� ���� �ڷ� �о������.
	for (int i = string_length - 1; i >= loc; i--) 
	{
		// �ڷ� �б�. �� �� ������ ���ڿ� �����Ͱ� ������� �ʰ� ��
		string_content[i + str.string_length] = string_content[i];
	}
	// �׸��� insert �Ǵ� ���� �ٽ� ����ֱ�
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
	// loc �� �� ���� �����ؼ� num ���ڸ� �����.
	if (num < 0 || loc < 0 || loc > string_length) return *this;
	// ����ٴ� ���� �ܼ��� ���� ���ڵ��� ������ ���� �´ٰ�
	// �����ϸ� �˴ϴ�.
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
	return -1; // ã�� ������
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
	// (*this) - (str) �� �����ؼ� �� 1, 0, -1 �� �� ����� �����Ѵ�
	// 1 �� (*this) �� ���������� �� �ڿ� �´ٴ� �ǹ�. 0 �� �� ���ڿ�
	// �� ���ٴ� �ǹ�, -1 �� (*this) �� ���������� �� �տ� �´ٴ� �ǹ��̴�.
	for (int i = 0; i < std::min(string_length, str.string_length); i++) 
	{
		if (string_content[i] > str.string_content[i])
			return 1;
		else if (string_content[i] < str.string_content[i])
			return -1;
	}
	// ���� ���� �ߴµ� ������ �ʾҴٸ� �� �κ� ���� ��� �Ȱ��� ���� �ȴ�.
	// ���� ���ڿ� ���̰� ���ٸ� �� ���ڿ��� �ƿ� ���� ���ڿ��� �ȴ�.
	if (string_length == str.string_length) return 0;
	// ����� abc �� abcd �� ũ�� �񱳴� abcd �� �� �ڿ� ���� �ȴ�.
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
	char* string_content; // ���ڿ� �����͸� ����Ű�� ������
	int string_length; // ���ڿ� ����
	int memory_capacity;
public:
	// capacity ��ŭ �̸� �Ҵ���. (explicit Ű���忡 �ָ�)
	explicit MyString(int capacity);
	//MyString(int capacity) {};
	// ���ڿ��� ���� ����
	MyString(const char* str) {};
	// ���� ������
	MyString(const MyString& str) {};
	~MyString() {};
	int length() const { return string_length; };
	int capacity() const { return memory_capacity; };
};

// .. (����) ..
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
		data_ = x; // �Ұ���!
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
	char* string_content; // ���ڿ� �����͸� ����Ű�� ������
	int string_length; // ���ڿ� ����
	int memory_capacity; // ���� �Ҵ�� �뷮
public:
	// ���� �ϳ��� ����
	MyString(char c);
	// ���ڿ��� ���� ����
	MyString(const char* str);
	// ���� ������
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
	// ���� �����Ϸ��� size �� ���� capacity ���� �۴ٸ�
	// �ƹ��͵� ���ص� �ȴ�.
}
char MyString::at(int i) const {
	if (i >= string_length || i < 0)
		return 0;
	else
		return string_content[i];
}
int MyString::compare(MyString& str) {
	// (*this) - (str) �� �����ؼ� �� 1, 0, -1 �� �� ����� �����Ѵ�
	// 1 �� (*this) �� ���������� �� �ڿ� �´ٴ� �ǹ�. 0 �� �� ���ڿ�
	// �� ���ٴ� �ǹ�, -1 �� (*this) �� ���������� �� �տ� �´ٴ� �ǹ��̴�.
	for (int i = 0; i < std::min(string_length, str.string_length); i++) {
		if (string_content[i] > str.string_content[i])
			return 1;
		else if (string_content[i] < str.string_content[i])
			return -1;
	}
	// ���� ���� �ߴµ� ������ �ʾҴٸ� �� �κ� ���� ��� �Ȱ��� ���� �ȴ�.
	// ���� ���ڿ� ���̰� ���ٸ� �� ���ڿ��� �ƿ� ���� ���ڿ��� �ȴ�.
	if (string_length == str.string_length) return 0;
	// ����� abc �� abcd �� ũ�� �񱳴� abcd �� �� �ڿ� ���� �ȴ�.
	else if (string_length > str.string_length)
		return 1;
	return -1;
}
bool MyString::operator==(MyString& str) {
	return !compare(str); // str �� ������ compare ���� 0 �� �����Ѵ�.
}
int main() {
	MyString str1("a word");
	MyString str2("sentence");
	MyString str3("sentence");
	if (str1 == str2)
		std::cout << "str1 �� str2 ����." << std::endl;
	else
		std::cout << "st1 �� str2 �� �ٸ���." << std::endl;
	if (str2 == str3)
		std::cout << "str2 �� str3 �� ����." << std::endl;
	else
		std::cout << "st2 �� str3 �� �ٸ���" << std::endl;

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
	// �Է� ���� ���ڿ��� �м��Ͽ� real �κа� img �κ��� ã�ƾ� �Ѵ�.
	// ���ڿ��� ���� ������ �����ϴ� "[��ȣ](�Ǽ���)(��ȣ)i(�����)"
	// �� �� �� ���� ��ȣ�� ���� �����մϴ�. (������ + �� ����)
	int begin = 0, end = strlen(str);
	img = 0.0;
	real = 0.0;
	// ���� ���� ������ �Ǵ� 'i' �� ��ġ�� ã�´�.
	int pos_i = -1;
	for (int i = 0; i != end; i++) {
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}
	// ���� 'i' �� ���ٸ� �� ���� �Ǽ� ���̴�.
	if (pos_i == -1) {
		real = get_number(str, begin, end - 1);
		return;
	}
	// ���� 'i' �� �ִٸ�, �Ǽ��ο� ����θ� ����� ó���ϸ� �ȴ�.
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
			break; // �� �̿��� �̻��� ���ڵ��� �� ���
	}
	if (minus) num *= -1.0;
	return num;
}

//Complex Complex::operator+(const char* str) {
//	// �Է� ���� ���ڿ��� �м��Ͽ� real �κа� img �κ��� ã�ƾ� �Ѵ�.
//	// ���ڿ��� ���� ������ �����ϴ� "[��ȣ](�Ǽ���)(��ȣ)i(�����)"
//	// �� �� �� ���� ��ȣ�� ���� �����մϴ�. (������ + �� ����)
//	int begin = 0, end = strlen(str);
//	double str_img = 0.0, str_real = 0.0;
//	// ���� ���� ������ �Ǵ� 'i' �� ��ġ�� ã�´�.
//	int pos_i = -1;
//	for (int i = 0; i != end; i++) {
//		if (str[i] == 'i') {
//			pos_i = i;
//			break;
//		}
//	}
//	// ���� 'i' �� ���ٸ� �� ���� �Ǽ� ���̴�.
//	if (pos_i == -1) {
//		str_real = get_number(str, begin, end - 1);
//		Complex temp(str_real, str_img);
//		return (*this) + temp;
//	}
//	// ���� 'i' �� �ִٸ�, �Ǽ��ο� ����θ� ����� ó���ϸ� �ȴ�.
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
//Complex operator+(const Complex& a, const Complex& b) { return a + b; } // ����� ȣ��� ���ѹݺ� ����. 
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
	// �Է� ���� ���ڿ��� �м��Ͽ� real �κа� img �κ��� ã�ƾ� �Ѵ�.
	// ���ڿ��� ���� ������ �����ϴ� "[��ȣ](�Ǽ���)(��ȣ)i(�����)"
	// �� �� �� ���� ��ȣ�� ���� �����մϴ�. (������ + �� ����)
	int begin = 0, end = strlen(str);
	img = 0.0;
	real = 0.0;
	// ���� ���� ������ �Ǵ� 'i' �� ��ġ�� ã�´�.
	int pos_i = -1;
	for (int i = 0; i != end; i++) {
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}
	// ���� 'i' �� ���ٸ� �� ���� �Ǽ� ���̴�.
	if (pos_i == -1) {
		real = get_number(str, begin, end - 1);
		return;
	}
	// ���� 'i' �� �ִٸ�, �Ǽ��ο� ����θ� ����� ó���ϸ� �ȴ�.
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
			break; // �� �̿��� �̻��� ���ڵ��� �� ���
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
	// �Է� ���� ���ڿ��� �м��Ͽ� real �κа� img �κ��� ã�ƾ� �Ѵ�.
	// ���ڿ��� ���� ������ �����ϴ� "[��ȣ](�Ǽ���)(��ȣ)i(�����)"
	// �� �� �� ���� ��ȣ�� ���� �����մϴ�. (������ + �� ����)
	int begin = 0, end = strlen(str);
	img = 0.0;
	real = 0.0;
	// ���� ���� ������ �Ǵ� 'i' �� ��ġ�� ã�´�.
	int pos_i = -1;
	for (int i = 0; i != end; i++) {
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}
	// ���� 'i' �� ���ٸ� �� ���� �Ǽ� ���̴�.
	if (pos_i == -1) {
		real = get_number(str, begin, end - 1);
		return;
	}
	// ���� 'i' �� �ִٸ�, �Ǽ��ο� ����θ� ����� ó���ϸ� �ȴ�.
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
			break; // �� �̿��� �̻��� ���ڵ��� �� ���
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
	std::cout << "a �� ���� : " << a << " �̴�. " << std::endl;

	getchar();
}
*/


/*
#include <iostream>
#include <cstring>
class MyString {
	char* string_content; // ���ڿ� �����͸� ����Ű�� ������
	int string_length; // ���ڿ� ����
	int memory_capacity; // ���� �Ҵ�� �뷮
public:
	// ���� �ϳ��� ����
	MyString(char c);
	// ���ڿ��� ���� ����
	MyString(const char* str);
	// ���� ������
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

	operator int() { return data; } // int() : ĳ���� ������ �����ε�
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
		std::cout << "���� ���� ������" << std::endl;
		return *this;
	}
	// ���� ������ ���� ������ ���̸� �α� ���� ���� ������ ��� ���ڷ� int ��
	// ������ �����δ� �ƹ��͵� ���޵��� �ʴ´�.
	Test operator++(int) {
		Test temp(*this);
		x++;
		std::cout << "���� ���� ������" << std::endl;
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
	func(t++); // 4 �� ��µ�
	std::cout << "x : " << t.get_x() << std::endl;

	getchar();
	return 0;
}
*/

/*
#include <iostream>
#include <string>
int main() {
	// ǥ���̹Ƿ� std �ȿ�string �� ���ǵǾ� �ֽ��ϴ�.
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
	std::string position; // ��å (�̸�)
	int rank; // ���� (���� Ŭ ���� ���� ����)

public:
	Employee(std::string name, int age, std::string position, int rank)
		: name(name), age(age), position(position), rank(rank) {}

	// ���� ������
	Employee(const Employee& employee) 
	{
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	// ����Ʈ ������
	Employee() {}

	void print_info() 
	{
		std::cout << name << " (" << position << " , " << age << ") ==> "
			<< calculate_pay() << "����" << std::endl;
	}
	int calculate_pay() { return 200 + rank * 50; }
};

class EmployeeList 
{
	int alloc_employee; // �Ҵ��� �� ���� ��
	int current_employee; // ���� ���� ��
	Employee** employee_list; // ���� ������
public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) 
	{
		employee_list = new Employee*[alloc_employee];
		current_employee = 0;
	}

	void add_employee(Employee* employee) 
	{
		// ��� current_employee ���� alloc_employee �� ��
		// �������� ��� �ݵ�� ���Ҵ��� �ؾ� ������, ���⼭��
		// �ִ��� �ܼ��ϰ� �����ؼ� alloc_employee ��
		// ������ current_employee ���� ũ�ٰ� �����Ѵ�.
		// (�� �Ҵ�� ũ��� ���� �� ������ ���� ����)
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
		std::cout << "�� ��� : " << total_pay << "���� " << std::endl;
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
	emp_list.add_employee(new Employee("��ȫö", 34, "����", 1));
	emp_list.add_employee(new Employee("����", 34, "����", 1));
	emp_list.add_employee(new Employee("���缮", 41, "����", 7));
	emp_list.add_employee(new Employee("������", 43, "����", 4));
	emp_list.add_employee(new Employee("�ڸ��", 43, "����", 5));
	emp_list.add_employee(new Employee("������", 36, "�븮", 2));
	emp_list.add_employee(new Employee("��", 36, "����", -2));
	emp_list.print_employee_info();

	getchar();
	return 0;
}


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


/*
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
*/

