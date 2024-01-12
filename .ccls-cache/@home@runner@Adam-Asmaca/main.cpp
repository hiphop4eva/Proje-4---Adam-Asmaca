#include <iostream>
#include<string>
#include<stdlib.h>


using namespace std;

bool sonlandır = 0;
string kelimeListe[8] = {"cicek", "hayal", "muz", "kabuk", "fantastik", "sirilsiklam", "keloglan", "bogaz"};
int hataSayısı = 0;
int doğruSayısı = 0;
bool tekrar = 1;

void yazdır(string*);
void sor(string, string*);


int main() {

  while(tekrar == 1){
    srand(time(0));

    string kelime = kelimeListe[rand() % 7];
    string kelimeHUD(kelime.size(), '_');
    string* pkelimeHUD = &kelimeHUD;

    //cout << endl << endl << kelime << endl;

    while (sonlandır == 0){
      yazdır(pkelimeHUD);
      sor(kelime, pkelimeHUD);
    }

    cout << endl << R"(______________________________________)" << "\nOyun sonlanmıştır\n";
    
    cout << "\nTekrar oynamak istiyorsanız 1 girin. İstemiyorsanız herhangi başka bir karakter girin.\n";
    cin >> tekrar;
    if (tekrar == 1) {
      sonlandır=0; hataSayısı=0; doğruSayısı=0;
      cout << "\nOyun tekrar başlatılmıştır\n";
    }
  }
  return 0;
}


void yazdır(string* pkelimeHUD) {
  cout << R"(______________________________________)" << "\n\n\n";
  for (int i = 0; i <= hataSayısı; i++){
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
        sonlandır = 1;
        break;
      default:
      break;
    }
  }  
  cout << endl << endl << *pkelimeHUD;
}
  
void sor(string kelime, string* pkelimeHUD){
  if (sonlandır == 1){return;}
  char harf;
  cout << "\n\n\nBir harf giriniz. \n";
  cin >> harf;
  bool hata = 1;
  for (int i = 0; i <= kelime.length(); i++){

    if (harf == kelime[i]){
      //cout << "\nKelimenin " << i + 1 << " numaralı harfi " <<"\""<< harf <<"\""<< " harfine uyuyor.\n";
      (*pkelimeHUD)[i] = harf;
      hata = 0;
      doğruSayısı++;
        if(doğruSayısı == kelime.length()){
        sonlandır = 1;
        cout << "Kelime " <<"\""<< kelime <<"\""<< " olarak bulunmuştur.\n\n";
        break;
      }
      continue;
    }

    if (hata == 1 && i == kelime.length()){
      hataSayısı++;
      cout << "Bu kelimenin içinde seçilen harf yoktur. " << 5 - hataSayısı  << " canınız kaldı.\n";
    }
  }  
}