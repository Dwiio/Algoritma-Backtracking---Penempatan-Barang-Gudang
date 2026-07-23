# 📦 Algoritma Backtracking — Penempatan Barang Gudang (C++)

Aplikasi berbasis **C++** yang mengimplementasikan **Algoritma Backtracking** untuk menyelesaikan masalah optimasi penempatan barang di dalam gudang. Program ini membantu menentukan tata letak dan alokasi ruang gudang secara efisien berdasarkan aturan dan batasan (*constraints*) kapasitas yang ditentukan.

---

## ✨ Fitur Utama

- **Pencarian Solusi Otomatis:** Menggunakan pendekatan eksplorasi *state-space tree* dengan algoritma *backtracking* untuk menemukan alokasi penempatan barang yang valid.
- **Pangkas Cabang (Pruning):** Mengabaikan kombinasi posisi yang tidak memenuhi batasan kapasitas atau ukuran gudang sehingga proses pencarian lebih cepat dan efisien.
- **Input Fleksibel:** Memproses data barang (ukuran/dimensi/bobot) serta kapasitas ruang penyimpanan gudang.
- **Visualisasi Output:** Menampilkan hasil susunan dan matriks/tata letak posisi barang di gudang secara jelas di terminal/CLI.

---

## 🛠️ Teknologi & Peralatan

- **Bahasa Pemrograman:** C++ (C++11 / C++14 / C++17)[cite: 2]
- **Compiler:** GCC / MinGW / Clang[cite: 2]
- **IDE / Editor:** Visual Studio Code / Dev-C++ / Code::Blocks / CLion[cite: 2]

---

## Contoh Output Program
==================================================
   SISTEM OPTIMASI PENEMPATAN BARANG GUDANG
==================================================

[+] Memproses penempatan barang menggunakan Backtracking...

Matriks Layout Gudang (3x3):
[ Barang 1 ] [ Barang 2 ] [ Kosong   ]
[ Barang 3 ] [ Barang 4 ] [ Barang 5 ]
[ Kosong   ] [ Kosong   ] [ Kosong   ]

Status: Solusi penempatan barang berhasil ditemukan!
==================================================

## 📁 Struktur Direktori Proyek

```text
Algoritma-Backtracking---Penempatan-Barang-Gudang-main/
│
├── penempatan_barang.cpp    # Kode sumber utama C++[cite: 2]
└── README.md                # Dokumentasi proyek

