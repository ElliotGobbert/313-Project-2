#include <iostream>
using namespace std;
class Matrix {
public:
	Matrix(int rows, int cols) {
		m_matrix = nullptr;
		m_cols = 0;
		m_rows = 0;
		if (cols > 0 && rows > 0) {
			m_matrix = new int* [rows];
			for (int row = 0; row < rows; row++) {
				m_matrix[row] = new int[cols];
			}

			m_cols = cols;
			m_rows = rows;
			initializeMatrix();
		}
		else {
			cout << "Invalid matrix size\n";
		}
	}
	Matrix(Matrix& rhs) {
		m_matrix = nullptr;
		m_cols = 0;
		m_rows = 0;
		if (rhs.m_cols > 0 && rhs.m_rows > 0) {
			m_matrix = new int* [rhs.m_rows];
			for (int row = 0; row < rhs.m_rows; row++) {
				m_matrix[row] = new int[rhs.m_cols];
			}

			for (int row = 0; row < rhs.m_rows; row++) {
				for (int col = 0; col < rhs.m_cols; col++) {
					m_matrix[row][col] = rhs.m_matrix[row][col];
				}
			}

			m_cols = rhs.m_cols;
			m_rows = rhs.m_rows;
		}
		else {
			cout << "Invalid matrix size\n";
		}
	}
	~Matrix() {
		clear();
	}
	void clear() {
		for (int i = 0; i < m_rows; i++) {
			delete[] m_matrix[i];
		}
		delete[] m_matrix;
		m_rows = 0;
		m_cols = 0;
	}
	void dump(string name = "") {
		if (name != "") {
			cout << name << ":\n";
		}
		if (m_rows > 0 && m_cols > 0) {
			for (int row = 0; row < m_rows; row++) {
				for (int col = 0; col < m_cols; col++) {
					cout << " " << m_matrix[row][col];
				}
				cout << "\n";
			}
			cout << "\n";
		}
	}
	int getRows() {
		return m_rows;
	}
	int getCols() {
		return m_cols;
	}
	void insert(int row, int col, int value) {
		if (row < m_rows && col < m_cols) {
			m_matrix[row][col] = value;
		}
		else {
			cout << "Invalid insert location\n";
		}
	}
	void fill(int value) {
		for (int row = 0; row < m_rows; row++) {
			for (int col = 0; col < m_cols; col++) {
				m_matrix[row][col] = value;
			}
		}
	}
	Matrix& operator=(const Matrix& rhs) {
		if (&rhs != this) {
			clear();
			m_matrix = nullptr;
			m_cols = 0;
			m_rows = 0;
			if (rhs.m_cols > 0 && rhs.m_rows > 0) {
				m_matrix = new int* [rhs.m_rows];
				for (int row = 0; row < rhs.m_rows; row++) {
					m_matrix[row] = new int[rhs.m_cols];
				}

				for (int row = 0; row < rhs.m_rows; row++) {
					for (int col = 0; col < rhs.m_cols; col++) {
						m_matrix[row][col] = rhs.m_matrix[row][col];
					}
				}

				m_cols = rhs.m_cols;
				m_rows = rhs.m_rows;
			}
			else {
				cout << "Invalid matrix size\n";
			}
		}
		return *this;
	}
	Matrix& operator=(int value) {
		for (int row = 0; row < m_rows; row++) {
			for (int col = 0; col < m_cols; col++) {
				m_matrix[row][col] = value;
			}
		}
		return *this;
	}
	Matrix& operator+(const Matrix& rhs) {
		if (rhs.m_rows > 0 && rhs.m_cols > 0) {
			int rows = min(m_rows, rhs.m_rows);
			int cols = min(m_cols, rhs.m_cols);

			for (int row = 0; row < rows; row++) {
				for (int col = 0; col < cols; col++) {
					m_matrix[row][col] += rhs.m_matrix[row][col];
				}
			}
		}
		else {
			cout << "Invalid matrix size\n";
		}
		return *this;
	}
	Matrix& operator+(int value) {
		for (int row = 0; row < m_rows; row++) {
			for (int col = 0; col < m_cols; col++) {
				m_matrix[row][col] += value;
			}
		}
		return *this;
	}
	Matrix& operator*(const Matrix& rhs) {
		if (rhs.m_rows > 0 && rhs.m_cols > 0) {
			int rows = min(m_rows, rhs.m_rows);
			int cols = min(m_cols, rhs.m_cols);

			for (int row = 0; row < rows; row++) {
				for (int col = 0; col < cols; col++) {
					m_matrix[row][col] *= rhs.m_matrix[row][col];
				}
			}
		}
		else {
			cout << "Invalid matrix size\n";
		}
		return *this;
	}
	Matrix& operator*(const int value) {
		for (int row = 0; row < m_rows; row++) {
			for (int col = 0; col < m_cols; col++) {
				m_matrix[row][col] *= value;
			}
		}
		return *this;
	}
private:
	int m_rows;
	int m_cols;
	int** m_matrix;
	void initializeMatrix() {
		for (int row = 0; row < m_rows; row++) {
			for (int col = 0; col < m_cols; col++) {
				m_matrix[row][col] = 0;
			}
		}
	}
};


int main() {
	Matrix test(3, 3);
	Matrix test2(6, 6);
	test2.fill(6);
	test.fill(2);
	test.dump("test");
	test2.dump("test2");
	test * (test + 2);
	test2 + test;
	test.dump("test");
	test2.dump("test2");
	return 0;
}