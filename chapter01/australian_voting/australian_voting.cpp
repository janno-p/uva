#include <iostream>

using namespace std;

void check_results();

int main()
{
    int num_cases;
    cin >> num_cases;

    for (int case_num = 0; case_num < num_cases; case_num++)
        check_results();
}

void check_results()
{
    int num_candidates;
    cin >> num_candidates;

    cout << "Number of candidates: " << num_candidates << endl;
}
