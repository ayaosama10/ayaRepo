#include <iostream>
#include <string>

using namespace std;

int amount = 0;
string clientname[5];
int clientid[5];
int ids=0;
class Person {
protected:
    int id;
    string name;
    string password;
public:
    Person() {
        id = 0;
    }
    Person(string name, int id, string password) {
        this->name = name;
        this->id = id;
        this->password = password;

    }
    void setName(string name) {
        this->name = name;
    }
    void setId(int id) {
        this->id = id;
    }
    void setPassword(string password) {
        this->password = password;
    }
    string getName() {
        return name;
    }
    int getId() {
        return id;
    }
    string getPassword() {
        return password;
    }

};

class Client : public Person {
private:
    double balance;
public:
    Client() {
        balance = 0;
    }
    Client(string name, int id, string password, double balance) :Person(name, id, password) {
        this->balance = balance;
    }
    void setBalance(double balance) {
        this->balance = balance;
    }
    double getBalance() {
        return balance;
    }
    double deposit(double amount) {
        balance += amount;
        return balance;
    }
    double withdraw(double amount) {
        if (amount > balance) {
            cout << "Amount Exceeds your Balance";
        }
        else {
            balance -= amount;
            return balance;
        }
    }
    double checkbalance() {
        return balance;
    }
    double transferto(Client& c, double amount) {
        if (amount <= balance) {
            balance -= amount;
            c.deposit(amount);
        }
        else {
            cout << "Amount Exceeds your Balance";
        }
        return balance;
    }
    void Display() {
        cout << "Name     = " << name << endl;
        cout << "ID       = " << id << endl;
        cout << "Password = " << password << endl;
        cout << "Balance  = " << balance << endl;

    }

};

class Employee : public Person {
protected:
    double salary;
public:
    Employee() {
        salary = 0;
    }
    Employee(string name, int id, string password, double salary) :Person(name, id, password) {
        this->salary = salary;
    }
    void setSalary(double salary) {
        this->salary = salary;
    }
    double getSalary() {
        return this->salary;
    }
    void addClient() {
        cout << "Enter The name of the client\n";
        getline(cin,name);
        cout << "Enter the ID Number\n";
        cin >> id;
        cout << "Enter the Client Deposit\n";
        cin >> amount;
        cout << " a New Client is added to the System\n";
    }
    void ShowClientInfo() {
        cout << "Client Name    = " << name << endl;
        cout << "Client ID      = " << name << endl;
        cout << "Client Balance = " << name << endl;
    }
    void ListClientInfo() {
        string names[5] = { "Ahmed","Mohamed","Ali","Sara","Salma" };
        int ids[5] = { 1101,1102,1103,1104,1105 };
        double balance[5] = { 5000,6000,7000,8000,9000 };
        for (int i = 0; i < 5; i++) {
            cout << names[i] << "," << ids[i] << "," << balance[i] << endl;
        }
    }
    /*void Search() {
        cout << "Enter the ID you want to search for\n";
        cin >> id;
        for (int i = 0; i < 5; i++) {
            if (id == ids[i]) {
                cout << "Client is on System\n";
            }
            else {
                cout << "Client is not on System\n";
            }
        }

    }*/
    void Display() {
        cout << "Name     = " << name << endl;
        cout << "ID       = " << id << endl;
        cout << "Password = " << password << endl;
        cout << "Salary   = " << salary << endl;

    }
};

class Admin : public Employee {
public:
    Admin() {

    }
    Admin(string name, int id, string password, double salary) :Employee(name, id, password, salary) {

    }

    void Display() {
        cout << "Name     = " << name << endl;
        cout << "ID       = " << id << endl;
        cout << "Password = " << password << endl;
        cout << "Salary   = " << salary << endl;

    }
};

int main()
{
    cout << " *               *\t"; cout << "*******\t";  cout << "*" << endl;
    cout << "  *             *\t"; cout << "*\t";         cout << "*" << endl;
        cout << "   *     *     *\t";  cout << "*******\t";   cout << "*" << endl;
    cout << "    *  *   *  *\t\t";   cout << "*\t";       cout << "*" << endl;
    cout << "     *       *\t\t";   cout << "*******\t"; cout  << "******" << endl;



    cout << "\t\t\tWELCOME TO CIB BANK\t\t\t\n";
    //LOG IN SCREEN
    cout << "Let us Know Who are you?" << endl;
    cout << "1-I am a Client" << endl;
    cout << "2-I am an Employee" << endl;
    cout << "3-I am an Admin" << endl;
    cout << "Please Choose a Number" << endl;
    int choice;
    cin >> choice;

    Employee e("Ayman", 555, "1234", 20000);
    e.ListClientInfo();
    e.addClient();
    e.Display();


}
