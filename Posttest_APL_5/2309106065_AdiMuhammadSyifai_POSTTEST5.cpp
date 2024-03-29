#include <iostream>

using namespace std;

// struct keyboard
struct komponen
{
    string keycaps;
    string switchs;
};

// nested struct
struct keyboard
{
    string nama;
    komponen komponenKeyboard;
};

// Fungsi Prosedur 1
void clearScreen() { system("cls || clear"); };

// Fungsi Prosedur 2
void enterContinue()
{
    cout << "\nTekan enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
    clearScreen();
}

// Fungsi 1
bool login();

// Fungsi 2
int menu(int pilihan);

// Fungsi Rekursif
// Fungsi dengan Dereference Operator pada parameter keyboards
void showKeyboardsRecursively(keyboard *keyboards, int index, int jumlahKeyboard)
{
    if (index == jumlahKeyboard)
        return;

    cout << index + 1 << ". Nama\t\t: " << keyboards[index].nama << endl;
    cout << "   Keycaps\t: " << keyboards[index].komponenKeyboard.keycaps << endl;
    cout << "   Switchs\t: " << keyboards[index].komponenKeyboard.switchs << endl;
    cout << endl;
    showKeyboardsRecursively(keyboards, index + 1, jumlahKeyboard);
}

// Funsgi Prosedur 3
// Fungsi dengan Dereference Operator pada parameter keyboards
// Fungsi dengan Address Operator pada parameter jumlahKeyboard
void addKeyboard(keyboard *keyboards, int &jumlahKeyboard)
{
    string namaKeyboard, keycaps, switchs;
    cout << "Masukkan nama keyboard: ";
    cin >> namaKeyboard;
    cout << "Masukkan keycaps: ";
    cin >> keycaps;
    cout << "Masukkan switchs: ";
    cin >> switchs;
    keyboards[jumlahKeyboard].nama = namaKeyboard;
    keyboards[jumlahKeyboard].komponenKeyboard.keycaps = keycaps;
    keyboards[jumlahKeyboard].komponenKeyboard.switchs = switchs;
    jumlahKeyboard++;
    cout << "Keyboard berhasil ditambahkan" << endl;
}

// Fungsi Prosedur 4
// Fungsi dengan Dereference Operator pada parameter keyboards
void editKeyboard(keyboard *keyboards, int jumlahKeyboard)
{
    int index;
    cout << "Pilih keyboard yang akan diubah: ";
    cin >> index;
    if (index >= 1 && index <= jumlahKeyboard)
    {
        cout << "Masukkan nama keyboard baru: ";
        cin >> keyboards[index - 1].nama;
        cout << "Masukkan keycaps baru: ";
        cin >> keyboards[index - 1].komponenKeyboard.keycaps;
        cout << "Masukkan switchs baru: ";
        cin >> keyboards[index - 1].komponenKeyboard.switchs;
        cout << "Keyboard berhasil diubah" << endl;
    }
    else
    {
        cout << "Index tidak tersedia";
    }
}

// Fungsi Prosedur 5
// Fungsi dengan Dereference Operator pada parameter keyboards
// Fungsi dengan Address Operator pada parameter jumlahKeyboard
void deleteKeyboard(keyboard *keyboards, int &jumlahKeyboard)
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
    keyboard keyboards[MAX_KEYBOARD] = {{"Maxfit61", {"PBT", "Gateron"}}, {"Orbiter67", {"ABS", "Cherry"}}};
    keyboard *keyboardPointer = keyboards;
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
            cout << "List Keyboard" << endl;
            showKeyboardsRecursively(keyboardPointer, 0, jumlahKeyboard);
            enterContinue();
            break;
        case 2:
            clearScreen();
            // Error Handling untuk jumlah maksimal keyboard yang bisa ditambahkan
            if (jumlahKeyboard >= MAX_KEYBOARD)
            {
                cout << "Jumlah keyboard sudah mencapai batas maksimal" << endl;
                enterContinue();
                break;
            }
            addKeyboard(keyboardPointer, jumlahKeyboard);
            enterContinue();
            break;
        case 3:
            clearScreen();
            showKeyboardsRecursively(keyboardPointer, 0, jumlahKeyboard);
            editKeyboard(keyboardPointer, jumlahKeyboard);
            enterContinue();
            break;
        case 4:
            clearScreen();
            showKeyboardsRecursively(keyboardPointer, 0, jumlahKeyboard);
            deleteKeyboard(keyboardPointer, jumlahKeyboard);
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

    // Error Handling untuk inputan menu
    while (true)
    {
        cout << "Pilihan: ";
        cin >> pilihan;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Input tidak valid, silahkan masukkan angka" << endl;
        }
        else
        {
            break;
        }
    }

    return pilihan;
}
