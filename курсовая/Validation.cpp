//���������� ������������ ����
#include "Validation.h"


 //���� � �������� �� ���������� ����
int inputNumber(int left_range, int right_range) {

	int number;   //����� �������
	while (true) { //��������� ���� ���� �� ����� ���������� ����
		cin >> number;  //������ ����� 
		if (isNumberNumeric() && isNumberRangeCorrect(number, left_range, right_range)) {  //���� ������ ������� ���������
			return number;   //���������� ����� ��������� ��������
		}
		else {  //���� ������ ������� ����������� , ��������� ����
			coutRedText(INCORRECT_INPUT);
		}
	}
}
bool isNumberNumeric() {

	if (cin.get() == '\n') {  //��� ���� ����� �������, ������� ��������� ������ �� �������� ������ ������
		return true;
	}
	else {
		cin.clear();   //���������� ���� ������, � �������� ������ ����� �in �� ���������
		cin.ignore(256, '\n'); //������� ������(����������� ������������ ����� ��������, ������� ����� �������� �����, �� ������� �������� ������ ������������)
		return false;
	}
}

//�������� ������ ������� , ���������� ��� ������� ������
bool isNumberRangeCorrect(int number, int left_range, int right_range) {

	if ((number >= left_range) && (number <= right_range)) {    //���� ������ � ���������� �������
		return true;  //���������� ������
	}
	else {    //���� �� ������ � ���������� ������� 
		return false;  //��������� ����
	}
}

//�������� �������� ���� ��������
bool validationInputData(int day, int month, int year) {

	//�������� �������� ���� �������� �� ������������ ��������
	if (day < BORDER_DAYS_START || month < JANUARY || month > BORDER_MONTH_END)
		return false;
	else if (month == FEBRUARY && day > FEBRUARURY_DAYS)
		return false;
	else if ((month == JANUARY || month == MARCH || month == MAY || month == JULY || month == AUGUST || month == OCTOBER || month == DECEMBER) && day > FULL_MONTH)
		return false;
	else if ((month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER) && day > NO_FULL_MONTH)
		return false;
	else if (year < BORDER_YEAR_START || year >= BORDER_YEAR_END)
		return false;
	else
		return true;
}

int inputday(int left_range, int right_range) {

	int number;   //����� �������
	while (true) { //��������� ���� ���� �� ����� ���������� ����
		cin >> number;  //������ ����� 
		if (isNumberNumeric() && isNumberRangeCorrect(number, left_range, right_range)) {  //���� ������ ������� ���������
			return number;   //���������� ����� ��������� ��������
		}
		else {  //���� ������ ������� ����������� , ��������� ����
			coutRedText(INCORRECT_INPUT);
		}
	}
}

//������� ����� ������ � ������ ��� �����������
string inputPassword() {
	
	string password;  //������
	int ch = 0;
	while (true) {
		ch = _getch(); //��������� � ���������� ������������ , �� �� ����������

		if (ch == KEY_ENTER) {  //���� �������� ENTER, ��������� ����
			break;
		}
		else if (ch == KEY_DELETE) { //���� �������� DELETE
			cout << (char)KEY_DELETE << " " << (char)KEY_DELETE;//��� ������� delete  ������� ��������� � �������
			if (!password.empty()) {  //���� ������ �� ������
				password.erase(password.length() - 1); //������� �� ������ password  � ������� � �������� ����� ������-1
			}
		}
		else {  //��� ����� ���������� ��������
			cout << "*";
			password = password + (char)ch; //�������� �� ���������
		}
	}
	return password;
}


//-----------------------------------------------------����������� ������� �����---------------------------------------------------------------
//������� ��������� ����
string generateSalt(int salt_size){

	string symbols = getSymbolsForSalt();
	srand(time(NULL));
	string salt;
	salt.reserve(salt_size);

	for (int i = 0; i < salt_size; i++)
	{
		salt.push_back(symbols[rand() % SYMBOLS_SIZE]);
	}
	return salt;
}

//������� ������������ ������ ��������
string getSymbolsForSalt(){

	string symbols;
	symbols.reserve(SYMBOLS_SIZE);

	char little_letter = 'a';
	char big_letter = 'A';
	char number = '0';
	int i = 0;
	for (int k = 0; k < 26; k++){
		symbols.push_back(little_letter++);
		symbols.push_back(big_letter++);
		if (k < 10) symbols.push_back(number++);
	}
	return symbols;
}

//������� ���������� ���� ��� ������
string generationHashForPassword(string password) {

	string salt = generateSalt(SALT_SIZE); // ���������� ����

	string hash = sha256(sha256(password) + sha256(password));
	return hash;
}
//----------------------------------------------------����������� ������� �����---------------------------------------------------------------


//---------------------------------------------------�������� �� ���������� ������� � ������ � ������ �����------------------------------------
//�������� �� ���������� ���� ������ � ������
string inputValidationPasswordOrLogin() {

	string editPassword;
	while (true) {
		cin >> editPassword;  //������ ������
		if (isLoginPasswordRangeCorrect(editPassword)) {  //���� ������ ������� ���������
			return editPassword;   //���������� ������
		}
		else {  //���� ������ ������� ����������� , ��������� ����
			coutRedText(INCORRECT_INPUT);
		}
	}
}

//�������� �� ���� ������������ ��������
bool isLoginPasswordRangeCorrect(string editData) {

	size_t found = editData.find_first_not_of("QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890"); //������� ������� ����� ��������
	if (editData != EXIT_FROM_INPUT) {  //���� �� ������� ��� �����
		if (found != string::npos || editData.length() < MIN_SYMBOLS_FOR_INPUT) {
			return false;
		}
		else {    //���� �� ������ � ���������� ������� 
			return true;  //��������� ����
		}
	}
}
//--------------------------------------------------�������� �� ���������� ������� � ������ � ������ �����-------------------------------------

//���������� ���� ������
string inputValidationString(string SYMBOLS) {
	
	string str;
	while (true) { //��������� ���� ���� �� ����� ���������� ����
		getline(cin, str);
		if (isStringRangeCorrect(str, SYMBOLS)) {  //���� ������ ������� ���������
			return str;
		}
		else {  //���� ������ ������� ����������� , ��������� ����
			coutRedText(INCORRECT_INPUT);
		}
	}
}

//���������� ���� ������
bool isStringRangeCorrect(string str, string SYMBOLS) {

	size_t found = str.find_first_not_of(SYMBOLS); //������� ������� ����� ��������
	if (SYMBOLS == NUMBER_SYMBOLS) {
		if (str.length() != 13 && str.length() != 11) {
			return false;
		}
	}
	if (found != string::npos) {
		return false;
	}
	else {    //���� �� ������ � ���������� ������� 
		return true;  //��������� ����
	}
}

//������������� ��������
int confirmation() {

	int confirmation = inputNumber(YES, NO);  //�������� �� ��� ���
	if (confirmation == YES) {   //���� �� 
		return true;
	}
	else {   //���� ���
		return false;
	}
}
