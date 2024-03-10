#include <iostream>

using namespace std;

void clearScreen() { system("cls || clear"); };

void enterContinue()
{
    cout << "\n Tekan enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
    clearScreen();
}

bool login();

void menu();

void showKeyboards(string keyboards[], int jumlahKeyboard)
{
    for (int i = 0; i < jumlahKeyboard; i++)
    {
        cout << i + 1 << ". " << keyboards[i] << endl;
    }
}

void addKeyboard(string keyboards[], int &jumlahKeyboard)
{
    string namaKeyboard;
    cout << "Masukkan nama keyboard: ";
    cin >> namaKeyboard;
    keyboards[jumlahKeyboard] = namaKeyboard;
    jumlahKeyboard++;
}

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
        menu();
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 0:
            clearScreen();
            break;
        case 1:
            clearScreen();
            showKeyboards(keyboards, jumlahKeyboard);
            enterContinue();
            break;
        case 2:
            clearScreen();
            addKeyboard(keyboards, jumlahKeyboard);
            enterContinue();
            break;
        case 3:
            clearScreen();
            showKeyboards(keyboards, jumlahKeyboard);
            editKeyboard(keyboards, jumlahKeyboard);
            enterContinue();
            break;
        case 4:
            clearScreen();
            showKeyboards(keyboards, jumlahKeyboard);
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

void menu()
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
}
