#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class employee {
    private:
    int id;
    char *name;
    char *position;
    float time;

    float direct_salary(); //Захирлын цалин бодох private function
    public:
    void setdata(); //Гарааны утга оноох void төрөлтэй гишүүн функц
    void getdata(); //Гараас утга авах
    void showdata(); //Мэдээлэл дэлгэцлэх
    float calculate_salary(); //Цалин бодох
    bool increase_time(float t); //Ажилсан цаг нэмэгдүүлэх
    employee(int id, char *name_, char *position_, float time); //Параметртэй бөйгуулагч функц
    employee(); //Гарааны утга оноох, Анхдагч байгуулагч функц
    ~employee(); //Устгагч функц
    int getId(); //ID утга авах getter
    void setId(int i); //ID утга оноох setter
    char *getName(); //Ажилчны нэрийг авах getter
    void setName(char *name_); //Ажилчны нэр оноох setter
    char *getPosition(); //Албан тушаалын утгыг авах getter
    void setPosition(char *position_); //Албан тушаал оноох setter
    float getTime(); //Ажилсан цаг авах getter
    void setTime(float t); //Ажилсан цагийн утга оноох setter
    employee(employee &e); //copy constructor
    void copy(employee &e); //copy function
};
employee::employee(int id, char *name_, char *position_, float time) : id(id), time(time) { // This one isnt even used just to mess with my head bruh
    name = new char[strlen(name_) + 1];
    strcpy(name, name_);
    position = new char[strlen(position_) + 1];
    strcpy(position, position_);
}
employee::employee() {
    id = 0;
    name = new char[1];
    strcpy(name, "");
    position = new char[9];
    strcpy(position, "Ajilchin");
    time = 0;
}
employee::~employee() {
    delete [] name;
    delete [] position;
}
int employee::getId() {
    return id;
}
void employee::setId(int i) {
    id = i;
}
char *employee::getName(){
    return name;
}
void employee::setName(char *name_){
    delete [] name;
    name = new char[strlen(name_) + 1];
    strcpy(name, name_);
}
char *employee::getPosition(){
    return position;
}
void employee::setPosition(char *position_){
    delete [] position;
    position = new char[strlen(position_) + 1];
    strcpy(position, position_);
}
float employee::getTime(){
    return time;
}
void employee::setTime(float t){
    time = t;
}
employee::employee(employee &e){
    id = e.id;
    delete [] name;
    name = new char[strlen(e.name) + 1];
    strcpy(name, e.name);
    delete [] position;
    position = new char[strlen(e.position) + 1];
    strcpy(position, e.position);
    time = e.time;
}
void employee::copy(employee &e){
    id = e.id;
    delete [] name;
    name = new char[strlen(e.name) + 1];
    strcpy(name, e.name);
    delete [] position;
    position = new char[strlen(e.position) + 1];
    strcpy(position, e.position);
    time = e.time;
}
void employee::setdata() {
    id = 0;
    name = new char[0];
    strcpy(name, "");
    position = new char[9];
    strcpy(position, "Ajilchin");
    time = 0;
}
void employee::getdata() {
    cout << "\n" << "ID :";
    cin >> id;
    cout << "NAME :";
    cin >> name;
    cout << "POSITION :";
    cin >> position;
    cout << "TIME :";
    cin >> time;
}
void employee::showdata() {
    cout << endl;
    cout << setw(6) << id;
    cout << setw(15) << name;
    cout << setw(15) << position;
    cout << setw(6) << time;
}
float employee::calculate_salary() {
    float salary = 20000 * time; //Нэг цагийн үнэлэмж 20000
    if(strcmp(position, "Ajilchin") != 0) {
        salary = salary + direct_salary();
    }
    return salary;
}
float employee::direct_salary() { //Захирлын цалин бодох private function
    return 15000 * time; //Захирлын нэмэлт орлогын цаг нь 15000
}
bool employee::increase_time(float t) {
    if(t > 0 && t < 24) {
        time = time + t;
        return 1;
    }
    else return 0;
}
void heading() {
    cout << endl;
    cout << setw(6) << "ID";
    cout << setw(15) << "NAME";
    cout << setw(15) << "POSITION";
    cout << setw(6) << "TIME";
}
int main() {
    int n;
    cout << "Objectiin toog oruulna uu : ";
    cin >> n;
    employee *p ;
    employee emp[n];
    p = &emp[0];
    employee e[n];
    e[0].getdata();
    for (int i = 1; i < n; i++) {
        e[i].getdata();
        int j = 0;
        while (j < i) {
            bool p = false;
            if(e[i].getId() == e[j].getId()) {
                cout << "This ID already exists !";
                int k;
                cin >> k;
                e[i].setId(k);
                p = true;
            }
            if (p == true) {
                j = 0;
            }
            else j++;
        }
    }
    heading();
    for (int i = 0; i < n; i++) {
        e[i].showdata();
    }
    int i, j;
    employee temp;
    p = &emp[0];
    for(i = 1; i < n; i++){          
        temp.copy(*(p + i));         
        j = i - 1;                  
        while(j >= 0 && temp.getName() < (p + j) -> getName()){ 
            (p+j+1) -> copy(*(p+j)); 
            j--;                     
        }   
        (p+j+1) -> copy(temp); 
    }
    heading();
    for (int i = 0; i < n; i++) {
        e[i].showdata();
        }
    return 0;
}
