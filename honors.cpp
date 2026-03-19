/*
*  BMCC CIS Honors Advisement
*  File:    honors_advisor.cpp
*  Name: Katherine Sanchez
*  Course:  CSC 211H
*
*  HOW TO COMPILE:
*    g++ -std=c++17 -o honors_advisor honors_advisor.cpp
*
*  HOW TO RUN:
*    ./honors_advisor
*
*  CONCEPTS USED:
*    - Classes with private fields, constructors, getters
*    - display() method on every data class
*    - Fixed-size arrays of class objects
*    - Plain strings for intent (no enum)
*    - using namespace std
*
*  NOTE:
*      Main chatbot menu just calls:
*      HonorsAdvisor advisor;
*      advisor.run();
*    when a student is identified as an honors student.
*/


#include <iostream>
#include <string>
#include <iomanip>


using namespace std;




// ============================================================
//  CLASS: Course
//  Stores one course from the CIS degree plan.
// ============================================================


class Course {
private:
   string code;
   string name;
   int    semester;
   string type;        // "Major Req", "General Ed", or "Elective"
   bool   honorsAvail;
   string honorsCode;


public:
   // Default constructor
   Course() {
       semester   = 0;
       honorsAvail = false;
   }


   // Constructor
   Course(string c, string n, int sem, string t, bool h, string hc) {
       code        = c;
       name        = n;
       semester    = sem;
       type        = t;
       honorsAvail = h;
       honorsCode  = hc;
   }


   // Getters
   int    getSemester()    const { return semester; }
   string getCode()        const { return code; }
   string getName()        const { return name; }
   string getType()        const { return type; }
   bool   hasHonors()      const { return honorsAvail; }
   string getHonorsCode()  const { return honorsCode; }


   // Print one course row
   void display() const {
       string displayCode = honorsAvail ? honorsCode + " *" : code;
       cout << "  " << left << setw(12) << displayCode
            << setw(34) << name
            << type << "\n";
   }
};




// ============================================================
//  CLASS: Requirement
//  Stores one honors program requirement (label + value).
// ============================================================


class Requirement {
private:
   string label;
   string value;


public:
   Requirement() {}


   Requirement(string l, string v) {
       label = l;
       value = v;
   }


   void display() const {
       cout << "  " << left << setw(28) << label << value << "\n";
   }
};




// ============================================================
//  CLASS: Benefit
//  Stores one numbered benefit of the honors program.
// ============================================================


class Benefit {
private:
   string text;
   int    number;


public:
   Benefit() {
       number = 0;
   }


   Benefit(string t, int n) {
       text   = t;
       number = n;
   }


   void display() const {
       cout << "  " << number << ". " << text << "\n";
   }
};




// ============================================================
//  CLASS: Scholarship
//  Stores one scholarship opportunity.
// ============================================================


class Scholarship {
private:
   string name;
   string amount;
   string requirement;


public:
   Scholarship() {}


   Scholarship(string n, string a, string r) {
       name        = n;
       amount      = a;
       requirement = r;
   }


   void display() const {
       cout << "  " << left << setw(32) << name
            << setw(18) << amount
            << requirement << "\n";
   }
};




// ============================================================
//  CLASS: Contact
//  Stores one advisor or office contact.
// ============================================================


class Contact {
private:
   string name;
   string title;
   string room;
   string phone;
   string email;


public:
   Contact() {}


   Contact(string n, string t, string r, string p, string e) {
       name  = n;
       title = t;
       room  = r;
       phone = p;
       email = e;
   }


   void display() const {
       cout << "  " << name << "\n";
       cout << "  " << title << "  -  Room " << room << "\n";
       cout << "  Phone : " << phone << "\n";
       cout << "  Email : " << email << "\n\n";
   }
};




// ============================================================
//  CLASS: ProgressRow
//  Stores one semester's degree completion info.
// ============================================================


class ProgressRow {
private:
   string label;
   int    pct;     // percentage complete, 0 to 100
   string note;


public:
   ProgressRow() {
       pct = 0;
   }


   ProgressRow(string l, int p, string n) {
       label = l;
       pct   = p;
       note  = n;
   }


   void display() const {
       cout << "  " << left << setw(14) << label << "[";


       int filled = pct / 5;   // bar is 20 characters wide
       for (int i = 0; i < 20; i++) {
           if (i < filled)
               cout << "#";
           else
               cout << "-";
       }


       cout << "] " << setw(4) << pct << "%  " << note << "\n";
   }
};




// ============================================================
//  CLASS: Prereq
//  Stores one prerequisite relationship between two courses.
// ============================================================


class Prereq {
private:
   string course;    // the course being taken
   string required;  // the course that must come first


public:
   Prereq() {}


   Prereq(string c, string r) {
       course   = c;
       required = r;
   }


   string getCourse()   const { return course; }
   string getRequired() const { return required; }


   void display() const {
       cout << "  " << left << setw(26) << required
            << "->  " << course << "\n";
   }
};




// ============================================================
//  CLASS: HelpOption
//  Stores one entry in the help menu.
// ============================================================


class HelpOption {
private:
   string command;
   string description;


public:
   HelpOption() {}


   HelpOption(string c, string d) {
       command     = c;
       description = d;
   }


   void display() const {
       cout << "  " << left << setw(20) << command
            << description << "\n";
   }
};




// ============================================================
//  CLASS: HonorsAdvisor
//  Main chatbot class. Owns all data arrays and runs the loop.
// ============================================================


class HonorsAdvisor {
private:


   // Array sizes can add more entries
   static const int NUM_COURSES      = 19;
   static const int NUM_REQUIREMENTS =  5;
   static const int NUM_BENEFITS     =  7;
   static const int NUM_SCHOLARSHIPS =  4;
   static const int NUM_CONTACTS     =  3;
   static const int NUM_PROGRESS     =  4;
   static const int NUM_PREREQS      = 12;
   static const int NUM_HELP         = 10;


   // Arrays of class objects
   Course      courses      [NUM_COURSES];
   Requirement requirements [NUM_REQUIREMENTS];
   Benefit     benefits     [NUM_BENEFITS];
   Scholarship scholarships [NUM_SCHOLARSHIPS];
   Contact     contacts     [NUM_CONTACTS];
   ProgressRow progress     [NUM_PROGRESS];
   Prereq      prereqs      [NUM_PREREQS];
   HelpOption  helpOptions  [NUM_HELP];




   // --------------------------------------------------------
   //  LOAD DATA
   //  Filled array with class objects.
   //  Able to edit values here to update chatbot content.
   // --------------------------------------------------------


   void loadData() {


       // Courses: (code, name, semester, type, honorsAvail, honorsCode)
       courses[0]  = Course("ENG 101", "English Composition",             1, "General Ed", true,  "ENG 101H");
       courses[1]  = Course("BUS 104", "Introduction to Business",        1, "Major Req",  false, "");
       courses[2]  = Course("CSC 101", "Principles in IT & Computation",  1, "Major Req",  true,  "CSC 101H");
       courses[3]  = Course("ACC 122", "Accounting Principles I",         1, "Major Req",  false, "");
       courses[4]  = Course("SPE 100", "Fundamentals of Public Speaking", 1, "General Ed", false, "");
       courses[5]  = Course("ENG 201", "Introduction to Literature",      2, "General Ed", true,  "ENG 201H");
       courses[6]  = Course("CSC 110", "Computer Programming I",          2, "Major Req",  true,  "CSC 110H");
       courses[7]  = Course("MAT 150", "Introduction to Statistics",      2, "General Ed", true,  "MAT 150H");
       courses[8]  = Course("AST 110", "General Astronomy",               2, "General Ed", true,  "AST 110H");
       courses[9]  = Course("CSC 210", "Computer Programming II",         3, "Major Req",  false, "");
       courses[10] = Course("CIS 345", "Telecommunication Network I",     3, "Major Req",  false, "");
       courses[11] = Course("CIS 385", "Web Programming I",               3, "Major Req",  false, "");
       courses[12] = Course("CIS 395", "Database Systems I",              3, "Major Req",  false, "");
       courses[13] = Course("XXX",     "Program Elective",                3, "Elective",   false, "");
       courses[14] = Course("CIS 440", "Unix",                            4, "Major Req",  false, "");
       courses[15] = Course("CIS 485", "Web Programming II",              4, "Major Req",  false, "");
       courses[16] = Course("CIS 495", "Database System II",              4, "Major Req",  false, "");
       courses[17] = Course("XXX",     "Program Elective",                4, "Elective",   false, "");
       courses[18] = Course("XXX",     "General Elective",                4, "Elective",   false, "");


       // Requirements: (label, value)
       requirements[0] = Requirement("Minimum GPA",           "3.2 or higher");
       requirements[1] = Requirement("Honors credits needed", "12 credits minimum");
       requirements[2] = Requirement("Capstone / Thesis",     "Required before graduation");
       requirements[3] = Requirement("Colloquia attendance",  "At least 3 per semester");
       requirements[4] = Requirement("Faculty mentor",        "Assigned in Semester 2");


       // Benefits: (text, number)
       benefits[0] = Benefit("Priority registration every semester",           1);
       benefits[1] = Benefit("Honors notation on transcript and diploma",      2);
       benefits[2] = Benefit("Dedicated honors academic advising",             3);
       benefits[3] = Benefit("Stronger transfer apps to 4-year CUNY schools", 4);
       benefits[4] = Benefit("Access to CUNY Honors Transfer Council",        5);
       benefits[5] = Benefit("Exclusive scholarship eligibility",             6);
       benefits[6] = Benefit("Smaller class sizes and faculty mentorship",    7);


       // Scholarships: (name, amount, requirement)
       scholarships[0] = Scholarship("Honors Program Merit Award",  "$1,000 - $2,500", "Honors member, 3.2+ GPA");
       scholarships[1] = Scholarship("CUNY STEM Scholarship",       "Up to $5,000/yr", "3.0+ GPA, STEM major");
       scholarships[2] = Scholarship("BMCC Foundation Scholarship", "Varies",          "Financial need + merit");
       scholarships[3] = Scholarship("NYCCT Tech Scholars",         "Up to $3,000",    "CIS/CS major, junior standing");


       // Contacts: (name, title, room, phone, email)
       contacts[0] = Contact("Honors Program Office", "Honors Academic Advising", "S-530", "(212) 220-8000 ext. 7100", "honors@bmcc.cuny.edu");
       contacts[1] = Contact("CIS Department Chair",  "Major-Specific Advising",  "N-599", "(212) 220-8000 ext. 7800", "cis@bmcc.cuny.edu");
       contacts[2] = Contact("Financial Aid Office",  "FAFSA & Scholarships",     "S-141", "(212) 220-8000 ext. 7700", "financialaid@bmcc.cuny.edu");


       // Progress rows: (label, percent complete, note)
       progress[0] = ProgressRow("Semester 1", 100, "Complete    - 15 credits");
       progress[1] = ProgressRow("Semester 2", 100, "Complete    - 15 credits");
       progress[2] = ProgressRow("Semester 3",  60, "In progress - ~9 credits done");
       progress[3] = ProgressRow("Semester 4",   0, "Upcoming");


       // Prereqs: (course being taken, course required first)
       prereqs[0]  = Prereq("CSC 110",  "CSC 101");
       prereqs[1]  = Prereq("CSC 110H", "CSC 101H or CSC 101");
       prereqs[2]  = Prereq("CSC 210",  "CSC 110");
       prereqs[3]  = Prereq("CIS 345",  "CSC 101");
       prereqs[4]  = Prereq("CIS 385",  "CSC 101");
       prereqs[5]  = Prereq("CIS 395",  "CSC 101");
       prereqs[6]  = Prereq("CIS 440",  "CIS 345");
       prereqs[7]  = Prereq("CIS 485",  "CIS 385");
       prereqs[8]  = Prereq("CIS 495",  "CIS 395");
       prereqs[9]  = Prereq("ENG 201",  "ENG 101");
       prereqs[10] = Prereq("ENG 201H", "ENG 101H or ENG 101");
       prereqs[11] = Prereq("MAT 150",  "MAT 56 or placement test");


       // Help options: (command keyword, description)
       helpOptions[0] = HelpOption("honors courses",  "List honors-eligible CIS courses");
       helpOptions[1] = HelpOption("requirements",    "Honors program requirements");
       helpOptions[2] = HelpOption("benefits",        "Perks of being in the honors program");
       helpOptions[3] = HelpOption("progress",        "Your degree completion status");
       helpOptions[4] = HelpOption("scholarships",    "Scholarships available to you");
       helpOptions[5] = HelpOption("contact advisor", "Advisor names, phones, and emails");
       helpOptions[6] = HelpOption("prerequisites",   "Prereq chains for all CIS courses");
       helpOptions[7] = HelpOption("transfer",        "Transfer pathways to 4-year schools");
       helpOptions[8] = HelpOption("gpa",             "GPA requirements and academic standing");
       helpOptions[9] = HelpOption("quit",            "Exit the honors advisor");
   }




   // --------------------------------------------------------
   //  HELPER: toLower
   //  Converts a string to all lowercase so we can compare
   //  user input without worrying about capital letters.
   // --------------------------------------------------------


   string toLower(string s) {
       for (int i = 0; i < (int)s.length(); i++) {
           s[i] = tolower(s[i]);
       }
       return s;
   }




   // --------------------------------------------------------
   //  HELPER: detectWord
   //  Returns true if text contains keyword.
   // --------------------------------------------------------


   bool detectWord(string text, string keyword) {
       return text.find(keyword) != string::npos;
   }




   // --------------------------------------------------------
   //  detectIntent
   //  Reads the user's input and returns a plain string
   //  that tells respond() which topic to show.
   // --------------------------------------------------------


   string detectIntent(string input) {
       string t = toLower(input);


       if (detectWord(t, "quit")  || detectWord(t, "exit") ||
           detectWord(t, "bye")   || detectWord(t, "done"))
           return "quit";


       if (detectWord(t, "honors course") || detectWord(t, "honors class") ||
           detectWord(t, "which honors")  || detectWord(t, "available"))
           return "courses";


       if (detectWord(t, "requirement") || detectWord(t, "stay in") ||
           detectWord(t, "qualify")     || detectWord(t, "maintain"))
           return "requirements";


       if (detectWord(t, "benefit")    || detectWord(t, "perk") ||
           detectWord(t, "why honors") || detectWord(t, "advantage"))
           return "benefits";


       if (detectWord(t, "on track")   || detectWord(t, "progress") ||
           detectWord(t, "graduate")   || detectWord(t, "graduation"))
           return "progress";


       if (detectWord(t, "scholarship") || detectWord(t, "fafsa") ||
           detectWord(t, "financial")   || detectWord(t, "aid"))
           return "scholarships";


       if (detectWord(t, "contact")  || detectWord(t, "advisor") ||
           detectWord(t, "advising") || detectWord(t, "phone")   ||
           detectWord(t, "email"))
           return "contacts";


       if (detectWord(t, "prereq")       || detectWord(t, "prerequisite") ||
           detectWord(t, "before taking") || detectWord(t, "required for"))
           return "prereqs";


       if (detectWord(t, "transfer") || detectWord(t, "4 year") ||
           detectWord(t, "bachelor") || detectWord(t, "cuny"))
           return "transfer";


       if (detectWord(t, "gpa")   || detectWord(t, "grade") ||
           detectWord(t, "standing"))
           return "gpa";


       if (detectWord(t, "help") || detectWord(t, "menu") ||
           detectWord(t, "options"))
           return "help";


       return "unknown";
   }




   // --------------------------------------------------------
   //  DISPLAY FUNCTIONS
   //  Each one calls display() on the relevant class objects.
   // --------------------------------------------------------


   void showHonorsCourses() {
       printSectionHeader("Honors-Eligible CIS Courses");
       cout << "  Courses marked * have an honors section available.\n\n";


       for (int sem = 1; sem <= 4; sem++) {
           cout << "  --- Semester " << sem << " ---\n";
           cout << "  " << left << setw(12) << "Code"
                << setw(34) << "Course Name" << "Type\n";
           cout << "  " << string(54, '-') << "\n";


           for (int i = 0; i < NUM_COURSES; i++) {
               if (courses[i].getSemester() == sem) {
                   courses[i].display();
               }
           }
           cout << "\n";
       }
       cout << "  * = Honors section available. Register early -- seats fill fast!\n";
   }


   void showRequirements() {
       printSectionHeader("Honors Program Requirements");
       cout << "  " << string(44, '-') << "\n";
       cout << "  " << left << setw(28) << "Requirement" << "Value\n";
       cout << "  " << string(44, '-') << "\n";
       for (int i = 0; i < NUM_REQUIREMENTS; i++) {
           requirements[i].display();
       }
       cout << "  " << string(44, '-') << "\n";
       cout << "\n  Failing any requirement triggers a review with the Honors Office.\n";
   }


   void showBenefits() {
       printSectionHeader("Honors Program Benefits");
       for (int i = 0; i < NUM_BENEFITS; i++) {
           benefits[i].display();
       }
       cout << "\n  Tip: Priority registration is one of the most valuable perks.\n";
       cout << "  Protect your GPA to keep it!\n";
   }


   void showProgress() {
       printSectionHeader("Your Degree Progress");
       cout << "  Standard Fall start -- on track for May 2026 graduation.\n\n";
       for (int i = 0; i < NUM_PROGRESS; i++) {
           progress[i].display();
       }
       cout << "\n  45 of 60 credits complete.\n";
       cout << "  Still needed: 2 program electives + 1 general elective in Semester 4.\n";
   }


   void showScholarships() {
       printSectionHeader("Scholarships for Honors CIS Students");
       cout << "  " << string(62, '-') << "\n";
       cout << "  " << left << setw(32) << "Scholarship"
            << setw(18) << "Award" << "Requirement\n";
       cout << "  " << string(62, '-') << "\n";
       for (int i = 0; i < NUM_SCHOLARSHIPS; i++) {
           scholarships[i].display();
       }
       cout << "  " << string(62, '-') << "\n";
       cout << "\n  FAFSA priority deadline: March 1\n";
       cout << "  Visit the Financial Aid Office in Room S-141 to apply.\n";
   }


   void showContacts() {
       printSectionHeader("Key Contacts -- Honors & CIS");
       for (int i = 0; i < NUM_CONTACTS; i++) {
           contacts[i].display();
       }
       cout << "  Tip: For honors-specific questions, start with the Honors Program Office (S-530).\n";
   }


   void showPrereqs() {
       printSectionHeader("CIS Prerequisite Chains");
       cout << "  Honors sections have the same prerequisites as standard sections.\n\n";
       cout << "  " << left << setw(26) << "Take this first"
            << "To unlock\n";
       cout << "  " << string(44, '-') << "\n";
       for (int i = 0; i < NUM_PREREQS; i++) {
           prereqs[i].display();
       }
   }


   void showTransfer() {
       printSectionHeader("Transfer Pathways");
       cout << "  Your CIS A.A.S. from BMCC connects to CUNY 4-year schools.\n\n";
       cout << "  As an Honors graduate you get two key advantages:\n";
       cout << "    1. CUNY Honors Transfer Council membership\n";
       cout << "    2. Stronger application profile at partner schools\n\n";
       cout << "  Schools with active CIS articulation:\n";
       cout << "    - City College of New York (CCNY)\n";
       cout << "    - Baruch College\n";
       cout << "    - York College\n\n";
       cout << "  Check course equivalencies at: cx.cuny.edu\n";
       cout << "  Ask your advisor about direct articulation agreements.\n";
   }


   void showGPA() {
       printSectionHeader("GPA & Academic Standing");
       cout << "  " << string(44, '-') << "\n";
       cout << "  " << left << setw(30) << "Honors Program minimum GPA"
            << "3.2\n";
       cout << "  " << left << setw(30) << "CIS major course minimum"
            << "C or better\n";
       cout << "  " << string(44, '-') << "\n";
       cout << "\n  If your GPA drops below 3.2, the Honors Office will reach out.\n";
       cout << "  It is always better to contact them first -- be proactive.\n";
       cout << "  Priority registration is tied to your honors standing.\n";
   }


   void showHelp() {
       printSectionHeader("What I Can Help You With");
       for (int i = 0; i < NUM_HELP; i++) {
           helpOptions[i].display();
       }
   }


   void showUnknown() {
       cout << "\n  [Honors Advisor]  I did not understand that.\n";
       cout << "  Type 'help' to see everything I can assist with.\n";
   }




   // --------------------------------------------------------
   //  respond
   //  Takes the intent string from detectIntent() and calls
   //  the right show function using if / else if statements.
   // --------------------------------------------------------


   void respond(string intent) {
       cout << "\n";


       if (intent == "courses") {
           showHonorsCourses();
       }
       else if (intent == "requirements") {
           showRequirements();
       }
       else if (intent == "benefits") {
           showBenefits();
       }
       else if (intent == "progress") {
           showProgress();
       }
       else if (intent == "scholarships") {
           showScholarships();
       }
       else if (intent == "contacts") {
           showContacts();
       }
       else if (intent == "prereqs") {
           showPrereqs();
       }
       else if (intent == "transfer") {
           showTransfer();
       }
       else if (intent == "gpa") {
           showGPA();
       }
       else if (intent == "help") {
           showHelp();
       }
       else {
           showUnknown();
       }


       cout << "\n";
   }




   // --------------------------------------------------------
   //  UI HELPERS
   //  Small functions that print consistent headers/prompts.
   // --------------------------------------------------------


   void printSectionHeader(string title) {
       cout << "  [Honors Advisor]\n\n";
       cout << "  " << title << "\n";
       cout << "  " << string(title.length() + 2, '=') << "\n";
   }


   void printHeader() {
       cout << "\n";
       cout << "  +----------------------------------------------+\n";
       cout << "  |   BMCC CIS -- Honors Advisor                 |\n";
       cout << "  |   Computer Information Systems  60 Credits   |\n";
       cout << "  +----------------------------------------------+\n";
       cout << "\n";
   }


   void printWelcome() {
       cout << "  [Honors Advisor]  Hi! I am your Honors CIS Advisor at BMCC.\n";
       cout << "                    I can help with honors courses, degree progress,\n";
       cout << "                    scholarships, prerequisites, and advisor contacts.\n";
       cout << "                    Type 'help' to see all options.\n\n";
   }


   void printPrompt() {
       cout << "  You: ";
   }


public:


   // Constructor that loads all the data when object is created
   HonorsAdvisor() {
       loadData();
   }


   // Main chat loop to be called from main
   void run() {
       printHeader();
       printWelcome();


       string input;


       while (true) {
           printPrompt();
           getline(cin, input);


           // Skip empty input
           if (input.empty()) {
               continue;
           }


           string intent = detectIntent(input);


           // Exit the loop if user wants to quit
           if (intent == "quit") {
               cout << "\n  [Honors Advisor]  Good luck with your studies!\n";
               cout << "                    Your Honors advisor is always here.\n\n";
               break;
           }


           respond(intent);
       }
   }
};




// ============================================================
//  MAIN
//  To integrate with Ziyang's, Kadidja's and Daliath's code, remove main() and
//  call:  HonorsAdvisor advisor;  advisor.run();
//  from wherever honors students are routed.
// ============================================================


int main() {
   HonorsAdvisor advisor;
   advisor.run();
   return 0;
}



