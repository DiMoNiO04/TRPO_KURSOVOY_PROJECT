#pragma once
//���������� ������������ �����
#include"Functions.h"
#include"User.h"
#include"Validation.h"
#include"SearchSort.h"
#include"Autorization.h"
#include"EditFunctions.h"
#include"Sha256.h"

//������� ���� ������
enum menuAdmin {
	EXIT_FROM_ADMIN,               //����� �� ����������� ������
	WORK_WITH_PATIENTS,            //������ � ������ ���������
	WORK_WITH_ACCOUNTS,            //������ � ����������
	DATA_PROCCESING_FOR_PATIENTS,  //��������� ������ � ���������
	EDIT_MY_PASSWORD               //�������������� ������
};

//���� ������ � �������� ��������
enum menuWorkWithAccounts {
	EXIT_FROM_WORK_WITH_ACCOUNTS,  //����� �� ������ � �������� ��������
	VIEW_ACCOUNTS,                 //�������� ���������
	ACTIVATION_ACCOUNTS,           //��������� ���������
	BLOCKING_ACCOUNTS              //���������� ���������
};

//���� ������ � ������� ���������
enum menuWorkWithPatients {
	EXIT_FROM_WORK_WITH_PATIENTS,  //����� �� ������ � ������� ���������
	VIEW_PATIENTS,                 //�������� ���������
	ADD_PATIENTS,                  //���������� ���������
	DELETE_PATIENTS,               //�������� ���������
	EDIT_PATIENTS                  //�������������� ���������
};

//���� ��������� ������ � ���������
enum menuProccesingPatientsData {
	EXIT_FROM_WORKING_WITH_PATIENTS,     //����� �� ��������� ������ � ���������
	VIEW_PATIENTS_ALL,                   //����� ���������� � ���� ���������
	VIEW_NONRESIDENT_PATIENTS,           //����� ����������� ���������
	SEARCH_PATIENTS,                     //����� 
	SORT_PATIENTS,                       //����������
	FILTRATION_PATIENTS                  //����������
};


//������� ���� ��������������
void menuAdmin();

//���� ��������� ���������� � ���������
void menuProccesingPatientsData();

//���� ������ � ������� ���������
void menuWorkWithPatients();

//���� ������ � �������� ��������
void menuWorkWithAccount();

//������ � �������� ��������
void workWithAccount(account*(& accounts), int &amountOfAccounts, int activeAccount);

//������ � ������� ���������
void workWithPatients(dataPatients* (&patients), int& amountOfPatients);

//���������� ��������������
void admin(account*(&accounts), int &amountOfAccounts, int activeAccount, dataPatients* (&patients), int &amountOfPatients);

//��������� ������ � ���������
void proccesingPatientsData(dataPatients* (&patients), int& amountOfPatients);