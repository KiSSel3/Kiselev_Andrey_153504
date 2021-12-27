//Лабораторная 8, задача 3. Выполнена: Киселёв А.В 153504

/*Реализовать любой из 30 вариантов (кроме уже реализованных вами)
заданий используя классы. Реализовать корректировку записей внутри файла без
полной перезаписи файла. Все методы класса должны иметь модификатор public,
а остальные поля – private;*/

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

class PhoneInfo {
private:
    char data[15];
    int kod;
    char city[20];
    long talkTime;
    int tariff;
    char cityNum[20];
    char subNum[20];

public:
    void showStruct() {
        std::cout << "Дата: " << data << std::endl;
        std::cout << "Код: " << kod << std::endl;
        std::cout << "Город: " << city << std::endl;
        std::cout << "Врмея разговора: " << talkTime << std::endl;
        std::cout << "Тариф: " << tariff << std::endl;
        std::cout << "Номер города: " << cityNum << std::endl;
        std::cout << "Номер города: " << cityNum << std::endl;
        std::cout << "Номер Абонента: " << subNum << std::endl;
    }

    void changeStruct() {
        printf("Введите дату\n");
        std::cin >> data;
        printf("Введите код\n");
        rewind(stdin);
        std::cin >> kod;
        printf("Введите название города\n");
        rewind(stdin);
        std::cin >> city;
        printf("Введите время разговора\n");
        rewind(stdin);
        std::cin >> talkTime;
        printf("Введите тариф\n");
        rewind(stdin);
        std::cin >> tariff;
        printf("Введите номер города\n");
        rewind(stdin);
        std::cin >> cityNum;
        printf("Введите номер абонента\n");
        rewind(stdin);
        std::cin >> subNum;
    }
    void InputData(int& n,std::string fileName) {
        std::ifstream fin;
        fin.open(fileName,std::ifstream::app);
        fin.seekg(n);

        if (!fin.is_open()) {
            std::cout << "Ошибка открытия файла!\n";
        }
        else {
            fin >> data;
            fin >> kod;
            fin >> city;
            fin >> talkTime;
            fin >> tariff;
            fin >> cityNum;
            fin >> subNum;
        }
        n = fin.tellg();
        fin.close();
    }
    void OutputData(std::string fileName) {
        std::ofstream fout;
        fout.open(fileName, std::ofstream::app);
        if (!fout.is_open()) {
            std::cout << "Ошибка открытия файла!\n";
        }
        else {
            fout << data << std::endl;
            fout << kod << std::endl;
            fout << city << std::endl;
            fout << talkTime << std::endl;
            fout << tariff << std::endl;
            fout << cityNum << std::endl;
            fout << subNum << std::endl;
        }
        fout.close();
    }
};

PhoneInfo* delStruct(PhoneInfo* Obj, int& Size) {
    int m;
    std::cout << "Выберите элемент,который хотите удалить:\n";
    while (!(std::cin >> m)) {
        std::cout << "Введите корректное значение:\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    int j = 0;
    PhoneInfo* temp_Obj = (PhoneInfo*)calloc(Size - 1, sizeof(PhoneInfo));

    for (int i = 0; i < Size; i++) {
        if (i != m - 1) {
            temp_Obj[j] = Obj[i];
            j++;
        }
        else
            continue;
    }

    Size--;
    free(Obj);
    Obj = temp_Obj;
    return Obj;
}

PhoneInfo* addStruct(PhoneInfo* Obj, int& OldSize, int& NewSize) {
    NewSize = OldSize + NewSize;
    if (OldSize == 0) {
        Obj = (PhoneInfo*)calloc(NewSize, sizeof(PhoneInfo));
    }
    else {
        PhoneInfo* temp_Obj = (PhoneInfo*)calloc(NewSize, sizeof(PhoneInfo));
        for (int i = 0; i < OldSize; i++) {
            temp_Obj[i] = Obj[i];
        }
        free(Obj);
        Obj = temp_Obj;
    }
    return Obj;
}

int main() {
    setlocale(LC_ALL, "ru");

    std::string fileName = "file.txt";

    PhoneInfo* data = 0;
    int oldSize = 0;
    int newSize = 0;
    std::ofstream output;
    std::ifstream input;
    
    do {
        
        int n = 0;

        std::cout << "Выберите действие:\n 1 - создать структуру\n 2 - изменить структуру\n 3 - записать в файл\n 4 - записать из файла \n 5 - удалить\n 6 - показать структуру\n 0 - выход\n";
        
        switch (_getch()){
        case '1':// добавляет структуру
            printf("Введите размер:\n");
            scanf_s("%d", &newSize);
            data = addStruct(data, oldSize, newSize);
            for (int i = oldSize; i < newSize; i++)
                data[i].changeStruct();
            oldSize = newSize; break;
        case '2':// изменяет структуру
            int ind;
            printf("Введите номер структуры, которую хотите изменить");
            scanf_s("%d", &ind);
            ind--;
            data[ind].changeStruct(); break;

        case '3':// записать в файл
            for (int i = 0; i < newSize; i++) 
                data[i].OutputData(fileName); break;   

        case '4':// записать из файла
            printf("Введите размер:\n");
            scanf_s("%d", &newSize);
            
            data = addStruct(data, oldSize, newSize);

            for (int i = 0; i < newSize; i++) {
                data[i].InputData(n, fileName);
            }

            oldSize = newSize; break;

        case '5':// удалить структуру
            if (data != 0)
                data = delStruct(data, newSize); break;

        case '6':
            for (int i = 0; i < newSize; i++)
                data[i].showStruct(); break;

        case '0':
            return 0;
        default:
            system("cls");
        }          

    } while (true);


    return 0;
}