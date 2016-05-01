#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
using std::min;

class HeapBuilder {
private:
	vector<int> data_;
	vector< pair<int, int> > swaps_;

	void WriteResponse() const {
		cout << "The array after swaps (Heap): "
		for (int i = 0; i < data_.size(); i++)
		{
			cout << data_[i] << ' ';
		}
		cout << "\n";
		cout << "The number of swaps: " << swaps_.size() << "\n";
		cout << "The swap pairs are : " << "\n";
		for (int i = 0; i < swaps_.size(); ++i) {
			cout << swaps_[i].first << " " << swaps_[i].second << "\n";
		}
	}

	void ReadData() {
		int n;   // the number of array elements
		cin >> n;
		data_.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> data_[i];   // array element
	}

	void GenerateSwaps() {
		swaps_.clear();
		for (int i = data_.size() - 1; i >= 0; i--)
		{
			SiftDown(i);
		}

	}

	int Parent(int i)
	{
		return (i - 1) / 2;  // the index of parent node
	}

	int LeftChild(int i)
	{
		return (2 * i + 1);  // the index of left child node
	}

	int RightChild(int i)
	{
		return (2 * i + 2);  // the index of right child node
	}

	void SiftDown(int i)
	{
		int minIndex = i;   // the root is the minimum number
		int l = LeftChild(i);
		if (l < data_.size() && data_[l] < data_[minIndex])
		{
			minIndex = l;
		}
		int r = RightChild(i);
		if (r < data_.size() &&  data_[r] < data_[minIndex])
		{
			minIndex = r;
		}
		if (i != minIndex)
		{
			swap(data_[i], data_[minIndex]);
			swaps_.push_back(make_pair(i, minIndex));
			SiftDown(minIndex);
		}
	}

public:
	void Solve() {
		ReadData();
		GenerateSwaps();
		WriteResponse();
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	HeapBuilder heap_builder;
	heap_builder.Solve();
	return 0;
}
