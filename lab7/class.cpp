#include "lab7.h"
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include "student.h"
using namespace std;
course::course(char *n_= "", char *t = "", char *i = ""){
    set_name(n_);
    set_topic(t);
    set_index(i);
    setLesson();
}
void course :: setLesson(){
char *l_name;
int room_num;
cout << "Enter lesson number:";
cin >> n;
lesson *les[n];
for(int i = 0; i < n; i++){
    cout << "Enter lesson name:" << endl;
    l_name = new char[20];
    cin >> l_name;
    cout << "Enter lesson room number:" << endl;
    cin >> room_num;
    les[i]->set_l_n(l_name);
    les[i]->set_num(room_num);
}

}

void course::set_name(char *_n){
    if(name) delete name;
    name = new char [strlen(_n)+1];
    strcpy(name, _n);
}
void course::set_topic(char *_t){
    if(topic) delete topic;
    topic = new char [strlen(_t)+1];
    strcpy(topic, _t);
}
void course::set_index(char *_i){
    if(index) delete index;
    index = new char [strlen(_i)+1];
    strcpy(index, _i);
}
char* course::get_name(){
    return name;
}
char* course::get_index(){
    return index;
}
char* course::get_topic(){
    return topic;
}
course::~course(){
    delete name;
    delete topic;
    delete index;
}
lesson::lesson(char *l_n = "", int n = 0){
   set_l_n(l_n);
   set_num(n);
   set_athendance();
   set_teacher();
   set_student();
}
void lesson::set_student(){
    char *nme;
    char *id;
    unsigned int crs;
    float ave;
    cout << "how much student?" << "\n";
    cin >> n;
    student *student[n];
//-------------------------------------- SET VALUE --------------------------------------
    for(int i = 0; i < n; i++){
        cout << "------------------------------------------------------------" << "\n";
        cout << "STUDENT NUMBER  -  " << i+1 << "\n";
        cout << "Enter "<< i+1 <<"student name:" << "\n";
        nme = new char[30];
        cin  >> nme;
        cout << "Enter "<< i+1 <<"student id:" << "\n";
        id = new char[20];
        cin >> id;
        cout << "Enter student level:" << "\n";
        cin >> crs;
        cout << "Enter student average: /it must between 0 and 4 float number/" << "\n";
        cin >> ave;
        student[i]->set_all_data(nme,crs,id,ave);
    }
}
void lesson::set_teacher(){
    char *nme_;
    char *id_;
    cout << "Enter teacher number:" << endl;
    cin >> n;
    teacher *teach[n];
    for(int i = 0; i < n; i++){
        cout << "Enter teacher name:";
        nme_ = new char[20];
        cin >> nme_;
        cout << "Enter teacher id:";
        id_ = new char[20];
        cin >> id_;
        teach[i] -> set_id(id_);
        teach[i] -> set_name(nme_);
    }

}
void lesson::set_athendance(){
    athendance *ath;
    char *state;
    state = new char[20];
    int num;
}
void lesson::set_l_n(char *l_n){
    if(lesson_name) delete lesson_name;
    lesson_name = new char [strlen(l_n) + 1];
    strcpy(lesson_name, l_n);
}
void lesson::set_num(int _n_){
    roomNum = _n_;
}
char* lesson::get_l_n(){
    return lesson_name;
}
int lesson::get_num(){
    return roomNum;
}
lesson::~lesson(){
    delete lesson_name;
}
athendance::athendance(char *state = "", int i_num = 0){
    set_state(state);
    input_n(i_num);
}
void athendance::set_state(char *k){
    if(state) delete state;
    state = new char [strlen(k) + 1];
    strcpy(state,k);
}
void athendance::input_n(int i){
    i_num = i;
}
char* athendance::get_state(){
    return state;
}
athendance::~athendance(){
    delete state;
}
teacher::teacher(char *k = "", char *i = ""){
    set_name(k);
    set_id(i);
}
void teacher::set_name(char *m){
    if(name) delete name;
    name = new char [strlen(m) + 1];
    strcpy(name , m);
}
void teacher::set_id(char *i){
    if(id) delete id;
    id = new char [strlen(i) + 1];
    strcpy(id , i);
}
char* teacher::get_name(){
    return name;
}
char* teacher::get_id(){
    return id;
}
teacher::~teacher(){
delete name;
delete id;
}
