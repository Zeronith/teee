#include<iostream>
#include<string.h>
using namespace std;

class R {
private:
 char *name;
 int a;
 int b;
public:
 R(){
  set_a(0); set_b(1);
  set_name("default");
 }
 R(int a, int b, char *n){ 
  //this->a=a; this->b=b; 
  set_a(a); set_b(b);
  set_name(n);
 }
 ~R(){ delete name; }
 
 void copy(R &r){
  set_a(r.a);
  set_b(r.b);
  delete this->name;
  set_name(r.name);
 }

 void set_name(char *n){
  name = new char[strlen(n)+1];
  strcpy(name, n);
 }
 void set_a(int a){ this->a = a; }
 int get_a() { return a; }
 void set_b(int b){  if(b!=0) this->b = b; }
 int get_b() { return b; } 
};

int main(){
 R o1, o2, o3(34, 2, "my number"); 
 o1.set_a(34);
 o2.set_a(24);
 R objects[100];

 
for(int i = 0; i < 100; i++) 
{
    for(int j = 0; j < 99 - i; j++)  // Reduce the number of comparisons as i increases
    { 
        if(objects[j].get_a() > objects[j + 1].get_a()) 
        {
            R tmp;
            tmp.copy(objects[j]);
            objects[j].copy(objects[j + 1]);
            objects[j + 1].copy(tmp);
        }
    }
}
}
