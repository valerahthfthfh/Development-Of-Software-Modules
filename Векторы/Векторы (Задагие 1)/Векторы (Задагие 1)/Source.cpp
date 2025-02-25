#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main()
{
	int N_arr;

	cout << "Add size vector: ";
	cin >> N_arr;

	vector<int> arr(N_arr);
	int N, input;

	for (int i = 0; i < N_arr; i++) {

		cout << "add number: ";

		cin >> N;

		arr[i] = N;

	}

	for (int i = arr.size() - 1; i >= 0; --i) {

		cout << arr[i] << " ";

	}

}
