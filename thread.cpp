#include <iostream>
#include <thread>
#include "Printer.hpp"
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <windows.h>






int main()
{
	::SetConsoleCP(1251);
	::SetConsoleOutputCP(1251);

	srand(time(NULL));
	Printer printer;

	std::vector<int> vector(10);
	
	std::list<int> list(10);

	for (auto& el : vector)
		el = ::rand() % 20;


	for (auto& el : list)
		el = ::rand() % 20;

	std::cout << "Вектор: ";
	std::thread thread_vector([&vector, &printer]()
	{
		std::sort(vector.begin(), vector.end());//сортируем
		printer.Print(vector);
	});;
	


	

	std::cout << "Список: ";
	list.sort();
	std::thread thread_list([&list, &printer]()//лямбда выражение
		{
			list.sort();
			printer.Print(list);
		});


	thread_vector.join();//чтоб не закрывался поток раньше времени
	thread_list.join();


	return 0;
}