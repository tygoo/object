#include <iostream>
#include <string>
using namespace std;

class employee {
    int number;
    string name;
    string position;
    float worked_time;
public:
    void set_value ();
    void get_value ();
    void start_value();
    float pay();
    float direct_pay();
    float additional_time();
};
void employee::set_value (){
    cout << "number:" << "\n";
    cin >> number;
    cout << "Enter your name:" << "\n";
    cin >> name;
    cout << "Enter your position: worker or director" << "\n";
    cin >> position;
    cout << "Enter your worked time:0 to 24" << "\n";
    cin >> worked_time;

}
float employee::pay(){
    float worker_pay = 5;
    float general_pay = 0;
    if(position == "director"){
        general_pay = direct_pay();
    }
    else{
        general_pay = worker_pay * worked_time;
    }
    cout << "your day salary:" << general_pay <<  "$"<<"\n";
}
float employee::direct_pay(){
    float general =worked_time * 10;
    return general;
}
void employee::get_value(){
    cout << "number = " << number<< "\n";
    cout << "name = " << name << "\n";
    cout << "position = " << position << "\n";
    cout << "Worked_time = " << worked_time << "\n";
}
void employee::start_value(){
    number = 0;
    name = "";
    position = "ajilchin";
    worked_time = 0;
}
float employee::additional_time(){
    cout << "your worked time:" << worked_time << "\n";
    cout << "Enter your additional time:" << "\n";
    float add_time = 0;
    cin >> add_time;
    worked_time = worked_time + add_time;
    if(0 < worked_time > 24){
        return 1;
    }
    else{
        return 0;
    }
}

main(){
    cout << "Enter your employees number:" << "\n";
    int n;
    cin >> n;
    employee worker;
    employee first;
    worker.set_value();
    first.start_value();
    first.get_value();
    worker.get_value();
    worker.pay();
    cout << worker.additional_time();
}
