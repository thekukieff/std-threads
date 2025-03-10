#pragma once
#ifndef PRINTER_HPP
#define PRINTER_HPP
#include <mutex>
class Printer
{
public:
	template<typename T>
	void Print(T collection);
	

private:
	std::mutex mutex;
};



#endif //

template<typename T>
inline void Printer::Print(T collection)//vs ñîçäàåò òåëî ìåòîäà çäåñü
{
	mutex.lock();

	for (auto& el : collection)
		std::cout << el << ' ';

	std::cout << std::endl;

	mutex.unlock();
}
