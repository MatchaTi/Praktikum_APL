#include <iostream>
#include <string>
#include <algorithm>

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
    int layout;
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
    cout << "   Layout\t: " << keyboards[index].layout << endl;
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
    int layout;
    cout << "Masukkan nama keyboard: ";
    cin >> namaKeyboard;
    cout << "Masukkan layout keyboard: ";
    cin >> layout;
    cout << "Masukkan keycaps: ";
    cin >> keycaps;
    cout << "Masukkan switchs: ";
    cin >> switchs;
    keyboards[jumlahKeyboard].nama = namaKeyboard;
    keyboards[jumlahKeyboard].layout = layout;
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
        cout << "Masukkan layout keyboard baru: ";
        cin >> keyboards[index - 1].layout;
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

// Fungsi untuk menukar dua elemen pada array
void swap(keyboard *arr, int i, int j)
{
    keyboard temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Fungsi untuk membagi array dan mengembalikan indeks pivot
int partition(keyboard *arr, int low, int high)
{
    string pivot = arr[high].nama; // Pilih elemen pivot (terakhir)
    int i = low - 1;               // Indeks elemen yang lebih kecil dari pivot

    for (int j = low; j < high; j++)
    {
        // Jika elemen saat ini lebih kecil dari atau sama dengan pivot
        if (arr[j].nama <= pivot)
        {
            i++;             // Pindahkan indeks batas atas
            swap(arr, i, j); // Tukar arr[i] dengan arr[j]
        }
    }
    swap(arr, i + 1, high); // Tukar arr[i+1] dengan arr[high] (pivot)
    return i + 1;           // Kembalikan indeks pivot
}

// Fungsi utama untuk melakukan quicksort
void quickSort(keyboard *arr, int low, int high)
{
    if (low < high)
    {
        // Ambil indeks pivot yang dipartisi
        int pivot = partition(arr, low, high);

        // Panggil quickSort secara rekursif pada dua bagian yang terbagi
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Fungsi untuk menggabungkan dua bagian array yang terurut
void merge(keyboard *arr, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Buat array sementara untuk kedua bagian
    keyboard Left[n1], Right[n2];

    // Salin data ke array sementara
    for (int i = 0; i < n1; i++)
        Left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];

    // Gabungkan array sementara kembali ke array utama
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (Left[i].layout >= Right[j].layout)
        {
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen dari Left[] jika ada
    while (i < n1)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }

    // Salin sisa elemen dari Right[] jika ada
    while (j < n2)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

// Fungsi utama untuk melakukan merge sort
void mergeSort(keyboard *arr, int low, int high)
{
    if (low < high)
    {
        // Temukan titik tengah
        int mid = low + (high - low) / 2;

        // Panggil mergeSort untuk bagian kiri
        mergeSort(arr, low, mid);

        // Panggil mergeSort untuk bagian kanan
        mergeSort(arr, mid + 1, high);

        // Gabungkan bagian yang terurut
        merge(arr, low, mid, high);
    }
}

// Fungsi untuk melakukan bubble sort
void bubbleSort(keyboard *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].layout > arr[j + 1].layout)
            {
                // Tukar elemen jika elemen saat ini lebih besar dari elemen berikutnya
                keyboard temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fungsi Interpolation Search untuk mencari kata dalam array kata yang sudah terurut secara ascending
int interpolationSearch(keyboard *arr, int n, string key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high && key >= arr[low].nama && key <= arr[high].nama)
    {
        // Hitung posisi perkiraan menggunakan rumus interpolasi
        double fraction = double(key.length() - arr[low].nama.length()) / double(arr[high].nama.length() - arr[low].nama.length());
        int pos = low + (high - low) * fraction;

        // Jika kata ditemukan di posisi perkiraan
        if (arr[pos].nama == key)
            return pos;

        // Jika kata terletak di bagian kiri dari posisi perkiraan
        if (arr[pos].nama < key)
            low = pos + 1;
        // Jika kata terletak di bagian kanan dari posisi perkiraan
        else
            high = pos - 1;
    }
    // Jika kata tidak ditemukan
    return -1;
}

// Fungsi Binary Search untuk mencari angka dalam array yang sudah terurut secara descending
int binarySearch(keyboard *arr, int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Jika angka ditemukan di tengah
        if (arr[mid].layout == key)
            return mid;

        // Jika angka terletak di sebelah kiri dari tengah
        if (arr[mid].layout < key)
            high = mid - 1;
        // Jika angka terletak di sebelah kanan dari tengah
        else
            low = mid + 1;
    }
    // Jika angka tidak ditemukan
    return -1;
}

int main()
{
    const int MAX_KEYBOARD = 10;
    keyboard keyboards[MAX_KEYBOARD] = {{"Maxfit61", 61, {"PBT", "Gateron"}}, {"Orbiter67", 67, {"ABS", "Cherry"}}};
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
        string key;
        int index, lyt;

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
        case 5:
            clearScreen();
            cout << "List keyboard berdasarkan nama (ASC / Quick Sort)" << endl;
            quickSort(keyboardPointer, 0, jumlahKeyboard - 1);
            showKeyboardsRecursively(keyboardPointer, 0, jumlahKeyboard);
            enterContinue();
            break;
        case 6:
            clearScreen();
            cout << "List keyboard berdasarkan layout (DSC / Merge Sort)" << endl;
            mergeSort(keyboardPointer, 0, jumlahKeyboard - 1);
            showKeyboardsRecursively(keyboardPointer, 0, jumlahKeyboard);
            enterContinue();
            break;
        case 7:
            clearScreen();
            cout << "List keyboard berdasarkan layout (ASC / Bubble Sort)" << endl;
            bubbleSort(keyboardPointer, jumlahKeyboard);
            showKeyboardsRecursively(keyboardPointer, 0, jumlahKeyboard);
            enterContinue();
            break;
        case 8:
            clearScreen();
            cout << "Mencari nama keyboard (ASC / Interpolation Search)" << endl;
            quickSort(keyboardPointer, 0, jumlahKeyboard - 1);
            cout << "Masukkan nama keyboard yang dicari: ";
            cin >> key;

            index = interpolationSearch(keyboardPointer, jumlahKeyboard, key);

            if (index != -1)
            {
                cout << endl
                     << "Keyboard " << key << " ditemukan: " << endl;
                cout << "Nama\t: " << keyboards[index].nama << endl;
                cout << "Layout\t: " << keyboards[index].layout << endl;
                cout << "Keycaps\t: " << keyboards[index].komponenKeyboard.keycaps << endl;
                cout << "Switchs\t: " << keyboards[index].komponenKeyboard.switchs << endl;
                cout << endl;
                enterContinue();
            }
            else
            {
                cout << endl
                     << "Keyboard " << key << " tidak ditemukan." << endl;
                enterContinue();
            }
            break;
        case 9:
            clearScreen();
            cout << "Mencari layout keyboard pertama yang ditemukan(DSC / Binary Search)" << endl;
            mergeSort(keyboardPointer, 0, jumlahKeyboard - 1);
            cout << "Masukkan jumlah layout keyboard yang dicari: ";
            cin >> lyt;

            index = binarySearch(keyboardPointer, 0, jumlahKeyboard, lyt);

            if (index != -1)
            {
                cout << endl
                     << "Keyboard " << key << " ditemukan: " << endl;
                cout << "Nama\t: " << keyboards[index].nama << endl;
                cout << "Layout\t: " << keyboards[index].layout << endl;
                cout << "Keycaps\t: " << keyboards[index].komponenKeyboard.keycaps << endl;
                cout << "Switchs\t: " << keyboards[index].komponenKeyboard.switchs << endl;
                cout << endl;
                enterContinue();
            }
            else
            {
                cout << endl
                     << "Keyboard " << key << " tidak ditemukan." << endl;
                enterContinue();
            }
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
    cout << "[5] Urutkan list keyboard berdasarkan nama (ASC / Quick Sort)" << endl;
    cout << "[6] Urutkan list keyboard berdasarkan layout (DSC / Merge Sort)" << endl;
    cout << "[7] Urutkan list keyboard berdasarkan layout (ASC / Bubble Sort)" << endl;
    cout << "[8] Mencari nama keyboard (ASC / Interpolation Search)" << endl;
    cout << "[9] Mencari layout keyboard pertama yang ditemukan (DSC / Binary Search)" << endl;
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
