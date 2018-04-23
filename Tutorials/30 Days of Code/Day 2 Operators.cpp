#include <bits/stdc++.h>

using namespace std;

int main() {
    double meal_cost;
    cin >> meal_cost;
    int tip_percent;
    cin >> tip_percent;
    int tax_percent;
    cin >> tax_percent;
    
    double cost = meal_cost * (1 + (tip_percent + tax_percent) / 100.0);
    double total_cost = round(cost);
    cout << "The total meal cost is " << total_cost << " dollars." << endl;
    return 0;
}
