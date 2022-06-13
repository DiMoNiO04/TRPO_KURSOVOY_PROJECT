#pragma once  //������ �� ���������� ��������� ����������� ���������� �������������
//���������� ���������� � ������������ �����
#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>
#include<algorithm>
#include<Windows.h>
#include<ctime>
#include<cstdlib>
using namespace std;  //����������� ������������ ����


//��������� ���� ��������
struct dateOfBirth {
	int day,   //���� ��������
		month, //����� ��������
		year;  //��� ��������
};

//��������� ���� ������
struct dataPatients {
	string surname;          //������� ��������
	string name;             //��� ��������
	string patronymic;       //�������� ��������
	string gender;           //��� ��������
	dateOfBirth dateOfBirth; //���� �������� ��������
	string town;             //����� �������� ��������
	string phoneNumber;      //����� �������� ��������
	string diagnosis;        //������� ��������
};

//��������� ������� �������
struct account {
	string login;      //�����
	string hash;       //������
	string salt;       //����
	string role;       //������������ ��� �������������
	string access;     //������
};


//-----------------------------------------������� ������ � ������� ��������� �����------------------------------------------------------------
//�������� ����� � ����������
void openingFilePatients(dataPatients* (&patients), int& amountOfPatients, string fileName);

//����� ���� ��������� � ������� 
void printAllPatients(dataPatients* (&patients), int &amountOfPatients);

//����� ������ �������� � �������
void printPatient(dataPatients* patients, int numberPatient);

//����� ����� 
void printShapka();

//���������� ������ ��������� � ����
void savingPatients(dataPatients* patients, int amountOfPatients, string fileName);

//���������� ��������
void addPatient(dataPatients* (&patients), int& amountOfPatients);

//����������� ���������
void copy(dataPatients* (&patientstNew), dataPatients* (patientsOld), int amountOfPatients);

//�������� ��������
void deletePatient(dataPatients* (&patients), int& amountOfPatients);

//����� ���� ����������� ���������
void printNonresidentPatients(dataPatients* patients, int amountOfData);

//���� ���� ��������
void inputDateOfBirth(dataPatients* (&patients), int amountOfPatients);
//----------------------------------------������� ������ � ������� ��������� �����-------------------------------------------------------------


//----------------------------------------������� ������ � �������� �������� �����-------------------------------------------------------------
 //�������� ����� � �������� ��������
void openingFileAccounts(account* (&accounts), int& amountOfAccounts, string fileName);

//���������� ������� ������� � ������
void readingFileAccounts(account* (&accounts), int& amountOfAccounts, string fileAccounts);

//����� ���� ������� ������� �� �����
void printAllAccounts(account* accounts, int amountOfAccounts);

//���������� ������� ������� � ����
void savingAccount(account* accounts, int amountOfAccounts, string fileName);

//����� ������ ��������
void printAccount(account* accounts, int numberAccount);

//����������� ��������
void copyAccount(account* (&accountsNew), account* (accountsOld), int amountOfAccounts);

//������� ��������� ��� �������
int accountsWithoutAccess(account* (&accounts), int amountOfAccounts);

//������ ��������� ��� ������� � ��������� ������
account* createArrOfAccountsWithoutAccess(account* (&accounts), int amountOfAccounts, int amountOfAccountNoActivation);

//����� ��������� ��� �������
void printAccountsForConfirmAdd(account* (&accounts), int amountOfAccounts);

//��������� ������ �� ��������� ��������
void confirmApplication(account* (&accounts), account* (&accountsWithAccess), int amountOfAccounts, int amountOfAccountNoActivation, int activeAccount);
void activationAccount(account* (&accounts), int& amountOfAccounts, int activeAccount);

//�������� ������� ������
void deleteAccounts(account* (&accounts), int& amountOfAccounts, int activeAccount, dataPatients*(&patients), int &amountOfPatients);


//���������� ������ �� ��������� ��������
void blockingAccount(account* (&accounts), int& amountOfAccounts, int activeAccount);
void confirmBlocking(account* (&accounts), account* (&accountsWithAccess), int amountOfAccounts, int amountOfAccountWithActivation, int activeAccount);

//������� ��������� � ��������
int accountsWithoAccess(account* (&accounts), int amountOfAccounts);

//������ ��������� � �������� � ��������� ������
account* createArrOfAccountsWithAccess(account* (&accounts), int amountOfAccounts, int amountOfAccountWithActivation);

//����� ���������� ������� �������
void printAccountsForConfirmBlocking(account* (&accounts), int amountOfAccounts);

//����� �� ��������
void exitFromAccount(account*(&accounts), int &amountOfAccounts, int activeAccount, dataPatients* (&patients), int &amountOfPatients, void user(account* (&accounts), int &amountOfAccounts, int activeAccount, dataPatients* (&patients), int &amountOfPatients));
//--------------------------------------������� ������ � �������� �������� �����--------------------------------------------------------------


//--------------------------------------------------������� ��������� ����� ������ ������-----------------------------------------------------
//������� ���� ������
void coutRedText(string LOGIN_IS_BUSY);

//������� ���� ������
void coutGreenText(string LOGIN_IS_BUSY);

//������� ���� ������
void coutBlueText(string LOGIN_IS_BUSY);

//������ ���� ������
void coutYellowText(string LOGIN_IS_BUSY);
//--------------------------------------------------������� ��������� ����� ������ �����-----------------------------------------------------