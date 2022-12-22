#include<bits/stdc++.h>
using namespace std;

struct user {
string username,password,gender;
int age;
};
user u[5];
int i = 0;
int reg () {
   string name,pass,gen;
   int ag;
   cin >> name >> pass >> gen >> ag;
   for(int j = 0; j < i; j++) {
   if(name == u[j].username)
   cout << "already exist\n";
   return 0;
   }
   u[i].username = name;
   u[i].password = pass;
   u[i].gender = gen;
   u[i].age = ag;
   i++;
   return 1;
}
int login() {
   string name,pass;
   for(int k = 0;k <= 5; k++) {
      cin >> name >> pass;
      for(int j = 0; j<= i; j++) {
      if(name == u[j].username and pass == u[j].password) {
      cout << "Successful\n";
      return 0;
      } else {cout << "Try again\n";break;}
      }
   }
   cout << "Account locked\n";
   return 1;
}
int main() {
int num = 5;
for(int i = 0;i < num; i++){
   string info; cin >> info;
   if(info == "reg") reg();
   else if (info == "login") login();
   }
}
