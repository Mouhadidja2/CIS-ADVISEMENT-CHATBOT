#include "traditional_advisor.h"
#include <iostream>

using namespace std;

void TraditionalAdvisor::loadData() {
    roadmap = {
        {
            {"ENG 101", "English Composition"},
            {"CSC 101", "Intro to IT"}
        },
        {
            {"CSC 110", "Programming I"},
            {"MAT 150", "Statistics"}
        },
        {
            {"CSC 210", "Programming II"}
        },
        {
            {"CIS 440", "Unix"}
        }
    };
}

void TraditionalAdvisor::displaySemester(int sem) {
    cout << "\nSemester " << sem + 1 << ":\n";
    for (const auto& c : roadmap[sem]) {
        cout << "- " << c.code << ": " << c.name << "\n";
    }
}

void TraditionalAdvisor::showRoadmap() {
    for (int i = 0; i < roadmap.size(); i++) {
        displaySemester(i);
    }
}

void TraditionalAdvisor::suggestNext() {
    int completed;
    cout << "Completed semesters: ";
    cin >> completed;

    if (completed >= 0 && completed < roadmap.size()) {
        displaySemester(completed);
    }
}

void TraditionalAdvisor::showFAQ() {
    cout << "\nFAQ:\n";
    cout << "60 credits needed.\n";
}

void TraditionalAdvisor::run() {
    loadData();

    int choice;
    do {
        cout << "\n1. Roadmap\n2. Suggest Next\n3. FAQ\n4. Exit\n";
        cin >> choice;

        if (choice == 1) showRoadmap();
        else if (choice == 2) suggestNext();
        else if (choice == 3) showFAQ();

    } while (choice != 4);
}
