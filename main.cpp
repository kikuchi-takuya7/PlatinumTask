#include<iostream>
#include"BigInt.h"

namespace {
	string BIRTHDAY = "20040123";
	int POW = 6;
}

int main() {

	//BigInt�N���X���g���v�Z����
	BigInt num(BIRTHDAY);

	num.Pow(POW);
	//num.Draw();

	long double birthday = 2.0040123;

	//birthday /= 10000000;

	std::cout << birthday << std::endl;

	return 1;
}
