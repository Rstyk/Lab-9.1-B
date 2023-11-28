#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Spec {  Õ, ≤Õ‘, Ã“≈, ‘“≤, “Õ };
string specStr[] = { " Õ", "≤Õ‘", "Ã“≈", "‘“≤", "“Õ" };

struct Student
{
	string prizv;
	unsigned physics;
	unsigned math;
	unsigned kurs;
	Spec spec;
	union
	{
		unsigned prog;
		unsigned chuslo;
		unsigned ped;
	};
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
int Physics(Student* p, const int N);
int Math(Student* p, const int N);
int Physics_Math(Student* p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "¬‚Â‰≥Ú¸ N: "; cin >> N;
	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);

	int Number1 = Physics(p, N);
	cout << "Í≥Î¸Í≥ÒÚ¸ Óˆ≥ÌÓÍ ‚≥‰Ï≥ÌÌÓ Á Ù≥ÁËÍË:" << Number1 << endl;
	int Number2 = Math(p, N);
	cout << "Í≥Î¸Í≥ÒÚ¸ Óˆ≥ÌÓÍ ‚≥‰Ï≥ÌÌÓ Á Ï‡ÚÂÏ‡ÚËÍË:" << Number2 << endl;

	int Number3 = Physics_Math(p, N);
	cout << "Í≥Î¸Í≥ÒÚ¸ ÒÚÛ‰ÂÌÚ≥‚ Á ‚≥‰Ï≥ÌÌËÏË Óˆ≥ÌÍ‡ÏË Á Ù≥Á. Ú‡ Ï‡Ú.:" << Number3 << endl;

	return 0;
}

void Create(Student* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "—ÚÛ‰ÂÌÚ π " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " Ô≥Á‚Ë˘Â: "; getline(cin, p[i].prizv);
		cout << " ÍÛÒ: "; cin >> p[i].kurs;
		cout << " ÒÔÂˆ≥‡Î¸Ì≥ÒÚ¸ (0 -  Õ, 1 - ≤Õ‘, 2 - Ã“≈, 3 - ‘“≤, 4 - “Õ): ";
		cin >> spec;
		p[i].spec = (Spec)spec;
		cout << " Óˆ≥ÌÍ‡ Á Ù≥ÁËÍË: "; cin >> p[i].physics;
		cout << " Óˆ≥ÌÍ‡ Á Ï‡ÚÂÏ‡ÚËÍË: "; cin >> p[i].math;
		switch (p[i].spec)
		{
		case  Õ:
			cout << " Óˆ≥ÌÍ‡ Á ÔÓ„‡ÏÛ‚‡ÌÌˇ: "; cin >> p[i].prog;
			break;
		case ≤Õ‘:
			cout << " Óˆ≥ÌÍ‡ Á ˜ËÒÂÎ¸ÌËı ÏÂÚÓ‰≥‚: "; cin >> p[i].chuslo;
			break;
		case Ã“≈:
		case ‘“≤:
		case “Õ:
			cout << " Óˆ≥ÌÍ‡ Á ÔÂ‰‡„Ó„≥ÍË: "; cin >> p[i].ped;
			break;
		}
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "==============================================================================================================="
		<< endl;
	cout << "|  π |   Ô≥Á‚Ë˘Â   |  ÍÛÒ |  ÒÔÂˆ. |  Ù≥Á. |  Ï‡Ú. |  ÔÓ„. | ˜ËÒÎ. |  ÔÂ‰„. |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(13) << right << p[i].prizv
			<< "| " << setw(5) << right << p[i].kurs << " "
			<< "| " << setw(7) << right << specStr[p[i].spec]
			<< "| " << setw(5) << right << p[i].physics << " "
			<< "| " << setw(5) << right << p[i].math << " ";

		switch (p[i].spec)
		{
		case  Õ:
			cout << "| " << setw(6) << right << p[i].prog << " " << "| " << setw(8) << "| " << setw(8);
			break;
		case ≤Õ‘:
			cout << "| " << setw(9) << "| " << setw(5) << right << p[i].chuslo << " " << "| " << setw(8);
			break;
		case Ã“≈:
		case ‘“≤:
		case “Õ:
			cout << "| " << setw(9) << "| " << setw(8) << "| " << setw(6) << right << p[i].ped << " ";
			break;
		}
		cout << "|"
			<< endl;
	}
	cout << "==============================================================================================================="
		<< endl;
	cout << endl;
}


int Physics(Student* p, const int N)
{
	int n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].physics == 5)
			n++;
	}
	return n;
}
int Math(Student* p, const int N)
{
	int n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].math == 5)
			n++;
	}
	return n;
}
int Physics_Math(Student* p, const int N)
{
	int students = 0;

	for (int i = 0; i < N; i++) {
		if (p[i].physics == 5 && p[i].math == 5) {
			students++;
		}
	}
	return students;
}
