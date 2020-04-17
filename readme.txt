Rombongan C Kelompok 1

Username             Nama                           NIM

Ranvan12             Raditya Adhidarma Nugraha      13218068
tifanysaulina        Tifany Saulina Nababan         13218070
clementeja           Krishudson Clement Teja        13218079
Satrio25             Satrio Puji Laksono            13218084

Notes:
Untuk mencoba program, compile berkas-berkas dibawah ini, lalu
run berkas main.c. Folder 'Fungsi Test' berisi fungsi test yang
dibuat untuk berkas-berkas sesuai dengan namanya.

main.c pernah tak sengaja terhapus pada commit
"8e90e020963a46e4957f3371b43ec8ad56def8cc" dan direvert oleh
clementeja pada commit "aeb59f5a6fc6e95bef6814be794f971da8dce8d2"

Berkas dan kegunaannya :
main.c      :
    - main() sebagai main program
lib.h       :
    - sebagai library yang menggabungkan semua berkas
InputFile.c :
    - input_file() untuk prosedur input seed melalui file
Simulate.c  :
    - AliveNeighbor() untuk prosedur pengecekan banyaknya sel 
      yang hidup disekitar suatu sel
    - Update() untuk memperbarui isi dari data hidup/mati sel 
      bedasarkan hasil pengecekan prosedur AliveNeighbor().
display.c   :
    - display() untuk menampilkan semua sel pada layar.
    - delay() untuk menambah jeda waktu antar display agar dapat
      dilihat keindahannya.