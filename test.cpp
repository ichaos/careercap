#include <iostream>
#include <string>

using namespace std;

int main() {
	string s = "";

	for (char i = 'a'; i <= 'z'; i++) {
		s += i;
		cout << "size of " << s << ": " << s.capacity() << endl;
	}
	
}