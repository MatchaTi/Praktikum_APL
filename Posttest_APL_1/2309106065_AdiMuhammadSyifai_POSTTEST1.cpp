#include <iostream>

using namespace std;

// maaf Bang dan Mbak, hapus fungsi clearScreen() jika error
void clearScreen() { system("cls || clear "); }

void enterContinue() {
  cout << "\nTekan enter untuk melanjutkan...";
  cin.ignore(10, '\n');
  cin.get();
  clearScreen();
}

bool login();

void menu();

void konversiKilometer();

void konversiCentimeter();

void konversiMeter();

void konversiMil();

int main() {
  clearScreen();

  bool isLogin = login();

  if (!isLogin) {
    clearScreen();
    cout << "Anda telah mencoba 3 kali, coba lagi nanti" << endl;
    return 0;
  }

  int pilihan;

  do {
    clearScreen();
    menu();
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
    case 0:
      clearScreen();
      break;
    case 1:
      clearScreen();
      konversiKilometer();
      break;
    case 2:
      clearScreen();
      konversiCentimeter();
      break;
    case 3:
      clearScreen();
      konversiMeter();
      break;
    case 4:
      clearScreen();
      konversiMil();
      break;
    default:
      clearScreen();
      cout << "Pilihan tidak tersedia" << endl;
    }

  } while (pilihan != 0);

  clearScreen();
  cout << "Program selesai" << endl;

  return 0;
}

bool login() {

  int counter = 0;
  bool isLogin = false;

  while (counter < 3 && !isLogin) {
    string nama, nim;

    cout << "Masukkan Nama: ";
    cin >> nama;
    cout << "Masukkan NIM: ";
    cin >> nim;

    if (nama == "Adi" && nim == "2309106065") {
      isLogin = true;
    } else {
      clearScreen();
      cout << "Tersisa " << 2 - counter << " percobaan lagi" << endl;
      counter++;
    }
  }

  return isLogin;
}

void menu() {
  cout << "Menu" << endl;
  cout << "[1] Konversi Kilometer/Jam ke (Centimeter/Detik, Meter/Detik, "
          "Mil/Jam)"
       << endl;
  cout << "[2] Konversi Centimeter/Detik ke (Kilometer/Jam, Meter/Detik, "
          "Mil/Jam)"
       << endl;
  cout << "[3] Konversi Meter/Detik ke (Centimeter/Detik, Kilometer/Jam, "
          "Mil/Jam)"
       << endl;
  cout << "[4] Konversi Mil/Jam ke (Centimeter/Detik, Meter/Detik, "
          "Kilometer/Jam)"
       << endl;
  cout << "[0] Keluar" << endl;
}

void konversiKilometer() {
  double nilai;

  cout << "Masukkan nilai dalam Kilometer/jam: ";
  cin >> nilai;
  cout << "Nilai dalam Centimeter/detik: " << nilai * 27.7778 << endl;
  cout << "Nilai dalam Meter/detik: " << nilai * 0.277778 << endl;
  cout << "Nilai dalam Mil/jam: " << nilai * 0.621371 << endl;
  enterContinue();
}

void konversiCentimeter() {
  double nilai;

  cout << "Masukkan nilai dalam Centimeter/detik: ";
  cin >> nilai;
  cout << "Nilai dalam Kilometer/jam: " << nilai * 0.036 << endl;
  cout << "Nilai dalam Meter/detik: " << nilai * 0.01 << endl;
  cout << "Nilai dalam Mil/jam: " << nilai * 0.0223694 << endl;
  enterContinue();
}

void konversiMeter() {
  double nilai;

  cout << "Masukkan nilai dalam Meter/detik: ";
  cin >> nilai;
  cout << "Nilai dalam Kilometer/jam: " << nilai * 3.6 << endl;
  cout << "Nilai dalam Centimeter/detik: " << nilai * 100 << endl;
  cout << "Nilai dalam Mil/jam: " << nilai * 2.23694 << endl;
  enterContinue();
}

void konversiMil() {
  double nilai;

  cout << "Masukkan nilai dalam Mil/jam: ";
  cin >> nilai;
  cout << "Nilai dalam Kilometer/jam: " << nilai * 1.60934 << endl;
  cout << "Nilai dalam Centimeter/detik: " << nilai * 44.704 << endl;
  cout << "Nilai dalam Meter/detik: " << nilai * 0.44704 << endl;
  enterContinue();
}
