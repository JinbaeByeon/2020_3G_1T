// �߻�Ŭ���� Converter�� ��ӹ޾� �޷��� ��ȭ�� ȯ���ϴ� WonToDollar Ŭ���� �ۼ�
#include <iostream>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0; // src�� �ٸ� ������ ��ȯ�Ѵ�.
	virtual string getSourceString() = 0; // �ҽ� ���� ��Ī
	virtual string getDestString() = 0; // dest ���� ��Ī
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
		cout << getSourceString() << "�� �Է��ϼ���>> ";
		cin >> src;
		cout << "��ȯ ��� : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar :public Converter {
	double convert(double src) {
		return src / ratio;	// src �� = src/ratio(1010) �޷�
	}
	string getSourceString() {
		return "��";
	}
	string getDestString() {
		return "�޷�";
	}

public:
	WonToDollar(double ratio) :Converter(ratio) {}
};

int main() {
	WonToDollar wd(1010);	// 1�޷��� 1010��
	wd.run();
}