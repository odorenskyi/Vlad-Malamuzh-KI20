#include <iostream>
#include <io.h>
#include <wchar.h>
#include <fcntl.h>
#include <ModulesMalamuzh.h>
using namespace std;

void dev_information()
{
    wcout << L" ---------------------------------------------------------------------------- " << endl;
    wcout << L"| Даний застосунок розроблено студентом центральноукраїнського нацiонального |" << endl;
    wcout << L"| технiчного унiверситету Маламужом Владиславом Сергійовичом 15 травня 2021 року.  |" << endl;
    wcout << L" ---------------------------©ALL_RIGHTS_ARE_RESERVED-------------------------" << endl;
}

int main()
{

    _wsetlocale(LC_ALL,L" ");
    _setmode(_fileno(stdout), _O_U8TEXT);

    char input = ' ';
    int x, y, z;
    float fahrenheit, celsius;
    int number = 0;
    dev_information();

    wcout << L"j - розв'язування виразу S = M_PI*x+pow(M_E,abs(y))-sqrt(abs(pow(z,2)-y))" << endl;
    wcout << L"z - розрахувати бал хвилювання моря" << endl;
    wcout << L"x - конвертація температури з Фаренгейтів в Цельсії" << endl;
    wcout << L"c - порахувати кiлькiсть бiнарних нулiв та одиниць числа." << endl;
    wcout << L"v, V, A - вийти." << endl;
    wcout << L"*______________________________________________________________________*" << endl;

    while(true){
       wcout << L"Введiть ключ: ";
       cin >> input;

       if(input == 'j'){
            while(true){
                 wcout << L"Введiть х: ";
                 if(!scanf("%d", &x)){
                     scanf("%*[^\n]");
                     wcout << L"Ви ввели символ, введiть число.\a" << endl;
                 }
                 else
                     break;
            }
            while(true){
                 wcout << L"Введiть y: ";
                 if(!scanf("%d", &y)){
                     scanf("%*[^\n]");
                     wcout << L"Ви ввели символ, введiть число. \a" << endl;
                 }
                 else
                     break;
             }
             while(true){
                 wcout << L"Введiть z: ";
                 if(!scanf("%d", &z)){
                     scanf("%*[^\n]");
                     wcout << L"Ви ввели символ, введiть число. \a" << endl;
                 }
                 else
                     break;
             }
             wcout << L"Результат S = " << calculations_s(x, y, z) << endl;
             wcout << L"*______________________________________________________________________*" << endl;
       } else if(input == 'z'){
            while(true){
                wcout << L"Введiть висоту хвиль (вiд 0 до 20): ";
                                                int wave=0;
                                                wcin >> wave;
                                                if(wave >=0 && wave <= 20)
                                                {
                                                    wcout << L"Бал хвилювання моря такий - " <<rating_actions(wave) << endl;
                                                    break;
                                                }
                                                else{
                                                    wcout << L"Невiрно введено данi, спробуйте ще раз. \a" << endl;
                                                }
                            }

            wcout << L"______________________________________________________________________" << endl;
       } else if(input == 'x'){
        while(true){
            wcout << "Fahrenheit: ";
               cin >> fahrenheit;
               celsius = (5.0/9) * (fahrenheit - 32);
               wcout << "Celcius = " << celsius << endl;
               break;

           }
            wcout << L"______________________________________________________________________" << endl;
       } else if(input == 'c'){
            while(true){
                wcout << L"Введiть цiле число вiд 0 до :65535 ";
                if(!scanf("%d", &number)){
                    scanf("%*[^\n]");
                    wcout << L"Ви ввели символ, введiть число. \a" << endl;
                }else if(number >= 0 && number <= 65535)
                {
                    wcout << bin_zero_counter(number) << L" - результат виконання." << endl;
                    break;
                }else{
                    wcout << L"Невiрно введенi данi. \a" << endl;
                }
            }
            wcout << L"______________________________________________________________________" << endl;
       } else if(input == 'v' || input == 'V' || input == 'A'){
            break;
       } else {
            wcout << L"Невiрно введений ключ. \a" << endl;
       }

    }

    return 0;
}
