//���������� ������������ ����
#include "Autorization.h" 

//������� ���� �����������
void mainMenu() {
    system("cls");
    cout << "1. �����\n"
        << "2. ������������������\n"
        << "0. �����\n"
        << "<< ";
}

//������� �����������
void autorization(account*(&accounts), int &amountOfAccounts, dataPatients*(&patients), int &amountOfPatients) {

    mainMenu();           //������� ���� �����������
    int choiceMain = inputNumber(EXIT, REGISTR);  //����� �������� ����������� � �������� �� ���������� ����
    system("cls");

    switch (choiceMain) { //�������� ����� �� �������� ����
    case ENTRANCE: {    //����
        entrance(accounts, amountOfAccounts, patients, amountOfPatients);
        break;
    }
    case REGISTR: {  //�����������
        registration(accounts, amountOfAccounts, patients, amountOfPatients);
        break;
    }
    case EXIT: {  //����� �� ��������
        exitFromProgram(accounts, amountOfAccounts, patients, amountOfPatients);
        break;
    }
    }
}

//������� ��������� ����� � ������ 
int checkLoginAndPasswordForEntrance(account* (&accounts), int &amountOfAccounts, string hash, string validationLogin, dataPatients* (&patients), int &amountOfPatients) {

    bool input = false;  //��� �������� �� ���������� ���� ��� ����� � �������
    for (int numberOfAccount = 0; numberOfAccount < amountOfAccounts; numberOfAccount++) {
        if (validationLogin == accounts[numberOfAccount].login && accounts[numberOfAccount].hash == hash && accounts[numberOfAccount].access == ACCESS) {  //������� �������� ������ � �������������
            if (accounts[numberOfAccount].role == USER) {  //���� ������ ������������
                user(accounts, amountOfAccounts, numberOfAccount, patients, amountOfPatients);
                input = true;  //�����
                break;
            }
            if (accounts[numberOfAccount].role == ADMIN) { //���� ������ ��������������
                input = true;  //�����
                admin(accounts,amountOfAccounts, numberOfAccount, patients, amountOfPatients);   //�������� ���������� �������������
                break;
            }
            if (accounts[numberOfAccount].role == ADMIN_MAIN) { //���� ������ �������� ��������������
                input = true;  //�����
                mainAdmin(accounts, amountOfAccounts, numberOfAccount, patients, amountOfPatients);   //�������� ���������� �������� ������
                break;
            }
            int activeAccount = numberOfAccount;  //����� �������� ��� ������� �����
            return activeAccount;  //���������� ����� ��������� ��������
        }
    }
    if (input == false) {  //���� ���� �� ��������
        system("cls");
        coutRedText(INCORRECT_LOGIN_AND_PASSWORD_INPUT);
        entrance(accounts, amountOfAccounts, patients, amountOfPatients);
    }
}

//������� ����� � �������
void entrance(account* (&accounts), int &amountOfAccounts,dataPatients*(&patients), int &amountOfPatients) {

    cout << LOGIN_AND_PASSWORD_INPUT;
    cout << LOGIN_INPUT; 
    string validationLogin; cin >> validationLogin;  //������ �����

    if (validationLogin == BACK_TO_AUTORIZATION) {  //���� ��������� �����
        autorization(accounts, amountOfAccounts, patients, amountOfPatients);  //���� �����������;
    }
    else {
        cout << PASSWORD_INPUT;
        string validationPassword = inputPassword();   //������ ������ � ������ ���� �����������
        string hash = generationHashForPassword(validationPassword);  //�������� ������
        checkLoginAndPasswordForEntrance(accounts, amountOfAccounts, hash, validationLogin, patients, amountOfPatients);  //������� �����
    }
}

//����� �� ���������
void exitFromProgram(account* (&accounts), int &amountOfAccounts, dataPatients*(&patients), int &amountOfPatients) {

    system("cls");
    cout << CONFIRMATION_EXIT_FROM_PROGRAM;
    if (confirmation()) {
        system("cls");
        cout << EXIT_FROM_PROGRAM;
        system("pause");
        return;
    }
    else {
        autorization(accounts, amountOfAccounts, patients, amountOfPatients);
    }
}

//�����������
void registration(account* (&accounts), int& amountOfAccounts, dataPatients* (&patients), int& amountOfPatients) {

    //������� ����� ��������� ������ � ��������� ���������� ���������
    account* buf;
    buf = new account[amountOfAccounts];
    copyAccount(buf, accounts, amountOfAccounts);
    amountOfAccounts++;
    accounts = new account[amountOfAccounts];
    copyAccount(accounts, buf, --amountOfAccounts);

    //��������� ������ ��� ����������
    cout << INPUT_DATA_FOR_REGIST;
    cout << INPUT_LOGIN;              string newLogin = inputValidationPasswordOrLogin();
    cout << INPUT_PASSWORD;           string newPassword = inputValidationPasswordOrLogin();
    cout << INPUT_REPEAT_PASSWORD;    string repeatNewPassword = inputValidationPasswordOrLogin();

    bool regist = true;   //���������� ��� �����������
    for (int numberAccount = 0; numberAccount < amountOfAccounts; numberAccount++) {
        if (accounts[numberAccount].login == newLogin) {   //���� ����� ��� �����
            regist = false;  //�����
            coutRedText(LOGIN_IS_BUSY);
            break;
        }
    }

    //������� �� ���������� ���� ������
    if (newPassword != repeatNewPassword) {
        coutRedText( PASSWORDS_DO_MOT_MATCH);
        regist = false;
    }

    else if (regist == true) {  //���� ������ ������� ������
        cout << MENU_CONFIRMATION_REGISTRATION;
        int confirmation = inputNumber(YES, NO); //������������� �������� � �������� �� ���������� ����
        if (confirmation == YES) {  //���� ��� , �� �� ���������
            amountOfAccounts++;                   //���������� ���������� ��������� � ��������� �� 1
            accounts[amountOfAccounts - 1].login = newLogin;
            accounts[amountOfAccounts - 1].role = USER;
            accounts[amountOfAccounts - 1].access = NOACCESS;
            accounts[amountOfAccounts - 1].hash = generationHashForPassword(newPassword);
            accounts[amountOfAccounts - 1].salt = generateSalt(SALT_SIZE);
            savingAccount(accounts, amountOfAccounts, "accounts.txt"); //���������� ��������� � ����
            coutGreenText(YOU_ARE_REGISTERED);
        }
    }
    delete[]buf;      //������� ��������� ������
    system("pause");
    autorization(accounts,amountOfAccounts, patients,amountOfPatients);
}
