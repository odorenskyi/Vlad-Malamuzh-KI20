#ifndef MODULESMALAMUZH_H_INCLUDED
#define MODULESMALAMUZH_H_INCLUDED
#include <iostream>
#include <fstream>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>
#include <clocale>
#include <string>
#include <cstdlib>
#include <sstream>
#include <codecvt>
#include <ctime>
#include <bitset>
#include <cmath>
std::string rating_actions(std::string length);

using namespace std;

using namespace std;
int rating_actions(int wave){
     int rating;
     rating = 0;
    if (wave >= 0 && wave <= 0) {
        wcout << L"CALM-GLASSY ";
        wcout << L"Rating 0";
    } if (wave >= 0 && wave <= 0.1) {
        rating = 1;
        wcout << L"CALM-RIPPLED ";
    } if (wave >= 0.1 && wave <= 0.5) {
        rating = 2;
        wcout << L"SMOOTH-WAVELET ";
    } if (wave >= 0.5 && wave <= 1.25) {
        rating = 3;
        wcout << L"SLIGHT";
    } if (wave >= 1.25 && wave <= 2.50) {
        rating = 4;
        wcout << L"MODERATE ";
    } if (wave >= 2.50 && wave <= 4.0) {
        rating = 5;
        wcout << L"ROUGH ";
    } if (wave >= 4 && wave <= 6) {
        rating = 6;
        wcout << L"VERY ROUGH";
    } if (wave >= 6 && wave <= 9) {
        rating = 7;
        wcout << L"HIGH ";
    } if (wave >= 9 && wave <= 13) {
        rating = 8;
        wcout << L"VERY HIGH ";
    } if (wave >= 13 && wave <= 20) {
        rating = 9;
        wcout << L"PHENOMENAL";
    }
    return rating;
}
int bin_zero_counter(int number){
    int mask = 1;
    int mask_2 = 1;

    int BinOne = 0;
    int BinZero = 0;

    for(int i = 0; i < (log2(number)); i++){
        if(!(number & mask))
            BinZero++;
        else
            BinOne++;
        mask<<=1;
    }

    if(!(number & (mask_2 << 1))){
        wcout << L"Binary Zero - ";
        return BinZero;
    }else{
        wcout << L"Binary One - ";
        return BinOne;
    }
}

int temp_calculation(float celsius,float fahrenheit) {
    cout << "Введіть градус по Фаренгейту: ";
    cin >> fahrenheit;
    celsius = (5.0/9) * (fahrenheit - 32);
    cout << "Температура по Цельсію = " << celsius << endl;

    return 0;
}

double calculations_s(double x, double y, double z)
{
    double s = M_PI*x+pow(M_E,abs(y))-sqrt(abs(pow(z,2)-y)) ;
    return s;
}

class ModulesMalamuzh
{
public:
    ModulesMalamuzh();
};

#endif // MODULESMALAMUZH_H
