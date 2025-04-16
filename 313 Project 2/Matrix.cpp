//#include <iostream>
//using namespace std;
//class Matrix {
//public:
//	Matrix(int rows, int cols) {
//		m_matrix = nullptr;
//		m_cols = 0;
//		m_rows = 0;
//		if (cols > 0 && rows > 0) {
//			m_matrix = new int* [rows];
//			for (int row = 0; row < rows; row++) {
//				m_matrix[row] = new int[cols];
//			}
//
//			m_cols = cols;
//			m_rows = rows;
//			initializeMatrix();
//		}
//		else {
//			//cout << "Invalid matrix size\n";
//		}
//	}
//	Matrix(Matrix& rhs) {
//		m_matrix = nullptr;
//		m_cols = 0;
//		m_rows = 0;
//		if (rhs.m_cols > 0 && rhs.m_rows > 0) {
//			m_matrix = new int* [rhs.m_rows];
//			for (int row = 0; row < rhs.m_rows; row++) {
//				m_matrix[row] = new int[rhs.m_cols];
//			}
//
//			for (int row = 0; row < rhs.m_rows; row++) {
//				for (int col = 0; col < rhs.m_cols; col++) {
//					m_matrix[row][col] = rhs.m_matrix[row][col];
//				}
//			}
//
//			m_cols = rhs.m_cols;
//			m_rows = rhs.m_rows;
//		}
//		else {
//			cout << "Invalid matrix size\n";
//		}
//	}
//	~Matrix() {
//		clear();
//	}
//	void clear() {
//		for (int i = 0; i < m_rows; i++) {
//			delete[] m_matrix[i];
//		}
//		delete[] m_matrix;
//		m_rows = 0;
//		m_cols = 0;
//	}
//	void dump(string name = "") {
//		if (name != "") {
//			cout << name << ":\n";
//		}
//		if (m_rows > 0 && m_cols > 0) {
//			for (int row = 0; row < m_rows; row++) {
//				for (int col = 0; col < m_cols; col++) {
//					cout << " " << m_matrix[row][col];
//				}
//				cout << "\n";
//			}
//			cout << "\n";
//		}
//	}
//	int getRows() {
//		return m_rows;
//	}
//	int getCols() {
//		return m_cols;
//	}
//	void insert(int row, int col, int value) {
//		if (row < m_rows && col < m_cols) {
//			m_matrix[row][col] = value;
//		}
//		else {
//			cout << "Invalid insert location\n";
//		}
//	}
//	void insert(int* values) {
//		for (int row = 0; row < m_rows; row++) {
//			for (int col = 0; col < m_cols; col++) {
//				int valuesIndex = (row * m_cols) + col;
//				m_matrix[row][col] = values[valuesIndex];
//			}
//		}
//	}
//	void fill(int value) {
//		for (int row = 0; row < m_rows; row++) {
//			for (int col = 0; col < m_cols; col++) {
//				m_matrix[row][col] = value;
//			}
//		}
//	}
//	// Assignment operator: still modifies this and returns *this
//	Matrix& operator=(const Matrix& rhs) {
//		if (this != &rhs) {
//			clear();
//			m_matrix = nullptr;
//			m_cols = 0;
//			m_rows = 0;
//			if (rhs.m_cols > 0 && rhs.m_rows > 0) {
//				m_matrix = new int* [rhs.m_rows];
//				for (int i = 0; i < rhs.m_rows; ++i) {
//					m_matrix[i] = new int[rhs.m_cols];
//				}
//				for (int i = 0; i < rhs.m_rows; ++i) {
//					for (int j = 0; j < rhs.m_cols; ++j) {
//						m_matrix[i][j] = rhs.m_matrix[i][j];
//					}
//				}
//				m_cols = rhs.m_cols;
//				m_rows = rhs.m_rows;
//			}
//			else {
//				cout << "Invalid matrix size\n";
//			}
//		}
//		return *this;
//	}
//
//	// Fills this matrix with a value and returns *this
//	Matrix& operator=(int value) {
//		for (int i = 0; i < m_rows; ++i) {
//			for (int j = 0; j < m_cols; ++j) {
//				m_matrix[i][j] = value;
//			}
//		}
//		return *this;
//	}
//
//	// Matrix + Matrix — returns new Matrix
//	Matrix operator+(const Matrix& rhs) const {
//		if (m_rows != rhs.m_rows || m_cols != rhs.m_cols) {
//			cout << "Matrix size mismatch for addition\n";
//			Matrix temp(0, 0);
//			return temp;
//		}
//		Matrix result(m_rows, m_cols);
//		for (int i = 0; i < m_rows; ++i) {
//			for (int j = 0; j < m_cols; ++j) {
//				result.m_matrix[i][j] = m_matrix[i][j] + rhs.m_matrix[i][j];
//			}
//		}
//		return result;
//	}
//
//	// Matrix + int — returns new Matrix
//	Matrix operator+(int value) const {
//		Matrix result(m_rows, m_cols);
//		for (int i = 0; i < m_rows; ++i) {
//			for (int j = 0; j < m_cols; ++j) {
//				result.m_matrix[i][j] = m_matrix[i][j] + value;
//			}
//		}
//		return result;
//	}
//
//	// Matrix * int — scalar multiplication
//	Matrix operator*(int value) const {
//		Matrix result(m_rows, m_cols);
//		for (int i = 0; i < m_rows; ++i) {
//			for (int j = 0; j < m_cols; ++j) {
//				result.m_matrix[i][j] = m_matrix[i][j] * value;
//			}
//		}
//		return result;
//	}
//
//	// Matrix * Matrix — matrix multiplication (dot product)
//	Matrix operator*(const Matrix& rhs) const {
//		if (m_cols != rhs.m_rows) {
//			cout << "Matrix size mismatch for multiplication\n";
//			Matrix temp(0, 0);
//			return temp;
//		}
//		Matrix result(m_rows, rhs.m_cols);
//		for (int i = 0; i < m_rows; ++i) {
//			for (int j = 0; j < rhs.m_cols; ++j) {
//				result.m_matrix[i][j] = 0;
//				for (int k = 0; k < m_cols; ++k) {
//					result.m_matrix[i][j] += m_matrix[i][k] * rhs.m_matrix[k][j];
//				}
//			}
//		}
//		return result;
//	}
//private:
//	int m_rows;
//	int m_cols;
//	int** m_matrix;
//	void initializeMatrix() {
//		for (int row = 0; row < m_rows; row++) {
//			for (int col = 0; col < m_cols; col++) {
//				m_matrix[row][col] = 0;
//			}
//		}
//	}
//};
//
//int main() {
//	int a[] = { 6,4,
//		        8,3 };
//
//	int b[] = { 1,2,3,
//			    4,5,6 };
//
//	int c[] = { 2,4,6,
//				1,3,5 };
//
//	Matrix A(2, 2);
//	A.insert(a);
//	Matrix B(2, 3);
//	B.insert(b);
//	Matrix C(2, 3);
//	C.insert(c);
//	A.dump("A");
//	B.dump("B");
//	C.dump("C");
//
//	Matrix D(0, 0);
//	D = (B + 3);
//	D.dump("B + 3");
//	D = C + B;
//	D.dump("C + B");
//	
//
//	return 0;
//}