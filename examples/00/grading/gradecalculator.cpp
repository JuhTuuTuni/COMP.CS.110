#include "gradecalculator.hh"
#include <sstream>  // needed for ostringstream

std::string print_constants()
{
    std::ostringstream outputstream{""};
    outputstream << "The program uses the following values for constants:" << std::endl;
    outputstream << "  MAX_P_POINTS: " << MAX_P_POINTS << std::endl;
    outputstream << "  MAX_N_POINTS: " << MAX_N_POINTS << std::endl;
    outputstream << "  MAX_B_POINTS: " << MAX_B_POINTS << std::endl;
    outputstream << "Update the values, if they do not match with those in Plussa.";
    return outputstream.str();
}

unsigned int calculate_total_grade(unsigned int n,
                                   unsigned int p1,
                                   unsigned int p2,
                                   unsigned int e)
{
    int score_w = score_from_weekly_exercises(n);
    int score_p = score_from_projects(p1, p2);

    if( score_w == 0 or score_p == 0 )
    {
        return 0;
    }
    if( e == 0 )
    {
        if( score_w >= 4 and score_p >= 4 )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        float mean = (score_w + score_p + e) / 3.0;

        // Casting from float to int discards the digits after the decimal point.
        // By adding 0.5 before casting has the effect that decimal values
        // greater than and equal to 0.5 are rounded upwards, while
        // decimal values less than 0.5 are rounded downwards.
        return static_cast<unsigned int>(mean + 0.5);
    }  
}

unsigned int score_from_weekly_exercises(unsigned int n)
{
    float percents = (n * 100.0) / MAX_N_POINTS;
    if( percents < 50.0 ) { return 0; }
    if( percents < 60.0 ) { return 1; }
    if( percents < 70.0 ) { return 2; }
    if( percents < 80.0 ) { return 3; }
    if( percents < 90.0 ) { return 4; }
    return 5;
}

unsigned int score_from_projects(unsigned int p1, unsigned int p2)
{
    // A project not done or just 1 point from automated tests
    if( p1 <= 1 or p2 <= 1 ) { return 0; }

    // Both projects done
    unsigned int total_p = p1 + p2;
    if( total_p < 40 ) { return 0; }
    if( total_p < 50 ) { return 1; }
    if( total_p < 60 ) { return 2; }
    if( total_p < 70 ) { return 3; }
    if( total_p < 80 ) { return 4; }
    return 5;
}
