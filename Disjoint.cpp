#include "Disjoint.h"

//���캯����ÿ��Ԫ�ؽ��м��ϳ�ʼ��
//numsElementsʱ������Ԫ�صĸ���
Disjoint::Disjoint(int numsElements) : s(numsElements)
{
    //unsignedΪ�޷�������
    for (unsigned i = 0; i < s.size(); ++i)
        s[i] = -1;
}

//����Ԫ�ش��ڵļ��ϵ����� xΪ�����ҵ�Ԫ��
int Disjoint::find(int x) const
{
    if (s[x] < 0)
        return x;
    else
        return find(s[x]);
    return 0;
}

//�ϲ���������,��һ������Ϊ��һ�������������������ƺϲ�
void Disjoint::unionSets(int root1, int root2)
{
    s[root2] = root1;
}

//�����ϴ�С�ϲ��������ϣ�ʹ�ý�С������Ϊ�ϴ����������
void Disjoint::unionSetsBySize(int root1, int root2)
{
    if (s[root2] < s[root1])
    {
        s[root2] += s[root1];  //�������Ĵ�С
        s[root1] = root2;      //��root1�ĸ��ڵ���root2
    }
    else
    {
        s[root1] += s[root2];
        s[root2] = root1;
    }
}

//���߶Ⱥϲ��������ϣ�ʹ��ǳ������Ϊ�������������
void Disjoint::unionSetsByHeight(int root1, int root2)
{
    if (s[root2] < s[root1])    //root2���Ƚϸ�
        s[root1] = root2;       //ֱ�Ӻϲ���root1��Ϊroot2������
    else
    {
        if (s[root1] == s[root2]) 
            s[root1]--;
        s[root2] = root1;
    }
}

//��ӡ����Ԫ��
void Disjoint::print()
{
    cout << "������ཻ�����ࣨÿ�б�ʾһ���ཻ���ϣ���" << endl;
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

//��ӡԪ��x�ĸ����
void Disjoint::print(int x)
{
    cout << x << " ";
    for (unsigned i = 0; i < s.size(); ++i)
    {
        if (s[i] == x)
            print(i);
    }
}
