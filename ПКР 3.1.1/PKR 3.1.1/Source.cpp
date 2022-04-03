#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
using namespace std;

enum Spec { CS, IT, ME, PhIT, TR };

string strSpec[] = { "����'�����i �����", "I����������", "���������� �� ������i��", "�i���� �� i����������", "������� ��������" };

struct Student {
    string surnamed;
    int kurs;
    Spec spec;
    int physics;
    int math;
    int informatik;
};

void create(Student* s, int amSt) {
    int sp;
    for (int i = 0; i < amSt; i++) {
        cout << "��i�����: "; cin >> s[i].surnamed;
        cout << "����: "; cin >> s[i].kurs;
        cout << "����i����i��� (0 - ����'�����i �����; 1 - I����������; 2 - ���������� �� ������i��; 3 - �i���� �� i����������; 4 - ������� ��������;) ";
        cin >> sp;
        s[i].spec = (Spec)sp;
        cout << "��i��� � �i����: ";
        cin >> s[i].physics;
        cout << "��i��� � ����������: ";
        cin >> s[i].math;
        cout << "��i��� � �����������: ";
        cin >> s[i].informatik;
    }
}
void print(Student* s, int amSt)
{
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "|  �  | ���� |    �������    |       ������������     | ������ | ���������� |�����������|" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << left;
    for (int i = 0; i < amSt; i++) {

        cout << "|" << setw(3) << right << i + 1 << "  ";
        cout << "| " << setw(3) << right << s[i].kurs << "  "
            << "|" << setw(16) << left << s[i].surnamed
            << "| " << setw(24) << left << strSpec[s[i].spec]
            << "| " << setw(3) << right << s[i].physics << "    "
            << "| " << setw(6) << right << s[i].math << "     "
            << "| " << setw(6) << right << s[i].informatik << "    " << "| ";
        cout << endl;
    }
    cout << "-------------------------------------------------------------------------------------------"
        << endl;
}

double HighestAverageScore(Student* s, const int N)
{
    double m = (s[0].physics + s[0].math + s[0].informatik) / 3;
    for (int i = 0; i < N; i++)
    {
        if ((s[i].physics + s[i].math + s[i].informatik) / 3 > m)
        {
            m = (s[i].physics + s[i].math + s[i].informatik) / 3;
            return m;
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
    return 100.0 * k / N * 1.;
}
int main()
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int amSt;
    cout << "�i���i��� �������i�: "; cin >> amSt;
    Student* s = new Student[amSt];
    create(s, amSt);
    print(s, amSt);

    cout << "��������� ������� ���: " << HighestAverageScore(s, amSt) << endl;
    cout << "������� �������i�, ��i �������� � �i���� ������ �5� ��� �4�: " << ProsPhysik(s, amSt) << "%" << endl;
    return 0;
}