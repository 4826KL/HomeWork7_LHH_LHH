#include "Disjoint.h"

//构造函数对每个元素进行集合初始化
//numsElements时集合中元素的个数
Disjoint::Disjoint(int numsElements) : s(numsElements)
{
    //unsigned为无符号类型
    for (unsigned i = 0; i < s.size(); ++i)
        s[i] = -1;
}

//查找元素处于的集合的名字 x为被查找的元素
int Disjoint::find(int x) const
{
    if (s[x] < 0)
        return x;
    else
        return find(s[x]);
    return 0;
}

//合并两个集合,将一棵树作为另一棵树的子树，可无限制合并
void Disjoint::unionSets(int root1, int root2)
{
    s[root2] = root1;
}

//按集合大小合并两个集合，使得较小的树成为较大的树的子树
void Disjoint::unionSetsBySize(int root1, int root2)
{
    if (s[root2] < s[root1])
    {
        s[root2] += s[root1];  //更新树的大小
        s[root1] = root2;      //将root1的父节点变成root2
    }
    else
    {
        s[root1] += s[root2];
        s[root2] = root1;
    }
}

//按高度合并两个集合，使较浅的树成为较深的树的子树
void Disjoint::unionSetsByHeight(int root1, int root2)
{
    if (s[root2] < s[root1])    //root2树比较高
        s[root1] = root2;       //直接合并，root1成为root2的子树
    else
    {
        if (s[root1] == s[root2]) 
            s[root1]--;
        s[root2] = root1;
    }
}

//打印集合元素
void Disjoint::print()
{
    cout << "输出不相交集合类（每行表示一个相交集合）：" << endl;
    cout << "s: ";
    for (unsigned i = 0; i < s.size(); ++i)
        cout << s[i] << " ";
    cout << endl;

    for (unsigned i = 0; i < s.size(); ++i)
    {
        if (s[i] < 0) {
            print(i);
            cout << endl;
        }
    }
}

//打印元素x的父结点
void Disjoint::print(int x)
{
    cout << x << " ";
    for (unsigned i = 0; i < s.size(); ++i)
    {
        if (s[i] == x)
            print(i);
    }
}
