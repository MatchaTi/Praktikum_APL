#include <iostream>

using namespace std;

// Fungsi Prosedur 1
void clearScreen() { system("cls || clear"); };

// Fungsi Prosedur 2
void enterContinue()
{
    cout << "\n Tekan enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
    clearScreen();
}

// Fungsi 1
bool login();

// Fungsi 2
int menu(int pilihan);

// Fungsi Rekursif
void showKeyboardsRecursively(string keyboards[], int index, int jumlahKeyboard)
{
    if (index == jumlahKeyboard)
        return;

    cout << index + 1 << ". " << keyboards[index] << endl;
    showKeyboardsRecursively(keyboards, index + 1, jumlahKeyboard);
}

// Funsgi Prosedur 3
void addKeyboard(string keyboards[], int &jumlahKeyboard)
{
    string namaKeyboard;
    cout << "Masukkan nama keyboard: ";
    cin >> namaKeyboard;
    keyboards[jumlahKeyboard] = namaKeyboard;
    jumlahKeyboard++;
    cout << "Keyboard berhasil ditambahkan" << endl;
}

// Fungsi Prosedur 4
void editKeyboard(string keyboards[], int jumlahKeyboard)
{
    int index;
    cout << "Pilih keyboard yang akan diubah: ";
    cin >> index;
    if (index >= 1 && index <= jumlahKeyboard)
    {
        cout << "Masukkan nama keyboard baru: ";
        cin >> keyboards[index - 1];
        cout << "Keyboard berhasil diubah" << endl;
    }
    else
    {
        cout << "Index tidak tersedia";
    }
}

// Fungsi Prosedur 5
void deleteKeyboard(string keyboards[], int &jumlahKeyboard)
{
    int index;
    cout << "Pilih keyboard yang akan dihapus: ";
    cin >> index;
    if (index >= 1 && index <= jumlahKeyboard)
    {
        for (int i = index - 1; i < jumlahKeyboard; i++)
        {
            keyboards[i] = keyboards[i + 1];
        }
        jumlahKeyboard--;
        cout << "Keyboard berhasil dihapus" << endl;
    }
    else
    {
        cout << "Index tidak tersedia";
    }
}

int main()
{
    const int MAX_KEYBOARD = 10;
    string keyboards[MAX_KEYBOARD] = {"Maxfit61", "Orbiter67"};
    int jumlahKeyboard = 2;
    clearScreen();

    bool isLogin = login();

    if (!isLogin)
    {
        clearScreen();
        cout << "Anda telah mencoba 3 kali, coba lagi nanti" << endl;
        return 0;
    }

    int pilihan;

    do
    {
        clearScreen();
        pilihan = menu(pilihan);

        switch (pilihan)
        {
        case 0:
            clearScreen();
            break;
        case 1:
            clearScreen();
            showKeyboardsRecursively(keyboards, 0, jumlahKeyboard);
            enterContinue();
            break;
        case 2:
            clearScreen();
            addKeyboard(keyboards, jumlahKeyboard);
            enterContinue();
            break;
        case 3:
            clearScreen();
            showKeyboardsRecursively(keyboards, 0, jumlahKeyboard);
            editKeyboard(keyboards, jumlahKeyboard);
            enterContinue();
            break;
        case 4:
            clearScreen();
            showKeyboardsRecursively(keyboards, 0, jumlahKeyboard);
            deleteKeyboard(keyboards, jumlahKeyboard);
            enterContinue();
            break;
        default:
            clearScreen();
            cout << "Pilihan tidak tersedia" << endl;
            enterContinue();
        }

    } while (pilihan != 0);

    clearScreen();
    cout << "Program selesai" << endl;
}

bool login()
{

    int counter = 0;
    bool isLogin = false;

    while (counter < 3 && !isLogin)
    {
        string nama, nim;

        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (nama == "Adi" && nim == "2309106065")
        {
            isLogin = true;
        }
        else
        {
            clearScreen();
            cout << "Tersisa " << 2 - counter << " percobaan lagi" << endl;
            counter++;
        }
    }

    return isLogin;
}

int menu(int pilihan)
{
    cout << "============================" << endl;
    cout << "Selamat Datang di Aplikasi" << endl;
    cout << "============================" << endl
         << endl;
    cout << "Menu" << endl;
    cout << "[1] Tampilkan list Mechanical Keyboard" << endl;
    cout << "[2] Tambah Mechanical Keyboard" << endl;
    cout << "[3] Edit nama Keyboard" << endl;
    cout << "[4] Hapus Keyboard" << endl;
    cout << "[0] Keluar" << endl;

    cout << "Pilihan: ";
    cin >> pilihan;

    return pilihan;
}
