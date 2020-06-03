//"Copyright 2020 Maxim Zarkov" 

#include <iostream>
#include "Calculator.h"
int main()
{
	Calculator *calc = new Calculator(1);
	std::cout << calc->sum(2, 2);
}
