#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
using namespace std;
void RecPermute(int p, vector<string>v1, vector<string>v2)
{
	if (v1.size() == p) {
		
		for (int i = 0; i < p; i++) {
			cout <<" " << i + 1 << "- " << v1[i];
		}
		cout << endl;

	}
	else {
		for (int i = 0; i < v2.size(); i++) {

			v1.push_back(v2[i]);

			RecPermute(p,v1, v2);
			v1.pop_back();
		}
	}
}


void ListPermutations(int p, vector<string>v1, vector<string>v2) {
	RecPermute(p,v1,v2);
}


int main()
{
	int num;
	cout << "please enter the number of traffic lights in your country : ";
	cin >> num;
	if (num == 2) {
		int p;
		cout << "please enter the number of traffic lights : ";
		cin >> p;
		vector<string>v1;
		vector<string>v2 = { "red","green" };
		ListPermutations(p, v1, v2);
	}
	else if (num == 3) {
		int p;
		cout << "please enter the number of traffic lights : ";
		cin >> p;
		vector<string>v1;
		vector<string>v2 = { "red","green","yellow"};
		ListPermutations(p, v1, v2);
	}
	else {
		cout << "NOT EXIST !!" << endl;
	}
	
	
}
