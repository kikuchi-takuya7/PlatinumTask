#include "BigInt.h"
#include<iostream>

BigInt::BigInt(string num)
{
	int size = num.size();

	//�T�C�Y��num�ɕύX
	num_.resize(num.size());

	//������num�Ɉꌅ�������
	for (int i = 0; i < size; ++i) {
		//ASCII�R�[�h��0~9������ł���ׁA0�̒l(48)���������Ƃ�0~9�̒l��int�ɂ��邱�Ƃ��\
		num_.at(i) = num.at(size - i - 1) - '0';
	}
}

BigInt::~BigInt()
{
	num_.clear();
}

vector<int> BigInt::CarryFix(vector<int> digit) {

	//�����J��Ԃ�
	for (int i = 0; i < digit.size() - 1; ++i) {

		// �J��オ�菈�� (tmp �͌J��オ��̉�)
		if (digit[i] >= 10) {
			int tmp = digit[i] / 10;
			digit[i] -= tmp * 10;
			digit[i + 1] += tmp;
		}
		// �J�艺���菈�� (tmp �͌J�艺����̉�)
		if (digit[i] < 0) {
			int tmp = (-digit[i] - 1) / 10 + 1;
			digit[i] += tmp * 10;
			digit[i + 1] -= tmp;
		}
	}

	// ��ԏ�̌��� 10 �ȏ�Ȃ�A�����𑝂₷���Ƃ��J��Ԃ�
	while (digit.back() >= 10) {
		int tmp = digit.back() / 10;
		digit.back() -= tmp * 10;
		digit.push_back(tmp);
	}

	// 1 ���́u0�v�ȊO�Ȃ�A��ԏ�̌��� 0 (���[�f�B���O�E�[��) ������
	while (digit.size() >= 2 && digit.back() == 0) {
		digit.pop_back();
	}
	return digit;
}

vector<int> BigInt::Mul(vector<int> digit_a, vector<int> digit_b) {
	int aSize = digit_a.size(); // A �̌���
	int bSize = digit_b.size(); // B �̌���
	vector<int> res(aSize + bSize - 1);
	for (int i = 0; i < aSize; ++i) {
		for (int j = 0; j < bSize; ++j) {
			res[i + j] += digit_a[i] * digit_b[j];
			// ������ i+j �̈ʂ� digit_a[i] * digit_b[j] �𑫂�
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

		//�_��ǉ�����
		if (i % 3 == 1 && i < num_.size() - 1)  {
			std::cout << ",";
		}
	}
}

int tmp = GetObjectID();
std::string ID = std::to_string(tmp);