#include <iostream>
#include <vector>
using namespace std;
class course{
private:
    char *name;
    char *topic;
    char *index;
public:
    course(char*, char*, char*);
    void set_name(char*);
    void set_topic(char*);
    void set_index(char*);
    char* get_name();
    char* get_topic();
    char* get_index();
    void setLesson();
    ~course();
    int n;
};

class lesson{
private:
    char *lesson_name = nullptr;
    int roomNum;
public:
    lesson(char*, int);
    void set_l_n(char *l);
    void set_num(int n);
    char* get_l_n();
    int get_num();
    ~lesson();
    void set_athendance();
    void set_teacher();
    void set_student();
    int n;
};

class athendance{
private:
    char *state;
    int i_num;
public:
    athendance(char*, int);
    void set_state(char*);
    void count_n();
    void input_n(int);
    char* get_state();
    ~athendance();
};
class teacher{
private:
    char *name;
    char *id;
public:
    teacher(char*, char*);
    void set_name(char*);
    void set_id(char*);
    char* get_name();
    char* get_id();
    ~teacher();
};

