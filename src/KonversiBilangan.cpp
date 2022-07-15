#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <algorithm>

/* Program Konversi Bilangan oleh AFP.
 * Dibuat pada tanggal 13/12/2021, diterjemahkan dari Java.
 */

using namespace std;

// Deklarasi function-nya.
string ConvertNum(string a, int b, int c);
void ConvertNum_Test(string a, string b, string c, string d);


// Program utama.
int main() {

	cout << "Konversi" << endl;
	cout << "========\n" << endl;

	string angka = "";
	int basis1 = 0;
	int basis2 = 0;

	// Method ConvertNum_Test digunakan untuk mengetes apakah
	// method ConvertNum berjalan dengan baik atau tidak.
	string bin = "101011001101110101";
	string oct = "531565";
	string dec = "177013";
	string hex = "2b375";

	ConvertNum_Test(bin, oct, dec, hex);

	try {

		cout << "> Bilangan \t: ";
		cin >> angka;

		cout << "> Basis Awal \t: ";
		cin >> basis1;

		cout << "> Basis Tujuan \t: ";
		cin >> basis2;

	}

	catch (...) {
		cout << "\nTolong masukin angka, jangan masukin macem-macem njer!" << endl;
	}

	cout << "\n=================" << endl;
	cout << "> Hasil \t: ";

	string hasil = ConvertNum(angka, basis1, basis2);
	cout << hasil << endl;

	cin.get();
	return 0;

}

// Function utama untuk konversi bilangan.
string ConvertNum(string bil, int base1, int base2) {

	// Bilangan basis-10 (desimal) bisa langsung diproses.
	// Sedangkan untuk bilangan basis non-10, bilangan tersebut harus dipreteli
	// satu per satu, kemudian dimasukkan ke dalam wadah temp, baru nantinya
	// bisa diproses.
	
	int i = 0;
	int pString = bil.length();
	int count_8 = 0;
	int count_16 = 0;
	int pString_8 = 0;
	int pString_16 = 0;
	long tempNum[1000];
	long hasil = 0;
	long temp_10 = 0;
	string tempChar[1000];
	string tempStr[1000];
	string newStr = "";
	string newStr_2 = "";
	bool konf1 = ((base1 == 2) || (base1 == 8) || (base1 == 10) || (base1 == 16));
	bool konf2 = ((base2 == 2) || (base2 == 8) || (base2 == 10) || (base2 == 16));

	// Program ini hanya akan menerima angka 2/8/10/16 sebagai basis asal dan
	// basis tujuan.
	if (konf1 && konf2) {

		// Case asal = tujuan, langsung return input-nya.
		if (base1 == base2) {
			return bil;
		}

		else {

			switch (base1) {
				case 2:

					switch (base2) {
						case 10: // Case (2, 10)

							for (i = 0; i < pString; i++) {

								tempChar[i] = bil.substr(i, 1);
								tempNum[i] = stoi(tempChar[i]);

								if (tempNum[i] == 1) {
									hasil += pow(2, (pString - i - 1));
								} else if (tempNum[i] > 1) {
									cout << "ERROR!";
									break;
								}

							}

							// Khusus untuk case (2, 16) karena nantinya konversi 2 -> 16,
							// dikonversi ke desimal dulu (2 -> 10 -> 16).
							switch ((int)hasil) {
								case 10:
									newStr = newStr + "A";
									break;

								case 11:
									newStr = newStr + "B";
									break;

								case 12:
									newStr = newStr + "C";
									break;

								case 13:
									newStr = newStr + "D";
									break;

								case 14:
									newStr = newStr + "E";
									break;

								case 15:
									newStr = newStr + "F";
									break;

								default:
									newStr = newStr + to_string(hasil);
									break;
							}

							return newStr;

						case 8: // Case (2, 8), di akhir case nanti bakal memakai konversi 2 -> 10.

							pString_8 = pString;
							count_8 = pString_8 / 3;

							if (pString_8 % 3 != 0) {
								count_8 += 1;
							}

							for (i = 0; i < count_8; i++) {

								if (pString_8 >= 3) {

									tempStr[i] = bil.substr((pString_8 - 3), 3);
									pString_8 -= 3;

								} else {
									tempStr[i] = bil.substr(0, (pString_8 % 3));
								}

							}

							for (i = count_8 - 1; i >= 0; i--) {
								newStr_2 = newStr_2 + ConvertNum(tempStr[i], 2, 10);
							}

							return newStr_2;

						case 16: // Case (2, 16), di akhir case nanti bakal memakai konversi 2 -> 10.

							pString_16 = pString;
							count_16 = pString_16 / 4;

							if (pString_16 % 4 != 0) {
								count_16 += 1;
							}

							for (i = 0; i < count_16; i++) {

								if (pString_16 >= 4) {

									tempStr[i] = bil.substr((pString_16 - 4), 4);
									pString_16 -= 4;

								} else {
									tempStr[i] = bil.substr(0, (pString_16 % 4));
								}

							}

							for (i = count_16 - 1; i >= 0; i--) {
								newStr_2 = newStr_2 + ConvertNum(tempStr[i], 2, 10);
							}

							return newStr_2;

					}

				case 10: // Case (10, non-10), semua hanya dalam satu case.

					temp_10 = stol(bil);

					if ((base2 == 2) || (base2 == 8) || (base2 == 16)) {

						while (temp_10 > 0) {

							tempNum[i] = temp_10 % base2;
							temp_10 /= base2;
							i++;

						}

					} else {
						cout <<("ERROR!");
					}

					// Case khusus untuk bilangan heksadesimal.
					for (int j = i - 1; j >= 0; j--) {

						switch ((int)tempNum[j]) {
							case 10:
								newStr = newStr + ("A");
								continue;

							case 11:
								newStr = newStr + ("B");
								continue;

							case 12:
								newStr = newStr + ("C");
								continue;

							case 13:
								newStr = newStr + ("D");
								continue;

							case 14:
								newStr = newStr + ("E");
								continue;

							case 15:
								newStr = newStr + ("F");
								continue;

							default:
								newStr = newStr + to_string(tempNum[j]);
								continue;

						}

					}

					return newStr;

				case 8:

					switch (base2) {
						case 10: // Case (8, 10)

							for (i = 0; i < pString; i++) {
								tempChar[i] = bil.substr(i, 1);
								tempNum[i] = stoi(tempChar[i]);

								if (tempNum[i] < 8) {
									hasil += pow(8, (pString - i - 1)) * tempNum[i];
								} else {
									cout <<("ERROR!");
									break;
								}

							}

							return newStr = newStr + to_string(hasil);

						case 2:  // Case (8, 2), konversinya secara tidak langsung (8 -> 10 -> 2).
							return newStr_2 = ConvertNum(ConvertNum(bil, 8, 10), 10, 2);

						case 16: // Case (8, 16), konversinya secara tidak langsung (8 -> 10 -> 16).
							return newStr_2 = ConvertNum(ConvertNum(bil, 8, 10), 10, 16);

					}

				case 16:

					// Karena input dari user bisa memuat huruf kecil maupun besar,
					// input-nya harus dibuat kapital semua.
					transform(bil.begin(), bil.end(), bil.begin(), ::toupper);

					switch (base2) {
						case 10: // Case (16, 10).
							char charCase[1000];

							for (i = 0; i < pString; i++) {
								tempChar[i] = bil.substr(i, 1);
								charCase[i] = tempChar[i].at(0);

								switch (charCase[i]) {
									case 'A' :
										tempNum[i] = 10;
										break;

									case 'B' :
										tempNum[i] = 11;
										break;

									case 'C' :
										tempNum[i] = 12;
										break;

									case 'D' :
										tempNum[i] = 13;
										break;

									case 'E' :
										tempNum[i] = 14;
										break;

									case 'F' :
										tempNum[i] = 15;
										break;

									default:
										tempNum[i] = stoi(tempChar[i]);
								}

								if (tempNum[i] < 16) {
									hasil += pow(16, (pString - i - 1)) * tempNum[i];
								} else {
									cout << "ERROR!";
									break;
								}

							}

							return newStr = newStr + to_string(hasil);

						case 2: // Case (16, 2), konversinya secara tidak langsung (16 -> 10 -> 2).
							return newStr_2 = ConvertNum(ConvertNum(bil, 16, 10), 10, 2);

						case 8: // Case (16, 8), konversinya secara tidak langsung (16 -> 10 -> 8).
							return newStr_2 = ConvertNum(ConvertNum(bil, 16, 10), 10, 8);

					}

			}

		}

	}

	else {

		cout << "ERROR!" << endl;
		return newStr;

	}

	return "";

}

// Method khusus untuk mengecek apakah method ConvertNum berfungsi dengan baik
// atau tidak.
void ConvertNum_Test(string a1, string b1, string c1, string d1) {

	cout << "[Test Purpose Only]\n" << endl;

	string konversi = "";

	// Dari biner ke basis apa saja.
	konversi = ConvertNum(a1, 2, 8);
	cout << a1 << " [2] " << "= " << konversi << " [8] " << endl;
	konversi = ConvertNum(a1, 2, 10);
	cout << a1 << " [2] " << "= " << konversi << " [10] " << endl;
	konversi = ConvertNum(a1, 2, 16);
	cout << a1 << " [2] " << "= " << konversi << " [16] " << endl;
	cout << "\n";

	// Dari oktal ke basis apa saja.
	konversi = ConvertNum(b1, 8, 2);
	cout << b1 << " [8] " << "= " << konversi << " [2] " << endl;
	konversi = ConvertNum(b1, 8, 10);
	cout << b1 << " [8] " << "= " << konversi << " [10] " << endl;
	konversi = ConvertNum(b1, 8, 16);
	cout << b1 << " [8] " << "= " << konversi << " [16] " << endl;
	cout << "\n";

	// Dari desimal ke basis apa saja.
	konversi = ConvertNum(c1, 10, 2);
	cout << c1 << " [10] " << "= " << konversi << " [2] " << endl;
	konversi = ConvertNum(c1, 10, 8);
	cout << c1 << " [10] " << "= " << konversi << " [8] " << endl;
	konversi = ConvertNum(c1, 10, 16);
	cout << c1 << " [10] " << "= " << konversi << " [16] " << endl;
	cout << "\n";

	// Dari heksadesimal ke basis apa saja.
	transform(d1.begin(), d1.end(), d1.begin(), ::toupper);
	konversi = ConvertNum(d1, 16, 2);
	cout << d1 << " [16] " << "= " << konversi << " [2] " << endl;
	konversi = ConvertNum(d1, 16, 8);
	cout << d1 << " [16] " << "= " << konversi << " [8] " << endl;
	konversi = ConvertNum(d1, 16, 10);
	cout << d1 << " [16] " << "= " << konversi << " [10] " << endl;
	cout << ("\n");

}
