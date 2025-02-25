#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main()
{
	int N_arr;

	cout << "Add size vector: ";
	cin >> N_arr;

	vector<string> arr(N_arr);
	string N;

	for (int i = 0; i < N_arr; i++) {

		cout << "add text: ";

		cin >> N;

		arr[i] = N;

	}

	arr.push_back("nember");
	for (int i = 0; i < arr.size(); i++) {

		cout << arr[i] << " ";

	}

}
