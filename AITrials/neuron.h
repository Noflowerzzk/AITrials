#pragma once
template <typename T,typename F>
class neuron
{
public:

	neuron(vector<T>& w, T& b) :weight(w), bias(b)
	{
		func = new F();
	}

	T output(const vector<T>& inputs) {
		return (*func)(sum(inputs));
	}

private:
	vector<T>& weight;	// Ȩ��
	double& bias;		// ƫ��

	F *func;

	T sum(const vector<T>& inputs)	// ��weight.size() == input.size()
	{
		T sum = 0;
		for (int i = 0; i < inputs.size(); i++)
			sum += inputs[i] * weight[i];
		sum += bias;
		return sum;
	}

};

