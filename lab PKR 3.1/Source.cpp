#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
using namespace std;

enum Spec { CS, IT, ME, PhIT, TR };

string strSpec[] = { "Комп'ютернi науки", "Iнформатика", "Математика та економiка", "Фiзика та iнформатика", "Трудове навчання" };

struct Student {
    string surnamed;
    int kurs;
    Spec spec;
    int physics;
    int math;
    union {
        int progr;
        int numb;
        int ped;
    };
};

void Create(Student* s, int amSt) {
    int sp;
    for (int i = 0; i < amSt; i++) {
        cout << "Прiзвище: "; cin >> s[i].surnamed;
        cout << "Курс: "; cin >> s[i].kurs;
        cout << "Спецiальнiсть (0 - Комп'ютернi науки; 1 - Iнформатика; 2 - Математика та економiка; 3 - Фiзика та iнформатика; 4 - Трудове навчання;) ";
        cin >> sp;
        s[i].spec = (Spec)sp;
        cout << "Оцiнка з фiзики: ";
        cin >> s[i].physics;
        cout << "Оцiнка з математики: ";
        cin >> s[i].math;
        if (s[i].spec == 0) {
            cout << "Оцiнка з програмування: ";
            cin >> s[i].progr;
        }
        else if (s[i].spec == 1) {
            cout << "Оцiнка з чисельних методiв: ";
            cin >> s[i].numb;
        }
        else {
            cout << "Оцiнка з педагогiки: ";
            cin >> s[i].ped;
        }
    }
}
void Print(Student* s, int amSt)
{
    cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|  №  | курс |    прізвище    |       спеціальність     | фізика | математика |програмування |чисельні методи | педагогіка|" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << left;
    for (int i = 0; i < amSt; i++) {

        cout << "|" << setw(3) << right << i + 1 << "  ";
        cout << "| " << setw(3) << right << s[i].kurs << "  "
            << "|" << setw(16) << left << s[i].surnamed
            << "| " << setw(24) << left << strSpec[s[i].spec]
            << "| " << setw(3) << right <<s[i].physics << "    "
            << "| " << setw(6) << right << s[i].math << "     ";
        if (s[i].spec == 0) {
            cout << "| " << setw(7) << right << s[i].progr << "      "
                << "| " << setw(15) << right << " "
                << "| " << setw(11) << right << " " << "| ";
        }
        else if (s[i].spec == 1) {
            cout << "| " << setw(13) << right << " "
                << "| " << setw(8) << right << s[i].numb << "       "
                << "| " << setw(11) << right << " " << "| ";
        }
        else {
            cout << "| " << setw(13) << right << " "
                << "| " << setw(15) << right << " "
                << "| " << setw(5) << right << s[i].ped << "      " << "| ";
        }
        cout << endl;
    }
    cout << "-----------------------------------------------------------------------------------------------------------------------------------"
        << endl;
}

double HighestAverageScore(Student* s, int N)
{
    double m = (s[0].physics + s[0].math + s[0].progr) / 3;
    double m1 = (s[0].physics + s[0].math + s[0].numb) / 3;
    double m2 = (s[0].physics + s[0].math + s[0].ped) / 3;
    for (int i = 0; i < N; i++)
    {
        if ((s[i].physics + s[i].math + s[i].progr) / 3 > m)
        {
            m = (s[i].physics + s[i].math + s[i].progr) / 3;
            return m;
        }
        if ((s[i].physics + s[i].math + s[i].numb) / 3 > m)
        {
            m1 = (s[i].physics + s[i].math + s[i].numb) / 3;
            return m1;
        }
        if ((s[i].physics + s[i].math + s[i].ped) / 3 > m)
        {
            m2 = (s[i].physics + s[i].math + s[i].ped) / 3;
            return m2;
        }
    }
    return m;
}

double ProsPhysik(Student* s, int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
    {
            if (s[i].physics == 5 || s[i].physics == 4)
            {
                k++;
            }
    }
    return 100.0 * k / N*1.;
}
int main()
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int amSt;
    cout << "Кiлькiсть студентiв: "; cin >> amSt;
    Student* s = new Student[amSt];
    Create(s, amSt);
    Print(s, amSt);

    cout << "Найбільший середній бал: " << HighestAverageScore(s, amSt) << endl;
    cout << "Процент студентiв, якi отримали з фiзики оцінки «5» або «4»: " << ProsPhysik(s, amSt) << "%" << endl;
    return 0;
}