//���������� ������������ �����
#include"EditFunctions.h"


//-----------------------------------------------����� �������--------------------------------------------------------------------------------
//���� ������ ���������
string inputEditString(string INPUT_DATA, string editData, string SYMBOLS) {

	cout << INPUT_DATA;
	editData = inputValidationString(SYMBOLS);
	return editData;
}

//���� ������������� �������� ���������
void menuConfirmationEdit(string LOGIN) {
	cout << "\n�� �������, ��� ������ �������� " << LOGIN << "?\n"
		<< "1. ��\n"
		<< "2. ���\n"
		<< "<< ";
}
//--------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------�������������� ���� ������ ������--------------------------------------------------------------
//���� �������������� ��������
void menuEditDataPatient() {
	cout << "��������, ��� ������ �������� � ������� ��������\n"
		<< "1. �������\n"
		<< "2. ���\n"
		<< "3. ��������\n"
		<< "4. ���\n"
		<< "5. ���� ��������\n"
		<< "6. ����� ����������\n"
		<< "7. ����� ��������\n"
		<< "8. �������\n"
		<< "0. ����� �� ���� �������������� ��������\n"
		<< "<< ";
}

//�������������� ���������
void editDataPatient(dataPatients* (&patients), int& amountOfPatients) {

	printAllPatients(patients, amountOfPatients);  //����� ���� ���������
	cout << "\n������� ����� �������� �� 1 �� " << amountOfPatients << " ������, �������� ������ �������� << ";
	int numberOfPatient = inputNumber(BACK, amountOfPatients);  //�������� �� ���������� ���� ������ ��������
	system("cls");

	if (numberOfPatient != BACK) { //���� �� 0 (����� �����)

		string editData;
		numberOfPatient--;
		printPatient(patients, numberOfPatient);  //����� ������ �������� ������ �������� ����� ��������
		menuEditDataPatient();   //���� ������ ��������������
		int choiceEditDataPatient = inputNumber(EXIT_MENU_EDIT_PATIENT, DIAGNOSIS_EDIT);   //�������� �� ���������� ���� 

		switch (choiceEditDataPatient) {   //�������� ����� ���� ���������
		case SURNAME_EDIT: {  //�������������� �������
			surnamePatientEdit(patients, amountOfPatients, numberOfPatient, editData);
			break;
		}
		case NAME_EDIT: {   //��������������  �����
			namePatientEdit(patients, amountOfPatients, numberOfPatient, editData);
			break;
		}
		case PATRONYMIC_EDIT: {  //�������������� ��������  
			patronymicPatientEdit(patients, amountOfPatients, numberOfPatient, editData);
			break;
		}
		case GENDER_EDIT: {  //��������� ����
			genderPatientEdit(patients, amountOfPatients, numberOfPatient);
			break;
		}
		case DATA_OF_BIRTH_EDIT: {  //�������������� ���� ��������
			dataOfBirthPatientEdit(patients, amountOfPatients, numberOfPatient);  //�������� ���� ��������
			break;
		}
		case TOWN_EDIT: {  //�������������� ����� ����������
			townPatientEdit(patients, amountOfPatients, numberOfPatient, editData);
			break;
		}
		case PHONE_NUMBER_EDIT: {  //�������������� ������ ��������
			phonenumberPatientEdit(patients, amountOfPatients, numberOfPatient, editData);
			break;
		}
		case DIAGNOSIS_EDIT: {  //�������������� ��������
			diagnosisPatientEdit(patients, amountOfPatients, numberOfPatient, editData);
			break;
		}
		case EXIT_MENU_EDIT_PATIENT: { //����� �� ���� ��������������
			break;
		}
		}
	}
	else {
		return;
	}
}

//������� �������������� ������� ������� ��������
void surnamePatientEdit(dataPatients* patients, int amountOfPatients, int numberOfPatient, string editData) {

	editData = inputEditString(INPUT_SURNAME, editData, LETTERS_SYMBOLS); //������ ����� ������
	menuConfirmationEdit(SURNAME);  //���� �������������
	if (confirmation()) {  //���� �������� �� ��������� ������
		patients[numberOfPatient].surname = editData;  //�������� ������ ������ �� �����
		savingPatients(patients, amountOfPatients, "patients.txt");  //��������� ���������
		coutGreenText(DATA_BEEN_CHANGED);
	}
	else {
		coutRedText(DATA_HAS_NOT_BEEN_CHANGED);
	}
}

//������� �������������� ����� ������� ��������
void namePatientEdit(dataPatients* patients, int amountOfPatients, int numberOfPatient, string editData) {

	editData = inputEditString(INPUT_NAME, editData, LETTERS_SYMBOLS);  //������ ����� ������
	menuConfirmationEdit(NAME);   //���� �������������
	if (confirmation()) {  //���� �������� �� ��������� ������
		patients[numberOfPatient].name = editData;  //�������� ������ ������ �� �����
		savingPatients(patients, amountOfPatients, "patients.txt");  //��������� ���������
		coutGreenText(DATA_BEEN_CHANGED);
	}
	else {
		coutRedText(DATA_HAS_NOT_BEEN_CHANGED);
	}
}

//������� �������������� �������� ������� ���������
void patronymicPatientEdit(dataPatients* patients, int amountOfPatients, int numberOfPatient, string editData) {

	editData = inputEditString(INPUT_PATRONYMIC, editData, LETTERS_SYMBOLS);   //������ ����� ������
	menuConfirmationEdit(PATRONYMIC);   //���� �������������
	if (confirmation()) {  //���� �������� �� ��������� ������
		patients[numberOfPatient].patronymic = editData;  //�������� ������ ������ �� �����
		savingPatients(patients, amountOfPatients, "patients.txt");  //��������� ���������
		coutGreenText(DATA_BEEN_CHANGED);
	}
	else {
		coutRedText(DATA_HAS_NOT_BEEN_CHANGED);
	}
}

//������� ��������� ���� ������� ��������
void genderPatientEdit(dataPatients* patients, int amountOfPatients, int numberOfPatient) {

	menuConfirmationEdit(GENDER);  //���� �������������
	if (confirmation()) {  //���� �������� �� ��������� ����
		if (patients[numberOfPatient].gender == MAN) {  //���� ��� ��� �������
			patients[numberOfPatient].gender = WOMAN;  //�������� �� �������
		}
		else {  //���� ��� ��� �������
			patients[numberOfPatient].gender = MAN;  //�������� �� �������
		}
		savingPatients(patients, amountOfPatients, "patients.txt");  //��������� ���������
		coutGreenText(DATA_BEEN_CHANGED);
	}
	else {
		coutRedText(DATA_HAS_NOT_BEEN_CHANGED);
	}
}

//������� �������������� ����� ���������� ��������
void townPatientEdit(dataPatients* patients, int amountOfPatients, int numberOfPatient, string editData) {

	editData = inputEditString(INPUT_TOWN, editData, LETTERS_SYMBOLS);   //������ ����� ������
	menuConfirmationEdit(TOWN);  //���� �������������    
	if (confirmation()) {  //���� �������� �� ��������� ������
		patients[numberOfPatient].town = editData;  //�������� ������ ������ �� �����
		savingPatients(patients, amountOfPatients, "patients.txt");  //��������� ���������
		coutGreenText(DATA_BEEN_CHANGED);
	}
	else {
		coutRedText(DATA_HAS_NOT_BEEN_CHANGED);
	}
}

//������� ������������� ������ �������� ������� ��������
void phonenumberPatientEdit(dataPatients* patients, int amountOfPatients, int numberOfPatient, string editData) {

	editData = inputEditString(INPUT_PHONE_NUMBER, editData, NUMBER_SYMBOLS);   //������ ����� ������
	menuConfirmationEdit(PHONE_NUMBER);    //���� �������������
	if (confirmation()) {  //���� �������� �� ��������� ������
		patients[numberOfPatient].phoneNumber = editData;  //�������� ������ ������ �� �����
		savingPatients(patients, amountOfPatients, "patients.txt");  //��������� ���������
		coutGreenText(DATA_BEEN_CHANGED);
	}
	else {
		coutRedText(DATA_HAS_NOT_BEEN_CHANGED);
	}
}

//������� �������������� ���� ��������
void dataOfBirthPatientEdit(dataPatients*(&patients), int &amountOfPatients, int numberOfPatient) {

	//���� ���� �������� ��������
	int day, month, year;
	while (true) { //��������� ���� ���� �� ����� ���������� ����
		  //������ ����, �����, ��� �� ������������ ��������
		cout << DAY;    cin >> day;
		cout << MONTH;  cin >> month;
		cout << YEAR;   cin >> year;
		if (validationInputData(day, month, year)) {  //���� ������ ������� ��������� � ������������ ����������� ��� �������������� ��������
			menuConfirmationEdit(DATA_OF_BIRTH);  //���� �������������    
			if (confirmation()) {  //���� �������� �� ��������� ������
				patients[numberOfPatient].dateOfBirth.day = day;
				patients[numberOfPatient].dateOfBirth.month = month;
				patients[numberOfPatient].dateOfBirth.year = year;
				savingPatients(patients, amountOfPatients, "patients.txt");  //��������� ���������
				coutGreenText(DATA_BEEN_CHANGED);
			}
			else {
				coutRedText(DATA_HAS_NOT_BEEN_CHANGED);
			}
			break;
		}
		else {  //���� ������ ������� ����������� , ��������� ����
			coutRedText(INCCORECT_INPUT_DATE_OF_BIRTH);
		}
	}
}

//������� �������������� �������� ������� ��������
void diagnosisPatientEdit(dataPatients* patients, int amountOfPatients, int numberOfPatient, string editData) {

	editData = inputEditString(INPUT_DIAGNOSIS, editData, LETTERS_SYMBOLS);   //������ ����� ������
	menuConfirmationEdit(DIAGNOSIS);   //���� �������������
	if (confirmation()) {  //���� �������� �� ��������� ������
		patients[numberOfPatient].diagnosis = editData;  //�������� ������ ������ �� �����
		savingPatients(patients, amountOfPatients, "patients.txt");  //��������� ���������
		coutGreenText(DATA_BEEN_CHANGED);
	}
	else {
		coutRedText(DATA_HAS_NOT_BEEN_CHANGED);
	}
}
//---------------------------------------------�������������� ���� ������ �����---------------------------------------------------------------


//---------------------------------------------�������������� ������� ������� ������-----------------------------------------------------------
//���� �������������� ��������
void menuAccountEdit() {
	cout << "\n\n�������� ������, ������� ������ ��������\n"
		<< "1. �����\n"
		<< "2. ������\n"
		<< "3. ����\n"
		<< "0. �����\n"
		<< "<< ";
}

//�������������� ������ ������� ������
void editAccount(account* (&accounts), int amountOfAccounts, int activeAccount) {

	printAllAccounts(accounts, amountOfAccounts);   //����� ���� ������� �������
	cout << "\n\n��� ���� , ����� ��������� ����� ������� - '0'\n������� ����� �������� �� 1 �� " << amountOfAccounts << " ������� ������ �������� << ";
	int numberEditAccount = inputNumber(BACK, amountOfAccounts);  //���� ������ ������� ������, ������� ����� �������������

	if (numberEditAccount - 1 == activeAccount) {  //���� ������� ���� �������, ������������� ������
		HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOutput, FOREGROUND_RED);
		cout << YOU_NOT_EDIT_ACCOUNT;
		SetConsoleTextAttribute(hOutput, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	else if (numberEditAccount != BACK) {  //���� �� ������� ��������� �����
		system("cls");
		numberEditAccount--;
		cout << DATA_ACCOUNT_FOR_EDIT;
		printAccount(accounts, numberEditAccount);  //����� ������ ��������� ������� ������
		menuAccountEdit();    //���� �������������� ������� ������
		int choiceAccountEdit = inputNumber(EXIT_FROM_EDIT_ACCOUNT, ROLE_EDIT);

		switch (choiceAccountEdit) {
		case EDIT_LOGIN_ACCOUNT: {   //�������������� ������
			loginEdit(accounts, amountOfAccounts, numberEditAccount);
			break;
		}
		case ACCESS_EDIT: {   //������� �������
			accessEdit(accounts, amountOfAccounts, numberEditAccount);
			break;
		}
		case ROLE_EDIT: {   //��������� ����
			roleEdit(accounts, amountOfAccounts, numberEditAccount);
			break;
		}
		case EXIT_FROM_EDIT_ACCOUNT: { //����� �� �������������� ��������
			break;
		}
		}
	}
}

//������� ��������� ������� ������� ������
void accessEdit(account* accounts, int amountOfAccounts, int numberAccount) {

	menuConfirmationEdit(ACCES);   //���� �������������
	if (confirmation()) {   //���� ��������
		if (accounts[numberAccount].access == NO_ACCESS) {   //���� ���� ��� �������
			accounts[numberAccount].access = ACCESS;     //�������� �� � ��������
		}
		else {   //���� ���� � ��������
			accounts[numberAccount].access = NO_ACCESS;    //�������� �� ��� �������
		}
		savingAccount(accounts, amountOfAccounts, "accounts.txt");   //��������� ���������
		coutGreenText(DATA_BEEN_CHANGED);
	}
	else {
		coutRedText(DATA_HAS_NOT_BEEN_CHANGED);
	}
}

//������� ��������� ���� ������� ������
void roleEdit(account* accounts, int amountOfAccounts, int numberAccount) {

	menuConfirmationEdit(ROLE);    //���� �������������
	if (confirmation()) {   //���� ��������   
		if (accounts[numberAccount].role == USER) {   //���� ��� ������������
			accounts[numberAccount].role = ADMIN;     //�������� �� ������
		}
		else {     //���� ��� �����
			accounts[numberAccount].role = USER;  //�������� �� ������������
		}
		savingAccount(accounts, amountOfAccounts, "accounts.txt"); //��������� ���������
		coutGreenText(DATA_BEEN_CHANGED);
	}
	else {
		coutRedText(DATA_HAS_NOT_BEEN_CHANGED);
	}
}

//������� ��������� ������ ������� ������
void passwordEdit(account* accounts, int amountOfAccounts, int numberOfAccount) {

	bool edit = false;
	cout << INPUT_PASSWORD<< BACK_ON_0;
	string password = inputValidationPasswordOrLogin();  //������ ������

	if (password != EXIT_FROM_INPUT) {
		cout << REPEAT_PASSWORD;
		string validationPassword = inputValidationPasswordOrLogin();

		if (validationPassword != EXIT_FROM_INPUT) {
			if (password == validationPassword) {
				menuConfirmationEdit(PASSWORD);
				if (confirmation()) {  //���� �������� �� ��������� ������
					accounts[numberOfAccount].hash = generationHashForPassword(password);  //���������� ���
					accounts[numberOfAccount].salt = generateSalt(SALT_SIZE);  //���������� ����
					savingAccount(accounts, amountOfAccounts, "accounts.txt");  //��������� ���������
					edit = true;
					coutGreenText(PASSWORD_SUCCESSFULLY_CHANGED);
				}
			}
			else {
				coutRedText(PASSWORDS_DO_NOT_MATCH);
			}
		}
	}
	if (edit == false) {
		coutRedText(PASSWORD_HAS_NOT_BEEN_CHANGED);
	}
}

//������� ��������� ������ ������� ������
void loginEdit(account* accounts, int amountOfAccounts, int numberAccount) {

	cout << INPUT_LOGIN<< BACK_ON_0;
	string login = inputValidationPasswordOrLogin();  //������ �����
	if (login != EXIT_FROM_INPUT) {   //���� �� ������� ��������� �����
		bool correct = true;   //���������� ��� �����������
		for (int numberAccount = 0; numberAccount < amountOfAccounts; numberAccount++) {
			if (accounts[numberAccount].login == login) {   //���� ����� ��� �����
				correct = false;  //�����
				coutRedText( LOGIN_IS_BUSY);
				break;
			}
		}
		if (correct == true) {  //���� ����� ������ �����
			menuConfirmationEdit(LOGIN);  //���� �������������
			if (confirmation()) {  //���� �������� �� ��������� ������
				accounts[numberAccount].login = login;  //�������� ������ ������ �� �����
				savingAccount(accounts, amountOfAccounts, "accounts.txt");  //��������� ���������
				coutGreenText(DATA_BEEN_CHANGED);
			}
			else {
				coutRedText(DATA_HAS_NOT_BEEN_CHANGED);
			}
		}
	}
}
//---------------------------------------------�������������� ������� ������� �����------------------------------------------------------------



