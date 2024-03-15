#include "BigInt.h"
#include<iostream>

BigInt::BigInt(string num)
{
	int size = num.size();

	//サイズをnumに変更
	num_.resize(num.size());

	//数字をnumに一桁ずつ入れる
	for (int i = 0; i < size; ++i) {
		//ASCIIコードの0~9が並んでいる為、0の値(48)を引くことで0~9の値をintにすることが可能
		num_.at(i) = num.at(size - i - 1) - '0';
	}
}

BigInt::~BigInt()
{
	num_.clear();
}

vector<int> BigInt::CarryFix(vector<int> digit) {

	//桁数繰り返す
	for (int i = 0; i < digit.size() - 1; ++i) {

		// 繰り上がり処理 (tmp は繰り上がりの回数)
		if (digit[i] >= 10) {
			int tmp = digit[i] / 10;
			digit[i] -= tmp * 10;
			digit[i + 1] += tmp;
		}
		// 繰り下がり処理 (tmp は繰り下がりの回数)
		if (digit[i] < 0) {
			int tmp = (-digit[i] - 1) / 10 + 1;
			digit[i] += tmp * 10;
			digit[i + 1] -= tmp;
		}
	}

	// 一番上の桁が 10 以上なら、桁数を増やすことを繰り返す
	while (digit.back() >= 10) {
		int tmp = digit.back() / 10;
		digit.back() -= tmp * 10;
		digit.push_back(tmp);
	}

	// 1 桁の「0」以外なら、一番上の桁の 0 (リーディング・ゼロ) を消す
	while (digit.size() >= 2 && digit.back() == 0) {
		digit.pop_back();
	}
	return digit;
}

vector<int> BigInt::Mul(vector<int> digit_a, vector<int> digit_b) {
	int aSize = digit_a.size(); // A の桁数
	int bSize = digit_b.size(); // B の桁数
	vector<int> res(aSize + bSize - 1);
	for (int i = 0; i < aSize; ++i) {
		for (int j = 0; j < bSize; ++j) {
			res[i + j] += digit_a[i] * digit_b[j];
			// 答えの i+j の位に digit_a[i] * digit_b[j] を足す
		}
	}
	return CarryFix(res);
}

void BigInt::Pow(int num)
{
	vector<int> ans = num_;
	for (int i = 0; i < num - 1; i++) {

		vector<int> tmp = Mul(ans, num_);

		ans.assign(tmp.begin(), tmp.end());
	}

	num_.assign(ans.begin(), ans.end());
}

void BigInt::Draw()
{

	for (int i = 0; i < num_.size(); i++) {
		std::cout << num_.at(num_.size() - i - 1);

		//点を追加する
		if (i % 3 == 1 && i < num_.size() - 1)  {
			std::cout << ",";
		}
	}
}

int tmp = GetObjectID();
std::string ID = std::to_string(tmp);