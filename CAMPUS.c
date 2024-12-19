#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    char hari[20];
    char tanggal[20];
    char jam[10];
    char mataKuliah[50];
    char kelas[20];
    char ruangan[20];
} Jadwal;
Jadwal jadwalList;
int jumlahJadwal = 0;


void tambahJadwal(){
    printf("\nTambah Jadwal \n");
    printf("Masukkan Hari : "); 
    scanf("%s", jadwalList.hari);
    printf("Masukkan Tanggal (DD/MM/YYYY) : ");
    scanf("%s", jadwalList.tanggal);
    printf("Masukkan Jam (JJ:MM): ");
    scanf("%s", jadwalList.jam);
    printf("Masukkan Mata Kuliah : ");
    scanf("%s", jadwalList.mataKuliah);
    printf("Masukkan Ruangan : ");
    scanf("%s", jadwalList.ruangan);
    printf("Jadwal Berhasil ditambahkan!");
    jumlahJadwal++;
}
void lihatJadwal(){
   char konfirmasi;
    
    if (jumlahJadwal == 0)
    {
        printf("\nTidak ada Jadwal yang ditambahkan!\n");
        printf("Tambah jadwal? (y/n) : ");
        scanf(" %c", &konfirmasi);
        if (konfirmasi == 'y' ){
            tambahJadwal();
        }
        else{
            printf("\nKembali ke kelola jadwal\n");
            return;
        }
    }
    else{
        printf("\n------------------DAFTAR JADWAL------------------ \n");
        printf("Jadwal Ke-%d \n", jumlahJadwal);
        printf("Hari : %s\n", jadwalList.hari);
        printf("Tanggal : %s\n", jadwalList.tanggal);
        printf("Jam : %s\n", jadwalList.jam);
        printf("Mata Kuliah : %s\n", jadwalList.mataKuliah);
        printf("Ruangan : %s\n", jadwalList.ruangan);
        printf("--------------------------------------------------\n");
        printf("Kembali? (y/n) :  ");
        scanf(" %c", &konfirmasi);
    }
   
}

void kelolaJadwal() {
    int opsiJadwal = 0;

    while (1) {
        printf("\n--Kelola Jadwal--\n");
        printf("1. Tambah Jadwal\n");
        printf("2. Lihat Jadwal\n");
        printf("3. Edit Jadwal\n");
        printf("4. Hapus Jadwal\n");
        printf("5. Kembali ke Dashboard\n");
        printf("Pilih Opsi: ");
        scanf("%d", &opsiJadwal);
        switch (opsiJadwal)
        {
        case 1:
            tambahJadwal();
            break;
        case 2:
            lihatJadwal();
            break;
        default:
            break;
        }
    }
    printf("\n--Kelola Jadwal--\n");
    printf("Fitur ini akan menampilkan dan mengelola jadwal Anda.\n");
}

void kelolaTugas() {
    int opsiTugas = 0;
    while (1) {
        printf("\n--Kelola Tugas--\n");
        printf("1. Tambah Tugas\n");
        printf("2. Lihat Tugas\n");
        printf("3. Edit Tugas\n");
        printf("4. Hapus Tugas\n");
        printf("5. Kembali ke Dashboard\n");
        printf("Pilih Opsi: ");
        scanf("%d", &opsiTugas);
    }
   
}

void kalkulatorAkademik() {
    int opsiKalkulator = 0;

     while (1) {
        printf("\n--Kelola Tugas--\n");
        printf("1. Tambah Tugas\n");
        printf("2. Lihat Tugas\n");
        printf("3. Edit Tugas\n");
        printf("4. Hapus Tugas\n");
        printf("5. Kembali ke Dashboard\n");
        printf("Pilih Opsi: ");
        scanf("%d", &opsiKalkulator);
    }
}

void notes() {
    printf("\n--Notes--\n");
    printf("Fitur ini akan memungkinkan Anda mencatat hal penting.\n");
}

void materiKontakDosen() {
    printf("\n--Akses Materi & Kontak Dosen--\n");
    printf("Fitur ini memungkinkan Anda mengakses materi kuliah dan informasi kontak dosen.\n");
}

int main (){
    char username[50], password [50], usernameTerdaftar[50] = "", passwordTerdaftar[50] = "";
    int opsi, opsiDashboard, signIn, halamanAwal = 1, dashboard = 1;

    while (halamanAwal = 1)
    {
        printf(" \n \n--CAMPUS--\nAplikasi keseharian mahasiswa\n \npilih opsi dibawah\n \n1. Sign In\n2. Sign Up\n3. Keluar\nPilih Opsi: ");
        scanf("%d", &opsi);
        if (opsi == 1)
        {
            printf("\n \n--Sign in--\n \n");
            printf("Masukkan Username  : ");
            scanf("%s", username);
            printf("Masukkan Password : ");
            scanf("%s", password);
            if (strcmp(usernameTerdaftar, "") == 0 && strcmp(passwordTerdaftar, "") == 0)
                {
                    printf(" \nSign Up Terlebih Dahulu!\n");
                }
                else
                {
                    while (strcmp(username, usernameTerdaftar) != 0 || strcmp(password, passwordTerdaftar) != 0)
                    {
                        printf("Data Tidak Benar, Silahkan Ulangi!\n");
                        printf("Masukkan Username : ");
                        scanf("%s", username);
                        printf("Masukkan Password : ");
                        scanf("%s", password);
                    }
                    printf(" \nSign In berhasil!\n");
                    signIn = 1;
                }
                while (signIn == 1)
                {
                       halamanAwal = 0;
                       dashboard = 1;
                       printf("\n--Dashboard--\n \n");
                       printf("\n--Pilih Fitur y--\n \n");
                       printf("1. Kelola Jadwal\n2. Kelola Tugas\n3. Kalkulator Akademik\n4. Notes \n5. Akses Materi & Kontak Dosen \n6. Keluar\n Pilih Opsi: ");
                       scanf("%d", &opsiDashboard);
                        switch (opsiDashboard) {
                    case 1:
                        kelolaJadwal();
                        break;
                    case 2:
                        kelolaTugas();
                        break;
                    case 3:
                        kalkulatorAkademik();
                        break;
                    case 4:
                        notes();
                        break;
                    case 5:
                        materiKontakDosen();
                        break;
                    case 6:
                        printf("\nKeluar dari dashboard.\n");
                        signIn = 0;
                        break;
                    default:
                        printf("\nPilihan tidak tersedia!\n");
                }
                }
                    
        }
        else if (opsi == 2)
        {
            printf("\n \n--Sign Up--\n \n");
            printf("Masukkan Username : ");;
            scanf("%s", username);
            printf("Masukkan Password : ");
            scanf("%s", password);
            strcpy(usernameTerdaftar, username);
            strcpy(passwordTerdaftar, password);
            printf("\nAkun telah terdaftar!");
        }
        else if (opsi == 3)
        {
            break;
        }
        else
        {
            printf("\n--Pilihan Tidak Tersedia--\n \n");
        }
        
    
    }
}

   