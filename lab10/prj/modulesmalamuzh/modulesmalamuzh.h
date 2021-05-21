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
void localisation()
{
    setlocale(LC_ALL,"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);
}

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
int input_symbol(char *exist_file)
{
    localisation();

    wifstream stream;
    wofstream output;
    wstring word;
    wifstream inputfile;
    wstring number;
    if (inputfile.good())
        {
        int number = 0;
        inputfile >> number;

        }



    stream.open(exist_file);
    if(stream.is_open())
    {
       stream.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
       getline(stream, number);
       stream.close();

       output.open(exist_file);
       output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

       output << number << L"\nКількість символів у файлі: " << number.length();
       output.close();
    }
    else
    {
       output.open(exist_file);
       output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

       output << number << L"\nКількість символів у файлі: " << number.length();
       output.close();
    }
    wcout << L"Файл був успiшно оброблений. Завершення виконання функцiї input_time." << endl;
    return 1;
}
double calculations_s(double x, double y, double z)
{
    double s = M_PI*x+pow(M_E,abs(y))-sqrt(abs(pow(z,2)-y)) ;
    return s;
}
int dec2bin(int num)
{
    int bin = 0, k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return bin;
}
int input_time(char *exist_file)
{
    localisation();

    wifstream stream;
    wofstream output;
    wstring word;
    wifstream inputfile;
    wstring number;
    if (inputfile.good())
        {
        int number = 0;
        inputfile >> number;

        }


    time_t cur_date = time(0);

    stream.open(exist_file);
    if(stream.is_open())
    {
       stream.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
       getline(stream, number);
       stream.close();

       output.open(exist_file);
       output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

       output << number << L"\nКількість цифр у файлі: " << number.length() << L"\nДата:" << ctime(&cur_date);
       output.close();
    }
    else
    {
       output.open(exist_file);
       output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

       output << number << L"\nКількість цифр у файлі: " << number.length() << L"\nДата:" << ctime(&cur_date);
       output.close();
    }
    wcout << L"Файл був успiшно оброблений. Завершення виконання функцiї input_time." << endl;
    return 1;
}
void second_funct()
{
    localisation();
    wchar_t input_file[100];
    char conv[100];

    wcout << L"Введiть назву вхiдного файлу з розширенням .txt" << endl;
    wcin >> input_file;
    const wchar_t * flag = input_file;
    wcstombs(conv, flag, sizeof(conv));

    input_time(conv);
}
int f_resofscalc(char *outputName, int x, int y, int z, float *S, int *binNum){
    _wsetlocale(LC_ALL, L"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    wofstream outputFile;
    int bitSize = 0;

    outputFile.open(outputName, ios::app);
    outputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

    *binNum = dec2bin(*binNum);
    *S = calculations_s(x, y, z);

    outputFile << L"Результат виконання s_calculation: " << *S << endl
               << L"Число B у двійковій системі числення: " << *binNum;

    outputFile.close();

    return 0;
}
void first_funct()
{
    localisation();
    wchar_t input_file[100];
    char conv[100],conv1[100], conv2[100];

    wcout << L"Введiть назву вхiдного файлу з розширенням .txt" << endl;
    wcin >> input_file;
    const wchar_t * flag = input_file;
    wcstombs(conv, flag, sizeof(conv));

    input_symbol(conv);

}
int f_searchword(char *inputName, char *outputName, int *vowelNum){

    setlocale(LC_ALL,"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    wifstream inputFile;
    wofstream outputFile;
    wchar_t wstr[50] = L"";
    *vowelNum = 0;
    int vows = 0;
    wchar_t vowelSounds[] = L"АаЕеЄєиІіЇїУуЮюЯяОо";
    wchar_t words[250] = {L"Модуль,модульчик,студент,студентка,програміст,програмістка."};

    inputFile.open(inputName);
    inputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    inputFile.getline(wstr, 50);
    inputFile.close();

    for(int i = 0; i < wcslen(wstr); i++){
        for(int j = 0; j < wcslen(vowelSounds); j++)
            if(wstr[i] == vowelSounds[j]) vows++;
    }
    *vowelNum = vows;

    outputFile.open(outputName);
    outputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    outputFile.clear();
    outputFile << L" ----------------------------------------------- " << endl
               << L"| Застосунок розроблено студентом першого курсу |" << endl
               << L"|                університету ЦНТУ              |" << endl
               << L"|       Маламужом Владиславом Сергійовичом КІ-20|" << endl
               << L" --------------©AllRightsAreReserved------------ " << endl;
    bool Marker = 0;
    int testRes = 0;
    if(wcsstr(words, wstr)){
           outputFile << L"Cлово " << wstr << L" присутнє в задачі." << endl;
           testRes = 1;
       }
       else{
           outputFile << L"Cлово " << wstr << L" відсутнє в задачі" << endl;
           testRes = 2;
       }

       outputFile.close();

       return testRes;
   }





class ModulesMalamuzh
{
public:
    ModulesMalamuzh();
};

#endif // MODULESMALAMUZH_H
