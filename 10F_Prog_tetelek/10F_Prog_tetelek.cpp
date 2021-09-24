#include <iostream>
#include <vector>
#include <map> // rendezett szótár

using namespace std;

int main()
{
    vector<int> lista{1,6,3,9,4,5,8,6,7,9,1,2,7,3,5,9,6,7,8,1,2,5,1,2,5,1,2,4};

    // "helye"-feladat
    // Találjuk meg a legelsõ 7-es helyét (ha nincs 7-es, lista utolsó utáni indexét adja vissza!)

    // minden ciklus elõtti 1. számú kérdés: while vagy for? elõbb be lehet-e fejezni vagy sem?
    cout << "a lista merete: " << lista.size() << endl;
    int i;
    i = 0;
    while (i<lista.size() && lista[i]!=-1) // ez nem megfordítható
    {
        i++;
    }
    cout << i;

    // Eldöntés tétele 
    // van-e 7-es a listában?
    i = 0;
    while (i < lista.size() && lista[i] != 7) // ez nem megfordítható
    {
        i++;
    }
    cout << (i < lista.size());

    // Keresés, ha tuti van
    // Hol van a 7-es, ha tuti, hogy van 7-es?
    i = 0;
    while (lista[i] != 7) // ez nem megfordítható
    {
        i++;
    }
    cout << i;

    // Keresés, ha nem biztos, hogy van
    // Hol van az elsõ 7-es, ha nem biztos, hogy van hetes, és ha nincs, akkor legyen -1?
    i = 0;
    while (i < lista.size() && lista[i] != 7) // ez nem megfordítható
    {
        i++;
    }
    cout << (i==lista.size()?-1:i);

    // Hol van az utolsó 7-es, ha nem biztos, hogy van hetes, és ha nincs, akkor legyen -1?
    //    ugyanaz, mint a helye, csak másik irányból megy a ciklus!
    i = lista.size()-1;
    while (0 <= i && lista[i] != 7) // ez nem megfordítható
    {
        i--;
    }
    cout << i;

    // maximumkeresés (érték)
    // sosem 0-tól indul!

    int max_ertek = lista[0];
    for (size_t i = 1; i < lista.size(); i++)
    {
        if (max_ertek < lista[i])
        {
            max_ertek = lista[i];
        }
    }

    cout << max_ertek;
    
    // maximumhely-keresés
    // ez sem 0-tól indul!

    max_ertek = lista[0];
    int max_hely = 0;
    for (size_t i = 1; i < lista.size(); i++)
    {
        if (max_ertek < lista[i])
        {
            max_ertek = lista[i];
            max_hely = i;
        }
    }

    cout << max_ertek;

    // Összegzés (szorzás, összeadás stb.)

    int sum = 0;

    for (int& elem : lista)
    {
        sum += elem;
    }

    cout << sum;

    // megszámlálás: hány 7-es van?

    int db = 0;
    for (auto& elem : lista)
    {
        if (elem == 7)
        {
            db++;
        }
    }
    cout << db;

    // Válogassuk ki a páros számokat!

    vector<int> parosak;

    for (int& elem : lista)
    {
        if (elem%2==0)
        {
            parosak.push_back(elem);
        }
    }

    for (auto& elem : parosak) { cout << elem << " "; }

    // legyen az eredmény az a lista, amely a számok négyzeteit tartalmazza!

    vector<int> negyzetek;

    for (int& elem : lista)
    {
        negyzetek.push_back(elem * elem);
    }

    vector<int> negyzetek2(lista.size());
    for (size_t i = 0; i < lista.size(); i++)
    {
        negyzetek2[i] = lista[i] * lista[i];
    }


    // Group by feladat:

    string szoveg = "asldfkjhasldfkjhasldfkjhasldfkjd";

    cout << endl;
    map<char, int> statisztika;
    for (char& k : szoveg)
    {
       statisztika[k]++;
    }

    for (auto& par : statisztika)
    {
        cout << par.first << " : " << par.second << endl;
    }

}

