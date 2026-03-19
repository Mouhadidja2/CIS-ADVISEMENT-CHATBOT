#include <iostream>
#include <string>
#include "header.h"
using namespace std;

void menu_display ()
{
    //Welcoming the student
    string name, numSemester, grad_plan, academic_path, cred_compl;
    cout <<"Hello ! Welcome to BMCC CIS ADVISEMENT CHATBOT! \n" <<"What is your name?"<<endl;
    cin >> name;
    cout <<"Hello! " << name << " ! Welcome to BMCC ! \n" <<"Let's get your advisement started!"<<endl;

    // Getting to know the student's current status, graduation plan and their intrest of being an honors student or traditional student.
    // If it is their first semester
    cout <<"What semester are you on ? Please enter first or later. \n";
    cin >> numSemester;
    if (numSemester == "first")
    {
        cout <<"What is your graduation plan? Do you plan to graduate in 2 years? 3 years?.... \n";
        cin >> grad_plan;
        cout << "Do you want to graduate as a traditional student? Or as an honors student? \n";
        cin >> academic_path;
    }

    //If it is a later semester
    if (numSemester == "later")
    {
        cout <<"What is your graduation plan? Do you plan to graduate in 2 years? 3 years?.... \n";
        cin >> grad_plan;
        cout << "Do you want to graduate as a traditional student? Or as an honors student? \n";
        cin >> academic_path;
        cout << "How much credits have you completed so far?";
        cin >> cred_compl;

    }


}

int main()
{
   do
   {
    menu_display();

} while (true);
   
    return 0;
}