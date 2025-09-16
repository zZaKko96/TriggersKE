#include "Triggers.h"
#include <windows.h>
#include <conio.h>

char action;

void Active_RS_asynchrony_trigger()
{
	string R_signal, S_signal;
	system("cls");
	cout << "Enter R-signal:\n";
	cin >> R_signal;
	cout << "\nEnter S-signal:\n";
	cin >> S_signal;

	cout << "\nRS_asynchrony_trigger\n";
	RS_asynchrony_trigger(R_signal, S_signal);

	cout << "\nPress any button...\n";
	_getch();
}

void Active_RS_synchrony_trigger()
{
	string R_signal, S_signal, C_signal;
	char Q;
	system("cls");
	cout << "Enter R-signal:\n";
	cin >> R_signal;
	cout << "\nEnter S-signal:\n";
	cin >> S_signal;
	cout << "\nEnter C-signal:\n";
	cin >> C_signal;
	cout << "\nEnter Q value:\n";
	cin >> Q;

	cout << "\nRS_synchrony_trigger\n";
	RS_synchrony_trigger(R_signal, S_signal, C_signal, Q);

	cout << "\nPress any button...\n";
	_getch();
}

void Active_D_trigger()
{
	string D_signal, C_signal;
	char Q;
	system("cls");
	cout << "Enter D-signal:\n";
	cin >> D_signal;
	cout << "\nEnter C-signal:\n";
	cin >> C_signal;
	cout << "\nEnter Q value:\n";
	cin >> Q;

	cout << "\nD_trigger\n";
	D_trigger(D_signal, C_signal, Q);

	cout << "\nPress any button...\n";
	_getch();
}

void Active_JK_trigger()
{
	string J_signal, K_signal, C_signal;
	char Q;
	system("cls");
	cout << "Enter J-signal:\n";
	cin >> J_signal;
	cout << "\nEnter K-signal:\n";
	cin >> K_signal;
	cout << "\nEnter C-signal:\n";
	cin >> C_signal;
	cout << "\nEnter Q value:\n";
	cin >> Q;

	cout << "\nJK_trigger\n";
	JK_trigger(J_signal, K_signal, C_signal, Q);

	cout << "\nPress any button...\n";
	_getch();
}

void Active_T_trigger()
{
	string T_signal, C_signal;
	char Q;
	system("cls");
	cout << "Enter T-signal:\n";
	cin >> T_signal;
	cout << "\nEnter C-signal:\n";
	cin >> C_signal;
	cout << "\nEnter Q value:\n";
	cin >> Q;

	cout << "\nT_trigger\n";
	T_trigger(T_signal, C_signal, Q);

	cout << "\nPress any button...\n";
	_getch();
}

int main()
{
	SetConsoleTitle(TEXT("Triggers Cheat by zZaKko"));
	while (1)
	{
		system("cls");
		cout << "1. RS asynchrony trigger\tPRESS 1\n";
		cout << "2. RS synchrony trigger\t\tPRESS 2\n";
		cout << "3. D trigger\t\t\tPRESS 3\n";
		cout << "4. JK trigger\t\t\tPRESS 4\n";
		cout << "5. T trigger\t\t\tPRESS 5\n";
		cout << "\n0. Quit\t\t\t\tPRESS 0\n";

		cin >> action;
		switch (action)
		{
			case '1': Active_RS_asynchrony_trigger(); break;
			case '2': Active_RS_synchrony_trigger(); break;
			case '3': Active_D_trigger(); break;
			case '4': Active_JK_trigger(); break;
			case '5': Active_T_trigger(); break;
		}

		if (action == '0') break;
	}
	/*
	cout << "RS_asynchrony_trigger\n";
	RS_asynchrony_trigger("01.0....101","10..1..0...");
	cout << "\nRS_synchrony_trigger\n";
	RS_synchrony_trigger("1.0.10.1.0.", "0.10.1.0..1", "101.01.0101", '1');
	cout << "\nD_trigger\n";
	D_trigger("10.10.1.0.1", "101.0101.01", '1');
	cout << "\nJK_trigger\n";
	JK_trigger("01.010.1.0.", "1..0101.0.1", "1010.1.0101", '0');
	cout << "\nT_trigger\n";
	T_trigger("01.010.1.0.", "101.0101.01", '0');
	*/

	return 0;
}