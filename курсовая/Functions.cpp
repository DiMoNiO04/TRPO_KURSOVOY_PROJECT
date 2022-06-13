//���������� ������������ ����
#include"Functions.h"   
#include"Validation.h"
#include"Const.h"


//---------------------------------------------------������� ������ � �������� �������� �����-------------------------------------------------
//�������� ����� ������� �������
void openingFileAccounts(account* (&accounts), int& amountOfAccounts, string fileAccounts) {

	ifstream reading(fileAccounts); //����� ��� ������ �� �����
	if (!reading.is_open()) {  //���� ����� � �������� �������� ����. �������������� � �������� �������� ������
		cout << REGISTR_AS_MAIN_ADMIN;
		cout << INPUT_LOGIN;              string newLogin = inputValidationPasswordOrLogin();
		cout << INPUT_PASSWORD;           string newPassword = inputValidationPasswordOrLogin();
		cout << INPUT_REPEAT_PASSWORD;    string repeatNewPassword = inputValidationPasswordOrLogin();
		amountOfAccounts++;                   //���������� ���������� ������� ������� � ��������� �� 1
		accounts[amountOfAccounts - 1].login = newLogin;
		accounts[amountOfAccounts - 1].role = ADMIN_MAIN;
		accounts[amountOfAccounts - 1].access = ACCESS;
		accounts[amountOfAccounts - 1].hash = generationHashForPassword(newPassword);
		accounts[amountOfAccounts - 1].salt = generateSalt(SALT_SIZE);
		savingAccount(accounts, amountOfAccounts, fileAccounts);   //���������� ��������� � ����
		coutYellowText(YOU_HAVE_CREATED_FILE_AND_REGISTERED_MAIN_ADMIN);
		system("pause");
	}
	else { //���� ���� � �������� �������� ����
		readingFileAccounts(accounts, amountOfAccounts, fileAccounts);//��������� ������ �� ����� � ������
	}
	reading.close();  //��������� ����
}

//���������� ������� ������� � ������
void readingFileAccounts(account*(&accounts), int &amountOfAccounts, string fileAccounts){

	ifstream reading(fileAccounts);
	int numberAccount = 0;
	while (!reading.eof()) {  //���� ���� �� ������
		if (numberAccount < RESERVE_AMOUNT_OF_ACCOUNTS) {
			reading >> accounts[numberAccount].login   //��������� ������
				>> accounts[numberAccount].hash
				>> accounts[numberAccount].salt
				>> accounts[numberAccount].role
				>> accounts[numberAccount].access;
			if (accounts[numberAccount].login.empty()) {
				break;
			}
			numberAccount++;  //������� ���������� ������� ������� 
		}
	}
	amountOfAccounts = numberAccount;  //���������� ���������
	reading.close();
}

//��������� ������� ������
void savingAccount(account* accounts, int amountOfAccounts, string fileName) {

	ofstream record(fileName, ios::out); //������� ����� ��� ������, ��������� ���� � ������ ��� ������
	if (record) {  //���� ���� ��������

		//���������� ������ � ����
		for (int numberAccount = 0; numberAccount < amountOfAccounts; numberAccount++) {
			record << accounts[numberAccount].login << "  "
				<< accounts[numberAccount].hash << "  "
				<< accounts[numberAccount].salt << " "
				<< accounts[numberAccount].role << " ";
			if (numberAccount < amountOfAccounts - 1) { //���� ������� �� ��������� ������ ������ �� ���� �������
				record << accounts[numberAccount].access << endl;
			}
			else {  //���� ������ ��������� ������ ������ �� ���� �������
				record << accounts[numberAccount].access;
			}
		}
	}
	else {  //���� ���� �� ��������
		coutRedText( ERROR_OPEN_FAIL);
	}
	record.close();  //��������� ����
}

//����� ���� ������� �������
void printAllAccounts(account* accounts, int amountOfAccounts) {

	system("cls");
	cout << setw(60); coutYellowText(ACCOUNTS);
	cout << setw(17)<<"�����:" << setw(10) << "����:" << setw(14) << "������:\n";
	for (int numberAccount = 0; numberAccount < amountOfAccounts; numberAccount++) {
		cout << "\n������ �" << numberAccount + 1 << ": ";
		printAccount(accounts, numberAccount);
	}
	cout << endl;
}

//����� ����� ������� ������
void printAccount(account* accounts, int numberAccount) {
	
	cout << left << setw(10) << accounts[numberAccount].login << setw(10) << accounts[numberAccount].role;
	if (accounts[numberAccount].access == ACCESS) {
		cout << setw(10) << WITH_ACCESS;
	}
	else {
		cout << setw(10) << WITHOUT_ACCESS;
	}
	cout << endl;
}

//����� �� ��������
void exitFromAccount(account* (&accounts), int &amountOfAccounts, int activeAccount, dataPatients* (&patients), int &amountOfPatients, void user(account*(&accounts), int &amountOfAccounts, int activeAccount, dataPatients* (&patients), int &amountOfPatients)) {
	
	system("cls");
	cout << CONFIRMATION_EXIT_FROM_ACCOUNT;
	if (confirmation()) {  //���� �������� �� ����� �� ��������
		autorization(accounts, amountOfAccounts, patients, amountOfPatients);
	}
	else {
		user(accounts, amountOfAccounts, activeAccount, patients, amountOfPatients);
	}
}

//�������� ��������
void deleteAccounts(account* (&accounts), int& amountOfAccounts, int activeAccount, dataPatients*(&patients), int& amountOfPatients) {  //�������� ������ �� ������, ���� ������� �����. �������� ������

	printAllAccounts(accounts, amountOfAccounts);    //����� ���� ������� �������
	cout << "\n\n��� ���� , ����� ��������� ����� ������� - '0'\n������� ����� �������� �� 1 �� " << amountOfAccounts << " �������� ������ ������� << ";
	int numberDeleteAccount = inputNumber(BACK, amountOfAccounts);  //���� ������ ������� , ������� ������ �������

	if (numberDeleteAccount == BACK) {   //���� ��������� �����
		return;
	}
	else if (numberDeleteAccount == activeAccount + 1) {  //���� ������� ���� �������
		coutRedText( NOT_DELETE_MAIN_ADMIN);
		return;
	}
	else {
		cout << CONFIRMATION_DELETE_ACCOUNT;
		if (confirmation()) {   //���� �������� �� �������� ������� ������
			numberDeleteAccount--;   //��������� �� 1
			for (int numberOfAccount = numberDeleteAccount; numberOfAccount < amountOfAccounts - 1; numberOfAccount++) {
				accounts[numberOfAccount] = accounts[numberOfAccount + 1];
			}
			amountOfAccounts--;   //��������� ���������� ���������
			savingAccount(accounts, amountOfAccounts, "accounts.txt");   //��������� ���������
			coutGreenText(ACCOUNT_DELETE);
		}
		else {
			coutRedText(ACCOUNT_NOT_DELETE);
		}
	}
}

//����������� ���������
void copyAccount(account* (&accountsNew), account* (accountsOld), int amountOfAccounts) { //�������� ��� �������

	for (int numberAccount = 0; numberAccount < amountOfAccounts; numberAccount++) {
		accountsNew[numberAccount] = accountsOld[numberAccount];  //������ ������� ������� , ����������� � ����� ������
	}
}

//��������� ������ �� ��������� ��������
void activationAccount(account* (&accounts), int& amountOfAccounts, int activeAccount) {

	int amountOfAccountNoActivation = accountsWithoutAccess(accounts, amountOfAccounts);  //���������� ��������� ��� �������
	account* accountsWithAccess = createArrOfAccountsWithoutAccess(accounts, amountOfAccounts, amountOfAccountNoActivation);  //�������� ������� ��������� ��� �������

	if (amountOfAccountNoActivation != DATA_EMPTY) {   
		printAccountsForConfirmAdd(accounts, amountOfAccounts);   //����� ����� �� �����������
		confirmApplication(accounts, accountsWithAccess, amountOfAccounts, amountOfAccountNoActivation, activeAccount);  //������� ������ ��������� ������
	}
	else {   //�������� �� ������� ������
		coutBlueText( NO_APPLICATION_REQUESTS);
	}
}
void confirmApplication(account* (&accounts), account* (&accountsWithAccess), int amountOfAccounts, int amountOfAccountNoActivation, int activeAccount) {

	cout << ENTER_APPLICATION_NUMBER;
	int numberApplication = inputNumber(BACK, amountOfAccountNoActivation);  //����� ������ ������ ��� ���������

	if (numberApplication == BACK) {     //���� ��������� �����
		return;
	}
	else {
		coutBlueText(CONFIRMATION_ACTIVATION);
		if (confirmation()) {  //���� �������� �� ��������� ��������
			numberApplication--;  //��������� �� 1
			for (int numberAccount = 0; numberAccount < amountOfAccounts; numberAccount++) {
				if (accounts[numberAccount].login == accountsWithAccess[numberApplication].login) {
					accounts[numberAccount].access = ACCESS;  //������ �� ������
					break;
				}
			}
			coutGreenText( ACCOUNT_ACTIVATED);
			savingAccount(accounts, amountOfAccounts, "accounts.txt");
		}
		else {
			coutRedText(ACCOUNT_NOT_ACTIVATED);
		}
	}
}

//������� ��������� ��� �������
int accountsWithoutAccess(account* (&accounts), int amountOfAccounts) {

	int amountOfAccountNoActivation = DATA_EMPTY;   //������������ ���������� �������� ��������� ��� �������
	for (int numberAccount = 0; numberAccount < amountOfAccounts; numberAccount++) {  
		if (accounts[numberAccount].access == NO_ACCESS) {  //�������� �� ������ ��������
			amountOfAccountNoActivation++;  //���������� ��������� ��� �������
		}
	}
	return  amountOfAccountNoActivation;   //���������� ���������� ��������� ��� �������
}

//������ ��������� ��� ������� � ��������� ������
account* createArrOfAccountsWithoutAccess(account* (&accounts), int amountOfAccounts, int amountOfAccountNoActivation) {

	account* accountsWithAccess = new account[amountOfAccountNoActivation];  //�������� ������ ��� ����� ������
	amountOfAccountNoActivation = DATA_EMPTY;     //������������� �������� ��������� ��� �������
	for (int numberAccount = 0; numberAccount < amountOfAccounts; numberAccount++) {
		if (accounts[numberAccount].access == NO_ACCESS) {  //�������� �� ������ ��������
			accountsWithAccess[amountOfAccountNoActivation].login = accounts[numberAccount].login;  //������������ ������ � ����� ������
			amountOfAccountNoActivation++;  //����������� ���������� ��������� ��� �������
		}
	}
	return accountsWithAccess;  //���������� ��������� �� ������ ��������� ��� �������
}

//����� ���������� �� ������� �������
void printAccountsForConfirmAdd(account* (&accounts), int amountOfAccounts) {

	system("cls");
	cout << BACK_ON_0;
	coutYellowText(ACTIVATION_REQUESTS);
	cout << setw(17) << "�����:" << setw(10) << "����:" << setw(14) << "������:\n";
	int amountOfAccountNoActivation = DATA_EMPTY;  //������������� ���������� �������� ��������� ��� �������
	for (int numberAccount = 0; numberAccount < amountOfAccounts; numberAccount++) {
		if (accounts[numberAccount].access == NO_ACCESS) {   //�������� �� ������ �������� � ����� ������� ������
			amountOfAccountNoActivation++;    //���������� ��������� ��� �������
			cout << "������ �" << amountOfAccountNoActivation << ": ";
			printAccount(accounts, numberAccount);
		}
	}
}

//���������� ������ �� ��������� ��������
void blockingAccount(account* (&accounts), int& amountOfAccounts, int activeAccount) {

	int amountOfAccountWithActivation = accountsWithoAccess(accounts, amountOfAccounts);  //���������� ��������� ��� �������
	account* accountsWithAccess = createArrOfAccountsWithAccess(accounts, amountOfAccounts, amountOfAccountWithActivation);  //�������� ������� ��������� ��� �������

	if (amountOfAccountWithActivation != DATA_EMPTY) {
		printAccountsForConfirmBlocking(accounts, amountOfAccounts);   //����� ����� �� �����������
		confirmBlocking(accounts, accountsWithAccess, amountOfAccounts, amountOfAccountWithActivation, activeAccount);  //������� ������ ��������� ������
	}
	else {   //�������� �� ������� ������
		coutBlueText(NO_BLOCK_REQUESTS);
	}
}
void confirmBlocking(account* (&accounts), account* (&accountsWithAccess), int amountOfAccounts, int amountOfAccountWithActivation, int activeAccount) {

	coutBlueText(ENTER_FOR_BLOCKING);
	int numberApplication = inputNumber(BACK, amountOfAccountWithActivation);  //����� ������ ������ ��� ���������

	if (numberApplication == BACK) {     //���� ��������� �����
		return;
	}
	else if (accounts[numberApplication - 1].login == accounts[activeAccount].login) {  //���� �� ������ ������������� ���� ��������
		coutRedText( YOU_CANNOT_BLOCK_YOUR_ACCOUNT);
		return;
	}
	else if (accounts[numberApplication - 1].role == ADMIN_MAIN) {   //���� ������ ������������� �������� ������
		coutRedText( YOU_CANNOT_DISABLE_MAIN_ADMIN);
		return;
	}
	else {
		coutBlueText(CONFIRMATION_BLOCKING);
		if (confirmation()) {  //���� �������� �� ��������� ��������
			numberApplication--;  //��������� �� 1
			for (int numberAccount = 0; numberAccount < amountOfAccounts; numberAccount++) {
				if (accounts[numberAccount].login == accountsWithAccess[numberApplication].login) {
					accounts[numberAccount].access = NO_ACCESS;  //������ �� ������
					break;
				}
			}
			coutGreenText(ACCOUNT_BLOCKING);
			savingAccount(accounts, amountOfAccounts, "accounts.txt");
		}
		else {
			coutRedText( ACCOUNT_NOT_BLOCKED);
		}
	}
}

//������� ��������� � �������
int accountsWithoAccess(account* (&accounts), int amountOfAccounts) {

	int amountOfAccountWithActivation = DATA_EMPTY;   //������������ ���������� �������� ��������� ��� �������
	for (int numberAccount = 0; numberAccount < amountOfAccounts; numberAccount++) {
		if (accounts[numberAccount].access == ACCESS) {  //�������� �� ������ ��������
			amountOfAccountWithActivation++;  //���������� ��������� ��� �������
		}
	}
	return  amountOfAccountWithActivation;   //���������� ���������� ��������� ��� �������
}

//������ ��������� � �������� � ��������� ������
account* createArrOfAccountsWithAccess(account* (&accounts), int amountOfAccounts, int amountOfAccountWithActivation) {

	account* accountsWithAccess = new account[amountOfAccountWithActivation];  //�������� ������ ��� ����� ������
	amountOfAccountWithActivation = DATA_EMPTY;     //������������� �������� ��������� ��� �������
	for (int numberAccount = 0; numberAccount < amountOfAccounts; numberAccount++) {
		if (accounts[numberAccount].access == ACCESS) {  //�������� �� ������ ��������
			accountsWithAccess[amountOfAccountWithActivation].login = accounts[numberAccount].login;  //������������ ������ � ����� ������
			amountOfAccountWithActivation++;  //����������� ���������� ��������� ��� �������
		}
	}
	return accountsWithAccess;  //���������� ��������� �� ������ ��������� ��� �������
}

//����� ���������� ������� �������
void printAccountsForConfirmBlocking(account* (&accounts), int amountOfAccounts) {

	system("cls");
	cout << BACK_ON_0;
	coutYellowText(BLOCKING_REQUESTS);
	cout <<endl<< setw(17) << "�����:" << setw(10) << "����:" << setw(14) << "������:\n";
	int amountOfAccountNoActivation = DATA_EMPTY;  //������������� ���������� �������� ��������� ��� �������
	for (int numberAccount = 0; numberAccount < amountOfAccounts; numberAccount++) {
		if (accounts[numberAccount].access == ACCESS) {   //�������� �� ������ �������� � ����� ������� ������
			amountOfAccountNoActivation++;    //���������� ��������� ��� �������
			cout << "������ �" << amountOfAccountNoActivation << ": ";
			printAccount(accounts, numberAccount);
		}
	}
}
//----------------------------------------------------������� ������ � �������� �������� �����-------------------------------------------------



//---------------------------------------------------������� ������ ������� ��������� ������------------------------------------------------------
//������ ������ ��������� � ���������
void openingFilePatients(dataPatients* (&patients), int& amountOfPatients, string fileName) {

	ifstream reading(fileName); //����� ��� ������ �� �����
	int numberPatients = 0;
	while (!reading.eof()) {    //���� ���� �� ������
		if (numberPatients < RESERVE_AMOUNT_OF_PATIENT) {
			reading >> patients[numberPatients].surname
				>> patients[numberPatients].name
				>> patients[numberPatients].patronymic
				>> patients[numberPatients].gender
				>> patients[numberPatients].dateOfBirth.day
				>> patients[numberPatients].dateOfBirth.month
				>> patients[numberPatients].dateOfBirth.year
				>> patients[numberPatients].town
				>> patients[numberPatients].phoneNumber
				>> patients[numberPatients].diagnosis;
			if (patients[numberPatients].surname.empty()) {
				break;
			}
			numberPatients++;   //������� ���������� ���������
		}
	}
	amountOfPatients = numberPatients;  //����������� ���������� ���������
	reading.close();  //��������� ����
}

//���������� ��������
void addPatient(dataPatients* (&patients), int& amountOfPatients) {

	//������� ����� ��������� ������
	dataPatients* buf;
	buf = new dataPatients[amountOfPatients];
	copy(buf, patients, amountOfPatients);

	//��������� ���������� ���������
	amountOfPatients++;
	patients = new dataPatients[amountOfPatients];
	copy(patients, buf, --amountOfPatients);

	//��������� ������ ��� ����������
	system("cls");
	cout << INPUT_DATA;
	cout << INPUT_ADD_SURNAME;        patients[amountOfPatients].surname = inputValidationString(LETTERS_SYMBOLS);
	cout << INPUT_ADD_NAME;           patients[amountOfPatients].name = inputValidationString(LETTERS_SYMBOLS);
	cout << INPUT_ADD_PATRONYMIC;     patients[amountOfPatients].patronymic = inputValidationString(LETTERS_SYMBOLS);
	cout << INPUT_ADD_GENDER;         patients[amountOfPatients].gender = inputValidationString(LETTERS_SYMBOLS);
	cout << INPUT_ADD_DATE_BIRTH;     inputDateOfBirth(patients, amountOfPatients); cin.ignore();
	cout << INPUT_ADD_TOWN;           patients[amountOfPatients].town = inputValidationString(LETTERS_SYMBOLS);
	cout << INPUT_ADD_PHONE;          patients[amountOfPatients].phoneNumber = inputValidationString(NUMBER_SYMBOLS);
	cout << INPUT_ADD_DIAGNOSIS;      patients[amountOfPatients].diagnosis = inputValidationString(LETTERS_SYMBOLS);

	cout << CONFIRMATION_ADD;
	if (confirmation()) {   //���� �������� �� ���������� ��������
		amountOfPatients++;   //����������� ���������� ���������
		savingPatients(patients, amountOfPatients, "patients.txt");   //��������� ���������
		coutGreenText(DATA_HAS_ADD);
	}
	else {
		coutRedText(DATA_NOT_HAS_ADD);
	}
	delete[]buf;  //������� ��������� ������
}

//���� ���� ��������
void inputDateOfBirth(dataPatients*(&patients), int amountOfPatients) {
	//���� ���� �������� ��������
	int day, month, year;
	while (true) { //��������� ���� ���� �� ����� ���������� ����
		  //������ ����, �����, ��� �� ������������ ��������
		cout << DAY;    cin >> day;
		cout << MONTH;  cin >> month;
		cout << YEAR;   cin >> year;
		if (validationInputData(day, month, year)) {  //���� ������ ������� ��������� � ������������ ����������� ��� �������������� ��������
			patients[amountOfPatients].dateOfBirth.day = day;
			patients[amountOfPatients].dateOfBirth.month = month;
			patients[amountOfPatients].dateOfBirth.year = year;
			break;
		}
		else {  //���� ������ ������� ����������� , ��������� ����
			coutRedText( INCCORECT_INPUT_DATE_OF_BIRTH);
		}
	}
}

//���������� �������� , ����������� ������ ���������
void copy(dataPatients* (&patientstNew), dataPatients* (patientsOld), int amountOfPatients) {

	for (int numberPatient = 0; numberPatient < amountOfPatients; numberPatient++) {
		patientstNew[numberPatient] = patientsOld[numberPatient];  //������ ������� ������� , ����������� � ����� ������
	}
}

//�������� ������ ��������� � ����
void savingPatients(dataPatients * patients, int amountOfPatients, string fileName) {

	ofstream record(fileName, ios::out); //������� ����� ��� ������, ��������� ���� � ������ ��� ������
	if (record) {  //���� ���� ��������

		//���������� ������ � ����
		for (int numberPatient = 0; numberPatient < amountOfPatients; numberPatient++) {
			record << patients[numberPatient].surname << "  "
				<< patients[numberPatient].name << "  "
				<< patients[numberPatient].patronymic << "  "
				<< patients[numberPatient].gender << "  "
				<< patients[numberPatient].dateOfBirth.day << " "
				<< patients[numberPatient].dateOfBirth.month << " "
				<< patients[numberPatient].dateOfBirth.year << "  "
				<< patients[numberPatient].town << "  "
				<< patients[numberPatient].phoneNumber << " ";

			if (numberPatient < amountOfPatients - 1) { //���� ������� �� ��������� ������ ������ �� ���� �������
				record << patients[numberPatient].diagnosis << endl;
			}
			else {  //���� ������ ��������� ������ ������ �� ���� �������
				record << patients[numberPatient].diagnosis;
			}
		}
	}
	else {  //���� ���� �� ��������
		coutRedText(ERROR_OPEN_FAIL);
	}
	record.close();  //��������� ����
}

//�������� ��������
void deletePatient(dataPatients* (&patients), int& amountOfPatients) {

	printAllPatients(patients, amountOfPatients);  //����� ���� ���������
	cout << "\n\n��� ���� , ����� ��������� ����� ������� - '0'\n������� ����� �������� �� 1 �� " << amountOfPatients << " �������� ������ ������� << ";
	int numberDeletePatient = inputNumber(BACK, amountOfPatients);  //���� ������ ������� , ������� ������ �������

	if (numberDeletePatient == BACK) {  //���� ������� ��������� �����
		return;
	}
	else {
		cout << CONFIRMATION_DELETE_PATIENT;
		if (confirmation()) {   //���� ������������ ��������
			numberDeletePatient--;  //��������� ����� ��������
			for (int numberOfPatient = numberDeletePatient; numberOfPatient < amountOfPatients - 1; numberOfPatient++) {
				patients[numberOfPatient] = patients[numberOfPatient + 1];
			}
			amountOfPatients--;  //��������� ��������� ���������
			savingPatients(patients, amountOfPatients, "patients.txt");   //��������� ���������
			coutGreenText(PATIENT_DELETE);
		}
		else {
			coutRedText(PATIENT_NOT_DELETE);
		}
	}
}

//����� ���� ������ � �������
void printAllPatients(dataPatients* (&patients), int& amountOfPatients) {

	printShapka();
	for (int numberPatient = 0; numberPatient < amountOfPatients; numberPatient++) {  //������� ��� ������ � �������
		cout << "������ � " << numberPatient + 1 << ": ";
		printPatient(patients, numberPatient);  //����� �� ������ �������� � �������
	}
}

//����� �����
void printShapka() {

	cout << setw(100) << "�������� �4 ��������� �������� �.������\n\n\n";
	cout << setw(40) << "���" << setw(35) << "���" << setw(24) << "���� ��������" << setw(20) << "����� ����������" <<
		setw(18) << "����� ��������" << setw(15) << "�������\n" << endl;
}

//����� ���� ��������� ���������
void printNonresidentPatients(dataPatients* patients, int amountOfData) {

	bool correct = false;  //��� �������� ������� �� ���������� ��������
	cout << setw(100); coutYellowText(NONRESIDENT_PATIENTS);
	printShapka();
	for (int numberPatient = 0; numberPatient < amountOfData; numberPatient++) {
		if (patients[numberPatient].town != NO_NONRESIDENT) {  //���� ����� �����������
			correct = true;
			cout << "������ �" << numberPatient + 1 << ": ";
			printPatient(patients, numberPatient);  //����� ������ �������� � �������
		}
	}
	if (correct == false) {   //���� ��� ����������� ���������
		coutBlueText(NOT_NONRESIDENT_PATIENTS);
	}
}

//����� ������ ������ ��������
void printPatient(dataPatients* patients, int numberPatient) {

	cout <<setw(15)<< patients[numberPatient].surname << setw(16) << patients[numberPatient].name << setw(20) << patients[numberPatient].patronymic << setw(15) << patients[numberPatient].gender<<setw(10);
	if (patients[numberPatient].dateOfBirth.day < 10) {
		cout << "0" << patients[numberPatient].dateOfBirth.day << ".";
	}
	else {
		cout << patients[numberPatient].dateOfBirth.day << ".";
	}
	if (patients[numberPatient].dateOfBirth.month < 10) {
		cout << "0" << patients[numberPatient].dateOfBirth.month << ".";
	}
	else {
		cout << patients[numberPatient].dateOfBirth.month << ".";
	}
	cout << patients[numberPatient].dateOfBirth.year << setw(18) << patients[numberPatient].town << setw(18) << patients[numberPatient].phoneNumber << setw(18) << patients[numberPatient].diagnosis << endl;

	cout << "____________________________________________________________________________________________________________________________________________________________________" << endl;

}
//---------------------------------------------------������� ������ � ������� ��������� �����-------------------------------------------------------


//--------------------------------------------------������� ��������� ����� ������ ������-----------------------------------------------------
//������� ���� ������
void coutRedText(string LOGIN_IS_BUSY) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	cout << LOGIN_IS_BUSY;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

//������� ���� ������
void coutGreenText(string LOGIN_IS_BUSY) {
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << LOGIN_IS_BUSY;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

//������� ���� ������
void coutBlueText(string LOGIN_IS_BUSY) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	cout << LOGIN_IS_BUSY;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

//������ ���� ������
void coutYellowText(string LOGIN_IS_BUSY) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);
	cout << LOGIN_IS_BUSY;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
//--------------------------------------------------������� ��������� ����� ������ ������-----------------------------------------------------

