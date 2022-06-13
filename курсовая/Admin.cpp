//���������� ������������ ����
#include"Admin.h"

//������� ���� ��������������
void menuAdmin() {
	system("cls");
	coutYellowText(ADMIN_FUNCTIONALITY);
	cout << "1. ������ � ������� ���������\n"
		<< "2. ������ � �������� ��������\n"
		<< "3. ��������� ������ � ���������\n"
		<< "4. �������� ������\n"
		<< "0. ����� �� ����������� ��������������\n"
		<< "<< ";
}

//���� ��������� ���������� � ���������
void menuProccesingPatientsData() {
	system("cls");
	cout << "1. �������� ���������� � ���� ���������\n"
		<< "2. �������� ���������� �� ���������� ���������\n"
		<< "3. �����\n"
		<< "4. ����������\n"
		<< "5. ����������\n"
		<< "0. ����� �� ��������� ������ � ���������\n"
		<< "<< ";
}

//���� ������ � ������� ���������
void menuWorkWithPatients() {
	system("cls");
	coutYellowText(ADMIN_FUNCTIONALITY);
	cout << "1. �������� ���� ���������\n"
		<< "2. �������� ��������\n"
		<< "3. ������� ��������\n"
		<< "4. ������������� ������ ��������\n"
		<< "0. ����� �� �������������� ������ ���������\n"
		<< "<< ";
}

//���� ������ � �������� ��������
void menuWorkWithAccount() {
	system("cls");
	coutYellowText( ADMIN_FUNCTIONALITY);
	cout << "1. ����������� ��������\n"
		<< "2. ��������� ���������\n"
		<< "3. ���������� ���������\n"
		<< "0. ����� �� ������ � ����������\n"
		<< "<< ";
}

//������ � �������� ��������
void workWithAccount(account*(&accounts), int& amountOfAccounts, int activeAccount) {

	menuWorkWithAccount();   //���� ������ � �������� ��������
	int choiceWorkWithAccounts = inputNumber(EXIT_FROM_WORK_WITH_ACCOUNTS, BLOCKING_ACCOUNTS);  //����� �������� � �������� �� ��������� ����
	
	switch (choiceWorkWithAccounts) {   //�������� ����� �������� 
	case VIEW_ACCOUNTS: {  //�������� ���� ������� �������
		printAllAccounts(accounts, amountOfAccounts);
		break;
	}
	case ACTIVATION_ACCOUNTS: {   //��������� ������������ ������
		activationAccount(accounts, amountOfAccounts, activeAccount);
		break;
	}
	case BLOCKING_ACCOUNTS: {     //���������� ���������
		blockingAccount(accounts, amountOfAccounts, activeAccount);
		break;
	}
	case EXIT_FROM_WORK_WITH_ACCOUNTS: {  //����� �� ������ � �������� ��������
		return;
	}
	}
	system("pause");
	workWithAccount(accounts, amountOfAccounts, activeAccount);
}

//������ � ������� ���������
void workWithPatients(dataPatients* (&patients), int& amountOfPatients) {

	menuWorkWithPatients();  //����� ���� ������ � ����� ������
	int choiceWorkWithPatients = inputNumber(EXIT_FROM_WORKING_WITH_PATIENTS, EDIT_PATIENTS);  //����� ��������  � �������� �� ��������� ����

	switch (choiceWorkWithPatients) {   //�������� ����� �������� 
	case VIEW_PATIENTS: {  //�������� ���� ���������
		if (amountOfPatients != DATA_EMPTY) {  //���� ���� �������� � �������
			printAllPatients(patients, amountOfPatients);
		}
		else {
			coutBlueText(NO_PATIENTS);
		}
		break;
	}
	case ADD_PATIENTS: {  //���������� ��������
		addPatient(patients, amountOfPatients);
		break;
	}
	case DELETE_PATIENTS: {   //�������� ��������
		if (amountOfPatients != DATA_EMPTY) {//���� ���� �������� � �������
			deletePatient(patients, amountOfPatients);
		}
		else {
			coutBlueText(NO_PATIENTS);
		}
		break;
	}
	case EDIT_PATIENTS: {  //�������������� ���������
		if (amountOfPatients != DATA_EMPTY) {//���� ���� �������� � �������
			editDataPatient(patients, amountOfPatients);
		}
		else {
			coutBlueText(NO_PATIENTS);
		}
		break;
	}
	case EXIT_FROM_WORKING_WITH_PATIENTS: {  //����� �� ������ � ������� ����������
		return;
	}
	}
	system("pause");
	workWithPatients(patients, amountOfPatients);
}

//��������� ������ � ���������
void proccesingPatientsData(dataPatients* (&patients), int& amountOfPatients) {

	menuProccesingPatientsData();  //����� ���� ������ ��������� ������ � ���������
	int choiceProccessingPatientsData = inputNumber(EXIT_FROM_WORKING_WITH_PATIENTS, FILTRATION_PATIENTS);  //����� �������� � �������� �� ��������� ����

	switch (choiceProccessingPatientsData) {   //�������� ����� �������� �� ������������
	case VIEW_PATIENTS_ALL: {  //�������� ���� ���������
		printAllPatients(patients, amountOfPatients);
		break;
	}
	case VIEW_NONRESIDENT_PATIENTS: {   //����������� ��������
		printNonresidentPatients(patients, amountOfPatients);
		break;
	}
	case SEARCH_PATIENTS: {  //�����
		search(patients, amountOfPatients);
		break;
	}
	case SORT_PATIENTS: {  //���������� 
		sort(patients, amountOfPatients);
		break;
	}
	case FILTRATION_PATIENTS: {  //����������
		filtration(patients, amountOfPatients);
		break;
	}
	case EXIT_FROM_WORKING_WITH_PATIENTS: {
		return;
	}
	}
	system("pause");
	proccesingPatientsData(patients, amountOfPatients);
}

//���������� ��������������
void admin(account* (&accounts), int& amountOfAccounts, int activeAccount, dataPatients* (&patients), int& amountOfPatients) {

	menuAdmin();  //����� �������� ���� ������
	int choiceAdmin = inputNumber(EXIT_FROM_ADMIN, EDIT_MY_PASSWORD);  //����� �������� ������ � �������� �� ��������� ����
	system("cls");

	switch (choiceAdmin) {     //�������� ����� �������� �� ������������
	case WORK_WITH_PATIENTS: {  //������ � ������� ���������
		workWithPatients(patients, amountOfPatients);
		break;
	}
	case WORK_WITH_ACCOUNTS: {  //������ � �������� ��������
		workWithAccount(accounts, amountOfAccounts, activeAccount);
		break;
	}
	case DATA_PROCCESING_FOR_PATIENTS: { //��������� ������ � ���������
		if (amountOfPatients != DATA_EMPTY) {  //���� ��� �������� � �������
			proccesingPatientsData(patients, amountOfPatients);
		}
		else {
			coutBlueText(NO_PATIENTS);
			system("pause");
		}
		break;
	}
	case EDIT_MY_PASSWORD: { //��������� ������ ������
		passwordEdit(accounts, amountOfAccounts, activeAccount);
		break;
	}
	case EXIT_FROM_ADMIN: {  //����� �� �������� ������
		exitFromAccount(accounts, amountOfAccounts, activeAccount, patients, amountOfPatients, admin);
		return;
	}
	}
	admin(accounts, amountOfAccounts, activeAccount, patients, amountOfPatients);
}



