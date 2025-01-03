#include <stdio.h>
#include <string.h>

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

int main() {
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

    return 0;
}
