//���������� ������������ ����� �����
#include"Functions.h"
#include "Autorization.h"

int main() {
	//������������ �������
	SetConsoleCP(1251);  //��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);  //��������� ������� �������� win-cp 1251 � ����� �����

	 //���������� ������ ��������� � ������� ������� � ������
	int amountOfAccounts = DATA_EMPTY;                                      //���������� ������� ������� � �����
	string fileAccounts = "accounts.txt";                                   //�������� ��� ����� � �������� ��������
	account* accounts = new account[RESERVE_AMOUNT_OF_ACCOUNTS];            //�������� ��������� ��� ������ ������� ������� �� �����
	openingFileAccounts(accounts, amountOfAccounts, fileAccounts);          //�������� ����� ������� �������

	int amountOfPatients = DATA_EMPTY;                                      //���������� ��������� � �����                            
	string filePatients = "patients.txt";                                   //�������� ����� ��� ���������
	dataPatients* patients = new dataPatients[RESERVE_AMOUNT_OF_ACCOUNTS];  //�������� ��������� ��� ������ ��������� �� �����
	openingFilePatients(patients, amountOfPatients, filePatients);              //�������� ����� � ����������

	autorization(accounts, amountOfAccounts, patients, amountOfPatients);   //������� �����������
	
	return 0;
}

