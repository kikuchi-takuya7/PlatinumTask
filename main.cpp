#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/multiprecision/cpp_dec_float.hpp>
#include"BigInt.h"

using std::cout;
using std::endl;

namespace mp = boost::multiprecision;

namespace {
	string BIRTHDAY_STR = "20040123";
	mp::cpp_dec_float_50 BIRTHDAY_FLOAT = 20040123;
	int POW = 6;
	mp::cpp_dec_float_50 SECOND = 3.2;
	int DECIMAL_PLACE_NUM = 3;
}

/// <summary>
/// �C�ӂ̌��Ŏl�̌ܓ�����֐�
/// </summary>
/// <param name="num">�l�̌ܓ����������l</param>
/// <param name="n">�\��������������(2�Ȃ珬�����ʂ܂�)</param>
/// <returns>�l�̌ܓ���̒l</returns>
template <class T>
T Rounding_n(T num, int n);

int main() {

	//[2] 18���̐�����������^�������ׁAint�z����g�������Ă݂܂����B
	{
		//BigInt�N���X���g���v�Z����
		BigInt num(BIRTHDAY_STR);

		num.Pow(POW);
		cout << "[2]  �̓����́F";
		num.Draw();
		cout << endl;
	}
	

	//[3] ��������Boostc++���C�u�������g�p���Ă��܂�

	//K������ɋ��߂܂�
	mp::cpp_dec_float_50 k = BIRTHDAY_FLOAT;
	k = k / 10000000;

	//A ��b���ɉ�������ׁA3.2�b���3�b��Ɠ��������x�Ȃ̂�K��3�悵�܂����B
	{

		mp::cpp_dec_float_50 ans = mp::pow(k, 3);
		ans = Rounding_n(ans, DECIMAL_PLACE_NUM);

		cout << "[3].A�̓����́F" << ans << endl;
	}
	

	//B ��b���̉����x�ƈړ��������v�Z���A�ړ������𑫂����킹�܂����B
	{
		mp::cpp_dec_float_50 ans = 0;

		//�b�����Ƃ̉����x
		mp::cpp_dec_float_50 a = 1.0f;
		
		//0~3�b�܂ł̈ړ����������߂�
		for (int sec = 0; sec < 3; sec++) {
			a = mp::pow(k, sec);
			ans += a * 1;
		}

		//�Ō��0.2�b���𑫂�
		a = mp::pow(k, 3);
		ans += a * 0.2;

		ans = Rounding_n(ans, DECIMAL_PLACE_NUM);

		cout << "[3].B�̓����́F" << ans << endl;
	}

	return 1;
}

// �C�ӂ̌��Ŏl�̌ܓ�����֐�
template<class T>
T Rounding_n(T num, int n)
{
	//�l�̌ܓ����������܂ł𐮐��ɂ��āAround�Ŏl�̌ܓ����Ă��猳�ɖ߂�
	num = num * std::pow(10, n - 1);
	num = mp::round(num);
	num /= std::pow(10, n - 1);
	return num;
}
