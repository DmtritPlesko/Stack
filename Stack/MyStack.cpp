#include<iostream>
#include"Benchmark.h"
#include<fstream>
#include"Stack.h"
#include<Windows.h>
#include<string>
#include<vector>

using Benchmark::test_push_and_pop;

int main()
{

	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);



	Stack<std::string> myStack;

	std::vector<std::string> container;

	std::string kk;
	std::cout << "¬ведите свою формулу: ";
	std::getline(std::cin, kk);
	kk.erase(std::remove_if(kk.begin(), kk.end(), ::isspace), kk.end());//удал€ет пробелы 
	//std::cout << kk;

	short temp=0;




	//std::string temp;//счЄтчик

	//for (int i = 0; i < kk.length(); i++)
	//{
	//	temp = kk[i];
	//	myStack.push(temp);
	//}

	

	//std::cout << myStack;


	return 0;
}