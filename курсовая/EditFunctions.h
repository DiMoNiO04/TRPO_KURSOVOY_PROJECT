#pragma once
//���������� ������������ ����� 
#include"Functions.h"
#include"Autorization.h"
#include"Validation.h"
#include"Const.h"

//���� �������������� ������� ������
enum menuAccountEdit {
	EXIT_FROM_EDIT_ACCOUNT,   //����� �� �������������� ������� ������
	EDIT_LOGIN_ACCOUNT,       //�������������� ������
	ACCESS_EDIT,              //��������� �������
	ROLE_EDIT,                //��������� ����
};

//���� �������������� ��������
enum menuEditDataPatient {
	EXIT_MENU_EDIT_PATIENT,  //����� �� ���� �������������� ��������
	SURNAME_EDIT,            //�������������� �������
	NAME_EDIT,               //�������������� �����
	PATRONYMIC_EDIT,         //�������������� ��������
	GENDER_EDIT,             //��������� ����
	DATA_OF_BIRTH_EDIT,      //�������������� ���� ��������
	TOWN_EDIT,               //�������������� ����� ����������
	PHONE_NUMBER_EDIT,       //�������������� ������ ��������
	DIAGNOSIS_EDIT,          //������������� ��������
};


//-----------------------------------------------����� �������---------------------------------------------------------------------------------
//���� ������ ���������
string inputEditString(string INPUT_DATA, string editData, string SYMBOLS);

//���� ������������� �������� ���������
void menuConfirmationEdit(string LOGIN);
//---------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------�������������� ���� ������ ������--------------------------------------------------------------
//���� �������������� ��������
void menuEditDataPatient();

//�������������� ���������
void editDataPatient(dataPatients* (&patients), int& amountOfPatients);

//������� �������������� ������� ������� ��������
void surnamePatientEdit(dataPatients* patients, int amountOfPatients, int numberOfPatient, string editData);

//������� �������������� ����� ������� ��������
void namePatientEdit(dataPatients* patients, int amountOfPatients, int numberOfPatient, string editData);

//������� �������������� �������� ������� ���������
void patronymicPatientEdit(dataPatients* patients, int amountOfPatients, int numberOfPatient, string editData);

//������� ��������� ���� ������� ��������
void genderPatientEdit(dataPatients* patients, int amountOfPatients, int numberOfPatient);

//������� �������������� ����� ���������� ��������
void townPatientEdit(dataPatients* patients, int amountOfPatients, int numberOfPatient, string editData);

//������� ������������� ������ �������� ������� ��������
void phonenumberPatientEdit(dataPatients* patients, int amountOfPatients, int numberOfPatient, string editData);

//������� �������������� ���� ��������
void dataOfBirthPatientEdit(dataPatients* (&patients), int& amountOfPatients, int numberOfPatient);

//������� �������������� �������� ������� ��������
void diagnosisPatientEdit(dataPatients* patients, int amountOfPatients, int numberOfPatient, string editData);
//---------------------------------------------�������������� ���� ������ �����----------------------------------------------------------------


//---------------------------------------------�������������� ������� ������� ������-----------------------------------------------------------
//���� �������������� ��������
void menuAccountEdit();

//�������������� ������ ������� ������
void editAccount(account* (&accounts), int amountOfAccounts, int activeAccount);

//������� ��������� ������� ������� ������
void accessEdit(account* accounts, int amountOfAccounts, int numberAccount);

//������� ��������� ���� ������� ������
void roleEdit(account* accounts, int amountOfAccounts, int numberAccount);

//������� ��������� ������ ������� ������
void passwordEdit(account* accounts, int amountOfAccounts, int numberOfAccount);

//������� ��������� ������ ������� ������
void loginEdit(account* accounts, int amountOfAccounts, int numberAccount);
//---------------------------------------------�������������� ������� ������� �����------------------------------------------------------------
