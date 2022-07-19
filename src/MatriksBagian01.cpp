/* Program Operasi Penjumlahan dan Perkalian Dua Matriks oleh AFP.
 * Dibuat pada tanggal 18/07/2022, ditulis menggunakan C++. 
 */

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// Deklarasi function.
void jumlah(int* array1, int* array2, int baris, int kolom);
void kali(int* array1, int* array2, int baris1, int kolom1, int baris2, int kolom2);
void printArray(int* array, int baris, int kolom);
void header(string msg);
bool confirm();

// Program utama.
int main () {
	
	bool isContinue = true;
	while (isContinue) {
		
		header("Operasi Matriks");
	
		// Deklarasi matriks pertama.
		int arr_1[3][3] = {
			{4, 1, -9},
			{7, -1, 2},
			{-1, 8, 0}
		};
		
		// Deklarasi matriks kedua.
		int arr_2[3][3] = {
			{-2, -1, 4},
			{-7, 4, -9},
			{3, -6, -8}
		};
		
		// Mengambil properti dari masing-masing matriks.
		int baris_1 = sizeof(arr_1) / sizeof(arr_1[0]);
		int kolom_1 = sizeof(arr_1[0]) / sizeof(arr_1[0][0]);
		int baris_2 = sizeof(arr_2) / sizeof(arr_2[0]);
		int kolom_2 = sizeof(arr_2[0]) / sizeof(arr_2[0][0]);
		char op;
		
		cout << "> Matriks Pertama" << endl;
		printArray(*arr_1, baris_1, kolom_1);
		
		cout << "> Matriks Kedua" << endl;
		printArray(*arr_2, baris_2, kolom_2);
		
		cout << "> Pilih operasi :" << endl;
		cout << "  1. Penjumlahan" << endl;
		cout << "  2. Perkalian" << endl;
		cout << "\n> Opsi : ";
		cin >> op;
		
		switch(op) {
			// Syarat agar kedua matriks bisa dijumlahkan yaitu
			// ordonya harus sama.
			case '1' :
				cout << "\n> Penjumlahan" << endl;
		
				if ((baris_1 == baris_2) && (kolom_1 == kolom_2)) {
					jumlah(*arr_1, *arr_2, baris_2, kolom_2);
				} else {
					cout << "Error : Ordo kedua matriks tidak sama." << endl;
				}
				
				break;
				
			// Syarat agar kedua matriks bisa dikalikan yaitu
			// jumlah kolom pada matriks pertama harus sama dengan
			// jumlah baris pada matriks kedua.
			// Matriks hasil kali (C) -> A[m,n] x B[n, p] = C[m, p].
			case '2' :
				cout << "\n> Perkalian" << endl;
				
				if (kolom_1 == baris_2) {
					kali(*arr_1, *arr_2, baris_1, kolom_1, baris_2, kolom_2);
				} else {
					cout << "Error : Ordo kedua matriks tidak memenuhi syarat." << endl;
				}
				
				break;
	
			default :
				cout << "Error : Pilihan tidak dikenali." << endl;

		}
		
		// Konfirmasi apakah ingin mengulang operasi atau tidak.
		isContinue = confirm();
		
	}
	
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

// Function untuk mencetak array.
void printArray(int* array, int baris, int kolom) {
	
	// Variabel k bisa dikatakan sebagai "manipulator"
	// address dari array-nya.
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

// Function untuk menjumlahkan kedua matriks.
void jumlah(int* array1, int* array2, int baris, int kolom) {
	
	int k = 0;
	int hasil[baris][kolom];
	
	// Proses penjumlahan.
	for (int i = 0; i < baris; i++) {
		for (int j = 0; j < kolom; j++) {
			hasil[i][j] = *(array1 + k) + *(array2 + k);
			k++;
		}
	}
	
	// Menampilkan hasil.
	printArray(*hasil, baris, kolom);
	
}

// Function untuk mengalikan kedua matriks.
void kali(int* array1, int* array2, int baris1, int kolom1, int baris2, int kolom2) {
	
	// Sebelum melakukan operasi, alangkah baiknya kedua matriks
	// dipindahkan ke wadah sementara karena kedua matriks yang
	// diinputkan masih berupa pointer.
	int i = 0, j = 0, k = 0;
	int temp1[baris1][kolom1];
	int temp2[baris2][kolom2];
	int hasil[baris1][kolom2];
	
	// Memindah elemen matriks pertama ke matriks temp1.
	for (i = 0; i < baris1; i++) {
		for (int j = 0; j < kolom1; j++) {
			temp1[i][j] = *(array1 + k);
			k++;
		}
	}
	
	// Memindah elemen matriks kedua ke matriks temp2.
	k = 0;
	for (i = 0; i < baris2; i++) {
		for (int j = 0; j < kolom2; j++) {
			temp2[i][j] = *(array2 + k);
			k++;
		}
	}
	
	// Proses perkalian.
	int temp = 0;
	for (i = 0; i < baris1; i++) {
		for (j = 0; j < kolom2; j++) {
			temp = 0;
			
			for (k = 0; k < baris2; k++) {
				temp += temp1[i][k] * temp2[k][j];
			}
			
			hasil[i][j] = temp;
		}
	}
	
	// Menampilkan hasil.
	printArray(*hasil, baris1, kolom2);
	
}

// Function khusus untuk konfirmasi user.
bool confirm() {
	
	bool isIncorrect = true, yes, no;
	char op;
	cout << "Ulangi lagi? [Y/N] : ";
	cin >> op;
	
	// Jika user memasukkan input selain huruf "y" atau "n," function ini
	// tetap "memaksa" user untuk memasukkan input secara benar.
	// Loop dihentikan (isIncorrect = false) apabila input yang
	// dimasukkan sudah benar, dan nantinya akan return 1/0 tergantung
	// dari input yang dimasukkan.
	while (isIncorrect) {
		yes = (op == 'Y' || op == 'y');
		no  = (op == 'N' || op == 'n');
		
		if (!(yes || no)) {
			cout << "Error : Pilihan tidak dikenali. Coba lagi." << endl;
			cout << "Ulangi lagi? [Y/N] : ";
			cin >> op;
			
		} else if (no) {
			isIncorrect = false;
			return false;
		} else {
			isIncorrect = false;
		}
	}
	
	return true;
	
}
