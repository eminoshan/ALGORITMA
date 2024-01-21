#include <iostream>

// Araba sýnýfý
struct Araba {
    int plakaNo;
    int saat;
    int dakika;
};

// Otopark sýnýfý
struct Otopark {
    const int kapasite;
    Araba* arabalar;
    int doluParkSayisi;

    Otopark(int kapasite) : kapasite(kapasite), doluParkSayisi(0) {
        arabalar = new Araba[kapasite];
    }

    ~Otopark() {
        delete[] arabalar;
    }

    bool aracEkle(int plaka, int saat, int dakika) {
        if (doluParkSayisi < kapasite) {
            Araba yeniAraba = {plaka, saat, dakika};
            arabalar[doluParkSayisi++] = yeniAraba;
            std::cout << "Arabaniz otoparka eklendi. Plaka: " << plaka << std::endl;
            return true;
        } else {
            std::cout << "Otopark suan dolu. Araba malesef eklenemedi." << std::endl;
            return false;
        }
    }

    void otoparktakiAraclariListele() {
        std::cout << "Otoparktaki mevcut Araçlar:" << std::endl;
        for (int i = 0; i < doluParkSayisi; ++i) {
            std::cout << "Plakaniz: " << arabalar[i].plakaNo << ", Saat: " << arabalar[i].saat
                      << ", Dakika: " << arabalar[i].dakika << std::endl;
        }
    }
};

int main() {
    // Örnek kullaným
    Otopark otopark(5);

    otopark.aracEkle(243, 15, 30);
    otopark.aracEkle(456, 10, 45);
    otopark.aracEkle(325, 11, 18);

    otopark.otoparktakiAraclariListele();

    return 0;
}
