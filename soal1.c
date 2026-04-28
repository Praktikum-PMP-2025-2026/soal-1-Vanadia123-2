/*
Nama : Vanadia Vlainti
NIM : 13224011
Deskripsi Soal :
Sebuah kubah pengaman dijaga oleh petugas dalam tiga shift berbeda: pagi, siang, dan malam. Setiap 
penjaga memiliki identitas dan skor respons yang menunjukkan performanya saat bertugas. Kepala 
keamanan ingin mengetahui siapa penjaga terbaik pada tiap shift agar jadwal evaluasi dapat segera 
disusun. Jika suatu shift tidak memiliki penjaga terdaftar, sistem tetap harus menandai kondisi itu 
dengan jelas. 
Tampilkan penjaga terbaik untuk tiap shift. 

Kondisi/Aturan :
1. Shift hanya PAGI, SIANG, atau MALAM 
2. Ranking dalam tiap shift: 
• skor lebih tinggi lebih baik 
• jika sama, ID lebih kecil lebih baik 
• jika sama, nama alfabetis lebih kecil lebih baik 
3. Jika suatu shift tidak memiliki penjaga, cetak -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Penjaga {
    char *nama;
    int id;
    char shift[10];
    int skor;
} Penjaga;

char *salinNama(char *namaAsli) {
    char *hasil = (char *) malloc((strlen(namaAsli) + 1) * sizeof(char));

    if (hasil==NULL) {
        exit(1);
    }

    strcpy(hasil, namaAsli);
    return hasil;
}

int lebihBaik(Penjaga a, Penjaga b) {
    if (a.skor>b.skor) {
        return 1;
    }

    if (a.skor<b.skor) {
        return 0;
    }

    if (a.id<b.id) {
        return 1;
    }

    if (a.id>b.id) {
        return 0;
    }

    if (strcmp(a.nama, b.nama)<0) {
        return 1;
    }

    return 0;
}

void printPenjaga(char *namaShift, Penjaga *data, int index) {
    if (index== -1) {
        printf("%s -\n", namaShift);
    } else {
        printf("%s %s %d %d\n", namaShift, data[index].nama, data[index].id, data[index].skor);
    }
}

int main() {
    int N;
    Penjaga *data;

    int terbaikPagi = -1;
    int terbaikSiang = -1;
    int terbaikMalam = -1;

    scanf("%d%*c", &N); 

    data = (Penjaga *) malloc(N * sizeof(Penjaga));

    if (data == NULL) {
        return 1;
    }

    for (int i=0; i< N; i++) {
        char namaSementara[100];

        scanf("%s %d %s %d", namaSementara, &data[i].id, data[i].shift, &data[i].skor);

        data[i].nama = salinNama(namaSementara);

        if (strcmp(data[i].shift, "PAGI") == 0) {
            if (terbaikPagi == -1 || lebihBaik(data[i], data[terbaikPagi])) {
                terbaikPagi = i;
            }
        } else if (strcmp(data[i].shift, "SIANG") == 0) {
            if (terbaikSiang == -1 || lebihBaik(data[i], data[terbaikSiang])) {
                terbaikSiang = i;
            }
        } else if (strcmp(data[i].shift, "MALAM") == 0) {
            if (terbaikMalam == -1 || lebihBaik(data[i], data[terbaikMalam])) {
                terbaikMalam = i;
            }
        }
    }

    printPenjaga("PAGI", data, terbaikPagi);
    printPenjaga("SIANG", data, terbaikSiang);
    printPenjaga("MALAM", data, terbaikMalam);

    for (int i=0; i<N; i++) {
        free(data[i].nama);
    }

    free(data);

    return 0;
}
