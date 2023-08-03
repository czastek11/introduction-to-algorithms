#include <iostream>
#include <vector>

using namespace std;

bool check_sort(vector<double> A)
{
	for (unsigned int i = 1; i < A.size(); i++)
	{
		if (A.at(i) < A.at(i - 1))
		{
			return 0;
		}
	}
	return 1;
}

void Heapify(vector<double>& A, unsigned int i, unsigned int n)
{
	unsigned int l = 2 * i + 1, r = 2 * i + 2, w = i;
	if (l<n && A.at(l)>A.at(w)) w = l;
	if (r<n && A.at(r)>A.at(w)) w = r;
	if (w != i)
	{
		swap(A.at(i), A.at(w));
		Heapify(A, w, n);
	}
}

void Heapsort(vector <double>& A)
{
	if (!A.empty())
	{
		unsigned int n = A.size();
		for (int i = (n - 1) / 2; i >= 0; i--) Heapify(A, i, n);
		for (int i = n - 1; i >= 1; i--)
		{
			swap(A.at(i), A.at(0));
			n--;
			Heapify(A, 0, n);
		}
	}
}

void BucketSort(vector<double>& Arr)
{
	vector<double> empty;
	empty.clear();
	vector<vector<double>> buckets;
	for (int i = 0; i < Arr.size(); i++)
	{
		buckets.push_back(empty);
	}

	for (int i = 0; i < Arr.size(); i++)
	{
		int b_in = Arr.size() * Arr.at(i);
		buckets.at(b_in).push_back(Arr.at(i));
	}

	for (int i = 0; i < Arr.size(); i++)
	{
		Heapsort(buckets.at(i));
	}

	int ind = 0;
	for (int i = 0; i < Arr.size(); i++)
	{
		for (int j = 0; j < buckets.at(i).size(); j++)
		{
			Arr.at(ind) = buckets.at(i).at(j);
			ind++;
		}
	}


}

int main()
{
	vector<double> arr
		= { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
	BucketSort(arr);
	cout << check_sort(arr) << endl;
	cout << "Sorted array is \n";
	for (int i = 0; i < arr.size(); i++)
		cout << arr.at(i) << " ";
	return 0;
}