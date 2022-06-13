#pragma once
//���������� ������������ �����
#include"Functions.h"
#include "Autorization.h"
#include"Const.h"

//���� ������
enum searchMenu {
	BACK_FROM_SEARCH,     //����� �� ���� ������
	SEARCH_FOR_SURNAME,   //����� �� �������
	SEARCH_FOR_NAME,      //����� �� �����
	SEARCH_FOR_DIAGNOSIS, //����� �� ��������
	SEARCH_FOR_TOWN,      //����� �� ����� ����������
};

//���� ����������
enum sortMenu {
	BACK_FROM_SORT,    //����� �� ���� ����������
	SORT_FOR_SURNAME,  //���������� �� �������
	SORT_FOR_NAME,     //���������� �� �����
	SORT_FOR_AGE,      //���������� �� ��������
	SORT_FOR_TOWN      //���������� �� ����� ����������
};

//���� ����������
enum filtrationMenu {
	BACK_FROM_FILTR,             //����� �� ���� ����������
	FILTR_FOR_GENDER,            //���������� �� ����
	FILTR_FOR_AGE_AND_DIAGNOSIS  //���������� �� �������� � ��������
};


//----------------------------------------------------����� ������-----------------------------------------------------------------------------
//���� ������
void menuSearch();

//������� ������� ���� ������
void search(dataPatients* (&patients), int &amountOfPatients);

//���� ������� ������
string inputAndOutputSearchString(string SURNAME, string searchString);

//����� �� �������
void searchForSurname(dataPatients* patients, int amountOfPatients, int countData, string searchString);

//����� �� �����
void searchForName(dataPatients* patients, int amountOfPatients, int countData, string searchString);

//����� �� ��������
void searchForDiagnosis(dataPatients* patients, int amountOfPatients, int countData, string searchString);

//����� �� ����� ����������
void searchForTown(dataPatients* patients, int amountOfPatients, int countData, string searchString);

//��������� �����
void reSearch(dataPatients* patients, int amountOfPatients, int countData, string searchString, string SURNAME, void searchForSurname(dataPatients* patients, int amountOfPatients, int contData, string searchString));
//-----------------------------------------------------------����� �����----------------------------------------------------------------------- 


//------------------------------------------------------------C���������� �����----------------------------------------------------------------
//���� ����������
void menuSort();

//������� ������� ����������
void sort(dataPatients* (&patients), int &amountOfPatients);

//���������� �� �������,�����, ����� ���������
void sortForSurnameOrNameOrTown(dataPatients* patients, int amountOfPatients, int choiceSort, string SURNAME, bool isSortForSurnameAscending(dataPatients patients, dataPatients patientsPlus), bool isSortForSurnameDescending(dataPatients patients, dataPatients patientsPlus));

//���������� �� ��������
void sortForAge(dataPatients* patients, int amountOfPatients, int choiceSort);

//----------------------------------------------������� ���������� �� .... ������--------------------------------------------------------------
bool isSortForSurnameAscending(dataPatients patients, dataPatients patientsPlus);   //���������� �� ������� �� � �� �
bool isSortForSurnameDescending(dataPatients patients, dataPatients patientsPlus);  //���������� �� ������� �� � �� �
bool isSortForNameAscending(dataPatients patients, dataPatients patientsPlus);      //���������� �� ����� �� � �� �
bool isSortForNameDescending(dataPatients patients, dataPatients patientsPlus);     //���������� �� ����� �� � �� �
bool isSortForTownDescending(dataPatients patients, dataPatients patientsPlus);     //���������� �� ����� ���������� �� � �� �
bool isSortForTownAscending(dataPatients patients, dataPatients patientsPlus);      //���������� �� ����� ���������� �� � �� �
bool isSortForYearDescending(dataPatients patients, dataPatients patientsPlus);     //���������� ���� �������� �� ��������
bool isSortForYearAscending(dataPatients patients, dataPatients patientsPlus);      //���������� ���� �������� �� �����������
bool isSortForMonthDescending(dataPatients patients, dataPatients patientsPlus);    //���������� ������ �������� �� ��������
bool isSortForMonthAscending(dataPatients patients, dataPatients patientsPlus);     //���������� ������ �������� �� ����������
bool isSortForDayDescending(dataPatients patients, dataPatients patientsPlus);      //���������� ��� �������� �� ��������
bool isSortForDayAscending(dataPatients patients, dataPatients patientsPlus);       //���������� ��� �������� �� �����������
//---------------------------------------------������� ���������� �� .... �����----------------------------------------------------------------
//----------------------------------------------------���������� �����-------------------------------------------------------------------------


//-------------------------------------------------------------���������� ������---------------------------------------------------------------
//���� ����������
void menuFiltration();

//���� ������ ���������� �� ����
void menuFiltratonForGender();

//������� ������� ����������
void filtration(dataPatients* (&patients), int &amountOfPatients);

//���������� �� ����
void filtrForGender(dataPatients* patients, int amountOfPatients, int choiceFiltrGender, int MAN_GENDER, string MAN);
void filtrationForGender(dataPatients* patients, int amountOfPatients);

//���������� �� �������� � ��������
void filtrationForAgeAndDiagnosis(dataPatients* patients, int amountOfPatients);
void filtrForAgeAndDiagnosis(dataPatients* patients, int amountOfPatients, int filtrAge, string filtrDiagnosis, SYSTEMTIME st);
//--------------------------------------------------------------���������� �����---------------------------------------------------------------
