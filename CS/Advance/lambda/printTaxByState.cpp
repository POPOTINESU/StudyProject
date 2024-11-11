#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <tuple>

using namespace std;

class Tax {
   public:
    const double FEDERAL_TAX_RATE = 0.21;
    map<string, double> taxRate = {
        {"California", 0.088}, {"Arizona", 0.049}, {"Northcarolina", 0.025}};

    int calcFederalTax(int income) const { return income * FEDERAL_TAX_RATE; }

    double getTaxRate(const string& state) const {
        auto tax = taxRate.find(state);
        if (tax != taxRate.end()) {
            return tax->second;
        } else {
            throw invalid_argument("Unknown state: " + state);
        }
    }

    double calcStateTax(int income, double stateTaxRate) const {
        return income * stateTaxRate;
    }
};

function<void(int)> printTaxByState(const string& state) {
    shared_ptr<Tax> taxObj = make_shared<Tax>();
    double stateTaxRate = taxObj->getTaxRate(state);

    return [state, stateTaxRate, taxObj](int income) {
        int federalTax = taxObj->calcFederalTax(income);
        int stateTax = taxObj->calcStateTax(income, stateTaxRate);
        int totalTax = federalTax + stateTax;

        cout << "Federal Tax: " << federalTax << endl;
        cout << state << " State Tax: " << stateTax << endl;
        cout << "Tax Amount: " << totalTax << endl;
    };
}

int entry() {
    auto getTaxInAZ = printTaxByState("Arizona");
    getTaxInAZ(400000);

    auto getTaxInCA = printTaxByState("California");
    getTaxInCA(100000);

    auto getTaxInNC = printTaxByState("Northcarolina");
    getTaxInNC(500000);

    return 0;
}

int main() {
    entry();
    return 0;
}