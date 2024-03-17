#include <iostream>

using namespace std;

// Prosedur 1
void clearScreen();

// Prosedur 2
void enterContinue();

// Prosedur 3
void menu();

// Fungsi 1
float luasLingkaran(float jariJari);

// Fungsi 2
float luasSegitiga(float alas, float tinggi);

// Fungsi Rekursif
int faktorial(int n);

// Fungsi Utama
int main()
{
    clearScreen();
    int pilihan;

    do
    {
        clearScreen();
        menu();
        float hasil;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 0:
            clearScreen();
            break;
        case 1:
            clearScreen();
            cout << "Menghitung Luas Lingkaran" << endl;
            float jariJari;
            cout << "Masukkan jari-jari: ";
            cin >> jariJari;
            hasil = luasLingkaran(jariJari);
            cout << "Luas lingkaran dengan jari-jari " << jariJari << " adalah " << hasil << endl;
            enterContinue();
            break;
        case 2:
            clearScreen();
            cout << "Menghitung Luas Segitiga" << endl;
            float alas, tinggi;
            cout << "Masukkan alas: ";
            cin >> alas;
            cout << "Masukkan tinggi: ";
            cin >> tinggi;
            hasil = luasSegitiga(alas, tinggi);
            cout << "Luas segitiga dengan alas " << alas << " dan tinggi " << tinggi << " adalah " << hasil << endl;
            enterContinue();
            break;
        case 3:
            clearScreen();
            cout << "Menghitung Hasil Faktorial" << endl;
            int n;
            cout << "Masukkan n: ";
            cin >> n;
            hasil = faktorial(n);
            cout << "Hasil faktorial dari " << n << " adalah " << hasil << endl;
            enterContinue();
            break;
        default:
            clearScreen();
            cout << "Pilihan tidak tersedia" << endl;
            enterContinue();
        }

    } while (pilihan != 0);

    clearScreen();
    cout << "Terima kasih telah menggunakan aplikasi ini" << endl;
    return 0;
}

void clearScreen() { system("cls || clear"); };

void enterContinue()
{
    cout << "\n Tekan enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
    clearScreen();
}

void menu()
{
    cout << "============================" << endl;
    cout << "Selamat Datang di Aplikasi" << endl;
    cout << "============================" << endl
         << endl;
    cout << "Menu" << endl;
    cout << "[1] Menghitung Luas Lingkaran" << endl;
    cout << "[2] Menghitung Luas Segitiga" << endl;
    cout << "[3] Menghitung Hasil Faktorial" << endl;
    cout << "[0] Keluar" << endl;
}

float luasLingkaran(float jariJari)
{
    return 3.14 * jariJari * jariJari;
}

float luasSegitiga(float alas, float tinggi)
{
    return 0.5 * alas * tinggi;
}

int faktorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * faktorial(n - 1);
    }
}