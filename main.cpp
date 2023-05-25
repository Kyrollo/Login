#include<iostream>
#include <regex>
#include<string>
#include <fstream>
#include <conio.h>

using namespace std;

fstream file, file_IDs;
string pass, re_pass, New_pass;

void display_menu()
{
    cout << "\n" << "can you tell me what you want to do: " << "\n" << "1-New Register" << "\n" << "2-Login" << "\n" << "3-Change Password" << "\n" << "4-Exit" << "\n";
}

void files()
{
    //creat a file to add passwords.
    ofstream file;
    file.open("passwords.txt", ios::app);
    file.close();
    //creat a file to add ids.
    ofstream file_IDs;
    file_IDs.open("IDs.txt", ios::app);
    file_IDs.close();
    //creat a file to add emails.
    ofstream file_emails;
    file_emails.open("Emails.txt", ios::app);
    file_emails.close();
    //creat a file to add phone numbers.
    ofstream file_phones;
    file_phones.open("phones.txt", ios::app);
    file_phones.close();
}

string check_username(string& user_name) {
    fstream file;
    string search_username;
    char character_of_file;
    file.open("IDs.txt", ios::in);
    if (file.fail())
    {
        ofstream file("IDs.txt");
    }
    while (!file.eof()) {
        //Read file char by char
        file.get(character_of_file);
        //If the character of files is space or tab or new line
        if (character_of_file == '\n' || character_of_file == ' ') {
            //Check the word read by char equal the word the user want search
            if (search_username == user_name) {
                //Found the word
                cout << "\n" << "Error: The user name you entered is already taken." << "\n" << "Please write another" << "\n";
                cout << "please enter your user name: ";
                cin >> user_name;
                user_name = check_username(user_name);
            }
            //The word end so clear the string
            search_username.clear();
        }
        else {
            //Store the word read by char in string
            search_username.push_back(character_of_file);
        }
    }
    return user_name;

}

string new_register() {
    string user_name;
    cout << "please enter your user name: ";
    cin >> user_name;
    user_name = check_username(user_name);
    for (char letter : user_name)
    {
        if (!(isupper(letter)) && (!(islower(letter))) && (letter != 45))
        {
            new_register();
        }
    }
    //store id
    /*
    file.open("IDs.txt", ios::app);
    if (file.is_open())
    {
        file << user_name << "\n";
        file.close();
    }*/
    return user_name;
}

string check_email(string& email)
{
    fstream file;
    string search_email;
    char character_of_file;
    file.open("Emails.txt", ios::in);
    while (!file.eof()) {
        //Read file char by char
        file.get(character_of_file);
        //If the character of files is space or tab or new line
        if (character_of_file == '\n' || character_of_file == ' ') {
            //Check the word read by char equal the word the user want search
            if (search_email == email) {
                //Found the word
                cout << "\n" << "Error: The E-mail you entered is already taken." << "\n" << "Please write another" << "\n";
                cout << "please enter your E-mail: ";
                cin >> email;
                email = check_email(email);
            }
            //The word end so clear the string
            search_email.clear();
        }
        else {
            //Store the word read by char in string
            search_email.push_back(character_of_file);
        }
    }
    return email;
}

string user_email()
{
    string email;
    int count_ = 0, count_1 = 0;
    cout << "please enter your E-mail: ";
    cin >> email;
    email = check_email(email);
    for (char letter : email)
    {
        if (letter == 46)
        {
            count_++;
        }
        while (count_ > 1 || email[0] == 46 || email[(email.length() - 1)] == 46)
        {
            if (count_ > 1)
            {
                cout << "Error: it can't more than one (.) in the E-mail.\n";
                email.clear();
            }
            if (email[0] == 46 || email[(email.length() - 1)] == 46)
            {
                cout << "Error: E-mail cannot start with dot(.) or end with dot(.)\n";
                email.clear();
            }
            user_email();
            break;
        }
    }
    int j = 0;
    while (email[j] != 46 && j < email.length())
    {
        if (email[j] != 46 && j == (email.length() - 1))
        {
            cout << " Error: E-mail must contain (.com) in it.\n";
            email.clear();
            user_email();
            break;
        }
        j++;
    }
    for (char letter : email)
    {
        if (letter == 64)
        {
            count_1++;
        }
        while (count_1 > 1 || email[0] == 64 || email[(email.length() - 1)] == 64)
        {
            if (count_1 > 1)
            {
                cout << "Error: it can't more than one (@) in the E-mail.\n";
                email.clear();
            }
            if (email[0] == 64 || email[(email.length() - 1)] == 64)
            {
                cout << "Error: E-mail cannot start with(@) or end with(@)\n";
                email.clear();
            }
            user_email();
            break;
        }
    }
    int i = 0;
    while (email[i] != 64 && i < email.length())
    {
        if (email[i] != 64 && i == (email.length() - 1))
        {
            cout << " Error: E-mail must contain (@) in it.\n";
            email.clear();
            user_email();
            break;
        }
        i++;
    }
    for (int i = 0; i < email.length(); i++)
    {
        if (email[i] == 64 && email[i + 1] == 46)
        {
            cout << "Error: Please enter the Domain name.\n";
            email.clear();
            user_email();
            break;
        }
        if (email[i] == 64)
        {
            if (email[i + 1] == 45)
            {
                cout << "Error: a hyphen (-), on condition that it is not placed at the beginning or end of the domain.\n";
                email.clear();
                user_email();
                break;
            }
        }
        if (email[i] == 46)
        {
            if (email[i - 1] == 45)
            {
                cout << "Error: a hyphen (-), on condition that it is not placed at the beginning or end of the domain.\n";
                email.clear();
                user_email();
                break;
            }
        }
    }
    //Store the Email
    /*file.open("Emails.txt", ios::app);
    if (file.is_open())
    {
        file << email << "\n";
        file.close();
    }*/
    return email;
}

string check_phone(string& phone)
{
    fstream file;
    string search_phone;
    char character_of_file;
    file.open("phones.txt", ios::in);
    while (!file.eof()) {
        //Read file char by char
        file.get(character_of_file);
        //If the character of files is space or tab or new line
        if (character_of_file == '\n' || character_of_file == ' ') {
            //Check the word read by char equal the word the user want search
            if (search_phone == phone) {
                //Found the word
                cout << "\n" << "Error: The phone number you entered is already taken." << "\n" << "Please write another" << "\n";
                cout << "please enter a valid mobile number: ";
                cin >> phone;
                phone = check_phone(phone);
            }
            //The word end so clear the string
            search_phone.clear();
        }
        else {
            //Store the word read by char in string
            search_phone.push_back(character_of_file);
        }
    }
    return phone;
}

string user_phone()
{
    string phone;
    cout << "please enter a valid mobile number: ";
    cin >> phone;
    phone = check_phone(phone);
    for (char num : phone)
    {
        if (phone.length() != 11)
        {
            cout << "Error: this number is not a valid.\n";
            user_phone();
            break;
        }
        if (phone[0] != 48 || phone[1] != 49 || (phone[2] != 48 && phone[2] != 49 && phone[2] != 50 && phone[2] != 53))
        {
            cout << "Error: this number is not a valid.\n";
            user_phone();
            break;
        }
    }
    //store phone number
    /*
    file.open("phones.txt", ios::app);
    if (file.is_open())
    {
        file << phone << "\n";
        file.close();
    }*/
    return phone;
}

string password_with_asterisk() {
    //Stores the password
    string pass = "";
    //The input
    char char_pass;
    // Until user press enter button
    while (true) {
        //Hide the input
        char_pass = getch();
        // if the input equal enter
        if (char_pass == 13) {
            //Return the input and stop the loop
            return pass;
        }
        //If the user want to clear the input and there is input
        else if (char_pass == 8 && pass.length() != 0) {
            //Clear the last content of the string
            pass.pop_back();
            //print space instead of the cleared content
            cout << "\b \b";
            //Continue looping
            continue;
        }
        //If the user want to clear the input and there is not input
        else if (char_pass == 8 && pass.length() == 0) {
            //Continue looping
            continue;
        }
        //Store the input in the string
        pass.push_back(char_pass);
        //Print the Asterisk
        cout << "*";
    }
}
//Check the strength of the password
string strong_password(string& pass) {
    //Check that rules of strength is exist or not
    int check = 0, check_1 = 0, check_2 = 0, check_3 = 0, check_4 = 0, check_5 = 0, check_6 = 0;
    //Loop until the user write a strong password
    while (check < 6) {
        //Check password length
        if (pass.length() >= 8) {
            //Rule of strong password achieved
            check_1 = 1;
        }
        else {
            //Print the error to user
            cout << "\n" << "Error: Password should be 8 characters or more" << "\n";
        }
        //Check password has lowercase
        for (int i = 0; i < pass.length(); i++) {
            if (islower(pass[i])) {
                //Rule of strong password achieved
                check_2 = 1;
            }
        }
        if (check_2 != 1) {
            //Print the error to user
            cout << "Error: Password should include a lowercase letters" << "\n";
        }
        //Check password has uppercase
        for (int i = 0; i < pass.length(); i++) {
            if (isupper(pass[i])) {
                //Rule of strong password achieved
                check_3 = 1;
            }
        }
        if (check_3 != 1) {
            //Print the error to user
            cout << "Error: Password should include a uppercase letters" << "\n";
        }
        //Check password has number
        for (int i = 0; i < pass.length(); i++) {
            if (isdigit(pass[i])) {
                //Rule of strong password achieved
                check_4 = 1;
            }
        }
        if (check_4 != 1) {
            //Print the error to user
            cout << "Error: Password should include a number" << "\n";
        }
        //Check password has char
        if (check_2 != 1 && check_3 != 1) {
            //Print the error to user
            cout << "Error: Password should include a characters" << "\n";
        }
        else {
            //Rule of strong password achieved
            check_5 = 1;
        }
        //Check password has one special characters
        regex special_char("(?=.*[-+=أ·_!@#$%^&*.,~`(){}<>/\?]).+$");

        if (regex_match(pass, special_char)) {
            //Rule of strong password achieved
            check_6 = 1;
        }
        if (check_6 != 1) {
            //Print the error to user
            cout << "Error: Password should include one special character" << "\n";
        }
        //Get the value of check
        check = check_1 + check_2 + check_3 + check_4 + check_5 + check_6;
        //If the rules are achieved
        if (check == 6) {
            ////Return the input and stop the loop
            return pass;
        }
        //Make the check as the start
        else {
            check_1 = 0, check_2 = 0, check_3 = 0, check_4 = 0, check_5 = 0, check_6 = 0;
            //Make the user write a new strong password
            cout << "\n" << "Password: ";
            pass = password_with_asterisk();
        }
    }
}


void take_pass()
{

    cout << "Password should be 8 characters or more." << "\n";
    cout << "Password should include a combination of uppercase and lowercase letters." << "\n";
    cout << "Password should include a combination of numbers, and characters." << "\n";
    cout << "It should contain at least one special character, e.g., ~`!@#$%^&*:;'<,>./\?" << "\n";
    //Take the password from the user
    cout << "Password: ";
    //The user write the password covered with Asterisk
    pass = password_with_asterisk();
    //Check that the user write the password with rules of strong password
    strong_password(pass);
    //Write the password again
    cout << "\n" << "Repeat the Password: ";
    //The user write the password covered with Asterisk
    re_pass = password_with_asterisk();
    //Loop until the password and it's repeat are the same
    while (pass != re_pass) {
        cout << "\n" << "The repeat of password doesn't equal the password." << "\n";
        cout << "Please write the password and it's repeat the same." << "\n";
        //Re-enter the password from
        cout << "Password: ";
        //The user write the password covered with Asterisk
        pass = password_with_asterisk();
        //Check that the user write the password with rules of strong password
        strong_password(pass);
        //Write the password again
        cout << "\n" << "Repeat Password: ";
        //The user write the password covered with Asterisk
        re_pass = password_with_asterisk();
        //If the password and it's repeat are the same break the loop
        if (pass == re_pass) {
            break;
        }
    }
}
//encryption password before add it in password file.
string encryption(string& email)
{
    string New_pass;
    //encrypt password by turn every character or number or special character to next character of it.
    for (int i = 0; i < pass.length(); i++)
    {
        New_pass += pass[i] + 1;
    }
    return New_pass;
}

//Store the Email
string store_email(string& email)
{
    ofstream file;
    file.open("Emails.txt", ios::app);
    if (file.is_open())
    {
        file << email << "\n";
        file.close();
    }
    return email;
}

//store id
string store_id(string& user_name)
{
    ofstream file;
    file.open("IDs.txt", ios::app);
    if (file.is_open())
    {
        file << user_name << "\n";
        file.close();
    }
    return user_name;
}

//store phone number
string store_phone(string& phone)
{
    ofstream file;
    file.open("phones.txt", ios::app);
    if (file.is_open())
    {
        file << phone << "\n";
        file.close();
    }
    return phone;
}

//add each password in file.
string creat_file(string& New_pass)
{
    ofstream file;
    file.open("passwords.txt", ios::app);
    if (file.is_open())
    {
        New_pass = encryption(pass);

        file << New_pass << endl;
        file.close();
    }
    return New_pass;
}


void login(fstream& file, fstream& file_IDs)
{
    string id, password, word_ids, word_pass, pass;
    char character;
    int lines1 = 0, lines2 = 0, check1 = 0, check2 = 0, chances = 3;
    //check if user used his three chances.
    while (chances > 0)
    {
        //if lines of id equal lines of password and check one and check two equal one that mean he is login successfully.
        if (lines1 == lines2 && check1 == 1 && check2 == 1)
        {
            cout << "\n" << "Successful login, welcome " << id << "\n";
            break;
        }
        else
        {
            //told user that the number of chances he has.
            cout << "\n" << "note that you have only " << chances << " chances to login" << "\n";
            //take id from users to know the number of lines.
            cout << "please enter your id: ";
            cin >> id;
            file_IDs.open("IDs.txt", ios::in);
            while (!file_IDs.eof())
            {
                file_IDs.get(character);
                //if the character is a new line the number of lines increase by one.
                if (character == '\n')
                {
                    lines1++;
                    //if he found the word make check equal one and break from loop.
                    if (word_ids == id)
                    {
                        check1 = 1;
                        break;
                    }
                    //if the word doesn't equal the id it make check equal zero and clear the word.
                    else
                    {
                        check1 = 0;
                    }
                    word_ids.clear();
                }
                //add the character in the word.
                else
                {
                    word_ids += character;
                }
            }
            file_IDs.close();
            //take the password from user and knoe the number of lines.
            cout << "please enter your password: ";
            password = password_with_asterisk();
            pass = encryption(password);
            file.open("passwords.txt", ios::in);
            while (!file.eof())
            {
                file.get(character);
                if (character == '\n')
                {
                    lines2++;
                    if (word_pass == pass)
                    {
                        check2 = 1;
                        break;
                    }
                    else
                    {
                        check2 = 0;
                    }
                    word_pass.clear();
                }
                else
                {
                    word_pass += character;
                }
            }
            file.close();
            //subtract from the opportunities one.
            chances -= 1;
            //check if the user login successfully and break.
            if (lines1 == lines2 && check1 == 1 && check2 == 1)
            {
                cout << "\n" << "Successful login, welcome " << id << "\n";
                break;
            }
            //check if the chances is ended to break.
            else if (chances == 0)
            {
                cout << "\n" << "sorry you can't login";
                break;
            }
            //if there are more chances continue and make user try again.
            else
            {
                lines1 = 0;
                lines2 = 0;
                word_ids.clear();
                word_pass.clear();
                check1 = 0;
                check2 = 0;
            }


        }


    }


}

//add id of new id in file of ids.
string replace_id(string& id)
{
    int num;
    fstream file;
    string word, str;
    char character_of_file;
    file.open("IDs.txt", ios::in);
    cout << "please enter your id to save changes: ";
    cin >> id;
    //open file and read it to end.
    while (!file.eof())
    {
        file.get(character_of_file);

        if (character_of_file == '\n' || character_of_file == ' ' || file.eof())
        {
            //check if the id is found delet it to be appended at the end of file.
            if (word == id)
            {
                str += "";
            }
            //else save the word in str.
            else
            {
                str += '\n';
                str += word;

            }
            word.clear();
        }
        //add character in the word.
        else
        {
            word += character_of_file;
        }


    }
    //add the str in file after delet the old cintent.
    file.close();
    file.open("IDs.txt", ios::out);
    file << "\n" << str;
}

//add id of new id in file of ids.
string replace_pass()
{
    int num;
    fstream file;
    string word, str, pass, password;
    char character_of_file;
    //open file and read it to end.
    file.open("passwords.txt", ios::in);
    cout << "please enter your old password to save changes: ";
    password = password_with_asterisk();
    pass = encryption(password);
    strong_password(pass);

    while (!file.eof())
    {
        file.get(character_of_file);
        if (character_of_file == '\n' || character_of_file == ' ' || file.eof())
        {
            //check if the id is found delet it to be appended at the end of file.
            if (word == pass)
            {
                cout << "..";
                str += "";
            }
            //else save the word in str.
            else
            {
                str += '\n';
                str += word;

            }
            word.clear();
        }
        //add character in the word.
        else
        {
            word += character_of_file;
        }


    }
    //add the str in file after delet the old cintent.
    file.close();
    file.open("passwords.txt", ios::out);
    file << "\n" << str;
}

//add an id of the new password in file.
string add_id(string& id)
{
    ofstream file_IDs;
    file_IDs.open("IDs.txt", ios::app);
    if (file_IDs.is_open())
    {
        file_IDs << id << endl;
        file_IDs.close();

    }


    return id;
}



void change_password()
{


    fstream file, file_IDs, account;
    string id, password, word_ids, word_pass, pass, word, re_pass, file1, word1, New_pass, line, old_pass, wordId, str, file2, file3, file4;
    char character, character_of_file;
    int  check = 0, chances = 3, lines = 0, lines1 = 0;
    // make user login to change password.
    cout << "please enter your id and old password";
    login(file, file_IDs);
    take_pass();

    //take the old password from user and check if it correct.
    while (check == 0) {
        cout << "\n" << "please enter your old password: ";
        old_pass = password_with_asterisk();
        old_pass = encryption(old_pass);

        file.open("passwords.txt", ios::in);
        while (!file.eof())
        {
            file.get(character_of_file);
            if (character_of_file == '\n' || character_of_file == ' ') {
                word.clear();
            }
            else {
                word += character_of_file;
            }
            if (word == old_pass) {
                check = 1;
                break;

            }
            else
            {
                check = 0;

            }

        }
        file.close();
    }
    file.close();
    //take new password from user.
    cout << "\n" << "please enter your New Password: ";
    New_pass = password_with_asterisk();
    New_pass = encryption(New_pass);
    //take id from user and know the number of lines.
    cout << "\n" << "please enter your id: ";
    cin >> id;


    file_IDs.open("IDs.txt", ios::in);
    while (!file_IDs.eof())
    {
        file_IDs.get(character);
        if (character == '\n')
        {
            lines1++;
            if (word1 == id)
            {
                break;
            }
            else
            {
                word1.clear();
            }
        }

        else
        {
            word1 += character;
        }
    }
    file_IDs.close();
    //check if old password equal new password.
    file.open("passwords.txt", ios::in);
    while (old_pass == New_pass)
    {

        while (!file.eof())
        {
            file.get(character);
            //if character is new line increase lines by one.
            if (character == '\n')
            {
                lines++;
                //check if the number of lines of id equal the number of lines of password.
                if (lines == lines1)
                {
                    //make user enter an other password because it equal an old password.
                    lines = 0;
                    cout << "\n" << "this password is not allowed because you used it before ." << "\n" << "please enter a valid password: ";
                    file.close();
                    New_pass = password_with_asterisk();
                    New_pass = encryption(New_pass);
                    strong_password(New_pass);
                    cout << "\n" << "Repeat newly Password: ";
                    re_pass = password_with_asterisk();
                    break;

                }
            }

        }
        file.close();
    }

    cout << "\n" << "the password change successfully" << "\n";
    //if the password change successfully replace the old password by new password and add it at the end of file and add id at the end of file.
    file1 = replace_id(id);
    file2 = add_id(id);
    file3 = replace_pass();
    file4 = creat_file(pass);
}




int main()
{
    //take the order from user to know what he want to do and creat four files.
    int order;
    string email, user_name, phone;
    files();
    //while user doesn't choose exit the menu appear.
    while (order != 4)
    {
        display_menu();
        cin >> order;
        //if he choose registration take the email, phone number, id and password from him.
        if (order == 1)
        {
            email = user_email();
            user_name = new_register();
            phone = user_phone();
            take_pass();
            creat_file(New_pass);
            store_email(email);
            store_id(user_name);
            store_phone(phone);
            cout << "\n" << "Registration completed successfully " << "\n";
        }
        else if (order == 2)
        {
            login(file, file_IDs);


        }
        else if (order == 3)
        {
            change_password();

        }
        else if (order == 4)
        {
            cout << "see you next time";
        }
        else
        {
            cout << "wrong choice";
        }
    }
}
