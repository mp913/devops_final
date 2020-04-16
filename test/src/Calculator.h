//"Copyright 2020 Maxim Zarkov" 

#pragma once
class Calculator
{
	int id;
public:
	explicit Calculator(int id) { 
		this->id = id;
	}
	int sum(int a, int b);
	int mul(int a, int b);
};

