#include "honors_advisor.h"
#include <iostream>
#include <algorithm>

using namespace std;

HonorsAdvisor::HonorsAdvisor() {}

string HonorsAdvisor::toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

string HonorsAdvisor::detectIntent(string input) {
    string t = toLower(input);

    if (t.find("course") != string::npos) return "courses";
    if (t.find("requirement") != string::npos) return "requirements";
    if (t.find("benefit") != string::npos) return "benefits";
    if (t.find("help") != string::npos) return "help";
    if (t.find("quit") != string::npos) return "quit";

    return "unknown";
}

void HonorsAdvisor::showCourses() {
    cout << "\nHonors Courses:\n";
    cout << "ENG 101H, CSC 101H, CSC 110H...\n";
}

void HonorsAdvisor::showRequirements() {
    cout << "\nRequirements:\n";
    cout << "GPA >= 3.2, 12 honors credits...\n";
}

void HonorsAdvisor::showBenefits() {
    cout << "\nBenefits:\n";
    cout << "Priority registration, scholarships...\n";
}

void HonorsAdvisor::showHelp() {
    cout << "\nCommands: courses, requirements, benefits, quit\n";
}

void HonorsAdvisor::respond(string intent) {
    if (intent == "courses") showCourses();
    else if (intent == "requirements") showRequirements();
    else if (intent == "benefits") showBenefits();
    else if (intent == "help") showHelp();
    else cout << "Unknown command.\n";
}

void HonorsAdvisor::run() {
    string input;

    cout << "\n[Honors Advisor]\n";

    while (true) {
        cout << "You: ";
        getline(cin, input);
        
        if (input == "quit" || input == "q" || input == "Q" || input == "QUIT") {
            break;
        }

        string intent = detectIntent(input);
        respond(intent);
    }
}
