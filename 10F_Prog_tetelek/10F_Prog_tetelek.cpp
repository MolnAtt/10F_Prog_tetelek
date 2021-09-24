#include <iostream>
#include <vector>
#include <map> // rendezett sz�t�r

using namespace std;

int main()
{
    vector<int> lista{1,6,3,9,4,5,8,6,7,9,1,2,7,3,5,9,6,7,8,1,2,5,1,2,5,1,2,4};

    // "helye"-feladat
    // Tal�ljuk meg a legels� 7-es hely�t (ha nincs 7-es, lista utols� ut�ni index�t adja vissza!)

    // minden ciklus el�tti 1. sz�m� k�rd�s: while vagy for? el�bb be lehet-e fejezni vagy sem?
    cout << "a lista merete: " << lista.size() << endl;
    int i;
    i = 0;
    while (i<lista.size() && lista[i]!=-1) // ez nem megford�that�
    {
        i++;
    }
    cout << i;

    // Eld�nt�s t�tele 
    // van-e 7-es a list�ban?
    i = 0;
    while (i < lista.size() && lista[i] != 7) // ez nem megford�that�
    {
        i++;
    }
    cout << (i < lista.size());

    // Keres�s, ha tuti van
    // Hol van a 7-es, ha tuti, hogy van 7-es?
    i = 0;
    while (lista[i] != 7) // ez nem megford�that�
    {
        i++;
    }
    cout << i;

    // Keres�s, ha nem biztos, hogy van
    // Hol van az els� 7-es, ha nem biztos, hogy van hetes, �s ha nincs, akkor legyen -1?
    i = 0;
    while (i < lista.size() && lista[i] != 7) // ez nem megford�that�
    {
        i++;
    }
    cout << (i==lista.size()?-1:i);

    // Hol van az utols� 7-es, ha nem biztos, hogy van hetes, �s ha nincs, akkor legyen -1?
    //    ugyanaz, mint a helye, csak m�sik ir�nyb�l megy a ciklus!
    i = lista.size()-1;
    while (0 <= i && lista[i] != 7) // ez nem megford�that�
    {
        i--;
    }
    cout << i;

    // maximumkeres�s (�rt�k)
    // sosem 0-t�l indul!

    int max_ertek = lista[0];
    for (size_t i = 1; i < lista.size(); i++)
    {
        if (max_ertek < lista[i])
        {
            max_ertek = lista[i];
        }
    }

    cout << max_ertek;
    
    // maximumhely-keres�s
    // ez sem 0-t�l indul!

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

    // �sszegz�s (szorz�s, �sszead�s stb.)

    int sum = 0;

    for (int& elem : lista)
    {
        sum += elem;
    }

    cout << sum;

    // megsz�ml�l�s: h�ny 7-es van?

    int db = 0;
    for (auto& elem : lista)
    {
        if (elem == 7)
        {
            db++;
        }
    }
    cout << db;

    // V�logassuk ki a p�ros sz�mokat!

    vector<int> parosak;

    for (int& elem : lista)
    {
        if (elem%2==0)
        {
            parosak.push_back(elem);
        }
    }

    for (auto& elem : parosak) { cout << elem << " "; }

    // legyen az eredm�ny az a lista, amely a sz�mok n�gyzeteit tartalmazza!

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

