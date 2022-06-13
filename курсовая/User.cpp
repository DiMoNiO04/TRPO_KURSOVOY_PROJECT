//���������� ������������ ����
#include"User.h" 


//������� ���� ������������
void mainUserMenu() {
	system("cls");      
	coutYellowText(USER_FUNCTIONALITY);
    cout << "1. �������� ���� ���������\n"
		<< "2. ������� ���� ����������� ���������\n"
		<< "3. ����� ������\n"
		<< "4. ���������� ������\n"
		<< "5. ���������� ������\n"
		<< "6. �������� ������\n"
		<< "0. ����� �� ����������� ������������\n"
		<< "<< ";
}

//���������� ������������
void user(account*(&accounts), int &amountOfAccounts, int activeAccount, dataPatients*(&patients), int &amountOfPatients) {

	mainUserMenu();  //����� �������� ���� ������������
	int choiceUser = inputNumber(EXIT_FROM_USER, EDIT_PASSWORD);  //����� �������� ������������ � �������� �� ��������� ����

	switch (choiceUser) {   //�������� ����� �������� �� ������������
	case VIEW_ALL_PATIENTS: {  //�������� ���� ���������
		if (amountOfPatients != DATA_EMPTY) {  //���� ���� �������� � �������
			printAllPatients(patients, amountOfPatients);
		}
		else {  //���� ��� ��������� � �������
			coutBlueText(NO_PATIENTS);
		}
		break;
	}
	case VIEW_NONRESIDENT: {   //����������� ��������
		if (amountOfPatients != DATA_EMPTY) {  //���� ���� �������� � �������
			printNonresidentPatients(patients, amountOfPatients);
		}
		else {  //���� ��� ��������� � �������
			coutBlueText(NO_PATIENTS);
		}
		break;
	}
	case SEARCH: {  //�����
		if (amountOfPatients != DATA_EMPTY) {  //���� ���� �������� � �������
			search(patients, amountOfPatients);
		}
		else {  //���� ��� ��������� � �������
			coutBlueText(NO_PATIENTS);
		}
		break;
	}
	case SORT: {  //���������� 
		if (amountOfPatients != DATA_EMPTY) {  //���� ���� �������� � �������
			sort(patients, amountOfPatients);
		}
		else {  //���� ��� ��������� � �������
			coutBlueText(NO_PATIENTS);
		}
		break;
	}
	case FILTRATION: {  //����������
		if (amountOfPatients != DATA_EMPTY) {  //���� ���� �������� � �������
			filtration(patients, amountOfPatients);
		}
		else {  //���� ��� ��������� � �������
			coutBlueText(NO_PATIENTS);
		}
		break;
	}
	case EDIT_PASSWORD: {  //�������� ������  
		passwordEdit(accounts, amountOfAccounts, activeAccount);
		break;
	}
	case EXIT_FROM_USER: {  //����� �� �������� ������
		exitFromAccount(accounts, amountOfAccounts, activeAccount, patients, amountOfPatients, user);
		return;
	}
	}
	system("pause");
	user(accounts, amountOfAccounts, activeAccount, patients, amountOfPatients);
}




