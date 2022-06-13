#pragma once//���������� �������� ���� ��� ���������� ������������ ������ ���� ���
//���������� ������������ �����
#include "Functions.h"
#include "Validation.h"
#include "Sha256.h"
#include"User.h"
#include"Admin.h"
#include"Const.h"
#include"MainAdmin.h"

//�������� ���� ����������
enum mainMenu {
	EXIT,     //����� �� �������
	ENTRANCE, //�����
	REGISTR   //������������������
};

//������� ����
void mainMenu();

//������� �����������
void autorization(account* (&accounts), int &amountOfAccounts, dataPatients* (&patients), int &amountOfPatients);

//������� �������� ������ � �����
int checkLoginAndPasswordForEntrance(account* (&accounts), int &amountOfAccounts, string hash, string validationLogin, dataPatients*(& patients), int &amountOfPatients);

//���� � �������
void entrance(account*(&accounts), int &amountOfAccounts, dataPatients*(&patients), int &amountOfPatients);

//����� �� ���������
void exitFromProgram(account* (&accounts), int &amountOfAccounts, dataPatients*(&patients), int &amountOfPatients);

//�����������
void registration(account* (&accounts), int& amountOfAccounts, dataPatients* (&patients), int& amountOfPatients);
