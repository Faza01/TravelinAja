#include <iostream>

using namespace std;

struct Users
{
    string nama;
    float usia;
    string username, password;
    string role = "costumer";
};

struct Admins
{
    string username, password;
    string role = "admin";
};

int jml_costumer = 0;
int jml_admin = 0;

Users *Costumer = new Users[99];
Admins *Admin = new Admins[99];