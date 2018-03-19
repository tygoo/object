#include <iostream>
#include <string.h>
using namespace std;
void head();
class employee {
    public:
    char* name;
    char* position;
    float worked_time;
    int id;
    employee(char*, int, char*, float, float);
    ~employee();

public:
    float worker_pay;

public:
    void change_value(employee&);
    void set_value (int, char*, char*, float);
    void get_value ();
    float pay();
    bool additional_time(float);

private:
    float direct_pay();
};
//---------------------------------------------------------------------------------
employee::employee(char *n = "unnamed", int a = 0, char *b = "worker", float t = 0, float p = 0){
    name = new char[strlen(n)+1];
    strcpy(name, n);
    id = a;
    position = new char[strlen(b)+1];
    strcpy(position, b);
    worked_time = t;
    worker_pay = p;
}
//--------------------------- DESTROY FUNC --------------------
employee::~employee(){
    delete name;
}
//---------------------------- SET VALUES ---------------------
void employee::set_value (int i, char *n, char *p, float time){
    name = new char[strlen(n)+1];
    strcpy(name, n);
    id = i;
    position = new char[strlen(p)+1];
    strcpy(position, p);
    worked_time = time;
}
//---------------------- PAY -------------------------------
float employee::pay(){
    float worker_pay = 5;
    float general_pay = 0;
    if(strcmp(position,"director") == 0){
        general_pay = direct_pay();
    }
    else{
        general_pay = worker_pay * worked_time;
    }
    worker_pay = general_pay;
    return worker_pay;
}
//-------------------- SUPPOSE DIRECTOR PAY ---------------
float employee::direct_pay(){
    float general =worked_time * 10;
    worker_pay = general;
    return worker_pay;
}
//-------------------- GET VALUE ---------------------------
void employee::get_value(){
    cout << name << "|       ";
    cout << id << "|       ";
    cout << position << "|       ";
    cout << worked_time << "|       ";
    cout << pay() << "\n";
}
//----------------------- CHECK ADDITIONAL TIME -------------------
bool employee::additional_time(float t){
    if(worked_time < 24 & worked_time > 0){
        worked_time = worked_time + t;
        return true;
    }
    else{
        return false;
    }
}
// ---------------------- CHANGE VALUE OF TWO OBJECT --------------------------
void employee::change_value(employee &e1){
    int num;
    char *n, *p;
    float work_time, wpay;
    num = e1.id;
    n = e1.name;
    p = e1.position;
    work_time = e1.worked_time;
    wpay = e1.worker_pay;

    e1.name = name;
    e1.id = id;
    e1.position = position;
    e1.worked_time = worked_time;
    e1.worker_pay = worker_pay;

    name = n;
    id = num;
    position = p;
    worked_time = work_time;
    worker_pay = wpay;
}
main(){
//----------------------------------------- START VALUES ---------------------------------------------------------
    cout << "Enter your employees number:" << "\n";
    int n, id;
    char *name, *position;
    float work_time;
    cin >> n;
   employee worker[n];
//------------------------------------------ SET VALUE -----------------------------------------------------
    for(int i = 0; i < n; i++){
        cout << "Enter your id(it must integer number):";
        cin >> id;
        cout << "Enter employee name:";
        name = new char[30];
        cin >> name;
        cout << "Enter employee position: worker or director" << "\n";
        position = new char[12];
        cin >> position;
        cout << "Enter worked time:0 to 24" << "\n";
        cin >> work_time;
        worker[i].set_value(id,name,position,work_time);
        cout << "Day salary:" << worker[i].pay() << "\n";
        cout << "-----------------------------" << "\n";
    }
//--------------------------------------- SORT BY NAME ------------------------------------------------
    int temp = 0,min;
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(strcmp(worker[i].name, worker[j].name) < 0 && i != j){
                worker[i].change_value(worker[j]);
            }
        }
    }
    head();
//-------------------------------------PRINT------------------------------------------------
    for(int i = 0; i < n; i++){
        worker[i].get_value();
    }
//-------addition member -------------
    employee add_member;

//-------------------------------------- CHECK ID -------------------------------------------
        cout << "---------------- Add Employee ------------" << "\n";
        cout << "Enter your id(it must integer number):";
        cin >> id;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(worker[i].id == id){
                count++;
            }
        }
        if(count == 0){
            cout << "Enter employee name:";
            name = new char[30];
            cin >> name;
            cout << "Enter employee position: worker or director" << "\n";
            position = new char[12];
            cin >> position;
            cout << "Enter worked time:0 to 24" << "\n";
            cin >> work_time;
            add_member.set_value(id,name,position,work_time);
            cout << "Day salary:" << add_member.pay() << "\n";
            cout << "-----------------------------" << "\n";
        }
        else{
            cout << "Your entered id is already used!" << "\n";
            while(count != 0){
                id = rand() % 9999;
                int count1 =0;
                for(int i = 0; i < n; i++){
                    if(worker[i].id == id){
                        count1++;
                    }
                }
                if(count1 == 0){
                    count = 0;
                }
            }
            cout << "Your id is " << id << "\n";
            cout << "Enter employee name:";
            name = new char[30];
            cin >> name;
            cout << "Enter employee position: worker or director" << "\n";
            position = new char[12];
            cin >> position;
            cout << "Enter worked time:0 to 24" << "\n";
            cin >> work_time;
            add_member.set_value(id,name,position,work_time);
            cout << "Day salary:" << add_member.pay() << "\n";
            cout << "-----------------------------" << "\n";
        }
        head();
        add_member.get_value();

}

void head(){
    cout << "name       ";
    cout << "id     ";
    cout << "position   ";
    cout << "worked time     ";
    cout << "worker_pay     " << "\n";
}
