// Converter Ŭ������ ��ӹ޾� km�� mile�� ��ȯ�ϴ� KmToMile Ŭ����
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

class KmToMile :public Converter {
	double convert(double src) {
		return src / ratio;	// src km = src/ratio(1.609344) mile
	}
	string getSourceString() {
		return "Km";
	}
	string getDestString() {
		return "Mile";
	}
public:
	KmToMile(double ratio) :Converter(ratio) {}
};

int main()
{
	KmToMile toMile(1.609344);	// 1mile�� 1.609344km
	toMile.run();
}