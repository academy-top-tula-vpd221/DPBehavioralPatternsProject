#pragma once
#include <iostream>

class Iterator
{
public:
	virtual bool Next() = 0;
	virtual void Begin() = 0;
	virtual int Current() = 0;
};

class Matrix;

class MatrixIterator : public Iterator
{
	Matrix* matrix;
	int row;
	int col;
public:
	MatrixIterator(Matrix* matrix)
		: matrix{ matrix }, row{}, col{-1} {}

	bool Next() override;
	void Begin() override;
	int Current() override;
	
};


class Matrix
{
	int rows;
	int cols;
	int** matrix;

public:
	Matrix() : rows{}, cols{} {}
	Matrix(int rows, int cols) : rows{ rows }, cols{ cols }
	{
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			matrix[i] = new int[cols];
	}

	int& Rows() { return rows; }
	int& Cols() { return cols; }
	int& Get(int row, int col) { return matrix[row][col]; }

	Iterator* GetIterator()
	{
		return new MatrixIterator(this);
	}

	void Print()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				std::cout << matrix[i][j] << "\t";
			std::cout << "\n";
		}
	}
};

bool MatrixIterator::Next()
{
	if (col < matrix->Cols() - 1)
		col++;
	else
	{
		if (row < matrix->Rows() - 1)
		{
			row++;
			col = 0;
		}
		else
			return false;
	}
	return true;

}
void MatrixIterator::Begin()
{
	row = 0;
	col = -1;
}
int MatrixIterator::Current()
{
	return matrix->Get(row, col);
}



