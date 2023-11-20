#pragma once
#include"Stack.h"
#include<chrono>
namespace Benchmark
{
	long long test_push_and_pop(long long push, long long delet)
	{
		Stack<int> list;
		auto begin = std::chrono::steady_clock::now();
		for (size_t i = 0; i < push; i++)
		{
			list.push(rand() % 100);
		}
		for (size_t i = 0; i < delet; i++)
		{
			list.pop();
		}
		auto end = std::chrono::steady_clock::now();
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		return ms.count();
	}
}

