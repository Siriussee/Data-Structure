#include "Extended_queue.h"

#include <iostream>

Extended_queue::Extended_queue() : size_num(0), head(0), rear(MAX - 1)
{
}
Extended_queue::~Extended_queue()
{
}
bool Extended_queue::empty()
{
	if (size_num == 0)
		return 1;
	return 0;
}
Error_code Extended_queue::retrieve(Plane &moving)
{
	if (size_num <= 0)
		return fail;
	moving = store[head];
	return success;
}
Error_code Extended_queue::serve()
{ //出队
	if (size_num <= 0)
		return fail;
	head = (head + 1 == MAX) ? 0 : head + 1;
	size_num--;
	return success;
}
Error_code Extended_queue::append(const Plane &current)
{ //入队
	if (size_num >= MAX)
		return fail;
	rear = (rear + 1 == MAX) ? 0 : rear + 1;
	store[rear] = current;
	size_num++;
	return success;
}
int Extended_queue::size() const
{
	return size_num;
}
//-----------------------------------------------------------
Error_code Extended_queue::push_front(const Plane &current)
{
	for (int i = rear; i >= head; --i)
	{
		store[i + 1] = store[i];
	}
	store[head] = current;
	rear++;
	size_num++;
	return success;
}
Plane Extended_queue::top()
{
	return store[head];
}

Plane &Extended_queue::operator[](int i)
{
	return store[i];
}
int Extended_queue::get_head()
{
	return head;
}
int Extended_queue::get_rear()
{
	return rear;
}
//-----------------------------------------------------------