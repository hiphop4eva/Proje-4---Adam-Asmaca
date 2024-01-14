#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<fstream>

using namespace std;

string dosyaListesi[28] = {"A.txt", "B.txt", "C.txt", "Ç.txt", "D.txt", "E.txt", "F.txt", "G.txt", "H.txt", "I.txt", "İ.txt", "J.txt", "K.txt", "L.txt", "M.txt", "N.txt", "O.txt", "Ö.txt", "P.txt", "R.txt", "S.txt", "Ş.txt", "T.txt", "U.txt", "Ü.txt", "V.txt", "Y.txt", "Z.txt"};
int kelimeMinUzunluk = 5;
bool sonlandir = 0;
int hataSayisi = 0;
int dogruSayisi = 0;
bool tekrar = 1;

string kelimeAl();
string HUDayarla(string);
void yazdir(string*);
void sor(string, string*);

int main() {

  while(tekrar == 1){
    
    cout << "Adam asmaca oyununa hoşgeldiniz. Bu oyunda kaç harften oluştuğu verilen bir kelimenin ne olduğunu 5 deneyiş içersinde tahmin etmeniz lazım." << "\n\n" << "Bu oyunda sadece ingilizce alfabesi kullanıldığına dikkat edin lütfen. Dolayısıyla hem sorulan sözcükte hem de sizin girdiğiniz harfte aşağıda gösterildiği gibi Türkçe harfler İngilizce eşleriyle değiştirilmiştir.\n ç = c\n ğ = g\n ı = i\n ö = o\n ş = s\n ü = u" << "\n\n" << "Devam etmek için herhangi bir karakter girin." << endl;
    cin.get();
    
    srand(time(0));

    string kelime = kelimeAl();
    string kelimeHUD = HUDayarla(kelime);
    string* pkelimeHUD = &kelimeHUD;

    //cout << endl << kelime << endl;

    while (sonlandir == 0){
      yazdir(pkelimeHUD);
      sor(kelime, pkelimeHUD);
    }

    cout << endl << R"(______________________________________)" << "\nOyun sonlanmıştır. Doğru kelime \n" << kelime << " idi.\n";

    cout << "\nTekrar oynamak istiyorsanız 1 girin. İstemiyorsanız herhangi başka bir karakter girin.\n";
    cin >> tekrar;
    if (tekrar == 1) {
      sonlandir=0; hataSayisi=0; dogruSayisi=0;
      cout << "\nOyun tekrar başlatılmıştır\n";
    }
  }
  return 0;
}

string kelimeAl(){
  srand(time(0));

  string dosya = "Kelime Veritabanı/" + dosyaListesi[rand() % 27];

  //cout << dosya << endl;

  ifstream dosyaOku;
  dosyaOku.open(dosya);

  vector<string> sahteDosya;
  string line;

  while(getline(dosyaOku, line)){
    sahteDosya.push_back(line);
  }

  dosyaOku.close();

  srand(time(0));
  string kelime = sahteDosya[rand() % (sahteDosya.size() - 1)];
  while(kelime.size() < kelimeMinUzunluk){
    srand(time(0));
    kelime = rand() % (sahteDosya.size() - 1);
  }
  return sahteDosya[rand() % (sahteDosya.size() - 1)];
}

string HUDayarla(string kelime){
  string kelimeHUD(kelime.size(), '_');
  for (int i = 0; i < kelime.size(); i++){
    if (kelime[i] == ' '){kelimeHUD[i] = ' '; dogruSayisi++;}
  }
  return kelimeHUD;
}

void yazdir(string* pkelimeHUD) {
  cout << R"(______________________________________)" << "\n\n" << "Kelimeniz " << pkelimeHUD->size() << " harften oluşuyor.\n";
  for (int i = 0; i <= hataSayisi; i++){
    switch (i) {
      case 1:
        cout << R"(_______)" << endl << R"( |)" << endl << R"( |     O)" << endl;
        break;
      case 2:
        cout << R"( |    /|\)" << endl;
        break;
      case 3:
        cout << R"( |   / | \)" << endl;
        break;
      case 4:
        cout << R"( |    / \)" << endl;
        break;
      case 5:
        cout << R"( |   /   \)" << endl << R"( |)" << endl << R"( -----------)" << "\n\n\n";
        sonlandir = 1;
        break;
      default:
        break;
    }
  }
  cout << "\n\n" << *pkelimeHUD << "\n\n" << 5 - hataSayisi << " canınız var.";
}

void sor(string kelime, string* pkelimeHUD){
  if (sonlandir == 1){return;}
  char harf;
  cout << "\n\n\nBir harf giriniz. \n";
  cin >> harf;
  bool hata = 1;
  for (int i = 0; i <= kelime.length(); i++){

    if (harf == kelime[i]){
      (*pkelimeHUD)[i] = harf;
      hata = 0;
      dogruSayisi++;
        if(dogruSayisi == kelime.length()){
        sonlandir = 1;
        cout << "Kelime " <<"\""<< kelime <<"\""<< " olarak bulunmuştur.\n\n";
        break;
      }
      continue;
    }

    if (hata == 1 && i == kelime.length()){
      hataSayisi++;
      cout << "Bu kelimenin içinde seçilen harf yoktur.\n";
    }
  }
}
