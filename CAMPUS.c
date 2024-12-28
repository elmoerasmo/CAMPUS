#include <stdio.h>
#include <string.h>
#include <time.h>
//------------------------------------------------------------JADWAL-----------------------------------------------------------------------
typedef struct {
    char hari[100][20];
    char jam[100][20];
    char tanggal[100][20];
    char mataKuliah[100][50];
    char kelas[100][20];
    char ruangan[100][20];
} Jadwal;
Jadwal jadwalList;
int jumlahJadwal = 0;


void tambahJadwal(){
    if(jumlahJadwal < 100){
        printf("\nTambah Jadwal \n");
        printf("Masukkan Hari : "); 
        scanf("%s", jadwalList.hari[jumlahJadwal]);
        printf("Masukkan Tanggal (HH/BB/TTTT) : ");
        scanf("%s", jadwalList.tanggal[jumlahJadwal]);
        printf("Masukkan Jam (JJ:MM): ");
        scanf("%s", jadwalList.jam[jumlahJadwal]);
        printf("Masukkan Mata Kuliah : ");
        scanf(" %[^\n]", jadwalList.mataKuliah[jumlahJadwal]);
        printf("Masukkan Ruangan : ");
        scanf(" %[^\n]", jadwalList.ruangan[jumlahJadwal]);
        printf("Jadwal Berhasil ditambahkan!");
        jumlahJadwal++;
    }
    else{
        printf("\nJadwal sudah penuh!");
    }
 
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
        for (int i = 0; i < jumlahJadwal; i++)
        {
            printf("-Jadwal Ke-%d- \n", i + 1);
            printf("Hari : %s\n", jadwalList.hari[i]);
            printf("Tanggal : %s\n", jadwalList.tanggal[i]);
            printf("Jam : %s\n", jadwalList.jam[i]);
            printf("Mata Kuliah : %s\n", jadwalList.mataKuliah[i]);
            printf("Ruangan : %s\n", jadwalList.ruangan[i]);
            printf("\n");
        }
            printf("--------------------------------------------------\n");
        printf("Kembali? (y/n) :  ");
        scanf(" %c", &konfirmasi);
        if (konfirmasi == 'y')
        {
            printf("\nKembali ke menu utama\n");
            return;
        }
        
    }
   
}
void editJadwal(){
     int index;
    if (jumlahJadwal == 0) {
        printf("\nTidak ada Jadwal untuk diedit!\n");
        return;
    }
    printf("Masukkan nomor jadwal yang ingin diedit (1 - %d): ", jumlahJadwal);
    scanf("%d", &index);
    
    if (index < 1 || index > jumlahJadwal) {
        printf("Jadwal tidak ditemukan.\n");
        return;
    }
    index--; 

    printf("\nEdit Jadwal Ke-%d:\n", index + 1);
    printf("Masukkan Hari baru : ");
    scanf("%s", jadwalList.hari[index]);
    printf("Masukkan Tanggal baru (DD/MM/YYYY) : ");
    scanf("%s", jadwalList.tanggal[index]);
    printf("Masukkan Jam baru (HH:MM) : ");
    scanf("%s", jadwalList.jam[index]);
    printf("Masukkan Mata Kuliah baru : ");
    scanf(" %[^\n]", jadwalList.mataKuliah[index]);
    printf("Masukkan Ruangan baru : ");
    scanf(" %[^\n]", jadwalList.ruangan[index]);
    
    printf("Jadwal Ke-%d berhasil diedit!\n", index + 1);
}

void hapusJadwal(){
    int index;
    if (jumlahJadwal == 0) {
        printf("\nTidak ada Jadwal untuk dihapus!\n");
        return;
    }
    printf("Masukkan nomor jadwal yang ingin dihapus (1 - %d): ", jumlahJadwal);
    scanf("%d", &index);
    
    if (index < 1 || index > jumlahJadwal) {
        printf("Jadwal tidak ditemukan.\n");
        return;
    }
    index--;

    for (int i = index; i < jumlahJadwal - 1; i++) {
        strcpy(jadwalList.hari[i], jadwalList.hari[i + 1]);
        strcpy(jadwalList.tanggal[i], jadwalList.tanggal[i + 1]);
        strcpy(jadwalList.jam[i], jadwalList.jam[i + 1]);
        strcpy(jadwalList.mataKuliah[i], jadwalList.mataKuliah[i + 1]);
        strcpy(jadwalList.ruangan[i], jadwalList.ruangan[i + 1]);
    }

    jumlahJadwal--; 
    printf("Jadwal Ke-%d berhasil dihapus!\n", index + 1);
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
        case 3:
            editJadwal();
            break;
        case 4:
            hapusJadwal();
            break;
        case 5:
            return;
        default:
            printf("Opsi tidak valid. Silakan pilih ulang.\n");
            break;
        }
    }
}
//---------------------------------------------------------------------TUGAS-------------------------------------------------------------------------
struct Tugas {
    char namaTugas[50];
    char jenisTugas[30];
    char deadline[20];
    char penanggungJawab[50];
};

struct Tugas tugasList[100];
int jumlahTugas = 0;

// menampilkan tugas
void tampilkanTugas() {
    if (jumlahTugas == 0) {
        printf("\nTidak ada tugas yang tersedia.\n");
        return;
    }
    else{
        printf("\n=== Daftar Tugas ===\n");
    for (int i = 0; i < jumlahTugas; i++) {
        printf("Tugas %d:\n", i + 1);
        printf("  Nama Tugas      : %s\n", tugasList[i].namaTugas);
        printf("  Jenis Tugas     : %s\n", tugasList[i].jenisTugas);
        printf("  Deadline        : %s\n", tugasList[i].deadline);
        printf("  Penanggung Jawab: %s\n\n", tugasList[i].penanggungJawab);
    }
    }
    
}

// tambah tugas
void tambahTugas() {
    if (jumlahTugas >= 100) {
        printf("Daftar tugas penuh!\n");
        return;
    }

    printf("\nMasukkan informasi tugas baru:\n");
    printf("Nama Tugas      : ");
    scanf(" %[^\n]", tugasList[jumlahTugas].namaTugas);
    printf("Jenis Tugas (kelompok/individu)    : ");
    scanf(" %[^\n]", tugasList[jumlahTugas].jenisTugas);
    printf("Deadline (DD/MM/YYYY): ");
    scanf(" %[^\n]", tugasList[jumlahTugas].deadline);  
    printf("Penanggung Jawab: ");
    scanf(" %[^\n]", tugasList[jumlahTugas].penanggungJawab);

    printf("Tugas berhasil ditambahkan!\n");
    jumlahTugas++;
}


void kelolaTugas() {
    int pilihan;

    do {
        printf("\n=== Kelola Tugas ===\n");
        printf("1. Tambah Tugas\n");
        printf("2. Lihat Daftar Tugas\n");
        printf("3. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahTugas();
                break;
            case 2:
                tampilkanTugas();
                break;
            case 3:
                printf("\nKeluar dari menu kelola tugas.\n");
                break;
            default:
                printf("\nPilihan tidak valid!\n");
        }
    } while (pilihan != 3);

}
//-------------------------------------------------KALKULATOR  AKADEMIK-----------------------------------------------------------------------

void hitungIPK() {
    int jumlahMataKuliah;
    float totalNilai = 0, totalSKS = 0;

    printf("Total jumlah mata kuliah? ");
    scanf("%d", &jumlahMataKuliah);

    for (int i = 0; i < jumlahMataKuliah; i++) {
        float nilai;
        int sks;

        printf("Masukkan nilai mata kuliah ke-%d (dalam skala 4): ", i + 1);
        scanf("%f", &nilai);

        printf("Masukkan jumlah SKS mata kuliah ke-%d tersebut: ", i + 1);
        scanf("%d", &sks);

        totalNilai += nilai * sks;
        totalSKS += sks;
    }

    float ipk = totalNilai / totalSKS;
    printf("IPK yang diperoleh: %.2f\n", ipk);
}


void hitungUTSUAS() {
    float uts, uas;

    printf("Masukkan nilai UTS: ");
    scanf("%f", &uts);

    printf("Masukkan nilai UAS: ");
    scanf("%f", &uas);

    float nilaiAkhir = (uts * 0.4) + (uas * 0.6);
    printf("Nilai akhir yang diperoleh: %.2f\n", nilaiAkhir);
}

void cekRemedial() {
    float nilaiAkhir;

    printf("Masukkan nilai akhir Anda: ");
    scanf("%f", &nilaiAkhir);

    if (nilaiAkhir < 60) {
        printf("Anda memerlukan remedial.\n");
    } else {
        printf("Anda tidak memerlukan remedial.\n");
    }
}


void kalkulatorAkademik() {
    int pilihan;

    do {
        printf("\n===((( Kalkulator Akademik )))=== \n");
        printf("1. Hitung Statistik Akademik (IPK)\n");
        printf("2. Hitung rata-rata nilai UTS dan UAS\n");
        printf("3. Cek Kebutuhan Remedial pelajar\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                hitungIPK();
                break;
            case 2:
                hitungUTSUAS();
                break;
            case 3:
                cekRemedial();
                break;
            case 4:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 4);

}
//---------------------------------------------------------NOTESSSSSSSSSS-----------------------------------------
void notes() {
    printf("\n--Notes--\n");
    printf("Fitur ini akan memungkinkan Anda mencatat hal penting.\n");
}///--------------------------------------------------------------------------------------------KONTAK DOSENNNNNN-----------------------------
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
            printf("\nAkun berhasil didaftarkan!");
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

   