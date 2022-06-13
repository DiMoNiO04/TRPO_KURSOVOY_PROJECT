#pragma once    //������ �� ���������� ��������� ����������� ���������� �������������
//���������� ������������ �����
#include "Functions.h"
#include"User.h"
#include "Validation.h"
#include "Autorization.h"
#include "SearchSort.h"
#include"EditFunctions.h"
#include "Const.h"

//������� ���� ������������
enum mainMenuUser {
	EXIT_FROM_USER,         //����� �� ����������� ������������
	VIEW_ALL_PATIENTS,      //�������� ���� ���������
	VIEW_NONRESIDENT,       //����� ����������� ���������
	SEARCH,                 //�����
	SORT,                   //����������
	FILTRATION,             //����������
	EDIT_PASSWORD,			//�������� ������
};

//������� ���� ������������
void mainUserMenu();

//���������� ������������
void user(account*(&accounts), int &amountOfAccounts, int numberOfAccount, dataPatients*(&patients), int &amountOfPatients);

