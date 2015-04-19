#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<fstream>
using namespace std;
class Sudoku{
public:
	int ReadIn();
	int rcheck(int row,int r);
	int ccheck(int column,int c);
	int scheck(int square,int x,int y);
	void Solve();
	void answers();
	void Solve2();
	void GiveQuestion();
private:
	int anscount;
	int temp[12][12];
	int answer[12][12];
	int num[12][12];
};
