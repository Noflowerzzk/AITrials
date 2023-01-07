#pragma once
template <typename T, typename F>
class neuronNet
{
public:

	neuronNet(vector<vector<neuron<T, F>>>& net)
		:net(net)
	{
		//for (int i = 0; i < net.size(); i++) {
		//	for (int j = 0; j < net[i].size(); j++) {
		//		this->net[i][j] = new neuron()
		//	}
		//}
	}


private:
	vector<vector<neuron<T, F>>>& net;	// [��] -> [����]
	/**
	* ��net[i - 1].size() == net[i][(any)].weight.size()
	*/

	vector<T>* inputs;	// ����ֵ
	vector<T>* expct;	// Ԥ��ֵ
	vector<T>* rl;		// ʵ��ֵ
	/**
	* ��input.size() == net[0][(any)].weight.size()
	*   expct.size() == rl.size() == net.back().weight.size()
	*/

	vector<T>&& cost() const	// ��ʧ����
	{
		T sum = 0;
		const vector<T>& opt = outputs();
		for (int i = 0; i < rl->size(); i++) {
			sum += static_cast<T>(0.5 * (opt[i] - (*rl)[i]) * (opt[i] - (*rl)[i]));
		}

	}

	vector<T>&& outputs() const
	{
		vector<T> temp_N(*inputs);	/*�������*/	//, temp_N	/**/;
		for (int i = 0; i < net.size(); i++) {

			vector<T> temp_B = temp_N;
			temp_N.clear();

			for (int j = 0; j < temp_B.size(); j++) {
				temp_N.push_back(net[i][j].output(temp_B));
			}
		}

		return move(temp_N);
	}

};

