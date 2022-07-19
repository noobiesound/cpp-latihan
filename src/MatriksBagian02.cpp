/* Program Invers Matriks oleh AFP.
 * Dibuat pada tanggal 19/07/2022, ditulis menggunakan C++. 
 */

#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>

using namespace std;

// Deklarasi function khusus untuk mencetak array.
void printArray(int* array, int baris, int kolom);
void printArray(string* array, int baris, int kolom);

// Deklarasi berbagai function untuk keperluan mencari
// invers matriks.
int det(int input[2][2]);
void invers(int input[2][2], string output[2][2]);
int det(int input[3][3]);
void invers(int input[3][3], string output[3][3]);

// Deklarasi function tambahan.
void header(string msg);

// Program utama.
int main() {
	
	header("Invers Matriks");
	
	// Deklarasi matriks pertama.
	int arr_1[2][2] = {
		{5, -8}, 
		{-3, 2}
	};
	
	// Deklarasi matriks kedua.
	int arr_2[3][3] = {
		{3, -2, 0}, 
		{2, 7, -8}, 
		{6, 1, -5}
	};
	
	string arrInv_1[2][2];
	string arrInv_2[3][3];
	
	// Output matriks pertama beserta inversnya.
	cout << "> Matriks Pertama" << endl;
	printArray(*arr_1, 2, 2);
	
	cout << "> Invers" << endl;
	invers(arr_1, arrInv_1);
	printArray(*arrInv_1, 2, 2);
	
	// Output matriks kedua beserta inversnya.
	cout << "> Matriks Kedua" << endl;
	printArray(*arr_2, 3, 3);
	
	cout << "> Invers" << endl;
	invers(arr_2, arrInv_2);
	printArray(*arrInv_2, 3, 3);
	
	return 0;
	
}

// Function khusus untuk mencetak header/judul pada bagian atas.
void header(string msg) {
	
	system("cls");
	int len = msg.length();
	int i = 0;
	
	for (i = 0; i < len + 4; i++) {
		cout << "=";
	}
	cout << "\n";
	
	cout << "| " << msg << " |" << endl;
	
	for (i = 0; i < len + 4; i++) {
		cout << "=";
	}
	cout << "\n\n";
	
}

// Function untuk mencetak array bertipe data integer.
void printArray(int* array, int baris, int kolom) {
	int k = 0;
	
	for (int i = 0; i < baris; i++) {
		cout << "| ";
		
		for (int j = 0; j < kolom; j++) {
			cout << *(array + k) << " ";
			k++;
		}
		
		cout << "|\n";
	}
	
	cout << "\n";	
}

// Function untuk mencetak array bertipe data string.
void printArray(string* array, int baris, int kolom) {
	int k = 0;
	
	for (int i = 0; i < baris; i++) {
		cout << "| ";
		
		for (int j = 0; j < kolom; j++) {
			cout << *(array + k) << " ";
			k++;
		}
		
		cout << "|\n";
	}
	
	cout << "\n";
}

// Function untuk mencari determinan matriks berordo 2x2.
int det(int input[2][2]) {

	// Untuk ordo 2x2, rumus determinannya = ad - bc.
	int hasil;
	return hasil = (input[0][0] * input[1][1]) - (input[0][1] * input[1][0]);
	
}

// Function untuk mencari determinan matriks berordo 3x3.
int det(int input[3][3]) {
	
	int i, j, k, l;
    	int hasil = 0;   
    	int hasil1 = 0;
    	int hasil2 = 0;
    	int temp = 1;
    	i = 0;
    	k = 0;
    
    	// Untuk ordo 3x3, di sini digunakanlah aturan Sarrus.
    	for (i = 0; i < 3; i++) {
    
		j = 0;
		temp = 1;
		l = k;
    
		for (j = 0; j < 3; j++) {
		    if (l > 2) {
			l = 0;
		    }

		    temp *= input[j][l];
		    l++;
		}

		k++;
		hasil1 += temp;
    
    	}
    
    	k = 2;
    
    	for (i = 0; i < 3; i++) {
    
		j = 0;
		temp = 1;
		l = k;
    
		for (j = 0; j < 3; j++) {
		    if (l < 0) {
			l = 2;
		    }

		    temp *= input[j][l];
		    l--;
		}
    
        k--;
        hasil2 += temp;
    
    	}
	
	hasil = hasil1 - hasil2;
	return hasil;
	
}

// Function untuk mencari invers matriks berordo 2x2.
void invers(int input[2][2], string output[2][2]) {
	
	int i, j;
	int detMat = det(input);
	
	// Mencari matriks adjoin.
	int arrayAdj[2][2];
	
	arrayAdj[0][0] = input[1][1];
	arrayAdj[1][1] = input[0][0];
	arrayAdj[0][1] = input[0][1] * (-1);
	arrayAdj[1][0] = input[1][0] * (-1);
	
	// Mencari inversnya.
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			
			if (detMat == 0) {
				cout << "Error!";
			} else if (detMat == 1) {
				output[i][j] = to_string(arrayAdj[i][j]);
			} else if (arrayAdj[i][j] % detMat == 0) {
				arrayAdj[i][j] /= detMat;
				output[i][j] = to_string(arrayAdj[i][j]);
			} else {
				if (detMat < 0) {
					output[i][j] = to_string(arrayAdj[i][j] * (-1)) + "/" + to_string(detMat * (-1));
				} else {
					output[i][j] = to_string(arrayAdj[i][j]) + "/" + to_string(detMat);
				}
			}
			
		}
	}
	
}

// Function untuk mencari invers matriks berordo 3x3.
void invers(int input[3][3], string output[3][3]) {
	
	int i = 0, j = 0, k = 0, l = 0;
	int detMat = det(input);
	
	// Mencari elemen matriks minornya.
	int KofIndex = 0;
	int eleKof[36];

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++) {
		    		for (l = 0; l < 3; l++) {

					if ((k == i) || (l == j)) {
						continue;
					} else {
						eleKof[KofIndex] = input[k][l];
						KofIndex++;
					}

		    		}
			}
	    	}
	}
	
	// Mencari matriks kofaktor.
	int arrayKof[3][3];
    	KofIndex = 0;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			arrayKof[i][j] = pow(-1, (i + j)) * ((eleKof[KofIndex] * eleKof[KofIndex + 3]) - (eleKof[KofIndex + 1] * eleKof[KofIndex + 2]));
			KofIndex += 4;
		}
    	}
    
	// Mencari matriks adjoin.
	int arrayAdj[3][3];
    
    	for (i = 0; i < 3; i++) {
    		for (j = 0; j < 3; j++) {
    			arrayAdj[j][i] = arrayKof[i][j];
		}
	}
	
	// Mencari invers.
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			
			if (detMat == 0) {
				cout << "Error!";
			} else if (detMat == 1) {
				output[i][j] = to_string(arrayAdj[i][j]);
			} else if (arrayAdj[i][j] % detMat == 0) {
				arrayAdj[i][j] /= detMat;
				output[i][j] = to_string(arrayAdj[i][j]);
			} else {
				if (detMat < 0) {
					output[i][j] = to_string(arrayAdj[i][j] * (-1)) + "/" + to_string(detMat * (-1));
				} else {
					output[i][j] = to_string(arrayAdj[i][j]) + "/" + to_string(detMat);
				}
			}
			
		}
	}
	
}
