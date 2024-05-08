#include <iostream>
using namespace std;

const int SPACE = 10;

struct wezel {
	int dane;
	wezel* lewo;
	wezel* prawo;
};

wezel* stworz(int data)
{
	wezel* temp = new wezel();
	temp->dane = data;
	temp->prawo = temp->lewo = NULL;
	return temp;
}
void wstawianie(wezel*& korzen, int data)
{
	if (korzen == NULL)
		korzen = stworz(data);
	else if (korzen->dane > data)
		wstawianie(korzen->lewo, data);
	else if (korzen->dane <= data)
		wstawianie(korzen->prawo, data);
}

void wyswietl(wezel* korzen, int spacja)
{
	if (korzen != NULL) {
		spacja += SPACE;
		wyswietl(korzen->prawo, spacja);
		cout << endl;
		for (int i = SPACE; i < spacja; i++)
			cout << " ";
		cout << korzen->dane << endl;
		wyswietl(korzen->lewo, spacja);
	}
}

wezel* usuwanie(wezel* korzen, int x) {
	if (korzen == NULL)
		return korzen;
	else if (x < korzen->dane) {
		korzen->lewo = usuwanie(korzen->lewo, x);
	}
	else if (x > korzen->dane)
	{
		korzen->prawo = usuwanie(korzen->prawo, x);
	}
	else
	{
		if (korzen->lewo == NULL and korzen->prawo == NULL)
		{
			delete korzen;
			korzen = NULL;
		}
		else if (korzen->lewo == NULL)
		{
			wezel* temp = korzen;
			korzen = korzen->prawo;
			delete temp;
		}
		else if (korzen->prawo == NULL)
		{
			wezel* temp = korzen;
			korzen = korzen->lewo;
			delete temp;
		}
		else
		{
			wezel* temp = korzen->prawo;
			while (temp and temp->lewo != NULL)
				temp = temp->lewo;
			korzen->dane = temp->dane;
			korzen->prawo = usuwanie(korzen->prawo, temp->dane);

		}
	}
	return korzen;
}

int main() {
	wezel* korzen = NULL;
	int liczba, ile;
	int choice;
	int x;


	do {
		cout << "1. Dodaj element" << endl;
		cout << "2. Usun element" << endl;
		cout << "3. Wyswietl drzewo" << endl;
		cout << "0. Wyjscie" << endl;


		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Podaj liczbe, ktora chcesz wstawic: ";
			cin >> liczba;
			wstawianie(korzen, liczba);
			system("cls");
			break;
		case 2:
			system("cls");
			cout << "Podaj liczbe, ktora chcesz usunac: ";
			cin >> x;
			korzen = usuwanie(korzen, x);
			system("cls");
			break;
		case 3:
			system("cls");
			wyswietl(korzen, 0);
			cout << "\n\n\n";

			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "Niedostepna opcja";
		}

	} while (choice != 0);

	return 0;
}


