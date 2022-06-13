//���������� ������������ ����
#include"MainAdmin.h"


//���� �������� ��������������
void mainMenuMainAdmin() {
	system("cls");
	coutYellowText( MAIN_ADMIN_FUNCTIONALITY);
	cout << "1. ������ � �������� ��������\n"
		<< "2. ��������� ������ � ���������\n"
		<< "3. ��������� ������ ������\n"
		<< "0. ����� �� ����������� �������� ��������������\n"
		<< "<< ";
}

//���� ������ � �������� ��������
void menuWorkWithAccounts() {
	system("cls");
	coutYellowText(MAIN_ADMIN_FUNCTIONALITY);
	cout << "1. �������� ���� ������� �������\n"
		<< "2. �������������� ������� �������\n"
		<< "3. �������� ������� �������\n"
		<< "0. ����� �� ������ � �������� ��������\n"
		<< "<< ";
}

//������ � �������� ��������
void workWithAccounts(account* (&accounts), int& amountOfAccounts, int activeAccount, dataPatients* (&patients), int amountOfPatients) {

	menuWorkWithAccounts();   //���� ������ � �������� ��������
	int choiceWorkWithAccounts = inputNumber(EXIT_FROM_WORKING_WITH_ACCOUNTS, DELETE_ACCOUNTS);  //����� �������� � �������� �� ��������� ����

	switch (choiceWorkWithAccounts) {   //�������� ����� �������� 
	case VIEW_ALL_ACCOUNTS: {  //�������� ���� ������� �������
		printAllAccounts(accounts, amountOfAccounts);
		break;
	}
	case EDIT_ACCOUNTS: {  //�������������� ������� �������
		editAccount(accounts, amountOfAccounts, activeAccount);
		break;
	}
	case DELETE_ACCOUNTS: {  //�������� ������� �������
		deleteAccounts(accounts, amountOfAccounts, activeAccount, patients, amountOfPatients);
		break;
	}
	case EXIT_FROM_WORKING_WITH_ACCOUNTS: {  //����� �� ������ � �������� ��������
		return;
	}
	}
	system("pause");
	workWithAccounts(accounts, amountOfAccounts, activeAccount, patients, amountOfPatients);
}

//���������� �������� ��������������
void mainAdmin(account* (&accounts), int& amountOfAccounts, int activeAccount, dataPatients* (&patients), int& amountOfPatients) {

	mainMenuMainAdmin();   //���� ������ � �������� ��������
	int choiceMainAdmin = inputNumber(EXIT_FROM_MAIN_ADMIN, EDIT_PASSWORD_MAIN_ADMIN);  //����� �������� � �������� �� ��������� ����

	switch (choiceMainAdmin) {   //�������� ����� �������� 
	case WORK_WITH_ACCOUNTS_FOR_MAIN_ADMIN: {  //������ � �������� ��������
		workWithAccounts(accounts, amountOfAccounts, activeAccount, patients, amountOfPatients);
		break;
	}
	case PROCCESSING_PATIENTS: {  //��������� ������ � ���������
		if (amountOfPatients != DATA_EMPTY) {  //���� ��� �������� � �������
			proccesingPatientsData(patients, amountOfPatients);
		}
		else {
			coutBlueText(PATIENTS_NO);
		}
		break;
	}
	case EDIT_PASSWORD_MAIN_ADMIN: {  //�������������� ������
		passwordEdit(accounts, amountOfAccounts, activeAccount);
		break;
	}
	case EXIT_FROM_MAIN_ADMIN: {  //����� �� ����������� �������� ��������������
		exitFromAccount(accounts, amountOfAccounts, activeAccount, patients, amountOfPatients, mainAdmin);
		return;
	}
	}
	system("pause");
	mainAdmin(accounts, amountOfAccounts, activeAccount, patients, amountOfPatients);
}
