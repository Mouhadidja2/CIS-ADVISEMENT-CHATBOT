#ifndef HONORS_ADVISOR_H
#define HONORS_ADVISOR_H

#include <string>

using namespace std;

class HonorsAdvisor {
public:
    HonorsAdvisor();
    void run();

private:
    string toLower(string s);
    string detectIntent(string input);
    void respond(string intent);

    void showCourses();
    void showRequirements();
    void showBenefits();
    void showHelp();
};

#endif
