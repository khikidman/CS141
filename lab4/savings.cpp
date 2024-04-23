#include <iostream>

using namespace std;

int main() {
    float salary = 0.0;
    float return_rate = 0.0;
    float salary_inc_rate = 0.0;
    float contribution = 0.0;
    int years_to_retire = 0.0;
    float employer_match = 0.0;
    float saving = 0.0;

    cout << "Salary: ";
    cin >> salary;

    cout << "Salary increase rate: ";
    cin >> salary_inc_rate;

    cout << "Retirement contribution: ";
    cin >> contribution;

    cout << "Expected return rate: ";
    cin >> return_rate;

    cout << "Years to retire: ";
    cin >> years_to_retire;


    int i = 0;
    while (i < years_to_retire) {
        
        // Apply return rate to savings
        saving *= 1.0 + return_rate/100;

        // Apply contribution percentage of salary to savings
        saving += salary * contribution/100;

        // Determing employer contribution
        if (contribution <= 5)
            employer_match = contribution;
        else
            employer_match = 5;

        // Apply employer contribution
        saving += salary * employer_match/100;

        cout << "Year: " << i + 1 << " Retirement saving: " << saving << endl;

        // Apply salary increase
        salary *= 1 + salary_inc_rate/100;

        i++;
    }

    return 0;


}