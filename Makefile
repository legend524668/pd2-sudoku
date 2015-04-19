all: hw2_give_question hw2_solve

hw2_give_question: hw2_give_question.o Sudoku.o
	g++ -o hw2_give_question hw2_give_question.o Sudoku.o
	
hw2_solve: hw2_solve.o Sudoku.o
	g++ -o hw2_solve hw2_solve.o Sudoku.o

hw2_solve.o: hw2_solve Sudoku.h
	g++ -c hw2_solve.cpp


hw2_give_question.o: hw2_give_question Sudoku.h
	g++ -c hw2_give_question.cpp

Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp

clean:
	rm hw2_give_question *.o
