#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//  CLASS: Course
//  Represents one course with its code, name, and credits
class Course {
private:
    string code;
    string name;
    int credits;

public:
    // Default constructor
    Course() {
        credits = 0;
    }

    // Constructor
    Course(string c, string n, int cr) {
        code    = c;
        name    = n;
        credits = cr;
    }

    // Getters
    string getCode()const { return code; }
    string getName()const { return name; }
    int getCredits()const { return credits; }

    // Display one course
    void display() const {
        cout << code << " - " << name << " (" << credits << " credits)\n";
    }
};



//  CLASS: Student
//  Stores all info collected from the student in the menu
class Student {
private:
    string         name;
    string         semester;      // "first" or "later"
    string         track;         // "honors" or "traditional"
    string         gradPlan;      // "2 years", "3 years", etc.
    int            creditsCompleted;
    vector<Course> completedCourses;

public:
    // Default constructor
    Student() {
        creditsCompleted = 0;
    }

    // Getters
    string getName() const { return name; }
    string getSemester() const { return semester; }
    string getTrack() const { return track; }
    string getGradPlan() const { return gradPlan; }
    int getCreditsCompleted() const { return creditsCompleted; }
    vector<Course> getCompletedCourses() const { return completedCourses; }

    // Setters
    void setName(string n)            { name             = n; }
    void setSemester(string s)        { semester         = s; }
    void setTrack(string t)           { track            = t; }
    void setGradPlan(string g)        { gradPlan         = g; }
    void setCreditsCompleted(int c)   { creditsCompleted = c; }
    void addCompletedCourse(Course c) { completedCourses.push_back(c); }

    // Check if a specific course code is in completedCourses
    bool hasTaken(string code) const {
        for (int i = 0; i < completedCourses.size(); i++) {
            if (completedCourses[i].getCode() == code)
                return true;
        }
        return false;
    }
};