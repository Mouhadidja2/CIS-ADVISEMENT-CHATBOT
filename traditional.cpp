
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to store courses
struct Course {
    string code;
    string name;
};

// Function to display courses
void displaySemester(vector<Course> semester, int semNumber) {
    cout << "\n Semester " << semNumber << " Courses:\n";
    for (int i = 0; i < semester.size(); i++) {
        cout << "- " << semester[i].code << ": " << semester[i].name << endl;
    }
}

// Function to show full roadmap
void showRoadmap(vector<vector<Course>> roadmap) {
    cout << "\n CIS 2-Year Roadmap:\n";
    for (int i = 0; i < roadmap.size(); i++) {
        displaySemester(roadmap[i], i + 1);
    }
}

// Function to suggest next semester
void suggestNext(vector<vector<Course>> roadmap) {
    int completed;
    cout << "\nEnter number of semesters completed (0-4): ";
    cin >> completed;

    if (completed < 0 || completed > 4) {
        cout << " Invalid input.\n";
        return;
    }

    if (completed == 4) {
        cout << " You have completed the program!\n";
    }
    else {
        displaySemester(roadmap[completed], completed + 1);
    }
}

// FAQ system
void showFAQ() {
    int choice;
    do {
        cout << "\n FAQ Menu:\n";
        cout << "1. How many credits do I need?\n";
        cout << "2. What is a prerequisite?\n";
        cout << "3. Can I take summer classes?\n";
        cout << "4. Back to main menu\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << " You need 60 credits to graduate.\n";
            break;
        case 2:
            cout << " A prerequisite is a course you must complete before taking another.\n";
            break;
        case 3:
            cout << " Yes! Summer classes help you graduate faster.\n";
            break;
        case 4:
            cout << "Returning...\n";
            break;
        default:
            cout << " Invalid choice.\n";
        }

    } while (choice != 4);
}

// Main chatbot
int main() {
    cout << "=====================================\n";
    cout << " BMCC CIS Panther Chatbot \n";

    cout << "=====================================\n";

    // Define roadmap
    vector<vector<Course>> roadmap = {

        { // Semester 1
            {"ENG 101", "English Composition"},
            {"BUS 104", "Introduction to Business"},
            {"CSC 101", "Principles in IT"},
            {"ACC 122", "Accounting Principles I"},
            {"SPE 100", "Public Speaking"}
        },

        { // Semester 2
            {"ENG 201", "Introduction to Literature"},
            {"CSC 110", "Computer Programming I"},
            {"MAT 150", "Statistics"},
            {"AST 110", "General Astronomy"}
        },

        { // Semester 3
            {"CSC 210", "Computer Programming II"},
            {"CIS 345", "Telecommunication Networks"},
            {"CIS 385", "Web Programming I"},
            {"CIS 395", "Database Systems I"},
            {"ELEC", "Program Elective"}
        },

        { // Semester 4
            {"CIS 440", "Unix"},
            {"CIS 485", "Web Programming II"},
            {"CIS 495", "Database Systems II"},
            {"ELEC", "Program Elective"},
            {"ELEC", "General Elective"}
        }
    };

    int choice;

    do {
        cout << "\n Main Menu:\n";
        cout << "1. View Full Roadmap\n";
        cout << "2. Suggest Next Semester\n";
        cout << "3. FAQ\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            showRoadmap(roadmap);
            break;

        case 2:
            suggestNext(roadmap);
            break;

        case 3:
            showFAQ();
            break;

        case 4:
            cout << " Goodbye! Good luck with your studies!\n";
            break;

        default:
            cout << " Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
