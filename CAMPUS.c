#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    char hari[100][20];
    char jam[100][20];
    char tanggal[100][20];
    char mataKuliah[100][50];
    char ruangan[100][20];
} Jadwal;
Jadwal jadwalList;
int jumlahJadwal = 0;

typedef struct Tugas {
    char namaTugas[50];
    char jenisTugas[30];
    char mataKuliah[50];
    char deadline[20];
    char penanggungJawab[50];
}Tugas;
Tugas tugasList[100];
int jumlahTugas = 0;

typedef struct {
    char isiNote[100][255];
    char tanggalNote[100][20];
} Note;
Note noteList;
int jumlahNote = 0;

//------------------------------------------------------------JADWAL-----------------------------------------------------------------------


void cekTanggal(char* hariIni) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(hariIni, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void notifikasi() {
    char hariIni[20];
    cekTanggal(hariIni);

    printf("\n=== Notifikasi Hari Ini (%s) ===\n", hariIni);
    int found = 0;
    for (int i = 0; i < jumlahJadwal; i++) {
        if (strcmp(jadwalList.tanggal[i], hariIni) == 0) {
            printf("  Mata Kuliah : %s\n", jadwalList.mataKuliah[i]);
            printf("  Jam         : %s\n", jadwalList.jam[i]);
            printf("  Ruangan     : %s\n\n", jadwalList.ruangan[i]);
            found = 1;
        }
    }
    for (int i = 0; i < jumlahTugas; i++) {
        if (strcmp(tugasList[i].deadline, hariIni) == 0) {
            printf("  Tugas            : %s\n", tugasList[i].namaTugas);
            printf("  Mata Kuliah      : %s\n", tugasList[i].mataKuliah);
            printf("  Jenis Tugas      : %s\n", tugasList[i].jenisTugas);
            printf("  Deadline         : %s\n", tugasList[i].deadline);
            printf("  Penanggung Jawab : %s\n\n", tugasList[i].penanggungJawab);
            found = 1;
        }
    }
    for (int i = 0; i < jumlahNote; i++)
    {
        if (strcmp(noteList.tanggalNote[i], hariIni) == 0){
            printf("  Note      : %s\n", noteList.isiNote[i]);
            printf("  Tanggal   : %s\n\n", noteList.tanggalNote[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Tidak ada jadwal untuk hari ini.\n");
    }
}

//------------------------------------------------------------JADWAL-----------------------------------------------------------------------


int bandingTanggal(const char *tanggal1, const char *tanggal2) {
    int hari1, bulan1, tahun1;
    int hari2, bulan2, tahun2;

    sscanf(tanggal1, "%d/%d/%d", &hari1, &bulan1, &tahun1);
    sscanf(tanggal2, "%d/%d/%d", &hari2, &bulan2, &tahun2);

    if (tahun1 != tahun2) return tahun1 - tahun2;
    if (bulan1 != bulan2) return bulan1 - bulan2;
    return hari1 - hari2;
}

void urutTanggal() {
    for (int i = 0; i < jumlahJadwal - 1; i++) {
        for (int j = i + 1; j < jumlahJadwal; j++) {
            if (bandingTanggal(jadwalList.tanggal[i], jadwalList.tanggal[j]) > 0) {
                char temp[50];
                
                strcpy(temp, jadwalList.hari[i]);
                strcpy(jadwalList.hari[i], jadwalList.hari[j]);
                strcpy(jadwalList.hari[j], temp);

                strcpy(temp, jadwalList.tanggal[i]);
                strcpy(jadwalList.tanggal[i], jadwalList.tanggal[j]);
                strcpy(jadwalList.tanggal[j], temp);

                strcpy(temp, jadwalList.jam[i]);
                strcpy(jadwalList.jam[i], jadwalList.jam[j]);
                strcpy(jadwalList.jam[j], temp);

                strcpy(temp, jadwalList.mataKuliah[i]);
                strcpy(jadwalList.mataKuliah[i], jadwalList.mataKuliah[j]);
                strcpy(jadwalList.mataKuliah[j], temp);

                strcpy(temp, jadwalList.ruangan[i]);
                strcpy(jadwalList.ruangan[i], jadwalList.ruangan[j]);
                strcpy(jadwalList.ruangan[j], temp);
            }
        }
    }
}

void tambahJadwal(){
    if(jumlahJadwal < 100){
        printf("\nTambah Jadwal \n");
        printf("Masukkan Hari                 : "); 
        scanf("%s", jadwalList.hari[jumlahJadwal]);
        printf("Masukkan Tanggal (DD/MM/YYYY) : ");
        scanf("%s", jadwalList.tanggal[jumlahJadwal]);
        printf("Masukkan Jam (HH:MM)          : ");
        scanf("%s", jadwalList.jam[jumlahJadwal]);
        printf("Masukkan Mata Kuliah          : ");
        scanf(" %[^\n]", jadwalList.mataKuliah[jumlahJadwal]);
        printf("Masukkan Ruangan              : ");
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
    char opsiUrut;
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
        printf("\nPilih metode pengurutan:\n");
        printf("1. Berdasarkan Index\n");
        printf("2. Berdasarkan Tanggal\n");
        printf("Pilih opsi: ");
        scanf("%d", &opsiUrut);
        if (opsiUrut == 2)
        {
            urutTanggal();
        }
        
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
        printf("Kembali? (y) :  ");
        scanf(" %c", &konfirmasi);
        if (konfirmasi == 'y')
        {
            printf("\nKembali ke menu sebelumnya\n");
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

void tambahTugas() {
    if (jumlahTugas >= 100) {
        printf("Daftar tugas penuh!\n");
        return;
    }

    printf("\nMasukkan informasi tugas baru:\n");
    printf("Nama Tugas      : ");
    scanf(" %[^\n]", tugasList[jumlahTugas].namaTugas);
    printf("Mata Kuliah     : ");
    scanf(" %[^\n]", tugasList[jumlahTugas].mataKuliah);
    printf("Jenis Tugas (kelompok/individu)    : ");
    scanf(" %[^\n]", tugasList[jumlahTugas].jenisTugas);
    printf("Deadline (DD/MM/YYYY): ");
    scanf(" %[^\n]", tugasList[jumlahTugas].deadline);  
    printf("Penanggung Jawab: ");
    scanf(" %[^\n]", tugasList[jumlahTugas].penanggungJawab);

    printf("Tugas berhasil ditambahkan!\n");
    jumlahTugas++;
}

void cariTugas() {
    char keyword[100];
    int found = 0;

    if (jumlahTugas == 0) {
        printf("\nTidak ada tugas yang tersedia untuk dicari.\n");
        return;
    }

    printf("\nMasukkan keyword untuk pencarian: ");
    scanf(" %[^\n]", keyword);

    printf("\n=== Hasil Pencarian ===\n");

    for (int i = 0; i < jumlahTugas; i++) {
        if (strstr(tugasList[i].namaTugas, keyword) != NULL || 
            strstr(tugasList[i].mataKuliah, keyword) != NULL || 
            strstr(tugasList[i].jenisTugas, keyword) != NULL || 
            strstr(tugasList[i].penanggungJawab, keyword) != NULL) {
            
            printf("Tugas %d:\n", i + 1);
            printf("  Nama Tugas      : %s\n", tugasList[i].namaTugas);
            printf("  Mata Kuliah     : %s\n", tugasList[i].mataKuliah);
            printf("  Jenis Tugas     : %s\n", tugasList[i].jenisTugas);
            printf("  Deadline        : %s\n", tugasList[i].deadline);
            printf("  Penanggung Jawab: %s\n\n", tugasList[i].penanggungJawab);
            found = 1;
        }
    }

    if (!found) {
        printf("Tidak ada tugas yang sesuai dengan keyword '%s'.\n", keyword);
    }
}

// menampilkan tugas
void tampilkanTugas() {
    int pilihan;
    int konfirmasi;
    printf("\n1. Lihat Semua Tugas\n");
    printf("2. Cari Tugas\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
        if (jumlahTugas == 0) {
            printf("\nTidak ada tugas yang tersedia.\n");
            return;
        }
        else {
            printf("\n=== Daftar Tugas ===\n");
            for (int i = 0; i < jumlahTugas; i++) {
                printf("Tugas %d:\n", i + 1);
                printf("  Nama Tugas      : %s\n", tugasList[i].namaTugas);
                printf("  Mata Kuliah     : %s\n", tugasList[i].mataKuliah);
                printf("  Jenis Tugas     : %s\n", tugasList[i].jenisTugas);
                printf("  Deadline        : %s\n", tugasList[i].deadline);
                printf("  Penanggung Jawab: %s\n\n", tugasList[i].penanggungJawab);
            }
        }
        printf("Kembali? (y) :  ");
        scanf(" %c", &konfirmasi);
        if (konfirmasi == 'y')
        {
            printf("\nKembali ke menu sebelumnya\n");
            return;
        }
    }
    else if (pilihan == 2) {
        cariTugas();
        printf("Kembali? (y) :  ");
        scanf(" %c", &konfirmasi);
        if (konfirmasi == 'y')
        {
            printf("\nKembali ke menu sebelumnya\n");
            return;
        }
    } else {
        printf("Pilihan tidak valid!\n");
    }
}


void editTugas() {
    int index;
    if (jumlahTugas == 0) {
        printf("\nTidak ada Tugas untuk diedit!\n");
        return;
    }
    printf("Masukkan nomor tugas yang ingin diedit (1 - %d): ", jumlahTugas);
    scanf("%d", &index);
    
    if (index < 1 || index > jumlahTugas) {
        printf("Tugas tidak ditemukan.\n");
        return;
    }
    index--; 

    printf("\nEdit Tugas Ke-%d:\n", index + 1);
    printf("Masukkan Nama Tugas baru                     : ");
    scanf(" %[^\n]", tugasList[index].namaTugas);
    printf("Masukkan Mata Kuliah baru                    : ");
    scanf(" %[^\n]", tugasList[index].mataKuliah);
    printf("Masukkan Jenis Tugas baru (kelompok/individu): ");
    scanf(" %[^\n]", tugasList[index].jenisTugas);
    printf("Masukkan Deadline baru (DD/MM/YYYY)          : ");
    scanf(" %[^\n]", tugasList[index].deadline);
    printf("Masukkan Penanggung Jawab baru               : ");
    scanf(" %[^\n]", tugasList[index].penanggungJawab);
    
    printf("Tugas berhasil diedit!\n");
}

void hapusTugas() {
    int index;
    if (jumlahTugas == 0) {
        printf("\nTidak ada Tugas untuk dihapus!\n");
        return;
    }
    printf("Masukkan nomor tugas yang ingin dihapus (1 - %d): ", jumlahTugas);
    scanf("%d", &index);

    if (index < 1 || index > jumlahTugas) {
        printf("Tugas tidak ditemukan.\n");
        return;
    }
    index--;

    for (int i = index; i < jumlahTugas - 1; i++) {
        strcpy(tugasList[i].namaTugas, tugasList[i + 1].namaTugas);
        strcpy(tugasList[i].mataKuliah, tugasList[i + 1].mataKuliah);
        strcpy(tugasList[i].jenisTugas, tugasList[i + 1].jenisTugas);
        strcpy(tugasList[i].deadline, tugasList[i + 1].deadline);
        strcpy(tugasList[i].penanggungJawab, tugasList[i + 1].penanggungJawab);
    }

    jumlahTugas--;
    printf("Tugas berhasil dihapus!\n");
}


void kelolaTugas() {
    int pilihan;

    do {
        printf("\n=== Kelola Tugas ===\n");
        printf("1. Tambah Tugas\n");
        printf("2. Lihat Daftar Tugas\n");
        printf("3. Edit Tugas\n");
        printf("4. Hapus Tugas\n");
        printf("4. Keluar\n");
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
                editTugas();
                break;
            case 4:
                hapusTugas();
                break;
            case 5:
                printf("\nKeluar dari menu kelola tugas.\n");
                return;
            default:
                printf("\nPilihan tidak valid!\n");
                break;
        }
    } while (pilihan != 5);

}
//-------------------------------------------------KALKULATOR  AKADEMIK-----------------------------------------------------------------------

float konversiPredikatKeNilai(char predikat[]) {
   
    if (strcmp(predikat, "A") == 0) return 4.0;
    if (strcmp(predikat, "A-") == 0) return 3.7;
    if (strcmp(predikat, "B+") == 0) return 3.3;
    if (strcmp(predikat, "B") == 0) return 3.0;
    if (strcmp(predikat, "B-") == 0) return 2.7;
    if (strcmp(predikat, "C+") == 0) return 2.3;
    if (strcmp(predikat, "C") == 0) return 2.0;
    if (strcmp(predikat, "C-") == 0) return 1.7;
    if (strcmp(predikat, "D") == 0) return 1.0;
    if (strcmp(predikat, "E") == 0) return 0.0;

    return -1; 
}

void hitungIPK() {
    int jumlahMataKuliah;
    float totalNilai = 0, totalSKS = 0;

    printf("Total jumlah mata kuliah? ");
    scanf("%d", &jumlahMataKuliah);

    for (int i = 0; i < jumlahMataKuliah; i++) {
        char predikat[3];
        int sks;

        printf("Masukkan predikat mata kuliah ke-%d (contoh: A, B+, C-): ", i + 1);
        scanf("%s", predikat);

        printf("Masukkan jumlah SKS mata kuliah ke-%d tersebut: ", i + 1);
        scanf("%d", &sks);

        float nilai = konversiPredikatKeNilai(predikat);
        if (nilai == -1) {
            printf("Predikat tidak valid. Ulangi input.\n");
            i--; 
            continue;
        }

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
                return;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 4);

}
//---------------------------------------------------------NOTESSSSSSSSSS-----------------------------------------


void tambahNote() {
    char tambahkanTanggal;

    if (jumlahNote >= 100) {
        printf("\nDaftar Note penuh!\n");
        return;
    }

    printf("\nMasukkan isi Note: ");
    scanf(" %[^\n]", noteList.isiNote[jumlahNote]);

    printf("Apakah Anda ingin menambahkan tanggal pada catatan ini? (y/n): ");
    scanf(" %c", &tambahkanTanggal);

    if (tambahkanTanggal == 'y' || tambahkanTanggal == 'Y') {
        printf("Masukkan tanggal (DD/MM/YYYY): ");
        scanf(" %[^\n]", noteList.tanggalNote[jumlahNote]);
    } else {
        strcpy(noteList.tanggalNote[jumlahNote], ""); 
    }
    printf("\nCatatan berhasil ditambahkan!\n");
    jumlahNote++;
}

void lihatNote() {
    int konfirmasi = 0;
    if (jumlahNote == 0) {
        printf("\nTidak ada note yang tersedia.\n");
        return;
    }

    printf("\n=== Daftar Catatan ===\n");
    for (int i = 0; i < jumlahNote; i++) {
        printf("Catatan %d:\n", i + 1);
        printf("  Isi       : %s\n", noteList.isiNote[i]);
        if (strlen(noteList.tanggalNote[i]) > 0) {
            printf("  Tanggal   : %s\n", noteList.tanggalNote[i]);
        } else {
            printf("  Tanggal   : Tidak ditambahkan\n");
        }
        printf("\n");
        printf("Kembali? (y) :  ");
        scanf(" %c", &konfirmasi);
        if (konfirmasi == 'y' || konfirmasi == 'Y') {   
        {
            printf("\nKembali\n");
            return;
        }
        }
        }
}


void editNote() {
    int index;
    char tambahkanTanggal;

    if (jumlahNote == 0) {
        printf("\nTidak ada catatan yang tersedia untuk diedit.\n");
        return;
    }

    printf("\nMasukkan nomor catatan yang ingin diedit (1-%d): ", jumlahNote);
    scanf("%d", &index);

    if (index < 1 || index > jumlahNote) {
        printf("\nNomor catatan tidak valid!\n");
        return;
    }

    index--; 
    printf("\nCatatan :\n");
    printf("  Isi       : %s\n", noteList.isiNote[index]);
    
    if (strlen(noteList.tanggalNote[index]) > 0) {
        printf("  Tanggal   : %s\n", noteList.tanggalNote[index]);
    } else {
        printf("  Tanggal   : Tidak ditambahkan\n");
    }

    printf("\nMasukkan isi catatan baru: ");
    scanf(" %[^\n]", noteList.isiNote[index]);

    printf("Apakah Anda ingin mengubah tanggal catatan ini? (y/n): ");
    scanf(" %c", &tambahkanTanggal);

    if (tambahkanTanggal == 'y' || tambahkanTanggal == 'Y') {
        printf("Masukkan tanggal baru (DD/MM/YYYY): ");
        scanf(" %[^\n]", noteList.tanggalNote[index]);
    }

    printf("\nCatatan berhasil diedit!\n");
}

void hapusNote() {
    int index;

    if (jumlahNote == 0) {
        printf("\nTidak ada catatan yang tersedia untuk dihapus.\n");
        return;
    }

    printf("\nMasukkan nomor catatan yang ingin dihapus (1-%d): ", jumlahNote);
    scanf("%d", &index);

    if (index < 1 || index > jumlahNote) {
        printf("\nNomor catatan tidak valid!\n");
        return;
    }

    index--; 
    for (int i = index; i < jumlahNote - 1; i++) {
        strcpy(noteList.isiNote[i], noteList.isiNote[i + 1]);
        strcpy(noteList.tanggalNote[i], noteList.tanggalNote[i + 1]);
    }

    jumlahNote--; 
    printf("\nCatatan berhasil dihapus!\n");
}

void notes() {
    int pilihan;

    do {
        printf("\n=== Kelola Catatan ===\n");
        printf("1. Tambah Catatan\n");
        printf("2. Lihat Catatan\n");
        printf("3. Edit Catatan\n");
        printf("4. Hapus Catatan\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahNote();
                break;
            case 2:
                lihatNote();
                break;
            case 3:
                editNote();
                break;
            case 4:
                hapusNote();
                break;
            case 5:
                printf("\nKeluar dari menu kelola catatan.\n");
                break;
            default:
                printf("\nPilihan tidak valid!\n");
                break;
        }
    } while (pilihan != 5);
}


//----------------------------------------------------------------------------------------KONTAK DOSENNNNNN-----------------------------
void materiKontakDosen() {
    int pilihan, pilihan1, pilihan2, konfirmasi;
    do{
        printf("\n ===MATERI DAN KONTAK DOSEN===");
        printf("\n1. Materi Pembelajaran\n2. Kontak Dosen\n3. Kembali Ke menu utama\n");
        printf("Masukan Pilihan : ");
        scanf("%d", &pilihan);
        
        if (pilihan == 1){
            do{
                printf("\n    ===MATERI PEMBELAJARAN===    \n1. Algoritma Dan Pemrograman Dasar\n2. Elektronika\n3. Pendidikan Agama Islam\n4. Rangkaian Listrik\n5. Matematika Teknik\n6. Pendidikan pancasila\n7. Pendidikan Agama kristen\n8. File PDF Materi Pembelajaran\n9. Kembali Ke menu sebelumnya\n");
                printf("Masukan angka pilihan : ");
                scanf("%d", &pilihan1);
                if (pilihan1 == 1) {
                    printf("youtube :\n1. Web Programing UNPAS\n2. Kelas Terbuka\n3. Free Code Camp\n4. CS Dojo\n5. Thenewboston\nWeb :\n1. https://www.CodeCademy.com \n2. https://www.Coursera.com \n3. https://www.CodeWars.com \n4. https://www.Udemy.com \n5. https://www.Github.com");
                }else if (pilihan1 == 2){
                    printf("youtube :\n1. MAKE\n2. EEVBLOG\n3. GREATSCOTT\n4. ADAFRUIT\n5. MJLORTON\nWeb :\n1. https://www.Allaboutcircuit.com \n2. https://www.Electronicstheory.com \n3. https://www.Learn.sparkfun.com \n4. https://www.Electronics-lab.com \n5. https://Instructable.com");
                }else if (pilihan1 == 3){
                    printf("Youtube :\n1. Ustadz Abdul Somad\n2. Yufid TV\n3. Kisah Islam\n4. Al-Bahjah TV\n5. Khalid Basalamah Official\nWeb :\n1. https://pesantrenalirsyad.org/category/artikel-islam/ \n2. https://www.kompasiana.com/tag/muslimah \n3. https://yufid.com/en/ \n4. https://konsultasisyariah.com/ \n5. https://yufid.tv/");
                }else if (pilihan1 == 4){
                    printf("Youtube :\n1. Class Time Off < udah paling best pokoknya ><\nWeb :\n1. https://www.kmtech.id/ \n2. https://Udemy.com \n3. https://PhEt.com \n4. https://Superprof.co.id \n5. https://indobot.co.id/");
                }else if (pilihan1 == 5){
                    printf("Youtube :\n1. kuliahMatematika\nWeb :\n1. https://tutorial.math.lamar.edu/ \n2. https://www.ArtofProblemSolving.com \n3. https://www.MathPickle.com \n4. https://www.HoodaMath.com \n5. https://www.Arcademics.com");
                }else if (pilihan1 == 6){
                    printf("Youtube :\n1. Pendidikan Pancasila\n2. Pendidikan dan Kewarganegaraan\n3. Channel Pancasila\n4. Civics Learning\n5. Pendidikan Moral Pancasila\nWeb :\n1. https://www.kemdikbud.go.id \n2. https://www.pancasila.id \n3. https://www.peraturan.go.id \n4. https://www.dikti.kemdikbud.go.id \n5. https://www.pusatpancasila.or.id");
                }else if (pilihan1 == 7){
                    printf("Youtube :\n1. KanalKristen \n2. JaringanGereja \n3. Iman Kristen\n4. The Bible Project\n5. Kristen Indonesia\nWeb :\n1. https://www.gkkdbp.org \n2. https://biblegateway.com \n3. https://www.alkitab.or.id \n4. https://www.christianity.com \n5. https://www.desiringgod.org");
                }else if (pilihan1 == 8){
                    printf("Untuk link google drive : https://drive.google.com/drive/folders/1FQVfD1k7Dz3ffNVdErME26DzbBcAlvAe");
                }else if (pilihan1 == 9)
                {
                    printf("kembali ke menu sebelumnya");
                    break;
                }else {
                    printf("pilihan tidak valid ><\n");
                    continue;
                }               
                printf("\nKembali ke menu KONTAK DOSEN ? (y): ");
                scanf(" %c", &konfirmasi);

            } while (konfirmasi == 'y' || konfirmasi == 'Y'); 

        }else if(pilihan == 2){ 
            do {
                printf("\n\n    ===KONTAK DOSEN MATAKULIAH===    \n");
                printf("1. Liptia Venica, S.T. M.T.\n");
                printf("2. Muhammad Rizalul Wahid, S.Si., M.T.\n");
                printf("3. Prof. Dr. Yayan Nurbayan, M.Ag.\n");
                printf("4. Diky Zakaria, S.Pd. M.T.\n");
                printf("5. Dr. Suprih Widodo, S.Si., M.T.\n");
                printf("6. Jennyta Catursari, M.Pd.\n");
                printf("7. Jojor Renta Maranatha, S.Pd., M.Pd.\n");
                printf("8. Kembali ke menu sebelumnya\n");
                printf("Masukan pilihan: ");
                scanf("%d", &pilihan);

                if (pilihan2 == 1) {
                    printf("\nNomor Whatsapp: 085222333300\n");
                } else if (pilihan2 == 2) {
                    printf("\nNomor Whatsapp: 082269333396\n");
                } else if (pilihan2 == 3) {
                    printf("\nNomor Whatsapp: 081394147474\n");
                } else if (pilihan2 == 4) {
                    printf("\nNomor Whatsapp: 081321439833\n");
                } else if (pilihan2 == 5) {
                    printf("\nNomor Whatsapp: 085624848424\n");
                } else if (pilihan2 == 6) {
                    printf("\nNomor Whatsapp: 081313093905\n");
                } else if (pilihan2 == 7) {
                    printf("\nNomor Whatsapp: 085292560667\n");
                } else if (pilihan2 == 8) {
                    printf("\nKembali ke menu sebelumnya.\n");
                    break; 
                } else {
                    printf("\nPilihan tidak valid! Silakan coba lagi.\n");
                    continue; 
                }
                printf("\nKembali ke menu KONTAK DOSEN ? (y): ");
                scanf(" %c", &konfirmasi);

            } while (konfirmasi == 'y' || konfirmasi == 'Y');

        } else if (pilihan == 3)
        {
            printf("Kembali ke menu utama");
            return;
        }
        else{
            printf("\nPilihan Tidak Valid ><");
        }
    
    }while (pilihan != 01235);
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
            printf("Masukkan Password  : ");
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
                    notifikasi();
                    printf("\n--Pilih Fitur--\n \n");
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

   