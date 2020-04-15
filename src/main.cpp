#include <iostream>
#include "Calculator.h"
int main()
{
	Calculator *calc = new Calculator(1);
	std::cout << calc->sum(1, 2);
}