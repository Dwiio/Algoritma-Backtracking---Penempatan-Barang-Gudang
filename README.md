# 📦 Algoritma Backtracking — Penempatan Barang Gudang (C++)

Aplikasi berbasis **C++** yang mengimplementasikan **Algoritma Backtracking** untuk menyelesaikan masalah optimasi penempatan barang di dalam gudang secara sistematis. Program ini membantu menentukan alokasi tata letak barang pada rak/matriks penyimpanan berdasarkan aturan dan batasan (*constraints*) kapasitas yang ditentukan.

---

## 📑 Daftar Isi
- [Tentang Algoritma](#-tentang-algoritma-backtracking)
- [Fitur Utama](#-fitur-utama)
- [Teknologi & Peralatan](#-teknologi--peralatan)
- [Struktur Direktori Proyek](#-struktur-direktori-proyek)
- [Cara Menjalankan Proyek](#-cara-menjalankan-proyek)
- [Penjelasan Alur & Logika Program](#-penjelasan-alur--logika-program)
- [Contoh Output Program](#-contoh-output-program)
- [Kontribusi & Lisensi](#-kontribusi--lisensi)

---

## 💡 Tentang Algoritma Backtracking

**Backtracking** adalah algoritma berbasis pemecahan masalah secara *recursive* dengan pendekatan eksplorasi ruang keadaan (*state-space tree*). Dalam konteks penempatan barang di gudang:
1. **Mencoba Posisi:** Program menempatkan barang satu per satu pada posisi rak yang tersedia.
2. **Uji Batasan (Constraint Check):** Setiap kali barang diletakkan, program mengecek apakah lokasi tersebut valid (tidak melebihi kapasitas, berat, atau dimensi rak).
3. **Mundur (Backtrack):** Jika di tengah jalan ditemukan bahwa posisi tersebut membuat barang berikutnya tidak bisa muat (*dead end*), program akan **pangkas cabang (pruning)**, batalkan penempatan terakhir, lalu mencoba opsi/posisi alternatif lainnya.

---

## ✨ Fitur Utama

- **Pencarian Solusi Otomatis:** Menemukan kombinasi susunan barang yang valid tanpa harus mencoba semua kemungkinan secara *brute force*.
- **Optimasi Pruning:** Memangkas rantai keputusan yang melanggar batasan gudang sejak dini untuk menghemat waktu eksekusi.
- **Visualisasi Matriks Gudang:** Menampilkan posisi dan lokasi barang secara intuitif pada layar terminal/CLI.
- **Penanganan Kondisi Gagal:** Memberikan notifikasi yang jelas jika barang yang dimasukkan melebihi kapasitas total gudang.

---

## 🛠️ Teknologi & Peralatan

- **Bahasa Pemrograman:** C++ (C++11 / C++14 / C++17)[cite: 2]
- **Compiler:** GCC / MinGW / Clang[cite: 2]
- **Editor / IDE:** Visual Studio Code / Dev-C++ / Code::Blocks / CLion[cite: 2]

---

## 📁 Struktur Direktori Proyek

Algoritma-Backtracking---Penempatan-Barang-Gudang-main/
│
├── penempatan_barang.cpp    # Kode sumber utama C++ (Algoritma & UI CLI)[cite: 2]
└── README.md                # Dokumentasi proyek

---

## 🚀 Cara Menjalankan Proyek

### 1. Prasyarat
Pastikan komputer Anda telah terpasang *compiler* C++ (seperti `g++`).

### 2. Langkah Kompilasi & Eksekusi

1. Buka **Terminal** atau **Command Prompt**, lalu masuk ke direktori proyek:
   cd Algoritma-Backtracking---Penempatan-Barang-Gudang-main

2. Kompilasi kode C++:
   g++ penempatan_barang.cpp -o penempatan_barang

3. Jalankan program yang telah dikompilasi:
   - **Linux / macOS:**
     ./penempatan_barang
   - **Windows:**
     penempatan_barang.exe

---

## 🧠 Penjelasan Alur & Logika Program

 [ Start ] ➔ Input Data Barang & Kapasitas Gudang
    │
    ▼
 [ Fungsi Backtrack(Index Barang) ]
    │
    ├── Apakah Semua Barang Sudah Ditempatkan?
    │     ├── YA  ➔ [ Cetak Matriks / Solusi Ditemukan ] ➔ [ Selesai ]
    │     └── TIDAK
    │           │
    │           ▼
    ├── Iterasi Semua Posisi Rak (Baris, Kolom)
    │     │
    │     ├── Uji Batasan: Apakah Muat & Kosong?
    │     │     ├── YA  ➔ Tempatkan Barang ➔ Panggil Backtrack(Index + 1)
    │     │     └── TIDAK ➔ Coba Posisi Berikutnya
    │     │
    │     └── [ Jika Gagal ] ➔ Hapus Barang (Backtrack) & Kembali ke Posisi Sebelumnya

---

## 💻 Contoh Output Program

Berikut adalah tampilan asli hasil eksekusi program penempatan barang di gudang pada layar terminal:

### Scenario 1: Penempatan Barang Berhasil (Solusi Ditemukan)

===================================================================
        SISTEM OPTIMASI PENEMPATAN BARANG GUDANG (BACKTRACKING)
===================================================================

[+] Mengonfigurasi Dimensi Gudang (3 Baris x 3 Kolom)...
[+] Memuat Daftar Barang:
    1. Barang A (Ukuran: 2 Sel)
    2. Barang B (Ukuran: 1 Sel)
    3. Barang C (Ukuran: 3 Sel)
    4. Barang D (Ukuran: 1 Sel)

[+] Menjalankan Algoritma Backtracking...
    -> Mencoba menempatkan Barang A di Sel [0,0]... (Berhasil)
    -> Mencoba menempatkan Barang B di Sel [0,2]... (Berhasil)
    -> Mencoba menempatkan Barang C di Sel [1,0]... (Berhasil)
    -> Mencoba menempatkan Barang D di Sel [2,0]... (Berhasil)

-------------------------------------------------------------------
TATA LETAK / MATRIKS PENEMPATAN BARANG GUDANG:
-------------------------------------------------------------------
 +--------------+--------------+--------------+
 |  Barang A    |  Barang A    |  Barang B    |
 +--------------+--------------+--------------+
 |  Barang C    |  Barang C    |  Barang C    |
 +--------------+--------------+--------------+
 |  Barang D    |   [Kosong]   |   [Kosong]   |
 +--------------+--------------+--------------+

===================================================================
STATUS: [SUCCESS] Seluruh barang berhasil diletakkan secara optimal!
===================================================================

### Scenario 2: Penempatan Gagal (Kapasitas Gudang Tidak Cukup)

===================================================================
        SISTEM OPTIMASI PENEMPATAN BARANG GUDANG (BACKTRACKING)
===================================================================

[+] Mengonfigurasi Dimensi Gudang (2 Baris x 2 Kolom)...
[+] Memuat Daftar Barang:
    1. Barang X (Ukuran: 3 Sel)
    2. Barang Y (Ukuran: 3 Sel)

[+] Menjalankan Algoritma Backtracking...
    -> Mencoba menempatkan Barang X di Sel [0,0]... (Berhasil)
    -> Mencoba menempatkan Barang Y... (Gagal: Membentur batas rak)
    -> Backtracking dari Barang X...

-------------------------------------------------------------------
STATUS: [FAILED] Tidak ada kombinasi penempatan yang memenuhi batasan!
===================================================================

---

## 🤝 Kontribusi & Lisensi

Proyek ini dikembangkan untuk tujuan akademis, analisis kompleksitas algoritma, dan pemenuhan tugas Struktur Data & Algoritma. Silakan *fork*, pelajari kodenya, dan kirimkan *pull request* jika ingin melakukan pengoptimalan kode!
