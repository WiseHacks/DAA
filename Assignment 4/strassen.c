#include <stdio.h>
#include <stdlib.h>
using namespace std;


struct Matrix {
	int M[100][100];
};

void print(Matrix Mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// cout << Mat.M[i][j] << " ";
			printf("%d ", Mat.M[i][j]);
		}
		printf("\n");
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
Matrix Subtraction(Matrix A, Matrix B, int n) { //A-B
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A.M[i][j] = A.M[i][j] - B.M[i][j];
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

	Matrix P1, P2, P3, P4, P5, P6, P7;
	int k = (n / 2);
	P1 = Multiplication(A11, Subtraction(B12, B22, k), k);
	P2 = Multiplication(Addition(A11, A12, k), B22, k);
	P3 = Multiplication(Addition(A21, A22, k), B11, k);
	P4 = Multiplication(A22, Subtraction(B21, B11, k), k);
	P5 = Multiplication(Addition(A11, A22, k), Addition(B11, B22, k), k);
	P6 = Multiplication(Subtraction(A12, A22, k), Addition(B21, B22, k), k);
	P7 = Multiplication(Subtraction(A11, A21, k), Addition(B11, B12, k), k);

	// combining all submat in res;
	Matrix C11, C12, C21, C22;
	C11 = Subtraction(Addition(Addition(P5, P4, k), P6, k), P2, k);
	C12 = Addition(P1, P2, k);
	C21 = Addition(P3, P4, k);
	C22 = Subtraction(Addition(P5, P1, k), Addition(P3, P7, k), k);

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
	// cin >> n;
	scanf("%d", &n);
	Matrix A, B;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// cin >> A.M[i][j];
			scanf("%d", &A.M[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// cin >> B.M[i][j];
			scanf("%d", &B.M[i][j]);
		}
	}
	int cnt = 0, temp = n;
	while (temp > 1)temp /= 2, cnt++;
	bool is = (1 << cnt) == n;
	if ((n % 2 && n > 1) || !is) {
		printf("Requirements not fullfield\n");
		return 0;
	}
	Matrix product = Multiplication(A, B, n);
	print(product, n);
}
