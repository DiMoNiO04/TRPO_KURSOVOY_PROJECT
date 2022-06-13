#pragma once
//���������� ������������ ����
#include"Functions.h"


const int
CONTINUE = 1,       //�����������
DESCENDING = 2,     //�� ��������
BACK = 0,           //�����
ASCENDING = 1,      //�� �����������
MAN_GENDER = 1,     //������� ���
WOMAN_GENDER = 2,   //������� ���
MIN_AGE = 0,        //����������� ������� ��� ������
MAX_AGE = 99,       //������������ ������ ��� ������
SALT_SIZE = 16,     // ����� ����
SYMBOLS_SIZE = 62,  // ����� ��������, �� ������� ������������ ����
MIN_SYMBOLS_FOR_INPUT = 4,  //������� �������� ��������
RESERVE_AMOUNT_OF_ACCOUNTS = 100,  //������ ���������� ���������
RESERVE_AMOUNT_OF_PATIENT = 1000,  //������ ���������� ���������
JANUARY = 1,               //������
FEBRUARY = 2,              //�������
MARCH = 3,                 //����
APRIL = 4,                 //������
MAY = 5,                   //���  
JUNE = 6,                  //����
JULY = 7,                  //����
AUGUST = 8,                //������
SEPTEMBER = 9,             //��������
OCTOBER = 10,              //�������
NOVEMBER = 11,             //������
DECEMBER = 12,             //�������
BORDER_DAYS_START = 1,     //�������� ������� ����
BORDER_DAYS_END = 31,      //�������� ������� ����
BORDER_MONTH_START = 1,    //��������� ������� �������
BORDER_MONTH_END = 12,     //�������� ������� �������
BORDER_YEAR_END = 2023,    //�������� ������� �����
BORDER_YEAR_START = 1920,  //��������� ������� �����
YES = 1,                   //��
NO = 2,                    //���
FEBRUARURY_DAYS = 28,      //��������� ���� �������
FULL_MONTH = 31,           //����� � 31 ����
NO_FULL_MONTH = 30,        //����� � 30 �����
BACK_TO_SEARCH_MENU = 0,   //������� � ���� ������
REPEAT = 1,                //�����������
BACK_TO_ADMIN_MENU = 0,    //������� � ���� ������
KEY_ENTER = 13,            //������� ENTER
KEY_DELETE = 8,            //������� DELETE
REGISTRATION = 3,          //������� � ������������
FIRST_PATIENT =1,
DATA_EMPTY = 0;            //������ �� �������

const string
BACK_TO_AUTORIZATION = "0",
NO_PATIENTS = "\n��������� ���\n",
PATIENTS_NO = "� ������ ����� ���� ����� ���� ����������, �.�. ��������� ���\n",
ADMIN_MAIN = "mainAdmin",            
MAN = "�������",
WOMAN = "�������",
NOACCESS = "0",
ACCOUNTS = "��������:\n",
USER_FUNCTIONALITY = "�� ���������� � ����������� ������������\n\n",
ADMIN_FUNCTIONALITY = "�� ���������� � ����������� ��������������\n\n",
MAIN_ADMIN_FUNCTIONALITY = "�� ���������� � ����������� �������� ��������������\n\n",
DATA_IS_EMPTY = "������ �����!\n",
CONFIRMATION_EXIT_FROM_ACCOUNT = "�� �������, ��� ������ ����� �� �������� ? \n1.��\n2.���\n << ",
EXIT_FROM_PROGRAM = "�� ����� �� ���������\n����� �������!\n",
ACCOUNT = "�������",
PATIENT = "�������",
DATA_NOT_ADD = "������� �� ��� ��������\n",
LOGIN_AND_PASSWORD_INPUT = "������� ��� ����� � ������ ��� ��������� ����� - '0'\n",
LOGIN_INPUT = "����� << ",
PASSWORD_INPUT = "������ << ",
INCORRECT_LOGIN_AND_PASSWORD_INPUT = "������� ������ ����� ��� ������\n��������� ����\n\n",
ACCESS = "1",
NO_ACCESS = "0",
ADMIN = "admin",
USER = "user",
LOGIN_IS_BUSY = "������������ � ����� ������� ��� ����������\n",
REPEAT_PASSWORD = "��������� ���� ������\n<< ",
INPUT_PASSWORD = "\n������� ������ ��������� �� 0 - 9, A - Z, a - z,  >6 ��������\n<< ",
INPUT_LOGIN = "\n������� ����� ��������� �� 0 - 9, A - Z, a - z,  >6 ��������\n<< ",
BACK_ON_0 = " 0.��������� �����\n\n",
INPUT_REPEAT_PASSWORD = "��������� ������\n << ",
INPUT_DATA_FOR_REGIST = "��������� ������:\n",
PASSWORD_SUCCESSFULLY_CHANGED = "������ ������� �������\n",
PASSWORDS_DO_NOT_MATCH = "������ �� ���������\n",
PASSWORD_HAS_NOT_BEEN_CHANGED = "������ �� ��� �������\n",
INPUT_SURNAME = "\n������� �������: \n<< ",
INPUT_NAME = "\n������� ���: \n<< ",
INPUT_PATRONYMIC = "\n������� ��������: \n<< ",
INPUT_GENDER = "\n�������� ���: \n<< ",
INPUT_DATA_OF_BIRTH = "\n������� ���� ��������\n<< ",
INPUT_TOWN = "\n������� ����� ����������: \n<< ",
INPUT_PHONE_NUMBER = "\n������� ����� ��������: \n<< ",
INPUT_DIAGNOSIS = "\n������� �������: \n<< ",
DATA_HAS_NOT_BEEN_CHANGED = "������ �� ���� ��������\n\n",
LETTERS_SYMBOLS = "����������������������������������������������������������������-",
LOGIN_LETTERS_SYMBOLS = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm",
FIND_DATA_AFTER_SEARCH = "\n��������� ������ �� ������ ������ : \n",
WHO_AGE_AND_DIAGNOSIS = "������� ������ ������� ��� ������ ������� ��������� � � ����� ���������?\n",
SURNAME = "�������",
PATRONYMIC = "��������",
GENDER = "���",
PHONE_NUMBER = "����� ��������",
NAME = "�����",
TOWN = "����� ����������",
DIAGNOSIS = "��������",
DATA_NOT_FOUND = "\n������ �� ������ ������ �� ������� ��� ���������� �������.\n 1. ��������� ������ �����\n0. ��������� � ���� ������:\n<< ",
NUMBER_SYMBOLS = "+0123456789",
NO_NONRESIDENT = "�����",
ALL_PATIENTS = "��� ��������\n",
EXIT_FROM_INPUT = "0",
LOGIN = "�����",
PASSWORD = "������",
INCORRECT_INPUT = "������������ ����!\n��������� ������� � ������� ���������� ������\n<< ",
INPUT_DATA = "��������� ������:\n",
INPUT_ADD_SURNAME = "������� << ",
INPUT_ADD_NAME = "��� << ",
INPUT_ADD_PATRONYMIC = "�������� << ",
INPUT_ADD_GENDER = "��� << ",
INPUT_ADD_DATE_BIRTH = "���� ��������:\n",
INPUT_ADD_TOWN = "����� ���������� << ",
INPUT_ADD_PHONE = "����� �������� << ",
INPUT_ADD_DIAGNOSIS = "������� << ",
DATA_HAS_ADD = "������ ���������\n",
DATA_NOT_HAS_ADD = "������ �� ���� ���������\n",
CONFIRMATION_ADD = "�� ������� ��� ������ �������� ������ \n1.��\n2.���\n<<",
INCORRECT_DATA_OF_BIRTH = "������� ������� ���� ��������. ��������� ����\n",
PATIENT_DELETE = "������� ������\n",
PATIENT_NOT_DELETE = "������� �� ��� ������\n",
ACCOUNT_DELETE = "������� ������\n",
ACCOUNT_NOT_DELETE = "������� �� ��� ������\n",
CONFIRMATION_DELETE_ACCOUNT = "�� ������� , ��� ������ ������� ���� �������?\n1.��\n2.���\n<< ",
CONFIRMATION_DELETE_PATIENT = "�� ������� , ��� ������ ������� ����� ��������?\n1.��\n2.���\n<< ",
NO_ACTIVATION_ACCOUNTS = "\n���������������� ��������:\n",
WHAT_ACCOUNT_ACTIVATION = "\n����� ������� ������ ������������ << ",
CONFIRMATION_ACTIVATION = "\n�� �������, ��� ������ ������������ ������ �������?\n1. ��\n2. ���\n<< ",
CONFIRMATION_BLOCKING = "\n�� �������, ��� ������ ������������� ������ �������?\n1. ��\n2. ���\n<< ",
ACTIVATION_REQUESTS = "������ �� ���������:\n",
BLOCKING_REQUESTS = "������ �� ����������:\n",
ACCOUNT_NOT_ACTIVATED = "������ �������� �� ��� �����������\n\n",
ENTER_APPLICATION_NUMBER = "\n�������� ����� ������ ��� ��������� << ",
ENTER_FOR_BLOCKING = "\n�������� ����� ������ ��� ���������� << ",
ACCOUNT_ACTIVATED = "\n������� �����������\n\n",
ACCOUNT_BLOCKING = "\n������� ������������\n\n",
NO_APPLICATION_REQUESTS = "������ �� ��������� �������� ���\n\n",
NO_BLOCK_REQUESTS = "������ �� ���������� �������� ���\n\n",
ACCES = "������",
ROLE = "����",
DATA_BEEN_CHANGED = "������ ��������\n",
DATA_ACCOUNT_FOR_EDIT = "������ �������� ������� ������ ��������\n",
YOU_NOT_EDIT_ACCOUNT = "�� �� ������ ��������������� ���� �������\n",
CONFIRMATION_EXIT_FROM_PROGRAM =  "�� �������, ��� ������ ����� �� ���������?\n1. ��\n2. ���\n<< ",
SORT_FOR_AGE_DESCENDING = "�������� ������������� �� ��������(99-0)\n",
SORT_FOR_AGE_ASCENDING = "�������� ������������� �� ��������(0-99)\n",
MENU_SORT_FOR_AGE = "���������� ������ �� ��������:\n1. �� �����������\n2. �� ��������\n0. �����\n<< ",
ERROR_OPEN_FAIL =  "������ �������� �����\n\n",
WITH_ACCESS = "� ��������",
WITHOUT_ACCESS = "��� �������",
NOT_DELETE_MAIN_ADMIN = "\n�� �� ������ ������� ���� ������� �������� ��������������\n",
MENU_CONFIRMATION_REGISTRATION = "�� ������� ��� ������ ������������������ \n1.��\n2.���\n<<",
PASSWORDS_DO_MOT_MATCH = "\n������ �� ���������\n",
YOU_ARE_REGISTERED = "\n���� ������ �� ����������� ���������� �� ������������ ��������������\n",
INCCORECT_INPUT_DATE_OF_BIRTH = "���� �������� �� ������������ ������������. ��������� ������� � ������� ���������� ������\n",
DAY = "\n���� << ",
MONTH = "����� << ",
YEAR = "��� << ",
YOU_CANNOT_BLOCK_YOUR_ACCOUNT = "�� �� ������ ������������� ���� �������\n",
YOU_CANNOT_DISABLE_MAIN_ADMIN = "�� �� ������ ������������� ������� �������� ��������������\n",
ACCOUNT_NOT_BLOCKED = "������� �� ��� ������������\n",
REGISTR_AS_MAIN_ADMIN = "C������� ���������� ���� � �������� �������� ��� ����� ����������������� � �������� �������� ������",
SEARCH_NOT_FOUND = "�� ������ ������� ������ �� �������, ��������� ������������ �������� ������\n\n",
DATA_OF_BIRTH = " ���� �������� ",
YOU_HAVE_CREATED_FILE_AND_REGISTERED_MAIN_ADMIN = "�� ������� ���� � �������� �������� � ������������������ � �������� �������� ��������������\n",
NOT_NONRESIDENT_PATIENTS = "����������� ��������� ���\n\n",
NO_PATIENTS_GENDER = "��������� � ��������� ��������� ����� ���\n",
NONRESIDENT_PATIENTS = "����������� ��������\n\n";
