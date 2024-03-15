#pragma once
#include<string>
#include<vector>

using std::string;
using std::vector;

//�Q�l�ɂ����T�C�g
//https://qiita.com/square1001/items/1aa12e04934b6e749962

/// <summary>
/// �傫���������ꌅ�������N���X�i�|���Z�̂ݎ����j
/// </summary>
class BigInt
{

	vector<int> num_;

public:
	
	BigInt(string num);
	~BigInt();

	/// <summary>
	/// �J��グ�J�艺�����s���֐�
	/// </summary>
	/// <param name="digit">�v�Z������̊֐�</param>
	/// <returns>�v�Z�������ʂ̔z��</returns>
	vector<int> CarryFix(vector<int> digit);

	/// <summary>
	/// �����̒l�Ŋ|���Z����֐�
	/// </summary>
	/// <param name="digit_a">�ꌅ���������|���Z�������z��</param>
	/// <param name="digit_b">�ꌅ���������|���Z�������z��</param>
	/// <returns>�J��グ�J�艺�����s�����|���Z�̌���</returns>
	vector<int> Mul(vector<int> digit_a, vector<int> digit_b);

	/// <summary>
	/// ��Z����֐�
	/// </summary>
	/// <param name="num">�w��</param>
	void Pow(int num);

	/// <summary>
	/// ���݂̐���\��
	/// </summary>
	void Draw();
};

