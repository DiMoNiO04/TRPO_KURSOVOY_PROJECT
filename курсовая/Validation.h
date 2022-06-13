#pragma once  //������ �� ���������� ��������� ����������� ���������� �������������
//���������� ������������ �����     
#include "Autorization.h"
#include "Sha256.h"
#include <conio.h>
#include"Functions.h"
#include"Const.h"


//���� � �������� �� ���������� ����
int inputNumber(int left_range, int right_range);  
bool isNumberNumeric();

//�������� ������ ������� , ���������� ��� ������� ������
bool isNumberRangeCorrect(int number, int left_range, int right_range);

//�������� �������� ���� ��������
bool validationInputData(int day, int month, int year);

//������ �����������
string inputPassword();

//���������� ���� ������
bool isStringRangeCorrect(string str, string SYMBOLS);
string inputValidationString(string SYMBOLS);

//������� �������������
int confirmation();


//---------------------------------------------������� ����������� �����-----------------------------------------------------------------------
// ������� ��������� ����
string generateSalt(int salt_size);
// ������� ������������ ������ ��������
string getSymbolsForSalt();
//��������� ����
string generationHashForPassword(string password);
//---------------------------------------------������� ����������� �����-----------------------------------------------------------------------


//---------------------------------------------�������� �� ���������� ������ � ������ � ������ �����-------------------------------------------
//�������� �� ���������� ���� ������ � ������
string inputValidationPasswordOrLogin();
//�������� �� ���� ������������ ��������
bool isLoginPasswordRangeCorrect(string edit);
//----------------------------------------------�������� �� ���������� ������� � ������ � ������ �����-----------------------------------------
