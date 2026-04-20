#ifndef TRADITIONAL_ADVISOR_H
#define TRADITIONAL_ADVISOR_H

#include <vector>
#include <string>

using namespace std;

struct Course {
    string code;
    string name;
};

class TraditionalAdvisor {
public:
    void run();

private:
    vector<vector<Course>> roadmap;

    void loadData();
    void displaySemester(int sem);
    void showRoadmap();
    void suggestNext();
    void showFAQ();
};

#endif
