#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<fstream>
#include"Sudoku.h"
using namespace std;
int Sudoku::ReadIn(){
    anscount=0;
    int i,j,n;
    for(i=0;i<12;i++){
        for(j=0;j<12;j++){
        	temp[i][j]=0;
        	answer[i][j]=0;
        }
    }
    for(i=0;i<12;i++){
        for(j=0;j<12;j++){
        	cin>>n;
        	temp[i][j]=n;
        }
    }
}
int Sudoku::rcheck(int fill,int r){
    int j;
    for(j=0;j<12;j++){
        if(temp[r][j]==fill)
        return 0;
    }
    return 1;
}
int Sudoku::ccheck(int fill,int c){
    int i;
    for(i=0;i<12;i++){
        if(temp[i][c]==fill)
        return 0;
    }
    return 1;
}
int Sudoku::scheck(int fill,int m,int n){
	int i,j,x=m-(m%3),y=n-(n%3);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            if(temp[x+i][y+j]==fill)
            return 0;
    }
    return 1;
}
void Sudoku::Solve2(){
    int i,j,k;
    int fill=0;
    for(i=0;i<12;i++){
        for(j=0;j<12;j++){
            if(temp[i][j]!=0)
                fill++;
        }
    }
    if(fill==144){
        anscount++;
        for(i=0;i<12;i++){
            for(j=0;j<12;j++)
            	answer[i][j]=temp[i][j];
        }
        return;
    }
    for(i=0;i<12;i++){
        for(j=0;j<12;j++){
            if(temp[i][j]==0){
                for(k=1;k<=9;k++){
                      if(rcheck(k,i)==1&&ccheck(k,j)==1&&scheck(k,i,j)==1){
                            temp[i][j]=k;
                            Solve2();
                            temp[i][j] = 0;
                      }
                }
                return;
            }
        }
    }
}
void Sudoku::answers(){
	int i,j;
	if(anscount == 0)
    	cout<<"0"<<endl;
	else if(anscount == 1){
		cout<<"1"<<endl;
		for(i=0;i<12;i++){
        	for(j=0;j<12;j++)
        		cout<<answer[i][j]<<" ";
        		printf("\n");
    	}
	}
	else if(anscount >= 2)
    	cout<<"2"<<endl;
}
void Sudoku::Solve(){
	Solve2();
	answers();
}
void Sudoku::GiveQuestion(){
	srand(time(NULL));
	int i=6, j, a, b;
	j=rand()%i+1;
    num[0][0] = 4; num[0][1] = 0; num[0][2] = 0; num[0][3] = 8; num[0][4] = 0; num[0][5] = 3; num[0][6] = 0; num[0][7] = 5; num[0][8] = 0; num[0][9] = -1; num[0][10] = -1; num[0][11] = -1;
    num[1][0] = 0; num[1][1] = 0; num[1][2] = 3; num[1][3] = 0; num[1][4] = 0; num[1][5] = 0; num[1][6] = 6; num[1][7] = 0; num[1][8] = 4; num[1][9] = -1; num[1][10] = -1; num[1][11] = -1;
    num[2][0] = 9; num[2][1] = 0; num[2][2] = 0; num[2][3] = 0; num[2][4] = 2; num[2][5] = 0; num[2][6] = 0; num[2][7] = 0; num[2][8] = 0; num[2][9] = -1; num[2][10] = -1; num[2][11] = -1;
    num[3][0] = -1; num[3][1] = -1; num[3][2] = -1; num[3][3] = 1; num[3][4] = 0; num[3][5] = 0; num[3][6] = 0; num[3][7] = 8; num[3][8] = 7; num[3][9] = 0; num[3][10] = 5; num[3][11] = 6;
    num[4][0] = -1; num[4][1] = -1; num[4][2] = -1; num[4][3] = 0; num[4][4] = 0; num[4][5] = 0; num[4][6] = 0; num[4][7] = 0; num[4][8] = 0; num[4][9] = 4; num[4][10] = 0; num[4][11] = 0;
    num[5][0] = -1; num[5][1] = -1; num[5][2] = -1; num[5][3] = 0; num[5][4] = 9; num[5][5] = 6; num[5][6] = 2; num[5][7] = 0; num[5][8] = 0; num[5][9] = 0; num[5][10] = 0; num[5][11] = 1;
    num[6][0] = 1; num[6][1] = 0; num[6][2] = 0; num[6][3] = 0; num[6][4] = 4; num[6][5] = 0; num[6][6] = -1; num[6][7] = -1; num[6][8] = -1; num[6][9] = 0; num[6][10] = 0; num[6][11] = 5;
    num[7][0] = 0; num[7][1] = 0; num[7][2] = 4; num[7][3] = 0; num[7][4] = 0; num[7][5] = 0; num[7][6] = -1; num[7][7] = -1; num[7][8] = -1; num[7][9] = 0; num[7][10] = 3; num[7][11] = 0;
    num[8][0] = 0; num[8][1] = 9; num[8][2] = 0; num[8][3] = 0; num[8][4] = 1; num[8][5] = 0; num[8][6] = -1; num[8][7] = -1; num[8][8] = -1; num[8][9] = 0; num[8][10] = 0; num[8][11] = 0;
    num[9][0] = 3; num[9][1] = 0; num[9][2] = 2; num[9][3] = -1; num[9][4] = -1; num[9][5] = -1; num[9][6] = 0; num[9][7] = 4; num[9][8] = 0; num[9][9] = 0; num[9][10] = 0; num[9][11] = 0;
    num[10][0] = 0; num[10][1] = 0; num[10][2] = 0; num[10][3] = -1; num[10][4] = -1; num[10][5] = -1; num[10][6] = 0; num[10][7] = 6; num[10][8] = 0; num[10][9] = 0; num[10][10] = 0; num[10][11] = 0;
    num[11][0] = 0; num[11][1] = 6; num[11][2] = 0; num[11][3] = -1; num[11][4] = -1; num[11][5] = -1; num[11][6] = 3; num[11][7] = 0; num[11][8] = 0; num[11][9] = 7; num[11][10] = 0; num[11][11] = 8;

    if(j==1){
        for(a=0;a<12;a++){
            temp[0][a] = num[0][a]; temp[1][a] = num[1][a]; temp[2][a] = num[2][a];
            num[0][a] = num[3][a]; num[1][a] = num[4][a]; num[2][a] = num[5][a];
            num[3][a] = temp[0][a]; num[4][a] = temp[1][a]; num[5][a] = temp[2][a];
        }
    }
    if(j==2){
        for(a=0;a<12;a++){
            temp[0][a] = num[0][a]; temp[1][a] = num[1][a]; temp[2][a] = num[2][a];
            num[0][a] = num[6][a]; num[1][a] = num[7][a]; num[2][a] = num[8][a];
            num[6][a] = temp[0][a]; num[7][a] = temp[1][a]; num[8][a] = temp[2][a];
        }
    }
    if(j==3){
        for(a=0;a<12;a++){
            temp[0][a] = num[0][a]; temp[1][a] = num[1][a]; temp[2][a] = num[2][a];
            num[0][a] = num[9][a]; num[1][a] = num[10][a]; num[2][a] = num[11][a];
            num[9][a] = temp[0][a]; num[10][a] = temp[1][a]; num[11][a] = temp[2][a];
        }
    }
    if(j==4){
        for(a=0;a<12;a++){
            temp[3][a] = num[3][a]; temp[4][a] = num[4][a]; temp[5][a] = num[5][a];
            num[3][a] = num[6][a]; num[4][a] = num[7][a]; num[5][a] = num[8][a];
            num[6][a] = temp[3][a]; num[7][a] = temp[4][a]; num[8][a] = temp[5][a];
        }
    }
    if(j==5){
        for(a=0;a<12;a++){
            temp[3][a] = num[3][a]; temp[4][a] = num[4][a]; temp[5][a] = num[5][a];
            num[3][a] = num[9][a]; num[4][a] = num[10][a]; num[5][a] = num[11][a];
            num[9][a] = temp[3][a]; num[10][a] = temp[4][a]; num[11][a] = temp[5][a];
        }
    }
    if(j==6){
        for(a=0;a<12;a++){
            temp[6][a] = num[6][a]; temp[7][a] = num[7][a]; temp[8][a] = num[8][a];
            num[6][a] = num[9][a]; num[7][a] = num[10][a]; num[8][a] = num[11][a];
            num[9][a] = temp[6][a]; num[10][a] = temp[7][a]; num[11][a] = temp[8][a];
        }
    }
    srand(time(NULL));
    j=rand()%i+1;

    if(j==1){
        for(a=0;a<12;a++){
            temp[a][0] = num[a][0]; temp[a][1] = num[a][1]; temp[a][2] = num[a][2];
            num[a][0] = num[a][3]; num[a][1] = num[a][4]; num[a][2] = num[a][5];
            num[a][3] = temp[a][0]; num[a][4] = temp[a][1]; num[a][5] = temp[a][2];
        }
    }
    if(j==2){
        for(a=0;a<12;a++){
            temp[a][0] = num[a][0]; temp[a][1] = num[a][1]; temp[a][2] = num[a][2];
            num[a][0] = num[a][6]; num[a][1] = num[a][7]; num[a][2] = num[a][8];
            num[a][6] = temp[a][0]; num[a][7] = temp[a][1]; num[a][8] = temp[a][2];
        }
    }
    if(j==3){
        for(a=0;a<12;a++){
            temp[a][0] = num[a][0]; temp[a][1] = num[a][1]; temp[a][2] = num[a][2];
            num[a][0] = num[a][9]; num[a][1] = num[a][10]; num[a][2] = num[a][11];
            num[a][9] = temp[a][0]; num[a][10] = temp[a][1]; num[a][11] = temp[a][2];
        }
    }
    if(j==4){
        for(a=0;a<12;a++){
            temp[a][3] = num[a][3]; temp[a][4] = num[a][4]; temp[a][5] = num[a][5];
            num[a][3] = num[a][6]; num[a][4] = num[a][7]; num[a][5] = num[a][8];
            num[a][6] = temp[a][3]; num[a][7] = temp[a][4]; num[a][8] = temp[a][5];
        }
    }
    if(j==5){
        for(a=0;a<12;a++){
            temp[a][3] = num[a][3]; temp[a][4] = num[a][4]; temp[a][5] = num[a][5];
            num[a][3] = num[a][9]; num[a][4] = num[a][10]; num[a][5] = num[a][11];
            num[a][9] = temp[a][3]; num[a][10] = temp[a][4]; num[a][11] = temp[a][5];
        }
    }
    if(j==6){
        for(a=0;a<12;a++){
            temp[a][6] = num[a][6]; temp[a][7] = num[a][7]; temp[a][8] = num[a][8];
            num[a][6] = num[a][9]; num[a][7] = num[a][10]; num[a][8] = num[a][11];
            num[a][9] = temp[a][6]; num[a][10] = temp[a][7]; num[a][11] = temp[a][8];
        }
    }

    for(a=0;a<12;a++){
        for(b=0;b<12;b++){
            printf("%d ", num[a][b]);
        }
        printf("\n");
    }
	/*if(j==1){
		printf("0 1 0 0 0 0 0 5 0\n8 0 0 7 2 0 0 0 0\n0 0 0 0 0 0 0 6 0\n0 0 0 0 0 5 0 9 0\n7 0 0 0 0 0 0 0 3\n0 0 0 0 0 0 0 0 2\n0 0 0 8 0 0 0 0 7\n0 6 0 0 0 0 0 0 0\n0 5 0 0 0 9 0 1 0\n");
	}
	if(j==2){
		printf("5 0 6 0 0 0 0 0 0\n0 2 0 0 0 9 0 0 0\n0 0 0 7 0 0 0 0 1\n0 0 0 0 0 0 0 1 7\n0 0 0 0 0 0 0 0 8\n0 0 0 0 5 2 0 0 0\n0 0 8 0 0 0 0 0 0\n0 0 1 0 0 0 3 0 0\n0 0 0 0 4 0 2 9 0\n");
	}
	if(j==3){
		printf("5 0 0 0 0 0 0 0 0\n0 0 3 0 4 0 0 0 0\n0 0 0 8 0 0 0 6 0\n0 0 0 0 5 3 0 0 0\n0 6 0 0 0 0 0 0 0\n1 8 0 0 0 0 0 7 0\n0 0 0 1 0 0 0 0 0\n0 7 0 0 0 0 0 0 5\n0 0 2 0 0 0 3 0 4\n");
	}
	if(j==4){
		printf("0 0 1 0 0 0 9 8 0\n7 0 0 0 0 0 0 0 0\n0 0 0 0 2 0 1 0 0\n6 0 0 8 0 0 0 0 0\n0 0 0 9 0 0 0 0 0\n4 0 0 0 0 0 0 0 3\n0 0 8 0 0 0 0 0 0\n0 0 9 0 3 5 0 0 0\n0 0 0 0 4 0 0 0 6\n");
	}
	if(j==5){
		printf("0 0 0 0 7 0 8 4 0\n0 0 0 0 0 0 0 0 0\n6 5 0 8 0 0 0 0 0\n2 0 0 0 0 5 0 0 0\n0 0 0 0 0 0 0 0 0\n0 0 7 0 0 0 3 0 0\n0 0 4 1 3 0 0 0 0\n0 0 0 0 0 0 0 2 0\n1 0 0 0 0 0 0 5 6\n");
	}
	if(j==6){
		printf("0 0 5 0 0 0 0 0 0\n6 0 1 0 0 3 0 0 0\n0 0 0 7 0 0 0 2 0\n8 0 0 0 0 0 0 0 0\n0 4 0 2 9 0 0 0 0\n0 0 0 0 0 0 1 0 5\n0 0 0 0 0 0 0 0 0\n0 2 0 0 0 0 0 9 0\n0 0 0 0 0 1 0 8 6\n");
	}
	if(j==7){
		printf("0 1 0 6 0 0 0 0 0\n0 0 0 0 7 0 0 0 4\n9 0 0 0 0 0 2 0 0\n0 0 0 8 0 4 0 9 0\n0 7 2 0 0 0 0 0 0\n3 0 0 0 0 0 0 0 0\n0 0 0 0 0 9 0 0 0\n0 8 0 0 0 0 0 1 0\n0 0 0 0 3 2 0 0 0\n");
	}
	if(j==8){
		printf("0 0 0 0 0 6 0 0 0\n0 0 0 0 0 0 1 2 0\n8 7 0 3 0 0 0 0 0\n0 0 0 0 0 0 0 0 5\n0 3 5 0 0 0 6 0 0\n0 0 0 7 0 8 0 0 0\n4 0 2 0 9 0 0 0 0\n0 0 0 0 0 0 0 0 7\n0 0 1 0 0 0 0 0 0\n");
	}
	if(j==9){
		printf("0 0 0 5 1 0 0 0 3\n0 0 0 2 0 0 0 0 0\n4 9 0 0 0 0 8 0 0\n0 7 0 0 0 0 0 0 0\n8 0 0 0 0 0 0 0 0\n0 0 0 1 0 0 0 2 0\n3 2 0 0 0 4 0 0 0\n0 0 0 0 0 0 0 0 6\n0 0 5 0 0 0 1 0 0\n");
	}
	if(j==10){
		printf("0 0 0 1 2 0 0 0 0\n0 0 7 0 0 0 0 0 5\n0 0 0 4 0 0 0 6 0\n0 0 0 0 0 6 0 0 8\n0 4 0 0 0 0 1 0 0\n0 0 0 0 0 5 0 0 0\n5 0 0 0 0 0 0 0 0\n8 0 6 0 0 0 0 7 0\n0 0 0 9 0 0 2 0 0\n");
	}*/
}
