#include <iostream>
#include <ctime>
using namespace std;


void randomize() {
    srand(time(nullptr));
    rand();
}

double rnd() {
    return 1.0 * rand() / RAND_MAX;
}

int rnd(int min, int max) {
    return rnd() * (max - min + 1) + min;
}

void wypisz(int &money, int &spentMoney){
    int a, b, c;
    cout << "wypisz 3 liczby od 1 do 10" << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    cout << "oto twoje liczby: " << a << " " << b << " " << c << endl;

    int  tab[3];
    cout << "oto wylosowane liczby: " << endl;

    for (int i = 0; i < 3; ++i) {
        tab[i] = rnd(1, 3);
        cout << tab[i] << endl;
    }


//    for (int i = 0; i < 3; ++i) {
        if(a == tab[0]){
            cout << "trafiles 1 liczbe!" << endl;
            spentMoney += 10;
        }
        if(b == tab[1]){
            cout << "trafiles 2 liczbe!" << endl;
            spentMoney += 10;
        }
        if(c == tab[2]){
            cout << "trafiles 3 liczbe!" << endl;
            spentMoney += 10;
        }
        else{
            spentMoney -= 10;
        }
//    }
    cout << "TWOJA ILOSC PIENIEDZY W TEJ KOLEJCE: " << spentMoney << endl;


}

void postaw(int &money, int &spentMoney){
    cout << "masz " << money << " $, ile stawiasz ?" << endl;
    cin >> spentMoney;
    if(spentMoney > money){
        cout << "!!!!!" << endl;
    }
    cout << "tyle piniendzy postawiles: " << spentMoney << endl;
    money -= spentMoney;
    cout << "tyle piniendzy ci zostalo: " << money << endl;
}




int main() {
    randomize();

    int money = 500;
    int spentMoney;
do {
    postaw(money, spentMoney);
    wypisz(money, spentMoney);
    cout << "czy chcesz kontynuowac (t/n)? " << endl;
    char continuation;
    cin >> continuation;
    if(continuation == 'n'){
        cout << "TWOJA ILOSC PIENIEDZY W TEJ GRZE: " << spentMoney << endl;
        break;
    }
    money += spentMoney;
}while(true);
}
