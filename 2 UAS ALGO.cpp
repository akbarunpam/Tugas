#include <iostream>

using namespace std;

// Fungsi untuk melakukan bubble sort pada array
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Tukar elemen jika elemen saat ini lebih besar dari elemen berikutnya
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Fungsi untuk melakukan selection sort pada array
void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        // Temukan indeks elemen terkecil
        minIndex = j;
      }
    }
    // Tukar elemen terkecil dengan elemen pada indeks i
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

// Fungsi untuk melakukan insertion sort pada array
void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    // Pindahkan elemen yang lebih besar dari key ke posisi yang lebih tinggi
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

// Fungsi untuk melakukan shell sort pada array
void shellSort(int arr[], int n) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
}

// Fungsi untuk melakukan merge pada array
void merge(int arr[], int left, int middle, int right) {
  int n1 = middle - left + 1;
  int n2 = right - middle;

  // Buat array sementara
  int L[n1], R[n2];

  // Salin data ke array sementara L[] dan R[]
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[middle + 1 + j];

  // Gabungkan array sementara kembali ke arr[left..right]
  int i = 0;
  int j = 0;
  int k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Salin sisa elemen dari L[], jika ada
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Salin sisa elemen dari R[], jika ada
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Fungsi untuk melakukan merge sort pada array
void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    // Temukan titik tengah
    int middle = left + (right - left) / 2;

    // Sort separuh pertama dan kedua
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);

    // Gabungkan hasilnya
    merge(arr, left, middle, right);
  }
}

// Fungsi untuk melakukan partisi dan quicksort pada array
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // Pilih pivot
  int i = (low - 1); // Temukan indeks tempat pivot seharusnya berada

  for (int j = low; j <= high - 1; j++) {
    // Jika elemen saat ini lebih kecil dari atau sama dengan pivot
    if (arr[j] <= pivot) {
      i++; // Tingkatkan indeks dari elemen yang lebih kecil
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

// Fungsi untuk melakukan quicksort pada array
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    // Dapatkan indeks partisi
    int pi = partition(arr, low, high);

    // Pisahkan elemen di sekitar partisi dan lakukan quicksort pada setiap bagian
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  cout << "Nama    : Akbar Ramadhan\n";
  cout << "NIM     : 221011400987\n";
  cout << "Matkul  : ALGORITMA DAN PEMROGRAMAN II\n";
  cout << "Kelas   : 03 TPLE 019 CS\n" << endl;

  const int MAX_SIZE = 100; // Maksimum jumlah elemen dalam array
  int arr[MAX_SIZE];
  int n;

  cout << "Masukkan banyak data: ";
  cin >> n;

  if (n > MAX_SIZE) {
    cout << "Jumlah nilai melebihi batas maksimum." << endl;
    return 1; // Keluar dari program dengan kode error
  }

  cout << "Masukkan Value: \n";
  for (int i = 0; i < n; i++) {
    cout << "Data " << i + 0 << ": ";
    cin >> arr[i];
  }

  // Menampilkan nilai-nilai dalam array sebelum diurutkan
  cout << "Data sebelum diurutkan: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  //    printArray(arr, n);
  cout << endl;

  // Menu untuk memilih jenis sorting
  int pilihan;
  do {
    cout << "\nPilih jenis sorting:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Shell Sort\n";
    cout << "5. Merge Sort\n";
    cout << "6. Quick Sort\n";
    cout << "7. All Sort\n";
    cout << "8. Keluar\n";
    cout << "Masukkan pilihan 0-8: ";
    cin >> pilihan;

    // Melakukan sorting sesuai pilihan pengguna
    switch (pilihan) {
    case 1:
      cout << "---------------------\n";
      bubbleSort(arr, n);
      cout << "Bubble Sort: ";
      for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << "\n" << "---------------------";
      break;
    case 2:
      cout << "---------------------\n";
      selectionSort(arr, n);
      cout << "Selection Sort: ";
      for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << "\n" << "---------------------";
      break;
    case 3:
      cout << "---------------------\n";
      insertionSort(arr, n);
      cout << "Insertion Sort: ";
      for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << "\n" << "---------------------";
      break;
    case 4:
      cout << "---------------------\n";
      shellSort(arr, n);
      cout << "Shell Sort: ";
      for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << "\n" << "---------------------";
      break;
    case 5:
      cout << "---------------------\n";
      cout << "Merge Sort" << endl;
      mergeSort(arr, 0, n - 1);
      cout << "1. Ascending" << endl;
      cout << "2. Descending" << endl;
      cout << "3. Keluar" << endl;

      cout << "Pilihan anda (1-3): " << endl;
      cin >> pilihan;
      cout << "---------------------\n";
      cout << "Merge Sort: ";
      switch (pilihan) {
      case 1:
        cout << "Ascending: ";
        for (int i = 0; i < n; i++) {
          cout << arr[i] << " ";
        }
        break;
      case 2:
        cout << "Descending: ";
        for (int i = n - 1; i >= 0; i--) {
          cout << arr[i] << " ";
        }
        break;
      case 3:
        cout << "Keluar";
        break;
      default:
        cout << "Pilihan tidak valid.\n";
        break;
        //	                case 1:
        //	                quickSort(arr, 0, n - 1);
        //	                cout << "Ascending: ";
        //	                break;
        //	                quickSort(arr, 0, n - 1);
        //	                cout << "Discending: ";

        //	                	case 1:
        //	                	for (int i = 0; i < n; i++){
        //	                		cout << "Merger Sort Ascending";
        //	                		cout << arr [i] << " ";
      }
      cout << "\n" << "---------------------";
      break;
    case 6:
      cout << "---------------------\n";
      quickSort(arr, 0, n - 1);
      cout << "Quick Sort: ";
      for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << "\n" << "---------------------";
      break;
    case 7:
      cout << "---------------------\n";
      bubbleSort(arr, n);
      cout << "Bubble Sort: ";
      for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      selectionSort(arr, n);
      cout << endl;
      cout << "Selection Sort: ";
      for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
      insertionSort(arr, n);
      cout << "Insertion Sort: ";
      for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
      shellSort(arr, n);
      cout << "Shell Sort: ";
      for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
      mergeSort(arr, 0, n - 1);
      cout << "Merge Sort: ";
      for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
      quickSort(arr, 0, n - 1);
      cout << "Quick Sort: ";
      for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << "\n" << "---------------------";
      break;
    case 8:
      cout << "Keluar dari program.\n";
      break;
    default:
      cout << "Pilihan tidak valid.\n";
      break;
    }

    // Menampilkan nilai-nilai dalam array setelah diurutkan
    if (pilihan != 8) {
      //            for (int i = 0; i < n; i++) {
      //                cout << arr[i] << " ";
      //            }
      cout << endl;
    }

  } while (pilihan != 8);

  return 0;
}
