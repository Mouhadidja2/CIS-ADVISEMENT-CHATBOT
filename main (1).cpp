#include <iostream>
#include "honors_advisor.h"
#include "traditional_advisor.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "\n===== BMCC Advisor System =====\n";
        cout << "1. Honors Advisor\n";
        cout << "2. Traditional Advisor\n";
        cout << "3. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            HonorsAdvisor advisor;
            advisor.run();
        }
        else if (choice == 2) {
            TraditionalAdvisor advisor;
            advisor.run();
        }

    } while (choice != 3);

    cout << "Goodbye.\n";
    return 0;
}
