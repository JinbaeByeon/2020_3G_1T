/* ������ �ߺ� �Ǵ� ����Ʈ �Ű������� ����Ͽ� Mouse Ŭ������ �����ڸ� �ۼ�*/

#include <iostream>
using namespace std;

class Mouse {
private:
	string vendor;
	string model;
	int nButton;
	bool isWireless;
public:
	Mouse(string vendor, string model, int nBut = 2, bool isWrls = false) :
		vendor(vendor), model(model), nButton(nBut), isWireless(isWrls) {}
	void spec() {
		cout << vendor << " " << model << ", " << nButton << " buttons, ";
		cout << (isWireless ? "Wireless" : "Wired") << endl;
	}
};

int main() {
	Mouse m150("Microsoft", "M150"), g102("Logitech", "G102", 5), hs022("Hansung", "HS022", 3, true);
	m150.spec();
	g102.spec();
	hs022.spec();
}