#pragma once
#include<iostream>
#include<vector>

using namespace std;

class Disjoint
{
public:
	Disjoint(int numsElements);
	~Disjoint(){}

	int find(int x) const;          //find操作
	void unionSets(int root1, int root2);    //union合并操作
	void unionSetsBySize(int root1, int root2);     //按大小合并
	void unionSetsByHeight(int root1, int root2);         //按高度合并
	void print();                                         //输出各个不相交集合类中的元素

private:
	vector<int> s;    //存放每个元素的根节点，即父节点
	void print(int x);
};

