#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	string from_file, to_file;
	char buff[1024];
	cout << "������� �� ������ ����� ����� �����������: ";
	cin >> from_file;
	cout << "������� � ����� ���� ����� ����������(���� ���� �� ����� ������, ����� ������ �����): ";
	cin >> to_file;
	ofstream out_file;
	ifstream in_file;
	in_file.open(from_file);
	out_file.open(to_file);
	if (!in_file) return cout << "�������� ���� �� ������!",0;
	do
	{
		in_file.getline(buff, 1024);
		out_file << buff << "\n";
	}while(!in_file.eof());
	cout << "����������� �����������!";
	in_file.close(); out_file.close();
	system("pause");
}
