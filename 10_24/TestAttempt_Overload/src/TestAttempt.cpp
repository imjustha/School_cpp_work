#include "TestAttempt.h"
#include <sstream>

//CODIO SOLUTION BEGIN
TestAttempt::TestAttempt(int count, string str) {
    numQuestions = count;
    results = new bool [numQuestions+1]; //results[0] is not going to be used
        //as it messes up our usual understanding

    //initialize the array
    for(int i=0; i<=count; i++)
        results[i] = false;

    //convert string content to populate bool array
    istringstream istr(str);
    int number;
    while (istr >> number)
      results[number] = true;
}

//union operation
TestAttempt TestAttempt::operator+(const TestAttempt &other) const {
    TestAttempt temp(numQuestions, "");
    for(int i=1; i<=numQuestions; i++)
        temp.results[i] = results[i] || other.results[i];

    /* previous line is simpler version of
    if (results[i] || other.results[i])
        temp.results[i] = true;
    else
        temp.results[i] = false; */

    return temp;
}

//compute A-B
TestAttempt TestAttempt::operator-(const TestAttempt &other) const {
    TestAttempt temp(numQuestions, "");
    for(int i=1; i<=numQuestions; i++)
        temp.results[i] = results[i] && !other.results[i];

    return temp;
}

// A^B
TestAttempt TestAttempt::operator^(const TestAttempt &other) const {
    TestAttempt temp(numQuestions, "");
    for(int i=1; i<=numQuestions; i++)
        temp.results[i] = results[i] && other.results[i];

    return temp;
}

// A%B
TestAttempt TestAttempt::operator%(const TestAttempt &other) const {
    TestAttempt temp(numQuestions, "");
    for(int i=1; i<=numQuestions; i++)
        temp.results[i] = !results[i] && !other.results[i];

    return temp;
}

//         1  2  3  4  5  6  7  8  9 10
// 10, {X, T, T, T, T, F, F, T, T, F, F}
string TestAttempt::toString() const {
    // come up with a string from boolean array
    ostringstream ostr;

    for(int i=1; i<=numQuestions; i++)
      if (results[i])
        ostr << i << " ";

    return ostr.str();
}

//destructor!
TestAttempt::~TestAttempt() {
    delete [] results;
}

ostream& operator<< (ostream& stream, const TestAttempt& attempt) {
  stream << attempt.toString();
  return stream;
}

//CODIO SOLUTION END
