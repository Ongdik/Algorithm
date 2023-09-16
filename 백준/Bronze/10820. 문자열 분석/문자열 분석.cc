#include <iostream>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	while (getline(cin, str)) {
		int arr[4]{ 0 };

		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= 'a' && str[i] <= 'z') arr[0]++;
			else if (str[i] >= 'A' && str[i] <= 'Z') arr[1]++;
			else if (str[i] >= '0' && str[i] <= '9') arr[2]++;
			else if (str[i] == ' ') arr[3]++;
		}

		for (int i = 0; i < 4; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
}