#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> fireEmployees(vector<string> employees, vector<string> unemployed){
    unordered_map<string, bool> employedMap;
    for (string employee :employees){
        employedMap[employee] = true;
    }

    for (string unemployee: unemployed){
        employedMap[unemployee] = false;
    }

    vector<string> employeeList;

    for (string employee: employees){
        if(employedMap[employee])
            employeeList.push_back(employee);
    }

    return employeeList;
}
