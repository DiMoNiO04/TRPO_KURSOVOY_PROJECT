//���������� ������������ ����
#include"SearchSort.h" 

//------------------------------------------------����� ������----------------------------------------------------------------------------------
//���� ������
void menuSearch() {
	system("cls");   
	cout << "1. ����� �� �������\n"
		<< "2. ����� �� �����\n"
		<< "3. ����� �� ��������\n"
		<< "4. ����� �� ����� ����������\n"
		<< "0. ����� �� ���� ������\n"
		<< "<< ";
}

//������� ������� ���� ������
void search(dataPatients* (&patients), int &amountOfPatients) {

	string searchString;
	bool isCountData = false;

	menuSearch();  //����� ���� ������
	int choiceSearch = inputNumber(BACK_FROM_SEARCH, SEARCH_FOR_TOWN);  //����� �������� � ���� � �������� �� ������������ �����

	switch (choiceSearch) {  //����� ����� �������� ��������� 
	case SEARCH_FOR_SURNAME: {  //����� �� �������(1)
		searchString = inputAndOutputSearchString(SURNAME, searchString);
		searchForSurname(patients, amountOfPatients, isCountData, searchString);
		break;
	}
	case SEARCH_FOR_NAME: {    //����� �� �����(2)
		searchString = inputAndOutputSearchString(NAME, searchString);
		searchForName(patients, amountOfPatients, isCountData, searchString);
		break;
	}
	case SEARCH_FOR_DIAGNOSIS: { //����� �� ��������(3)
		searchString = inputAndOutputSearchString(DIAGNOSIS, searchString);
		searchForDiagnosis(patients, amountOfPatients, isCountData, searchString);
		break;
	}
	case SEARCH_FOR_TOWN: {  //����� �� ������(5)
		searchString = inputAndOutputSearchString(TOWN, searchString);
		searchForTown(patients, amountOfPatients, isCountData, searchString);
		break;
	}
	case BACK_FROM_SEARCH: //����� (0)
		return;
	}
	system("pause");
	search(patients, amountOfPatients);
}

//���� ������� ������
string inputAndOutputSearchString(string SURNAME, string searchString) {

	system("cls");
	cout << "������� ������ " << SURNAME << " ������� ������ ����� : \n << ";
	searchString = inputValidationString(LETTERS_SYMBOLS);
	cout << setw(100) << FIND_DATA_AFTER_SEARCH;
	return searchString;
}

//����� �� �������
void searchForSurname(dataPatients* patients, int amountOfPatients, int countData, string searchString) {  //����� �� �������

	for (int numberOfPatientsSearch = 0; numberOfPatientsSearch < amountOfPatients; numberOfPatientsSearch++) {
		string str = patients[numberOfPatientsSearch].surname;  //����������� str ������ � ������� ����� ������ substr
		size_t substr = str.find(searchString);   //������������ ��� ��� ������� �������. ���� � str ������ ������ ��������� ������ ������ substr
		if (substr != string::npos) {   //���� �� ����� ������
			countData = true;     //���� ��������� ������� 
			printPatient(patients, numberOfPatientsSearch);  //����� ��������� ������ � �������
		}
	}
	reSearch(patients, amountOfPatients, countData, searchString, SURNAME, searchForSurname);  //���� ������ �� �������, ��������� �����
}

//����� �� �����
void searchForName(dataPatients* patients, int amountOfPatients, int countData, string searchString) {  //����� �� �����

	for (int numberOfPatientsSearch = 0; numberOfPatientsSearch < amountOfPatients; numberOfPatientsSearch++) {
		string str = patients[numberOfPatientsSearch].name;  //����������� str ������ � ������� ����� ������ substr
		size_t substr = str.find(searchString);   //������������ ��� ��� ������� �������. ���� � str ������ ������ ��������� ������ ������ substr
		if (substr != string::npos) {  //���� �� ����� ������
			countData = true;  //���� ��������� ������� 
			printPatient(patients,  numberOfPatientsSearch); //������� �������� � �������
		}
	}
	reSearch(patients, amountOfPatients, countData, searchString, NAME, searchForName);   //���� ������ �� �������, ��������� �����
}

//����� �� ��������
void searchForDiagnosis(dataPatients* patients, int amountOfPatients, int countData, string searchString) {  //����� �� ��������

	for (int numberOfPatientsSearch = 0; numberOfPatientsSearch < amountOfPatients; numberOfPatientsSearch++) {
		string str = patients[numberOfPatientsSearch].diagnosis;  //����������� str ������ � ������� ����� ������ substr
		size_t substr = str.find(searchString);   //������������ ��� ��� ������� �������. ���� � str ������ ������ ��������� ������ ������ substr
		if (substr != string::npos) {  //���� �� ����� ������
			countData = true;    //���� ��������� �������
			printPatient(patients, numberOfPatientsSearch);  //����� �������� � �������
		}
	}
	reSearch(patients, amountOfPatients, countData, searchString, DIAGNOSIS, searchForDiagnosis);    //���� ������ �� �������, ��������� �����
}

//����� �� ����� ����������
void searchForTown(dataPatients* patients, int amountOfPatients, int countData, string searchString) {  //����� �� ����� ����������

	for (int numberOfPatientsSearch = 0; numberOfPatientsSearch < amountOfPatients; numberOfPatientsSearch++) {
		string str = patients[numberOfPatientsSearch].town;  //����������� str ������ � ������� ����� ������ substr
		size_t substr = str.find(searchString); //������������ ��� ��� ������� �������. ���� � str ������ ������ ��������� ������ ������ substr
		if (substr != string::npos) {  //���� �� ����� ������
			countData++;  //���� ��������� �������
			printPatient(patients, numberOfPatientsSearch);   //����� �������� � �������
		}
	}
	reSearch(patients, amountOfPatients, countData, searchString, TOWN, searchForDiagnosis);   //���� ������ �� �������, ��������� �����
}

//��������� �����
void reSearch(dataPatients* patients, int amountOfPatients, int countData, string searchString, string SURNAME, void searchForSurname(dataPatients* patients, int amountOfPatients, int contData, string searchString)) { //��������� �����
	
	if (countData == false) {   //���� ������ �� �������
		coutBlueText( DATA_NOT_FOUND);
		int continueOrBack = inputNumber(BACK_TO_SEARCH_MENU, CONTINUE);  //�������� ���������� ����� ��� ��������� � ���� � ��������� �� ���������� ����
		if (continueOrBack == CONTINUE) {  //���� ������� ���������
			searchString = inputAndOutputSearchString(SURNAME, searchString);
			searchForSurname(patients, amountOfPatients, countData, searchString);  //�������� ������� ������ 
		}
	}
}
//----------------------------------------------------����� �����-----------------------------------------------------------------------------


//-------------------------------------------------���������� ������---------------------------------------------------------------------------
//���� ����������
void menuSort() {
	system("cls");     
	cout << "1. ���������� �� �������\n"
		<< "2. ���������� �� �����\n"
		<< "3. ���������� �� ��������\n"
		<< "4. ���������� �� ����� ����������\n"
		<< "0. ����� �� ���� ����������\n"
		<< "<< ";
}

//������� ������� ����������
void sort(dataPatients* (&patients), int &amountOfPatients) {

	menuSort();  //����� ���� ����������
	int choiceSort = inputNumber(BACK_FROM_SORT, SORT_FOR_TOWN);  //����� �������� � ���� � �������� �� ������������ �����
	system("cls");

	switch (choiceSort) {  //����� ����� �������� ��������� 
	case SORT_FOR_SURNAME: {  //���������� �� �������(1)
		sortForSurnameOrNameOrTown(patients, amountOfPatients, choiceSort, SURNAME, isSortForSurnameAscending, isSortForSurnameDescending);
		break;
	}
	case SORT_FOR_NAME: {    //���������� �� �����(2)
		sortForSurnameOrNameOrTown(patients, amountOfPatients, choiceSort, NAME, isSortForNameAscending, isSortForNameDescending);
		break;
	}
	case SORT_FOR_AGE: { //���������� �� ��������(3)
		sortForAge(patients, amountOfPatients, choiceSort);
		break;
	}
	case SORT_FOR_TOWN: {  //���������� �� ����� ����������(5)
		sortForSurnameOrNameOrTown(patients, amountOfPatients, choiceSort, TOWN, isSortForTownAscending, isSortForTownDescending);
		break;
	}
	case BACK_FROM_SORT: //����� (0)
		return;
	}
	system("pause");
	sort(patients, amountOfPatients);
}

//���������� �� �������,�����, ����� ���������
void sortForSurnameOrNameOrTown(dataPatients* patients, int amountOfPatients, int choiceSort, string SURNAME, bool isSortForSurnameAscending(dataPatients patients, dataPatients patientsPlus), bool isSortForSurnameDescending(dataPatients patients, dataPatients patientsPlus)) {

	cout << "���������� ������ �� " << SURNAME << ":\n1.�� � �� �\n2.�� � �� �\n0.�����\n << ";
	int sortSelection = inputNumber(BACK, DESCENDING);  //����� ���� ���������� � �������� �� ���������� ����
	system("cls");

	if (sortSelection == ASCENDING) {   //���� �� � �� �
		sort(patients, patients + amountOfPatients, isSortForSurnameAscending);  //���������� �� � �� �
		cout << setw(80) << "�������� ������������� �� " << SURNAME << "(A - �)\n";
		printAllPatients(patients, amountOfPatients);   //����� ��������������� ������ ���������
	}
	else if (sortSelection == DESCENDING) {  //���� �� � �� �
		sort(patients, patients + amountOfPatients, isSortForSurnameDescending);  //���������� �� � �� �
		cout << setw(80) << "�������� ������������� �� " << SURNAME << "(� - �)\n";
		printAllPatients(patients, amountOfPatients);    //����� ��������������� ������ ���������
	}
}

//���������� �� ��������
void sortForAge(dataPatients* patients, int amountOfPatients, int choiceSort) {

	cout << MENU_SORT_FOR_AGE;
	int sortSelection = inputNumber(BACK, DESCENDING);  //����� ���� ���������� � �������� �� ���������� ����
	system("cls");   //������� �������

	if (sortSelection == ASCENDING) {   //���� ����� �� �����������
		sort(patients, patients + amountOfPatients, isSortForDayAscending);   // ������� 
		sort(patients, patients + amountOfPatients, isSortForMonthAscending); // ����������
		sort(patients, patients + amountOfPatients, isSortForYearAscending);  //�������� �� �����������
		cout << setw(80) << SORT_FOR_AGE_ASCENDING;
		printAllPatients(patients, amountOfPatients);   //����� ���� ��������������� ������ � �������
	}
	else if (sortSelection == DESCENDING) {   //���� �� ����� �� ��������
		sort(patients, patients + amountOfPatients, isSortForDayDescending);  //�������
		sort(patients, patients + amountOfPatients, isSortForMonthDescending);//���������
		sort(patients, patients + amountOfPatients, isSortForYearDescending); //�������� �� ��������
		cout << setw(80) << SORT_FOR_AGE_DESCENDING;
		printAllPatients(patients, amountOfPatients);  //����� ���� ��������������� ������ � �������
	}
}

//----------------------------------------������� ���������� �� ... ������---------------------------------------------------------------------
bool isSortForSurnameAscending(dataPatients patients, dataPatients patientsPlus) {     //���������� �� ������� �� � �� �
	return patients.surname < patientsPlus.surname;                                    //���������� ������������, ���������� ����� �������� ������-������
}
bool isSortForSurnameDescending(dataPatients patients, dataPatients patientsPlus) {    //���������� �� ������� �� � �� �
	return patients.surname > patientsPlus.surname;                                    //���������� ������������, ���������� ����� �������� ������-������
}
bool isSortForNameAscending(dataPatients patients, dataPatients patientsPlus) {        //���������� �� ����� �� � �� �
	return patients.name < patientsPlus.name;                                          //���������� ������������, ���������� ����� �������� ������-������
}
bool isSortForNameDescending(dataPatients patients, dataPatients patientsPlus) {       //���������� �� ����� �� � �� �
	return patients.name > patientsPlus.name;                                          //���������� ������������, ���������� ����� �������� ������-������
}
bool isSortForTownDescending(dataPatients patients, dataPatients patientsPlus) {       //���������� �� ����� ���������� �� � �� �
	return patients.town < patientsPlus.town;                                          //���������� ������������, ���������� ����� �������� ������-������
}
bool isSortForTownAscending(dataPatients patients, dataPatients patientsPlus) {        //���������� �� ����� ���������� �� � �� �
	return patients.town > patientsPlus.town;                                          //���������� ������������, ���������� ����� �������� ������-������
}
bool isSortForYearDescending(dataPatients patients, dataPatients patientsPlus) {       //���������� ���� �������� �� ��������
	return patients.dateOfBirth.year < patientsPlus.dateOfBirth.year;                  //���������� ������������, ���������� ����� �������� ������-������
}
bool isSortForYearAscending(dataPatients patients, dataPatients patientsPlus) {        //���������� ���� �������� �� �����������
	return patients.dateOfBirth.year > patientsPlus.dateOfBirth.year;                  //���������� ������������, ���������� ����� �������� ������-������
}
bool isSortForMonthDescending(dataPatients patients, dataPatients patientsPlus) {      //���������� ������ �������� �� ��������
	return patients.dateOfBirth.month < patientsPlus.dateOfBirth.month;                //���������� ������������, ���������� ����� �������� ������-������
}
bool isSortForMonthAscending(dataPatients patients, dataPatients patientsPlus) {       //���������� ������ �������� �� �����������
	return patients.dateOfBirth.month > patientsPlus.dateOfBirth.month;                //���������� ������������, ���������� ����� �������� ������-������
}
bool isSortForDayDescending(dataPatients patients, dataPatients patientsPlus) {        //���������� ��� �������� �� ��������
	return patients.dateOfBirth.day < patientsPlus.dateOfBirth.day;                    //���������� ������������, ���������� ����� �������� ������-������
}
bool isSortForDayAscending(dataPatients patients, dataPatients patientsPlus) {         //���������� ��� �������� �� �����������
	return patients.dateOfBirth.day > patientsPlus.dateOfBirth.day;                    //���������� ������������, ���������� ����� �������� ������-������
}
//----------------------------------------------������� ���������� �� .... �����--------------------------------------------------------------
//----------------------------------------------------------���������� �����-------------------------------------------------------------------


//------------------------------------------------------------���������� ������ ������---------------------------------------------------------
//���� ����������
void menuFiltration() {
	system("cls"); 
	cout << "1. ���������� �� ����\n"
		<< "2. ���������� �� �������� � ��������\n"
		<< "0. ����� �� ���� ����������\n"
		<< "<< ";
}

//����� ���� ��� ����������
void menuFiltratonForGender() {
	cout << "1. ������� ��������� �������� ����\n"
		<<"2. ������� ��������� �������� ����\n"
		<<"0. �����\n"
		<<"<< ";
}

//������� ������� ����������
void filtration(dataPatients* (&patients), int &amountOfPatients) {

	menuFiltration();  //����� ���� ����������
	int choiceFiltr = inputNumber(BACK_FROM_FILTR, FILTR_FOR_AGE_AND_DIAGNOSIS); //����� ���� ���������� � ���������� ����
	system("cls");

	switch (choiceFiltr) {  //����� ����� �������� ��������� 
	case FILTR_FOR_GENDER: {  //���������� �� ����
		filtrationForGender(patients, amountOfPatients);
		break;
	}
	case FILTR_FOR_AGE_AND_DIAGNOSIS: {    //���������� �� �������� � ��������
		filtrationForAgeAndDiagnosis(patients, amountOfPatients);
		break;
	}
	case BACK_FROM_FILTR: //����� (0)
		return;
	}
}

//���������� �� ����
void filtrationForGender(dataPatients* patients, int amountOfPatients) {

	menuFiltratonForGender();   //���� ���������� �� ����
	int choiceFiltrGender = inputNumber(BACK, WOMAN_GENDER);  //�������� ��� ��� ����������
	if (choiceFiltrGender == MAN_GENDER) {   //���� ������� ���
		filtrForGender(patients, amountOfPatients, choiceFiltrGender, MAN_GENDER, MAN);  //������� ������
	}
	else if (choiceFiltrGender == WOMAN_GENDER) {   //���� ������� ���
		filtrForGender(patients, amountOfPatients, choiceFiltrGender, WOMAN_GENDER, WOMAN);   //������� ������
	}
}
void filtrForGender(dataPatients* patients, int amountOfPatients, int choiceFiltrGender, int MAN_GENDER, string MAN) {

	bool correct = false;  //��� �������� ���� �� �������� � ����� �����
	cout << setw(60) << "�������� " << MAN << " ����:\n";
	for (int numberPatient = 0; numberPatient < amountOfPatients; numberPatient++) {
		if (patients[numberPatient].gender == MAN) {
			correct = true;
			printPatient(patients, numberPatient);
		}
	}
	if (correct == false) {   //��������� � ����� ��������� ����� ���
		coutBlueText(NO_PATIENTS_GENDER);
	}
}

//���������� �� �������� � ��������
void filtrationForAgeAndDiagnosis(dataPatients* patients, int amountOfPatients) {  

	//������������� �������� ����
	SYSTEMTIME st;
	GetLocalTime(&st);
	cout << st.wDay << " " << st.wMonth << " " << st.wYear << endl;

	cout << WHO_AGE_AND_DIAGNOSIS;
	cout << "������ << ";   //������ ������� , ������� ����� �����
	int filtrAge = inputNumber(MIN_AGE, MAX_AGE);
	cout << "������� << ";  //������ ������� , ������� ����� �����
	string filtrDiagnosis = inputValidationString(LETTERS_SYMBOLS);
	cout << "\n�������� ������ " << filtrAge << " ��� � � ��������� " << filtrDiagnosis << ":\n";
	filtrForAgeAndDiagnosis(patients, amountOfPatients, filtrAge, filtrDiagnosis, st);
}
void filtrForAgeAndDiagnosis(dataPatients* patients, int amountOfPatients, int filtrAge, string filtrDiagnosis, SYSTEMTIME st) {

	int patientAge, patientMonth, patientDay;
	bool isCountData = false;
	//����������� ������ ���������� ��� � ���������
	for (int numberPatient = 0; numberPatient < amountOfPatients; numberPatient++) {
		patientAge = st.wYear - patients[numberPatient].dateOfBirth.year;
		patientMonth = st.wMonth - patients[numberPatient].dateOfBirth.month;
		patientDay = st.wDay - patients[numberPatient].dateOfBirth.day;
		if (patientMonth < 0 || patientDay < 0) patientAge = patientAge - 1;
		if (patientMonth < 0 && patientDay <= 0) patientMonth = 12 + patientMonth - 1;
		if (patientMonth < 0 && patientDay > 0) patientMonth = 12 + patientMonth;
		if (patientMonth >= 0 && patientDay < 0) patientDay = patients[numberPatient].dateOfBirth.day + patientDay;
		if (filtrAge <= patientAge && filtrDiagnosis == patients[numberPatient].diagnosis) {
			isCountData = true;
			printPatient(patients, numberPatient);  //����� ������ �������� � �������
		}
	}
	if (isCountData == false) {
		coutRedText(SEARCH_NOT_FOUND);
	}
}
//-----------------------------------------------------------���������� ������ �����-----------------------------------------------------------
