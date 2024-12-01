#include <stdio.h>
#include <stdlib.h>

void banner()
{
    printf("==================================\n");
    printf("============ BANK KRUT ===========\n");
    printf("==================================\n\n");
}

int main()
{
    int saldo = 1000000, pin, rekening, keluar, transfer, rekeningTuju, setor, nominal, pilih;
    int continueTransaction = 1;

    system("cls");
    banner();
    printf("Masukkan No. Rekening: ");
    scanf("%d", &rekening);
    printf("\n");

pin: // Loop untuk PIN
    printf("Masukkan Pin: ");
    scanf("%d", &pin);

    if (pin != 8888) {
        system("cls");
        banner();
        printf("Pin Salah\n\n");
        goto pin; // Kembali ke input PIN jika salah
    }

    while (continueTransaction) { // Perulangan menu utama
        system("cls");
        banner();
        printf("Menu,\n");
        printf("  1. Cek Saldo\n");
        printf("  2. Tarik Uang\n");
        printf("  3. Setor Uang\n");
        printf("  4. Kembali\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih) {
        case 1: // Cek Saldo
            system("cls");
            banner();
            printf("Saldo Anda saat ini: %d\n\n", saldo);
            break;

        case 2: // Tarik Uang
            system("cls");
            banner();
            printf("Pilih nominal yang ingin Anda ambil,\n");
            printf("  1. 50000\n");
            printf("  2. 100000\n");
            printf("  3. 250000\n");
            printf("  4. Nominal Lain\n");
            printf("Pilih: ");
            scanf("%d", &nominal);

            if (nominal == 1)
                keluar = 50000;
            else if (nominal == 2)
                keluar = 100000;
            else if (nominal == 3)
                keluar = 250000;
            else if (nominal == 4) {
                system("cls");
                banner();
                printf("Masukkan nominal yang ingin Anda ambil (kelipatan 50000):\n");
                scanf("%d", &keluar);
                if (keluar % 50000 != 0) {
                    system("cls");
                    banner();
                    printf("Nominal yang Anda masukkan bukan kelipatan 50000\n\n");
                    continue; // Kembali ke menu tarik tunai
                }
            } else {
                system("cls");
                banner();
                printf("Pilihan Salah. Silahkan Pilih Kembali.\n\n");
                continue; // Kembali ke menu tarik tunai
            }

            if (keluar > saldo) {
                system("cls");
                banner();
                printf("Transaksi Gagal. Saldo Anda tidak mencukupi.\n\n");
            } else {
                saldo -= keluar;
                system("cls");
                banner();
                printf("Transaksi Berhasil!\nSisa saldo Anda: %d\n\n", saldo);
            }
            break;

        case 3: // Setor Uang
            system("cls");
            banner();
            printf("Uang yang Anda masukkan harus rapi, dan merupakan kelipatan 50000.\n\n");
        inputSetor:
            printf("Masukkan nominal yang ingin Anda setor: ");
            scanf("%d", &setor);

            if (setor % 50000 != 0) {
                system("cls");
                banner();
                printf("Nominal yang Anda masukkan bukan kelipatan 50000\n\n");
                goto inputSetor; // Kembali ke input setor jika salah
            }

            saldo += setor;
            system("cls");
            banner();
            printf("Transaksi Berhasil! Saldo Anda saat ini: %d\n\n", saldo);
            break;

        case 4: // Kembali (Keluar dari program)
            system("cls");
            banner();
            printf("Terima kasih telah bertransaksi di Bank Krut.\n\n");
            return 0; // Keluar dari program

        default:
            system("cls");
            banner();
            printf("Pilihan Menu Salah. Silakan Pilih Kembali.\n\n");
            continue; // Kembali ke menu utama
        }

        // Konfirmasi transaksi lain
        printf("Apakah Anda ingin melakukan transaksi lain?\n");
        printf("  1. Ya\n");
        printf("  2. Tidak\n");
        printf("Pilih: ");
        scanf("%d", &pilih);
        if (pilih == 1) {
            continueTransaction = 1;
        } else if (pilih == 2) {
            continueTransaction = 0;
        } else {
            system("cls");
            banner();
            printf("Pilihan Salah. Silakan Pilih Kembali.\n\n");
        }
        end:
            system("cls");
            banner();
            printf("Terimakasih Telah Bertransaksi\n\tDi Bank Krut\n\n");
    }

    return 0;
}
