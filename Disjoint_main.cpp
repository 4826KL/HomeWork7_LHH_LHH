#include"Disjoint.h"

int main() 
{
	cout << "任意合并：\n";
	Disjoint disjoints(8);
	disjoints.unionSets(4, 5);
	disjoints.unionSets(6, 7);
	disjoints.unionSets(4, 6);
	disjoints.print();

	cout << "按大小合并：\n";
	Disjoint disjoints2(8);
	disjoints2.unionSetsBySize(4, 5);
	disjoints2.unionSetsBySize(6, 7);
	disjoints2.unionSetsBySize(4, 6);
	disjoints2.unionSetsBySize(3, 4);
	disjoints.print();

	cout << "按高度合并：\n";
	Disjoint disjoints3(8);
	disjoints3.unionSetsByHeight(4, 5);
	disjoints3.unionSetsByHeight(6, 7);
	disjoints3.unionSetsByHeight(4, 6);
	disjoints3.unionSetsByHeight(3, 4);
	disjoints3.print();
	
	return 0;


}