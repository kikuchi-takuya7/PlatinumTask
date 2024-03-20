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
/// 任意の桁で四捨五入する関数
/// </summary>
/// <param name="num">四捨五入させたい値</param>
/// <param name="n">表示させたい桁数(2なら小数第一位まで)</param>
/// <returns>四捨五入後の値</returns>
template <class T>
T Rounding_n(T num, int n);

int main() {

	//[2] 18桁の整数を扱える型が無い為、int配列を使い解いてみました。
	{
		//BigIntクラスを使い計算する
		BigInt num(BIRTHDAY_STR);

		num.Pow(POW);
		cout << "[2]  の答えは：";
		num.Draw();
		cout << endl;
	}
	

	//[3] ここからBoostc++ライブラリを使用しています

	//Kだけ先に求めます
	mp::cpp_dec_float_50 k = BIRTHDAY_FLOAT;
	k = k / 10000000;

	//A 一秒毎に加速する為、3.2秒後は3秒後と同じ加速度なのでKを3乗しました。
	{

		mp::cpp_dec_float_50 ans = mp::pow(k, 3);
		ans = Rounding_n(ans, DECIMAL_PLACE_NUM);

		cout << "[3].Aの答えは：" << ans << endl;
	}
	

	//B 一秒毎の加速度と移動距離を計算し、移動距離を足し合わせました。
	{
		mp::cpp_dec_float_50 ans = 0;

		//秒数ごとの加速度
		mp::cpp_dec_float_50 a = 1.0f;
		
		//0~3秒までの移動距離を求める
		for (int sec = 0; sec < 3; sec++) {
			a = mp::pow(k, sec);
			ans += a * 1;
		}

		//最後の0.2秒分を足す
		a = mp::pow(k, 3);
		ans += a * 0.2;

		ans = Rounding_n(ans, DECIMAL_PLACE_NUM);

		cout << "[3].Bの答えは：" << ans << endl;
	}

	return 1;
}

// 任意の桁で四捨五入する関数
template<class T>
T Rounding_n(T num, int n)
{
	//四捨五入したい所までを整数にして、roundで四捨五入してから元に戻す
	num = num * std::pow(10, n - 1);
	num = mp::round(num);
	num /= std::pow(10, n - 1);
	return num;
}
