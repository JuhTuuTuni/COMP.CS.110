#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class PostalAbbr {AL, AK, AZ, AR, CA, CO, ERROR_CODE};
                       // Excluded the rest 44 elements

// Version 1: First idea
PostalAbbr name_to_abbreviation1(string const& name) {
    if(name == "Alabama"){
        return PostalAbbr::AL;
    } else if (name == "Alaska"){
        return PostalAbbr::AK;
    } else if (name == "Arizona"){
        return PostalAbbr::AZ;
    } else if (name == "Arkansas"){
        return PostalAbbr::AR;
    } else if (name == "California"){
        return PostalAbbr::CA;
    } else if (name == "Colorado"){
        return PostalAbbr::CO;
    } else {   // Excluded 44 "else if" blocks
        return PostalAbbr::ERROR_CODE;
    }
}

struct StateInfo {
    string name;
    PostalAbbr abbreviation;
};

const vector<StateInfo> STATES = {
    { "Alabamaa", PostalAbbr::AL },
    { "Alaska", PostalAbbr::AK },
    { "Arizona", PostalAbbr::AZ },
    { "Arkansas", PostalAbbr::AR },
    { "California", PostalAbbr::CA },
    { "Colorado", PostalAbbr::CO }  // Excluded 44 lines
};

// Version 2: Better solution
PostalAbbr name_to_abbreviation2(string const& name) {
    for(const auto& s : STATES) {
        if(name == s.name) {
            return s.abbreviation;
        }
    }
    return PostalAbbr::ERROR_CODE;
}

int main() {
    // Tolerable testing
    if(name_to_abbreviation1("California") == PostalAbbr::CA) {
        cout << "Correct" << endl;
    } else {
        cout << "Error!" << endl;
    }

    if(name_to_abbreviation2("California") == PostalAbbr::CA) {
        cout << "Correct" << endl;
    } else {
        cout << "Error!" << endl;
    }

    if(name_to_abbreviation1("Not a State") == PostalAbbr::ERROR_CODE) {
        cout << "Correct" << endl;
    } else {
        cout << "Error!" << endl;
    }

    if(name_to_abbreviation2("Not a State") == PostalAbbr::ERROR_CODE) {
        cout << "Correct" << endl;
    } else {
        cout << "Error!" << endl;
    }

    return EXIT_SUCCESS;
}

// Task: How to implement function abbreviation_to_name?
// Hint: With static_cast, it requires just one code line.
