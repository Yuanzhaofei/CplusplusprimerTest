#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>
#include<vector>

using namespace std;
//main��������������������һ��Ϊ�����ļ�������������Ϊ����ļ���
//�������������ļ��е��������������������һ������ļ���ż��������ڶ�������ļ�
int main(int argc, const char*argv[]) {
	//����������
	ifstream in(argv[1]);
	//����������������
	istream_iterator<int> in_it(in), in_eof;
	//��������������������
	ofstream out1(argv[2]), out2(argv[3]);
	ostream_iterator<int> out1_it(out1," "), out2_it(out2,"\n");
	vector<int> vi;//����vector�洢��������
	//��������,��ŵ�vector��
	copy(in_it, in_eof, back_inserter(vi));
	//������ż�����з���
	auto even_it = stable_partition(vi.begin(), vi.end(), [](const int i)->bool {return i % 2; });//��������ǰ�����ص�һ��ż���ĵ�����
	//������д���һ������ļ�
	copy(vi.begin(), even_it, out1_it);//��ʾ��Χ�ĵ���������Ҫһ�£�even_itû�еײ�const
	//��ż��д��ڶ�������ļ�
	copy(even_it,vi.end(), out2_it);
}