#include "Menu.h"
Menu::Menu()
{}

Menu::Menu(Display* d)
{
	int tmp;
	while (1)
	{
		print(MENU);
		cin >> tmp;
		switch (tmp)
		{
		case 0:
			cout << "==============" << endl;
			cout << "Exiting" << endl;
			cout << "==============" << endl;
			opt = 999;
			return;
		case 1:
			while (tmp)
			{
				print(SETTINGS);
				cin >> tmp;
				switch (tmp)
				{
				case 0:
					break;
				case 1:
					int tmp1, tmp2;
					cout << "Window widht: " << endl;
					cin >> tmp1;
					cout << "Window height: " << endl;
					cin >> tmp2;
					d->change_size(tmp1, tmp2);
					break;
				case 2:
					break;
				default:
					cout << "Wrong option" << endl;
					break;
				}
		case 2:
			opt = 1;
			return;
		default:
			cout << "Wrong option" << endl;
			break;
			}
		}
	}
}

void Menu::print(Meni opt)
{
	switch (opt)
	{
	case MENU:
		cout << "=====" << endl;
		cout << "0.Wyjscie z gry." << endl;
		cout << "1.Ustawienia." << endl;
		cout << "2.Wybierz poziom" << endl;
		break;
	case SETTINGS:
		cout << "=====" << endl;
		cout << "0.Powrot." << endl;
		cout << "1.Zmien rozdzielczosc." << endl;
		break;
	}
}

int Menu::get_opt()
{
	return opt;
}