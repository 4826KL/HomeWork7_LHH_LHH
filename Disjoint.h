#pragma once
#include<iostream>
#include<vector>

using namespace std;

class Disjoint
{
public:
	Disjoint(int numsElements);
	~Disjoint(){}

	int find(int x) const;          //find����
	void unionSets(int root1, int root2);    //union�ϲ�����
	void unionSetsBySize(int root1, int root2);     //����С�ϲ�
	void unionSetsByHeight(int root1, int root2);         //���߶Ⱥϲ�
	void print();                                         //����������ཻ�������е�Ԫ��

private:
	vector<int> s;    //���ÿ��Ԫ�صĸ��ڵ㣬�����ڵ�
	void print(int x);
};

