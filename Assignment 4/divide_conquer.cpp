#include <bits/stdc++.h>
using namespace std;


struct Matrix {
	int M[100][100];
};

void print(Matrix Mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << Mat.M[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix Addition(Matrix A, Matrix B, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A.M[i][j] = A.M[i][j] + B.M[i][j];
		}
	}
	return A;
}

Matrix Multiplication(Matrix A, Matrix B, int n) {
	Matrix res;

	if (n == 1) {
		res.M[0][0] = A.M[0][0] * B.M[0][0];
		return res;
	}

	Matrix A11, A12, A21, A22, B11, B12, B21, B22;
	for (int i = 0; i < (n / 2); i++) {
		for (int j = 0; j < (n / 2); j++) {
			A11.M[i][j] = A.M[i][j];
			A12.M[i][j] = A.M[i][j + (n / 2)];
			A21.M[i][j] = A.M[i + (n / 2)][j];
			A22.M[i][j] = A.M[i + (n / 2)][j + (n / 2)];
			B11.M[i][j] = B.M[i][j];
			B12.M[i][j] = B.M[i][j + (n / 2)];
			B21.M[i][j] = B.M[i + (n / 2)][j];
			B22.M[i][j] = B.M[i + (n / 2)][j + (n / 2)];
		}
	}

	Matrix C11 = Addition(Multiplication(A11, B11, (n / 2)) , Multiplication(A12, B21, (n / 2)), (n / 2));
	Matrix C12 = Addition(Multiplication(A11, B12, (n / 2)) , Multiplication(A12, B22, (n / 2)), (n / 2));
	Matrix C21 = Addition(Multiplication(A21, B11, (n / 2)) , Multiplication(A22, B21, (n / 2)), (n / 2));
	Matrix C22 = Addition(Multiplication(A21, B12, (n / 2)) , Multiplication(A22, B22, (n / 2)), (n / 2));

	// combining all submat in res;

	for (int i = 0; i < (n / 2); i++) {
		for (int j = 0; j < (n / 2); j++) {
			res.M[i][j] = C11.M[i][j];
			res.M[i][j + (n / 2)] = C12.M[i][j];
			res.M[i + (n / 2)][j] = C21.M[i][j];
			res.M[i + (n / 2)][j + (n / 2)] = C22.M[i][j];
		}
	}

	return res;
}
int main() {

	int n;
	cin >> n;
	Matrix A, B;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A.M[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> B.M[i][j];
		}
	}
	if ((n % 2 && n > 1) || (bitset<32> (n)).count() != 1) {
		cout << "requirements not fullfield";
		return 0;
	}
	Matrix product = Multiplication(A, B, n);
	print(product, n);
}
