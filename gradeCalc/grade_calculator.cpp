// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>


// ONLY MAKE CHANGES WHERE THERE IS A TODO(student)


// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;


// These methods are defined below the main function


// print instructions for inputting grades
void print_instructions();


// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);


// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);


int main() {
    print_instructions();


    // ONLY MAKE CHANGES WHERE THERE IS A TODO(student)


    // TODO(student): declare and initialize variables


    // is 36% of avg.
    double midterm_exam = 0;
    int midterm_exam_count = 0;


    // is 24% of avg.
    double final_exam = 0;


    // is 20% of avg.
    double hw_total = 0;
    int hw_count = 0;


    // is 10% of avg.
    double lw_total = 0;
    int lw_count = 0;


    // is 5% of avg.
    double reading_total = 0;
    int reading_count = 0;


    // is 5% of avg.
    double engagement_total = 0;
    int engagement_count = 0;


    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);


        // process the grade entry
        if (category == "exam") {
            midterm_exam += score;
            midterm_exam_count += 1;
        } else if (category == "final-exam") {
            final_exam = score;
        } else if (category == "hw") {
            hw_total += score;
            hw_count += 1;
        } else if (category == "lw") {
            if (score > 50){
                lw_total += 1; // considered completed
                lw_count += 1;
            }
            lw_count += 1; // add count regardless of completed or not
        } else if (category == "reading") {
            if (score == 1){
                reading_total += 1;
            }
            reading_count += 1;
        } else if (category == "engagement") {
            if (score == 1){
                engagement_total += 1;
            }
            engagement_count += 1;
        } else {
            cout << "ignored invalid input" << endl;
        }


        // get the next line from standard input
        getline(cin, line);
    }


    double hw_average = 0;
    double lw_average = 0;
    double exam_average = 0;
    double reading = 0;
    double engagement = 0;
    // TODO(student): compute component averages and assign to the above variables
   
    // EXAMS
    if (midterm_exam_count != 0){
        exam_average = ((midterm_exam / midterm_exam_count) * .36) + (final_exam * .24); // added respective final grade weight already
    }

    // READING
    if (reading_total == 0){ // no reading scores provided; grade still above 0
        reading = 15;
    }
    else {
        reading = (reading_total / reading_count);  
    }

    // ENGAGEMENT
    if (engagement_total == 0){ // no engagement scores provided; grade still above 0
        engagement = 15;
    }
    else {
        engagement = (engagement_total / engagement_count);  
    }

    // HW
    if (hw_total == 0){ // conditional implemented to handle dividing by 0 error
        hw_average = 0;
    }
    else {
        hw_average = (hw_total / hw_count);
    }

    // LW
    if (lw_total == 0){
        lw_average = 0;
    }
    else{
        lw_average = (lw_total / lw_total);
    }


    // TODO(student): compute weighted total of components
    double weighted_total = exam_average + () + () + () + ();


    // TODO(student): compute final letter grade
    char final_letter_grade = 'X';


    // Do not modify print_results since this will not help
    print_results(
        exam_average, hw_average, lw_average, reading, engagement,
        weighted_total, final_letter_grade);
}


// These methods are already implemented for you
// You should not need to modify them
// Even minor changes might cause you to fail test cases for the wrong reasons


void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}


// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);


    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;


    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}


void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double reading,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "        exam average: " << exam_average << endl;
    cout << "          hw average: " << hw_average << endl;
    cout << "          lw average: " << lw_average << endl;
    cout << "     reading average: " << reading << endl;
    cout << "  engagement average: " << engagement << endl;
    cout << "  -------------------" << endl;


    cout << "      weighted total: " << weighted_total << endl;


    cout << "  final letter grade: " << final_letter_grade << endl;
}








