#pragma once
//���������� ������������ �����
#include"Functions.h"
#include"User.h"
#include"Validation.h"
#include"SearchSort.h"
#include"Autorization.h"
#include"EditFunctions.h"
#include"Sha256.h"


//������� ���� �������� ��������������
enum mainMenuMainAdmin {
	EXIT_FROM_MAIN_ADMIN,               //����� �� ����������� �������� ������
	WORK_WITH_ACCOUNTS_FOR_MAIN_ADMIN,  //������ � �������� �������� �� �������� ������
	PROCCESSING_PATIENTS,               //��������� ������ � ���������
	EDIT_PASSWORD_MAIN_ADMIN            //�������������� ������
};

//���� ������ � �������� ��������
enum menuWorkkWithAccounts {
	EXIT_FROM_WORKING_WITH_ACCOUNTS,         //����� �� ������ � �������� ��������
	VIEW_ALL_ACCOUNTS,                       //�������� ���� ������� �������
	EDIT_ACCOUNTS,                           //�������������� ������� �������
	DELETE_ACCOUNTS                          //�������� ������� �������
};


//���� �������� ��������������
void mainMenuMainAdmin();

//���� ������ � �������� ��������
void menuWorkWithAccounts();

//������ � �������� ��������
void workWithAccounts(account* (&accounts), int& amountOfAccounts, int activeAccount, dataPatients* (&patients), int amountOfPatients);

//���������� �������� ��������������
void mainAdmin(account* (&accounts), int& amountOfAccounts, int activeAccount, dataPatients* (&patients), int& amountOfPatients);