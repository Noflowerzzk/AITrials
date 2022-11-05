#pragma once
class Sigmoid
{
public:
	Sigmoid(){}

	double operator () (double x)
	{
		return func(x);
	}

	double dSig(double x)
	{
		return func(x) * (1 - func(x));
	}

private:
	inline double func(double x)
	{
		return 1.0 / (1.0 + exp(-x));
	}
};

