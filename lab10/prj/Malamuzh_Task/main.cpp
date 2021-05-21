#include <iostream>
#include <fstream>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <cstdlib>
#include <sstream>
#include <codecvt>
#include <ctime>
#include <bitset>
#include <cmath>

#include "modulesmalamuzh.h"

using namespace std;

int checkXYZ(int num){
    wcout << L": ";

    if(!(wcin >> num)){
        wcin.clear();
        while (wcin.get() != '\n');
        wcout << L"Ви ввели символ, введіть число." << endl;
        checkXYZ(num);
    }
    return num;
}

int main()
{
    _wsetlocale(LC_ALL, L"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    ifstream inputFile;
    wifstream inFILE;
    wofstream inputFileWrite;
    wchar_t inputName[100] = L"";
    char outputName[] = "output.txt";
    wchar_t Key[2] = L"";
    wchar_t D[2] = L"D";
    wchar_t F[2] = L"F";
    int vowelNum = 0;
    char inputWord[50];

    wcout << L"*****************************************************************************" << endl;
    wcout << L"Даний застосунок виконує операцiї над файлами, використовуючи функцiї:      " << endl;
    wcout << L" * f_searchword - шукає чи є вхідному файлі слова з задачі та вносить до файлу " << endl;
    wcout << L"   iнформацiю про розробника та кiлькiсть голосних у введеному словi. Увага!" << endl;
    wcout << L"   Дана функцiя повнiстю очищує вмiст вихiдного файлу output.txt            " << endl;
    wcout << L" * second_funct() - рахує кiлькiсть цифр у вхiдному файлі та записує ре-" << endl;
    wcout << L"   зультат у вихiдний файл, у файлi вiдображається час дозапису iнформацiї. " << endl;
    wcout << L" * f_resofscalc - рахує число S за формулою з лабораторної роботи №8 та пе- " << endl;
    wcout << L"   реводить число binNum у двiйкову систему числення, результат записується " << endl;
    wcout << L"   до вихiдного файду.                                                      " << endl;
    wcout << L"****************************************************************************" << endl;

    wcout << L"Введiть назву та розширення вхiдного файлу(Ви створюєте вхiдний файл самостiйно через файловий менеджер у тецi з програмою): ";
    wcin.getline(inputName, 50);

    char ch_inputName[50] = "";
    wcstombs(ch_inputName, inputName, sizeof(ch_inputName));

    while(true){
        if(access(ch_inputName, 0) != -1){


            break;
        }
        else{
            wcout << L"Файл не знайдено. Можливе невiрно введенне iм'я або вiдсутнiсть файлу у тецi програми." << endl;
            wcin.getline(inputName, 50);
            wcstombs(ch_inputName, inputName, sizeof(ch_inputName));
        }
    }
    wcout << L"Введiть до файлу (через блокнот) слово, пiсля введення напишiть в консоль ключ \"D\"(отримання доступу до функцiй): ";
    wcin.getline(Key, 2);

    inputFile.open(ch_inputName);
    inputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    inputFile.getline(inputWord, 50);
    inputFile.close();

    inputFileWrite.open(ch_inputName, ios_base::trunc);
    inputFileWrite.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    inputFileWrite << inputWord;
    inputFileWrite.close();

    while(!wcsstr(D, Key) && !wcsstr(F, Key)){
        wcout << L"Ви ввели невiрний ключ, спробуйте ще раз: ";
        wcin >> Key;
    }
    if(wcsstr(F, Key)){
        wcout << L"Застосунок завершиться пiсля натиснення Enter" << endl;
        system("pause");
        return 0;
    } else if(wcsstr(D, Key)){
        wcout << L"Ключi для виклику функцiй: " << endl;
        wcout << L"f_searcword -- Z" << endl;
        wcout << L"second_funct -- X" << endl;
        wcout << L"f_resofscalc -- C" << endl;
        wcout << L"exit - E" << endl;



        while(true){
            wchar_t fKey;
            int x = 0;
            int y = 0;
            int z = 0;
            float S = 0;
            int binNum = 0;

            wcout << L"Введiть ключ для: ";
            wcin >> fKey;

            if(fKey == 'E')
                return 0;

            switch(fKey)
            {
                case 'Z':
                 f_searchword(ch_inputName, outputName, &vowelNum);
                 wcout << L"Введiть назву вхідного файлу з розширенням txt ";
                    wcout << L"Робота с файлами була завершена, результати виконання f_searchword можна побачити у вихiдному файлi." << endl;
                    break;
                case 'X':
                    second_funct();

                    wcout << L"Робота с файлами була завершена, результати виконання second_funct можна побачити у вихiдному файлi." << endl;
                    break;
                case 'C':
                    wcout << L"Введiть x ";
                    x = checkXYZ(x);
                    wcout << L"Введiть y ";
                    y = checkXYZ(y);
                    wcout << L"Введiть z ";
                    z = checkXYZ(z);
                    wcout << L"Введiть binNum ";
                    binNum = checkXYZ(binNum);
                    f_resofscalc(outputName, x, y, z, &S, &binNum);
                    wcout << L"Робота с файлами була завершена, результати виконання f_resofscalc можна побачити у вихiдному файлi." << endl;
                    break;
                default:
                    wcout << L"Невiрно введений ключ" << endl;
                    break;


            }
        }
    }

    return 0;
}
