#pragma once
#include<string>
#include<vector>

using std::string;
using std::vector;

//参考にしたサイト
//https://qiita.com/square1001/items/1aa12e04934b6e749962

/// <summary>
/// 大きい数字を一桁ずつ扱うクラス（掛け算のみ実装）
/// </summary>
class BigInt
{

	vector<int> num_;

public:
	
	BigInt(string num);
	~BigInt();

	/// <summary>
	/// 繰り上げ繰り下げを行う関数
	/// </summary>
	/// <param name="digit">計算した後の関数</param>
	/// <returns>計算した結果の配列</returns>
	vector<int> CarryFix(vector<int> digit);

	/// <summary>
	/// 引数の値で掛け算する関数
	/// </summary>
	/// <param name="digit_a">一桁ずつ入った掛け算したい配列</param>
	/// <param name="digit_b">一桁ずつ入った掛け算したい配列</param>
	/// <returns>繰り上げ繰り下げを行った掛け算の結果</returns>
	vector<int> Mul(vector<int> digit_a, vector<int> digit_b);

	/// <summary>
	/// 乗算する関数
	/// </summary>
	/// <param name="num">指数</param>
	void Pow(int num);

	/// <summary>
	/// 現在の数を表示
	/// </summary>
	void Draw();
};

