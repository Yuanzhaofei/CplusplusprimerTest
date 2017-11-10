#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>
#include<vector>

using namespace std;
//main函数接受三个参数，第一个为输入文件名，另外两个为输出文件名
//函数读入输入文件中的整数，将奇数输出到第一个输出文件，偶数输出到第二个输出文件
int main(int argc, const char*argv[]) {
	//定义输入流
	ifstream in(argv[1]);
	//定义输入流迭代器
	istream_iterator<int> in_it(in), in_eof;
	//定义输出流及输出迭代器
	ofstream out1(argv[2]), out2(argv[3]);
	ostream_iterator<int> out1_it(out1," "), out2_it(out2,"\n");
	vector<int> vi;//定义vector存储读入整数
	//读入整数,存放到vector中
	copy(in_it, in_eof, back_inserter(vi));
	//对奇数偶数进行分类
	auto even_it = stable_partition(vi.begin(), vi.end(), [](const int i)->bool {return i % 2; });//奇数排在前，返回第一个偶数的迭代器
	//将奇数写入第一个输出文件
	copy(vi.begin(), even_it, out1_it);//表示范围的迭代器类型要一致，even_it没有底层const
	//将偶数写入第二个输出文件
	copy(even_it,vi.end(), out2_it);
}