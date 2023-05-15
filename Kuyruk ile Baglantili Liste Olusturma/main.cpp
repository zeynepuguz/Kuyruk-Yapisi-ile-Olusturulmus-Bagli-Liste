#include <iostream>
using namespace std;

class Node { // Node sınıfı, elemanların veri ve bir sonraki elemanın adres bilgisini tutan düğümleri temsil eder.
public:
    int veri; // Düğümdeki veri
    Node* yeni; // Bir sonraki düğümün adresi
};

class LinkedList { // Bağlantılı liste sınıfı
public:
    Node* bas;  // Listenin başlangıç düğümü

    LinkedList() {
        bas = NULL;  // Başlangıçta liste boş
    }

    // Eleman ekleme fonksiyonu
    void ekle(int deger) {
        Node* newNode = new Node;   // Yeni bir düğüm oluşturuluyor.
        newNode->veri = deger;
        newNode->yeni = NULL;

        if (bas == NULL) { // Eğer liste boşsa yeni düğüm başlangıç düğümü olur.
            bas = newNode;
        } else {  // Eğer liste doluysa son düğüme gidilip yeni düğüm eklenir.
            Node* gecerli = bas;
            while (gecerli->yeni != NULL) {
                gecerli = gecerli -> yeni;
            }
            gecerli->yeni = newNode;
        }
    }

    // Eleman silme fonksiyonu
    void remove() {
        if (bas != NULL) {   // Eğer liste boş değilse başlangıç düğümü silinir.
            int silinecekdeger = bas->veri;
            bas = bas->yeni;
            }
    }

    // Elemanları görüntüleme fonksiyonu
    void goruntule() {
        if (bas != NULL) {  // Eğer liste boş değilse tüm elemanlar görüntülenir.
            Node* gecerli = bas;
            cout << "Listedeki elemanlar:" << endl;
            while (gecerli != NULL) {
                cout << gecerli->veri << endl;
                gecerli = gecerli->yeni;
            }
        }
    }
};

int main() {
    LinkedList list; // Yeni bir bağlantılı liste oluşturuluyor.
    int secim,deger;

    do {
        cout << "Lutfen asagidaki islemlerden birini seciniz:" << endl;
        cout << "1.Ekleme\n2.Silme\n3.Goruntuleme\n4.Cikis" << endl;
        cout << "Seciminiz=";
        cin >> secim;

         // Burada kullanıcıdan seçim yapması istenir.
        switch (secim) {
            case 1:
                cout << "Eklemek istediginiz degeri giriniz : ";
                cin >> deger; // Kullanıcı eklenecek değeri girer.
                list.ekle(deger); // Ekleme işlemini gerçekleştirmek için ekle fonksiyonu çağrılır.
                break;
            case 2:
                list.remove(); // Silme işlemi gerçekleştirilir.
                break;
            case 3:
                list.goruntule(); // Liste görüntülenir.
                break;
            case 4: // Programı sonlandırmak için kullanıcı bu seçeneği seçmelidir.
                cout << "Programdan cikiliyor." << endl;
                break;
            default: // Kullanıcı seçenekler dışında bir değer seçerse default olur ve tekrar denememiz için program seçenekleri tekrar sıralar.
                cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
        }
    } while (secim != 4); // Kullanıcı çıkış seçeneğini seçmediği sürece döngü devam eder.

    return 0;
}
