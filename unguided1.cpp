#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Fungsi untuk menampilkan adjacency matrix
void displayMatrix(const vector<vector<int>>& matrix, const vector<string>& simpul) {
    int n = matrix.size();

    // Menampilkan header kolom
    cout << setw(12) << " ";
    for (int i = 0; i < n; ++i) {
        cout << setw(12) << simpul[i];
    }
    cout << endl;

    // Menampilkan matrix
    for (int i = 0; i < n; ++i) {
        cout << setw(12) << simpul[i];
        for (int j = 0; j < n; ++j) {
            cout << setw(12) << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> n;

    vector<string> simpul(n);
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    // Input nama simpul
    for (int i = 0; i < n; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul[i];
    }

    // Input bobot antar simpul
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << simpul[i] << " --> " << simpul[j] << " = ";
            cin >> matrix[i][j];
        }
    }

    // Menampilkan adjacency matrix
    cout << endl << setw(12) << " ";
    for (int i = 0; i < n; ++i) {
        cout << setw(12) << simpul[i];
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << setw(12) << simpul[i];
        for (int j = 0; j < n; ++j) {
            cout << setw(12) << matrix[i][j];
        }
        cout << endl;
    }

    // Meminta input untuk menghitung jarak dari satu kota ke kota lainnya
    int start, end;
    cout << "\nMasukkan indeks kota awal: ";
    cin >> start;
    cout << "Masukkan indeks kota tujuan: ";
    cin >> end;

    cout << "Jarak dari " << simpul[start] << " ke " << simpul[end] << " adalah " << matrix[start][end] << endl;

    return 0;
}
