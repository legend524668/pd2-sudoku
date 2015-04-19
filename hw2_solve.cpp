#include "Sudoku.h"
int main(){    
	Sudoku ss;
	
	cout<<"Enter a sudoku:"<<endl;
	ss.ReadIn();
	ss.Solve();
	return 0;
}